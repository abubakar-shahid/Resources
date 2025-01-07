--create procedure Q4_ShowMinimumBalance @output float output as
--select @output = min(balance) from Card
--go

declare @output float
execute Q4_ShowMinimumBalance @output output
select @output as [Minimum Balance]