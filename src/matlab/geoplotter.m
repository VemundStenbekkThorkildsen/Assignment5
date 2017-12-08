home
close all
clear all

%Accessing the 'data' folder on github
addpath('..\..\data')

%Loading stable solutions
forward = load('fwdgeo120.txt');
gutten = load('maen120.txt');


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
figure(2)
contourf(X,Y,gutten,'ShowText','on');
colorbar
title('Contour') %Title
xlabel('x') %Labels and legend
ylabel('z')

%% 1d

temp=forward(:,50);
z=linspace(0,120,length(temp));



plot (z,temp)
