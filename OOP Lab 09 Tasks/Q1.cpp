#include <iostream>
using namespace std;

class Client
{
protected:
    string fullName;
    string clientID;

public:
    Client(string name, string id) : fullName(name), clientID(id) {}

    virtual void showTreatmentPlan() const = 0;
    virtual double computeBill() const = 0;

    virtual ~Client() {}
};

class AdmittedClient : public Client
{
public:
    AdmittedClient(string name, string id) : Client(name, id) {}

    void showTreatmentPlan() const override
    {
        cout << "Treatment Details for Admitted Client: " << fullName << " (Client ID: " << clientID << ")\n";
        cout << " - Hospital room provided\n - Regular doctor rounds\n - Required medical tests\n";
    }

    double computeBill() const override
    {
        double roomFee = 2500;
        double careFee = 1800;
        double testFee = 1200;
        return roomFee + careFee + testFee;
    }
};

class VisitingClient : public Client
{
public:
    VisitingClient(string name, string id) : Client(name, id) {}

    void showTreatmentPlan() const override
    {
        cout << "Treatment Overview for Visiting Client: " << fullName << " (Client ID: " << clientID << ")\n";
        cout << " - Doctor consultation\n - Medicines prescribed\n";
    }

    double computeBill() const override
    {
        double consultationCharge = 600;
        double prescriptionCost = 350;
        return consultationCharge + prescriptionCost;
    }
};

int main()
{
    const int NUM_CLIENTS = 2;
    Client *clients[NUM_CLIENTS];

    clients[0] = new AdmittedClient("Ali Khan", "AC1010");
    clients[1] = new VisitingClient("Sara Ahmed", "VC2020");

    for (int i = 0; i < NUM_CLIENTS; ++i)
    {
        clients[i]->showTreatmentPlan();
        cout << "Total Billing Amount: $" << clients[i]->computeBill() << "\n\n";
    }

    for (int i = 0; i < NUM_CLIENTS; ++i)
    {
        delete clients[i];
    }

    return 0;
}
