--create procedure Q8_WithDraw @cardNum varchar(20), @pin varchar(4), @amount int as
--declare @status bit
--execute Q6_Login @cardNum, @pin, @status output
--declare @maxi int
--select @maxi = max(transId) from Transactions
--select @maxi = @maxi + 1
--update Card set balance = balance - @amount where cardNum = @cardNum
--    if @status = 1
--		insert into Transactions values (@maxi, GETDATE(), @cardNum, @amount, '1')
--    else
--	    insert into Transactions values (@maxi, GETDATE(), @cardNum, @amount, '4')

select * from Transactions;
execute Q8_WithDraw 2324325436566, 1234, 325;
select * from Card;
select * from Transactions;