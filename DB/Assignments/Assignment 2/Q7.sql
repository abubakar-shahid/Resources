select * from Employees where SALARY in
(select max(SALARY) from Employees where JOB = 'SA_REP' group by JOB);

select * from Employees where JOB = 'SA_REP' order by SALARY desc limit 1;