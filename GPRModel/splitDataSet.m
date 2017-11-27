
% This file splits a dataset into train and test

%% Instructions
% Load the data, must be in table format.
% e.g. load RW9_rw_table.mat into the workspace
% can be found in data directory


%% Split data
% splits data with logical arrays

% random number generator and seed
rng(0, 'twister');

% initialize the logical arrays
test_idx =  false(length(rw9Tbl.Current),1);
train_idx = false(length(rw9Tbl.Current),1);

% split the data 4:1 train to test
for i=1:length(rw9Tbl.Current)
    r = randi([0, 10]);
    
    if r >= 8
        test_idx(i) = true();
    elseif r < 8
        train_idx(i) = true();
    end
end

rw9TestSet = rw9Tbl(test_idx,:);

rw9TrainSet = rw9Tbl(train_idx,:);