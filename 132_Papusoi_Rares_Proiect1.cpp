#include <bits/stdc++.h>

using namespace std;

class Cabana {
    static int contorCab;
    const int idCab;
    char* numeCabana;
    string prefixJudet;
    bool inConstructie;
    int stocEchipamente;

public:
    //Constructori;
    Cabana();
    Cabana(char* numeCabana, string prefixJudet, bool inConstructie, int stocEchipamente);
    Cabana(char* numeCabana, string prefixJudet);
    Cabana(string prefixJudet, int stocEchipament);
    Cabana(const Cabana& obj);

    //Operatori;
    Cabana& operator = (const Cabana&);
    bool operator == (const Cabana& obj);
    bool operator < (const Cabana& obj);
    bool operator > (const Cabana& obj);
    Cabana operator + (Cabana obj);
    Cabana operator + (int stocEchipamente);
    friend Cabana operator + (int stocEchipamente, Cabana obj);
    Cabana operator - (Cabana obj);
    Cabana operator - (int stocEchipamente);
    friend int operator - (int stocEchipamente, Cabana obj);
    Cabana& operator ++ ();
    Cabana operator ++ (int);
    char operator [] (int index);
    operator string() const;

    friend ostream& operator <<(ostream& out, const Cabana& obj);
    friend istream& operator >>(istream& in, Cabana& obj);

    //Metode;
    void numar_echipamente();

    //Get_Set
    int getIdCab() const {return idCab;}
    const char* getNumeCabana() const {return this->numeCabana;}
    string getPrefixJudet() const {return prefixJudet;}
    bool getInConstructie() const {return inConstructie;}
    int getStocEchipamente() const {return stocEchipamente;}

    void setNumeCabana(char* numeCabana);
    void setPrefixJudet(string prefixJudet) {this->prefixJudet = prefixJudet;}
    void setInConstructie (bool inConstructie) {this->inConstructie = inConstructie;}
    void setStocEchipamente (int stocEchipamente) {this->stocEchipamente = stocEchipamente;}

    //Destructor
    ~Cabana();
};

int Cabana::contorCab = 0;

Cabana::Cabana():idCab(contorCab++){
    numeCabana = new char[strlen("fara_nume") + 1];
    strcpy(numeCabana, "fara_nume");
    inConstructie = true;
    prefixJudet = "Fara Judet";
    stocEchipamente = 0;
}

Cabana::Cabana(char* numeCabana, string prefixJudet, bool inConstructie, int stocEchipamente):idCab(contorCab++){
    this->numeCabana = new char[strlen(numeCabana) + 1];
    strcpy(this->numeCabana, numeCabana);
    this->prefixJudet = prefixJudet;
    this->inConstructie = inConstructie;
    this->stocEchipamente = stocEchipamente;
}

Cabana::Cabana(char* numeCabana, string prefixJudet):idCab(contorCab++){
    this->numeCabana = new char[strlen(numeCabana) + 1];
    strcpy(this->numeCabana, numeCabana);
    this->prefixJudet = prefixJudet;
    this->inConstructie = true;
    this->stocEchipamente = 0;
}

Cabana::Cabana(string prefixJudet, int stocEchipamente):idCab(contorCab++){
    this->numeCabana = new char[strlen("fara_nume") + 1];
    strcpy(this->numeCabana, "fara_nume");
    this->prefixJudet = prefixJudet;
    this->stocEchipamente = stocEchipamente;
    this->inConstructie = true;
}

Cabana::Cabana(const Cabana& obj):idCab(obj.idCab){
    this->numeCabana = new char[strlen(obj.numeCabana) + 1];
    strcpy(this->numeCabana, obj.numeCabana);
    this->prefixJudet = obj.prefixJudet;
    this->inConstructie = obj.inConstructie;
    this->stocEchipamente = obj.stocEchipamente;
}

Cabana& Cabana::operator = (const Cabana& obj){
    if (this != &obj){
        if (this->numeCabana != NULL){
            delete[] this->numeCabana;
            this->numeCabana = NULL;
        }
        this->numeCabana = new char[strlen(obj.numeCabana) + 1];
        strcpy(this->numeCabana, obj.numeCabana);
        this->prefixJudet = obj.prefixJudet;
        this->inConstructie = obj.inConstructie;
        this->stocEchipamente = obj.stocEchipamente;
    }
    return *this;
}

bool Cabana::operator == (const Cabana& obj){
    if (this->numeCabana != obj.numeCabana)
        return false;
    if (this->inConstructie != obj.inConstructie)
        return false;
    if (this->stocEchipamente != obj.stocEchipamente)
        return false;
    return true;
}

bool Cabana::operator < (const Cabana& obj){
    if (this->stocEchipamente < obj.stocEchipamente)
        return true;
    else return false;
}

bool Cabana::operator > (const Cabana& obj){
    if (this->stocEchipamente > obj.stocEchipamente)
        return true;
    else return false;
}

Cabana Cabana::operator + (Cabana obj){
    obj.stocEchipamente = obj.stocEchipamente + this->stocEchipamente;
    return obj;
}

Cabana Cabana::operator + (int stocEchipamente){
    Cabana cop(*this);
    cop.stocEchipamente = cop.stocEchipamente + stocEchipamente;
    return cop;
}

Cabana operator + (int stocEchipamente, Cabana obj){
    obj.stocEchipamente = obj.stocEchipamente + stocEchipamente;
    return obj;
}

Cabana Cabana::operator - (Cabana obj){
    obj.stocEchipamente = this->stocEchipamente - obj.stocEchipamente;
    return obj;
}

Cabana Cabana::operator - (int numarEchipamente){
    Cabana cop(*this);
    cop.stocEchipamente = cop.stocEchipamente - numarEchipamente;
    return cop;
}

int operator - (int numarEchipamente, Cabana obj){
    numarEchipamente = numarEchipamente - obj.stocEchipamente;
    return numarEchipamente;
}

Cabana& Cabana::operator ++ (){
    this->stocEchipamente ++;
    return *this;
}

Cabana Cabana::operator ++ (int){
    Cabana cop(*this);
    this->stocEchipamente++;
    return cop;
}

char Cabana::operator [] (int index){
    try{
        if (index < 0 || index > strlen(this->numeCabana) - 1)
            throw runtime_error("invalid index");
    }
    catch(runtime_error){
        cout<<"Index invalid.";
    }
    return this->numeCabana[index];
}

Cabana::operator string() const{
    return this->numeCabana;
}

ostream& operator << (ostream& out, const Cabana& obj){
    out<<"ID: "<<obj.idCab<<endl;
    out<<"Nume Cabana: "<<obj.numeCabana<<endl;
    out<<"Prefixul judetului: "<<obj.prefixJudet<<endl;
    out<<"In constructie: "<<obj.inConstructie<<endl;
    out<<"Stoc echipament: "<<obj.stocEchipamente<<endl;
    return out;
}

istream& operator >>(istream& in, Cabana& obj){
    cout<<"Numele cabanei: ";
    char numeCabana[100];
    in >> numeCabana;
    if (obj.numeCabana != NULL){
        delete[] obj.numeCabana;
        obj.numeCabana = NULL;
    }
    obj.numeCabana = new char[strlen(numeCabana) + 1];
    strcpy(obj.numeCabana, numeCabana);

    cout<<"Care este prefixul judetului: ";
    in>>obj.prefixJudet;
    cout<<endl;

    cout<<"Este cabana in constructie?(1/0) ";
    in>>obj.inConstructie;
    cout<<endl;

    cout<<"Care este stocul cabanei? ";
    in>>obj.stocEchipamente;
    cout<<endl;

    return in;
}

inline void Cabana::numar_echipamente(){
    cout<<"La cabana "<<this->numeCabana<<" din "<<this->prefixJudet<<" sunt "<<this->stocEchipamente<<
    " perechi de schiuri";
}

void Cabana::setNumeCabana(char* numeCabana){
    if (this->numeCabana != NULL){
        delete[] this->numeCabana;
        this->numeCabana = NULL;
    }
    this->numeCabana = new char[strlen(numeCabana) + 1];
    strcpy(this->numeCabana, numeCabana);
}

Cabana::~Cabana(){
    if (this->numeCabana != NULL){
        delete[] this->numeCabana;
        this->numeCabana = NULL;
    }
    this->prefixJudet = "";
    this->inConstructie = true;
    this->stocEchipamente = 0;
}

class Schi {
    static int contorSchi;
    const int idSchi;
    char* numeProd;
    float inaltimeSchi;
    char culoareSchi;
    int numarMarimiAcceptate;
    float* marimiAcceptate;

public:
    //Constructori
    Schi();
    Schi(char* numeProd, float inaltimeSchi, char culoareSchi,int numarMarimiAcceptate, float* marimiAcceptate);
    Schi(char* numeProd, float inaltimeSchi);
    Schi(char culoareSchi,int numarMarimiAcceptate, float* marimiAcceptate);
    Schi(const Schi& obj);

    //Operatori
    Schi& operator = (const Schi& obj);
    bool operator == (const Schi& obj);
    bool operator > (const Schi& obj);
    bool operator < (const Schi& obj);
    Schi operator + (Schi obj);
    Schi operator + (float inaltimeSchi);
    friend Schi operator + (float inaltimeSchi, Schi obj);
    Schi operator - (Schi obj);
    Schi operator - (float inaltimeSchi);
    friend int operator - (float inaltimeSchi, Schi obj);
    Schi& operator ++ ();
    Schi operator ++ (int);
    int operator [] (int index);
    operator float();
    
    friend ostream& operator << (ostream& out, const Schi& obj);
    friend istream& operator >> (istream& out, Schi& obj);

    //Metode
    void culoare_schi();

    //Get_Set
    int getIdSchi() const {return idSchi;}
    const char* getNumeProd() const {return this->numeProd;}
    float getInaltimeSchi() const {return inaltimeSchi;}
    char getCuloareSchi() const {return culoareSchi;}
    int getNumarMarimiAcceptate() const {return numarMarimiAcceptate;}
    const float* getMarimiAcceptate() const {return this->marimiAcceptate;}

    void setNumeProd(char* numeProd);
    void setInaltimeSchi(float inaltimeSchi) {this->inaltimeSchi = inaltimeSchi;}
    void setCuloareSchi(char culoareSchi) {this->culoareSchi = culoareSchi;}
    void setNumarMarimiAcceptate(int numarMarimiAcceptate) {this->numarMarimiAcceptate = numarMarimiAcceptate;}
    void setMarimiAcceptate(float* marimiAcceptate);

    //Destructor
    ~Schi();
};

int Schi::contorSchi = 0;

Schi::Schi():idSchi(contorSchi++){
    this->numeProd = new char[strlen("fara_nume") + 1];
    strcpy(this->numeProd, "fara_nume");
    this->inaltimeSchi = 0;
    this->culoareSchi = '-';
    this->numarMarimiAcceptate = 0;
    this->marimiAcceptate = NULL;
}

Schi::Schi(char* numeProd, float inaltimeSchi, char culoareSchi,int numarMarimiAcceptate,
float* marimiAcceptate):idSchi(contorSchi++){
    this->numeProd = new char[strlen(numeProd) + 1];
    strcpy(this->numeProd, numeProd);
    this->inaltimeSchi = inaltimeSchi;
    this->culoareSchi = culoareSchi;
    this->numarMarimiAcceptate = numarMarimiAcceptate;
    this->marimiAcceptate = marimiAcceptate;
}

Schi::Schi(char* numeProd, float inaltimeSchi):idSchi(contorSchi++){
    this->numeProd = new char[strlen(numeProd) + 1];
    strcpy(this->numeProd, numeProd);
    this->inaltimeSchi = inaltimeSchi;
    this->culoareSchi = '-';
    this->numarMarimiAcceptate = 0;
    this->marimiAcceptate = NULL;
}

Schi::Schi(char culoareSchi,int numarMarimiAcceptate, float* marimiAcceptate):idSchi(contorSchi++){
    this->numeProd = new char[strlen("fara_nume") + 1];
    strcpy(this->numeProd, numeProd);
    this->inaltimeSchi = 0;
    this->culoareSchi = culoareSchi;
    this->numarMarimiAcceptate = numarMarimiAcceptate;
    this->marimiAcceptate = marimiAcceptate;
}

Schi::Schi(const Schi& obj):idSchi(obj.idSchi){
    this->numeProd = new char[strlen(obj.numeProd) + 1];
    strcpy(this->numeProd, obj.numeProd);
    this->inaltimeSchi = obj.inaltimeSchi;
    this->culoareSchi = obj.culoareSchi;
    this->numarMarimiAcceptate = obj.numarMarimiAcceptate;
    this->marimiAcceptate = new float[obj.numarMarimiAcceptate];
    for (int i=0; i<obj.numarMarimiAcceptate; i++){
        this->marimiAcceptate[i] = obj.marimiAcceptate[i];
    }
}

Schi& Schi::operator = (const Schi& obj){
    if (this != &obj){
        if (this->numeProd != NULL){
            delete[] this->numeProd;
            this->numeProd = NULL;
        }
        if (this->marimiAcceptate != NULL){
            delete[] this->marimiAcceptate;
            this->marimiAcceptate = NULL;
        }
        this->numeProd = new char[strlen(obj.numeProd) + 1];
        strcpy(this->numeProd, obj.numeProd);
        this->inaltimeSchi = obj.inaltimeSchi;
        this->culoareSchi = obj.culoareSchi;
        this->numarMarimiAcceptate = obj.numarMarimiAcceptate;
        this->marimiAcceptate = new float[obj.numarMarimiAcceptate + 1];
        for (int i=0; i<obj.numarMarimiAcceptate; i++){
            this->marimiAcceptate[i] = obj.marimiAcceptate[i];
        }
    }
    return *this;
}

bool Schi::operator == (const Schi& obj){
    if (strcmp(this->numeProd, obj.numeProd) != 0)
        return false;
    if (this->inaltimeSchi != obj.inaltimeSchi)
        return false;
    if (this->numarMarimiAcceptate != obj.numarMarimiAcceptate)
        return false;
    float a[this->numarMarimiAcceptate], b[this->numarMarimiAcceptate];
    for (int i=0; i<this->numarMarimiAcceptate; i++){
        a[i] = this->marimiAcceptate[i];
        b[i] = obj.marimiAcceptate[i];
    }
    sort(a, a+this->numarMarimiAcceptate-1);
    sort(b, b+obj.numarMarimiAcceptate-1);
    for (int i=0; i<this->numarMarimiAcceptate; i++){
        if (a[i] != b[i])
            return false;
    }
    return true;
}

bool Schi::operator > (const Schi& obj){
    if (obj.inaltimeSchi > this->inaltimeSchi)
        return false;
    else return true;
}

bool Schi::operator < (const Schi& obj){
    if (obj.inaltimeSchi < this->inaltimeSchi)
        return false;
    else return true;
}

Schi Schi::operator + (Schi obj){
    obj.inaltimeSchi = obj.inaltimeSchi + this->inaltimeSchi;
    return obj;    
}

Schi Schi::operator + (float inaltimeSchi){
    Schi cop(*this);
    cop.inaltimeSchi = cop.inaltimeSchi + inaltimeSchi;
    return cop;
}

Schi operator + (float inaltimeSchi, Schi obj){
    obj.inaltimeSchi = obj.inaltimeSchi + inaltimeSchi;
    return obj;
}

Schi Schi::operator - (Schi obj){
    obj.inaltimeSchi = obj.inaltimeSchi - this->inaltimeSchi;
    return obj;
}

Schi Schi::operator - (float inaltimeSchi){
    Schi cpy(*this);
    cpy.inaltimeSchi = cpy.inaltimeSchi - inaltimeSchi;
    return cpy;
}

int operator - (float inaltimeSchi, Schi obj){
    inaltimeSchi = inaltimeSchi - obj.inaltimeSchi;
    return inaltimeSchi;
}

Schi& Schi::operator ++ (){
        this->inaltimeSchi ++;
        return *this;
    }

Schi Schi::operator ++ (int){
    Schi copy(*this);
    this->inaltimeSchi ++;
    return copy;
}

int Schi::operator [] (int index){
    try{
        if (index < 0 || index > this->numarMarimiAcceptate - 1)
            throw runtime_error("invalid index");
    }
    catch(runtime_error){
        cout<<"Index invalid.";
    }
    return this->marimiAcceptate[index];
}

ostream& operator << (ostream& out, const Schi& obj){
    out<<"ID: "<<obj.idSchi<<endl;
    out<<"Nume Producator: "<<obj.numeProd<<endl;
    out<<"Inaltime schiuri: "<<obj.inaltimeSchi<<endl;
    out<<"Culoare schiuri: "<<obj.culoareSchi<<endl;
    out<<"Numar de marimi potrivite: "<<obj.numarMarimiAcceptate<<endl;
    out<<"Marimile care se potrivesc: ";
    for (int i=0; i<obj.numarMarimiAcceptate; i++){
        out<<obj.marimiAcceptate[i]<<" ";
    }
    out<<endl;
    return out;
}

istream& operator >> (istream& in, Schi& obj){
    cout<<"Care este numele producatorului: ";
    char numeProd[100];
    in >> numeProd;
    if (obj.numeProd != NULL){
        delete[] obj.numeProd;
        obj.numeProd = NULL;
    }
    obj.numeProd = new char[strlen(numeProd) + 1];
    strcpy(obj.numeProd, numeProd);

    cout<<"Care este inaltimea schiurilor? ";
    in>>obj.inaltimeSchi;
    cout<<endl;

    cout<<"Care este culoarea schiurilor?(g/a/v/r) ";
    in>>obj.culoareSchi;
    cout<<endl;
    if (obj.culoareSchi != 'g' || obj.culoareSchi != 'a' || obj.culoareSchi != 'v' || obj.culoareSchi !='r'){
        cout<<"Introduceti o culoare valida (g/a/v/r) ";
    in>>obj.culoareSchi;
    }
    cout<<endl;

    cout<<"Cate marimi se potrivesc pe schiuri: ";
    in>>obj.numarMarimiAcceptate;
    cout<<endl;

    cout<<"Ce marimi se potrivesc pe schiuri? ";
    if (obj.marimiAcceptate != NULL){
        delete[] obj.marimiAcceptate;
        obj.marimiAcceptate = NULL;
    }
    obj.marimiAcceptate = new float[obj.numarMarimiAcceptate];
    for (int i=0; i<obj.numarMarimiAcceptate; i++){
        in>>obj.marimiAcceptate[i];
    }
    return in;
}

void Schi::culoare_schi(){
    if (this->culoareSchi == 'g')
        cout<<"Galben\n";
    if (this->culoareSchi == 'a')
        cout<<"Albastru\n";
    if (this->culoareSchi == 'v')
        cout<<"Verde\n";
    if (this->culoareSchi == 'r')
        cout<<"Rosu\n";
}

void Schi::setNumeProd(char* numeProd){
    if (this->numeProd != NULL){
        delete[] this->numeProd;
        this->numeProd = NULL;
    }
    this->numeProd = new char[strlen(numeProd) + 1];
    strcpy(this->numeProd, numeProd);
}

void Schi::setMarimiAcceptate(float* marimiAcceptate){
    if (this->marimiAcceptate != NULL){
        delete[] this->marimiAcceptate;
        this->marimiAcceptate = NULL;
    }
    this->marimiAcceptate = new float[getNumarMarimiAcceptate() + 1];
    for (int i=0; i<getNumarMarimiAcceptate(); i++){
        this->marimiAcceptate[i] = marimiAcceptate[i];
    }
}

Schi::~Schi(){
    if (this->numeProd != NULL){
        delete[] this->numeProd;
        this->numeProd = NULL;
    }
    if (this->marimiAcceptate != NULL){
        delete[] this->marimiAcceptate;
        this->marimiAcceptate = NULL;
    }
    this->inaltimeSchi = 0;
    this->culoareSchi = '-';
    this->numarMarimiAcceptate = 0;
}

class Schior{
    static int contorSchiori;
    const int idSchior;
    string nume;
    int varsta;
    double inaltime;
    bool inchiriat;
    int numarPerechiInchiriate;
    int* idSchiuriInchiriate;

public:
    //Constructori
    Schior();
    Schior(string nume, int varsta, double inaltime, bool inchiriat, int numarPerechiInchiriate, int* idSchiuriInchiriate);
    Schior(string nume, int varsta, double inaltime);
    Schior(bool inchiriat, int numarPerechiInchiroate);
    Schior(const Schior& obj);

    //Operatori
    Schior& operator = (const Schior& obj);
    bool operator == (const Schior& obj);
    bool operator > (const Schior& obj);
    bool operator < (const Schior& obj);
    Schior operator + (Schior obj);
    Schior operator + (int varsta);
    friend Schior operator + (int varsta, Schior obj);
    Schior operator + (double inaltime);
    friend Schior operator + (double inaltime, Schior obj);
    Schior operator + (const Schi& schi);
    friend Schior operator + (Schi schi, Schior obj);
    Schior operator - (Schior obj);
    Schior operator - (int varsta);
    friend int operator - (int varsta, Schior obj);
    Schior operator - (double inaltime);
    friend double operator - (double inaltime, Schior obj);
    Schior& operator ++ ();
    Schior operator ++ (int);
    int operator [] (int index);
    operator string() const;


    friend ostream& operator << (ostream& out, const Schior& obj);
    friend istream& operator >> (istream& in, Schior& obj);

    //Metode
    void schi_recomandat();

    //Get_Set
    int getIdSchior() const {return idSchior;}
    string getNume() const {return nume;}
    int getVarsta() const {return varsta;}
    double getInaltime() const {return inaltime;}
    bool getInchiriat() const {return inchiriat;}
    int getNumarPerechiInchiriate() const {return numarPerechiInchiriate;}
    const int* getIdSchiuriInchiriate() const {return this->idSchiuriInchiriate;}

    void setNume(string nume) {this->nume = nume;}
    void setVarsta(int varsta) {this->varsta = varsta;}
    void setInaltime(double inaltime) {this->inaltime = inaltime;}
    void setInchiriat(bool inchiriat) {this->inchiriat = inchiriat;}
    void setNumarPerechiInchiriate(int numarPerechiInchiriate) {this->numarPerechiInchiriate = numarPerechiInchiriate;}
    void setIdSchiuriInchiriate(int* idSchiuriInchiriate);

    //Destructor
    ~Schior();    

};

int Schior::contorSchiori = 0;

Schior::Schior():idSchior(contorSchiori++){
    this->nume = "Fara nume";
    this->varsta = 0;
    this->inaltime = 0;
    this->inchiriat = false;
    this->numarPerechiInchiriate = 0;
    this->idSchiuriInchiriate = NULL;
}

Schior::Schior(string nume, int varsta, double inaltime, bool inchiriat, 
int numarPerechiInchiriate, int* idSchiuriInchiriate):idSchior(contorSchiori++){
    this->nume = nume;
    this->varsta = varsta;
    this->inaltime = inaltime;
    this->inchiriat = inchiriat;
    this->numarPerechiInchiriate = numarPerechiInchiriate;
    this->idSchiuriInchiriate = new int[numarPerechiInchiriate];
    for (int i=0; i<numarPerechiInchiriate; i++)
        this->idSchiuriInchiriate[i] = idSchiuriInchiriate[i];
}

Schior::Schior(string nume, int varsta, double inaltime):idSchior(contorSchiori++){
    this->nume = nume;
    this->varsta = varsta;
    this->inaltime = inaltime;
    this->inchiriat = false;
    this->numarPerechiInchiriate = 0;
    this->idSchiuriInchiriate = NULL;
}

Schior::Schior(bool inchiriat, int numarPerechiInchiroate):idSchior(contorSchiori++){
    this->inchiriat = inchiriat;
    this->numarPerechiInchiriate = numarPerechiInchiriate;
    this->nume = "Fara nume";
    this->varsta = 0;
    this->inaltime = 0;
    this->idSchiuriInchiriate = new int[numarPerechiInchiriate];
}

Schior::Schior(const Schior& obj):idSchior(obj.idSchior){
    this->nume = obj.nume;
    this->varsta = obj.varsta;
    this->inaltime = obj.inaltime;
    this->inchiriat = obj.inchiriat;
    this->numarPerechiInchiriate = obj.numarPerechiInchiriate;
    this->idSchiuriInchiriate = new int[obj.numarPerechiInchiriate];
    for (int i=0; i<this->numarPerechiInchiriate; i++)
        this->idSchiuriInchiriate[i] = obj.idSchiuriInchiriate[i];
}

Schior& Schior::operator = (const Schior& obj){
    if (this != &obj){
        if (this->idSchiuriInchiriate != NULL){
            delete[] this->idSchiuriInchiriate;
            this->idSchiuriInchiriate = NULL;
        }
        this->idSchiuriInchiriate = new int[obj.numarPerechiInchiriate];
        for (int i=0; i<obj.numarPerechiInchiriate; i++){
            this->idSchiuriInchiriate[i] = obj.idSchiuriInchiriate[i];
        }
        this->nume = obj.nume;
        this->varsta = obj.varsta;
        this->inaltime = obj.inaltime;
        this->inchiriat = obj.inchiriat;
        this->numarPerechiInchiriate = obj.numarPerechiInchiriate;
    }
    return *this;
}

bool Schior::operator == (const Schior& obj){
    if (this->inaltime != obj.inaltime)
        return false;
    if (this->varsta != obj.varsta)
        return false;
    if (this->inchiriat != obj.inchiriat)
        return false;
    return true;
}

bool Schior::operator > (const Schior& obj){
    if (this->inaltime > obj.inaltime)
        return true;
    else return false;
}

bool Schior::operator < (const Schior& obj){
    if (this->inaltime < obj.inaltime)
        return true;
    else return false;
}

Schior Schior::operator + (Schior obj){
    obj.inaltime = obj.inaltime + this->inaltime;
    obj.varsta = obj.varsta + this->varsta;
    return obj;
}

Schior Schior::operator + (int varsta){
    Schior cop(*this);
    cop.varsta = cop.varsta + varsta;
    return cop;
}

Schior operator + (int varsta, Schior obj){
    obj.varsta = obj.varsta + varsta;
    return obj;
}

Schior Schior::operator + (double inaltime){
    Schior cop(*this);
    cop.inaltime = cop.inaltime + inaltime;
    return cop;
}

Schior operator + (double inaltime, Schior obj){
    obj.inaltime = obj.inaltime + inaltime;
    return obj;
}

Schior Schior::operator + (const Schi& schi){
    Schior cop(*this);
    cop.numarPerechiInchiriate ++;
    int* temp = new int[cop.numarPerechiInchiriate];
    if (cop.idSchiuriInchiriate != NULL){
        delete[] cop.idSchiuriInchiriate;
        cop.idSchiuriInchiriate = NULL;
        for (int i=0; i<this->numarPerechiInchiriate; i++)
            temp[i] = this->idSchiuriInchiriate[i];
        temp[cop.numarPerechiInchiriate - 1] = schi.getIdSchi();
        cop.idSchiuriInchiriate = temp;
    }
    else{
        temp[0] = schi.getIdSchi();
        cop.idSchiuriInchiriate = temp;
    }
    return cop;
}

Schior operator + (Schi schi, Schior obj){
    Schior cop(obj);
    obj.numarPerechiInchiriate ++;
    if (obj.idSchiuriInchiriate != NULL){
        delete[] obj.idSchiuriInchiriate;
        obj.idSchiuriInchiriate = NULL;
        obj.idSchiuriInchiriate = new int[obj.numarPerechiInchiriate];
        for (int i=0; i<cop.numarPerechiInchiriate; i++)
            obj.idSchiuriInchiriate[i] = cop.idSchiuriInchiriate[i];
        obj.idSchiuriInchiriate[obj.numarPerechiInchiriate - 1] = schi.getIdSchi();
    }
    else{
        obj.idSchiuriInchiriate = new int[obj.numarPerechiInchiriate];
        obj.idSchiuriInchiriate[0] = schi.getIdSchi();
    }
    return obj;
}

Schior Schior::operator - (Schior obj){
    obj.varsta = this->varsta - obj.varsta;
    obj.inaltime = this->inaltime - obj.inaltime;
    return obj;
}

Schior Schior::operator - (int varsta){
    Schior cop(*this);
    cop.varsta = cop.varsta - varsta;
    return cop;
}

int operator - (int varsta, Schior obj){
    varsta = varsta - obj.varsta;
    return varsta;
}

Schior Schior::operator - (double inaltime){
    Schior cop(*this);
    cop.inaltime = cop.inaltime - inaltime;
    return cop;
}

double operator - (double inaltime, Schior obj){
    inaltime = inaltime - obj.inaltime;
    return inaltime;
}

Schior& Schior::operator ++ (){
    this->inaltime ++;
    return *this;
}

Schior Schior::operator ++ (int){
    Schior cop(*this);
    cop.inaltime = cop.inaltime + 1;
    return cop;
}

int Schior::operator [] (int index){
    try{
        if (index < 0 || index > this->numarPerechiInchiriate - 1)
            throw runtime_error("invalid index");
    }
    catch(runtime_error){
        cout<<"Index invalid.";
    }
    return this->idSchiuriInchiriate[index];
}

Schior::operator string() const{
    return this->nume;
}

ostream& operator << (ostream& out, const Schior& obj){
    out<<"ID: "<<obj.idSchior<<endl;
    out<<"Nume : "<<obj.nume<<endl;
    out<<"Varsta: "<<obj.varsta<<endl;
    out<<"Inaltime: "<<obj.inaltime<<endl;
    out<<"Inchiriat: "<<obj.inchiriat<<endl;
    out<<"Numar perechi inchiriate: "<<obj.numarPerechiInchiriate<<endl;
    out<<"Id-uri perechi inchiriate: ";
    for (int i=0; i<obj.numarPerechiInchiriate; i++)
        out<<obj.idSchiuriInchiriate[i]<<" ";
    cout<<endl;
    return out;
}

istream& operator >> (istream& in, Schior& obj){
    cout<<"Nume : "; in>>obj.nume;
    cout<<"Varsta: "; in>>obj.varsta;
    cout<<"Inaltime: "; in>>obj.inaltime;
    cout<<"Inchiriat: "; in>>obj.inchiriat;
    if (obj.inchiriat == 1){
        cout<<"Numarul perechilor inchiriate: "; in>>obj.numarPerechiInchiriate;
        cout<<"Id-urile schiurilor inchiriate: ";
        if (obj.idSchiuriInchiriate != NULL){
            delete[] obj.idSchiuriInchiriate;
            obj.idSchiuriInchiriate = NULL;
        }
        obj.idSchiuriInchiriate = new int[obj.numarPerechiInchiriate];
        for (int i=0; i<obj.numarPerechiInchiriate; i++)
            in>>obj.idSchiuriInchiriate[i];
        cout<<endl;
    }
    else{
        obj.numarPerechiInchiriate = 0;
        obj.idSchiuriInchiriate = NULL;
    }
    return in;
}

void Schior::schi_recomandat(){
    cout<<"Inaltimea recomandata a schiurilor este: ";
    cout<<this->inaltime - 0.12<<endl;
}

void Schior::setIdSchiuriInchiriate(int* idSchiuriInchiriate){
    if (this->idSchiuriInchiriate != NULL){
        delete[] this->idSchiuriInchiriate;
        this->idSchiuriInchiriate = NULL;
    }
    this->idSchiuriInchiriate = new int[getNumarPerechiInchiriate() + 1];
    for (int i=0; i<getNumarPerechiInchiriate(); i++)
        this->idSchiuriInchiriate[i] = idSchiuriInchiriate[i];
}


Schior::~Schior(){
    if (this->idSchiuriInchiriate != NULL){
        delete[] this->idSchiuriInchiriate;
        this->idSchiuriInchiriate = NULL;
    }
    this->nume = "Fara nume";
    this->varsta = 0;
    this->inaltime = 0;
    this->inchiriat = false;
    this->numarPerechiInchiriate = 0;
}

class Partie{
    string numePartie;
    float lungimePartie;
    int numarSchiori;
    int* idSchiori;

public:
    //Constructori
    Partie();
    Partie(string numePartie, float lungimePartie, int numarSchiori, int* idSchiori);
    Partie(string numePartie, float lungimePartie);
    Partie(float lungimePartie);
    Partie(const Partie& obj);

    //Operatori
    Partie& operator = (const Partie& obj);
    bool operator == (const Partie& obj);
    bool operator > (const Partie& obj);
    bool operator < (const Partie& obj);
    Partie operator + (Partie obj);
    Partie operator + (float lungimePartie);
    friend Partie operator + (float lungimePartie, Partie obj);
    Partie operator + (const Schior& schior);
    friend Partie operator + (Schior schior, Partie obj);
    Partie& operator ++ ();
    Partie operator ++ (int);
    Partie operator - (Partie obj);
    Partie operator - (double lungimePartie);
    friend double operator - (double lungimePartie, Partie obj);
    int operator [] (int index);
    operator string() const;

    friend ostream& operator << (ostream& out, const Partie& obj);
    friend istream& operator >> (istream& in, Partie& obj);

    //Metode
    void timpMediuCoborare();

    //Get_Set
    string getNumePartie() const {return numePartie;}
    float getLungimePartie() const {return lungimePartie;}
    int getNumarSchiori() const {return numarSchiori;}
    const int* getIdSchiori() const {return this->idSchiori;}

    void setNumePartie(string numePartie) {this->numePartie = numePartie;}
    void setLungimePartie(float lungimePartie) {this->lungimePartie = lungimePartie;}
    void setNumarSchiori(int numarSchiori) {this->numarSchiori = numarSchiori;}
    void setIdSchiori(int* idSchiori);

    //Destructor
    ~Partie();
};

Partie::Partie(){
    this->numePartie = "fara_nume";
    this->lungimePartie = 0;
    this->numarSchiori = 0;
    this->idSchiori = NULL;
}

Partie::Partie(string numePartie, float lungimePartie, int numarSchiori, int* idSchiori){
    this->numePartie = numePartie;
    this->lungimePartie = lungimePartie;
    this->numarSchiori = numarSchiori;
    if (numarSchiori != 0){
        this->idSchiori = new int[numarSchiori];
        for (int i=0; i<numarSchiori; i++)
            this->idSchiori[i] = idSchiori[i];
    }
    else{
        this->idSchiori = NULL;
    }
}

Partie::Partie(string numePartie, float lungimePartie){
    this->numePartie = this->numePartie;
    this->lungimePartie = this->lungimePartie;
    this->numarSchiori = 0;
    this->idSchiori = NULL;
}

Partie::Partie(float lungimePartie){
    this->lungimePartie = lungimePartie;
    this->numePartie = "fara_nume";
    this->numarSchiori = 0;
    this->idSchiori = NULL;
}

Partie::Partie(const Partie& obj){
    this->numePartie = obj.numePartie;
    this->lungimePartie = obj.lungimePartie;
    this->numarSchiori = obj.numarSchiori;
    this->idSchiori = new int[obj.numarSchiori];
    for (int i=0; i<obj.numarSchiori; i++)
        this->idSchiori[i] = obj.idSchiori[i];
}

Partie& Partie::operator = (const Partie& obj){
    if (this != &obj){
        if (this->idSchiori != NULL){
            delete[] this->idSchiori;
            this->idSchiori = NULL;
        }
        this->numePartie = obj.numePartie;
        this->lungimePartie = obj.lungimePartie;
        this->numarSchiori = obj.numarSchiori;
        this->idSchiori = new int[obj.numarSchiori];
        for (int i=0; i<obj.numarSchiori; i++)
            this->idSchiori[i] = obj.idSchiori[i];
    }
    return *this;
}

bool Partie::operator == (const Partie& obj){
    if (this->lungimePartie != obj.lungimePartie)
        return false;
    if (this->numarSchiori != obj.numarSchiori)
        return false;
    return true;
}

bool Partie::operator < (const Partie& obj){
    if (this->lungimePartie > obj.lungimePartie)
        return false;
    if (this->numarSchiori > obj.numarSchiori)
        return false;
    return true;
}

bool Partie::operator > (const Partie& obj){
    if (this->lungimePartie < obj.lungimePartie)
        return false;
    if (this->numarSchiori < obj.numarSchiori)
        return false;
    return true;
}

Partie Partie::operator + (Partie obj){
    obj.lungimePartie = obj.lungimePartie + this->lungimePartie;
    int* temp = new int[this->numarSchiori + obj.numarSchiori];
    for (int i=0; i<obj.numarSchiori; i++)
        temp[i] = obj.idSchiori[i];
    for (int i=0; i<this->numarSchiori; i++)
        temp[i+obj.numarSchiori] = this->idSchiori[i];
    obj.idSchiori = temp;
    obj.numarSchiori = obj.numarSchiori + this->numarSchiori;
    return obj;
}

Partie Partie::operator + (float lungimePartie){
    Partie cop(*this);
    cop.lungimePartie = cop.lungimePartie + lungimePartie;
    return cop;
}

Partie operator + (float lungimePartie, Partie obj){
    obj.lungimePartie = obj.lungimePartie + lungimePartie;
    return obj;
}

Partie Partie::operator + (const Schior& schior){
    Partie cop(*this);
    cop.numarSchiori ++;
    int* temp = new int[cop.numarSchiori];
    if (cop.idSchiori != NULL){
        delete[] cop.idSchiori;
        cop.idSchiori = NULL;
        for (int i=0; i<this->numarSchiori; i++)
            temp[i] = this->idSchiori[i];
        temp[cop.numarSchiori - 1] = schior.getIdSchior();
        cop.idSchiori = temp;
    }
    else{
        temp[0] = schior.getIdSchior();
        cop.idSchiori = temp;
    }
    return cop;
}

Partie operator + (Schior schior, Partie obj){
    Partie cop(obj);
    obj.numarSchiori ++;
    if (obj.idSchiori != NULL){
        delete[] obj.idSchiori;
        obj.idSchiori = NULL;
        obj.idSchiori = new int[obj.numarSchiori];
        for (int i=0; i<cop.numarSchiori; i++)
            obj.idSchiori[i] = cop.idSchiori[i];
        obj.idSchiori[obj.numarSchiori - 1] = schior.getIdSchior();
    }
    else{
        obj.idSchiori = new int[obj.numarSchiori];
        obj.idSchiori[0] = schior.getIdSchior();
    }
    return obj;
}


Partie& Partie::operator ++ (){
    this->lungimePartie ++;
    return *this;
}

Partie Partie::operator ++ (int){
    Partie cop(*this);
    this->lungimePartie ++;
    return cop;
}

Partie Partie::operator - (Partie obj){
    obj.lungimePartie = this->lungimePartie - obj.lungimePartie;
    return obj;
}

Partie Partie::operator - (double lungimePartie){
    Partie cop(*this);
    cop.lungimePartie = cop.lungimePartie - lungimePartie;
    return cop;
}

double operator - (double lungimePartie, Partie obj){
    lungimePartie = lungimePartie - obj.lungimePartie;
    return lungimePartie;
}

int Partie::operator [] (int index){
    try{
        if (index < 0 || index > this->numarSchiori - 1)
            throw runtime_error("invalid index");
    }
    catch(runtime_error){
        cout<<"Index invalid.";
    }
    return this->idSchiori[index];
}


Partie::operator string() const{
    return this->numePartie;
}

ostream& operator << (ostream& out, const Partie& obj){
    out<<"Nume partie: "<<obj.numePartie<<endl;
    out<<"Lungime partie: "<<obj.lungimePartie<<endl;
    out<<"Numar schiori: "<<obj.numarSchiori<<endl;
    if (obj.numarSchiori != 0){
        out<<"Id-urile sunt: ";
        for (int i=0; i<obj.numarSchiori; i++)
            out<<obj.idSchiori[i]<<" ";
    }
    else{
        out<<"Nu sunt schiori."<<endl;
    }
    cout<<endl;
    return out;
}

istream& operator >> (istream& in, Partie& obj){
    if (obj.idSchiori != NULL){
        delete[] obj.idSchiori;
        obj.idSchiori = NULL;
    }
    cout<<"Numele partiei: "; in>>obj.numePartie; cout<<endl;
    cout<<"Lungimea partiei (in km): "; in>>obj.lungimePartie; cout<<endl;
    cout<<"Numarul schiorilor "; in>>obj.numarSchiori; cout<<endl;
    obj.idSchiori = new int[obj.numarSchiori];
    if (obj.numarSchiori != 0){
        cout<<"Id-urile schiorilor: ";
        for (int i=0; i<obj.numarSchiori; i++)
            in>>obj.idSchiori[i];
    }
    cout<<endl;
    return in;
}

void Partie::timpMediuCoborare(){
    cout<<"Timp mediu de coborare este: ";
    cout<<(this->lungimePartie / 24) * 60<<" minute.\n";
}

void Partie::setIdSchiori(int* idSchiori){
    if (this->idSchiori != NULL){
        delete[] this->idSchiori;
        this->idSchiori = NULL;
    }
    this->idSchiori = new int[getNumarSchiori() + 1];
    for (int i=0; i<getNumarSchiori(); i++)
        this->idSchiori[i] = idSchiori[i];
}

Partie::~Partie(){
    if (this->idSchiori != NULL){
        delete[] this->idSchiori;
        this->idSchiori = NULL;
    }
    this->numePartie = "fara_nume";
    this->lungimePartie = 0;
    this->numarSchiori = 0;
}

char nume[30], litera;
string STRINGNUME;
vector<Cabana*> cabane;
vector<Schi*> schiuri;
vector<Schior*> schiori;
vector<Partie*> partii;
int choice;
int i, c, sirint[30];
float f, sir[30];
double d;


int main()
{   
    while(1){
        cout<<"Alegeti clasa pe care doriti sa operati:\n";
        cout<<"\t1. Cabana\n";
        cout<<"\t2. Schi\n";
        cout<<"\t3. Schior\n";
        cout<<"\t4. Partie\n";
        cout<<"Apasa 5 pentru a iesi\n";
        cout<<"Introduceti alegerea: ";
        cin>>choice;
        switch (choice){
        case(1):
            cout<<"Actiuni pentru Cabane:\n";
            cout<<"\t1. Creati un obiect\n";
            cout<<"\t2. Obtineti informatii despre un obiect\n";
            cout<<"\t3. Modificati un obiect\n";
            cout<<"\t4. Eliminati un obiect\n";
            cout<<"\t5. Meniu operatii\n";
            cout<<"\t6. Reveniti la meniul anterior\n";
            cout<<"Introduceti alegerea: ";
            cin>>choice;
            switch(choice){
                case(1):
                    cout<<"Modul de creare al obiectului:\n";
                    cout<<"\t1. Creati un obiect de la 0\n";
                    cout<<"\t2. Creati un obiect care sa preia datele altui obiect\n";
                    cout<<"\t3. Creati un obiect cu ajutorul unui numar redus de informatii\n";
                    cout<<"\t4. Reveniti la meniul anterior\n";
                    cout<<"Introduceti alegerea: ";
                    cin>>choice;
                    switch(choice){
                        case(1):
                            {Cabana *x = new Cabana();
                            cin>>*x;
                            cabane.push_back(x);
                            cout<<"Cabana creata!\n";}
                            break;
                        case(2):
                            {if (cabane.size() != 0){
                                cout<<"Trebuie sa alegeti un obiect existent\n";
                                for (int i=0; i<cabane.size(); i++)
                                    cout<<cabane[i]->getIdCab()<<" ";
                                cout<<endl<<"Alegeti al catelea obiect sa fie sursa: ";
                                cin>>i;
                                Cabana *y(cabane[i-1]);
                                cabane.push_back(y);
                            }
                            else{
                                cout<<"Nu sunt cabane existente.\n";
                            }}
                            break;
                        case(3):
                            cout<<"Alegeti metoda:\n";
                            cout<<"\t1. Cu nume si prefix de judet\n";
                            cout<<"\t2. Cu prefix de judet si numarul de echipamente\n";
                            cout<<"\t3. Reveniti la meniul anterior\n";
                            cout<<"Introduceti alegerea: ";
                            cin>>choice;
                            switch(choice){
                                case(1):
                                    {cout<<"Introduceti numele cabanei: ";
                                    cin>>nume;
                                    cout<<"\n";
                                    cout<<"Introduceti prefixul judetului: ";
                                    cin>>STRINGNUME;
                                    Cabana *z = new Cabana(nume, STRINGNUME);
                                    cabane.push_back(z);}
                                    break;
                                case(2):
                                    {cout<<"Introduceti prefixul judetului: ";
                                    cin>>STRINGNUME;
                                    cout<<"Introduceti numarul de echipamente: ";
                                    cin>>c;
                                    Cabana *t = new Cabana(STRINGNUME, c);
                                    cabane.push_back(t);}
                                    break;
                                case(3):
                                    break;
                            }
                            break;
                        case(4):
                            break;
                    }
                    break;
                case(2):
                    if (cabane.size() == 0){
                        cout<<"Nu exista obiecte. Creati unul mai intai.\n";
                        break;
                    }
                    cout<<"Meniu informatii\n";
                    cout<<"\t1. Toate informatiile despre un obiect\n";
                    cout<<"\t2. Id-ul cabanei\n";
                    cout<<"\t3. Numele cabanei\n";
                    cout<<"\t4. Prefixul judetului in care se afla\n";
                    cout<<"\t5. Status cabana\n";
                    cout<<"\t6. Numarul de echipamente\n";
                    cout<<"\t7. Reveniti la meniul anterior\n";
                    cout<<"Introduceti alegerea: ";
                    cin>>choice;
                    if (choice != 7){
                        cout<<"Cabanele disponibile au urm. ID-uri: \n";
                        for (int i=0; i<cabane.size(); i++)
                            cout<<cabane[i]->getIdCab()<<" "<<endl;
                    }
                    switch(choice){
                        case(1):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<*cabane[i-1];
                            break;
                        case(2):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<cabane[i-1]->getIdCab()<<endl;
                            break;
                        case(3):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<cabane[i-1]->getNumeCabana()<<endl;
                            break;
                        case(4):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<cabane[i-1]->getPrefixJudet()<<endl;
                            break;
                        case(5):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            if (cabane[i-1]->getInConstructie() == 0)
                                cout<<"Nu este in constructie\n";
                            else
                                cout<<"Este in constructie\n";
                            break;
                        case(6):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<cabane[i-1]->getStocEchipamente()<<endl;
                            break;
                        case(7):
                            break;
                    }
                    break;
                case(3):
                    if (cabane.size() == 0){
                        cout<<"Nu aveti cabane de modificat. Mai intai introduceti cabane.\n";
                        break;
                    }
                    cout<<"Meniu modificare\n";
                    cout<<"\t1. Schimbati numele\n";
                    cout<<"\t2. Schimbari prefixul judetului\n";
                    cout<<"\t3. Schimbati statusul cabanei (este sau nu in constructie)\n";
                    cout<<"\t4. Schimbati stocul echipamentelor\n";
                    cout<<"\t5. Reveniti la meniul anterior\n";
                    cout<<"Introduceti alegerea: ";
                    cin>>choice;
                    switch(choice){
                        case(1):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<"Alegeti noul nume: ";
                            cin>>nume;
                            cabane[i-1]->setNumeCabana(nume);
                            break;
                        case(2):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<"Alegeti prefixul judetului: ";
                            cin>>STRINGNUME;
                            cabane[i-1]->setPrefixJudet(STRINGNUME);
                            break;
                        case(3):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<"Este cabana in constructie? (Da/Nu): ";
                            cin>>STRINGNUME;
                            if(STRINGNUME == "DA")
                                cabane[i-1]->setInConstructie(1);
                            else
                                cabane[i-1]->setInConstructie(0);
                            break;
                        case(4):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<"Care este noul stoc: ";
                            cin>>c;
                            cabane[i-1]->setStocEchipamente(c);
                            break;
                        case(5):
                            break;
                    }
                    break;
                case(4):
                    cout<<"Din: \n";
                    for (int i=0; i<cabane.size(); i++)
                        cout<<cabane[i]->getIdCab()<<" ";
                    cout<<"\nAlegeti cabana pe care o eliminati: ";
                    cin>>c;
                    cabane.erase(cabane.begin() + c - 1);
                    cout<<"Obiectul a fost eliminat.\n";                    
                    break;
                case(5):
                    cout<<"Meniu operatii\n";
                    cout<<"\t1. Adaugati echipemente unui obiect";
                    cout<<"\t2. Eliminati echipamente unui obiect\n";
                    cout<<"\t3. Reveniti la meniul anterior";
                    cout<<"Introduceti alegerea: ";
                    cin>>choice;
                    switch(choice){
                        case(1):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<"Cate elemente doriti sa adaugati: ";
                            cin>>c;
                            cabane[i-1] = cabane[i-1] + c;
                            break;
                        case(2):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<"Nu se poate sa eliminati mai mult de ";
                            cout<<cabane[i-1]->getStocEchipamente();
                            cout<<" echipamente \n";
                            cout<<"Cate elemente doriti sa eliminati: ";
                            cin>>c;
                            cabane[i-1] = cabane[i-1] - c;
                            break;
                        case(3):
                            break;
                    }
                    break;
                case(6):
                    break;
            }
            break;
        case(2):
            cout<<"Actiuni pentru Schiuri:\n";
            cout<<"\t1. Creati un obiect\n";
            cout<<"\t2. Obtineti informatii despre un obiect\n";
            cout<<"\t3. Modificati un obiect\n";
            cout<<"\t4. Eliminati un obiect\n";
            cout<<"\t5. Meniu operatii\n";
            cout<<"\t6. Reveniti la meniul anterior\n";
            cout<<"Introduceti alegerea: ";
            cin>>choice;
            switch(choice){
                case(1):
                    cout<<"Modul de creare al obiectului\n";
                    cout<<"\t1. Creati un obiect de la 0\n";
                    cout<<"\t2. Creati un obiect care sa preia datele altui obiect existent\n";
                    cout<<"\t3. Creati obiecte folosind un numar redus de informatii\n";
                    cout<<"\t4. Reveniti la meniul anterior\n";
                    cout<<"Introduceti alegerea: ";
                    cin>>choice;
                    switch(choice){
                        case(1):
                            {Schi *x = new Schi();
                            cin>>*x;
                            schiuri.push_back(x);
                            cout<<"Schi creat!\n";}
                            break;
                        case(2):
                            {if (schiuri.size() != 0){
                                cout<<"Trebuie sa alegeti un obiect existent\n";
                                for(int i=0; i<schiuri.size(); i++)
                                    cout<<schiuri[i]->getIdSchi()<<" ";
                                cout<<endl<<"Alegeti al catelea obiect sa fie sursa: ";
                                cin>>i;
                                Schi *x(schiuri[i-1]);
                                schiuri.push_back(x);}
                            else{
                                cout<<"Nu sunt schiuri existente.\n";
                            }}
                            break;
                        case(3):
                            cout<<"Alegeti metoda: \n";
                            cout<<"\t1. Folosind numele schiului si inaltimea sa\n";
                            cout<<"\t2. Folosind culoarea, numarul de marimi acceptate si marimile\n";
                            cout<<"\t3. Reveniti la meniul anterior\n";
                            cout<<"Introduceti alegerea: ";
                            cin>>choice;
                            switch(choice){
                                case(1):
                                    {cout<<"Introduceti numele producatorului: ";
                                    cin>>nume;
                                    cout<<"Introduceti inaltimea schiurilor: ";
                                    cin>>f;
                                    Schi *x = new Schi(nume, f);
                                    schiuri.push_back(x);}
                                    break;
                                case(2):
                                    {cout<<"Introduceti culoarea (g/a/v/r): ";
                                    cin>>litera;
                                    cout<<"Introduceti numarul de marimi acceptate: ";
                                    cin>>c;
                                    cout<<"Introduceti marimile acceptate: ";
                                    for(int i=0; i<c; i++)
                                        cin>>sir[i];
                                    Schi *x = new Schi(litera, c, sir);
                                    schiuri.push_back(x);}
                                    break;
                                case(3):
                                    break;
                            }
                            break;
                        case(4):
                            break;
                    }
                    break;
                case(2):
                    if (schiuri.size() == 0){
                        cout<<"Nu exista obiecte. Creati unul mai intai.\n";
                        break;
                    }
                    cout<<"Meniu informatii\n";
                    cout<<"\t1. Toate informatiile despre un obiect\n";
                    cout<<"\t2. Id-ul unei perechi\n";
                    cout<<"\t3. Numele producatorului unei perechi\n";
                    cout<<"\t4. Inaltimea unei perechi\n";
                    cout<<"\t5. Culoarea unei perechi\n";
                    cout<<"\t6. Numarul de marimi de clapari acceptate\n";
                    cout<<"\t7. Marimile acceptate\n";
                    cout<<"\t8. Reveniti la meniul anterior\n";
                    cout<<"Introduceti alegerea: ";
                    cin>>choice;
                    if (choice != 8){
                        cout<<"Schiurile disponibila au urm. ID-uri: \n";
                        for (int i=0; i<schiuri.size(); i++)
                            cout<<schiuri[i]->getIdSchi()<<" "<<endl;
                    }
                    switch(choice){
                        case(1):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<*schiuri[i-1];
                            break;
                        case(2):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<schiuri[i-1]->getIdSchi()<<endl;
                            break;
                        case(3):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<schiuri[i-1]->getNumeProd()<<endl;
                            break;
                        case(4):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<schiuri[i-1]->getInaltimeSchi()<<endl;
                            break;
                        case(5):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<schiuri[i-1]->getCuloareSchi()<<endl;
                            break;
                        case(6):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<schiuri[i-1]->getNumarMarimiAcceptate()<<endl;
                            break;
                        case(7):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<schiuri[i-1]->getMarimiAcceptate()<<endl;
                            break;
                        case(8):
                            break;   
                    }
                    break; 
                case(3):
                    if (schiuri.size() == 0){
                        cout<<"Nu aveti schiuri de modificat. Mai intai introduceti schiuri.\n";
                        break;
                    }
                    cout<<"Meniu modificare\n";
                    cout<<"\t1. Schimbati numele producatorului\n";
                    cout<<"\t2. Schimbati inaltimea unei perechi\n";
                    cout<<"\t3. Schimbati culoare schiurilor (g/a/v/r) \n";
                    cout<<"\t4. Schimbati cate marimi accepta o pereche\n";
                    cout<<"\t5. Schimbati care sunt marimile acceptate\n";
                    cout<<"\t6. Reveniti la meniul anterior";
                    cout<<"Introduceti alegerea: ";
                    cin>>choice;
                    switch(choice){
                        case(1):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<"Alegeti noul nume: ";
                            cin>>nume;
                            schiuri[i-1]->setNumeProd(nume);
                            break;
                        case(2):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<"Alegeti inaltimea: ";
                            cin>>f;
                            schiuri[i-1]->setInaltimeSchi(f);
                            break;
                        case(3):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<"Introduceti culoarea schiurilor (g/a/v/r): ";
                            cin>>litera;
                            schiuri[i-1]->setCuloareSchi(litera);
                            break;
                        case(4):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<"Cate marimi accepta perechea: ";
                            cin>>c;
                            schiuri[i-1]->setNumarMarimiAcceptate(c);
                            break;
                        case(5):
                            cout<<"Alegeti obiectul (al catelea este): ";
                            cin>>i;
                            cout<<"Perechea aceasta accepta "<<schiuri[i-1]->getNumarMarimiAcceptate()<<" marimi\n";
                            cout<<"Care sunt marimile acceptate: ";
                            for (int i=0; i<schiuri[i-1]->getNumarMarimiAcceptate(); i++)
                                cin>>sir[i];
                            schiuri[i-1]->setMarimiAcceptate(sir);
                            break;
                        case(6):
                            break;
                    }   
                    break;
                case(4):
                    cout<<"Din: \n";
                    for (int i=0; i<schiuri.size(); i++)
                        cout<<schiuri[i]->getIdSchi()<<" ";
                    cout<<"\nAlegeti a cata perechea pe care o eliminati: ";
                    cin>>c;
                    schiuri.erase(schiuri.begin() + c - 1);
                    cout<<"Obiectul a fost eliminat";
                    break;
                case(5):
                    cout<<"Meniu operatii\n";
                    cout<<"\t1. Cresteti inaltimea unei perechi\n";
                    cout<<"\t2. Reduceti inaltimea unei perechi\n";
                    cout<<"\t3. Afisati culoarea completa a unei perechi\n";
                    cout<<"\t4. Reveniti la meniul anterior\n";
                    cout<<"Introduceti alegerea: ";
                    cin>>choice;
                    switch(choice){
                        case(1):
                            cout<<"Alegeti a cata pereche, din lista de id-uri urmatoare: \n";
                            for(int i=0; i<schiuri.size(); i++)
                                cout<<schiuri[i]->getIdSchi()<<" ";
                            cout<<endl;
                            cout<<"Introduceti alegerea: ";
                            cin>>i;
                            cout<<"Introduceti inaltimea: ";
                            cin>>f;
                            *schiuri[i-1] = *schiuri[i-1] + f;
                            break;
                        case(2):
                            cout<<"Alegeti al cata pereche, din lista de id-uri urmatoare: \n";
                            for(int i=0; i<schiuri.size(); i++)
                                cout<<schiuri[i]->getIdSchi()<<" ";
                            cout<<endl;
                            cout<<"Introduceti alegerea: ";
                            cin>>i;
                            cout<<"Nu puteti introduce o inaltime mai mare de: ";
                            cout<<schiuri[i-1]->getInaltimeSchi();
                            cout<<"\nIntroduceti inaltimea: ";
                            cin>>f;
                            *schiuri[i-1] = *schiuri[i-1] - f;
                            break;
                        case(3):
                            cout<<"Alegeti al cata pereche, din lista de id-uri urmatoare: \n";
                            for(int i=0; i<schiuri.size(); i++)
                                cout<<schiuri[i]->getIdSchi()<<" ";
                            cout<<endl;
                            cout<<"Introduceti alegerea: ";
                            cin>>i;
                            schiuri[i-1]->culoare_schi();
                            break;
                        case(4):
                            break;
                    }
                    break;
                case(6):
                    break;
            }
            break;
        case(3):
            cout<<"Actiuni pentru Schiori:\n";
            cout<<"\t1. Creati un obiect\n";
            cout<<"\t2. Obtineti informatii despre un obiect\n";
            cout<<"\t3. Modificati un obiect\n";
            cout<<"\t4. Eliminati un obiect\n";
            cout<<"\t5. Meniu operatii\n";
            cout<<"\t6. Reveniti la meniul anterior\n";
            cout<<"Introduceti alegerea: ";
            cin>>choice;
            switch(choice){
                case(1):
                    cout<<"Modul de creare al obiectului\n";
                    cout<<"\t1. Creati un obiect de la 0\n";
                    cout<<"\t2. Creati un obiect care sa preia datele altui obiect existent\n";
                    cout<<"\t3. Creati obiecte folosind un numar redus de informatii\n";
                    cout<<"\t4. Reveniti la meniul anterior\n";
                    cout<<"Introduceti alegerea: ";
                    cin>>choice;
                    switch(choice){
                        case(1):
                            {Schior *x = new Schior();
                            cin>>*x;
                            schiori.push_back(x);
                            cout<<"Schior creat!\n";}
                            break;
                        case(2):
                            {if (schiori.size() != 0){
                                cout<<"Trebuie sa alegeti un obiect existent\n";
                                for (int i=0; i<schiori.size(); i++)
                                    cout<<schiori[i]->getIdSchior()<<" ";
                                cout<<endl<<"Alegeti al catelea obiect sa fie sursa:";
                                cin>>c;
                                Schior *x = new Schior(*schiori[c-1]);
                                schiori.push_back(x);
                            }
                            else
                                cout<<"Nu sunt schiori existenti.\n";
                            }
                            break;
                        case(3):
                            cout<<"Alegeti metoda: \n";
                            cout<<"\t1. Folosing numele, varsta schiorului, inaltimea schiorului\n";
                            cout<<"\t2. Folosind statusul inchirierii, numarul perechilor inchiriate\n";
                            cout<<"\t3. Reveniti la meniul anterior\n";
                            cout<<"Introduceti alegerea: ";
                            cin>>choice;
                            switch(choice){
                                case(1):
                                    {cout<<"Introduceti numele: ";
                                    cin>>STRINGNUME;
                                    cout<<"Introduceti varsta: ";
                                    cin>>i;
                                    cout<<"Introduceti inaltimea: ";
                                    cin>>d;
                                    Schior *x = new Schior(STRINGNUME, i, d);
                                    schiori.push_back(x);}
                                    break;
                                case(2):
                                    {cout<<"Introduceti statusul inchirierii: ";
                                    cin>>i;
                                    if (i == 1){
                                        cout<<"Introduceti cate perechi a inchiriat: ";
                                        cin>>c;
                                        Schior *x = new Schior(i, c);
                                        schiori.push_back(x);
                                    }
                                    else{
                                        cout<<"Intrucat nu a inchiriat, numarul perechilor inchiriate este 0.\n";
                                        Schior *x = new Schior(0, 0);
                                        schiori.push_back(x);
                                    }}
                                    break;
                                case(3):
                                    break;
                            }
                            break;
                        case(4):
                            break;
                    }
                    break;
                case(2):
                    if (schiori.size() == 0){
                        cout<<"Nu exista obiecte. Creati unul mai intai.\n";
                        break;
                    }
                    cout<<"Meniu informatii\n";
                    cout<<"\t1. Toate informatiile despre un obiect\n";
                    cout<<"\t2. Id-ul schiorului\n";
                    cout<<"\t3. Numele schiorului\n";
                    cout<<"\t4. Varsta schiorului\n";
                    cout<<"\t5. Inaltimea schiorului\n";
                    cout<<"\t6. Statusul inchirierii\n";
                    cout<<"\t7. Numarul perechilor inchiriate\n";
                    cout<<"\t8. Perechile inchiriate\n";
                    cout<<"\t9. Reveniti la meniul anterior\n";
                    cout<<"Introduceti alegerea: ";
                    cin>>choice;
                    if(choice != 9){
                        cout<<"Schiorii disponibili sunt: ";
                        for (int i=0; i<schiori.size(); i++)
                            cout<<schiori[i]->getIdSchior()<<" ";
                        cout<<endl<<"Alegeti al catelea schior: ";
                        cin>>c;
                    }
                    switch(choice){
                        case(1):
                            cout<<*schiori[c-1];
                            break;
                        case(2):
                            cout<<schiori[c-1]->getIdSchior()<<endl;
                            break;
                        case(3):
                            cout<<schiori[c-1]->getNume()<<endl;
                            break;
                        case(4):
                            cout<<schiori[c-1]->getVarsta()<<endl;
                            break;
                        case(5):
                            cout<<schiori[c-1]->getInaltime()<<endl;
                            break;
                        case(6):
                            cout<<schiori[c-1]->getInchiriat()<<endl;
                            break;
                        case(7):
                            cout<<schiori[c-1]->getNumarPerechiInchiriate()<<endl;;
                            break;
                        case(8):
                            cout<<schiori[c-1]->getIdSchiuriInchiriate()<<endl;
                            break;
                        case(9):
                            break;
                    }
                    break;
                case(3):
                    if (cabane.size() == 0){
                        cout<<"Nu aveti schiori de modificat. Mai intai introduceti cabane.\n";
                        break;
                    }
                    cout<<"Meniu modificare\n";
                    cout<<"\t1. Schimbati numele\n";
                    cout<<"\t2. Schimbari varsta \n";
                    cout<<"\t3. Schimbati inaltimea\n";
                    cout<<"\t4. Schimbati statusul inchirierii\n";
                    cout<<"\t5. Schimbati numarul perechilor inchiriate\n";
                    cout<<"\t6. Schimbati care sunt perechile inchiriate\n";
                    cout<<"\t7. Reveniti la meniul anterior\n";
                    cout<<"Introduceti alegerea: ";
                    cin>>choice;
                    if(choice != 7){
                        cout<<"Schiorii disponibili sunt: ";
                        for (int i=0; i<schiori.size(); i++)
                            cout<<schiori[i]->getIdSchior()<<" ";
                        cout<<"Alegeti al catelea schior: ";
                        cin>>c;
                    }
                    switch(choice){
                        case(1):
                            cout<<"Introduceti numele: ";
                            cin>>STRINGNUME;
                            schiori[c-1]->setNume(STRINGNUME);
                            break;
                        case(2):
                            cout<<"Introduceti varsta: ";
                            cin>>i;
                            schiori[c-1]->setVarsta(i);
                            break;
                        case(3):
                            cout<<"Introduceti inaltimea: ";
                            cin>>f;
                            schiori[c-1]->setInaltime(f);
                            break;
                        case(4):
                            cout<<"Introduceti statusul inchirierii (0/1): ";
                            cin>>i;
                            schiori[c-1]->setInchiriat(i);
                            break;
                        case(5):
                            cout<<"Introduceti numarul perechilor inchiriate: ";
                            cin>>i;
                            schiori[c-1]->setNumarPerechiInchiriate(i);
                            break;
                        case(6):
                            cout<<"Puteti introduce ";
                            cout<<schiori[c-1]->getNumarPerechiInchiriate();
                            cout<<" marimi.\n";
                            cout<<"Introduceti id-urile: ";
                            for(int i=0; i<schiori[c-1]->getNumarPerechiInchiriate(); i++)
                                cin>>sirint[i];
                            schiori[c-1]->setIdSchiuriInchiriate(sirint);
                            break;
                        case(7):
                            break;
                    }
                    break;
                case(4):
                    cout<<"Din: \n";
                    for(int i=0; i<schiori.size(); i++)
                        cout<<schiori[i]->getIdSchior()<<" ";
                    cout<<"\nAlegeti al catelea schior va fi eliminat: ";
                    cin>>i;
                    schiori.erase(schiori.begin() + i - 1);
                    break;
                case(5):
                    cout<<"Meniu operatii\n";
                    cout<<"\t1. Cresteti varsta unui schior\n";
                    cout<<"\t2. Cresteti inaltimea unui schior\n";
                    cout<<"\t3. Reduceti varsta unui schior\n";
                    cout<<"\t4. Reduceti inaltimea unui schior\n";
                    cout<<"\t5. Afisati inaltimea recomandata pentru schiuri\n";
                    cout<<"\t6. Adaugati o pereche de schiuri la inchirierile sale\n";
                    cout<<"\t7. Reveniti la meniul anterior\n";
                    cout<<"Introduceti alegerea: ";
                    cin>>choice;
                    if (choice != 7){
                        cout<<"Din :\n";
                        for (int i=0; i<schiori.size(); i++)
                            cout<<schiori[i]->getIdSchior()<<" ";
                        cout<<endl<<"Alegeti al catelea schior: ";
                        cin>>i;
                    }
                    switch(choice){
                        case(1):
                            cout<<"Introduceti cat adaugati la varsta: \n";
                            cin>>c;
                            *schiori[i-1] = *schiori[i-1] + c;
                            break;
                        case(2):
                            cout<<"Introduceti cat adaugati la inaltime:\n";
                            cin>>d;
                            *schiori[i-1] = *schiori[i-1] + d;
                            break;
                        case(3):
                            cout<<"Varsta schiorului este "<<schiori[i-1]->getVarsta()<<".\n";
                            cout<<"Introduceti cat reduceti din varsta: ";
                            cin>>c;
                            *schiori[i-1] = *schiori[i-1] - c;
                            break;
                        case(4):
                            cout<<"Inaltimea schiorului este "<<schiori[i-1]->getInaltime()<<".\n";
                            cout<<"Introduceti cat reduceti din inaltime: ";
                            cin>>d;
                            *schiori[i-1] = *schiori[i-1] - f;
                            break;
                        case(5):
                            schiori[i-1]->schi_recomandat();
                            break;
                        case(6):
                            cout<<"Alegeti a cata pereche: \n";
                            for (int i=0; i<schiuri.size(); i++)
                                cout<<schiuri[i]->getIdSchi()<<" ";
                            cout<<endl;
                            cin>>c;
                            *schiori[i-1] = *schiori[i-1] + *schiuri[c-1];
                            break;
                        case(7):
                            break;
                    }
                    break;
                case(6):
                    break;
            }
            break;
        case(4):
            cout<<"Actiuni pentru Partie:\n";
            cout<<"\t1. Creati un obiect\n";
            cout<<"\t2. Obtineti informatii despre un obiect\n";
            cout<<"\t3. Modificati un obiect\n";
            cout<<"\t4. Eliminati un obiect\n";
            cout<<"\t5. Meniu operatii\n";
            cout<<"\t6. Reveniti la meniul anterior\n";
            cout<<"Introduceti alegerea: ";
            cin>>choice;
            switch(choice){
                case(1):
                    cout<<"Modul de creare al obiectului\n";
                    cout<<"\t1. Creati un obiect de la 0\n";
                    cout<<"\t2. Creati un obiect care sa preia datele altui obiect existent\n";
                    cout<<"\t3. Creati obiecte folosind un numar redus de informatii\n";
                    cout<<"\t4. Reveniti la meniul anterior\n";
                    cout<<"Introduceti alegerea: ";
                    cin>>choice;
                    switch(choice){
                        case(1):
                            {Partie *x = new Partie();
                            cin>>*x;
                            partii.push_back(x);
                            cout<<"Partie creata!\n";}
                            break;
                        case(2):
                            {if (partii.size() != 0){
                                cout<<"Trebuie sa alegeti un obiect existent \n";
                                for (int i=0; i<partii.size(); i++)
                                    cout<<partii[i]->getNumePartie()<<" ";  
                                cout<<endl<<"Alegeti a cata partie sa fie sursa: ";
                                cin>>c;
                                Partie *x = new Partie(*partii[c-1]);
                                partii.push_back(x);
                            }
                            else
                                cout<<"Nu sunt partii eixstente.\n";}
                            break;
                        case(3):
                            cout<<"Alegeti metoda: \n";
                            cout<<"\t1. Folosind numele si lungimea partiei.\n";
                            cout<<"\t2. Folosing doar lungimea partiei.\n";
                            cout<<"\t3. Reveniti la meniul anterior\n";
                            cout<<"Introduceti alegerea: ";
                            cin>>choice;
                            switch(choice){
                                case(1):
                                    {cout<<"Introduceti numele: ";
                                    cin>>STRINGNUME;
                                    cout<<"Introduceti lungimea partiei: ";
                                    cin>>f;
                                    Partie *x = new Partie(STRINGNUME, f);
                                    partii.push_back(x);}
                                    break;
                                case(2):
                                    {cout<<"Introduceti lungimea: ";
                                    cin>>f;
                                    Partie *x = new Partie(f);
                                    partii.push_back(x);}
                                    break;
                                case(3):
                                    break;
                            }
                                break;   
                            case(4):
                                break;
                    }
                    break;
                case(2):
                    cout<<"Meniu informatii\n";
                    cout<<"\t1. Toate informatiile despre un obiect\n";
                    cout<<"\t2. Numele partiei\n";
                    cout<<"\t3. Lungimea partiei \n";
                    cout<<"\t4. Numarul de schiori de pe partie \n";
                    cout<<"\t5. Id-urile schiorilor de pe partie \n";
                    cout<<"\t6. Reveniti la meniul anterior\n";
                    cout<<"Introduceti alegerea: ";
                    cin>>choice;
                    if(partii.size() == 0)
                        break;
                    if (choice != 6){
                        cout<<"Partiile disponibili sunt: ";
                        for (int i=0; i<partii.size(); i++)
                            cout<<partii[i]->getNumePartie()<<" ";
                        cout<<endl<<"Alegeti a cata partie: ";
                        cin>>c;
                    }
                    switch(choice){
                        case(1):
                            cout<<*partii[c-1];
                            break;
                        case(2):
                            cout<<partii[c-1]->getNumePartie()<<endl;
                            break;
                        case(3):
                            cout<<partii[c-1]->getLungimePartie()<<endl;
                            break;
                        case(4):
                            cout<<partii[c-1]->getNumarSchiori()<<endl;
                            break;
                        case(5):
                            cout<<partii[c-1]->getIdSchiori()<<endl;
                            break;
                        case(6):
                            break;
                    }
                    break;
                case(3):
                    if (partii.size() == 0){
                        cout<<"Nu sunt partii disponibile.\n";
                        break;
                    }
                    cout<<"Meniu de modificare\n";
                    cout<<"\t1. Schimbati numele\n";
                    cout<<"\t2. Schimbati lungimea partiei\n";
                    cout<<"\t3. Schimbati numarul de schiori de pe partie\n";
                    cout<<"\t4. Schimbati id-urile schiorior de pe partie\n";
                    cout<<"\t5. Reveniti la meniul anterior \n";
                    cout<<"Introduceti alegerea: ";
                    cin>>choice;
                    if (choice != 5){
                        cout<<"Partiile disponibile sunt: ";
                        for(int i=0; i<partii.size(); i++)
                            cout<<partii[i]->getNumePartie()<<" ";
                        cout<<endl<<"Alegeti a cata partie: ";
                        cin>>c;
                    }
                    switch(choice){
                        case(1):
                            cout<<"Introduceti numele: ";
                            cin>>STRINGNUME;
                            partii[c-1]->setNumePartie(STRINGNUME);
                            break;
                        case(2):
                            cout<<"Introduceti lungimea partiei: ";
                            cin>>f;
                            partii[c-1]->setLungimePartie(f);
                            break;
                        case(3):
                            cout<<"Introduceti numarul nou de schiori: ";
                            cin>>i;
                            partii[c-1]->setNumarSchiori(i);
                            break;
                        case(4):
                            cout<<"Introduceti "<<partii[c-1]->getNumarSchiori()<<" id-uri\n";
                            cout<<"Introduceti id-urile noi: ";
                            for (int i=0; i<partii[c-1]->getNumarSchiori(); i++)
                                cin>>sirint[i];
                            partii[c-1]->setIdSchiori(sirint);
                            break;
                        case(5):
                            break;
                    }       
                    break;
                case(4):
                    cout<<"Din: \n";
                    for (int i=0; i<partii.size(); i++)
                        cout<<partii[i]->getNumePartie()<<" ";
                    cout<<endl<<"Alegeti a cata partie va fi stearsa: ";
                    cin>>c;
                    partii.erase(partii.begin() + c - 1);
                    break;
                case(5):
                    cout<<"Meniu operatii\n";
                    cout<<"\t1. Cresteti lungimea partiei\n";
                    cout<<"\t2. Reduceti lungimea partiei\n";
                    cout<<"\t3. Adaugati un schior pe partie\n";
                    cout<<"\t4. Verificati timpul mediu de coborare\n";
                    cout<<"\t5. Reveniti la meniul anterior\n";
                    cout<<"Introduceti alegerea: ";
                    cin>>choice;
                    if (choice != 5){
                        for(int i=0; i<partii.size(); i++)
                            cout<<partii[i]->getNumePartie()<<" ";
                        cout<<endl<<"Alegeti pe a cata partie sa fie operatiile: ";
                        cin>>c;
                    }
                    switch(choice){
                        case(1):
                            cout<<"Introduceti lungimea pe care vreti sa o adunati: ";
                            cin>>f;
                            *partii[c-1] = *partii[c-1] + f;
                            break;
                        case(2):
                            cout<<"Partia are lungimea "<<partii[c-1]->getLungimePartie()<<endl;
                            cout<<"Cu cat vreti sa reduceti lungimea: ";
                            cin>>f;
                            *partii[c-1] = *partii[c-1] - f;
                            break;
                        case(3):
                            cout<<"Schiorii disponibili sunt: \n";
                            for(int i=0; i<schiori.size(); i++)
                                cout<<schiori[i]->getIdSchior()<<" ";
                            cout<<endl;
                            cin>>i;
                            *partii[c-1] = *partii[c-1] + *schiori[i-1];
                            break;
                        case(4):
                            partii[c-1]->timpMediuCoborare();
                            break;
                        case(5):
                            break;
                    }
                    break;
                case(6):
                    break;
            }
            break;
        case(5):
            exit(0);
            break;
        }
    }
    return 0;
}
