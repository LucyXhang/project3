#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <cmath>

using namespace std;

class State
{
    public:
        State();
        State(string, double, long long int);
        
        double findPercentage();
        string getName();
        double getEnergy();
        long long int getSize();
        double getPercentage();
        void setPercentage(double);
        
    private:
        string m_name;
        double m_energy;
        long long int m_size;
        double m_percentage;
};

State::State(){
    m_name = "";
    m_energy = 0.0;
    m_size = 0;
    m_percentage = 0.0;
}

State::State(string name, double energy, long long int size)
{
    m_name = name;
    m_energy = energy * 1000000000000;
    m_size = size;
}

string State::getName()
{
    return m_name;
}

double State::getEnergy()
{
    return m_energy;
}

long long int State::getSize()
{
    return m_size;
}

double State::getPercentage()
{
    return m_percentage;
}

void State::setPercentage(double percentage)
{
    m_percentage = percentage;
}

double State::findPercentage()
{
    // calculate panel out per year in BTUs
    // assume an 18 square foot panel produces 600 kwh per year
    double panelBTU = 600 * 3412;
    
    // calculate the panels need to produce required electricity
    double panelsNeeded = m_energy * 365 / panelBTU;
    
    // deterine percentage of states' land mass needed
    // assume 18 squaer foot panels
    double percentage = (panelsNeeded / (m_size / 18)) * 100;
    m_percentage = percentage;
    return percentage;
}

void printPercentage (list <State> a)
{
    cout << endl << "State \t\t" << "Percentage of land used" << endl << endl;
    for (auto it = a.begin(); it != a.end(); it++)
    {
        cout << std::left << std::setw(18) << (*it).getName() << "\t" << (*it).getPercentage() << endl << endl;
    }
}

void add (list<State> &a, State &b)
{
    list<State>::iterator it;
    list<State>::iterator previous;
    
    if (a.empty() || ((a.front()).getPercentage() > b.getPercentage()))
    {
        // add to start on list
        a.push_front(b);
    }
    else
    {
        // find the correct location
        previous = a.begin();
        for (auto it = a.begin(); it != a.end(); ++it)
        {
            if ((*it).getPercentage() > b.getPercentage())
            {
                break;
            }
            else
            {
                previous = it;
            }
        }
        // add to correct position
        a.insert(++previous,b);
    }
}

int main()
{
    list<State> states;
    double percentage;
    
    State tx("Texas", 13480.8, 7487580672000);
    percentage = tx.findPercentage();
    add(states, tx);
    
    State ca("California", 6922.8, 4563554688000);
    ca.findPercentage();
    add(states, ca);
    
    State la("Louisiana", 4200.4, 1445216256000);
    la.findPercentage();
    add(states, la);
    
    State fd("Florida", 4003.1, 1806265792000);
    fd.findPercentage();
    add(states, fd);
    
    State il("Illinois", 3612.9, 1614549657600);
    il.findPercentage();
    add(states, il);
    
    State pl("Pennsylvania", 3413.0, 1283967590400);
    pl.findPercentage();
    add(states, pl);
    
    State oi("Ohio", 3404.5, 1249649280000);
    oi.findPercentage();
    add(states,oi);
    
    State ny("New York", 3354.2, 1520933990400);
    ny.findPercentage();
    add(states,ny);
    
    State ga("Georgia", 2727.6, 1656673920000);
    ga.findPercentage();
    add(states,ga);
    
    State mg("Michigan", 2610.6, 2696287334400);
    mg.findPercentage();
    add(states,mg);
    
    cout << endl;
    printPercentage (states);
    
    return 0;
}