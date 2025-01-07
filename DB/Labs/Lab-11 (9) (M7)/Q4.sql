--create trigger EnsureEnrollment on Registration
--for insert as
--declare @flag varchar(7), @semester varchar(15), @rollNum  varchar(7), @ID int, @section varchar(1), @gpa float
--select @semester = Semester, @rollNum = RollNumber, @ID = CourseID, @section = Section, @gpa = GPA from inserted
--select @flag = inserted.Rollnumber from inserted join ChallanForm
--on inserted.RollNumber = ChallanForm.RollNumber and ChallanForm.TotalDues > 20000 and ChallanForm.Status = 'pending'
--   if(@flag is not null)
--       print 'You cannot be enrolled due to pending dues.'
--   else 
--       insert into Registration values(@semester, @rollNum, @ID, @section, @gpa)
--	   print 'Course Registered Successfully!'
--go

insert into Registration values ('Fall2016', '1', 30, 'A', 2.9)