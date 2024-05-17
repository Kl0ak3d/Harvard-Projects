from sys import argv
import csv

def main():
    def main(database, sequence):
    # Reads the database file
    db = []
    with open(database) as file:
        reader = csv.DictReader(file)
        for row in reader:
            db.append(row)

    # Reads the DNA sequence file
    with open(sequence) as txt:
        dna_sequence = txt.read()

    # Computes maximum number of consecutive STRs from sequence file
    str_patterns = ['AGATC', 'AATG', 'TATC', 'TTTTTTCT', 'TCTAG', 'GATA', 'GAAA', 'TCTG']
    max_counts = {}
    for pattern in str_patterns:
        max_counts[pattern] = compute(pattern, dna_sequence)

    return max_counts

def compute(pattern, sequence):
    max_count = 0
    current_count = 0
    pattern_len = len(pattern)
    for i in range(len(sequence) - pattern_len + 1):
        if sequence[i:i+pattern_len] == pattern:
            current_count += 1
            max_count = max(max_count, current_count)
            i += pattern_len
        else:
            current_count = 0
    return max_count

    # Compare data
    for row in db:
        matches = 0
        for key, value in row.items():
            if key != "name":
                if int(max_counts[key]) == int(value):
                    matches += 1
        if matches == len(row) - 1:
            print(row['name'])
            return

    print("No match")

if __name__ == "__main__":
    main()
