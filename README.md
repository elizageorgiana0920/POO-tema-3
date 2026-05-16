# Gestiunea unei cafenele
## Eliza's Coffee Shop

Pentru Tema 3 la materia Programare Orientată pe Obiecte, am implementat o aplicație software care se ocupă cu gestionarea completă a unei cafenele. Aplicația are la bază trei meniuri interactive separate, structurate astfel încât să asigure o utilizare facilă și intuitivă pentru cele trei categorii de utilizatori: Clientul, Barista și Managerul. Fiecare dintre aceștia deține roluri complet diferite și esențiale în funcționarea corectă și eficientă a cafenelei.

---

### 1. Meniul pentru Client
Accesarea acestui meniu se face la liber, fără a fi necesară introducerea unei chei de acces sau a unei parole. Clientul beneficiază de o gamă variată de opțiuni pentru a interacționa cu produsele cafenelei:

* **VEZI MENIU COMPLET:** Permite vizualizarea catalogului integral de preparate, oferind transparență totală asupra ofertei cafenelei, indiferent dacă produsele se află sau nu în stoc la momentul respectiv.
* **VEZI CE OPTIUNI AVEM DISPONIBILE MOMENTAN:** Oferă posibilitatea de a filtra și vizualiza exclusiv preparatele care se află pe stoc.
* **ALEGE UN MENIU PERSONALIZAT:** Pe baza unui scurt chestionar, clientul poate filtra produsele în funcție de preferințele sau restricțiile sale dietetice. Fie că dorește produse fără zahăr, fără lactoză, vegane sau care să conțină (ori să excludă) un ingredient specific introdus de la tastatură, aplicația va genera o listă adaptată exact nevoilor sale.
* **CĂUTARE PRODUS:** Prin simpla introducere a numelui unui preparat, clientul primește instant informații detaliate și specifice legate de preț, timp de preparare și proprietăți nutriționale.
* **COMANDĂ ACUM:** Permite clientului să inițieze o comandă pas cu pas. Acesta introduce numele preparatului dorit. În cazul în care alege o băutură, sistemul îl întreabă dacă dorește un topping extra (care va fi încasat suplimentar). Dacă alege un sandwich, sistemul verifică dacă rețeta permite încălzirea și îi oferă această opțiune. După trimiterea comenzii, clientul primește pe consolă un bon fiscal detaliat ce conține: rezumatul produselor, prețul final, data/ora plasării și un cod unic de ridicare generat pe baza timestamp-ului Unix (prin preluarea ultimelor 3 cifre, asigurând unicitatea).

### 2. Meniul pentru Barista
Meniul dedicat personalului din spatele barului a fost actualizat pentru a oferi o utilizare cât mai practică. Logarea în acest meniu este securizată și necesită o parolă (*hardcoded* ca fiind `barista123`). Opțiunile puse la dispoziție sunt:

* **VEZI PRODUSELE DIN MENIU CARE SUNT PE STOC:** Barista poate vizualiza rapid doar preparatele disponibile. Această funcție este esențială pentru a ști exact ce se poate produce în timp real, eliminând din câmpul vizual produsele indisponibile.
* **VIZUALIZEAZĂ COMENZI ACTIVE ÎN AȘTEPTARE:** Această opțiune expune o coadă polimorfică de comenzi active, trimise direct de clienți. Barista are la dispoziție bonul aferent fiecărei comenzi pentru a le putea pregăti în ordinea corectă a sosirii lor.
* **PREPARA / FINALIZEAZA CEA MAI VECHE COMANDĂ:** Cu ajutorul acestei opțiuni, barista finalizează și elimină din coada de așteptare cea mai veche comandă din sistem (cea a persoanei care se află la rând), actualizând simultan timpul estimat de așteptare pentru clienții următori.
* **ALERTE AUTOMATE DE STOC:** De fiecare dată când barista accesează o opțiune din meniu, sistemul afișează automat pe ecran alerte vizuale privind stocurile critice. Sunt semnalate ingredientele cu mai puțin de 5 unități și produsele de patiserie/sandwich-urile cu mai puțin de 3 unități, alături de numărul total al alertelor active extras din clasa șablon.

### 3. Meniul pentru Manager
Acesta reprezintă cel mai complex modul al aplicației, oferind control administrativ, logistic și economic asupra întregii afaceri. Logarea se face pe bază de parolă securizată (setată în cod ca `manager456`), iar opțiunile sunt:

* **VEZI MENIU COMPLET:** Permite managerului să consulte întreaga listă de produse în vederea analizării structurii meniului și a prețurilor de bază.
* **VEZI STOC INGREDIENTE:** Oferă o imagine de ansamblu asupra inventarului de ingrediente din depozit.
* **REAPROVIZIONEAZĂ:** Permite managerului să introducă marfă nouă în sistem, crescând cantitățile ingredientelor selectate și actualizând stocurile în timp real.
* **INGREDIENTE CU STOC CRITIC:** Filtrează inventarul și afișează strict ingredientele care au coborât sub pragul de 5 unități, ajutând la planificarea rapidă a comenzilor către distribuitori.
* **PRODUSE CU STOC CRITIC (PATISERIE/SANDWICH):** Afișează produsele gata preparate din vitrină care au stocul mai mic de 3 bucăți și necesită o suplimentare urgentă.
* **RAPOARTE BUSINESS:** Optiunea pentru controlul financiar ar cafenelei, afiseaza: profitul total acumulat (care persistă și se adună în continuare între rulările programului datorită salvării externe), ora de vârf (ora în care s-au înregistrat cele mai multe comenzi) și cel mai vândut produs din istoric.
* **VEZI TOATE COMENZILE (ISTORIC):** Oferă acces la jurnalul complet de vânzări. Fiecare comandă are un ID unic și un număr de ordine pe sesiune (care se resetează la 1 la fiecare pornire a programului), permițând managerului o delimitare clară a activității per zi/sesiune.
* **MODIFICĂ POLITICA DE PREȚURI:** Managerul poate schimba dinamic mecanismul de calcul al prețurilor la nivel global. Poate menține regimul standard, poate activa tariful de weekend (+10% la toate produsele pentru maximizarea profitului în perioadele aglomerate) sau poate introduce regimul de Happy Hour (-20% discount pentru stimularea vânzărilor).
* **VERIFICĂ ALERTE STOC ȘI STRATEGII DE PREȚ ACTIVE ÎN DEPOZIT:** O opțiune care apelează direct funcțiile șablon, afișand numărul total de mesaje de alertă active și numărul de strategii de preț încărcate în memorie pentru o mai bună planificare logistică.

---

##  Respectarea Cerințelor-Tema 3

Cerințele impuse în cadrul Proiectului 3 au fost respectate în totalitate, aducând îmbunătățiri față de etapele anterioare:

### 1. Utilizarea Șabloanelor de Proiectare (Design Patterns)
Am integrat **3 design pattern-uri**:
* **Singleton Pattern:** Implementat în clasa `Gestiune` prin metoda statică `getInstanta()`. Constructorul este privat, iar constructorul de copiere și operatorul de atribuire sunt dezactivați (`= delete`). Acest lucru garantează existența unei singure instanțe globale care coordonează baza de date și stocurile cafenelei pe parcursul execuției.
* **Factory Method Pattern:** Clasa `ProdusFactory` expune metoda statică `creeazaProdus`. Aceasta se ocupă de instanțierea polimorfică a obiectelor de tip `Bautura`, `Patiserie` sau `Sandwich` pe baza unui parametru de tip text (`string`), izolând logica de creare a obiectelor și returnând un pointer inteligent de tip `std::shared_ptr<Produs>`.
* **Strategy Pattern:** Interfața `StrategiePret` împreună cu clasele derivate (`StrategieStandard`, `StrategieHappyHour`, `StrategieWeekend`) încapsulează algoritmii de stabilire a prețului. Acest pattern permite modificarea dinamică și polimorfică a prețului final al produselor la rulare, în funcție de decizia managerului.

### 2. Clasă Șablon (Template Class) cu Instanțieri Multiple
Am proiectat clasa șablon `Depozit<T>` (în fișierul `Depozit.h`), care acționează ca un container generic responsabil cu gestionarea unei colecții de elemente (oferă operații de adăugare, ștergere completă, verificare container gol și acces la elemente). Această clasă este instanțiată în mod logic în cadrul proiectului pentru două tipuri de date distincte, ambele fiind membre ale clasei `Gestiune`:
1.  `Depozit<std::string> alerteStoc;` utilizată pentru reținerea și centralizarea mesajelor de alertă text destinate stocurilor critice.
2.  `Depozit<std::shared_ptr<StrategiePret>> strategiiDisponibile;` utilizată pentru stocarea și monitorizarea strategiilor polimorfice de preț încărcate în sistem.

---

## ️ Structura Detaliată a Metodelor Utilizate

### 1. Clasa `Produs` (Clasa de Bază Polimorfică)
* `virtual std::shared_ptr<Produs> clone() const = 0;` // Copiere polimorfică fără secționare
* `virtual float calculeazaPretFinal() const = 0;` // Metodă internă pentru prețul total al unui produs
* `virtual bool esteDisponibil() const = 0;` // Verificare stoc și valabilitate
* `void afiseaza(std::ostream& os) const;` // Interfață Non-Virtuală (NVI) pentru afișarea de bază
* `virtual bool esteVegan() const = 0;` // Filtrare dietetică polimorfică
* `virtual float calculeazaKcalTotal() const = 0;` // Calcul kilocalorii pe baza rețetei

### 2. Clasa `Bautura` (Derivată din `Produs`)
* `void adaugaIngredient(Ingredient* ing);` // Definire rețetă de bază din fișier
* `void adaugaToppingExtra(Ingredient* top);` // Personalizare comandă client la tastaura
* `float calculeazaPretFinal() const override;` // Suma dintre ingrediente, topping-uri și strategie
* `const std::vector<Ingredient*>& getIngrediente() const override;` // Returnează vectorul de ingrediente

### 3. Clasa `Sandwich` (Derivată din `Produs`)
* `void cereIncalzit();` // Activează opțiunea de toast dacă rețeta permite
* `float calculeazaPretFinal() const override;` // Calculează adaosul și adaugă taxa de încălzire (+2 RON)
* `bool esteExpirat() const;` // Verificare timestamp vs timp curent
* `void marcheazaExpirat();` // Setează stocul la 0 în vitrină
* `void scadeStoc();` // Actualizare inventar după vânzare

### 4. Clasa `Patiserie` (Derivată din `Produs`)
* `bool esteExpirat() const;` // Verificare valabilitate termen Unix
* `void marcheazaExpirat();` // Setează stocul la 0 dacă produsul a expirat
* `void scadeStoc();` // Scădere din vitrină la cumpărare
* `int getStoc() const;` // Returnează cantitatea disponibilă

### 5. Clasa `Gestiune`
* `void incarcaIngrediente(string fisier);` // Citire bază de date materii prime
* `void incarcaMeniuSandwich(string fisier);` // Instanțiere obiecte Sandwich din fișier
* `void incarcaMeniuPatiserie(string fisier);` // Instanțiere obiecte Patiserie din fișier
* `void afisareMeniu(bool doarDisponibile) const;` // Vizualizare catalog complet sau filtrat
* `void verificaPatiserieExpirata();` // Curăță vitrina de patiserie expirată
* `void proceseazaComanda(shared_ptr<Produs> p, int ora);` // Scade stoc, adaugă profit, scrie registru
* `void afisareProduseCriticePatiserieSandwich() const;` // Alertă manager pentru produse finite < 3
* `void afisareRapoarte() const;` // Analiză date macro din fișierele text

### 6. Clasa `Comanda`
* `void adaugaProdus(shared_ptr<Produs> p);` // Adăugare în coșul polimorfic
* `void finalizeazaComanda(Gestiune& g);` // Confirmare plată și trimitere în procesare stocuri
* `void afisareSumarConsola() const;` // Afișare bon fiscal înainte de plată

### 7. Clasa `Autentificare` (Sistemul de Securitate)
* `static Rol selecteazaRol();` // Gestionează meniul de start și validarea tipului de utilizator
* `static void verificaParola(Rol rol);` // Verifică credențialele și aruncă `AccesInterzisException` în caz de eșec
* `static string getNumeRol(Rol rol);` // Convertește tipul Enum în text lizibil pentru interfață

### 8. Clasa `Ingredient` (Gestiunea Materiilor Prime)
* `void consumaStoc();` // Scade stocul cu 1 la vânzare, aruncă excepție dacă e 0
* `bool atentieStocMic();` // Indicator pentru pragul critic de aprovizionare (< 5)
* `operator>>` / `operator<<` // Facilitează citirea formatată din fișiere și afișarea datelor
---
##  Fișierele folosite
Aplicația salvează și citește automat date externe pentru a simula un mediu real de producție:
* `profit_total.txt`: Salvează valoarea cumulată a profitului net la închiderea corectă a programului.
* `registru.txt`: Jurnalul complet al tranzacțiilor (contine bonurile detaliate cu ID, dată, oră și produse).
* `statistici.txt`: Ține evidența orelor și a denumirilor produselor vândute pentru a putea genera rapoartele legate de ora de vârf și top produse vândute.
* `ingrediente.txt` & `toppinguri.txt`: Inventarul de materii prime actualizat automat la final de către destructorul managerului.

---

##  Bibliografie
* [GeeksforGeeks - File Handling in C++](https://www.geeksforgeeks.org/cpp/file-handling-c-classes/)
* [StackOverflow - Formatting Text Output with setw](https://stackoverflow.com/questions/54738445/how-do-i-use-setw-in-c-to-align-format-text-in-the-console)
* [StackOverflow - Clearing input streams using cin.ignore](https://stackoverflow.com/questions/25020129/cin-ignorenumeric-limitsstreamsizemax-n)
* [Repository POO - Exemple Arhitecturi și Structuri](https://github.com/mcmarius/poo/tree/master/tema-2)