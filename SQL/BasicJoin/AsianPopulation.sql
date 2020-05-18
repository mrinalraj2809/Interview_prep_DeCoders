/*****************************************
Given the CITY and COUNTRY tables, query the sum of the populations of all cities where the CONTINENT is 'Asia'.

Note: CITY.CountryCode and COUNTRY.Code are matching key columns.
*****************************************/

```sql
select sum(c.population)
from city c, country cc
where c.countrycode = cc.code and cc.continent = 'Asia';
```