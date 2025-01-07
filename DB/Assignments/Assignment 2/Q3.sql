select * from Employees where SALARY < 
(select min(SALARY) from Employees where DEPT_ID = '10' group by DEPT_ID);

select * from Employees E1
where exists (select * from Employees E2 where E2.SALARY < E1.SALARY and E2.DEPT_ID=10);