-----------------------------------------------------Mid-1 Fall-2020-----------------------------------------------------
--create table PATIENT(
--PatID int primary key,
--Pname varchar(25),
--Category varchar(5)
--)

--create table MEDICALCASE(
--CaseID int primary key,
--PatID int foreign key references PATIENT(PatID),
--InjuryDate date
--)

--create table CLAIM(
--CaseID int primary key foreign key references MEDICALCASE(CaseID),
--Amount int,
--Type varchar(15)
--)

--insert into PATIENT values
--('100','Isbah','Adult'),
--('200','Izaan','Child'),
--('300','Tahreem','Child'),
--('400','Izaan','Adult'),
--('500','Tahreem','Adult')

--insert into MEDICALCASE values
--('1','100','2020-05-15'),
--('2','200','2020-05-20'),
--('3','100','2020-10-13'),
--('4','100','2020-10-16'),
--('5','100','2020-10-19')

--insert into Claim values
--('1','10000','InPatient'),
--('3','30000','Emergency')

--select * from Patient;
--select * from Medicalcase;
--select * from Claim;

--Q1
--SELECT P.patID, P.Pname, P.category
--FROM patient AS P LEFT OUTER JOIN medicalcase AS M ON P.patID=M.patID
--WHERE P.category != 'Child' AND M.caseID IS NULL

--Q2
--SELECT P.patID, P.Pname, COUNT(M.caseID) AS TotalCases
--FROM patient AS P JOIN medicalcase AS M ON P.patID=M.patID JOIN claim C ON M.caseID=C.caseID
--GROUP BY P.patID, P.Pname

--Q3
--select P.Pname from Patient as P join Medicalcase as M on P.PatID = M.PatID
--join Claim as C on M.CaseID = C.CaseID where C.Amount > '15000';

--Q4
--select distinct P1.PatID, P2.PatID, P1.Pname from Patient as P1 inner join Patient as P2
--on P1.Pname = P2.Pname where P1.PatID != P2.PatID

-----------------------------------------------------Mid-1 Fall-2021-----------------------------------------------------
