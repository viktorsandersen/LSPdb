# LSPdb

## Diagram 
![image](https://github.com/user-attachments/assets/9b145d29-3655-41ad-9ddf-30d28cb831d2)


## Creating the Database
This code creates a dummy database to test the application

```sql
CREATE DATABASE lsp WITH PASSWORD =  'lsp'; Set the desired password

CREATE TABLE Contacts (
 first_name varchar (50),
 last_name varchar (50) ,
 phone_number integer,
 email varchar (255),
 department varchar 
);

CREATE TABLE  Department (
 name varchar (50),
 city varchar (50),
 country varchar (50), 
 company varchar (50), 
 department_id integer PRIMARY KEY
);

CREATE TABLE Companies (
  name          varchar (50),
  city             varchar (50),
  country       varchar (50),
  company_id integer PRIMARY KEY 
);

INSERT INTO Contacts (First_name, Last_name, Phone_number,Email,Department) VALUES
      
('Emily', 'Anderson', '12345678', 'emily.anderson@example.com', 'R&D'),
('Daniel', 'Thompson', '23456789', 'daniel.thompson@example.com', 'HR'),
('Olivia', 'Harris', '34567890', 'olivia.harris@example.com', 'R&D'),
('Alexander', 'Martinez', '45678901', 'alexander.martinez@example.com', 'SOME'),
('Sophia', 'Robinson', '56789012', 'sophia.robinson@example.com', 'HR'),
('William', 'Clark', '67890123', 'william.clark@example.com', 'R&D'),
('Amelia', 'Rodriguez', '78901234', 'amelia.rodriguez@example.com', 'SOME'),
('James', 'Lewis', '89012345', 'james.lewis@example.com', 'HR'),
('Charlotte', 'Lee', '90123456', 'charlotte.lee@example.com', 'R&D'),
('Benjamin', 'Walker', '12345678', 'benjamin.walker@example.com', 'SOME'),
('Ava', 'Hall', '23456789', 'ava.hall@example.com', 'HR'),
('Mason', 'Allen', '34567890', 'mason.allen@example.com', 'R&D'),
('Harper', 'Young', '45678901', 'harper.young@example.com', 'SOME'),
('Evelyn', 'Hernandez', '56789012', 'evelyn.hernandez@example.com', 'HR'),
('Ethan', 'King', '67890123', 'ethan.king@example.com', 'R&D'),
('Abigail', 'Scott', '78901234', 'abigail.scott@example.com', 'SOME'),
('Victoria', 'Adams', '89012345', 'victoria.adams@example.com', 'HR'),
('Michael', 'Baker', '90123456', 'michael.baker@example.com', 'R&D'),
('Elizabeth', 'Gonzalez', '12345678', 'elizabeth.gonzalez@example.com', 'SOME'),
('Mia', 'Nelson', '23456789', 'mia.nelson@example.com', 'HR'),
('Sebastian', 'Carter', '34567890', 'sebastian.carter@example.com', 'R&D'),
('Camila', 'Perez', '45678901', 'camila.perez@example.com', 'SOME'),
('Lucas', 'Evans', '56789012', 'lucas.evans@example.com', 'HR'),
('Madison', 'Turner', '67890123', 'madison.turner@example.com', 'R&D'),
('Henry', 'Collins', '78901234', 'henry.collins@example.com', 'SOME'),
('Liam', 'Parker', '89012345', 'liam.parker@example.com', 'HR'),
('Chloe', 'Edwards', '90123456', 'chloe.edwards@example.com', 'R&D'),
('Grace', 'Mitchell', '12345678', 'grace.mitchell@example.com', 'SOME'),
('Zoe', 'Diaz', '23456789', 'zoe.diaz@example.com', 'HR'),
('Elijah', 'Campbell', '34567890', 'elijah.campbell@example.com', 'R&D'),
('Natalie', 'Perez', '45678901', 'natalie.perez@example.com', 'SOME'),
('Logan', 'Fisher', '56789012', 'logan.fisher@example.com', 'HR'),
('Isabella', 'Ward', '67890123', 'isabella.ward@example.com', 'R&D'),
('Luna', 'Hill', '78901234', 'luna.hill@example.com', 'SOME'),
('Ryan', 'Cox', '89012345', 'ryan.cox@example.com', 'HR'),
('Jackson', 'Price', '90123456', 'jackson.price@example.com', 'R&D'),
('Avery', 'Hayes', '12345678', 'avery.hayes@example.com', 'SOME'),
('Layla', 'Ramirez', '23456789', 'layla.ramirez@example.com', 'HR'),
('Sofia', 'Brooks', '34567890', 'sofia.brooks@example.com', 'R&D'),
('Harper', 'Russell', '45678901', 'harper.russell@example.com', 'SOME'),
('Daniel', 'Barnes', '56789012', 'daniel.barnes@example.com', 'HR'),
('Liam', 'Long', '67890123', 'liam.long@example.com', 'R&D'),
('Zoey', 'Flores', '78901234', 'zoey.flores@example.com', 'SOME'),
('Mila', 'Bennett', '89012345', 'mila.bennett@example.com', 'HR'),
('Eleanor', 'Reed', '90123456', 'eleanor.reed@example.com', 'R&D'),
('Carter', 'Foster', '12345678', 'carter.foster@example.com', 'SOME'),
('Elena', 'Gray', '23456789', 'elena.gray@example.com', 'HR'),
('Hudson', 'Brooks', '34567890', 'hudson.brooks@example.com', 'R&D'),
('Aria', 'Hughes', '45678901', 'aria.hughes@example.com', 'SOME'),
('Gabriel', 'Perry', '56789012', 'gabriel.perry@example.com', 'HR');


INSERT INTO Department(Name, City, Country,Company, department_ID) VALUES
('R&D', 'Odense SØ', 'Denmark','Mir', 1),
('HR', 'Odense SØ', 'Denmark','Mir', 2),
('SOME', 'Odense SØ', 'Denmark','Mir', 3),
('R&D', 'Odense S', 'Denmark','Blue Ocean', 4),
('HR', 'Odense S', 'Denmark','Blue Ocean', 5),
('SOME', 'Odense S', 'Denmark','Blue Ocean', 6),
('R&D', 'Odense SØ', 'Denmark','Universal Robotics', 7),
('HR', 'Odense SØ', 'Denmark','Universal Robotics', 8),
('SOME', 'Odense SØ', 'Denmark','Universal Robotics', 9),
('R&D', 'Svendborg', 'Denmark','Odico A/S', 10),
('HR', 'Svendborg', 'Denmark','Odico A/S', 11),
('SOME', 'Svendborg', 'Denmark','Odico A/S', 12);

INSERT INTO Companies(Name,City,Country,Company_ID) VALUES
('Mir','Odense SØ','Denmark',1),
('Blue Ocean','Odense S','Denmark',2),
('Universal Robotics','Odense SØ','Denmark',3),
('Odico A/S','Svenborg','Denmark',4);

psql -d mydb -U myuser
