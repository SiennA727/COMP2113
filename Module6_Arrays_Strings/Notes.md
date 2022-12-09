# Arrays

Declaration: `int max_score, min_score, score[5];`

Declare and initialize: `int score[5] = {80,100,64};` or `int score[] = {80,100,64};`

Specify array size: use `const int arraySize = 10`

Array as function parameter:
- declaration: `void modifyArray(int [], int);`
- definition: `void modiftArray(int b[], int);`
- function call: `modifyArray(a,10)` **pass by reference default!**
- often use another parameter as size
- `const int array[]` to specify the content of array remain constant

Selection sort:
- look for smallest number from index 0 to size-1, swap with array[0]
- look for smallest number from index 1 to size-1, swap with array[1]
- ...

Declaration multi-dimentional array: `void print_2D_array(int array[][5][6], int nrows)'` **(must) specify size except first dimension**

```c++
#include <cctype>
isdigit(c);
isalpha(c);
isalnum(c); // letter or digit
islower(c);
isupper(c);
tolower(c);
toupper(c);
```

# C-String: array of characters

'A' vs "A": 'A' '\0'

'0' (48bytes) vs  '\0' (null)

declare: `char name[16] = {'J','o','h','n','\0'}` or `char name[16]="John"`

**`char name[] = "John";` has size 5!!!**

if null character at the end is overwrite, the output will include garbage byte contents `name[5]='n'`

# C++ String

index access available: `msg[11]="?"`

concate: `+` **at least one should be string!!!*

comparison: < > == ... left to right according to ASCII value

read line from user input: `getline(cin, s, ',')` delimited by ',' only reads before ','

member functions:
```c++
#include <string>
s.length();
s.empty();
s.erase(pos,n);
s.substr(pos,n);
s.find(str, pos); // returns index of first index and -1 if not found at or after pos
s.rfind(str, pos); // reverse, last occurence at or before pos
s.insert(pos, str); // the first char of str will be at pos
s.replace(pos, n, str);