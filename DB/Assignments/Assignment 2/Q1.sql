select Departments.DEPT_ID, Departments.DEPT_NAME from Departments where
(select min(Employees.salary) from Employees where Employees.DEPT_ID = Departments.DEPT_ID) >
(select max(Employees.salary) from Employees where Employees.DEPT_ID = '10');