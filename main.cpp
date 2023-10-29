#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class State
{
    public:
        State();
        State(string, double, long long int);
        
        double findPercentage();
        string getName() const;
        double getPercentage() const;
        
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
    m_percentage = findPercentage();
}

double State::findPercentage()
{
    double panelsNeeded = ceil ((m_energy * 51.0));
    double panelArea = panelsNeeded * 18.0;
    m_percentage = ceil((panelArea / m_size) * 100.0);
    return m_percentage;
}

string State::getName() const
{
    return m_name;
}

double State::getPercentage() const
{
    return m_percentage;
}

bool compareStates(const State& a, const State& b)
{
    return a.getPercentage() < b.getPercentage();
}

void customSort(list<State>& states)
{
    for(auto it1 = states.begin(); it1 != states.end(); ++it1)
    {
        for (auto it2 = it1; it2 != states.end(); ++it2)
        {
            if(it1 -> getPercentage() > it2 -> getPercentage())
            {
                swap(*it1, *it2);
            }
        }
    }
}

int main()
{
    list<State> states;
    
    cout << "Ordered Listing of States Based on Percentage of Land Needed for Solar Panels" << endl;
    cout << endl;
    
    State tx("Texas", 13480.8, 7487580672000);
    tx.findPercentage();
    cout << tx.getName() << " would use " << tx.getPercentage() << "% of its area" << endl;
    states.push_back(tx);
    
    State cl("California", 6922.8, 4563554688000);
    cl.findPercentage();
    cout << cl.getName() << " would use " << cl.getPercentage() << "% of its area" << endl;
    states.push_back(cl);
    
    State la("Louisiana", 4200.4, 1445216256000);
    la.findPercentage();
    cout << la.getName() << " would use " << la.getPercentage() << "% of its area" << endl;
    states.push_back(la);
    
    State fd("Florida", 4003.1, 1806265792000);
    fd.findPercentage();
    cout << fd.getName() << " would use " << fd.getPercentage() << "% of its area" << endl;
    states.push_back(fd);
    
    State il("Illinois", 3612.9, 1614549657600);
    il.findPercentage();
    cout << il.getName() << " would use " << il.getPercentage() << "% of its area" << endl;
    states.push_back(il);
    
    State pl("Pennsylvania", 3413.0, 1283967590400);
    pl.findPercentage();
    cout << pl.getName() << " would use " << pl.getPercentage() << "% of its area" << endl;
    states.push_back(pl);
    
    State oi("Ohio", 3404.5, 1249649280000);
    oi.findPercentage();
    cout << oi.getName() << " would use " << oi.getPercentage() << "% of its area" << endl;
    states.push_back(oi);
    
    State ny("New York", 3354.2, 1520933990400);
    ny.findPercentage();
    cout << ny.getName() << " would use " << ny.getPercentage() << "% of its area" << endl;
    states.push_back(ny);
    
    State ga("Georgia", 2727.6, 1656673920000);
    ga.findPercentage();
    cout << ga.getName() << " would use " << ga.getPercentage() << "% of its area" << endl;
    states.push_back(ga);
    
    State mg("Michigan", 2610.6, 2696287334400);
    mg.findPercentage();
    cout << mg.getName() << " would use " << mg.getPercentage() << "% of its area" << endl;
    states.push_back(mg);
    
    customSort(states);
    
    return 0;
}