import sys
import csv

def main():
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    db_path = sys.argv[1]
    seq_path = sys.argv[2]

    db = []
    sequence = ""
    def find_max_strs(dna_sequence, str_patterns):
    max_counts = {str_pattern: 0 for str_pattern in str_patterns}

    for str_pattern in str_patterns:
        pattern_length = len(str_pattern)
        max_repeat_count = 0

        for i in range(len(dna_sequence)):
            repeat_count = 0
            j = i

            # Count repeats of the current STR pattern starting from position i
            while dna_sequence[j:j + pattern_length] == str_pattern:
                repeat_count += 1
                j += pattern_length

            # Update max repeat count if necessary
            if repeat_count > max_repeat_count:
                max_repeat_count = repeat_count

        # Update the maximum count for this STR pattern
        max_counts[str_pattern] = max_repeat_count

 AGATC = compute('AGATC', text)
    AATG = compute('AATG', text)
    TATC = compute('TATC', text)
    TTTTTTCT = compute('TTTTTTCT', text)
    TCTAG = compute('TCTAG', text)
    GATA = compute('GATA', text)
    GAAA = compute('GAAA', text)
    TCTG = compute('TCTG', text)


    # Open & Read CSV
    with open(db_path, "r") as csvfile:
        reader = csv.DictReader(csvfile)
        db = list(reader)

    # Open & Read sequence file
    with open(seq_path, "r") as file:
        sequence = file.read().strip()

    # Compute repeats
    max_counts = {}
    for row in db:
        for key, value in row.items():
            if key != "name":
                max_counts[key] = 0

    for key in max_counts:
        max_counts[key] = max(sequence.count(key * max_counts[key]), max_counts[key])

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

