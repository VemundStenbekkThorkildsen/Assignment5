Folder containing the c++ scripts generating data for the different cases. The different scripts do the following:
* __bwdeuler.cpp__
  - calculates the Backward Euler implicit scheme for one dimension
* __cranknic__
  - calculates the Crank-Nicolson implicit scheme for one dimension
* __fwdeuler.cpp__
  - calculates the Forward Euler explicit scheme for one dimension
* __fwdeuler2.cpp__
  - calculates the Forward Euler explicit scheme for two dimensions
* __geoeulerforward.cpp__
  - calculates three layer model for the Earths' lithosphere using Forward Euler explicit scheme
* __main.cpp__
  - connects the entire program and initializes the different cases. Reads maximum time, number of time points and grid-/line size.
* __methods.h__
  - header included in main connecting the scripts
* __trisolver.cpp__
  - LU triagonal solver used in Backward Euler and Crank-Nicolson
* __writematfile.cpp__
  - writes data to file for the different 2 dimensional cases
* __writetofile.cpp__
  - writes data to file for the different one dimensional cases
