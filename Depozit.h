#ifndef DEPOZIT_H
#define DEPOZIT_H

#include <vector>
#include <iostream>
///clasa template folosita in clasa gestiune pentru numararea alertelor si a strategiilor de pret
template <typename T>
class Depozit
{
private:
    std::vector<T> elemente;
public:
///
    Depozit()=default;
///adaug in vector
    void adauga(const T& elem)
    {
        elemente.push_back(elem);
    }
///golesc vectorul
    void stergeToate()
    {
        elemente.clear();
    }
///functie de returnare a elementelor din vector
    const std::vector<T>& getElemente() const
    {
        return elemente;
    }
///metoda de verificare daca este gol vectorul
    bool esteGol() const
    {
        return elemente.empty();
    }

    template <typename U>
    friend void afiseazaDimensiuneDepozit(const Depozit<U>& d);
};
///aici este functia care afiseaza numarul de alerte din depozit si o folosesc cu stocul si cu numarul de strategii de pret
template <typename U>
void afiseazaDimensiuneDepozit(const Depozit<U>& d)
{
    std::cout<<"[INFO DEPOZIT] Numarul de elemente: "<<d.elemente.size()<<"\n";
}

#endif
