# Gestiunea unei cafenele
## Eliza's Coffee Shop

Pentru Tema 3, am implementat o aplicație software care se ocupă cu gestionarea completă a unei cafenele. Aplicația are la bază trei meniuri interactive separate, structurate astfel încât să asigure o utilizare facilă pentru cele trei categorii de utilizatori: Clientul, Barista și Managerul. Fiecare dintre aceștia deține roluri complet diferite și esențiale în funcționarea corectă și eficientă a cafenelei.

---

### 1. Meniul pentru Client
Accesarea acestui meniu se face la liber, fără a fi necesară introducerea unei chei de acces sau a unei parole. Clientul beneficiază de o gamă variată de opțiuni:

* **VEZI MENIU COMPLET:** Permite vizualizarea catalogului integral de preparate, oferind transparență totală asupra ofertei cafenelei, indiferent dacă produsele se află sau nu în stoc la momentul respectiv.
* **VEZI CE OPTIUNI AVEM DISPONIBILE MOMENTAN:** Oferă posibilitatea de a filtra și vizualiza exclusiv preparatele care se află pe stoc.
* **ALEGE UN MENIU PERSONALIZAT:** Pe baza unui scurt chestionar, clientul poate filtra produsele în funcție de preferințele sau restricțiile sale dietetice. Fie că dorește produse fără zahăr, fără lactoză, vegane sau care să conțină (ori să excludă) un ingredient specific introdus de la tastatură, aplicația va genera o listă adaptată exact nevoilor sale.
* **CĂUTARE PRODUS:** Prin simpla introducere a numelui unui preparat, clientul primește instant informații detaliate și specifice legate de preț, timp de preparare și proprietăți nutriționale.
* **COMANDĂ ACUM:** Permite clientului să inițieze o comandă pas cu pas. Acesta introduce numele preparatului dorit. În cazul în care alege o băutură, sistemul îl întreabă dacă dorește un topping extra (care va fi încasat suplimentar). Dacă alege un sandwich, sistemul verifică dacă rețeta permite încălzirea și îi oferă această opțiune. După trimiterea comenzii, clientul primește pe consolă un bon fiscal detaliat ce conține: rezumatul produselor, prețul final, data/ora plasării și un cod unic de ridicare generat pe baza timestamp-ului Unix (prin preluarea ultimelor 3 cifre, asigură unicitatea).

### 2. Meniul pentru Barista
Meniul dedicat personalului din spatele barului a fost actualizat pentru a oferi o utilizare cât mai practică. Logarea în acest meniu este securizată și necesită o parolă (*hardcoded* ca fiind `barista123`). Opțiunile puse la dispoziție sunt:

* **VEZI PRODUSELE DIN MENIU CARE SUNT PE STOC:** Barista poate vizualiza rapid doar preparatele disponibile. Această funcție este esențială pentru a ști exact ce se poate produce în timp real, eliminând din câmpul vizual produsele indisponibile.
* **VIZUALIZEAZĂ COMENZI ACTIVE ÎN AȘTEPTARE:** Această opțiune expune o coadă polimorfică de comenzi active, trimise direct de clienți. Barista are la dispoziție bonul aferent fiecărei comenzi pentru a le putea pregăti în ordinea corectă a sosirii lor.
* **PREPARA / FINALIZEAZA CEA MAI VECHE COMANDĂ:** Cu ajutorul acestei opțiuni, barista finalizează și elimină din coada de așteptare cea mai veche comandă din sistem (cea a persoanei care se află la rând), actualizând simultan timpul estimat de așteptare pentru clienții următori.
* **ALERTE AUTOMATE DE STOC:** De fiecare dată când barista accesează o opțiune din meniu, sistemul afișează automat pe ecran alerte vizuale privind stocurile critice. Sunt semnalate ingredientele cu mai puțin de 5 unități și produsele de patiserie/sandwich-urile cu mai puțin de 3 unități, alături de numărul total al alertelor active extras din clasa șablon.

### 3. Meniul pentru Manager
Acesta reprezintă cel mai complex modul al aplicației, oferind control administrativ, logistic și economic asupra întregii afaceri. Logarea se face pe bază de parolă securizată (setată în cod ca `manager456`), iar opțiunile sunt:

* **VEZI MENIU COMPLET:** Permite managerului să consulte întreaga listă de produse în cazul în care ar vrea modificarea structurii și a prețurilor de bază.
* **VEZI STOC INGREDIENTE:** Afișează inventarul tuturor ingredientelor din depozit.
* **REAPROVIZIONEAZĂ:** Permite managerului să introducă marfă nouă în sistem, crescând cantitățile ingredientelor selectate și actualizând stocurile în timp real.
* **INGREDIENTE CU STOC CRITIC:** Filtrează inventarul și afișează strict ingredientele care au coborât sub pragul de 5 unități, ajutând la o reaprovizionare mai eficientă.
* **PRODUSE CU STOC CRITIC (PATISERIE/SANDWICH):** Afișează produsele gata preparate din vitrină care au stocul mai mic de 3 bucăți și necesită o suplimentare urgentă.
* **RAPOARTE BUSINESS:** Optiunea pentru controlul financiar ar cafenelei, afiseaza: profitul total acumulat (care persistă și se adună în continuare între rulările programului datorită salvării în fișier), ora de vârf (ora în care s-au înregistrat cele mai multe comenzi) și cel mai vândut produs din istoric.
* **VEZI TOATE COMENZILE (ISTORIC):** Oferă acces la registrul complet de vânzări. Fiecare comandă are un ID unic și un număr de ordine pe sesiune (care se resetează la 1 la fiecare pornire a programului), permițând managerului o delimitare clară a activității per zi/sesiune.
* **MODIFICĂ POLITICA DE PREȚURI:** Managerul poate schimba dinamic mecanismul de calcul al prețurilor la nivel global. Poate menține regimul standard, poate activa tariful de weekend (+10% la toate produsele pentru maximizarea profitului în perioadele aglomerate) sau poate introduce regimul de Happy Hour (-20% discount pentru stimularea vânzărilor).
* **VERIFICĂ ALERTE STOC ȘI STRATEGII DE PREȚ ACTIVE ÎN DEPOZIT:** O opțiune care apelează direct funcțiile șablon, afișand numărul total de mesaje de alertă active și numărul de strategii de preț încărcate în memorie pentru o mai bună planificare logistică.

---
## Respectarea Cerințelor – Tema 3

Pentru această temă am implementat toate cerințele impuse, plus câteva îmbunătățiri față de etapele anterioare.

### Design Patterns

Am integrat trei șabloane de proiectare:

**Singleton** l-am folosit în clasa `Gestiune`, pentru că toată cafeneaua e coordonată de o singură instanță. Constructorul e privat, copia și atribuirea sunt dezactivate, iar accesul se face exclusiv prin `getInstanta()`.

**Factory Method** apare în `ProdusFactory`, prin metoda statică `creeazaProdus`. Primește un string cu tipul produsului și returnează un `shared_ptr<Produs>` care este fie `Bautura`, `Patiserie` sau `Sandwich`.

**Strategy** l-am aplicat pentru prețuri. Interfața `StrategiePret` are trei implementări: `StrategieStandard`, `StrategieHappyHour` (−20%) și `StrategieWeekend` (+10%). Managerul poate schimba strategia global la rulare, fără să afecteze logica produselor.

### Clasa Șablon

Am proiectat `Depozit<T>` ca o clasa template cu operații de bază: adăugare, ștergere, verificare și acces la elemente. În `Gestiune` o folosesc în două moduri: `Depozit<std::string>` pentru alertele de stoc și `Depozit<shared_ptr<StrategiePret>>` pentru strategiile disponibile în sistem, astfel am doua instanțieri.

---

## ️ Structura Detaliată a Metodelor Utilizate

### 1. Clasa `Produs` (Clasa de Bază)
* `virtual std::shared_ptr<Produs> clone() const = 0;`
* `virtual float calculeazaPretFinal() const = 0;` // Calcul preț total pentru un produs
* `virtual bool esteDisponibil() const = 0;` // Verificare stoc și termen de valabilitate
* `void afiseaza(std::ostream& os) const;` // Interfață Non-Virtuală (NVI) pentru afișare
* `virtual bool esteVegan() const = 0;` // Getter pentru filtrare
* `virtual float calculeazaKcalTotal() const = 0;` // Calcul kilocalorii

### 2. Clasa `Bautura`
* `void adaugaIngredient(Ingredient* ing);` // Definire rețetă de bază
* `void adaugaToppingExtra(Ingredient* top);` // Personalizare comandă client
* `float calculeazaPretFinal() const override;` // Suma (PretBaza + Ingrediente + Toppings + StrategiePret)
* `const std::vector<Ingredient*>& getIngrediente() const override;` // Returnează lista de ingrediente

### 3. Clasa `Sandwich`
* `void cereIncalzit();` // Opțiune încălzire
* `float calculeazaPretFinal() const override;` // Include taxa de încălzire (+2 RON)
* `bool esteExpirat() const;` // Verificare timestamp vs timp curent
* `void marcheazaExpirat();` // Setează stocul la 0 (scoatere forțată din meniu)
* `void scadeStoc();` // Actualizare inventar după vânzare

### 4. Clasa `Patiserie`
* `bool esteExpirat() const;` // Verificare valabilitate
* `void marcheazaExpirat();` // Setează stocul la 0
* `void scadeStoc();` // Actualizare stoc
* `int getStoc() const;` // Accesare cantitate disponibilă

### 5. Clasa `Gestiune`
* `void incarcaIngrediente(string fisier);` // Preia materia prima
* `void incarcaMeniuSandwich(string fisier);` // Preia obiecte Sandwich din fișier
* `void incarcaMeniuPatiserie(string fisier);` // Preia obiecte Patiserie din fișier
* `void afisareMeniu(bool doarDisponibile) const;` // Vizualizare meniu complet sau filtrat in functie de stoc
* `void verificaPatiserieExpirata();` // Verifica produsele din stoc daca sunt expirate si le "arunca", adica le reseteaza stocul la 0(cu ajutorul altei metode)
* `void proceseazaComanda(shared_ptr<Produs> p, int ora);` // Scade stoc, adaugă profit, scrie registru
* `void afisareProduseCriticePatiserieSandwich() const;` // Alertă manager pentru produse din patiserie sau sandwich < 3
* `void afisareRapoarte() const;` // Analizeaza datele salvate in fisierele care persista in vederea calcularii rapoartelor

### 6. Clasa `Comanda`
* `void adaugaProdus(shared_ptr<Produs> p);` // Adăugare în comanda
* `void finalizeazaComanda(Gestiune& g);` // Confirmare plată și trimitere în procesare stocuri
* `void afisareSumarConsola() const;` // Afișare bon fiscal înainte de plată

### 7. Clasa `Autentificare` (Sistemul de Securitate)
* `static Rol selecteazaRol();` // Gestionează meniul de start și validarea tipului de utilizator
* `static void verificaParola(Rol rol);` // Verifică daca parola a fost introdusa corect și aruncă `AccesInterzisException` în caz de eșec
* `static string getNumeRol(Rol rol);` // Convertește tipul Enum în text lizibil

### 8. Clasa `Ingredient` (Gestiunea Materiilor Prime)
* `void consumaStoc();` // Scade stocul cu 1 la vânzare, aruncă excepție dacă e 0
* `bool atentieStocMic();` // Indicator pentru pragul critic de aprovizionare (< 5)
* `operator>>` / `operator<<` // Facilitează citirea din fișiere și afișarea datelor
---
##  Fișierele folosite
Aplicația folosește fișiere externe cu scopul de a salva datele calculate și de a introduce o bază de date în sistem asemenea unei cafenele reale:
* `profit_total.txt`: Salvează profitul încasat la închiderea corectă a programului.
* `registru.txt`: Istoricul complet al comenzilor (contine bonurile detaliate cu ID, dată, oră și produse).
* `statistici.txt`: Ține evidența orelor și a denumirilor produselor vândute pentru a putea genera rapoartele legate de ora de vârf și top produse vândute.
* `ingrediente.txt` & `toppinguri.txt`: Inventarul materiei prime.

---

##  Bibliografie
* [GeeksforGeeks - File Handling in C++](https://www.geeksforgeeks.org/cpp/file-handling-c-classes/)
* [StackOverflow - Formatting Text Output with setw](https://stackoverflow.com/questions/54738445/how-do-i-use-setw-in-c-to-align-format-text-in-the-console)
* [StackOverflow - Clearing input streams using cin.ignore](https://stackoverflow.com/questions/25020129/cin-ignorenumeric-limitsstreamsizemax-n)
* [Repository POO - Exemple Arhitecturi și Structuri](https://github.com/mcmarius/poo/tree/master/tema-2)
