#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Skladnik 
{
    public:
        string nazwa;

        Skladnik (string n) : nazwa (n) {}
};

class Pizza 
{
    private:
        string ciasto;
        string sos;
        vector<Skladnik> dodatki;

    public:  
        void setCiasto (string c) 
        {
            ciasto = c;
        }

    void setSos (string s)
    {
        sos = s;
    }

    void dodajDodatek (const Skladnik& skladnik) 
    {
        dodatki.push_back (skladnik);
    }

    void show () 
    {
        cout << "Pizza:\n" << "Ciasto = " << ciasto << "\n" << "Sos = " << sos << "\n";
        cout << "Dodatki:\n";
        
        for (const auto& skladnik : dodatki) 
        {
            cout << "- " << skladnik.nazwa << "\n";
        }
    }
};

class BudowniczyPizza 
{
    protected:
        Pizza* pizza;

    public:
        void nowaPizza () 
        {
            pizza = new Pizza ();
        }

        virtual ~BudowniczyPizza () {}

        Pizza getPizza () 
        {
            return *pizza;
        }

        virtual void budujCiasto () = 0;
        virtual void budujSos () = 0;
        virtual void budujDodatek () = 0;
};

class BudowniczyPizzaPepperoni : public BudowniczyPizza 
{
    public:
        void budujCiasto () override 
        {
            pizza -> setCiasto ("cienkie");
        }

    void budujSos () override 
    {
        pizza -> setSos ("pomidorowy");
    }

    void budujDodatek () override 
    {
        pizza -> dodajDodatek (Skladnik ("pepperoni"));
    }
};

class BudowniczyPizzaSerowa : public BudowniczyPizza 
{
    public:
        void budujCiasto () override 
        {
            pizza -> setCiasto ("grube");
        }

    void budujSos () override 
    {
        pizza -> setSos ("śmietanowy");
    }

    void budujDodatek () override 
    {
        pizza -> dodajDodatek (Skladnik ("dodatkowy ser"));
    }
};

class Kierownik 
{
    private:
        BudowniczyPizza* budowniczy;

    public:
        void setBudowniczy (BudowniczyPizza* b) 
        {
            budowniczy = b;
        }

        Pizza getPizza () 
        {
            return budowniczy -> getPizza ();
        }

        void tworzPizza () 
        {
            budowniczy -> nowaPizza ();
            budowniczy -> budujCiasto ();
            budowniczy -> budujSos ();
            budowniczy -> budujDodatek ();
        }
};

int main () 
{
    Kierownik* szef = new Kierownik ();

    BudowniczyPizza* budowniczy1 = new BudowniczyPizzaPepperoni ();
    BudowniczyPizza* budowniczy2 = new BudowniczyPizzaSerowa ();

    szef -> setBudowniczy (budowniczy1);
    szef -> tworzPizza ();
    Pizza pizza1 = szef -> getPizza ();

    szef -> setBudowniczy (budowniczy2);
    szef -> tworzPizza ();
    Pizza pizza2 = szef -> getPizza ();

    cout << "PIZZA 1\n";
    pizza1.show ();
    cout << "\n\nPIZZA 2\n";
    pizza2.show ();

    delete szef;
    delete budowniczy1;
    delete budowniczy2;

    return 0;
}
