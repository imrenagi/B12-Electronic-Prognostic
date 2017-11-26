% example script that recreates the plots shown in the README document
close all;
clear all;

% Change this data file name below to plot different files
load('data/Matlab/RW9')

%% The following sample code shows data collected over the first 50 and the 
% last 50 RW steps in the experiment.

steps = data.step; % save steps array to new variable

%% Example Plots of Pulsed Load Charging and Discharging Cycles

PulsedDis.repition{1}.indexes = 0;
counter1 = 0;
counter2 = 0;
% find Pulsed Load discharge characterization cycles
for i = 2:length(data.step)
    if (strcmp(data.step(i).comment,'pulsed load (discharge)')...
            || strcmp(data.step(i).comment,'pulsed load (rest)'))  
        % if just starting the pulsed load cycle
        if (strcmp(data.step(i).comment,'pulsed load (rest)') && (~strcmp(data.step(i-1).comment,'pulsed load (discharge)')))  
            counter1 = 1;
            counter2 = counter2+1;
            PulsedDis.repition{counter2}.indexes(counter1) = i;
        else
            counter1 = counter1+1;
            PulsedDis.repition{counter2}.indexes(counter1) = i; 
        end
    end
    if(strcmp(data.step(i).comment,'rest post pulsed load or charge'))
        % check to see if this preceeds a pulsed load (discharge)
        if(strcmp(data.step(i-1).comment,'pulsed load (discharge)'))
            counter1 = counter1+1;
            PulsedDis.repition{counter2}.indexes(counter1) = i;
        end
    end
end

% now plot each of the grouped pulsed load discharge cycles
figure, hold on
% for i = 1:length(PulsedDis.repition)
for i = 4:4
    % stitch together all of the substeps identified in the repitition
    % field
    step = steps(PulsedDis.repition{i}.indexes(1));
    
    for j = 2:(length(PulsedDis.repition{i}.indexes))
        step.relativeTime = [step.relativeTime step.relativeTime(end)+steps(PulsedDis.repition{i}.indexes(j)).relativeTime];
        step.voltage = [step.voltage steps(PulsedDis.repition{i}.indexes(j)).voltage];
        step.current = [step.current steps(PulsedDis.repition{i}.indexes(j)).current];
        step.temperature = [step.temperature steps(PulsedDis.repition{i}.indexes(j)).temperature];
    end
    
%     plot(step.relativeTime/3600,step.voltage,'k')
%     title('Pulsed Discharge')
%     xlabel('Time (h)')
%     ylabel('Voltage (V)')
%     subplot(3,1,1)
%     plot(step.relativeTime/3600,step.voltage,'k')
%     title(sprintf('Pulsed Charge and Discharge of 1 Cycle',i))
%     xlabel('Time (h)')
%     ylabel('Voltage (V)')
% 
%     % plot Current
%     subplot(3,1,2), hold on
%     plot(step.relativeTime/3600,step.current,'k')
%     xlabel('Time (h)')
%     ylabel('Current (A)')
% 
%     % plot temperature
%     subplot(3,1,3), hold on
%     plot(step.relativeTime/3600,step.temperature,'k')
%     ylim([15, 40])
%     xlabel('Time (h)')
%     ylabel('Temperature (C)')
end

    subplot(3,1,1)
    plot(step.relativeTime/3600,step.voltage,'k')
    title(sprintf('Pulsed Charge and Discharge of 1 Cycle',i))
    xlabel('Time (h)')
    ylabel('Voltage (V)')

    % plot Current
    subplot(3,1,2), hold on
    plot(step.relativeTime/3600,step.current,'k')
    xlabel('Time (h)')
    ylabel('Current (A)')

    % plot temperature
    subplot(3,1,3), hold on
    plot(step.relativeTime/3600,step.temperature,'k')
    ylim([15, 40])
    xlabel('Time (h)')
    ylabel('Temperature (C)')
    
% voltCol=transpose(step.voltage(1:20:22938))
% x = step.current * -1
% currCol=transpose(x(1:20:22938))
% tempCol=transpose(step.temperature(1:20:22938))
% timeCol=transpose(floor(step.relativeTime(1:20:22938)))

voltCol=transpose(step.voltage);
x = step.current * -1;
currCol=transpose(x);
tempCol=transpose(step.temperature);
timeCol=transpose(floor(step.relativeTime));

PulseData = struct('time', timeCol, 'voltage', voltCol, 'current', currCol, 'temperature', tempCol);    
