select Departments.DEPT_NAME from Departments
join Employees on Departments.DEPT_ID = Employees.DEPT_ID
where Employees.EMP_ID = '200';