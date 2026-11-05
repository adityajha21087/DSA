# Write your MySQL query statement below
select  t2.email as 'Email' from person t1
join 
person t2
on t1.id!=t2.id and t1.email=t2.email
group by (Email)