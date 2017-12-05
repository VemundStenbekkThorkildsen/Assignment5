#include "methods.h"

void writeMatFile(mat& u, string filename)
{
  ofstream outfile(filename);
  outfile << u << endl;
  outfile.close();
}
