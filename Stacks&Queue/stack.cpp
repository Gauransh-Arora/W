#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElements(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n, -1);
    stack<int> st; // stores numbers (not indexes)

    for (int i = n - 1; i >= 0; i--) {

        while (!st.empty() && st.top() <= nums[i])
            st.pop();

        ans[i] = st.empty() ? -1 : st.top();
        
        st.push(nums[i]);
    }

    return ans;
}

vector<int> asteroidCollision(vector<int>& ast) {
    stack<int> st;

    for (int a : ast) {
        bool destroyed = false;

        while (!st.empty() && st.top() > 0 && a < 0) {
            if (abs(a) > abs(st.top())) {
                st.pop();              // top explodes
                continue;              // keep checking collisions
            }
            else if (abs(a) == abs(st.top())) {
                st.pop();              // both explode
                destroyed = true;
                break;
            }
            else {                     // current asteroid explodes
                destroyed = true;
                break;
            }
        }

        if (!destroyed)
            st.push(a);
    }

    // Convert stack to vector
    vector<int> ans(st.size());
    for (int i = st.size() - 1; i >= 0; i--) {
        ans[i] = st.top();
        st.pop();
    }

    return ans;
}
