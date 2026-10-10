#include <iostream>
#include <string>

using namespace std;

struct Stop {
    string name;
    int minutesFromDepot;
    Stop* next;
};

class BusRoute {
    private:
        Stop* head;

    public:
        BusRoute() {
            head = nullptr;
        }

    void addStop(string name, int minutes) {
        Stop* newStop = new Stop;
        newStop->name = name;
        newStop->minutesFromDepot = minutes;
        newStop->next = nullptr;

        // (a) Add a stop to the end of the linked list

        if (head == nullptr) {
            head = newStop;
        } else {
            Stop* current = head;

            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newStop;
        }
    }  

    void displayRoute() {

        // (b) Display all stops

        Stop* current = head;

        while (current != nullptr) {
            cout << current->name << " ("
                 << current->minutesFromDepot
                 << " min) -> ";

            current = current->next;
        }
        cout << "END" << endl;
    }

    bool removeStop(string name) {

        // (c) Remove the first stop with the matching name

        if (head->name == name) {
            Stop* temp = head;
            head = head->next;
            delete temp;
            return true;
        }

    // Find the node before the matching node

        Stop* current = head;

        while (current->next != nullptr &&
               current->next->name != name) {
            current = current->next;
               }

        if (current->next == nullptr) {
            return false;
        }

        // Remove the matcjing node

        Stop* temp = current->next;
        current->next = temp->next;
        delete temp;

        return true;
    }

    ~BusRoute() {

        // (d) Destructor: free all dynamically allocated nodes

        Stop* current = head;

        while (current != nullptr) {
            Stop* temp = current;
            current = current->next;
            delete temp;
        }
        head = nullptr;
    }
};
int main() {
    BusRoute route;
    route.addStop("Ellis Park", 5);
    route.addStop("Library Gardens", 12);
    route.addStop("Thokoza Park", 25);
    route.addStop("Dobsonville", 38);

    route.displayRoute();

    if (route.removeStop("LibraryGardens"))
        cout << "Braamfontein not found" << endl;

    route.displayRoute();
    return 0;
}