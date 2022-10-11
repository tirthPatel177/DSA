# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
        if(k==1 or not head):
            return head
        at = ListNode()
        at.next = head
        ln = 0
        sa = head
        while(sa):
            sa = sa.next
            ln+=1
        hd = at
        hd1 = head
        for _ in range(ln//k):
            tp1 = hd.next
            prev = hd1
            hdd = prev.next
            tka = k-1
            while(tka>0):
                asd = hdd.next
                hdd.next = prev
                prev = hdd
                hdd = asd
                tka-=1
            hd.next = prev
            tp1.next = hdd
            hd = tp1
            hd1 = hdd
        return at.next
