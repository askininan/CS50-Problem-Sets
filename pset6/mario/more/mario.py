from cs50 import get_int

# Prompt the user to get a height between 1 and 8
while True:
    h = get_int("What's height of the pyramid?" + " ")
    if h > 0 and h < 9:
        break

# Loop through heigth
for i in range(h):
    # For reverse half-pyramid start with creating max space and loop through smaller and smaller spaces
    for j in range(h-i-1):
        print(" ", end="")
    for k in range(i+1):
        print("#", end="")
    print("  ", end="")
    for l in range(i+1):
        print("#", end="")
    print("")