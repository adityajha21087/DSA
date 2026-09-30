# Write your MySQL query statement below
select t1.name as 'Customers' from Customers t1
left join 
Orders  t2
on t1.id=t2.customerId
where t2.id is null