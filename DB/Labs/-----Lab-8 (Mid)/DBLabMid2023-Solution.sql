

--1) Write a query to display all the studio names and number actors that have worked in the studio.

Select s.studioName, count(si.actorId) as noOfActors
from Studio as s
join Movie as m
on s.studioId=m.studioId
join StarsIn as si
on m.movieId = si.movieId
group by s.studioName

--2) Write a query to display the actorId and actorName who have worked in the most number of movies genre.

Select a.actorId, a.actorName, count(mg.movieId) noOfMovies
from Actor as a
join StarsIn as si
on a.actorId=si.actorId
join MovieGenre as mg
on si.movieId=mg.movieId
group by a.actorId,a.actorName
having count(mg.movieId) = (
	Select Top 1 count(mg.movieId) noOfMovies
	from StarsIn as si
	join MovieGenre as mg
	on si.movieId=mg.movieId
	group by si.actorId
	order by noOfMovies desc
)

--3) List the actor names, movie titles and genre names for genres with the highest number of movies.
-- One movie can have different genres and one actor can work in different genre movies.

select a.actorName, m.movieTitle, t2.genreName
from Actor a 

join StarsIn si
on a.actorId = si.actorId

join Movie m
on si.movieId = m.movieId

join MovieGenre mg 
on si.movieId = mg.movieId

join Genre g 
on mg.genreId = g.genreId

join 
( 
	select g.genreName, count(mg.movieId) maxNoOfMovies 
	from Genre g join MovieGenre mg
	on g.genreId = mg.genreId
	group by g.genreName
	having count(mg.movieId) = 
	(
		select Top 1 count(movieId) maxNoOfMovies
		from MovieGenre
		group by genreId
		order by maxNoOfMovies Desc	
	)
) t2 
on g.genreName = t2.genreName  

--4) List the genre names and total production cost of the genres with 
-- highest production cost and lowest production cost in the last 10 years.
-- Show result in a single table. 

select * from (
	select Top (1) g.genreName, SUM(m.productionCost) totalProductionCost
	from Genre g
	join MovieGenre mg
	on g.genreId=mg.genreId
	join Movie m
	on mg.movieId=m.movieId
	where Year(m.releaseDate) > YEAR(CURRENT_TIMESTAMP)-10
	group by g.genreName
	order by totalProductionCost DESC
) as T1
Union
select * from (
	select Top (1) g.genreName, SUM(m.productionCost) totalProductionCost
	from Genre g
	join MovieGenre mg
	on g.genreId=mg.genreId
	join Movie m
	on mg.movieId=m.movieId
	where Year(m.releaseDate) > YEAR(CURRENT_TIMESTAMP)-10
	group by g.genreName
	order by totalProductionCost ASC
) as T2

--5) List the genre name and total production cost of the genre with 
-- the second lowest production cost of all time.

select top (1) * from (
	select Top 2 g.genreName, SUM(m.productionCost) totalProductionCost
	from Genre g
	join MovieGenre mg
	on g.genreId=mg.genreId
	join Movie m
	on mg.movieId=m.movieId
	group by g.genreName
	order by totalProductionCost asc
) t1
order by t1.totalProductionCost desc

--6) List the names of all the actors and movie titles, who have starred in movies which have 
-- running time lesser than the average running time of all movies 
-- but production cost greater than the average production cost of all movies.

select a.actorName, m1.movieTitle, m1.runningTime, m1.productionCost
from Actor as a 
join StarsIn as si
on a.actorId = si.actorId
join Movie as m1
on si.movieId = m1.movieId
where m1.runningTime < ( 
	select AVG(m.runningTime) totalAvgRunningTime
	from Movie as m
) 
AND m1.productionCost > (
	select AVG(m.productionCost) totalAvgProductionCost
	from Movie as m)


--1a--
create table Employee
(
--EmployeeId int primary key, 
EmployeeName varchar(20) primary key NOT NULL, 
streetAddress varchar(100), 
city varchar (15)

);

create table Company
(
--RegisterationNmber int primary key,
companyName varchar(20) primary key NOT NULL,
city varchar(15)
);

create table works
(
employeeName varchar(20) primary key not null,
companyName varchar(20),
salary float
);

create table manages
(
employeeName varchar (20) primary key NOT NULL, 
managerName varchar(30)
);


--1b--

--Foreign Key Constraints

alter table Works add constraint FK_Employee foreign key (employeeName) references Employee(employeeName) on update cascade
alter table works add constraint FK_Company foreign key (companyName) references Company (CompanyName) on Delete set NULL
alter table manages add constraint FK_EmployeM foreign key (employeeName) references Employee(employeeName) on update cascade


--1c--


alter table employee add Phone int check (len(phone)=11)
alter table Company add establishDate date check(establishDate >= datepart(yyyy,getdate()-2))
alter table works add constraint salary  default 4000 for Salary
alter table [company] drop column [city] 
