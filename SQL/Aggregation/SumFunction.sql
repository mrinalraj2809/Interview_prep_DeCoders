//Query the total population of all cities in CITY where District is California.

```sql
select sum(population)
from city
where district = 'California';
```