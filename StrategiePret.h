#ifndef STRATEGIE_PRET_H
#define STRATEGIE_PRET_H

#include <string>

class StrategiePret
{
public:
    virtual ~StrategiePret()=default;
    virtual float calculeazaPret(float pretBaza, float modificatorMancare=0.0f) const=0;
    virtual std::string getDenumire() const=0;
};

///este strategia din proiectul pentru tema2
class StrategieStandard : public StrategiePret
{
public:
    float calculeazaPret(float pretBaza, float modificatorMancare=0.0f) const override
    {
        if (modificatorMancare>0.0f)
        {
            return (pretBaza*modificatorMancare);
        }
        return pretBaza;///pentru bauturi pretul final este suma ingredientelor
    }
    std::string getDenumire() const override
    {
        return "Standard";
    }
};

///pentru reduecere de 20% la HappyHour
class StrategieHappyHour : public StrategiePret
{
public:
    float calculeazaPret(float pretBaza, float modificatorMancare=0.0f) const override
    {
        float pretNormal=pretBaza;
        if (modificatorMancare>0.0f)
        {
            pretNormal=pretBaza*modificatorMancare;
        }
        return pretNormal*0.80f;///reducere 20% din pretul final cu tot cu adaos
    }
    std::string getDenumire() const override
    {
        return "Happy Hour (-20%)";
    }
};

///adaos de 10% in timpul weekendului pentru un profit mai bun
class StrategieWeekend : public StrategiePret
{
public:
    float calculeazaPret(float pretBaza, float modificatorMancare = 0.0f) const override
    {
        float pretNormal=pretBaza;
        if (modificatorMancare>0.0f)
        {
            pretNormal=pretBaza*modificatorMancare;
        }
        return pretNormal*1.10f;
    }
    std::string getDenumire() const override
    {
        return "Tarif Weekend (+10%)";
    }
};

#endif
