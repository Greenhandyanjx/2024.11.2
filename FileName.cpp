#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int len = nums.size();
        if (len < 3) return false;
        int small = INT_MAX, mid = INT_MAX;
        for (auto num : nums) {
            if (num <= small) {
                small = num;
            }
            else if (num <= mid) {
                mid = num;
            }
            else if (num > mid) {
                return true;
            }
        }
        return false;
    }
};
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3)return false;
        int len = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i + 1] > nums[i])len++;
            else len = 1;
            if (len == 2)return true;
        }
        return false;
    }
};
class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int>st;
        st.push(1);
        for (int i = 0; i < preorder.length(); i++) {
            if (preorder[i] == ',')continue;
            if (isdigit(preorder[i])) {
                if (st.empty())return false;
                while (isdigit(preorder[i]))i++;
                st.top() -= 1;
                if (st.top() == 0)st.pop();
                st.push(2);
            }
            else if (preorder[i] == '#') {
                if (st.empty())return false;
                st.top() -= 1;
            }
            while (!st.empty() && st.top() == 0) {
                st.pop();
            }
        }
        return st.empty();
    }
};
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL)return NULL;
        if (head->next == NULL)return head;
        ListNode* dummyodd = new ListNode();
        ListNode* dummyeven = new ListNode();
        ListNode* odd = head;
        ListNode* even = head->next;
        dummyodd->next = head;
        dummyeven->next = even;
        ListNode* cur = head->next->next;
        int flag = 1;
        while (cur) {
            if (flag % 2 == 1)
            {
                odd->next = cur;
                odd = cur;
            }
            else 
            {
                even->next = cur;
                even = cur;
            }
            cur = cur->next;
            flag++;
        }
        odd->next = dummyeven->next;
        even->next = NULL;
        return dummyodd->next;
    }
};