#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to compress the input string
vector<string> compress(string s)
{
    int num = s.length();
    int i = 0;
    vector<string> s1;

    // Iterate through the string
    while (i < num)
    {
        int repetition = 1;
        // Count consecutive occurrences of characters
        while (i < num - 1 && s[i] == s[i + 1])
        {
            repetition++;
            i++;
        }
        // Store the character and its repetition count
        s1.push_back(string(1, s[i]));
        s1.push_back(to_string(repetition));
        i++;
    }
    return s1;
}

// Function to optimize the compressed string
vector<string> optimizer(vector<string> s)
{
    vector<string> result;
    char last_char = s[0][0];
    int count = stoi(s[1]);

    // Iterate through the compressed string
    for (int i = 2; i < s.size(); i += 2)
    {
        char current_char = s[i][0];
        int current_count = stoi(s[i + 1]);

        // If the count matches the previous count, compress it further
        if (current_count == count)
        {
            result.push_back(string(1, last_char));
            last_char = current_char;
        }
        // If the count is different, store the previous character and its count
        else
        {
            result.push_back(string(1, last_char));
            result.push_back(to_string(count));
            last_char = current_char;
            count = current_count;
        }
    }

    // Store the last character and its count
    result.push_back(string(1, last_char));
    result.push_back(to_string(count));

    return result;
}

// Function to expand the compressed string
string expand(vector<string> s)
{
    string exp = "";
    int num = 0;
    vector<int> l;
    vector<char> ch;

    // Iterate through the compressed string
    for (int m = 0; m < s.size(); m++)
    {
        // If the string is a digit, store it in the count vector
        if (isdigit(s[m][0]))
        {
            l.push_back(stoi(s[m]));
            // If it's the last element, expand the characters based on their counts
            if (m == s.size() - 1)
            {
                num = 0;
                int k = 0;
                for (int i = l.size() - 1; i >= 0; i--)
                {
                    num = num + l[i] * pow(10, k);
                    k++;
                }
                l.clear();
                for (char ch1 : ch)
                {
                    for (int i = 0; i < num; i++)
                    {
                        exp += ch1;
                    }
                }
                ch.clear();
            }
        }
        // If the string is a character, store it in the character vector
        else
        {
            // If there are counts stored previously, expand the characters accordingly
            if (l.size() != 0)
            {
                num = 0;
                int k = 0;
                for (int i = l.size() - 1; i >= 0; i--)
                {
                    num = num + l[i] * pow(10, k);
                    k++;
                }
                l.clear();
                for (char ch1 : ch)
                {
                    for (int i = 0; i < num; i++)
                    {
                        exp += ch1;
                    }
                }
                ch.clear();
            }
            // Store the character
            ch.push_back(s[m][0]);
        }
    }
    return exp;
}

// Function to convert vector of strings to a single string
string vector_to_string(vector<string> vec)
{
    string result;
    for (const auto &str : vec)
    {
        result += str;
    }
    return result;
}

int main()
{
    string string_to_compress = "aabcccccaaa";

    // Compress the input string
    vector<string> compressed_first = compress(string_to_compress);
    // Optimize the compressed string
    vector<string> compressed_second = optimizer(compressed_first);
    // Expand the optimized compressed string
    string ans = expand(compressed_second);

    cout << "Original String: " << string_to_compress << endl;
    cout << "First compressed String: " << vector_to_string(compressed_first) << endl;
    cout << "Second compressed String: " << vector_to_string(compressed_second) << endl;
    cout << ans << endl;

    return 0;
}
