#include "CoffeeMachine.h"

// coffeee 1 unit = 10
// water 1 unit = 5
// milk 1 unit = 7

int main()
{
    bool run = true;
    cout << "Hello from the coffee Machine :-) \n";

    CoffeeMachine cm = CoffeeMachine(10, 10, 10);

    while (run)
    {
        cm.printOptions();
        int choice;
        cout << "\nChoose from the following Inputs : ";
        cin >> choice;

        if (choice == 10)
        {
            cout << "Thank You for using the Coffee Machine ;-)\n Turning Off...\n";
            run = false;
        }
        else if (choice >= 1 && choice <= 9)
        {
            cm.runOptions(choice);
        }
        else
        {
            cout << "Please Enter a valid input";
        }
    }
}