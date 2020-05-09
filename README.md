# Cheat Sheet
--------------------------------------------
| [Important functions](#important-functions)|
| [Manipulation Algorithm](#manipulation-algorithm) |
| [String important functions](#string-important-functions) |
| [Sets](#sets) |
| [Maps](#maps) |
--------------------------------------------

## Important functions
### Sorting
1. sort(arr,arr+n) : quick sort in (nlogn) ascending order.
2. sort(arr,arr+n,greater<int>()) : sort in descending order.
3. sort(arr,arr+n, comparable) : sort accordingly.
```cpp
	bool comparable(int a, int b)
	{
		return a>b;
	}
```

### Reverse
reverse(arr,arr+n);

### Max element in vector
*max_element(arr,arr+n);

### Min element
*min_element(arr,arr+n);

### Finding sum of all elements in vector
accumulate(arr,arr+n,0) : 0 is to specify the initial value of sum

### Count of pattern in vector
count(arr,arr+n);

### Finding the iterator position of the patter in vector
find(arr,arr+n,pattern); return iterator to first match else vector.end() if not found

### Shifting the vector
rotate(arr.begin(), arr.begin()+3, arr.end()); the element at 3rd position become the first after **first** rotate.
rotate(arr.begin(), arr.end() + (arr.size() - 3), arr.end()); the element at 3rd position become the first after **last 3rd** rotate.

### value not less than x
lower_bound(arr,arr+n,x);

### value not greater than x
upper_bound(arr,arr+n,x);

### Common elements in set
set_intersection(vec1.begin(),vect1.end(),vec2.begin(),vect2.end(), result.begin()) : store the common elements in result vector

### All elements in set
set_union(vec1.begin(),vect1.end(),vec2.begin(),vect2.end(), result.begin()) : store the all elements in result vector

--------------------------------------------

## Manipulation Algorithm
### Erase
arr.erase(iteratorPosition) : erases the element at position +1 
arr.erase(unique(arr.begin(),arr.end()), arr.end()) : erases the duplicate elements.

### Permutation
1. next_permutation(arr,arr+n);
2. prev_permutation(arr,arr+n);

--------------------------------------------

## String important functions
### find
1. str.find_last_of("pattern") :returns substring index position of the match from the last
2. str.find_first_of("pattern") : returns substring index position of the match from the beginning
3. str.find("pattern"): return position of the patterns first match else return -1;

### sub-string
3. str.substr(position) : return sub-string from that position to the last.
4. str.substr(indexPosition, substringLength) : return sub-string from that position to the sub-string length specified.

--------------------------------------------

## Sets
set<int,greater<int>> setName; : stores element in descending order.
set.insert(10);

### Copying values in set from vector
set<int> setName(arr.begin(),arr.end())

### Find
setName.find(30) : return iterator position else return setName.end()

### Erase a value
1. setName.erase(value)
2. setName.erase(arr.begin(),arr.end(), setName.find(30) )

### Count fn to check if element is present or not
setName.count(element) : // return 1 if present or 0 when not present.

--------------------------------------------

## Maps
1. map<int,int> mapName;
2. mapName.insert(pair<int,int>(10,40));
3. itrPos->first : gives key
4. itrPos->second : gives value

### Modifying value pair
mapName.find(keyValue)->second = newValue;