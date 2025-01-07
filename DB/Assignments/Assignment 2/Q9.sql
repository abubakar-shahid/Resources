select distinct JOB from Employees
where JOB not in (select distinct JOB from Employees);