create procedure Q7_UpdatePIN @cardNum varchar(20), @oldPIN varchar(4), @newPIN varchar(4), @message varchar(11) output as
select @message = ''
if len(@newPIN) != 4
    select @message = 'Error'
if @message = ''
    declare @flag bit = 0
	select @message = 'PIN Updated'
    select @flag = 1 where exists(select cardNum from Card where cardNum = @cardNum and PIN = @oldPIN)
    if @flag = 1
	    update Card
		set PIN = @newPIN where cardNum = @cardNum
    else
	    select @message = 'Error'

declare @status varchar(11)
execute Q7_UpdatePIN 1324327436569, 1770, 1771, @status output
select @status as [Message]
select * from Card;