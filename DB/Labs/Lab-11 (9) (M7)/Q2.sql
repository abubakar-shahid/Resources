--create trigger StopInsertion
--on Courses
--instead of insert as
--print 'You don’t have the permission to Insert a new Course'
--go

insert into Courses values(50, 'Testing', 40, 3);