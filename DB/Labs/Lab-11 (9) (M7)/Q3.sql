--Create table Notify(
--NotificationID int identity(1,1),
--StudentID varchar(7) foreign key  references Students(Rollno),
--[Notification String] varchar(255)
--);
--create trigger NotifyStudent on Registration
--after insert as
--declare @rollNum varchar(7), @insertedRollNum varchar(7)
--select @insertedRollNum = rollnumber from inserted
--select @rollNum = inserted.RollNumber from inserted join Semester on inserted.Semester = Semester.Semester 
--join Courses_Semester on inserted.CourseID = Courses_Semester.CourseID
--where Semester.Status = 'Complete' and Courses_Semester.AvailableSeats > 0;
--    if @rollNum is null
--        insert into Notify values (@insertedRollNum, 'Registration Unsuccessful for Course');
--    else
--        insert into Notify values (@rollNum, 'Registration Successful for Course');
--go

insert into Registration values (N'Fall2016', N'7', 40, N'A', 3.3)