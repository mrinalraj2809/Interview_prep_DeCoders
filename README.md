# Important functions
## Sorting
1. sort(arr,arr+n) : quick sort in (nlogn) ascending order.
2. sort(arr,arr+n,greater<int>()) : sort in descending order.
3. sort(arr,arr+n, comparable) : sort accordingly.
	bool comparable(int a, int b)
	{
		return a>b;
	}

## Reverse
reverse(arr,arr+n);

## Max element in vector
*max_element(arr,arr+n);

## Min element
*min_element(arr,arr+n);

## Finding sum of all elements in vector
accumulate(arr,arr+n,0) : 0 is to specify the initial value of sum

## Count of pattern in vector
count(arr,arr+n);

## Finding the iterator position of the patter in vector
find(arr,arr+n,pattern); return iterator to first match else vector.end() if not found

## Shifting the vector
rotate(arr.begin(), arr.begin()+3, arr.end()); the element at 3rd position become the first after **first** rotate.
rotate(arr.begin(), arr.end() + (arr.size() - 3), arr.end()); the element at 3rd position become the first after **last 3rd** rotate.

## value not less than x
lower_bound(arr,arr+n,x);

## value not greater than x
upper_bound(arr,arr+n,x);

## Common elements in set
set_intersection(vec1.begin(),vect1.end(),vec2.begin(),vect2.end(), result.begin()) : store the common elements in result vector

##



# String important functions
## find
1. str.find_last_of("pattern") :returns substring index position of the match from the last
2. str.find_first_of("pattern") : returns substring index position of the match from the beginning
3. str.find("pattern"): return position of the patterns first match else return -1;

## sub-string
3. str.substr(position) : return sub-string from that position to the last.
4. str.substr(indexPosition, substringLength) : return sub-string from that position to the sub-string length specified.

