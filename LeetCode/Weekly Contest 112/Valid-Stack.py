class Solution:
    def validateStackSequences(self, pushed, popped):
        """
        :type pushed: List[int]
        :type popped: List[int]
        :rtype: bool
        """
        push = []
        i = 0
        j = 0
        while (i != len(popped)):
            if push == [] or popped[i] != push[-1]:
                if (j == len(pushed)): return False
                while (popped[i] != pushed[j]):
                    push.append(pushed[j])
                    j += 1
                    if (j == len(pushed)): return False
                j += 1
            else:
                push.pop()
            i += 1
        return True