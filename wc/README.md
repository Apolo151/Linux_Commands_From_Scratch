The **wc** command return the word, line, character, and byte count for each file.


### Notes
- The eof() function returns true only after an attempt has been made to read beyond the end of the file
- The `==` operator won't always work for comparing string
	- when comparing `argv[i]=="-c"`, it always returns false, as the `==` operator is not overloaded
	- [Difference between == and compare() - Stackoverflow](https://stackoverflow.com/questions/9158894/differences-between-c-string-and-compare#comment37104032_9158894)

