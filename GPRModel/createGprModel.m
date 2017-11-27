
% This file creates a Gaussian Process Regression Model from
% traininig data

%% Instructions
% Load the train dataset to train a GPR model
% use GPRModel/splitDataSet.m to create a train and test dataset

% From experimentation, Matlab seems to be unable to handle
% datasets greater than roughly 50k on a Windows 10 computer with
% Intel Core i7-4790K CPU @ 4.00GHZ and 16 GB of RAM


%% Reduce the train data set
% so we don't crash Matlab

% random number generator and seed
rng(0, 'twister');

% initialize the logical arrays
% train set of rw9 is around 6.18M data rows
% need to reduce it to 50K
idx =  false(length(rw9TrainSet.Current),1);

% randomly select only about 50K data points from train set
% i.e. only use about 0.8% of the data
for i=1:length(rw9TrainSet.Current)
    r = randi([0, 1000]);
    
    if r >= 996
        idx(i) = true();
    end
end

rw9ReducedTrainSet = rw9TrainSet(idx,:);

GprModel = fitrgp(rw9ReducedTrainSet, 'Voltage', ...
    'BasisFunction', 'constant',...
    'KernelFunction', 'exponential',...
    'FitMethod', 'fic', ...
    'Standardize', true);

partitionedModel = crossval(GprModel, 'KFold', 5);
validationPredictions = kfoldPredict(partitionedModel);
validationRMSE = sqrt(kfoldLoss(partitionedModel, 'LossFun', 'mse'));