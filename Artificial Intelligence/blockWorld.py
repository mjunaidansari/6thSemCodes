class Stack:
    def __init__(self):
        self.stack = []
        
    def __str__(self): 
        return str(self.stack)

    def push(self, item):
        self.stack.append(item)

    def pop(self):
        if not self.is_empty():
            return self.stack.pop()
        else: 
            return None

    def peek(self):
        if not self.is_empty():
            return self.stack[-1]
        else: 
            return None

    def is_empty(self):
        return len(self.stack) == 0

    def size(self):
        return len(self.stack)


# function to define mutliple stack
def initializeStacks(n):
    stacks = []
    for _ in range(n): 
        stacks.append(Stack())
    return stacks

blocks = ['A', 'B', 'C', 'D', 'E']
n = len(blocks)


stacks = initializeStacks(n)
print(stacks)

stack = Stack()
stack.push(1)
print(stack)



