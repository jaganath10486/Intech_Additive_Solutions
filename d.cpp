#include <iostream>
#include <cmath>
using namespace std;

class ConsecutiveCounter
{
public:
    // Function to count the number of ways to express N as sum of consecutive numbers
    long int countConsecutive(long int N)
    {
        long int count = 0;
        // Loop to find consecutive numbers whose sum equals N
        for (long int L = 1; L * (L + 1) < 2 * N; L++)
        {
            // Calculate the possible consecutive number series using arithmetic progression formula
            double a = (1.0 * N - (L * (L + 1)) / 2) / (L + 1);
            // Check if 'a' is an integer, indicating a valid consecutive number series
            if (a - (int)a == 0.0)
                count++; // If 'a' is integer, increment the count
        }
        return count;
    }
};

int main()
{
    ConsecutiveCounter cnt;

    long int N = 15;
    cout << "Number of ways to express " << N << " as sum of consecutive numbers: " << cnt.countConsecutive(N) << endl;

    N = 10;
    cout << "Number of ways to express " << N << " as sum of consecutive numbers: " << cnt.countConsecutive(N) << endl;

    return 0;
}
