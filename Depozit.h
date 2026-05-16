#ifndef DEPOZIT_H
#define DEPOZIT_H

#include <vector>
#include <iostream>

template <typename T>
class Depozit
{
private:
    std::vector<T> elemente;
public:
    Depozit()=default;

    void adauga(const T& elem)
    {
        elemente.push_back(elem);
    }

    void stergeToate()
    {
        elemente.clear();
    }

    const std::vector<T>& getElemente() const
    {
        return elemente;
    }

    bool esteGol() const
    {
        return elemente.empty();
    }

    template <typename U>
    friend void afiseazaDimensiuneDepozit(const Depozit<U>& d);
};

template <typename U>
void afiseazaDimensiuneDepozit(const Depozit<U>& d)
{
    std::cout<<"[INFO DEPOZIT] Numarul de elemente: "<<d.elemente.size()<<"\n";
}

#endif
