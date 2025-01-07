select * from Employees where
MGR in (select MGR from Employees where EMP_ID in ('200','121')) and
DEPT_ID in (select DEPT_ID from Employees where EMP_ID in ('200','121'));