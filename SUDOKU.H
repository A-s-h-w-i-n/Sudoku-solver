   void display4(int a[4][4])
  {int i,j;

   cout<<"                         -------------\n";
   for(i=0; i<2; i++)
  {cout<<"                         | ";
   for(j=0; j<2; j++)
  {if(a[i][j]!=0)
   cout<<a[i][j]<<" ";
   else
   cout<<"  "; }
   cout<<"| ";
   for(j=2; j<4; j++)
  {if(a[i][j]!=0)
   cout<<a[i][j]<<" ";
   else
   cout<<"  "; }
   cout<<"|\n"; }
   cout<<"                         |-----|-----|\n";
   for(i=2; i<4; i++)
  {cout<<"                         | ";
   for(j=0; j<2; j++)
  {if(a[i][j]!=0)
   cout<<a[i][j]<<" ";
   else
   cout<<"  "; }
   cout<<"| ";
   for(j=2; j<4; j++)
  {if(a[i][j]!=0)
   cout<<a[i][j]<<" ";
   else
   cout<<"  "; }
   cout<<"|\n"; }
   cout<<"                         -------------";  }


  void display9(int a[9][9])
  {int i,j;

   cout<<"                         -------------------------\n";
   for(i=0; i<3; i++)
  {cout<<"                         | ";
   for(j=0; j<3; j++)
  {if(a[i][j]!=0)
   cout<<a[i][j]<<" ";
   else
   cout<<"  "; }
   cout<<"| ";
   for(j=3; j<6; j++)
  {if(a[i][j]!=0)
   cout<<a[i][j]<<" ";
   else
   cout<<"  "; }
   cout<<"| ";
   for(j=6; j<9; j++)
  {if(a[i][j]!=0)
   cout<<a[i][j]<<" ";
   else
   cout<<"  "; }
   cout<<"|\n"; }
   cout<<"                         |-------|-------|-------|\n";
   for(i=3; i<6; i++)
  {cout<<"                         | ";
   for(j=0; j<3; j++)
  {if(a[i][j]!=0)
   cout<<a[i][j]<<" ";
   else
   cout<<"  "; }
   cout<<"| ";
   for(j=3; j<6; j++)
  {if(a[i][j]!=0)
   cout<<a[i][j]<<" ";
   else
   cout<<"  "; }
   cout<<"| ";
   for(j=6; j<9; j++)
  {if(a[i][j]!=0)
   cout<<a[i][j]<<" ";
   else
   cout<<"  "; }
   cout<<"|\n"; }
   cout<<"                         |-------|-------|-------|\n";
   for(i=6; i<9; i++)
  {cout<<"                         | ";
   for(j=0; j<3; j++)
  {if(a[i][j]!=0)
   cout<<a[i][j]<<" ";
   else
   cout<<"  "; }
   cout<<"| ";
   for(j=3; j<6; j++)
  {if(a[i][j]!=0)
   cout<<a[i][j]<<" ";
   else
   cout<<"  "; }
   cout<<"| ";
   for(j=6; j<9; j++)
  {if(a[i][j]!=0)
   cout<<a[i][j]<<" ";
   else
   cout<<"  "; }
   cout<<"|\n"; }
   cout<<"                         -------------------------\n";   }


void init4(int b[4][4][4])
{ int i,j,k;
for(i=0;i<4;i++)
for(j=0;j<4;j++)
for(k=0;k<4;k++)
b[i][j][k] = k+1;
}

void init9(int b[9][9][9])
{ int i,j,k;
for(i=0;i<9;i++)
for(j=0;j<9;j++)
for(k=0;k<9;k++)
b[i][j][k] = k+1;
}