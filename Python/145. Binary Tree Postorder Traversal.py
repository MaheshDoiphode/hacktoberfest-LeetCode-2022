# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


        
class Solution(object):
    def postorderTraversal(self, root):
        lis = []

        def pos(x):
            if x is None:
                return
            pos(x.left)
            pos(x.right)
            lis.append(x.val)

        pos(root)
        return lis
