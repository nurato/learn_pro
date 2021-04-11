class Solution {
public:
    vector<int> subans;
    vector<vector<int>> ans;
    queue<Node*> que;
    vector<vector<int>> levelOrder(Node* root) {
        if(root ==NULL) return {};
        Node* p = root;
        que.push(p);
        int flag =1;
        while(!que.empty()){
            p = que.front();
            que.pop();
            subans.push_back(p->val);
            for(auto c:p->children){
                que.push(c);
            }
            --flag;  //用于记录当前层次的节点个数
            if(flag == 0){
                flag = que.size();
                ans.push_back(subans);
                subans.clear();
            }
        }
        return ans;
    }
};
