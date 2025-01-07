select top 1 SALARY from Employees where SALARY in (
select top 3 SALARY from Employees group by SALARY order by SALARY desc) order by SALARY asc;

select SALARY from Employees order by salary desc limit 2,1;