import csv
from sys import argv, exit

def main():
    # Check
    if len(argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        exit(1)

    # Read File
    STRs, profiles = read_database(argv[1])

    # Repeat
    seq_str_count = {STR: find_repeats(read_sequence(argv[2]), STR) for STR in STRs}

    # Check
    for profile in profiles:
        if all(int(profile[STR]) == seq_str_count[STR] for STR in STRs):
            print(profile['name'])
            exit(0)

    print("No match")
    exit(1)

def read_database(filename):
    STRs = []
    profiles = []
    with open(filename, mode="r") as database:
        reader = csv.DictReader(database)
        STRs = reader.fieldnames[1:]
        for row in reader:
            profiles.append(row)
    return STRs, profiles

def read_sequence(filename):
    with open(filename, mode="r") as sequence_file:
        return sequence_file.readline()
# Compare & Find
def find_repeats(sequence, STR):
    L = len(STR)
    max_repeats = 0
    for i in range(len(sequence)):
        repeats = 0
        if sequence[i: i + L] == STR:
            repeats += 1
            while sequence[i: i + L] == sequence[i + L: i + (2 * L)]:
                repeats += 1
                i += L
        if repeats > max_repeats:
            max_repeats = repeats
    return max_repeats

if __name__ == "__main__":
    main()
