from sys import argv, exit
import csv


# Checks Usage
if len(sys.argv) != 3:
    sys.exit("Usage: python dna.py data.csv sequence.txt")

# Open & Read CSV
with open(argv[1], "r") as inputfile:
    reader = list(csv.reader(inputfile))
    reader[0].remove("name")
    i = reader[0]
# Open TxT
 with open(seq_path, "r") as file:
        sequence = file.read()
#Compute Repeats
  max_counts = []    for i in range(1, len(reader.fieldnames)):
        STR = reader.fieldnames[i]
        max_counts.append(0)
#Loop
 if line[strepeat] == str(sequenceRepeats[strepeat]):
        strsMatched += 1
        if strsMatched == len(checkSTRS):
              matchedPerson = line['name']
              break
        print(matchedPerson)
#Function
 def compute(pattern, dnaSeq):
       if match == []:
        myresult = 0
        return myresult
#Compares data
   for i in range(len(dict_list)):
        matches = 0
        for j in range(1, len(reader.fieldnames)):
              if int(max_counts[j - 1]) == int(dict_list[i]  [reader.fieldnames[j]]):
                matches += 1
            if matches == (len(reader.fieldnames) - 1):
                print(dict_list[i]['name'])
                exit(0)print("No match")


