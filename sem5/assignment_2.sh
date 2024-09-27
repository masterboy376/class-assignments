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
