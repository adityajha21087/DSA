# Write your MySQL query statement below
with final as (select t2.name as 'Department', t1.name as 'Employee',
t1.salary as 'Salary' from Employee t1
join 
Department t2
on t1.departmentId=t2.id)

select * from final t1
where Salary=(select max(Salary) from final t2 where t1.Department=t2.Department )