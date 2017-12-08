home
close all
clear all

%Accessing the 'data' folder on github
addpath('..\..\data')

%Loading stable solutions
forward = load('fwdgeo120.txt');
<<<<<<< HEAD
gutten = load('maen120.txt');

=======
oneD=load('1ma.txt');
>>>>>>> 790cb01a08d769e09921b615631cae2b6f623cb1

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
<<<<<<< HEAD
contourf(X,Y,gutten,'ShowText','on');
colorbar
title('Contour') %Title
xlabel('x') %Labels and legend
ylabel('z')

%% 1d

temp=forward(:,50);
z=linspace(0,120,length(temp));



plot (z,temp)
=======
mesh(forward)

%% one dimensional plotter

Temp=oneD(:,50);
z=linspace(0,-121,length(Temp));
z=z';
plot(Temp,z)

format long
y=polyfit(Temp,z,2)
>>>>>>> 790cb01a08d769e09921b615631cae2b6f623cb1
