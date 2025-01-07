--create procedure StudentRegistration
--@semester varchar(15), @rollNumber varchar(7), @courseID int, @section varchar(1), @gpa float
--as begin
--begin tran
--  begin try
--    insert into Registration values(@semester, @rollNumber, @courseID, @section, @gpa)
--  end try
--  begin catch
--    if @gpa<2.5
--      begin
--	    print 'GPA less than 2.5!!!  You can only enroll in subjects that you can improve'
--	    rollback
--	  end
--  end catch
--commit tran
--end
--select * from Registration
execute StudentRegistration 'Fall2019','9','30','B','2.3';
select * from Registration