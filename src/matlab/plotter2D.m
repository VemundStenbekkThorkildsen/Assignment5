home
close all
clear all

addpath('..\..\data')

%Loading variables
x = load('2fwd10.txt');

%%

%Arrays for x-axis
dx = linspace(0,1,length(x));
dy = dx;

%Plotting the data
figure(1)
mesh(x)
xlabel('x')
ylabel('y')
zlabel('t')
title('u(x) over t')
