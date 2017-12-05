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
graph = mesh(forward);
set(graph,'LineWidth',2); %Thicker lines
xlabel('x') %Labels
ylabel('y')
zlabel('t')
title('u(x) over t') %Title
