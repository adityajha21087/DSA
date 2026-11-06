# Write your MySQL query statement below
with final as (select t1.name, t1.salary , t2.salary as 'a' from Employee t1
join 
Employee t2
on t1.managerId=t2.id)

select name as 'Employee' from final
where salary>a

