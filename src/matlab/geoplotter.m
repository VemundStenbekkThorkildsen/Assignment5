home
close all
clear all

%Accessing the 'data' folder on github
addpath('..\..\data')

%Loading stable solutions
forward = load('fwdgeo120.txt');

%%

dx = linspace(1,120,length(forward));
dy = dx;
[X,Y] = meshgrid(dx,dy);


%Plotting the data
figure(1)
contourf(X,Y,forward,'ShowText','on'); %Crank-Nicolson
colorbar
title('Contour') %Title
xlabel('x') %Labels and legend
ylabel('z')

%%

surf(forward)

%% one dimensional plotter

Temp=forward(:,50);
z=linspace(0,121,length(Temp));
z=z';
plot(Temp,z)

format long
y=polyfit(Temp,z,2);
