#include<iostream>
using namespace std;
int grid[9][9]=
	{
		{9,0,0,3,0,2,6,0,0},
		{4,0,7,0,0,8,9,1,3},
		{6,0,3,1,0,0,0,5,4},
		{0,3,0,0,8,0,4,7,0},
		{0,0,8,0,3,0,1,6,0},
		{0,0,4,2,0,0,5,0,0},
		{8,7,1,9,0,6,0,4,5},
		{3,0,0,0,5,0,0,0,0},
		{2,0,0,4,0,0,0,0,1}
	};
void printsudoku()
{
	for(int i=0;i<9;i++)
	{
		for(int j=0;j<9;j++)
		{
			cout<<"\t"<<grid[i][j];
		}
		cout<<endl;
	}
	cout<<endl;
}

bool isvalid(int row, int col, int num)
{	int r,c;
	for(c=0;c<9;c++)
	{
		if(grid[row][c]==num)
		{
			return false;
		}
	}
	for(r=0;r<9;r++)
	{
		if(grid[r][col]==num)
		{
			return false;
		}
	}
	row=row-(row%3);
	col=col-(col%3);
	for(int i=row;i<row+3;i++)
	{
		for(int j=col;j<col+3;j++)
		{
			if(grid[i][j]==num)
			{
				return false;
			}
		}
	}
	return true;

}
void solver()
{	
	for(int i=0;i<9;i++)
	{	
		for(int j=0;j<9;j++)
		{	
			if(grid[i][j]==0)
			{
				for(int n=1;n<10;n++)
				{
					if(isvalid(i,j,n))
					{
						grid[i][j]=n;
						solver();
						grid[i][j]=0;
						
					}
					
				}
				return;
				
			}
			
		}
	}
	cout<<"The Solution: "<<endl;
	printsudoku();
}


int main()
{
	
	cout<<"The Given Sudoku:"<<endl;
	printsudoku();

	solver();	
	
}
