This folder is for those who prefer to compile in g++ via terminal on linux/OSX instead of using Qt. To compile the program, simply type 

```
make
```
which produces the file *diff*. This is can be run by typing
```
./diff n t_max tsteps
```
where *n* is the grid-/line size, *t_max* is the maximum time and *tsteps* are the number of time steps. *n* and *tsteps* are both integers while *t_max* is a double.
