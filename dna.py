import sys
import csv

def main():
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    db_path = sys.argv[1]
    seq_path = sys.argv[2]

    db = []
    sequence = ""

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

