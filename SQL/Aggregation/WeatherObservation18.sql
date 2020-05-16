/********************************
Consider p1 and p2 to be two points on a 2D plane.

a happens to equal the minimum value in Northern Latitude (LAT_N in STATION).
b happens to equal the minimum value in Western Longitude (LONG_W in STATION).
c happens to equal the maximum value in Northern Latitude (LAT_N in STATION).
d happens to equal the maximum value in Western Longitude (LONG_W in STATION).
Query the Manhattan Distance( |x1 - x2| + |y1 - y2|) between points p1 and p2 and round it to a scale of 4 decimal places.
********************************/
```sql
Select Round(ABS(min(lat_n)-max(lat_n))+abs(max(long_w)-min(long_w)),4)
from station;
```