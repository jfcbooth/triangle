/* Make a pyramid of numbers given some integer
  1                          1
  2                       1  2  1
  3                    1  2  3  2  1
  4                 1  2  3  4  3  2 1
  5               1 2  3  4  5  4  3 2 1
  6             1 2 3  4  5  6  5  4 3 2 1
  7           1 2 3 4  5  6  7  6  5 4 3 2 1
  8         1 2 3 4 5  6  7  8  7  6 5 4 3 2 1
  9       1 2 3 4 5 6  7  8  9  8  7 6 5 4 3 2 1
 10     1 2 3 4 5 6 7  8  9 10  9  8 7 6 5 4 3 2 1
 11   1 2 3 4 5 6 7 8  9 10 11 10  9 8 7 6 5 4 3 2 1
 12 1 2 3 4 5 6 7 8 9 10 11 12 11 10 9 8 7 6 5 4 3 2 1

    1 2 3 4 5 6 7 8 9 10 11 12 13 14151617181920212223
*/

#include <iostream>
#include <cmath>
using namespace std;
void pyramid(int height);

int main() 
{
	int height = 0;
	cout << "Enter the number of rows you would like for the pyramid: ";
	cin >> height;
	pyramid(height);

	/* // for height < 100
	int height = 12, extra = 0, position = 0, width = 1, output = 0;

	if (height >= 10) extra = 1; // check if adjusted alignment
	for (int row = 1; row <= height; row++) {
		position = 0;
		if (row >= height - 8) extra = 0;
		int beginning = 2*(height - row) + extra*(height - row - 8);
		for (int i = 1; i <= beginning; i++) { 
			cout << " "; 
			position++; 
		}

		for (int i = 1; i <= row * 2 - 1; i++) { // iterate row from 1:23 (or so)
			cout << row - abs(row - i) << " ";
			position += 2;
			if (row - abs(row - i) >= 10) {
			    position++; 
			}

			if ((row - abs(row - (i + 1)) < 10) && (position >= 18) && (position <= 6 * height - 40)) {
				cout << " "; 
				position++;
			}
		} cout << "\n";
	}
	*/
	/* // for height < 10, no special alignment
    for (int row = 1; row<=height; row++){
	    for (int i = 2*(height-row); i>=0; i--) cout << " "; // initial spaces
	    for (int j = 1; j<=row*2-1; j++) cout << row - abs(row - j) << " "; // count up
        cout << "\n";
    } 
	*/
    return 0;
}

void pyramid(int height) {
	// local variable declaration
	int width = 0;
	
	for (int row = 1; row <= height; row++) {
		for (int i = 1; i <= height + row - 1; i++) { // iterate each column for that row
			width = (log10(height - abs(height - i)) + 1);
			if (i <= height - row) { // output the initial spaces
				for (int k = 0; k <= width; k++) {
					cout << " ";
				}
			}
			if (i > height - row) { // output the numbers
				cout << row - abs(row - (i - height + row)) << " ";
				for (int k = 0; k < width - (log10(row - abs(row - (i - height + row))) + 1); k++) {
					cout << " ";
				}
			}
		} cout << "\n";
	}
}