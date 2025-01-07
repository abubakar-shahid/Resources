select * from Employees where SALARY in
(select SALARY from Employees where DEPT_ID = '10');