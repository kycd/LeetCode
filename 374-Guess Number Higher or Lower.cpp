// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
		private:
				int guessNumber(int min, int max) {
						int mid = (min + max) / 2;
						int guessResult = guess(mid);

						cout << "( " << min << ", " << mid << " ," << max << ") = " << guessResult << endl;
						switch(guessResult) {
								case -1:
										return guessNumber(min, mid - 1);
										break;
								case 1:
										return guessNumber(mid + 1, max);
										break;
								case 0:
										return mid;
										break;
						}
				}
		public:
				int guessNumber(int n) {
						return guessNumber(1, n);
				}
};
