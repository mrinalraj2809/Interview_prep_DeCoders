//Query the list of CITY names from STATION that either do not start with vowels or do not end with vowels. Your result cannot contain duplicates.


```sql
select unique city
from station 
MINUS
select unique city
from station 
where REGEXP_LIKE(city,'^[AEIOUaeiou].*[aeiouAEIOU]$');
```