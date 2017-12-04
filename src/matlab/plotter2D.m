home
close all
clear all

%Accessing the 'data' folder on github
addpath('..\..\data')

%Loading the forward euler matrix for 2D
forward = load('2fwd10.txt');

%%

%Plotting the data
figure(1)
mesh(forward)
xlabel('x')
ylabel('y')
zlabel('t')
title('u(x) over t')
