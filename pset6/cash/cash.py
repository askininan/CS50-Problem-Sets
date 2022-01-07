from cs50 import get_float

counter = 0

# Prompt user for a positive input
while True:
    change = 100 * get_float("Change owed (in dollars): ")
    if change > 0:
        break
print(f"Cents:", change)

# Count quarters
while change >= 25:
    change = change - 25
    counter = counter + 1
    if change < 25:
        break
    
# Count dimes
while change >= 10:
    change = change - 10
    counter = counter + 1
    if change < 10:
        break
    
# Count nickels
while change >= 5:
    change = change - 5
    counter = counter + 1
    if change < 5:
        break

# Count pennies
while change >= 1:
    change = change - 1
    counter = counter + 1
    if change < 1:
        break
    
    
print(counter, "coin(s).")
        