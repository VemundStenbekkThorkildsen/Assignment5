#include "methods.h"

void writeToFile(vec& u, string filename)
{
  ofstream outfile(filename);
  outfile << u << endl;
  outfile.close();
}
