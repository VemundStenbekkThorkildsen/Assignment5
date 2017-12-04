home
close all
clear all

addpath('..\data')

%Loading variables
x = load('');
y = load('');

%%

%Arrays for x-axis
dx = linspace(0,1,length(x));
dy = dx;

%Plotting the data
figure(1)
hold on


