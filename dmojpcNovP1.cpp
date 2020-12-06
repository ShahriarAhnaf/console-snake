#include <bits/stdc++.h>

using namespace std;


int main() {
	int n; cin >> n;
	char grid[2*n][n];
	memset(grid, '.', sizeof(grid));
	
	bool print[2*n];
	short int row= n;
	short int last = row;
	memset(print, false, sizeof(print));
		
	for (int p=0; p < n; p++)
	{
		char x;
		cin >> x;
		if (x == '^')
		{
			grid[row][p]= '/';
			print[row] = true;
			row--;
			last = row + 1;
		}
		else if (x == 'v')
		{	
			grid[row][p]= '\\';
		print[row] = true;
			row++;
			last = row - 1;
		}
		else if (x == '>')
		{
			
				grid[last][p]= '_';
			
			row = last;
			print[last] = true;
			
		}
		
	}
	
	for(int y=0; y < 2*n; y++)
	{
		{
			if(print[y]) 
			{
				for(int x=0; x<n; x++)
				{
					 cout << grid[y][x];
				}
			}
			if (print[y]) cout << endl;
		}
	}
}
