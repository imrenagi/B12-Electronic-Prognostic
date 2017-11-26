clc
load('smalldat.csv');
data = smalldat(:,2:4);

% plot(smalldat(:,1), smalldat(:,4), '.')

B = transpose(data);
voltcell=cell(2,100);

voltcell(2,:)=num2cell(B(1,:)); % voltage data observed
