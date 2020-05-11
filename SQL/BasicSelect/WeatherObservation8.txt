Query the list of CITY names from STATION which have vowels (i.e., a, e, i, o, and u) as both their first and last characters. Your result cannot contain duplicates.

```sql
select unique city
from station 
where REGEXP_LIKE(city,'^[aeiouAEIOU].*[aeiouAEIOU]$');
```