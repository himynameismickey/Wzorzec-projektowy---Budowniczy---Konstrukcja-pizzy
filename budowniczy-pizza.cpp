#include <iostream>
#include <string>
using namespace std;

class Pizza
{
    private:
        string ciasto;
        string sos;
        string dodatek;

    public:
        void setCiasto (string c)
        {
            ciasto = c;
        }

        void setSos (string s)
        {
            sos = s;
        }

        void setDodatek (string d)
        {
            dodatek = d;
        }

        void show ()
        {
            cout << "Pizza:\n" << "Ciasto = " << ciasto << "\n" << "Sos = " << sos << "\n" << "Dodatek = " << dodatek << "\n";
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
        BudowniczyPizzaPepperoni () : BudowniczyPizza ()
        {
        }

        void budujCiasto ()
        {
            pizza -> setCiasto ("cienkie");
        }

        void budujSos ()
        {
            pizza -> setSos ("pomidorowy");
        }

        void budujDodatek ()
        {
            pizza -> setDodatek ("pepperoni");
        }
};

class BudowniczyPizzaSerowa : public BudowniczyPizza
{
    public:
        BudowniczyPizzaSerowa () : BudowniczyPizza ()
        {
        }

        void budujCiasto ()
        {
            pizza -> setCiasto ("grube");
        }

        void budujSos ()
        {
            pizza -> setSos ("śmietanowy");
        }

        void budujDodatek()
        {
            pizza -> setDodatek ("dodatkowy ser");
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
    pizza2.show();

    delete szef;
    delete budowniczy1;
    delete budowniczy2;

    return 0;
}
