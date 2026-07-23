CREATE DATABASE AirlineSystem;

USE AirlineSystem;

CREATE TABLE Users (
    UserID INT PRIMARY KEY AUTO_INCREMENT,
    Username VARCHAR(50) UNIQUE NOT NULL,
    Password VARCHAR(100) NOT NULL
);

CREATE TABLE Flights (
    FlightID INT PRIMARY KEY AUTO_INCREMENT,
    Destination VARCHAR(50),
    DepartureTime VARCHAR(20),
    TotalSeats INT,
    AvailableSeats INT

INSERT INTO Flights
(Destination, DepartureTime, TotalSeats, AvailableSeats)
VALUES
('London', '1 PM', 50, 15),
('New york', '4 PM', 50, 13),
('Manchester', '5 PM', 50, 7);

CREATE TABLE Reservations (
    ReservationID INT PRIMARY KEY AUTO_INCREMENT,
    UserID INT,
    FlightID INT,
    SeatNumber INT,

    FOREIGN KEY (UserID)
        REFERENCES Users(UserID),

    FOREIGN KEY (FlightID)
        REFERENCES Flights(FlightID)
);

CREATE TABLE Payments (
    PaymentID INT PRIMARY KEY AUTO_INCREMENT,
    ReservationID INT,
    Amount DECIMAL(10,2),
    CardNumber VARCHAR(16),
    PaymentStatus VARCHAR(20),

    FOREIGN KEY (ReservationID)
        REFERENCES Reservations(ReservationID)
);

INSERT INTO Users (Username, Password)
VALUES ('Alice', '12345');

SELECT *
FROM Users
WHERE Username='Alice'
AND Password='12345';

SELECT *
FROM Flights;

SELECT Destination,
       AvailableSeats
FROM Flights
WHERE FlightID = 1;

INSERT INTO Reservations
(UserID, FlightID, SeatNumber)
VALUES
(1, 2, 10);

UPDATE Flights
SET AvailableSeats = AvailableSeats - 1
WHERE FlightID = 2;

INSERT INTO Payments
(ReservationID,
 Amount,
 CardNumber,
 PaymentStatus)

VALUES
(1,
500.00,
'1234567812345678',
'Successful');

SELECT
Reservations.ReservationID,
Users.Username,
Flights.Destination,
Flights.DepartureTime,
Reservations.SeatNumber
FROM Reservations
JOIN Users
ON Reservations.UserID = Users.UserID
JOIN Flights
ON Reservations.FlightID = Flights.FlightID;

DELETE FROM Reservations
WHERE ReservationID = 1;

UPDATE Flights
SET AvailableSeats = AvailableSeats + 1
WHERE FlightID = 2;

SELECT *
FROM Payments;
