import csv
from sys import argv


def main():

    # Exit with an error message if argc is not made of 3 elements
    if len(argv) != 3:
        print("Error, usage: python dna.py data.csv sequence.txt")

    # Open database and read it to STRs list
    csvfile = open(argv[1], "r")
    dataReader = csv.reader(csvfile)
    STRs = next(dataReader)
    del STRs[0]

    # Open dna sequence, read it to sequence list
    with open(argv[2], "r") as txtfile:
        seqReader = csv.reader(txtfile)
        for row in seqReader:
            sequence = str(row)
    
    # Compare STRs to DNA sequences and count the number of repeats        
    countTable = []
    for i in range(len(STRs)):
        counter = 1
        c = STRs[i]
        while c * counter in sequence:
            a = c * counter
            counter += 1
        # Add each count result to countTable
        countTable.append(counter - 1)
        
    for row in dataReader:
        name = row[0]
        row.pop(0)
        row = [int(i) for i in row]
        x = compare_count(row, countTable)
        if x == True:
            print(name)
            break
    if x == False:
        print("No match.")

    csvfile.close()

# FUNCTIONS

# Compares countTable to given dna count


def compare_count(x, y):
    if set(x).intersection(y) == set(x):
        return True
    else:
        return False

        
main()