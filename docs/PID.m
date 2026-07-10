%% live_pid_plot.m
%  Real-time SINGLE-PLOT view of motor PID data over UART/serial,
%  using a dual y-axis: LEFT = speed (rpm), RIGHT = error centered on zero.
%  Lines look like:   DEBUG   : T:3120 C:2011 E:1109
%
%  Close the figure window (or press Stop) to end and free the port.
%  Requires MATLAB R2019b+ (serialport interface).

clear; clc; close all;

%% ---- Settings -------------------------------------------------------
port     = "COM3";        % "COM5" (Win), "/dev/ttyUSB0" (Linux), "/dev/tty.usbserial-XXXX" (macOS)
baud     = 115200;        % must match firmware UART baud
windowN  = 300;           % recent samples kept on screen
cycleT   = 0.100;         % runnable period (s)
filterGlitches = true;    % drop corrupt samples where E ~= T - C

%% ---- Open the serial port ------------------------------------------
s = serialport(port, baud);
configureTerminator(s, "LF");   % use "CR/LF" if firmware sends \r\n
s.Timeout = 1;
flush(s);
cleanupObj = onCleanup(@() clear('s'));   % auto-release port on exit/error

%% ---- One plot, two y-axes ------------------------------------------
fig = figure('Name','Live Motor PID', 'Color','w', 'Position',[100 100 900 520]);

running = true;
uicontrol(fig, 'Style','pushbutton', 'String','Stop', 'FontSize',11, ...
          'Position',[10 10 70 28], ...
          'Callback', @(~,~) assignin('base','running',false));

ax = axes(fig); hold(ax,'on'); grid(ax,'on'); box(ax,'on');

% LEFT axis: speeds (rpm)
yyaxis(ax,'left');
hTar = animatedline(ax, 'Color','k',           'LineStyle','--', 'LineWidth',1.4);
hCur = animatedline(ax, 'Color',[0 0.45 0.85], 'LineStyle','-',  'LineWidth',1.7);
ylabel(ax,'Speed (rpm)');
ax.YColor = [0 0.3 0.6];

% RIGHT axis: error, centered on its own zero
yyaxis(ax,'right');
hErr = animatedline(ax, 'Color',[0.85 0.1 0.1], 'LineStyle','-', 'LineWidth',1.3);
yline(ax, 0, 'k:');                 % zero reference for the error axis
ylabel(ax,'Error (rpm)');
ax.YColor = [0.7 0.1 0.1];

xlabel(ax,'Time (s)');
title(ax,'Live PID response (speed left, error right)');
legend(ax, {'Target','Measured','Error','zero'}, 'Location','best');

%% ---- Read loop ------------------------------------------------------
k = 0;
fprintf('Reading from %s @ %d baud. Close window or press Stop to end.\n', port, baud);

while running && isvalid(fig)
    running = evalin('base', 'exist(''running'',''var'') && running');

    line = readline(s);                  % <missing> on timeout
    if ismissing(line), drawnow limitrate; continue; end

    tok = regexp(line, 'T:(-?\d+)\s+C:(-?\d+)\s+E:(-?\d+)', 'tokens', 'once');
    if isempty(tok), continue; end

    T = str2double(tok{1});
    C = str2double(tok{2});
    E = str2double(tok{3});

    if filterGlitches && (T < 0 || T > 20000 || abs(E - (T - C)) > 5)
        continue;
    end

    k = k + 1;
    tNow = k * cycleT;
    addpoints(hTar, tNow, T);
    addpoints(hCur, tNow, C);
    addpoints(hErr, tNow, E);

    xMax = tNow;  xMin = max(0, xMax - windowN*cycleT);
    xlim(ax, [xMin xMax]);

    drawnow limitrate;
end

disp('Stopped. Serial port released.');