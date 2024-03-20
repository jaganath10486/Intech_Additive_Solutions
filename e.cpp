#include <iostream>
#include <string>

using namespace std;

class PiAnalyzer
{
public:
    // Function to check if a number is prime
    bool isPrime(int num)
    {
        if (num <= 1)
            return false;
        if (num <= 3)
            return true;
        if (num % 2 == 0 || num % 3 == 0)
            return false;
        for (int i = 5; i * i <= num; i += 6)
        {
            // If divisibility by numbers of the form 6k +/- 1
            if (num % i == 0 || num % (i + 2) == 0)
            {
                return false; // If divisible by i or i + 2, not prime
            }
        }
        return true;
    }

    // Function to find the largest 5-digit prime in the first 100 digits of Pi.
    int findLargestPrimeInPi()
    {
        string piDigits = "31415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";

        int largestPrime = -1;

        // Iterate through every 5-digit substring of the first 100 digits of Pi
        for (int i = 0; i <= 95; i++)
        {
            string sub = piDigits.substr(i, 5); // Extract a 5-digit substring
            int num = stoi(sub);                // Convert the substring to an integer stoi or atoi for integer conversion
            if (isPrime(num))
            {
                // If the integer is prime
                if (num > largestPrime)
                {
                    largestPrime = num; // Update largest prime if necessary
                }
            }
        }
        return largestPrime;
    }
};

int main()
{
    PiAnalyzer analyzer;
    int largestPrime = analyzer.findLargestPrimeInPi(); 

    if (largestPrime != -1)
    {
        cout << "The largest 5-digit prime number in the first 100 digits of Pi is: " << largestPrime << endl;
    }
    else
    {
        cout << "5-digit prime number not found in the first 100 digits of Pi." << endl;
    }

    return 0;
}
