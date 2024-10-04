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

mysql> show databases;
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
6 rows in set (0.02 sec)

mysql> create database assignement_2
    -> ;
Query OK, 1 row affected (0.01 sec)

mysql> use assignement_2
Database changed
mysql> create table hotel(
    -> hotel_no varchar(20) NOT NULL UNIQUE,
    -> name varchar(30) NOT NULL,
    -> city varchar(30) NOT NULL,
    -> CONSTRAINT hotel_pk PRIMARY KEY (hotel_no));
Query OK, 0 rows affected (0.03 sec)

mysql> create table guest(
    -> guest_no varchar(20) NOT NULL UNIQUE,
    -> name varchar(30) NOT NULL,
    -> city varchar(30) NOT NULL,
    -> CONSTRAINT guest_pk PRIMARY KEY (guest_no));
Query OK, 0 rows affected (0.03 sec)

mysql> create table room(
    -> room_no int NOT NULL,
    -> hotel_no varchar(20) NOT NULL;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near '' at line 3
mysql> create table room(
    -> room_no int NOT NULL,
    -> hotel_no varchar(20) NOT NULL,
    -> type ENUM ('S', 'N') NOT NULL,
    -> price FLOAT NOT NULL,
    -> CONSTRAINT room_pk PRIMARY KEY (room_no, hotel_name),
    -> CONSTRAINT room_to_hotel_fk FOREIGN KEY (hotel_no)
    -> REFERENCES hotel(hotel_no));
ERROR 1072 (42000): Key column 'hotel_name' doesn't exist in table
mysql> create table room(
    -> room_no int NOT NULL,
    -> hotel_no varchar(20) NOT NULL,
    -> type ENUM ('S', 'N') NOT NULL,
    -> price FLOAT NOT NULL,
    -> CONSTRAINT room_pk PRIMARY KEY (room_no, hotel_no),
    -> CONSTRAINT room_to_hotel_fk FOREIGN KEY (hotel_no)
    -> REFERENCES hotel(hotel_no));
Query OK, 0 rows affected (0.03 sec)

mysql> create table booking(
    -> hotel_no varchar(20) NOT NULL,
    -> guest_no varchar(20) NOT NULL,
    -> room_no INT NOT NULL,
    -> date_from DATE NOT NULL,
    -> date_to DATE NOT NULL,
    -> CONSTRAINT booking_pk PRIMARY KEY (guest_no, hotel_no),
    -> CONSTRAINT booking_to_hotel_fk FOREIGN KEY (hotel_no)
    -> REFERENCES hotel(hotel_no),
    -> CONSTRAINT booking_to_guest_fk FOREIGN KEY (guest_no)
    -> REFERENCES guest(guest_no),
    -> CONSTRAINT booking_to_room_fk FOREIGN KEY (room_no, hotel_no)
    -> REFERENCES room(room_no, hotel_no));
Query OK, 0 rows affected (0.04 sec)

mysql> show tables;
+-------------------------+
| Tables_in_assignement_2 |
+-------------------------+
| booking                 |
| guest                   |
| hotel                   |
| room                    |
+-------------------------+
4 rows in set (0.01 sec)

mysql> desc hotel;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| hotel_no | varchar(20) | NO   | PRI | NULL    |       |
| name     | varchar(30) | NO   |     | NULL    |       |
| city     | varchar(30) | NO   |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+
3 rows in set (0.01 sec)

mysql> desc guest;
+----------+-------------+------+-----+---------+-------+
| Field    | Type        | Null | Key | Default | Extra |
+----------+-------------+------+-----+---------+-------+
| guest_no | varchar(20) | NO   | PRI | NULL    |       |
| name     | varchar(30) | NO   |     | NULL    |       |
| city     | varchar(30) | NO   |     | NULL    |       |
+----------+-------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

mysql> desc room;
+----------+---------------+------+-----+---------+-------+
| Field    | Type          | Null | Key | Default | Extra |
+----------+---------------+------+-----+---------+-------+
| room_no  | int           | NO   | PRI | NULL    |       |
| hotel_no | varchar(20)   | NO   | PRI | NULL    |       |
| type     | enum('S','N') | NO   |     | NULL    |       |
| price    | float         | NO   |     | NULL    |       |
+----------+---------------+------+-----+---------+-------+
4 rows in set (0.00 sec)

mysql> desc booking;
+-----------+-------------+------+-----+---------+-------+
| Field     | Type        | Null | Key | Default | Extra |
+-----------+-------------+------+-----+---------+-------+
| hotel_no  | varchar(20) | NO   | PRI | NULL    |       |
| guest_no  | varchar(20) | NO   | PRI | NULL    |       |
| room_no   | int         | NO   | MUL | NULL    |       |
| date_from | date        | NO   |     | NULL    |       |
| date_to   | date        | NO   |     | NULL    |       |
+-----------+-------------+------+-----+---------+-------+
5 rows in set (0.00 sec)

mysql> insert hotel
    -> values
    -> ('H111', 'empire hotel', 'new york'),
    -> ('H235', 'park place', 'new york'),
    -> ('H432', 'brownstone hotel', 'toronto'),
    -> ('H498', 'james plaza', 'toronto'),
    -> ('H193', 'devon hotel', 'boston'),
    -> ('H437', 'clairmont hotel', 'boston');
Query OK, 6 rows affected (0.01 sec)
Records: 6  Duplicates: 0  Warnings: 0

mysql> insert room
    -> values
    -> (313, 'H111', 'S', 145),
    -> (412, 'H111', 'N', 145),
    -> (1267, 'H235', 'N', 175),
    -> (1289, 'H235', 'N', 195),
    -> (876, 'H432', 'S', 124),
    -> (898, 'H432', 'S', 124),
    -> (345, 'H498', 'N', 160),
    -> (467, 'H498', 'N', 180),
    -> (1001, 'H193', 'S', 150),
    -> (1201, 'H193', 'N', 175),
    -> (257, 'H437', 'N', 140),
    -> (223, 'H437', 'N', 155);
Query OK, 12 rows affected (0.26 sec)
Records: 12  Duplicates: 0  Warnings: 0

mysql> insert guest
    -> values
    -> ('G256', 'adam wayne', 'pittsburgh'),
    -> ('G367', 'tara cummings', 'baltimore'),
    -> ('G879', 'vanessa parry', 'pittsburgh'),
    -> ('G230', 'tom hancock', 'philadelphia'),
    -> ('G467', 'robert swift', 'atlanta'),
    -> ('G190', 'edward cane', 'baltimore');
Query OK, 6 rows affected (0.01 sec)
Records: 6  Duplicates: 0  Warnings: 0

mysql> INSERT booking
    -> values
    -> ('H111', 'G256', 412, STR_TO_DATE('10-AUG-99', '%d-%b-%y'), STR_TO_DATE('15-AUG-99', '%d-%b-%y')),
    -> ('H111', 'G367', 412, STR_TO_DATE('18-AUG-99', '%d-%b-%y'), STR_TO_DATE('21-AUG-99', '%d-%b-%y')),
    -> ('H235', 'G879', 1267, STR_TO_DATE('05-SEP-99', '%d-%b-%y'), STR_TO_DATE('12-SEP-99', '%d-%b-%y')),
    -> ('H498', 'G230', 467, STR_TO_DATE('15-SEP-99', '%d-%b-%y'), STR_TO_DATE('19-SEP-99', '%d-%b-%y')),
    -> ('H498', 'G256', 345, STR_TO_DATE('30-NOV-99', '%d-%b-%y'), STR_TO_DATE('02-DEC-99', '%d-%b-%y')),
    -> ('H498', 'G467', 345, STR_TO_DATE('03-NOV-99', '%d-%b-%y'), STR_TO_DATE('05-NOV-99', '%d-%b-%y')),
    -> ('H193', 'G190', 1001, STR_TO_DATE('15-NOV-99', '%d-%b-%y'), STR_TO_DATE('19-NOV-99', '%d-%b-%y')),
    -> ('H193', 'G367', 1001, STR_TO_DATE('12-SEP-99', '%d-%b-%y'), STR_TO_DATE('14-SEP-99', '%d-%b-%y')),
    -> ('H193', 'G367', 1201, STR_TO_DATE('01-OCT-99', '%d-%b-%y'), STR_TO_DATE('06-OCT-99', '%d-%b-%y')),
    -> ('H437', 'G190', 223, STR_TO_DATE('04-OCT-99', '%d-%b-%y'), STR_TO_DATE('06-OCT-99', '%d-%b-%y')),
    -> ('H437', 'G879', 223, STR_TO_DATE('14-SEP-99', '%d-%b-%y'), STR_TO_DATE('17-SEP-99', '%d-%b-%y'));
ERROR 1062 (23000): Duplicate entry 'G367-H193' for key 'booking.PRIMARY'
mysql> INSERT booking
    -> values
    -> ^C
mysql> INSERT booking
    -> values
    -> ('H111', 'G256', 412, STR_TO_DATE('10-AUG-99', '%d-%b-%y'), STR_TO_DATE('15-AUG-99', '%d-%b-%y')),
    -> ('H111', 'G367', 412, STR_TO_DATE('18-AUG-99', '%d-%b-%y'), STR_TO_DATE('21-AUG-99', '%d-%b-%y')),
    -> ('H235', 'G879', 1267, STR_TO_DATE('05-SEP-99', '%d-%b-%y'), STR_TO_DATE('12-SEP-99', '%d-%b-%y')),
    -> ('H498', 'G230', 467, STR_TO_DATE('15-SEP-99', '%d-%b-%y'), STR_TO_DATE('19-SEP-99', '%d-%b-%y')),
    -> ('H498', 'G256', 345, STR_TO_DATE('30-NOV-99', '%d-%b-%y'), STR_TO_DATE('02-DEC-99', '%d-%b-%y')),
    -> ('H498', 'G467', 345, STR_TO_DATE('03-NOV-99', '%d-%b-%y'), STR_TO_DATE('05-NOV-99', '%d-%b-%y')),
    -> ('H193', 'G190', 1001, STR_TO_DATE('15-NOV-99', '%d-%b-%y'), STR_TO_DATE('19-NOV-99', '%d-%b-%y')),
    -> ('H193', 'G367', 1001, STR_TO_DATE('12-SEP-99', '%d-%b-%y'), STR_TO_DATE('14-SEP-99', '%d-%b-%y')),
    -> ('H193', 'G467', 1201, STR_TO_DATE('01-OCT-99', '%d-%b-%y'), STR_TO_DATE('06-OCT-99', '%d-%b-%y')),
    -> ('H437', 'G190', 223, STR_TO_DATE('04-OCT-99', '%d-%b-%y'), STR_TO_DATE('06-OCT-99', '%d-%b-%y')),
    -> ('H437', 'G879', 223, STR_TO_DATE('14-SEP-99', '%d-%b-%y'), STR_TO_DATE('17-SEP-99', '%d-%b-%y'));
Query OK, 11 rows affected (0.01 sec)
Records: 11  Duplicates: 0  Warnings: 0

mysql> select * from booking;
+----------+----------+---------+------------+------------+
| hotel_no | guest_no | room_no | date_from  | date_to    |
+----------+----------+---------+------------+------------+
| H193     | G190     |    1001 | 1999-11-15 | 1999-11-19 |
| H437     | G190     |     223 | 1999-10-04 | 1999-10-06 |
| H498     | G230     |     467 | 1999-09-15 | 1999-09-19 |
| H111     | G256     |     412 | 1999-08-10 | 1999-08-15 |
| H498     | G256     |     345 | 1999-11-30 | 1999-12-02 |
| H111     | G367     |     412 | 1999-08-18 | 1999-08-21 |
| H193     | G367     |    1001 | 1999-09-12 | 1999-09-14 |
| H193     | G467     |    1201 | 1999-10-01 | 1999-10-06 |
| H498     | G467     |     345 | 1999-11-03 | 1999-11-05 |
| H235     | G879     |    1267 | 1999-09-05 | 1999-09-12 |
| H437     | G879     |     223 | 1999-09-14 | 1999-09-17 |
+----------+----------+---------+------------+------------+
11 rows in set (0.00 sec)

mysql> select * from guest;
+----------+---------------+--------------+
| guest_no | name          | city         |
+----------+---------------+--------------+
| G190     | edward cane   | baltimore    |
| G230     | tom hancock   | philadelphia |
| G256     | adam wayne    | pittsburgh   |
| G367     | tara cummings | baltimore    |
| G467     | robert swift  | atlanta      |
| G879     | vanessa parry | pittsburgh   |
+----------+---------------+--------------+
6 rows in set (0.00 sec)

mysql> select * from hotel;
+----------+------------------+----------+
| hotel_no | name             | city     |
+----------+------------------+----------+
| H111     | empire hotel     | new york |
| H193     | devon hotel      | boston   |
| H235     | park place       | new york |
| H432     | brownstone hotel | toronto  |
| H437     | clairmont hotel  | boston   |
| H498     | james plaza      | toronto  |
+----------+------------------+----------+
6 rows in set (0.00 sec)

mysql> select * from room;
+---------+----------+------+-------+
| room_no | hotel_no | type | price |
+---------+----------+------+-------+
|     223 | H437     | N    |   155 |
|     257 | H437     | N    |   140 |
|     313 | H111     | S    |   145 |
|     345 | H498     | N    |   160 |
|     412 | H111     | N    |   145 |
|     467 | H498     | N    |   180 |
|     876 | H432     | S    |   124 |
|     898 | H432     | S    |   124 |
|    1001 | H193     | S    |   150 |
|    1201 | H193     | N    |   175 |
|    1267 | H235     | N    |   175 |
|    1289 | H235     | N    |   195 |
+---------+----------+------+-------+
12 rows in set (0.00 sec)

mysql> select * from hotel;
+----------+------------------+----------+
| hotel_no | name             | city     |
+----------+------------------+----------+
| H111     | empire hotel     | new york |
| H193     | devon hotel      | boston   |
| H235     | park place       | new york |
| H432     | brownstone hotel | toronto  |
| H437     | clairmont hotel  | boston   |
| H498     | james plaza      | toronto  |
+----------+------------------+----------+
6 rows in set (0.00 sec)

mysql> select * from hotel where city="new york";
+----------+--------------+----------+
| hotel_no | name         | city     |
+----------+--------------+----------+
| H111     | empire hotel | new york |
| H235     | park place   | new york |
+----------+--------------+----------+
2 rows in set (0.01 sec)

mysql> select name, city from guest order by city;
+---------------+--------------+
| name          | city         |
+---------------+--------------+
| robert swift  | atlanta      |
| edward cane   | baltimore    |
| tara cummings | baltimore    |
| tom hancock   | philadelphia |
| adam wayne    | pittsburgh   |
| vanessa parry | pittsburgh   |
+---------------+--------------+
6 rows in set (0.00 sec)

mysql> select * from room order by price;
+---------+----------+------+-------+
| room_no | hotel_no | type | price |
+---------+----------+------+-------+
|     876 | H432     | S    |   124 |
|     898 | H432     | S    |   124 |
|     257 | H437     | N    |   140 |
|     313 | H111     | S    |   145 |
|     412 | H111     | N    |   145 |
|    1001 | H193     | S    |   150 |
|     223 | H437     | N    |   155 |
|     345 | H498     | N    |   160 |
|    1201 | H193     | N    |   175 |
|    1267 | H235     | N    |   175 |
|     467 | H498     | N    |   180 |
|    1289 | H235     | N    |   195 |
+---------+----------+------+-------+
12 rows in set (0.00 sec)

mysql> select * from room where type='N' order by price;
+---------+----------+------+-------+
| room_no | hotel_no | type | price |
+---------+----------+------+-------+
|     257 | H437     | N    |   140 |
|     412 | H111     | N    |   145 |
|     223 | H437     | N    |   155 |
|     345 | H498     | N    |   160 |
|    1201 | H193     | N    |   175 |
|    1267 | H235     | N    |   175 |
|     467 | H498     | N    |   180 |
|    1289 | H235     | N    |   195 |
+---------+----------+------+-------+
8 rows in set (0.00 sec)

mysql> select count(hotel_no) from hotel;
+-----------------+
| count(hotel_no) |
+-----------------+
|               6 |
+-----------------+
1 row in set (0.01 sec)

mysql> select distinct city from guests;
ERROR 1146 (42S02): Table 'assignement_2.guests' doesn't exist
mysql> select distinct city from guest;
+--------------+
| city         |
+--------------+
| baltimore    |
| philadelphia |
| pittsburgh   |
| atlanta      |
+--------------+
4 rows in set (0.01 sec)

mysql> select avg(price) from room;
+--------------------+
| avg(price)         |
+--------------------+
| 155.66666666666666 |
+--------------------+
1 row in set (0.00 sec)

mysql> select hotel.name, room_no, type from
    -> room inner join
    -> hotel on room.hostel_no=hotel.hotel_no;
ERROR 1054 (42S22): Unknown column 'room.hostel_no' in 'on clause'
mysql> select hotel(name), room_no, type
    -> from room
    -> inner join hotel
    -> on room.hotel_no = hotel.hotel_no;
ERROR 1305 (42000): FUNCTION assignement_2.hotel does not exist
mysql> select hotel.name, room_no, type
    -> from room
    -> inner join hotel
    -> on room.hotel_no = hotel.hotel_no;
+------------------+---------+------+
| name             | room_no | type |
+------------------+---------+------+
| empire hotel     |     313 | S    |
| empire hotel     |     412 | N    |
| devon hotel      |    1001 | S    |
| devon hotel      |    1201 | N    |
| park place       |    1267 | N    |
| park place       |    1289 | N    |
| brownstone hotel |     876 | S    |
| brownstone hotel |     898 | S    |
| clairmont hotel  |     223 | N    |
| clairmont hotel  |     257 | N    |
| james plaza      |     345 | N    |
| james plaza      |     467 | N    |
+------------------+---------+------+
12 rows in set (0.00 sec)

mysql> select hotel.name, room_no, date_from, date_to
    -> from booking
    -> inner join hotel
    -> on booking.hotel_no = hotel.hotel_no
    -> where hotel.city="new york";
+--------------+---------+------------+------------+
| name         | room_no | date_from  | date_to    |
+--------------+---------+------------+------------+
| empire hotel |     412 | 1999-08-10 | 1999-08-15 |
| empire hotel |     412 | 1999-08-18 | 1999-08-21 |
| park place   |    1267 | 1999-09-05 | 1999-09-12 |
+--------------+---------+------------+------------+
3 rows in set (0.00 sec)

mysql> select hotel.name, room_no, FORMAT(date_from, 'dd-MMM-yy') AS booking_from, FORMAT(date_to, 'dd-MMM-yy') AS booking_to
    -> from booking
    -> inner join hotel
    -> on booking.hotel_no = hotel.hotel_no
    -> where hotel.city="new york";
+--------------+---------+--------------+------------+
| name         | room_no | booking_from | booking_to |
+--------------+---------+--------------+------------+
| empire hotel |     412 | 19,990,810   | 19,990,815 |
| empire hotel |     412 | 19,990,818   | 19,990,821 |
| park place   |    1267 | 19,990,905   | 19,990,912 |
+--------------+---------+--------------+------------+
3 rows in set, 6 warnings (0.00 sec)

mysql> select hotel.name, room_no, FORMAT(getdate(date_from), 'dd-MMM-yy') AS booking_from, FORMAT(getdate(date_to), 'dd-MMM-yy') AS booking_to
    -> from booking
    -> inner join hotel
    -> on booking.hotel_no = hotel.hotel_no
    -> where hotel.city="new york";
ERROR 1305 (42000): FUNCTION assignement_2.getdate does not exist
mysql> select count(*) from booking where date_from like '%SEP%'
    -> ;
+----------+
| count(*) |
+----------+
|        0 |
+----------+
1 row in set (0.01 sec)

mysql> select hotel.name, room_no, FORMAT(getdate(), 'dd-MMM-yy') AS booking_from, FORMAT(getdate(), 'dd-MMM-yy') AS booking_to
    -> from booking
    -> inner join hotel
    -> on booking.hotel_no = hotel.hotel_no
    ->
    -> where hotel.city="new york";
ERROR 1305 (42000): FUNCTION assignement_2.getdate does not exist
mysql> SELECT FORMAT (getdate(), 'dd-MM-yy') as date
    -> ;
ERROR 1305 (42000): FUNCTION assignement_2.getdate does not exist
mysql> select hotel.name, room_no, DATE_FORMAT(date_from, '%D-%b-%Y') AS booking_from, DATE_FORMAT(date_to, '%D-%b-%Y') AS booking_to
    -> from booking
    -> inner join hotel
    -> on booking.hotel_no = hotel.hotel_no
    -> where hotel.city="new york";
+--------------+---------+---------------+---------------+
| name         | room_no | booking_from  | booking_to    |
+--------------+---------+---------------+---------------+
| empire hotel |     412 | 10th-Aug-1999 | 15th-Aug-1999 |
| empire hotel |     412 | 18th-Aug-1999 | 21st-Aug-1999 |
| park place   |    1267 | 5th-Sep-1999  | 12th-Sep-1999 |
+--------------+---------+---------------+---------------+
3 rows in set (0.00 sec)

mysql> select count(*) from booking where DATE_FORMAT(date_from, '%D-%b-%Y') like '%Sep%';
+----------+
| count(*) |
+----------+
|        4 |
+----------+
1 row in set (0.00 sec)

mysql> SELECT guest.name, guest.city
    -> from booking
    -> inner join guest
    -> on booking.guest_no = guest.guest_no
    -> where guest.city = "new york" and DATE_FORMAT(date_from, '%D-%b-%Y') like '%Aug%';
Empty set (0.00 sec)

mysql> SELECT guest.name, guest.city
    -> from booking
    -> inner join guest
    -> on booking.guest_no = guest.guest_no
    -> inner join hotel
    -> not booking.hotel_no = hotel.hotel_no
    -> ^C
mysql> SELECT guest.name, guest.city
    -> from booking
    -> inner join guest
    -> on booking.guest_no = guest.guest_no
    -> inner join hotel
    -> on booking.hotel_no = hotel.hotel_noo
    -> where hotel.city = "new york" and DATE_FORMAT(date_from, '%D-%b-%Y') like '%Aug%';
ERROR 1054 (42S22): Unknown column 'hotel.hotel_noo' in 'on clause'
mysql> SELECT guest.name, guest.city
    -> from booking
    -> inner join guest
    -> on booking.guest_no = guest.guest_no
    -> inner join hotel
    -> on booking.hotel_no = hotel.hotel_no
    -> where hotel.city = "new york" and DATE_FORMAT(date_from, '%D-%b-%Y') like '%Aug%';
+---------------+------------+
| name          | city       |
+---------------+------------+
| adam wayne    | pittsburgh |
| tara cummings | baltimore  |
+---------------+------------+
2 rows in set (0.00 sec)

mysql> select hotel.name, hotel.city
    -> from room
    -> inner join hotel
    -> on room.hotel_no = hotel.hotel_no
    -> where room.price = (select max(price) from room);
+------------+----------+
| name       | city     |
+------------+----------+
| park place | new york |
+------------+----------+
1 row in set (0.00 sec)

mysql> select hotel.name, room_no, hotel.city, price
    -> from room
    -> inner join hotel
    -> on room.hotel_no = hotel.hotel_no
    -> where price<(select min(price) form room inner join hotel on room.hotel_no=hotel.hotel_no where hotel.city="boston")
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'room inner join hotel on room.hotel_no=hotel.hotel_no where hotel.city="boston")' at line 5
mysql> select hotel.name, room_no, hotel.city, price
    -> from room
    -> inner join hotel
    -> on room.hotel_no = hotel.hotel_no
    -> where price<(select min(room.price) form room inner join hotel on room.hotel_no = hotel.hotel_no where hotel.city="boston")
    -> ;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'room inner join hotel on room.hotel_no = hotel.hotel_no where hotel.city="boston' at line 5
mysql> SELECT hotel.name, room.room_no, hotel.city, room.price
    -> FROM room
    -> INNER JOIN hotel
    -> ON room.hotel_no = hotel.hotel_no
    -> WHERE room.price < (
    ->     SELECT MIN(room.price)
    ->     FROM room
    ->     INNER JOIN hotel
    ->     ON room.hotel_no = hotel.hotel_no
    ->     WHERE hotel.city = 'boston'
    -> );
+------------------+---------+---------+-------+
| name             | room_no | city    | price |
+------------------+---------+---------+-------+
| brownstone hotel |     876 | toronto |   124 |
| brownstone hotel |     898 | toronto |   124 |
+------------------+---------+---------+-------+
2 rows in set (0.00 sec)

mysql>
mysql> select avg(price)
    -> form room
    -> inner join hotel
    -> ON room.hotel_no = hotel.hotel_no
    -> group by hotel.city;
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'room
inner join hotel
ON room.hotel_no = hotel.hotel_no
group by hotel.city' at line 2
mysql> SELECT AVG(room.price)
    -> FROM room
    -> INNER JOIN hotel
    -> ON room.hotel_no = hotel.hotel_no
    -> GROUP BY hotel.city;
+-----------------+
| AVG(room.price) |
+-----------------+
|             165 |
|             155 |
|             147 |
+-----------------+
3 rows in set (0.00 sec)

mysql> select hotel.name, room_no
    -> from room
    -> inner join hotel
    -> on room.hotel_no = hotel.hotel_no
    -> where room_no not in (select distinct room_no form booking);
ERROR 1064 (42000): You have an error in your SQL syntax; check the manual that corresponds to your MySQL server version for the right syntax to use near 'booking)' at line 5
mysql> SELECT hotel.name, room.room_no
    -> FROM room
    -> INNER JOIN hotel
    -> ON room.hotel_no = hotel.hotel_no
    -> WHERE room.room_no NOT IN (
    ->     SELECT DISTINCT room_no
    ->     FROM booking
    -> );
+------------------+---------+
| name             | room_no |
+------------------+---------+
| empire hotel     |     313 |
| park place       |    1289 |
| brownstone hotel |     876 |
| brownstone hotel |     898 |
| clairmont hotel  |     257 |
+------------------+---------+
5 rows in set (0.00 sec)
