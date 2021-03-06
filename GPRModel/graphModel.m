
% file to graph the partitioned gpr model (cross valuated with kfold 5
% times)
% graphs entirevalidation predictions vs. train set data
% graphs first and last 5k data points of RW9 vs. Trained Model predictions

%% Instructions
% load GprModel/data/rw9ReducedTrainSet
% load GprModel/data/rw9ValidationPrediction

% load GprModel/RW9_rw_table or whichever battery to predict on

% change below to battery being used
data = rw9Tbl;
battery = 'RW9';

%% Graph train set vs. validation prediction

x = rw9ReducedTrainSet.RelativeTime/3600;

figure;
plot(x, rw9ReducedTrainSet.Voltage, 'r');
hold on;
plot(x, validationPredictions, 'b');

title('Train Set vs. Validation Prediction');
xlabel('Time (h)');
ylabel('Voltage (V)');

%% Graph first and last 5k data rows to train set vs. validation prediction
data_points = 5000;

% First 5000 points
yfit = GprModel(data(1:data_points,:));

figure;
plot(x(1:data_points), data.Voltage(1:data_points), 'r');
hold on;
plot(x(1:data_points), yfit, 'b');

legend(battery, 'Trained Model', 'Location', 'Best');
title('Train Phase First 5k data points');
xlabel('Time (h)');
ylabel('Voltage (V)');

% Last 5000 points
yfit = GprModel(data(1:data_points,:));

figure;
plot(x(end-data_points:end), data.Voltage(end-data_points:end), 'r');
hold on;
plot(x(end-data_points:end), yfit, 'b');

legend(battery, 'Trained Model', 'Location', 'Best');
title('Train Phase Last 5k data points');
xlabel('Time (h)');
ylabel('Voltage (V)');