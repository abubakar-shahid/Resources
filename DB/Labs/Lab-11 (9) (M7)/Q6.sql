create trigger ProtectInstructors on Instructors
instead of update, delete as
    if exists (select * from inserted)
        raiserror ('Cannot modify Instructors table.', 16, 1)
    else
        raiserror ('Cannot drop Instructors table.', 16, 1)
go
