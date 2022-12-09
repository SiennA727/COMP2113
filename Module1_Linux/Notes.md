# Basic Linux Commands

## Directory

show date: `date`

listing directories and files:
- list in long format: `ls -l`
- list a child directory: `ls lab1`
- list all hidden: `ls -a`
- sort by time: `ls -t`

change directories:
- change to parent: `cd ..`
- change to home: `cd ~`
- change to other user's home directory: `cd ~username`

create directories: `mkdir lab1 "lab 2"`

remove directories:
- empty directory: `rmdir lab`
- delete entire: `rm -rf lab` &nbsp;&nbsp;&nbsp; *-r recursively travel down the directory -f prevent prompt of confirmation*

rename directory: `mv lab "lab 1"` *same for files*

print current directory: `pwd`

display user manual: `man ls`

## File  Management

create empty file: `touch file1.txt`

display file: `cat file1.txt`

move file to a directory: `mv file1.txt mydir`

same prefix: `myfile*` refers to all files starting with "myfile"

copy file1 to file2: `cp file1 file2`

remove file: `rm file1.txt`

vi editor: `vi file.txt` *if no, will create and show*
- first enter or press `esc`: command mode
- press `i`: insert mode
- save and quit: `esc` + `:wq`
- save to a new file: `:w filename`
- quit w/o saving: `:q!`

archive: `tar -cvf files.tar fileA fileB`

## File Permission

|Type|User|Group|Other|
|:-:|:-:|:-:|:-:|
|-/d|rwx|rwx|rwx|

421: `chmod 666 hello.txt` gives read and write permission to all types of users

d: directory

change permission: `chmod u+rwx filename` + / - / =

u(user) g(group) o(other) a(all)

## Other Basic Commands

`grep 'abc' file`: returns the lines in the file that contains abc

`wc file`: word count, returns number of lines (-l), words (-w) and bytes (-b)

`cut -d "," -f 1,3 file`: returns specific column (1-based) separated with delimiter ,

`sort filename`:
- default: alphabetical
- `-n`: numerical sort
- `-r`: reverse
- `-k3`: sort on field 3, default delimiter space
- `-t,`: field delimiter ,

`uniq filename`: remove **adjacent** duplicate lines

`spell filename`: print all incorrect words line by line

`diff file1 file2`: display how to transform fileA to fileB

example 1:

|A|B|
|-|-|
|Apple|Boy|
|Boy|Cat|
|Cat|Egg|
|Dog||
|Egg||

A to B:
```
1d0
< Apple
4d2
< Dog
```

B to A:
```
0a1
> Apple
2a4
> Dog
```

example 2:
|A|B|
|-|-|
|aaa|eee|
|bbb|aaa|
|ccc|ddd|

A to B:
```
0a1
> eee
2,3c3
< bbb
< aaa
---
> ddd
```

B to A:
```
1d0
< eee
3c2,3
< ddd
---
> bbb
> ccc
```

## File I/O

standard input: 0

standard output: 1

standard error: 2

send command output to file: `ls -l 1> files.txt` or `ls -l > files.txt` or `ls -l >| files.txt` to force overwrite

append: `>>`

complete: `command < fileA > fileB 2> fileC`

direct to same location: `cp fileA fileB 1> result.txt 2&1`

pipe output as input:
- `ls -l | grep "Jan 26"`
- `ls -l | grep -E ^...x..x..x`
- `cat -d' ' -f4-8 mark.txt | ./mark > result.txt`

## Search

search for files/directories: `find`
- `find . -name "hello*" -type f/d`
- `.`: stands for current directory, find will dive down by itself

search inside a file: `grep`

Regular expressions: use `-E`
|Symbol| Meaning |
|:-:|:-:|
|.|any single character|
|^|beginning of line|
|$|end of line|
|?|zero or **one** occurences of specified character|
|+|one or more occurences of the specified character|
|*|zero or more occurences of the specified character|
|()|substring|
|[]|match any character in the set|
|{}|match specified number of occurences|

[0-9] [A-Z] [a-z] [A-Za-z]

examples:
- `^.....$`: any line with 5 characters
- `a.*ge`: search for line including "a" followed by any number of characters and then by "ge"
- `[a-z]*`: nay number of lower-case letters
- `(co)+`: lines with "co" occuring one or more time
- `HKD[0-9]*`: HKD followed by zero or more numbers
- `[0-9]{1,2}[a-zA-Z]{3,}[0-9]{4}`: 1/2 digits of number + 3 or more digits of alphabets + 4 digits of number