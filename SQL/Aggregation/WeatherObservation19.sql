/********************************
Consider p1(a,c) and p2(b,d) to be two points on a 2D plane where (a,b) are the respective minimum and maximum values of Northern Latitude (LAT_N) and (c,d) are the respective minimum and maximum values of Western Longitude (LONG_W) in STATION.

Query the Euclidean Distance between points p1 and p2 and format your answer to display 4 decimal digits.
********************************/
```sql
select round(sqrt(power(max(lat_n)-min(lat_n),2) + power(max(long_w)-min(long_w),2)),4)
from station;
```