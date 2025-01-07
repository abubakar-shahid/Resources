--create procedure Q5_NoOfCards @userName varchar(20), @userID int, @output int output as
--select @output = count(UserCard.userID) from Users join UserCard on Users.userId = UserCard.userID
--where Users.name = @userName and Users.userId = @userID group by UserCard.userID
--go

declare @output int
execute Q5_NoOfCards Ali, 1, @output output
select @output as [Number of Cards]