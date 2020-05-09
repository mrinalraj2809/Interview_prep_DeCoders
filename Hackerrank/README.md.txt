Hope I am able to clear your concept.


Below is the explanation for the Precomputation part.
```

index ->    	    0    1    2    3    4    5    6...


	j*i


	for i=1           1


	for i=2                2        4


	for i=3                      3                6                9


	for i=4                          4              8               12                 16


	
	
values : 


index ->    0    1    2    3    4    5    6    7    8    9    10    11    12    13...
 	
initially   0    1    2    3   -1   -1   -1   -1   -1   -1    -1    -1    -1    -1
for(j*i)th index for i=1:

	         no exec

for(j*i)th index for i=2:

		no exec

for(j*i)th index for i=3:

		no exec

for(j*i)th index for i=4:

			   	4(from if condn.)

		                     5(num[4]+1)         5(num[4]+1)         5(num[4]+1)


for(j*i)th index for i=5:

                                       5(from if condn.)

						6(num[5]+1)            6(num[5]+1)

```
in Precomputation part:

	part 1: Initialize all the (i)th index with previous value + 1
	part 2: Multiply (0,1,...,i) X (i)th index to get index with is then initialized by the value at (i)th index + 1.

NOTE: At the same time check at (i)th index values should be less than one more than previous index value.
