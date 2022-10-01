#Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution(object):
    def preorderTraversal(self, root):
        lis = []

        def fic(x):
            if x is None:
                return
            lis.append(x.val)
            fic(x.left)
            fic(x.right)

        fic(root)
        return lis
