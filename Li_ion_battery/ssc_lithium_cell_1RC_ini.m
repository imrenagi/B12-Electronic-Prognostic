% Initialization file for demo ssc_lithium_cell_1RC.mdl. Demo
% based on T. Huria, M. Ceraolo, J. Gazzarri, R. Jackey. "High Fidelity
% Electrical Model with Thermal Dependence for Characterization and
% Simulation of High Power Lithium Battery Cells," IEEE International
% Electric Vehicle Conference, March 2012
%
% Copyright 2012 The MathWorks, Inc.


%% Lookup Table Breakpoints

SOC_LUT = [0 0.1 0.25 0.5 0.75 0.9 1]';
Temperature_LUT = [5 20 40] + 273.15;

%% Em Branch Properties (OCV, Capacity)

% Battery capacity
Capacity_LUT = [2.6   2.55   2.5]; %Ampere*hours

% Em open-circuit voltage vs SOC rows and T columns
Em_LUT = [
    4.0000    4.0000    4.0000
    4.0000    4.0000    4.0000
    4.0000    4.0000    4.0000
    4.0000    4.0000    4.0000
    4.0000    4.0000    4.0000
    4.0000    4.0000    4.0000
    4.0000    4.0000    4.0000]; %Volts

%% Terminal Resistance Properties

% R0 resistance vs SOC rows and T columns
R0_LUT = [
    0.1000    0.1000    0.1000
    0.1000    0.1000    0.1000
    0.1000    0.1000    0.1000
    0.1000    0.1000    0.1000
    0.1000    0.1000    0.1000
    0.1000    0.1000    0.1000
    0.1000    0.1000    0.1000]; %Ohms

%% RC Branch 1 Properties

% R1 Resistance vs SOC rows and T columns
R1_LUT = [
    0.0700    0.0700    0.0700
    0.0700    0.0700    0.0700
    0.0700    0.0700    0.0700
    0.0700    0.0700    0.0700
    0.0700    0.0700    0.0700
    0.0700    0.0700    0.0700
    0.0700    0.0700    0.0700]; %Ohms

% C1 Capacitance vs SOC rows and T columns
C1_LUT = [
    10000     10000    10000
    10000     10000    10000
    10000     10000    10000
    10000     10000    10000
    10000     10000    10000
    10000     10000    10000
    10000     10000    10000]; %Farads

   
%% Thermal Properties

% Cell dimensions and sizes
% cell_thickness = 0.0084; %m
% cell_width = 0.215; %m
% cell_height = 0.220; %m

cell_diameter = 0.0184; %m
cell_height = 0.0652; %m

% Cell surface area
% cell_area = 2 * (...
%     cell_thickness * cell_width +...
%     cell_thickness * cell_height +...
%     cell_width * cell_height); %m^2
cell_area = 2 * pi * (cell_diameter / 2) * (cell_diameter / 2 + cell_height);

% Cell volume
% cell_volume = cell_thickness * cell_width * cell_height; %m^3
cell_volume = pi * (cell_diameter / 2)^2 * cell_height;

% Cell mass
cell_mass = 0.0465; %kg

% Volumetric heat capacity
% assumes uniform heat capacity throughout the cell
% ref: J. Electrochemical Society 158 (8) A955-A969 (2011) pA962
cell_rho_Cp = 2.04E6; %J/m3/K

% Specific Heat
cell_Cp_heat = cell_rho_Cp * cell_volume; %J/kg/K

% Convective heat transfer coefficient
% For natural convection this number should be in the range of 5 to 25
h_conv = 5; %W/m^2/K
h_conv_end = 5; %W/m^2/K

%% Initial Conditions

% Charge deficit
Qinit = 0.5000; %Ampere*hours

% Ambient Temperature
T_init = 20 + 273.15; %K


