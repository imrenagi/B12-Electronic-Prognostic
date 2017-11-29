
% file to graph the partitioned gpr model (cross valuated with kfold 5
% times)
% graphs validation predictions vs. train set data

%% Instructions
% load GprModel/data/rw9ReducedTrainSet
% load GprModel/data/rw9ValidationPrediction

%% Graph train set vs. validation prediction
data = rw9ReducedTrainSet;

x = data.RelativeTime/3600;

figure;
plot(x, data.Voltage, 'r');
hold on;
plot(x, validationPredictions, 'b');

title('Train Set vs. Validation Prediction');
xlabel('Time (h)');
ylabel('Voltage (V)');

%% Graph first and last 5k data rows to train set vs. validation prediction
data_points = 150;

% First few hours
figure;
plot(x(1:data_points), data.Voltage(1:data_points), 'r');
hold on;
plot(x(1:data_points), validationPredictions(1:data_points), 'b');

title('First few hours Train Set vs. Validation Prediction');
xlabel('Time (h)');
ylabel('Voltage (V)');

% Last few hours
figure;
plot(x(end-data_points:end), data.Voltage(end-data_points:end), 'r');
hold on;
plot(x(end-data_points:end), validationPredictions(end-data_points:end), 'b');

title('Last few hours Train Set vs. Validation Prediction');
xlabel('Time (h)');
ylabel('Voltage (V)');