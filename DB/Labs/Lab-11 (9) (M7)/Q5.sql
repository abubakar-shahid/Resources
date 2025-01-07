--create trigger AvoidSemesterCourseDeletion on Courses_Semester
--for delete as
--declare @courseId int, @semester varchar(15), @seats int
--select @courseId = CourseID, @semester = Semester from inserted
--select @seats from Courses_Semester where CourseID = @courseId and Semester = @semester
--    if @seats < 10
--	    select msg = 'Not Possible!'
--	else
--	    delete from Courses_Semester where CourseID = @courseId and Semester = @semester
--		select msg = 'Successfully Deleted'
--go

delete from Courses_Semester where CourseID = 10 and Semester = 'Spring2017'