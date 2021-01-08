Memory allocation & Strings


## Stack
 + faster operations with memory
 	+ variables are ordered in the memory
 	+ we know the used memory in compile time
 - not enough memory?

## Heap
 + more control
	 + we decide when to allocate the memory
	 + we decide when to free it
	 - we must take care not to go outside this memory
 - variables are spread out
 - not enough memory?



```
RAM/ HEAP
x = new int;
a = new int[5];
y = new int;
|-------------[ x(int) ][-------  a (int x 5) ---------][ y(int) ]------------|

delete a;
|-------------[ x(int) ]--------------------------------[ y(int) ]------------|

option 1:
a = new int[4];
|-------------[ x(int) ][-------  a (int x 4) -----]----[ y(int) ]------------|


option 2:
new int[6];
|-------------[ x(int) ]--------------------------------[ y(int) ][-------- int x 6 -------------------------]
RAM Fragmentation


|[ x(int) ][ y(int) ][-------- int x 6 -------------------------]--------------------------------------------


Garbage Collector



Code Clarity                                            Performance
    |--------------------------------------------------------|

```

1. Make it work
2. Make it clean
3. Make it fast, if needed

## C
cstrings ->>> char*, NULL terminated
char[9] = "Ala bala\0"


## C++
string ->>> object (OOP)














