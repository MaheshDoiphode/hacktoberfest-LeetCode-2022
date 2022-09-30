/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

Node* cloneGraph(Node* node)
{
   if(node==nullptr)return nullptr;
   Node *top=new Node;
   top->val=node->val;
   vector<Node*>corr(101,nullptr);
   corr[node->val]=top;
   function<void(Node*)> dfs=[&](Node *original){
       //cout<<original<<endl;
      for(Node *child:original->neighbors)
      {
         if(corr[child->val]==nullptr)
         {
            Node *clone=new Node;
            clone->val=child->val;
            corr[child->val]=clone;
            dfs(child);
         }
         corr[original->val]->neighbors.push_back(corr[child->val]);
      }
   };
   dfs(node);
   return top;
}
};
