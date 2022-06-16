#include "Matrix.h"
#include "Mesh.h"
#include <stdio.h>
int numit = 10;

using namespace EuLa;
void calculate_shape_matrices (const double &rg, const double &sg, Matrix &X2){
  //rg=gauss[ig]
  //sg=gauss[jg]

  //Numerated as in Bathe
  Matrix Ns(1,4);
  Ns.Set(0,0,0.25*(1+rg)*(1+sg));
  Ns.Set(0,0,0.25*(1-rg)*(1+sg));
  Ns.Set(0,0,0.25*(1-sg)*(1-rg));  
  Ns.Set(0,0,0.25*(1+rg)*(1-sg));
  // Ns  =0.25*matrix([(1+sg)*(1+rg),(1-rg)*(1+sg),(1-sg)*(1-rg),(1-sg)*(1+rg)])   
  Matrix dHrs(2,4);
  dHrs.Set(0,0,1+sg);  dHrs.Set(0,1,-(1+sg));  dHrs.Set(0,2,-(1-sg));  dHrs.Set(0,3,1-sg);
  dHrs.Set(1,0,1+rg);  dHrs.Set(1,1,1-rg);    dHrs.Set(0,2,-(1-rg));  dHrs.Set(0,3,-(1+rg));
  //dHrs = 0.25 * dHrs;
  Matrix J(2,2);
  J=dHrs*X2;
  Matrix dHxy(2,4);
  dHxy = J.Inv()*dHrs;
  // dHxy=linalg.inv(J)*dHrs
  // detJ=linalg.det(J)
  // //Calculate shape functions
  // //Bs=J-1 dHrs(B.13)
  // Bs=dHxy
  Matrix Bv(4,8);
  for (int i=0;i<4;i++){
    Bv.Set(0,2*i  ,dHxy(0,i));
    Bv.Set(1,2*i  ,dHxy(1,i));
    Bv.Set(2,2*i+1,dHxy(0,i));
    Bv.Set(3,2*i+1,dHxy(1,i));
  }
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

int main() {
  Matrix X2(4,2);  //Nodes
  Mesh mesh; 
  
  int it = 0;
  
  while (it < numit){
    printf("Iteration: %d from %d \n",it, numit);
    //Clean Global Matrices for assembly
    //print ("Kglob",Kglob)
    // for idof in range(dof):
        // Rglob [idof] = 0.
        // for jdof in range(dof):
            // Kglob[idof,jdof] = 0.  
////////////////////////////ELEMENT LOOP  ----------------
    for (int e = 0; e < mesh.elcount;e++){  
        // #Obtain Ve from global
        // Kt=Kzero
        // R=Rzero
        // Kel=0.
        // for n in range(4):
            // X2[n]=mesh.node[elnodes.astype(int)[e][n]]
        // #print ("Element ", e)
        // #print ("Element Nodes")
        // #print ("X2",X2)
        
        // dHrs=matrix([[(1+0.),-(1+0.),-(1-0.),(1-0.)], [(1+0.),(1-0.),-(1-0.),-(1+0.)] ])
        // J=dHrs*X2
        // lx=J[0,0]/2.
        // ly=J[1,1]/2.
        // #print("J,lx,ly",J,lx,ly)
        // for ig in range(2):
            // for jg in range(2):
                // rg=gauss[ig]
                // sg=gauss[jg]
                // detJ=0.
                // Nv,NsigF,Ns,Bv,BsigF,BFvp=calculate_shape_matrices (rg, sg,X2)  
    }//Element loop
    it++;
  }//while it 
  return 0;
}