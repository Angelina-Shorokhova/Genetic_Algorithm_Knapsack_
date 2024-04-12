#include "Solver.h"
#include <iostream>

using namespace std;


    int Solver::competition(int q,int x,int y,vector<vector<int>> t){
    int i,j;
    srand(q+35);
    i=rand()%x;
    j=rand()%x;
    while(t[i]==t[j])
       j=rand()%x;
    if(t[i][y-1]>t[j][y-1])
      return i;
    else 
      return j;
    }
    
    Solver::Solver(string f_name): Parser(f_name){
    int num=170; //population size (per generation)
    int num_generation=7000;//number of generations
    //these numbers must be high enough for the solution to converge to the optimal one
    
    vector<vector<int>> vec(num,vector<int>(n+1));
    int b;
    srand(time(0));
    //creating sets
     for(int j=0;j<num;j++){
        for(int l=0;l<n;l++){
         b=rand()%1500; //if n is large enough, for better convergence, you need to increase the probability of zeros in order to consider fewer overweight situations
           if(b>20)     
             vec[j][l]=0;
           else 
             vec[j][l]=1;
        }
     }
     
      //check correctness
  /*  cout<<"Population 0"<<endl;
      for(int j=0;j<num;j++){
        for(int l=0;l<n+1;l++){
         cout<<vec[j][l]<<" ";
        }
        cout<<endl;
    }*/
    for(int i=0;i<num_generation;i++){
     //adding value to sets
      for(int j=0;j<num;j++){
        int value=0,weight=0;
        for(int l=0;l<n;l++)
          weight+=w[l]*vec[j][l];
        if(weight<=K){
          for(int l=0;l<n;l++)
             value+=v[l]*vec[j][l];
        }
        vec[j][n]=value;
     }
    
    //competition of parents and the appearance of descendants
    vector<vector<int>> vec2(num,vector<int>(n+1));
    for(int j=0;j<num;j+=2){
      int parent1,parent2;
      parent1=competition(j,num,n+1,vec);
      parent2=competition(j+10,num,n+1,vec);
      //cout<<"p1="<<parent1<<endl;
      //cout<<"p2="<<parent2<<endl;
      for(int l=0;l<round(n/2);l++){
        vec2[j][l]=vec[parent1][l];
        vec2[j+1][l]=vec[parent2][l];
      }
      for(int l=round(n/2);l<n;l++){
        vec2[j][l]=vec[parent2][l];
        vec2[j+1][l]=vec[parent1][l];
      }
      //possible mutation of children
      int m1;
      if(rand()%2){
         m1=rand()%n;
      if (vec2[j][m1]==0) 
         vec2[j][m1]=1;
      else
         vec2[j][m1]=1;
    }
    if(rand()%2){
      m1=rand()%n;
      if (vec2[j+1][m1]==0) 
         vec2[j+1][m1]=1;
      else
         vec2[j+1][m1]=1;
    }

    }
      for(int j=0;j<num;j++)
        for(int l=0;l<n;l++)
         vec[j][l]=vec2[j][l];
           
      for(int j=0;j<num;j++){
        vec2[j].clear();
        }
       vec2.clear();
    }
    
    for(int j=0;j<num;j++){
       int value=0,weight=0;
       for(int l=0;l<n;l++)
         weight+=w[l]*vec[j][l];
       if(weight<=K){
         for(int l=0;l<n;l++)
            value+=v[l]*vec[j][l];
       }
       vec[j][n]=value;
     }
    //check correctness
    /* cout<<"Population "<<num_generation<<endl;
      for(int j=0;j<num;j++){
        for(int l=0;l<n+1;l++){
         cout<<vec[j][l]<<" ";
        }
        cout<<endl;
    }
    */
    int max=0;
    for(int l=0;l<num;l++){
       if(vec[l][n]>vec[max][n]){
         max=l;}}
         int wt=0;
    for(int l=0;l<n;l++)
         wt+=w[l]*vec[max][l];
         

   // cout<<"Result:"<<endl;
    cout<<vec[max][n]<<" "<<K-wt<<endl;
     for(int l=0;l<n;l++)
         cout<<vec[max][l]<<" ";
    }
