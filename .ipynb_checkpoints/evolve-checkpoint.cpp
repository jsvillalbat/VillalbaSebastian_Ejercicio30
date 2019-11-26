#include <iostream>
#include <fstream>
#include <cmath>
#include "stdio.h"

void init(double *psi, int n_x);
void print(double *psi, int n_x);
void copy(double *recibe, double *entrega, int n_x);
void evolve(double *psi_new, double *psi_old, double delta_t, double delta_x, int n_x);
double maxcambio(double *psi_new, double *psi_old,int n_x,double delta_t);

int main(int argc, char **argv){

  int n_t;
  int n;
  double t_max=1.0;
  double delta_t=1.0/n_t;


  int n_x[10] = {10,20,30,40,50,60,70,80,90,100};
  //n_t=atoi(argv[2]);

  n_t = 1.0/delta_t;
   std::ofstream outfile1;
   outfile1.open("errorcor"+std::to_string(n_x[0])+".dat");
   std::ofstream outfile;
   outfile.open("errorcero"+std::to_string(n_x[0])+".dat");

  for (int i = 0; i <10;i++)
  {
   double epsilon = 100.0;    
  double *psi = NULL;
  double *psi_past = NULL;    
  psi  = new double [n_x[i]];
  psi_past  = new double [n_x[i]];

  init(psi, n_x[i]);
  //print(psi, n_x[i]);    
  double delta_x = 2.0/n_x[i];
  int iteraciones = 0;   
  while(epsilon > 0.00001)
  {
    copy(psi_past, psi, n_x[i]);
    evolve(psi, psi_past, delta_t, delta_x, n_x[i]);
    //print(psi, n_x);
      
    double cambioiter = maxcambio(psi, psi_past,n_x[i],delta_t);
      
      if(cambioiter < epsilon)
      {
          epsilon = cambioiter;
      }
      iteraciones+=1;
  }
      

    outfile << n_x[i] << "\t"<< std::abs(((-0.5-psi[n_x[i]/2])/-0.5))<<std::endl;
   
      

    outfile1 << n_x[i] << "\t"<< epsilon*1000000<<std::endl;
         
      
    std::cout<<n_x[i]<<"\t"<<iteraciones<<std::endl;
      
  }
    outfile.close();
   outfile1.close();  
  return 0;
}

void evolve(double *psi_new, double *psi_old, double delta_t, double delta_x, int n_x){
  int i;
  double s=1.0;
  for(i=1;i<n_x-1;i++){
    psi_new[i] = psi_old[i];
    psi_new[i] += ((delta_x * delta_x)/2.0)*s + (0.5*psi_old[i+1]-psi_old[i] + 0.5*psi_old[i-1]);
  }
  
}

void copy(double *recibe, double *entrega, int n_x){
  int i;
  for (i=0;i<n_x;i++){
    recibe[i] = entrega[i];
  }
}

void init(double *psi, int n_x){
  int i;
  for(i=0;i<n_x;i++){
    psi[i] = 0.0;
  }
}


void print(double *psi, int n_x){
  int i;
    
  for(i=0;i<n_x;i++){
    std::cout << psi[i]<< " ";
  }
  std::cout << "\n";
}

double maxcambio(double *psi_new, double *psi_old,int n_x,double delta_t)
{
    double max = 0.0;
    double cambio = 0.0;
    for(int i = 0; i<n_x;i++)
    {
        cambio = (psi_new[i] - psi_old[i])/psi_new[i];
        if(cambio >= max)
        {
            max = cambio;
        }
    }
    return max;
}


