#include <iostream>
#include <vector>

using namespace std;

class TrappingRainWater
{
public:
    // Function to calculate trapped rainwater
    int trapping_rain_water(vector<int> &A)
    {
        int res = 0; 
        int N = A.size();

        int left = 0, right = N - 1;     // Pointers to track left and right boundaries
        int left_max = 0, right_max = 0; //To track maximum heights from left and right

        
        while (left <= right)
        {
            // If height at left pointer is less than height at right pointer
            if (A[left] < A[right])
            {
                // If the height at left pointer is greater than the maximum height encountered so far on the left
                if (A[left] > left_max)
                {
                    left_max = A[left]; // Update the maximum height on the left
                }
                else
                {
                    res += left_max - A[left]; // Add trapped rainwater calculated from left side
                }
                left = left + 1; // Move the left pointer to the right
            }
            else // If height at right pointer is less than or equal to height at left pointer
            {
                // If the height at right pointer is greater than the maximum height encountered so far on the right
                if (A[right] > right_max)
                {
                    right_max = A[right]; // Update the maximum height on the right
                }
                else
                {
                    res += right_max - A[right]; // Add trapped rainwater calculated from right side
                }
                right = right - 1; // Move the right pointer to the left
            }
        }
        return res;
    }
};

int main()
{
    //Instance of the TrappingRainWater class
    TrappingRainWater trappedwater;

    //Input
    vector<int> heights = {2,1,3,0,1,2,3};
       
    // Output the result
    cout << "Trapped Rainwater: " << trappedwater.trapping_rain_water(heights) << endl;

    return 0;
}
