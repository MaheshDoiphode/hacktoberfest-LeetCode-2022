# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right



class Solution(object):
    def inorderTraversal(self, root):
        lis = []

        def ino(x):
            if x is None:
                return
            ino(x.left)
            lis.append(x.val)
            ino(x.right)

        ino(root)
        return lis

