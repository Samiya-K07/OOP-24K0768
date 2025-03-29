//Samiya Khan
//24K-0768

#include<iostream>
#include<string>
using namespace std;

class Ticket{
protected:
    int ticketID;
    string passengerName;
    double price;
    string date;
    string destination;

public:
    Ticket(int id, string name, double p, string d, string dest) : ticketID(id), passengerName(name), price(p), date(d), destination(dest) {}
    
    virtual void reserve() 
    {
        cout << "Ticket has been reserved for " << passengerName << " on " << date << " to " << destination << "!!" << endl;
    }
    
    virtual void cancel() 
    {
        cout << "Ticket has been cancelled for " << passengerName << "!!" << endl;
    }
    
    virtual void displayTicketInfo() const 
    {
        cout << "Ticket ID: " << ticketID << "\nPassenger Name: " << passengerName << "\nPrice: " << price << "\nDate: " << date << "\nDestination: " << destination << endl;
    }
    
};

class FlightTicket : public Ticket{
private:
    string airlineName;
    string flightNumber;
    string seatClass;

public:
    FlightTicket(int id, string name, double p, string d, string dest, string airline, string num, string seat) : Ticket(id, name, p, d, dest), airlineName(airline), flightNumber(num), seatClass(seat) {}
    
    void displayTicketInfo() 
    {
        Ticket::displayTicketInfo();
        cout << "Airline: " << airlineName << "\nFlight Number: " << flightNumber << "\nSeat Class: " << seatClass << endl;
    }
};

class TrainTicket : public Ticket{
private:
    string trainNumber;
    string coachType;
    string departureTime;

public:
    TrainTicket(int id, string name, double p, string d, string dest, string num, string coach, string time) : Ticket(id, name, p, d, dest), trainNumber(num), coachType(coach), departureTime(time) {}
    
    void reserve() 
    {
        cout << "Train ticket has been successfully reserved for " << passengerName << "!! Seat has been auto assigned!!" << endl;
    }
};

class BusTicket : public Ticket{
private:
    string busCompany;
    string seatNumber;

public:
    BusTicket(int id, string name, double p, string d, string dest, string company, string num) : Ticket(id, name, p, d, dest), busCompany(company), seatNumber(num) {}
    
    void cancel() 
    {
        cout << "Bus ticket has been cancelled for " << passengerName << "!! Refund is available!!" << endl;
    }
};

class ConcertTicket : public Ticket{
private:
    string artistName;
    string venue;
    string seatType;

public:
    ConcertTicket(int id, string name, double p, string d, string dest, string artist, string v, string type) : Ticket(id, name, p, d, dest), artistName(artist), venue(v), seatType(type) {}
    
    void displayTicketInfo() 
    {
        Ticket::displayTicketInfo();
        cout << "Artist: " << artistName << "\nVenue: " << venue << "\nSeat Type: " << seatType << endl;
    }
};

int main() {
    
    FlightTicket flightticket1(101, "Samiya", 250, "2025-02-04", "Karachi", "PIA", "5715", "Luxury");
    TrainTicket trainticket1(444, "Hamza", 154, "2025-06-11", "Islamabad", "Karakoram", "Sleeper", "10:00 AM");
    BusTicket busticket1(767, "Abeer", 200, "2025-06-27", "Lahore", "Red Fort", "A02");
    ConcertTicket concertticket1(686, "Hania", 350, "2025-10-09", "Manakin", "Rock Singer", "Fast University", "VIP");

    flightticket1.displayTicketInfo();
    trainticket1.reserve();
    busticket1.cancel();
    concertticket1.displayTicketInfo();
    
    return 0;
}