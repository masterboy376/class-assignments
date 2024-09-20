Windows PowerShell
Copyright (C) Microsoft Corporation. All rights reserved.

Install the latest PowerShell for new features and improvements! https://aka.ms/PSWindows

PS C:\Users\Student> mysql -u sam -p
Enter password: ******
Welcome to the MySQL monitor.  Commands end with ; or \g.
Your MySQL connection id is 8
Server version: 9.0.1 MySQL Community Server - GPL

Copyright (c) 2000, 2024, Oracle and/or its affiliates.

Oracle is a registered trademark of Oracle Corporation and/or its
affiliates. Other names may be trademarks of their respective
owners.

Type 'help;' or '\h' for help. Type '\c' to clear the current input statement.

mysql> show tables;
ERROR 1046 (3D000): No database selected
mysql> show table;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '' at line 1
mysql> show databases
    -> ;
+--------------------+
| Database           |
+--------------------+
| employee           |
| information_schema |
| mysql              |
| performance_schema |
| sys                |
| world              |
+--------------------+
6 rows in set (0.03 sec)

mysql> use employee;
Database changed
mysql> show tables
    -> ;
+--------------------+
| Tables_in_employee |
+--------------------+
| company            |
| employee           |
| manages            |
| works              |
+--------------------+
4 rows in set (0.01 sec)

mysql> \
mysql>
mysql>
mysql>
mysql> select *
    -> from company;
+------------------------+----------+
| company_name           | city     |
+------------------------+----------+
| first bank corporation | hydrabad |
| yes bank corporation   | delhi    |
+------------------------+----------+
2 rows in set (0.03 sec)

mysql>
mysql> update company
    -> city='varanasi'
    -> where company_name='first bank corporation';
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '='varanasi'
where company_name='first bank corporation'' at line 2
mysql> update company
    -> city='varanasi',
    -> where company_name='first bank corporation';
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '='varanasi',
where company_name='first bank corporation'' at line 2
mysql> select *
    -> from employee
    -> ;
+-----------------+------------------------+----------+------------------------+
| employee_name   | street                 | city     | email_id               |
+-----------------+------------------------+----------+------------------------+
| deependar goyal | block 5, shastri nagar | delhi    | deependargoyal@yb.corp |
| smith jones     | st 52, julbee hills    | hydrabad | smithjones@fb.corp     |
+-----------------+------------------------+----------+------------------------+
2 rows in set (0.02 sec)

mysql> update company
    -> set city='varanasi'
    -> where company_name='first bank corporation';
Query OK, 1 row affected (0.02 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select * from company;
+------------------------+----------+
| company_name           | city     |
+------------------------+----------+
| first bank corporation | varanasi |
| yes bank corporation   | delhi    |
+------------------------+----------+
2 rows in set (0.00 sec)

mysql> select * from works;
+-----------------+------------------------+--------+
| employee_name   | company_name           | salary |
+-----------------+------------------------+--------+
| deependar goyal | yes bank corporation   | 890000 |
| smith jones     | first bank corporation | 780000 |
+-----------------+------------------------+--------+
2 rows in set (0.02 sec)

mysql> update employee
    -> set city='varanasi'
    -> where employee_name='smith jones';
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> update works
    -> set salary=89000
    -> where salary=890000;
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> update works
    -> set salary=78000
    -> where salary=780000;
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select * from works;
+-----------------+------------------------+--------+
| employee_name   | company_name           | salary |
+-----------------+------------------------+--------+
| deependar goyal | yes bank corporation   |  89000 |
| smith jones     | first bank corporation |  78000 |
+-----------------+------------------------+--------+
2 rows in set (0.00 sec)

mysql> ALTER TABLE Orders
    -> ADD CONSTRAINT FK_PersonOrder
    -> FOREIGN KEY (PersonID) REFERENCES Persons(PersonID);
ERROR 1146 (42S02): Table 'employee.orders' doesn't exist
mysql> ALTER TABLE works
    -> ADD CONSTRAINT fk_emp
    -> FOREIGN KEY (employee_name) REFERENCES employee(employee_name);
Query OK, 2 rows affected (0.05 sec)
Records: 2  Duplicates: 0  Warnings: 0

mysql> desc works
    -> ;
+---------------+-------------+------+-----+---------+-------+
| Field         | Type        | Null | Key | Default | Extra |
+---------------+-------------+------+-----+---------+-------+
| employee_name | varchar(30) | NO   | PRI | NULL    |       |
| company_name  | varchar(50) | YES  |     | NULL    |       |
| salary        | int         | YES  |     | NULL    |       |
+---------------+-------------+------+-----+---------+-------+
3 rows in set (0.01 sec)

mysql> ALTER TABLE works
    -> ADD CONSTRAINT fk_cmp
    -> FOREIGN KEY (company_name) REFERENCES company(company_name);
Query OK, 2 rows affected (0.05 sec)
Records: 2  Duplicates: 0  Warnings: 0

mysql> desc works;
+---------------+-------------+------+-----+---------+-------+
| Field         | Type        | Null | Key | Default | Extra |
+---------------+-------------+------+-----+---------+-------+
| employee_name | varchar(30) | NO   | PRI | NULL    |       |
| company_name  | varchar(50) | YES  | MUL | NULL    |       |
| salary        | int         | YES  |     | NULL    |       |
+---------------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> INSERT INTO table_name (column1, column2, column3, ...)
    -> VALUES (value1, value2, value3, ...);
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '...)
VALUES (value1, value2, value3, ...)' at line 1
mysql> INSERT INTO employee (employee_name, street, city, email_id)
    -> VALUES ('piyush mittal', 'park avenue', 'mumbai', 15000),
    -> ('akash singhania', 'lanka', 'varanasi', 5000)
    -> ;
Query OK, 2 rows affected (0.01 sec)
Records: 2  Duplicates: 0  Warnings: 0

mysql> INSERT INTO employee (employee_name, street, city, email_id)
    -> VALUES ('latika joshi', 'race course', 'dehradun', 45000);
Query OK, 1 row affected (0.08 sec)

mysql> INSERT INTO works (employee_name, company_name, salary)
    -> values ('piyush mittal', 'first bank corporation', 15000)
    -> ;
Query OK, 1 row affected (0.01 sec)

mysql> INSERT INTO works (employee_name, company_name, salary)
    -> values ('akash singhania', 'first bank corporation', 5000),
    -> ('latika joshi', 'first bank corporation', 45000);
Query OK, 2 rows affected (0.01 sec)
Records: 2  Duplicates: 0  Warnings: 0

mysql> select * from works
    -> ;
+-----------------+------------------------+--------+
| employee_name   | company_name           | salary |
+-----------------+------------------------+--------+
| akash singhania | first bank corporation |   5000 |
| deependar goyal | yes bank corporation   |  89000 |
| latika joshi    | first bank corporation |  45000 |
| piyush mittal   | first bank corporation |  15000 |
| smith jones     | first bank corporation |  78000 |
+-----------------+------------------------+--------+
5 rows in set (0.00 sec)

mysql> select * from employee
    -> ;
+-----------------+------------------------+----------+------------------------+
| employee_name   | street                 | city     | email_id               |
+-----------------+------------------------+----------+------------------------+
| akash singhania | lanka                  | varanasi | 5000                   |
| deependar goyal | block 5, shastri nagar | delhi    | deependargoyal@yb.corp |
| latika joshi    | race course            | dehradun | 45000                  |
| piyush mittal   | park avenue            | mumbai   | 15000                  |
| smith jones     | st 52, julbee hills    | varanasi | smithjones@fb.corp     |
+-----------------+------------------------+----------+------------------------+
5 rows in set (0.00 sec)

mysql> update employee
    -> set email_id='aksingh@yahoo.com'
    -> where employee_name='akash singhania';
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> update employee
    -> set email_id='latika262@gmail.com'
    -> where employee_name='latika joshi';
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> update employee
    -> set email_id='piyushmittal15@hotmail.com'
    -> where employee_name='piyush mittal';
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select * from employee;
+-----------------+------------------------+----------+----------------------------+
| employee_name   | street                 | city     | email_id                   |
+-----------------+------------------------+----------+----------------------------+
| akash singhania | lanka                  | varanasi | aksingh@yahoo.com          |
| deependar goyal | block 5, shastri nagar | delhi    | deependargoyal@yb.corp     |
| latika joshi    | race course            | dehradun | latika262@gmail.com        |
| piyush mittal   | park avenue            | mumbai   | piyushmittal15@hotmail.com |
| smith jones     | st 52, julbee hills    | varanasi | smithjones@fb.corp         |
+-----------------+------------------------+----------+----------------------------+
5 rows in set (0.00 sec)

mysql> select * from works;
+-----------------+------------------------+--------+
| employee_name   | company_name           | salary |
+-----------------+------------------------+--------+
| akash singhania | first bank corporation |   5000 |
| deependar goyal | yes bank corporation   |  89000 |
| latika joshi    | first bank corporation |  45000 |
| piyush mittal   | first bank corporation |  15000 |
| smith jones     | first bank corporation |  78000 |
+-----------------+------------------------+--------+
5 rows in set (0.00 sec)

mysql> select * from company;
+------------------------+----------+
| company_name           | city     |
+------------------------+----------+
| first bank corporation | varanasi |
| yes bank corporation   | delhi    |
+------------------------+----------+
2 rows in set (0.00 sec)

mysql> update employee
    -> set street='clock tower, cant.'
    -> where employee_name='smith jones';
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select * from employee;
+-----------------+------------------------+----------+----------------------------+
| employee_name   | street                 | city     | email_id                   |
+-----------------+------------------------+----------+----------------------------+
| akash singhania | lanka                  | varanasi | aksingh@yahoo.com          |
| deependar goyal | block 5, shastri nagar | delhi    | deependargoyal@yb.corp     |
| latika joshi    | race course            | dehradun | latika262@gmail.com        |
| piyush mittal   | park avenue            | mumbai   | piyushmittal15@hotmail.com |
| smith jones     | clock tower, cant.     | varanasi | smithjones@fb.corp         |
+-----------------+------------------------+----------+----------------------------+
5 rows in set (0.00 sec)

mysql> INSERT INTO manages (employee_name, manager_name)
    -> values ('akash singhania', 'smith jones'),
    -> ('latika joshi', 'smith jones'),
    -> ('piyush mittal', 'smith jones');
Query OK, 3 rows affected (0.02 sec)
Records: 3  Duplicates: 0  Warnings: 0

mysql> select * from manages;
+-----------------+--------------+
| employee_name   | manager_name |
+-----------------+--------------+
| akash singhania | smith jones  |
| latika joshi    | smith jones  |
| piyush mittal   | smith jones  |
+-----------------+--------------+
3 rows in set (0.00 sec)

mysql> INSERT INTO employee (employee_name, street, city, email_id)
    -> VALUES ('ramya juneja', 'st 52, jublee hills', 'hydrabad', 'ramyajuneja64@gmail.com'),
    -> ('ramya juneja', 'st 52, 'm.g. road', 'bangalore', 'dhritisharmaofficial@gmail.com'),
    '> ('rudra pandey', 'vidya vihar', 'dehradun', 'rudrapandey87@gmail.com','sf');
    '> ;
    '> ;;
    '> ;
    '> ;^C
mysql> INSERT INTO employee (employee_name, street, city, email_id)
    -> VALUES ('ramya juneja', 'st 52, jublee hills', 'hydrabad', 'ramyajuneja64@gmail.com'),
    -> ('dhriti sharma', 'm.g. road', 'bangalore', 'dhritisharmaofficial@gmail.com'),
    -> ('rudra pandey', 'vidya vihar colony', 'dehradun', 'rudrapandey87@gmail.com');
Query OK, 3 rows affected (0.01 sec)
Records: 3  Duplicates: 0  Warnings: 0

mysql> INSERT INTO works (employee_name, company_name, salary)
    -> values ('ramya juneja', 'yes bank corporation', 49000),
    -> ('rudra pandey', 'yes bank corporation', 8700),
    -> ('dhriti sharma', 'yes bank corporation', 19000);
Query OK, 3 rows affected (0.01 sec)
Records: 3  Duplicates: 0  Warnings: 0

mysql> INSERT INTO manages (employee_name, manager_name)
    -> values ('ramya juneja', 'deependar goyal'),
    -> ('rudra pandey', 'deependar goyal'),
    -> ('dhriti sharma', 'deependar goyal');
Query OK, 3 rows affected (0.01 sec)
Records: 3  Duplicates: 0  Warnings: 0

mysql> select * from company;
+------------------------+----------+
| company_name           | city     |
+------------------------+----------+
| first bank corporation | varanasi |
| yes bank corporation   | delhi    |
+------------------------+----------+
2 rows in set (0.00 sec)

mysql> select * from works;
+-----------------+------------------------+--------+
| employee_name   | company_name           | salary |
+-----------------+------------------------+--------+
| akash singhania | first bank corporation |   5000 |
| deependar goyal | yes bank corporation   |  89000 |
| dhriti sharma   | yes bank corporation   |  19000 |
| latika joshi    | first bank corporation |  45000 |
| piyush mittal   | first bank corporation |  15000 |
| ramya juneja    | yes bank corporation   |  49000 |
| rudra pandey    | yes bank corporation   |   8700 |
| smith jones     | first bank corporation |  78000 |
+-----------------+------------------------+--------+
8 rows in set (0.00 sec)

mysql> select * from employee;
+-----------------+------------------------+-----------+--------------------------------+
| employee_name   | street                 | city      | email_id                       |
+-----------------+------------------------+-----------+--------------------------------+
| akash singhania | lanka                  | varanasi  | aksingh@yahoo.com              |
| deependar goyal | block 5, shastri nagar | delhi     | deependargoyal@yb.corp         |
| dhriti sharma   | m.g. road              | bangalore | dhritisharmaofficial@gmail.com |
| latika joshi    | race course            | dehradun  | latika262@gmail.com            |
| piyush mittal   | park avenue            | mumbai    | piyushmittal15@hotmail.com     |
| ramya juneja    | st 52, jublee hills    | hydrabad  | ramyajuneja64@gmail.com        |
| rudra pandey    | vidya vihar colony     | dehradun  | rudrapandey87@gmail.com        |
| smith jones     | clock tower, cant.     | varanasi  | smithjones@fb.corp             |
+-----------------+------------------------+-----------+--------------------------------+
8 rows in set (0.00 sec)

mysql> select * from manages;
+-----------------+-----------------+
| employee_name   | manager_name    |
+-----------------+-----------------+
| akash singhania | smith jones     |
| dhriti sharma   | deependar goyal |
| latika joshi    | smith jones     |
| piyush mittal   | smith jones     |
| ramya juneja    | deependar goyal |
| rudra pandey    | deependar goyal |
+-----------------+-----------------+
6 rows in set (0.00 sec)

mysql> select employee_name form works where company_name='first bank corporation';
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'works where company_name='first bank corporation'' at line 1
mysql> select employee_name form works where company_name='first bank corporation';
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'works where company_name='first bank corporation'' at line 1
mysql> select employee_name form works;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'works' at line 1
mysql> select employee_name from works where company_name='first bank corporation';
+-----------------+
| employee_name   |
+-----------------+
| akash singhania |
| latika joshi    |
| piyush mittal   |
| smith jones     |
+-----------------+
4 rows in set (0.00 sec)

mysql> select employee_name form works where company_name in ('first bank corporation', 'yes bank corporation');
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'works where company_name in ('first bank corporation', 'yes bank corporation')' at line 1
mysql> select employee_name from works where company_name in ('first bank corporation', 'yes bank corporation');
+-----------------+
| employee_name   |
+-----------------+
| akash singhania |
| latika joshi    |
| piyush mittal   |
| smith jones     |
| deependar goyal |
| dhriti sharma   |
| ramya juneja    |
| rudra pandey    |
+-----------------+
8 rows in set (0.00 sec)

mysql> select employee_name from works where salary between 20000 and 50000;
+---------------+
| employee_name |
+---------------+
| latika joshi  |
| ramya juneja  |
+---------------+
2 rows in set (0.00 sec)

mysql> select employee.city
    -> form works
    -> inner join employee
    -> where works.company_name='first bank corporation';
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'works
inner join employee
where works.company_name='first bank corporation'' at line 2
mysql> select employee.city
    -> from works
    -> inner join employee
    -> where works.company_name='first bank corporation';
+-----------+
| city      |
+-----------+
| varanasi  |
| varanasi  |
| varanasi  |
| varanasi  |
| delhi     |
| delhi     |
| delhi     |
| delhi     |
| bangalore |
| bangalore |
| bangalore |
| bangalore |
| dehradun  |
| dehradun  |
| dehradun  |
| dehradun  |
| mumbai    |
| mumbai    |
| mumbai    |
| mumbai    |
| hydrabad  |
| hydrabad  |
| hydrabad  |
| hydrabad  |
| dehradun  |
| dehradun  |
| dehradun  |
| dehradun  |
| varanasi  |
| varanasi  |
| varanasi  |
| varanasi  |
+-----------+
32 rows in set (0.00 sec)

mysql> select employee.city
    -> form works
    -> inner join employee
    -> where employee.employee_name=works.employee_name and works.company_name='first bank corporation';
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'works
inner join employee
where employee.employee_name=works.employee_name and w' at line 2
mysql> select employee.city
    -> form works
    -> inner join employee
    -> where (employee.employee_name=works.employee_name and works.company_name='first bank corporation');
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'works
inner join employee
where (employee.employee_name=works.employee_name and ' at line 2
mysql> select employee.city
    -> form works
    -> inner join employee
    -> where (employee.employee_name=works.employee_name AND works.company_name='first bank corporation');
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'works
inner join employee
where (employee.employee_name=works.employee_name AND ' at line 2
mysql> select employee.city
    -> form works
    -> inner join employee
    -> on employee.employee_name=works.employee_name
    -> where works.company_name='first bank corporation';
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'works
inner join employee
on employee.employee_name=works.employee_name
where wo' at line 2
mysql> select employee.city
    -> form works
    -> inner join employee
    -> where employee.employee_name=works.employee_name;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'works
inner join employee
where employee.employee_name=works.employee_name' at line 2
mysql> form works
    -> ^C
mysql> select employee.city
    -> form works
    -> inner join employee
    -> on employee.employee_name=works.employee_name;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'works
inner join employee
on employee.employee_name=works.employee_name' at line 2
mysql> select employee.city
    -> form works
    -> inner join employee
    -> on employee_name
    -> where works.company_name='first bank corporation';
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'works
inner join employee
on employee_name
where works.company_name='first bank ' at line 2
mysql> select employee.city
    -> form works
    -> inner join employee
    ->
    -> on employee_name;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'works
inner join employee

on employee_name' at line 2
mysql> select employee.city
    -> ^C
mysql> ^C
mysql> ^C
mysql> ^C
mysql> ^C
mysql> ^C
mysql> clear
mysql> select city
    -> from employee inner join works
    -> on employee.employee_name = works.employee_name
    -> where company_name='first bank corporation';
+----------+
| city     |
+----------+
| varanasi |
| dehradun |
| mumbai   |
| varanasi |
+----------+
4 rows in set (0.00 sec)

mysql> select employee_name, street, city
    -> from employee inner join works
    -> on employee.employee_name = works.employee_name
    -> where company_name='first bank corporation' and salary>10000;
ERROR 1052 (23000): Column 'employee_name' in field list is ambiguous
mysql> select employee.employee_name, street, city
    -> from employee inner join works
    -> on employee.employee_name = works.employee_name
    -> where company_name='first bank corporation' and salary>10000;
+---------------+--------------------+----------+
| employee_name | street             | city     |
+---------------+--------------------+----------+
| latika joshi  | race course        | dehradun |
| piyush mittal | park avenue        | mumbai   |
| smith jones   | clock tower, cant. | varanasi |
+---------------+--------------------+----------+
3 rows in set (0.00 sec)

mysql> select * from employee inner join works
    -> on employee.employee_name = works.employee_name
    -> where company_name is not 'first bank corporation';
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near ''first bank corporation'' at line 3
mysql> select * from employee inner join works
    -> on employee.employee_name = works.employee_name
    -> where company_name!='first bank corporation';
+-----------------+------------------------+-----------+--------------------------------+-----------------+----------------------+--------+
| employee_name   | street                 | city      | email_id                       | employee_name   | company_name         | salary |
+-----------------+------------------------+-----------+--------------------------------+-----------------+----------------------+--------+
| deependar goyal | block 5, shastri nagar | delhi     | deependargoyal@yb.corp         | deependar goyal | yes bank corporation |  89000 |
| dhriti sharma   | m.g. road              | bangalore | dhritisharmaofficial@gmail.com | dhriti sharma   | yes bank corporation |  19000 |
| ramya juneja    | st 52, jublee hills    | hydrabad  | ramyajuneja64@gmail.com        | ramya juneja    | yes bank corporation |  49000 |
| rudra pandey    | vidya vihar colony     | dehradun  | rudrapandey87@gmail.com        | rudra pandey    | yes bank corporation |   8700 |
+-----------------+------------------------+-----------+--------------------------------+-----------------+----------------------+--------+
4 rows in set (0.01 sec)

mysql> select employee.employee_name
    -> from employee inner join manages
    -> on employee.employee_name = works.employee_name
    -> where manager_name='smith jones';
ERROR 1054 (42S22): Unknown column 'works.employee_name' in 'on clause'
mysql> select employee.employee_name
    -> from employee inner join manages
    -> on employee.employee_name = works.employee_name;
ERROR 1054 (42S22): Unknown column 'works.employee_name' in 'on clause'
mysql> select employee.employee_name
    -> from employee inner join manages
    -> on employee.employee_name = manages.employee_name;
+-----------------+
| employee_name   |
+-----------------+
| akash singhania |
| dhriti sharma   |
| latika joshi    |
| piyush mittal   |
| ramya juneja    |
| rudra pandey    |
+-----------------+
6 rows in set (0.00 sec)

mysql> select employee.employee_name
    -> from employee inner join manages
    -> on employee.employee_name = manages.employee_name
    -> where manager_name='smith jones';
+-----------------+
| employee_name   |
+-----------------+
| akash singhania |
| latika joshi    |
| piyush mittal   |
+-----------------+
3 rows in set (0.00 sec)

mysql> insert into manages values
    -> ('smith jone'),
    -> ('deependar goyal');
ERROR 1136 (21S01): Column count doesn't match value count at row 1
mysql> insert into manages (employee_name, manager_name) values
    -> ('smith jone', ),
    -> ('deependar goyal', );
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '),
('deependar goyal', )' at line 2
mysql> insert into manages (employee_name, manager_name) values
    -> ('smith jone'),
    -> ('deependar goyal');
ERROR 1136 (21S01): Column count doesn't match value count at row 1
mysql> insert into manages (employee_name, manager_name) values
    -> ('smith jone', null),
    -> ('deependar goyal', null);
Query OK, 2 rows affected (0.01 sec)
Records: 2  Duplicates: 0  Warnings: 0

mysql> select * form manages;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'form manages' at line 1
mysql> select * from manages;
+-----------------+-----------------+
| employee_name   | manager_name    |
+-----------------+-----------------+
| akash singhania | smith jones     |
| deependar goyal | NULL            |
| dhriti sharma   | deependar goyal |
| latika joshi    | smith jones     |
| piyush mittal   | smith jones     |
| ramya juneja    | deependar goyal |
| rudra pandey    | deependar goyal |
| smith jone      | NULL            |
+-----------------+-----------------+
8 rows in set (0.00 sec)

mysql> select employee.employee_name
    -> from employee inner join manages
    -> on employee.employee_name = manages.employee_name
    -> where manager_name is NULL;
+-----------------+
| employee_name   |
+-----------------+
| deependar goyal |
+-----------------+
1 row in set (0.00 sec)

mysql> update manages
    -> set employee_name='smith jones'
    -> where employee_name='smith jone';
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> select employee.employee_name
    -> from employee inner join manages
    ->
    -> on employee.employee_name = manages.employee_name
    -> where manager_name is NULL;
+-----------------+
| employee_name   |
+-----------------+
| deependar goyal |
| smith jones     |
+-----------------+
2 rows in set (0.00 sec)

mysql> select employee.employee_name
    -> from employee inner join manages
    -> on employee.employee_name = manages.employee_name
    -> where (manager_name is NULL) and (city='varanasi');
+---------------+
| employee_name |
+---------------+
| smith jones   |
+---------------+
1 row in set (0.00 sec)

mysql> select * form employee where employee_name='p%';
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'form employee where employee_name='p%'' at line 1
mysql> select * from employee where employee_name='p%';
Empty set (0.00 sec)

mysql> select * from employee where employee_name='%p%';
Empty set (0.00 sec)

mysql> select * from employee where employee_name is like '%p%';
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'like '%p%'' at line 1
mysql> select * from employee where employee_name like '%p%';
+-----------------+------------------------+----------+----------------------------+
| employee_name   | street                 | city     | email_id                   |
+-----------------+------------------------+----------+----------------------------+
| deependar goyal | block 5, shastri nagar | delhi    | deependargoyal@yb.corp     |
| piyush mittal   | park avenue            | mumbai   | piyushmittal15@hotmail.com |
| rudra pandey    | vidya vihar colony     | dehradun | rudrapandey87@gmail.com    |
+-----------------+------------------------+----------+----------------------------+
3 rows in set (0.01 sec)

mysql> select * from employee where employee_name like 'p%';
+---------------+-------------+--------+----------------------------+
| employee_name | street      | city   | email_id                   |
+---------------+-------------+--------+----------------------------+
| piyush mittal | park avenue | mumbai | piyushmittal15@hotmail.com |
+---------------+-------------+--------+----------------------------+
1 row in set (0.00 sec)

mysql> select * from employee where employee_name like '%a';
+-----------------+---------------------+-----------+--------------------------------+
| employee_name   | street              | city      | email_id                       |
+-----------------+---------------------+-----------+--------------------------------+
| akash singhania | lanka               | varanasi  | aksingh@yahoo.com              |
| dhriti sharma   | m.g. road           | bangalore | dhritisharmaofficial@gmail.com |
| ramya juneja    | st 52, jublee hills | hydrabad  | ramyajuneja64@gmail.com        |
+-----------------+---------------------+-----------+--------------------------------+
3 rows in set (0.00 sec)

mysql> select employee.employee_name
    -> from employee inner join works
    -> on employee.employee_name = works.employee_name
    -> where company_name like '__s%';
+-----------------+
| employee_name   |
+-----------------+
| deependar goyal |
| dhriti sharma   |
| ramya juneja    |
| rudra pandey    |
+-----------------+
4 rows in set (0.00 sec)

mysql> select employee_name from employee where email_id like '%gmail%';
+---------------+
| employee_name |
+---------------+
| dhriti sharma |
| latika joshi  |
| ramya juneja  |
| rudra pandey  |
+---------------+
4 rows in set (0.00 sec)

mysql>
