import csv
import sys
from collections import Counter

def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py CSVfile sequences")
    # TODO: Read database file into a variable
    # Read database as a list of dictionaries with key-value pairs comprising name and STR counts for each individual
    databases = []
    with open (sys.argv[1], 'r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            databases.append(row)
    # TODO: Read DNA sequence file into a variable
    # Read sequence text fie as
    readera = ""
    with open(sys.argv[2], 'r') as filea:
        readera = filea.read()
    # TODO: Find longest match of each STR in DNA sequence
    # Create a dictionary to store the database keys and set STR counts to the longest run of each using the helper function
    longest_run = {}
    keys = databases[0].keys()
    for i in keys:
        longest_run[i] = str(longest_match(readera, i))
    # TODO: Check database for matching profiles
    # Loop through the entire database list and check for run of STR counts that match the values in longest_run dictionary. If so, add the relevant names to a list
    matches = []
    for i in range(len(databases)):
        for j in keys:
            if j == 'name':
                continue
            elif longest_run[j] in databases[i][j]:
                matches.append(databases[i]['name'])
            else: break
    none = "No match"
    count = Counter(matches)
    print(count)
    for i in count.keys():
        if (count[i]) == len(keys) - 1:
            none = i
            break
    print(none)
    print(matches)
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1
            
            # If there is no match in the substring
            else:
                break
        
        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
