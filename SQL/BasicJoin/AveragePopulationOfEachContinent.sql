/*****************************************
Given the CITY and COUNTRY tables, query the names of all the continents (COUNTRY.Continent) and their respective average city populations (CITY.Population) rounded down to the nearest integer.

Note: CITY.CountryCode and COUNTRY.Code are matching key columns.
*****************************************/

```sql
select cc.continent, round(avg(c.population)-0.5)
from city c, country cc
where c.countrycode = cc.code 
group by cc.continent;
```