#include<iostream>						//mtrx[maxsize][maxsize][0] will be the first input
using namespace std;					//mtrx[maxsize][maxsize][1] will be the second input				
const int maxsize = 10;					//mtrx[maxsize][maxsize][2] will be the output
int main() {
	int size, sum = 0;
	int mtrx[maxsize][maxsize][4];
	cout << "Enter the number of rows and columns = "; cin >> size;						//even though we have row and col as constant they exist to fill the requirement of an array					//here we give the actual size of the matrix array
	cout << "\nEnter the numbers for a " << size << " X " << size << " matrix " << endl;													//if rows and cols are the same there wont be any need of adjusting 
	for (int z = 0; z < 2; z++) {										//z acts as a layer counter x y z
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				cin >> mtrx[x][y][z];									//if z is 0 u input the first matrix then z turns into 1 and u input the second matrix
				if(z==1){
					mtrx[x][y][3] = mtrx[x][y][1] + mtrx[x][y][0];
				}
			}
		}
		if (z == 0) {													//while inputting a message will appear when you are done with the first matrix
			cout << "\nEnter the numbers for the second " << size << " X " << size << " matrix " << endl;
		}
	}													//the proccess for the multiplication matrixes
		for (int z = 0; z < 2; z++) {
			for (int x = 0; x < size; x++) {
				for (int y = 0; y < size; y++) {
					mtrx[x][y][2] = 0;
					for (int r = 0; r < size; r++) {
						mtrx[x][y][2] += mtrx[x][r][0] * mtrx[r][y][1];		
					}
				}
			}
		}
		cout << "\nAddition Result of Two Given Matrix is:\n";				//output of Addition
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				cout << mtrx[x][y][3] << "  ";
			}
			cout << endl;
		}
		cout << "\nMultiplication Result of Two Given Matrix is:\n";		//output of Multiplication
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++) {
				cout << mtrx[x][y][2] << " ";
			}
			cout << endl;
		}
	return 0;
}
/* first line is rows cols then the inputs (personal use to not write constantly (line 75 and under)
3 2
2 3
4 2
4 1
3 2 1
4 3 2
*/