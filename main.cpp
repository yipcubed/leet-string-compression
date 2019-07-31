#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"
// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"


// https://leetcode.com/problems/string-compression/

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    int compress(vector<char> &chars) {
        // anchor points to base char to keep
        int write = 0, anchor = 0;
        for (int read = 0; read < chars.size(); ++read) {
            if (read + 1 == chars.size() || chars[read] != chars[read + 1]) {
                chars[write++] = chars[anchor];
                int count = read - anchor + 1;
                if (count > 1) {
                    for (char c: to_string(count)) {
                        chars[write++] = c;
                    }
                }
                anchor = read + 1;
            }
        }
        return write;
    }
};

void test1() {
    vector<char> v1{'a', 'a', 'b', 'b', 'c', 'c', 'c'};


    cout << "6 ? " << Solution().compress(v1) << v1 << endl;

    vector<char> v2{'a'};


    cout << "1 ? " << Solution().compress(v2) << v2 << endl;
}

void test2() {

}

void test3() {

}