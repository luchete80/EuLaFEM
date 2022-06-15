#ifndef _MESH_H_
#define _MESH_H_

#include <vector>

class Vector{
  double x[3];
};

class Element{
  int node[4];
};

namespace EuLa{
class Mesh{
public:
  int nodecount, elcount;
  std::vector< Vector > node;
  std::vector< Element> elem;
  
};

};
#endif