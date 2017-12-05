home
close all
clear all

%Accessing the 'data' folder on github
addpath('..\..\data')

%Loading stable solutions
forward = load('2fwd120.txt');


%%

dx = linspace(1,120,length(forward));
dy = dx;
[X,Y] = meshgrid(dx,dy);


%Plotting the data
figure(1)
map = contourf(X,Y,forward,'ShowText','on'); %Crank-Nicolson
colorbar
title('Contour') %Title
xlabel('x') %Labels and legend
ylabel('z')

figure(2)
surf(forward)
colormap(parula(20));