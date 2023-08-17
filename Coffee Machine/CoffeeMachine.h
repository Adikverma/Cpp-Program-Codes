#include <iostream>
using namespace std;

class Storage
{
    int milkQty = 0;
    int waterQty = 0;
    int coffeeBeansQty = 0;

public:
    Storage(){};
    void setStorage(int milk, int water, int coffeeBeans)
    {
        if (milk > 10 || water > 10 || coffeeBeans > 10)
        {
            cout << "\n Sorry, Cannot fill above limit\n";
        }
        else
        {
            this->milkQty = milk;
            this->waterQty = water;
            this->coffeeBeansQty = coffeeBeans;
        }
    }
    void fillMilk(int milk)
    {
        if (milk + this->milkQty > 10)
        {
            cout << "\n Sorry, Cannot fill above limit\n";
        }
        else
        {
            milkQty += milk;
        }
    }
    void fillWater(int water)
    {
        if (water + this->waterQty > 10)
        {
            cout << "\n Sorry, Cannot fill above limit\n";
        }
        else
        {
            waterQty += water;
        }
    }
    void fillCoffeeBeans(int coffeeBeans)
    {
        if (coffeeBeans + this->coffeeBeansQty > 10)
        {
            cout << "\n Sorry, Cannot fill above limit\n";
        }
        else
        {
            coffeeBeansQty += coffeeBeans;
        }
    }
    int getWater(void)
    {
        return this->waterQty;
    }
    int getMilk(void)
    {
        return this->milkQty;
    }
    int getCoffeeBeans(void)
    {
        return this->coffeeBeansQty;
    }
};

class Ingridient
{
    int cost = 0;

public:
    Ingridient(){};
    Ingridient(int x)
    {
        cost = x;
    }
    int getCost()
    {
        return cost;
    }
    void setCost(int newCost)
    {
        cost = newCost;
    }
};

class CoffeeMachine
{
    // local data
    int waterQty;
    int milkQty;
    int coffeeBeansQty;

    // storage object
    Storage strg;

public:
    CoffeeMachine() {}
    CoffeeMachine(int milk, int water, int coffeeBeans)
    {
        this->strg.setStorage(milk, water, coffeeBeans);
    }
    void printOptions()
    {
        this->waterQty = strg.getWater();
        this->milkQty = strg.getMilk();
        this->coffeeBeansQty = strg.getCoffeeBeans();

        cout << "\nChoose from the given inputs : \n";
        cout << "1. Serve Cappucino\n";
        cout << "2. Serve Latte\n";
        cout << "3. Serve Espresso\n";
        cout << "4. Serve Milk\n";
        cout << "5. Serve Water\n";
        cout << "6. Fill Coffee Beans\n";
        cout << "7. Fill Milk\n";
        cout << "8. Fill Water\n";
        cout << "9. Display current ingredient Quantity\n";
        cout << "10. Turn Off\n";
    }

    // handeling user input
    void runOptions(int choice)
    {
        switch (choice)
        {
        case 1:
        {
            this->serveCappuccino();
            break;
        }
        case 2:
        {
            this->serveLatte();
            break;
        }
        case 3:
        {
            this->serveEspresso();
            break;
        }
        case 4:
        {
            this->serveMilk();
            break;
        }
        case 5:
        {
            this->serveWater();
            break;
        }
        case 6:
        {
            this->fillCoffeeBeans();
            break;
        }
        case 7:
        {
            this->fillMilk();
            break;
        }
        case 8:
        {
            this->fillWater();
            break;
        }
        case 9:
        {
            this->displayIngredients();
            break;
        }
        }
    }

    // combined function to serve
    void serveThis(int coffeeBeans, int milkQty, int waterQty, string choice)
    {
        if (this->coffeeBeansQty < coffeeBeans || this->waterQty < waterQty || this->milkQty < milkQty)
        {
            cout << "Sorry but one or more ingredients are missing  for making of :" << choice << "\n";
            if (this->coffeeBeansQty < coffeeBeans)
                coffeeBeans = coffeeBeans - this->coffeeBeansQty;
            else
                coffeeBeans = 0;
            if (this->waterQty < waterQty)
                waterQty = waterQty - this->waterQty;
            else
                waterQty = 0;
            if (this->milkQty < milkQty)
                milkQty = milkQty - this->milkQty;
            else
                milkQty = 0;
            cout << coffeeBeans << " Coffee Beans units needed\n";
            cout << waterQty << " Water units needed\n";
            cout << milkQty << " Milk units needed\n";
        }
        else
        {
            this->coffeeBeansQty -= coffeeBeans;
            this->milkQty -= milkQty;
            this->waterQty -= waterQty;
            this->strg.setStorage(this->milkQty, this->waterQty, this->coffeeBeansQty);
            int amount = ;
            cout << choice << " has been served successfully. Please pay amount of : " << amount;
        }
    }

    // serving
    void serveCappuccino()
    {
        serveThis(2, 2, 1, "Cappuccino");
    }
    void serveLatte()
    {
        serveThis(2, 3, 1, "Latte");
    }
    void serveEspresso()
    {
        serveThis(3, 0, 1, "Espresso");
    }
    void serveMilk()
    {
        serveThis(0, 3, 0, "Milk");
    }
    void serveWater()
    {
        serveThis(0, 0, 3, "Water");
    }

    // filling
    void fillCoffeeBeans()
    {
        cout << "Enter the Coffe Beans Qty to fill: ";
        int coffeeBeans;
        cin >> coffeeBeans;
        this->strg.fillCoffeeBeans(coffeeBeans);
    }
    void fillMilk()
    {
        cout << "Enter the Milk Qty to fill: ";
        int milk;
        cin >> milk;
        this->strg.fillMilk(milk);
    }
    void fillWater()
    {
        cout << "Enter the Water Qty to fill: ";
        int water;
        cin >> water;
        this->strg.fillWater(water);
    }

    // displaying
    void displayIngredients()
    {
        cout << "The available ingredients are : \n";
        cout << "Coffee Beans : " << this->coffeeBeansQty << '\n';
        cout << "Water : " << this->waterQty << '\n';
        cout << "Milk : " << this->milkQty << '\n';
    }
};