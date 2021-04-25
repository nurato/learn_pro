class Solution {
public:
    vector<pair<int,int>> delta = {{0,1}, {-1,0}, {0,-1}, {1,0}};
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // direction: 北-0 西-1 南-2 东-3 在MOD4 的条件下
        int direction = 0;
        int x = 0, y = 0;
        int res = 0;
        set<pair<int,int>> obset;
        for(const auto &v : obstacles)
            obset.insert({v[0], v[1]});
        for(const auto &command : commands) {
            if (command == -1)
                direction--;
            else if (command == -2)
                direction++;
            else {
                int cur_dir = (direction+400000) % 4;
                int len = command;
                while(len) {
                    int nxt_x = x + delta[cur_dir].first;
                    int nxt_y = y + delta[cur_dir].second;
                    if(!obset.count({nxt_x, nxt_y})) {
                        x = nxt_x; y = nxt_y;
                    }
                    len--;
                    res = max(res, x*x+y*y);
                }
            }
        }
        return res;
    }
};
