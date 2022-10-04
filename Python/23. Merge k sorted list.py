class Solution:
    def mergeKLists(self, lists: List[Optional[ListNode]]) -> Optional[ListNode]:
        lists = [l for l in lists if l!=None]
        
        if len(lists) == 0:
            return None
        
        if len(lists) == 1:
            return lists[0]
        
        def getList(r):
            if r == None:
                return []
            l = []
            while r != None:
                l.append(r.val)
                r = r.next
            return l
        l = []
        for r in lists:
            l += getList(r)
        l = sorted(l)
        # print(l)
        for i,v in enumerate(l):
            newNode = ListNode(v,None)
            if i == 0:
                mlist = newNode
                mlistR = mlist
            else:
                mlistR.next = newNode
                mlistR = mlistR.next
        return mlist
