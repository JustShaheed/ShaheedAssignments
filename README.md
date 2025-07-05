
# Assignment Solutions – Reverse Words (C++) & Version Update Script (Python)

This repo contains solutions for two coding assignments:

---

## Assignment 1 – Reverse Each Word (C++)

### Description:
Reverses only the letters and numbers in each word of a string.  
Punctuation and spacing are kept in place. Word order doesn't change.

### Example:
**Input:**
```
String; 2be reversed...
```

**Output:**
```
gnirtS; eb2 desrever...
```

### How to Run:
```bash
g++ assignment1_reverse_words.cpp -o reverse
./reverse
```

---

## Assignment 2 – Version Update Script (Python)

### Description:
Script to update version numbers in two config files:
- `SConstruct` → updates the `point=XXX` line
- `VERSION` → updates the `ADLMSDK_VERSION_POINT = XXX` line

The new version number is taken from the `BuildNum` environment variable.  
Both files are located under:
```
$SourcePath/develop/global/src
```

### How to Run:
```powershell
# Set environment variables
$env:BuildNum="456"
$env:SourcePath="C:\Path\To\AssignmentSolutions"

# Run the script
python assignment2_version_update.py
```

### What It Does:
- Updates `point=456` in `SConstruct`
- Updates `ADLMSDK_VERSION_POINT= 456` in `VERSION`
- Prints a confirmation message after updating
