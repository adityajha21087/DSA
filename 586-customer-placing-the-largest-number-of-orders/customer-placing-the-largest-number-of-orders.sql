# Write your MySQL query statement below
select customer_number from (select count(*) as 'num',customer_number  from Orders
group by customer_number
order by num desc limit 1 ) t1