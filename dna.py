from sys import argv, exit
import csv

def main():
    # Check
    if len(argv) != 3:
        print(f"Error: Expected 2 arguments, got {len(argv) - 1}")
        exit(1)

    # Read CSV file and extract STR patterns
    with open(argv[1], "r") as inputfile:
        reader = csv.reader(inputfile)
        header = next(reader)
        str_patterns = header[1:]

    # Read File
    with open(argv[2], "r") as sequence_file:
        dna_sequence = sequence_file.read()

    # Count Repeats
    str_counts = {pattern: count_str(pattern, dna_sequence) for pattern in str_patterns}

    # Read & Compare
    with open(argv[1], "r") as inputfile:
        reader = csv.reader(inputfile)
        next(reader)
    #Print
        for row in reader:
            if row[1:] == [str_counts[pattern] for pattern in str_patterns]:
                print(row[0])
                return
        print("No match")

def count_str(pattern, sequence):
    pattern_len = len(pattern)
    max_count = 0
    count = 0
    i = 0
    while i < len(sequence):
        if sequence[i:i + pattern_len] == pattern:
            count += 1
            max_count = max(max_count, count)
            i += pattern_len
        else:
            count = 0
            i += 1
    return max_count

if __name__ == "__main__":
    main()
