/******************************
Query the sum of the populations for all Japanese cities in CITY. The COUNTRYCODE for Japan is JPN.
******************************/

```sql
select sum(population)
from city 
where COUNTRYCODE = 'JPN';
```