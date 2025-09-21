/*
Problem Statement:
------------------
Given a 9-digit number, check if we can make the number a palindrome
by deleting exactly one digit. 

If possible, return true , otherwise return false.

Constraints:
------------
- Input number will always be a 9-digit integer.

Example 1:
----------
Input: 123456321
Output: true
Explanation: If we delete '4', the number becomes 12356321 which is a palindrome.

Example 2:
----------
Input: 123456789
Output: false
Explanation: No single digit removal can make this a palindrome.

Approach:
---------
1. Convert the number to string for easier manipulation.
2. Use two-pointer technique:
   - Compare characters from left and right.
   - If mismatch occurs, try deleting left or right character once.
   - Check if either resulting substring is a palindrome.
3. Return true if possible, else false.
*/

#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(const string &s, int l, int r) {
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++, r--;
    }
    return true;
}

bool canFormPalindrome(int num) {
    string s = to_string(num);
    int l = 0, r = s.size() - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            return isPalindrome(s, l + 1, r) || isPalindrome(s, l, r - 1);
        }
        l++, r--;
    }
    return true;
}

int main() {
    int num;
    cout << "Enter 9-digit number: ";
    cin >> num;

    if (canFormPalindrome(num))
        cout << "true\n";
    else
        cout << "false\n";
    return 0;
}
