home
close all
clear all

%Accessing the 'data' folder on github
addpath('..\..\data')

%Loading stable solutions
forward = load('fwd100.txt');
backward = load('bwd100.txt');
crank = load('crank100.txt');

%%

dx = linspace(0,1,length(forward)); %Defining x-axis

%Plotting the data
figure(1)
hold on
graphf = plot(dx,forward); %Forward
graphb = plot(dx,backward); %Backward
graphcn = plot(dx,crank); %Crank-Nicolson
set(graphf,'LineWidth',2); %Thicker lines
set(graphb,'LineWidth',2); %Thicker lines
set(graphcn,'LineWidth',2); %Thicker lines
title('Different methods over x') %Title
xlabel('x') %Labels and legend
ylabel('u(x)')
legend('Euler Forward','Euler Backward','Crank-Nicolson')
