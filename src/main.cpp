#include "Matrix.h"

using namespace EuLa;
void calculate_shape_matrices (const double &rg, const double &sg, Matrix &X2){
  //rg=gauss[ig]
  //sg=gauss[jg]

  //Numerated as in Bathe
  Matrix Ns(1,4);
  Ns.Set(0,0,(1+rg)*(1+sg));
  Ns.Set(0,0,(1-rg)*(1+sg));
  Ns.Set(0,0,(1-sg)*(1-rg));  
  Ns.Set(0,0,(1+rg)*(1-sg));
  // Ns  =0.25*matrix([(1+sg)*(1+rg),(1-rg)*(1+sg),(1-sg)*(1-rg),(1-sg)*(1+rg)])   
  Matrix dHrs(2,4);
  dHrs.Set(0,0,1+sg);  dHrs.Set(0,1,-(1+sg));  dHrs.Set(0,2,-(1-sg));  dHrs.Set(0,3,1-sg);
  dHrs.Set(1,0,1+rg);  dHrs.Set(1,1,1-rg);  dHrs.Set(0,2,-(1-rg));  dHrs.Set(0,3,-(1+rg));
  //dHrs = 0.25 * dHrs;
  Matrix J();
  // J=dHrs*X2
  // dHxy=linalg.inv(J)*dHrs
  // detJ=linalg.det(J)
  // //Calculate shape functions
  // //Bs=J-1 dHrs(B.13)
  // Bs=dHxy
  // for k in range(4):
      // //shape functions
      // Nv[0,2*k  ]=Nv[1,2*k+1]=Ns[0,k]
      // for j in range(4):
          // NsigF[j,4*k+j]=Ns[0,k]

      // //derivatives Bv (B.14)
      // Bv[0,2*k  ]=dHxy[0,k]
      // Bv[1,2*k  ]=dHxy[1,k]
      // Bv[2,2*k+1]=dHxy[0,k]
      // Bv[3,2*k+1]=dHxy[1,k]
      
}

int main(){
  
  return 0;
}