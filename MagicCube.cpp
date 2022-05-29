#include <iostream>
#include<bits/stdc++.h>
using namespace std;

//function to change values of column, row, column as required
int normalize(int n, int index) {
	while (index < 0) {
			index = index + n;
		}
		while (index > n - 1) {
			index = index - n;
		}
		return index;
}
//3d vector array function
vector< vector< vector<int> > > getMagicCube(int n) {
		//when n is odd, using normalize function to make the cube
		if (n % 2 == 1) 
		{
			//initialize 3d vector
	        vector< vector< vector<int> > > magicCube(n, vector< vector<int> >(n , vector<int>(n)));
			// layer index, row index, column index
			int l, r, c;
			l = 0; 
			r = n / 2;
			c = n / 2; //these values to insure we start from middle of first layer if n is odd, i. e, place 1 at middle of first layer

            //make all cells zero for once
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					for (int k = 0; k < n; k++) 
					{
						magicCube[i][j][k] = 0;
					}
				}
			}
			
			int last = (int) pow(n, 3); //to get index of last element
			for (int i = 0; i < last; i++) 
			{
				magicCube[l][r][c] = i + 1;
				l--;
				l = normalize(n, l);
				c--;
				c = normalize(n, c);
				if (magicCube[l][r][c] != 0) {
					r--;
					r = normalize(n, r);
					c++;
					c = normalize(n, c);
					if (magicCube[l][r][c] != 0) {
						r++;
						r = normalize(n, r);
						l += 2;
						l = normalize(n, l);
					}
				}
			}

			return magicCube;
		}
		//for a "doubly even number", using 
		else if (n % 4 == 0) 
		{
			vector< vector< vector<int> > > magicCube(n, vector< vector<int> >(n , vector<int>(n)));
			int lastPlusOne = (int) pow(n, 3) + 1;
			int number = 1;
			int nBy4 = n / 4;
			for (int l = 0; l < n; l++) {
				for (int r = 0; r < n; r++) {
					for (int c = 0; c < n; c++) {
						bool parity = false;
						if (l >= nBy4 && l < 3 * nBy4) {
							parity = true;
						}
						if (r >= nBy4 && r < 3 * nBy4) {
							parity = !parity;
						}
						if (c >= nBy4 && c < 3 * nBy4) {
							parity = !parity;
						}
						magicCube[l][r][c] = (parity) ? lastPlusOne - number
								: number;
						number++;
					}
				}
			}
			return magicCube;
		}
		else
		{
		throw "Pls enter n > 2 , no singly even values";
		}
}

int main(){
	cout<<"What should be the dimension of the cube? (n*n*n) -> ";
	int n;
	cin>>n;
	vector< vector< vector<int> > > magicCube = getMagicCube(n);
	
		for (int i = 0; i < n; i++) 
		{
			for (int j = 0; j < n; j++) 
			{
				for (int k = 0; k < n; k++) 
				{
					if (k != 0) 
					{
						cout<<"  |";
					}
					cout<<magicCube[i][j][k];
				}
				cout<<endl;
			}
			cout<<endl;
			cout<<endl;
		}

}
