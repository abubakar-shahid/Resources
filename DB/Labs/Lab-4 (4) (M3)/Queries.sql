---------------------------------------------------------------------- (Creating Tables and Inserting Data) ----------------------------------------------------------------------
create table hotel(
hotelno varchar(10) primary key,
hotelname varchar(20),
city varchar(20),
)

insert into hotel values('fb01', 'Grosvenor', 'London');
insert into hotel values('fb02', 'Watergate', 'Paris');
insert into hotel values('ch01', 'Omni Shoreham', 'London');
insert into hotel values('ch02', 'Phoenix Park', 'London');
insert into hotel values('dc01', 'Latham', 'Berlin');

 -- create a table named hotel

 create table room(

roomno numeric(5),
hotelno varchar(10),
type varchar(10),
price decimal(5,2),
primary key (roomno, hotelno),
foreign key (hotelno) REFERENCES hotel(hotelno)
)

insert into room values(501, 'fb01', 'single', 19);
insert into room values(601, 'fb01', 'double', 29);
insert into room values(701, 'fb01', 'family', 39);
insert into room values(1001, 'fb02', 'single', 58);
insert into room values(1101, 'fb02', 'double', 86);
insert into room values(1001, 'ch01', 'single', 29.99);
insert into room values(1101, 'ch01', 'family', 59.99);
insert into room values(701, 'ch02', 'single', 10);
insert into room values(801, 'ch02', 'double', 15);
insert into room values(901, 'dc01', 'single', 18);
insert into room values(1001, 'dc01', 'double', 30);
insert into room values(1101, 'dc01', 'family', 35);

create table guest(
guestno numeric(5),
guestname varchar(20),
guestaddress varchar(50),
primary key (guestno)
)

insert into guest values(10001, 'John Kay', '56 High St, London');
insert into guest values(10002, 'Mike Ritchie', '18 Tain St, London');
insert into guest values(10003, 'Mary Tregear', '5 Tarbot Rd, Aberdeen');
insert into guest values(10004, 'Joe Keogh', '2 Fergus Dr, Aberdeen');
insert into guest values(10005, 'Carol Farrel', '6 Achray St, Glasgow');
insert into guest values(10006, 'Tina Murphy', '63 Well St, Glasgow');
insert into guest values(10007, 'Tony Shaw', '12 Park Pl, Glasgow');

create table booking(
hotelno varchar(10),
guestno numeric(5),
datefrom date,
dateto date,
roomno numeric(5),
primary key (hotelno, guestno, datefrom),
foreign key (roomno, hotelno) REFERENCES room(roomno, hotelno),
foreign key (guestno) REFERENCES guest(guestno)
)

 

insert into booking values('fb01', 10001, '04-04-01', '04-04-08', 501);
insert into booking values('fb01', 10004, '04-04-15', '04-05-15', 601);
insert into booking values('fb01', 10005, '04-05-02', '04-05-07', 501);
insert into booking values('fb01', 10001, '04-05-01', null, 701);
insert into booking values('fb02', 10003, '04-04-05', '10-04-04', 1001);
insert into booking values('ch01', 10006, '04-04-21', null, 1101);
insert into booking values('ch02', 10002, '04-04-25', '04-05-06', 801);
insert into booking values('dc01', 10007, '04-05-13', '04-05-15', 1001);
insert into booking values('dc01', 10003, '04-05-20', null, 1001);

--------------------------------------------------------------------- (Selecting All) --------------------------------------------------------------------
select * from guest;
select * from booking;
select * from hotel;
select * from room;

--------------------------------------------------------------------- (Tasks) --------------------------------------------------------------------------------

(Task # 1)
select * from hotel
where city='London' order by hotelname desc;

(Task # 2)
select guestname, guestaddress from guest
where guestaddress like '%Glasgow' and guestname like '%Farrel' or guestname like 'Tony%';

(Task # 3)
select roomno, hotelno from booking
where datefrom between '2005-01-01' and '2010-01-01';

(Task # 4)
select * from room
where roomno='1001' and type='single' and price between 20 and 40;

(Task # 5)
select guest.guestname from guest
inner join booking
on guest.guestno=booking.guestno and dateto is null;

(Task # 6)
select top 1 roomno, hotelname from room
inner join hotel
on hotel.hotelno=room.hotelno order by room.price desc;


(Task # 7)
select 'The hotel whose id is ' + hotelno + ' is in ' + city + ' and its name is ' + hotelname + '.'
as Data_of_Hotel_Table from hotel;

(Task # 8)
select hotel.hotelname from hotel
inner join room
on hotel.hotelno=room.hotelno
where room.type='family' or room.type='double'
group by hotel.hotelname having count(*)=2;

(Task # 9)


(Task # 10)
select room.roomno, room.hotelno, room.type, room.price, booking.guestno from room
inner join booking
on booking.roomno=room.roomno
and booking.guestno=10003 or booking.guestno = 10007
and not booking.guestno=10001;

(Task # 11)
select count(hotelno) as totalHotels from hotel;

(Task # 12)
select room.price, room.type from room
inner join hotel
on hotel.hotelno=room.hotelno and hotelname='Watergate';
