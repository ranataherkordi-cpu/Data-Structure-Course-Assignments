def can_transform(n, m, s, t):
    if '*' not in s:
        return "YES" if s == t else "NO"
    
    prefix, suffix = s.split('*')
    if len(prefix) + len(suffix) > m:
        return "NO"
    
    if t.startswith(prefix) and t.endswith(suffix):
        return "YES"
    else:
        return "NO"

# دریافت ورودی
n, m = map(int, input().strip().split())
s = input().strip()
t = input().strip()

# چاپ خروجی
print(can_transform(n, m, s, t))
