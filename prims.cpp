#include<iostream>
#include<string>
#define SIZE 10
#define INFINITY 999
using namespace std;

class MST
{
   int graph[SIZE][SIZE],vertex,v1,v2;
   public:
      MST()
      {
        for(int i=0;i<SIZE;i++)  //initialise graph
         { for(int j=0;j<SIZE;j++)
             graph[i][j]=0;    }
       }
       
     void find_PrimsMST()
       {
         int select[SIZE],i,j,k,min_dist,total=0;
         for(i=0;i<vertex;i++)
             select[i]=0;
           cout<<"\n The Minimum Spanning Tree ";
           select[0]=1;
           for(k=1;k<vertex;k++)
           {
             min_dist=INFINITY;
             for(i=0;i<vertex;i++)
             {
               for(j=0;j<vertex;j++)
                {
                  if(graph[i][j] && ((select[i] && !select[j]) || (!select[i] && select[j])))
                     {
                       if(graph[i][j] <min_dist)
                         {
                           min_dist=graph[i][j];
                           v1=i;
                           v2=j;
                           }
                       }
                  }
              }
              cout<<" \n Edge (" <<v1 <<" " <<v2<<")"<<min_dist;
              select[v1]=select[v2]=1;
              total=total+min_dist;
            }
            cout<<"\n Total Distance: "<<total;
            cout<<"\n";
        }
       void get_data()
       { 
         int len,n;
         cout<<"\n Enter number of departments in the college ";
         cin>>vertex;
         cout<<"\n Enter number of edges :";
         cin>>n;
         cout<<"\n Enter edges and weights ";
         for(int i=0;i<n;i++)
          {
             cout<<"\n Enter Edge by V1 and V2: ";
             cin>>v1>>v2;
             cout<<"\n Enter Corresponding Distance between two vertex : ";
             cin>>len;
             graph[v1][v2]=graph[v2][v1]=len;
           }
        }   
        void printmatrix()
        {
         cout<<"\n Adjacency Matrix for departments in college :\n";
         for(int i=0;i<vertex;i++)
          {for(int j=0;j<vertex;j++)
            cout<<" "<<graph[i][j];
            cout<<"\n";
           } 
        }
          
     };
     
     int main()
     {
       MST mt;
       cout<<"\n\n Prim's Algorithm ";
       mt.get_data();
       mt.printmatrix();
       cout<<"\n \n";
       mt.find_PrimsMST();
      } 
               
                  
                           
             
