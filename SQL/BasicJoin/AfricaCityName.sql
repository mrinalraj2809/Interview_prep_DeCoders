/*****************************************
Given the CITY and COUNTRY tables, query the names of all cities where the CONTINENT is 'Africa'.

Note: CITY.CountryCode and COUNTRY.Code are matching key columns.
*****************************************/

```sql
select c.name
from city c, country cc
where c.countrycode = cc.code and cc.continent = 'Africa';
```