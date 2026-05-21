
#ifndef GESTIUNE_H
#define GESTIUNE_H

#include <vector>
#include <string>
#include <map>
#include <memory>
#include "Ingredient.h"
#include "Produs.h"
#include "Comanda.h"
#include "Depozit.h"

class Gestiune
{
private:
///am implementat formatul singleton aici
     Gestiune();
    ~Gestiune();
    Gestiune(const Gestiune&)=delete;
    Gestiune& operator=(const Gestiune&)=delete;

    ///pointeri obiecte fizice
    std::vector<Ingredient> listaIngrediente;
    std::vector<Ingredient> listaToppinguri;
    ///clasa de baza, pemite amestecarea bauturi, sandwich
    std::vector<std::shared_ptr<Produs>> meniu;
    std::vector<std::string> istoricComenzi;

    std::vector<std::shared_ptr<Comanda>> coadaComenzi;
    std::vector<std::shared_ptr<Comanda>> comenziSesiuneCurenta;

    static float profitTotal;

    ///asociaza o cheie cu o valoare
    std::map<std::string, int> frecventaProduse;///ora
    std::map<std::string, int> frecventaIngrediente;///nume
    std::map<int, int> frecventaOre;

    Depozit<std::string> alerteStoc;
    Depozit<std::shared_ptr<StrategiePret>> strategiiDisponibile;


public:

    ///asta este poarta de acces la obiect, pe care o apelez in main 
    static Gestiune& getInstanta(){
    static Gestiune instanta;
    return instanta;
    }

    ///metode pe care le-am adaugat pentru barista
    void adaugaComandaInCoada(std::shared_ptr<Comanda> c);
    void afisareComenziActive() const;
    void finalizeazaCeaMaiVecheComanda();
    void genereazaAlerteStoc();
    void afisareAlerteBarista() const;

    /// Incarcare date din fisiere
    void incarcaIngrediente(const std::string& fisier);
    void incarcaToppinguri(const std::string& fisier);
    void incarcaMeniuBauturi(const std::string& fisier);
    void incarcaMeniuPatiserie(const std::string& fisier);
    void incarcaMeniuSandwich(const std::string& fisier);
    void incarcaStatistici(const std::string& fisier);


    void vizualizareComenziRecente() const;
    void salveazaVanzareInIstoric(int ora, const std::string& numeProdus);

    /// Operatii Meniu (Client)
    void afisareMeniu(bool doarDisponibile = false) const;
    void afisareMeniuPersonalizat(bool vegan, bool fZahar, bool fLactoza, const std::string& numeIng = "", bool saContina = true) const;
    void cautaSiAfiseazaProdus(const std::string& nume) const;
    void afisareLogisticaPreparare();

    /// Operatii Manager
    void afisareStocuriIngrediente() const;
    void reaprovizionare(const std::string& numeIng, int cantitate);
    void verificaPatiserieExpirata();
    void verificaSandwichExpirat();
    void afisareRapoarte() const;
    void afisareToateStocurile() const;      /// Pentru Barista (toate)
    void afisareIngredienteCritice() const; /// Pentru Manager (doar < 5)
    void afisareProduseCriticePatiserieSandwich() const;
    void afiseazaRaportBusiness() const;

    void aplicaStrategieGlobala(int tipStrategie);

    /// pentru cautare
    Produs* gasesteProdusDupaNume(const std::string& nume) const;
    Ingredient* gasesteIngredient(const std::string& nume);
    Ingredient* gasesteTopping(const std::string& nume);

    /// Procesare
    void proceseazaComanda(std::shared_ptr<Produs> p, int ora);
    static float getProfitTotal()
    {
        return profitTotal;
    }

    ///pentru folosirea depozitului de alerte
    const Depozit<std::string>& getAlerteStoc() const {return alerteStoc;}
    const Depozit<std::shared_ptr<StrategiePret>>& getStrategiiDisponibile() const{return strategiiDisponibile;}

    void afisareComenziSesiune() const;
    void adaugaComandaInSesiune(std::shared_ptr<Comanda> c);
};

#endif
