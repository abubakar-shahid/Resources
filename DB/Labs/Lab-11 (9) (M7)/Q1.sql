--create trigger StopDeletion on Students
--instead of delete as
--print 'You don’t have the permission to delete the student'
--go

delete from Students where Name='Ali';