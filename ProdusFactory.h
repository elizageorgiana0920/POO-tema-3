#ifndef PRODUS_FACTORY_H
#define PRODUS_FACTORY_H

#include <memory>
#include <string>
#include <ctime>
#include "Produs.h"
#include "Bautura.h"
#include "Patiserie.h"
#include "Sandwich.h"

class ProdusFactory
{
public:
    static std::shared_ptr<Produs> creeazaProdus(
        const std::string& tip,
        const std::string& nume,
        float pretBaza,
        int timpPrep,
        std::time_t dataExpira=0,
        int stoc=0,
        bool v=false,
        bool z=false,
        bool l=false,
        float kcal=0.0f,
        bool specificMancare=false /// calda pentru Bautura sau poateIncalzi pentru Sandwich
    )
    {
        if (tip=="bautura")
        {
            return std::make_shared<Bautura>(nume, pretBaza, timpPrep, specificMancare);
        }
        else if (tip=="patiserie")
        {
            return std::make_shared<Patiserie>(nume, pretBaza, timpPrep, dataExpira, stoc, v, z, l, kcal);
        }
        else if (tip=="sandwich")
        {
            return std::make_shared<Sandwich>(nume, pretBaza, timpPrep, dataExpira, stoc, v, z, l, kcal, specificMancare);
        }

        return nullptr;
    }
};

#endif
