--6
--CREATE PROCEDURE Q6_Login @cardNum varchar(20), @pin varchar(4), @status bit output as
--select @status = 0
--select @status = 1 where exists(select cardNum from Card where cardNum = @cardNum and PIN = @pin)
--go

declare @status bit
execute Q6_Login 1324327436569, 1770, @status output
select @status as [Login Status]