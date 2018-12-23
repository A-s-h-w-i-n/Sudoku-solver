#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<stdlib.h>
#include"sudoku.h"

struct sudoku
{ int num; };

void main()
{ randomize();
  int a[4][4],b[4][4][4],c[9][9],d[9][9][9],t,j,l,k,n,u,x,temp;
  int count4=0, count9=0, z=0, z1=0, i=0;
  sudoku s;
  ifstream f4, f9;

  f4.open("sudoku4.dat");
  f4.seekg(0,ios::end);
  count4 = (f4.tellg()+1)/32;

  f9.open("sudoku9.dat");
  f9.seekg(0,ios::end);
  count9 = (f9.tellg()+1)/162;

start:
clrscr();
cout<<"\n\n                           _________________________";
cout<<"\n                           |   THE SUDOKU SOLVER   |";
cout<<"\n                           |~~~~~~~~~~~~~~~~~~~~~~~|";
cout<<"\n                           |---|---|---|---|---|---|";
cout<<"\n\n\n\n  1) 4 X 4 SUDOKU SOLVER";
cout<<"\n\n  2) 9 X 9 SUDOKU SOLVER";
cout<<"\n\n  3) HELP";
cout<<"\n\n  4) EXIT";
cout<<"\n\n\n  ENTER YOUR CHOICE (1-4): ";
cin>>t;

if(t==1)
{  clrscr();
   cout<<"\n\n\n\n                             4 X 4 SUDOKU SOLVER";
   cout<<"\n                          -------------------------";

   cout<<"\n\n\nENTER THE SUDOKU ELEMENTS:                         (enter 9 to exit at any time)";
   cout<<"\n                                                   (enter 8 to run sample)\n";

   for(i=0; i<4; i++)
   for(j=0; j<4; j++)
 { cin>>a[i][j];;

   if(a[i][j]==9)
   goto start;

   else if(a[i][j]==8)
   { temp = random(count4);
     f4.seekg(32*temp);

     for(i=0; i<4; i++)
    {  for(j=0; j<4; j++)
      { f4.read((char*)&s, sizeof(s));
	a[i][j] = s.num;			}  }
     break;	  }
			 }

   cout<<"\n\n";
   cout<<"  SUDOKU GRID ENTERED:\n";
   display4(a);

   cout<<"\n\n  press enter to solve. press e to go to home screen";
   x = getch();
   if(x==13)

{ for(u=0; u<50; u++)
 { init4(b);
   for(i=0; i<4; i++)
 { for(j=0; j<4; j++)
 {
   if(a[i][j]==0)
 { for(l=0; l<4; l++)
 { z = 0;
   k = b[i][j][l];
   for(n=0; n<4; n++)
 { if((a[i][n]==k)||(a[n][j]==k))
   z++;   }

   if((i<2)&&(j<2)&&((a[0][0]==k)||(a[0][1]==k)||(a[1][0]==k)||(a[1][1]==k)))
   z++;
   else if((i<2)&&(j>=2)&&((a[0][2]==k)||(a[0][3]==k)||(a[1][2]==k)||(a[1][3]==k)))
   z++;
   else if((i>=2)&&(j<2)&&((a[2][0]==k)||(a[2][1]==k)||(a[3][0]==k)||(a[3][1]==k)))
   z++;
   else if((i>=2)&&(j>=2)&&((a[2][2]==k)||(a[2][3]==k)||(a[3][2]==k)||(a[3][3]==k)))
   z++;
   if(z!=0)
   b[i][j][l] = 0;
			}  }  }  }

   for(i=0; i<4; i++)
   for(j=0; j<4; j++)
 { for(l=0; l<4; l++)
   if(b[i][j][l]!=0)
   z1++;

   if(z1==1)
   for(l=0; l<4; l++)
   if(b[i][j][l]!=0)
 { a[i][j] = b[i][j][l];
   break;    }

    z1 = 0;       }  }

 cout<<"\n\nSOLVED SUDOKU GRID: \n";
 display4(a);
 cout<<"\n\n                    press enter to continue";

   getch();
   goto start;  }

   else
   goto start;  }

else if(t==2)
{  clrscr();
   cout<<"\n\n\n                            9 X 9 SUDOKU SOLVER";
   cout<<"\n                          -----------------------";

   cout<<"\n\n\nENTER THE SUDOKU ELEMENTS:                        (enter 99 to exit at any time)\n\n";
   cout<<"\n                                                   (enter 98 to run sample)\n";

   for(i=0; i<9; i++)
   for(j=0; j<9; j++)
 { cin>>c[i][j];;
   if(c[i][j]==99)
   goto start;

    else if(c[i][j]==98)
   { temp = random(count9);
     f9.seekg(temp*162);

     for(i=0; i<9; i++)
    {  for(j=0; j<9; j++)
      { f9.read((char*)&s, sizeof(s));
	c[i][j] = s.num;			}  }
     break;	  }
		       }

   cout<<" \n\n SUDOKU GRID ENTERED:\n";
   display9(c);

   cout<<"\n\n  press enter to solve. press e to go to home screen";
   x = getch();

 if(x==13)
{
  for(u=0; u<81; u++)
 { init9(d);
   for(i=0; i<9; i++)
 { for(j=0; j<9; j++)
 {
   if(c[i][j]==0)
 { for(l=0; l<9; l++)
 { z = 0;
   k = d[i][j][l];

   for(n=0; n<9; n++)
 { if((c[i][n]==k)||(c[n][j]==k))
   z++;   }

   if((i<3)&&(j<3)&&((c[0][0]==k)||(c[0][1]==k)||(c[0][2]==k)||(c[1][0]==k)||(c[1][1]==k)||(c[1][2]==k)||(c[2][0]==k)||(c[2][1]==k)||(c[2][2]==k)))
   z++;
   else if((i>=3)&&(i<6)&&(j<3)&&((c[3][0]==k)||(c[3][1]==k)||(c[3][2]==k)||(c[4][0]==k)||(c[4][1]==k)||(c[4][2]==k)||(c[5][0]==k)||(c[5][1]==k)||(c[5][2]==k)))
   z++;
   else if((i>=6)&&(j<3)&&((c[6][0]==k)||(c[6][1]==k)||(c[6][2]==k)||(c[7][0]==k)||(c[7][1]==k)||(c[7][2]==k)||(c[8][0]==k)||(c[8][1]==k)||(c[8][2]==k)))
   z++;
   else if((i<3)&&(j>=3)&&(j<6)&&((c[0][3]==k)||(c[0][4]==k)||(c[0][5]==k)||(c[1][3]==k)||(c[1][4]==k)||(c[1][5]==k)||(c[2][3]==k)||(c[2][4]==k)||(c[2][5]==k)))
   z++;
   else if((i>=3)&&(i<6)&&(j>=3)&&(j<6)&&((c[3][3]==k)||(c[3][4]==k)||(c[3][5]==k)||(c[4][3]==k)||(c[4][4]==k)||(c[4][5]==k)||(c[5][3]==k)||(c[5][4]==k)||(c[5][5]==k)))
   z++;
   else if((i>=6)&&(j>=3)&&(j<6)&&((c[6][3]==k)||(c[6][4]==k)||(c[6][5]==k)||(c[7][3]==k)||(c[7][4]==k)||(c[7][5]==k)||(c[8][3]==k)||(c[8][4]==k)||(c[8][5]==k)))
   z++;
   else if((i<3)&&(j>=6)&&((c[0][6]==k)||(c[0][7]==k)||(c[0][8]==k)||(c[1][6]==k)||(c[1][7]==k)||(c[1][8]==k)||(c[2][6]==k)||(c[2][7]==k)||(c[2][8]==k)))
   z++;
   else if((i>=3)&&(i<6)&&(j>=6)&&((c[3][6]==k)||(c[3][7]==k)||(c[3][8]==k)||(c[4][6]==k)||(c[4][7]==k)||(c[4][8]==k)||(c[5][6]==k)||(c[5][7]==k)||(c[5][8]==k)))
   z++;
   else if((i>=6)&&(j>=6)&&((c[6][6]==k)||(c[6][7]==k)||(c[6][8]==k)||(c[7][6]==k)||(c[7][7]==k)||(c[7][8]==k)||(c[8][6]==k)||(c[8][7]==k)||(c[8][8]==k)))
   z++;

   if(z!=0)
   d[i][j][l] = 0;
			}  }  }  }

   for(i=0; i<9; i++)
   for(j=0; j<9; j++)
 { for(l=0; l<9; l++)
   if(d[i][j][l]!=0)
   z1++;

   if(z1==1)
   for(l=0; l<9; l++)
   if(d[i][j][l]!=0)
 { c[i][j] = d[i][j][l];
   break;    }

    z1 = 0;      }   }

   cout<<"\n\nSOLVED SUDOKU GRID: \n";
   display9(c);
   cout<<"\n\n                          press enter to continue";
   getch();
   goto start;  }

   else
   goto start;  }

else if(t==3)
{ clrscr();
  cout<<"\n\n                                 HOW TO USE ?";
  cout<<"\n\n\n(*) ENTER THE DIGITS ROW-WISE.";
  cout<<"\n\n(*) ENTER ZEROS(0) FOR BLANK PLACES";
  cout<<"\n\n\n                                    ENJOY!";
  cout<<"\n\n\n                         press any key to continue.";
 getch();
 goto start;       }

else
exit(0);

	    }