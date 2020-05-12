//Query the list of CITY names from STATION that do not start with vowels and do not end with vowels. Your result cannot contain duplicates.



```sql
select unique city
from station 
MINUS
select unique city
from station 
where REGEXP_LIKE(city,'^[AEIOUaeiou]')
MINUS
select unique city
from station 
where REGEXP_LIKE(city,'.[aeiouAEIOU]$');
```

```sql Efficient
SELECT DISTINCT City
FROM Station
WHERE REGEXP_LIKE(City, '^[^AEIOU].*[^aeiou]$');

```