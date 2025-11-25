def print_diamonds(n):
    lines = n
    mid = n // 2
    
    for i in range(lines):
        if i <= mid:
            stars = 1 + 2 * i
        else:
            stars = 1 + 2 * (lines - i - 1)
        
        spaces = (n - stars) // 2
        line = " " * spaces + "*" * stars + " " * (2 * spaces) + "*" * stars + " " * spaces
        print(line)

n = int(input())
print_diamonds(n)
