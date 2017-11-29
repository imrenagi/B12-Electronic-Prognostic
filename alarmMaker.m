
%%
% Instructions
% Given the data produces from State Estimation of Degrading Battery System
% Find an alarm threshold based on recharging speed

%%
% Setup
% discharge/charge indicator
% -1 is discharge, 1 is charge
dc_indicator = DischargeChargeIndicator;

% input current to system
% positive is charge, negative is discharge
a = inputCurrent;

% estimated state of charge from the model
% must make sure SoC is the same when rechage begins and ends
eSOC = EstimatedSOC;


%%
% Find alarm threshold

% battery gives out around 62h
% find a recharge time threshold around 60-62h

% index for current
a_idx = 1;
a_idx_next = 1;
% whether current state is charging
isCharging = false;
% time step when charging began
charging_start = 0;
% record time it takes to charge
% first column: charging start time
% second column: time took to charge from 0.3 SOC to 0.9 SOC
recharge_times = [];
% mark that this charging cycle has been recorded
hasRecorded = false;

% iterate over time
for i = 1:(length(eSOC.Time)-1)
    % current time
    t = eSOC.Time(i);
    t_next = eSOC.Time(i+1);
    
    % estimated SOC at this time
    soc_now = eSOC.Data(i);
    soc_next = eSOC.Data(i+1);
    
    % find current time that matches eSOC time
    a_time = a.Time(a_idx);
    
    while a_time ~= t
        a_idx = a_idx+1;
        a_time = a.Time(a_idx);
    end
    
    % find next time that matches next eSOC time
    a_idx_next = a_idx;
    a_time_next = a_time;
    while a_time_next ~= t
        a_idx_next = a_idx_next+1;
        a_time_next = a.Time(a_idx_next);
    end

    % if charging
    if a.Data(a_idx) > 0
        
        if ~isCharging
            isCharging = true;
            charging_start = (a_time + a_time_next)/2;
        end
        
        % if next element is charging as well
        if a.Data(a_idx_next) > 0 && ~hasRecorded
            % record recharge time when SOC passes 0.9
            % if eSoC_now =< 0.9 and eSoC_next >= 0.9
            if soc_now <= 0.9 && soc_next >= 0.9
                charging_time = (a_time + a_time_next)/2 - charging_start;
                recharge_times = [recharge_times ; [charging_start, charging_time]];
                hasRecorded = true;
            end
        % if next element is not charging
        else
            % but the data hasn't been recorded for this charging cycle
            if ~hasRecorded
                charging_time = a_time - charging_start;
                recharge_times = [recharge_times ; [charging_start, charging_time]];
                hasRecorded = true
            end
        end
    % not charging
    else
        % set flag to not charging
        if isCharging
            isCharging = false;
            hasRecorded = false;
        end
    end
    
    
end