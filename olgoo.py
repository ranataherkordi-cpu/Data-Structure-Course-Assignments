def distance(s1, s2):
    # Calculate the number of differing characters between two strings of the same length
    return sum(1 for a, b in zip(s1, s2) if a != b)

def countOccurrences(string, pattern, d):
    # Get the length of the string and the pattern
    n = len(string)
    m = len(pattern)
    
    count = 0
    
    # Loop through the string to find all substrings of the same length as the pattern
    for i in range(n - m + 1):
        substring = string[i:i+m]
        if distance(substring, pattern) <= d:
            count += 1
            
    return count

# Input processing
input_string = input().strip()
string, pattern, d = input_string.rsplit(' ', 2)
d = int(d)

# Output the result
print(countOccurrences(string, pattern, d))
