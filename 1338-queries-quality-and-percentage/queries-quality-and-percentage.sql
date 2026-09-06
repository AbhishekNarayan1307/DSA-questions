# Write your MySQL query statement below
select query_name, round(avg(q.rating/q.position),2) as quality,
round((SUM(CASE WHEN q.rating < 3 THEN 1 ELSE 0 END)/count(q.query_name))*100,2) as poor_query_percentage
from queries q
group by q.query_name