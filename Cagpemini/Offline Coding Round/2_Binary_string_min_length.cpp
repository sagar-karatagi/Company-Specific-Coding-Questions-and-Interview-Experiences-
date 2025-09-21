/*
Problem Statement:
------------------
You are given a binary string. You may repeatedly delete:
1. Adjacent "00"
2. Adjacent "10"

After each deletion, the string shrinks. Continue until no more deletions are possible.
Return the minimum length of the string.

Constraints:
------------
- 1 <= |s| <= 10^5
- s contains only '0' and '1'.

Examples:
---------
Input: "100"
Process:
- Delete "10" -> "0"
No more deletions possible.
Output: 1

Input: "1100"
Process:
- Delete "00" -> "11"
No more deletions possible.
Output: 2

Input: "1000"
Process:
- Delete "00" -> "10"
- Delete "10" -> ""
Output: 0

Approach:
---------
- Use stack to simulate operations.
- Traverse characters:
  - If top + current == "00" or "10", pop top (delete pair).
  - Else push current.
- Result is stack size.
*/

#include <bits/stdc++.h>
using namespace std;

int reduceBinaryString(const string &s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty()) {
            char top = st.top();
            if ((top == '0' && c == '0') || (top == '1' && c == '0')) {
                st.pop(); // delete pair
                continue;
            }
        }
        st.push(c);
    }
    return st.size();
}

int main() {
    string s;
    cout << "Enter binary string: ";
    cin >> s;

    cout << "Minimum length after operations: "
         << reduceBinaryString(s) << "\n";
}
