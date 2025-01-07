create table Department(
dept_id varchar(3) primary key,
name varchar(255)
)

create table Student(
roll_no varchar(8) primary key,
name varchar(255),
dept_id varchar(3) foreign key references Department(dept_id),
batch int
)

create table Course(
course_id varchar(5) primary key,
name varchar(255),
credit_hrs int,
dept_id varchar(3) foreign key references Department(dept_id)
)

create table Section (
section_id varchar(4) primary key,
course_id varchar(5) foreign key references Course(course_id),
capacity int
)

create table Enrolled(
student_roll_no varchar(8) foreign key references Student(roll_no),
section_id varchar(4) foreign key references Section(section_id)
)

create table Faculty(
faculty_id int,
name varchar(255),
dept_id varchar(3) foreign key references Department(dept_id)
)