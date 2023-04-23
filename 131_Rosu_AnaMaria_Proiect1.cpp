#include <iostream>
#include <string.h>
using namespace std;
class Departament;

class Voluntar {
private:
  const int idVoluntar;
  static int contorId;
  char* nume;
  string prenume;
  string numeDepartament;
  int varsta;
  char sex;
  bool esteActiv;
  bool* disponibilitate; // 7 zile intr-o saptamana

public:
  // Constructori
  Voluntar();
  Voluntar(char* nume, string prenume);
  Voluntar(char* nume, string prenume, string numeDepartament);
  Voluntar(char* nume, string prenume, string numeDepartament, int varsta, char sex, bool esteActiv);
  Voluntar(char* nume, string prenume, string numeDepartament, int varsta, char sex, bool esteActiv, bool* disponibilitate);

   // Setters
  void setName(char* nume);
  void setPrenume(string prenume);
  void setNumeDepartament(string numeDepartament);
  void setVarsta(int varsta);
  void setSex(char sex);
  void setDisponibilitate(bool* disponibilitate);
  void setEsteActiv(bool esteActiv);

  // Getters
  int getIdVoluntar() const;
  const char* getNume() const;
  string getPrenume();
  string getNumeDepartament();
  int getVarsta();
  char getSex();
  const bool* getDisponibilitate() const;
  bool getEsteActiv();

  // Copy Constructor
  Voluntar(const Voluntar &v);

  // Operatori
  Voluntar& operator = (const Voluntar& v);
  friend ostream& operator <<(ostream& out, const Voluntar& v);
  friend istream& operator >>(istream& in, Voluntar& v);
  bool operator [](int);
  Voluntar& operator ++();
  Voluntar operator ++(int);
  Voluntar operator+(int);
  friend Voluntar operator +(int, const Voluntar&);
  operator string();
  operator bool();
  bool operator >(int);
  bool operator == (const Voluntar&);
  friend Departament operator +(const Voluntar& v, const Departament&);
  friend Departament operator+(const Departament&, const Voluntar& v);
  // Functii
  void afisare();
  void citire();
  int nrZileDisp();

  // Destructor
  ~Voluntar();
};

int Voluntar::contorId=100;

// Constructori
Voluntar::Voluntar():idVoluntar(contorId++){
  nume = new char[strlen("Anonim")+1];
  strcpy(nume, "Anonim");
  prenume = "Anonim";
  numeDepartament = "Necunoscut";
  varsta = 0;
  sex = 'X';
  esteActiv = false;
  disponibilitate = new bool[7];
  for(int i = 0; i < 7; i++)
    disponibilitate[i] = 0;
}

Voluntar::Voluntar(char* nume, string prenume):idVoluntar(contorId++){
  this->nume = new char[strlen(nume)+1];
  strcpy(this->nume, nume);
  this->prenume = prenume;
  numeDepartament = "Necunoscut";
  varsta = 0;
  sex = 'X';
  esteActiv = false;
  disponibilitate = new bool[7];
  for(int i = 0; i < 7; i++)
    disponibilitate[i] = 0;
}
Voluntar::Voluntar(char* nume, string prenume, string numeDepartament):idVoluntar(contorId++){
  this->nume = new char[strlen(nume)+1];
  strcpy(this->nume, nume);
  this->prenume = prenume;
  this->numeDepartament = numeDepartament;
  varsta = 0;
  sex = 'X';
  esteActiv = false;
  disponibilitate = new bool[7];
  for(int i = 0; i < 7; i++)
    disponibilitate[i] = 0;
}
Voluntar::Voluntar(char* nume, string prenume, string numeDepartament, int varsta, char sex, bool esteActiv):idVoluntar(contorId++){
  this->nume = new char[strlen(nume)+1];
  strcpy(this->nume, nume);
  this->prenume = prenume;
  this->numeDepartament = numeDepartament;
  this->varsta = varsta;
  this->sex = sex;
  this->esteActiv = esteActiv;
  disponibilitate = new bool[7];
  for(int i = 0; i < 7; i++)
    disponibilitate[i] = 0;
};
Voluntar::Voluntar(char* nume, string prenume, string numeDepartament, int varsta, char sex, bool esteActiv, bool* disponibilitate):idVoluntar(contorId++){
  this->nume = new char[strlen(nume)+1];
  strcpy(this->nume, nume);
  this->prenume = prenume;
  this->numeDepartament = numeDepartament;
  this->varsta = varsta;
  this->sex = sex;
  this->esteActiv = esteActiv;
  this->disponibilitate = new bool[7];
  for(int i=0; i < 7; i++)
    this->disponibilitate[i] = disponibilitate[i];
}

// Setters
void Voluntar::setName(char* nume){
    if(this->nume != NULL){
      delete[] this->nume;
      this->nume = NULL;
    }
    this->nume = new char[strlen(nume)+1];
    strcpy(this->nume, nume);

};
void Voluntar::setPrenume(string prenume){
  this->prenume = prenume;
};
void Voluntar::setNumeDepartament(string numeDepartament){
  this->numeDepartament = numeDepartament;
};
void Voluntar::setVarsta(int varsta){
  this->varsta = varsta;
};
void Voluntar::setSex(char sex){
  this->sex = sex;
};
void Voluntar::setDisponibilitate(bool* disponibilitate){
  if (this->disponibilitate != NULL){
    delete[] this->disponibilitate;
    this->disponibilitate = NULL;
  }
  this->disponibilitate = new bool[7];
  for(int i = 0; i < 7; i++)
    this->disponibilitate[i] = disponibilitate[i];
};
void Voluntar::setEsteActiv(bool esteActiv){
  this->esteActiv = esteActiv;
}
// Getters
int Voluntar::getIdVoluntar() const{
  return this->idVoluntar;
};
const char* Voluntar::getNume() const{
  return this->nume;
};
string Voluntar::getPrenume(){
  return this->prenume;
};
string Voluntar::getNumeDepartament(){
  return this->numeDepartament;
};
int Voluntar::getVarsta(){
  return this->varsta;
};
char Voluntar::getSex(){
  return this->sex;
};
const bool* Voluntar::getDisponibilitate() const{
  return this->disponibilitate;
}
bool Voluntar::getEsteActiv(){
  return this->esteActiv;
}
// Copy constructor
Voluntar::Voluntar(const Voluntar& v):idVoluntar(contorId++){
  this->nume = new char[strlen(v.nume)+1];
  strcpy(this->nume, v.nume);
  this->prenume = v.prenume;
  this->numeDepartament = v.numeDepartament;
  this->varsta = v.varsta;
  this->sex = v.sex;
  this->esteActiv = v.esteActiv;
  this->disponibilitate = new bool[7];
  for(int i = 0; i < 7; i++)
    this->disponibilitate[i] = v.disponibilitate[i];
}
// Operatorul =
Voluntar& Voluntar::operator=(const Voluntar& v){
  if(this!=&v){
    if(this->nume!=NULL){
      delete[] this->nume;
      this->nume = NULL;
    }
    if(this->disponibilitate!=NULL){
      delete[] this->disponibilitate;
      this->disponibilitate = NULL;
    }    
  this->nume = new char[strlen(v.nume)+1];
  strcpy(this->nume, v.nume);

  for(int i = 0; i < 7; i++)
    this->disponibilitate[i] = v.disponibilitate[i];

  this->prenume = v.prenume;
  this->numeDepartament = v.numeDepartament;
  this->varsta = v.varsta;
  this->sex = v.sex;
  this->esteActiv = v.esteActiv;
  }
  return *this;
}
// Operatorul <<
ostream& operator <<(ostream& out, const Voluntar& v){

  out<< "ID: "<< v.idVoluntar<<endl;
  out<< "Nume: "<< v.nume<<endl;
  out<< "Prenume: "<< v.prenume<<endl;
  out<< "Nume departament: "<<v.numeDepartament<<endl;
  out<< "Varsta: "<< v.varsta<<endl;
  out<< "Sex: "<< v.sex<<endl;
  out<< "Voluntar activ: "<<((v.esteActiv) ? "Da" : "Nu")<<endl;
  out<< "Disponibilitate: ";
  string zile[7] = {"Luni: ", "Marti: ", "Miercuri: ", "Joi: ", "Vineri: ", "Sambata: ","Duminica: "};
  for(int i = 0; i < 7; i++){
    out<<zile[i]<<((v.disponibilitate[i]) ? "Da" : "Nu")<<". ";
  }
  out<<endl;
  return out;
}
// Operatorul >>
istream& operator >>(istream& in, Voluntar& v){
  cout<< "Nume: ";
  char aux[100];
  in >> aux;
  if(v.nume!=NULL){
    delete[] v.nume;
    v.nume = NULL;
  }
  v.nume = new char[strlen(aux)+1];
  strcpy(v.nume, aux);

  cout<< "Prenume: ";
  in >> v.prenume;
  cout<< "Nume departament: ";
  in >> v.numeDepartament;
  cout<< "Varsta: ";
  in >> v.varsta;
  cout<< "Sex: ";
  in >> v.sex;
  cout<< "Voluntar activ [0/1]: ";
  in >> v.esteActiv;
  cout<< "Disponibilitate: "<<endl;
  if (v.disponibilitate != NULL){
    delete[] v.disponibilitate;
    v.disponibilitate = NULL;
  }
  v.disponibilitate = new bool[7];
  string zile[7] = {"Luni [0/1]: ", "Marti [0/1]: ", "Miercuri [0/1]: ", "Joi [0/1]: ", "Vineri [0/1]: ", "Sambata [0/1]: ","Duminica [0/1]: "};
  for(int i=0; i<7; i++){
    cout<<zile[i];
    in>> v.disponibilitate[i];
  }
  cout<<endl;
  return in;
}
// Operatorul []
bool Voluntar::operator [](int i){
  if(this->disponibilitate == NULL)
    throw runtime_error("Disponibilitate nu are elemente.");
  if(i<0 || i>=7)
    throw runtime_error("Index invalid. Introduceti un index intre 0 si 6.");
  else
    return this->disponibilitate[i];
}
// Operatorul ++ (pre-incrementare)
Voluntar& Voluntar::operator++(){
  this->varsta++;
  return *this;
}
// Operatorul ++ (post-incrementare)
Voluntar Voluntar::operator++(int){
  Voluntar aux(*this);
  this->varsta++;
  return aux;
}
// Operatorul + cu int
Voluntar Voluntar::operator+(int x){
  Voluntar aux(*this);
  aux.varsta += x;
  return aux;
}
Voluntar operator +(int x, const Voluntar& v){
  Voluntar aux(v);
  aux.varsta += x;
  return aux;
}
// Cast string
Voluntar::operator string(){
  return this->prenume;
}
// Cast bool
Voluntar::operator bool(){
  return this->esteActiv;
}
// Operatorul >
bool Voluntar::operator >(int x){
  return this->varsta > x;
}
// Operatorul ==
bool Voluntar::operator == (const Voluntar& v){
  return this->idVoluntar == v.idVoluntar;
}
// Afisare
void Voluntar::afisare(){
  cout<< "Afisare informatii relevante despre voluntar: "<<endl;
  cout<< "ID: "<< this->idVoluntar<<endl;
  cout<< "Nume: "<< this->nume<<endl;
  cout<< "Prenume: "<< this->prenume<<endl;
  cout<< "Nume departament: "<<this->numeDepartament<<endl;
  cout<< "Varsta: "<< this->varsta<<endl;
  cout<< "Sex: "<< this->sex<<endl;
  cout<< "Voluntar activ: "<<((this->esteActiv) ? "Da" : "Nu")<<endl;
  cout<< "Disponibilitate: ";
  string zile[7] = {"Luni: ", "Marti: ", "Miercuri: ", "Joi: ", "Vineri: ", "Sambata: ","Duminica: "};
  for(int i = 0; i < 7; i++){
    cout<<zile[i]<<((this->disponibilitate[i]) ? "Da" : "Nu")<<". ";
  }
  cout<<endl;

}
// Citire
void Voluntar::citire(){
cout<< "Nume: ";
  char aux[100];
  cin >> aux;
  if(this->nume!=NULL){
    delete[] this->nume;
  }
  this->nume = new char[strlen(aux)+1];
  strcpy(this->nume, aux);
  cout<< "Prenume: ";
  cin >> this->prenume;
  cout<< "Nume departament: ";
  cin >> this->numeDepartament;
  cout<< "Varsta: ";
  cin >> this->varsta;
  cout<< "Sex: ";
  cin >> this->sex;
  cout<< "Voluntar activ: ";
  cin >> this->esteActiv;

  cout<< "Disponibilitate: "<<endl;
  string zile[7] = {"Luni: ", "Marti: ", "Miercuri: ", "Joi: ", "Vineri: ", "Sambata: ","Duminica: "};
  for(int i=0; i<7; i++){
    cout<<zile[i];
    cin>> this->disponibilitate[i];
  }
  cout<<endl;
}
// Functionalitate: returneaza nr de zile disponibile ale voluntarului din saptamana curenta
int Voluntar::nrZileDisp(){
  int nr = 0;
  for(int i = 0; i < 7; i++)
      if(this->disponibilitate[i])
        nr+=1;
  return nr;
}

// Destructor
Voluntar::~Voluntar(){
  if(this->nume != NULL){
    delete[] this->nume;
    this->nume = NULL;
  }
  if(this->disponibilitate != NULL){
    delete[] this->disponibilitate;
    this->disponibilitate = NULL;
  }
}

class Sponsor {
private:
  string nume;
  float bugetTotal;  
  int nrSponsorizari;
  float* sponsorizari;
public:
  // Constructori
  Sponsor();
  Sponsor(string nume);
  Sponsor(string nume, float bugetTotal);
  Sponsor(string nume, float bugetTotal, int nrSponsorizari, float* sponsorizari);
  // Setters
  void setNume(string nume);
  void setBugetTotal(float bugetTotal);
  void setSponsorizari(float* sponsorizari, int nrSponsorizari);
  // Getters
  string getNume();
  float getBugetTotal();
  int getNrSponsorizari();
  const float* getSponsorizari() const;
  // Copy Constructor
  Sponsor(const Sponsor& s);
  // Operatori
  Sponsor& operator = (const Sponsor& s);
  friend ostream& operator <<(ostream& out, const Sponsor& s);
  friend istream& operator >>(istream& in, Sponsor& s);
  float operator[](int);
  Sponsor& operator ++(); //pre-incrementate
  Sponsor operator ++(int); //post-incrementare
  Sponsor operator +(float);
  friend Sponsor operator +(float, const Sponsor);
  operator float(); 
  bool operator <=(float);
  bool operator ==(const Sponsor&);
  // Functii
  // bugetul total investit
  // sustrage buget
  // Destructor
  ~Sponsor();
};
// Constructori
Sponsor::Sponsor(){
  nume = "Anonim";
  bugetTotal = 0;
  nrSponsorizari = 0;
  sponsorizari = NULL;
}
Sponsor::Sponsor(string nume){
  this->nume = nume;
  bugetTotal = 0;
  nrSponsorizari = 0;
  sponsorizari = NULL;
}
Sponsor::Sponsor(string nume, float bugetTotal){
  this->nume = nume;
  this->bugetTotal = bugetTotal;
  nrSponsorizari = 0;
  sponsorizari = NULL;
}
Sponsor::Sponsor(string nume, float bugetTotal, int nrSponsorizari, float* sponsorizari){
  this->nume = nume;
  this->bugetTotal = bugetTotal;
  this->nrSponsorizari = nrSponsorizari;
  this->sponsorizari = new float[nrSponsorizari];
  for(int i = 0; i < nrSponsorizari; i++)
    this->sponsorizari[i] = sponsorizari[i];
}
// Setters
void Sponsor::setNume(string nume){
  this->nume = nume;
};
void Sponsor::setBugetTotal(float bugetTotal){
  this->bugetTotal = bugetTotal;
};
void Sponsor::setSponsorizari(float* sponsorizari, int nrSponsorizari){
  this->nrSponsorizari = nrSponsorizari;
  if(this->sponsorizari != NULL){
    delete[] this->sponsorizari;
    this->sponsorizari = NULL;
  }
  this->sponsorizari = new float[this->nrSponsorizari];
  for(int i = 0; i < nrSponsorizari; i++)
    this->sponsorizari[i] = sponsorizari[i];
};
// Getters
string Sponsor::getNume(){
  return this->nume;
};
float Sponsor::getBugetTotal(){
  return this->bugetTotal;
};
int Sponsor::getNrSponsorizari(){
  return this->nrSponsorizari;
};
const float* Sponsor::getSponsorizari() const{
  return this->sponsorizari;
};
// Copy constructor
Sponsor::Sponsor(const Sponsor& s){
  this->nume = s.nume;
  this->bugetTotal = s.bugetTotal;
  this->nrSponsorizari = s.nrSponsorizari;
  this->sponsorizari = new float[s.nrSponsorizari];
  for(int i = 0; i < s.nrSponsorizari; i++)
    this->sponsorizari[i] = s.sponsorizari[i];
}
// Operatori
// Operatorul =
Sponsor& Sponsor::operator = (const Sponsor& s){
  if(this!=&s){
    if(this->sponsorizari != NULL){
    delete[] this->sponsorizari;
    this->sponsorizari = NULL;
  }
  this->nume = s.nume;
  this->bugetTotal = s.bugetTotal;
  this->nrSponsorizari = s.nrSponsorizari;
  this->sponsorizari = new float[s.nrSponsorizari];
  for(int i = 0; i < s.nrSponsorizari; i++)
    this->sponsorizari[i] = s.sponsorizari[i];
  }
  return *this;
};
// Operatorul <<
ostream& operator <<(ostream& out, const Sponsor& s){
  out<<"Afisare informatii relevante: "<<endl;
  out<<"Nume: "<<s.nume<<endl;
  out<<"Buget total: "<<s.bugetTotal<<endl;
  out<<"Nr de sponsorizari facute: "<<s.nrSponsorizari<<endl;
  out<<"Valoarea sponsorizarilor: ";
  for(int i = 0; i < s.nrSponsorizari; i++)
    out<<s.sponsorizari[i]<<" ";
  out<<endl;
  return out;
};
// Operatorul >>
istream& operator >>(istream& in, Sponsor& s){
  cout<<"Nume: ";
  in>>s.nume;
  cout<<"Buget total: ";
  in>>s.bugetTotal;
  cout<<"Nr de sponsorizari facute: ";
  in>>s.nrSponsorizari;
  cout<<"Valoarea sponsorizarilor: ";
  if(s.sponsorizari != NULL){
    delete[] s.sponsorizari;
    s.sponsorizari = NULL;
  }
  s.sponsorizari = new float[s.nrSponsorizari];
  for(int i = 0; i < s.nrSponsorizari; i++)
    in>>s.sponsorizari[i];
  cout<<endl;
  return in;
};
// Operatorul []
float Sponsor::operator[](int i){
  if(this->sponsorizari == NULL)
    throw runtime_error("Acest sponsor nu a facut nicio sponsorizare pana acum.");
  if(i<0 || i>=this->nrSponsorizari)
    throw runtime_error("Index invalid");
  else
    return this->sponsorizari[i];
}
// Operatorul ++(pre)
Sponsor& Sponsor::operator++(){
  this->bugetTotal++;
  return *this;
}
// Operatorul ++(post)
Sponsor Sponsor::operator++(int){
  Sponsor aux(*this);
  this->bugetTotal++;
  return aux;
}
// Operatorul + => adauga sponsorizarea de valoarea x la array ul de sponsorizari 
Sponsor Sponsor::operator+(float x){
  Sponsor aux(*this);
  if(aux.sponsorizari != NULL){
    delete[] aux.sponsorizari;
    aux.sponsorizari = NULL;
  }
  aux.nrSponsorizari++;
  aux.sponsorizari  = new float[aux.nrSponsorizari];
  for(int i = 0; i < aux.nrSponsorizari-1; i++)
    aux.sponsorizari[i] = this->sponsorizari[i];
  aux.sponsorizari[nrSponsorizari-1] = x;
  return aux;
}
// Operatorul + (comutativitate)
Sponsor operator + (float x, Sponsor s){
  Sponsor aux(s);
  if(aux.sponsorizari != NULL){
    delete[] aux.sponsorizari;
    aux.sponsorizari = NULL;
  }
  aux.nrSponsorizari++;
  aux.sponsorizari  = new float[aux.nrSponsorizari];
  for(int i = 0; i < aux.nrSponsorizari-1; i++)
    aux.sponsorizari[i] = s.sponsorizari[i];
  aux.sponsorizari[aux.nrSponsorizari-1] = x;
  return aux;
}
// Operatorul cast int
Sponsor::operator float(){
  return this->bugetTotal;
}
// Operatorul <= 
bool Sponsor::operator<=(float x){
  return this->bugetTotal <= x;
}
// Operatorul ==
bool Sponsor::operator==(const Sponsor& s){
  if(this->nume == s.nume &&
  this->bugetTotal == s.bugetTotal &&
  this->nrSponsorizari == s.nrSponsorizari &&
  this->sponsorizari == s.sponsorizari)
    return true;
  
  return false;
}
// Destructor
Sponsor::~Sponsor(){
  if(this->sponsorizari != NULL){
    delete[] this->sponsorizari;
    this->sponsorizari = NULL;
  }
}

// enum plan {
//     gold, silver, bronze
// };

class Proiect {
private:
  const int idProiect;
  static int contorId;
  // static plan planuriParteneriat[3];
  // static int nrPlanuri;
  string denumireProiect;
  int durata; //nr zile
  double costuri;
  int nrVoluntari;
  // Voluntar* listaVoluntari;
  // int nrSponsori;
  // string* sponsori;
  // plan* planuriCumparate; 
  // float* preturiPlanuri;

public:
  // Constructori
  Proiect();
  Proiect(string denumireProiect);
  Proiect(string denumireProiect, int durata, double costuri);
  Proiect(string denumireProiect, int durata, double costuri, int nrVoluntari);
  // Proiect(string denumireProiect, int durata, double costuri, int nrVoluntari, Voluntar* listaVoluntari, int nrSponsori, string* sponsori,plan* planuriCumparate, float* preturiPlanuri);
  // Setters, Getters
  int getIdProiect()const;
  void setCosturi(double costuri);
  double getCosturi();
  // Copy Constructor
  Proiect(const Proiect &p);
  // Operatori
  Proiect& operator = (const Proiect& p);
  friend ostream& operator<<(ostream& out, const Proiect& p);
  friend istream& operator>>(istream& in, Proiect& p);
  Proiect& operator++(); //pre
  Proiect operator++(int); //post
  Proiect operator +(float);
  friend Proiect operator +(float, const Proiect&);
  operator double();
  bool operator <(int);
  bool operator == (const Proiect&);
  // Functionalitate
  int nrVoluntariNecesari();
  // Destructor
  ~Proiect();

};
int Proiect::contorId = 500;
// plan Proiect::planuriParteneriat[3] = {gold, silver, bronze};
// int Proiect::nrPlanuri = 3;

// Constructori
Proiect::Proiect():idProiect(contorId++){
  denumireProiect = "Anonim";
  durata = 0;
  costuri = 0;
  nrVoluntari = 0;
  // listaVoluntari = NULL;
  // nrSponsori = 0;
  // sponsori = NULL;
  // planuriCumparate = NULL;
  // preturiPlanuri = NULL;
}
Proiect::Proiect(string denumireProiect):idProiect(contorId++){
  this->denumireProiect = denumireProiect;
  durata = 0;
  costuri = 0;
  nrVoluntari = 0;
}
Proiect::Proiect(string denumireProiect, int durata, double costuri):idProiect(contorId++){
  this->denumireProiect = denumireProiect;
  this->durata = durata;
  this->costuri = costuri;
  nrVoluntari = 0;
  // listaVoluntari = NULL;
  // nrSponsori = 0;
  // sponsori = NULL;
  // planuriCumparate = NULL;
  // preturiPlanuri = NULL;
}
Proiect::Proiect(string denumireProiect, int durata, double costuri,int nrVoluntari):idProiect(contorId++){
  this->denumireProiect = denumireProiect;
  this->durata = durata;
  this->costuri = costuri;
  this->nrVoluntari = nrVoluntari;
}
// Proiect::Proiect(string denumireProiect, int durata, double costuri, int nrVoluntari, Voluntar* listaVoluntari, int nrSponsori, string* sponsori,plan* planuriCumparate, float* preturiPlanuri){
  // this->denumireProiect = denumireProiect;
  // this->durata = durata;
  // this->costuri = costuri;

  // this->nrVoluntari = nrVoluntari;
  // this->listaVoluntari = new Voluntar[this->nrVoluntari];
  // for(int i = 0; i < this->nrVoluntari; i++)
  //   this->listaVoluntari[i] = listaVoluntari[i];

  // this->nrSponsori = nrSponsori;
  // this->sponsori = new string[this->nrSponsori];
  // for(int i = 0; i < this->nrSponsori; i++)
  //   this->sponsori[i] = sponsori[i];

  // for(int i = 0; i < this->nrSponsori; i++)
  //   this->planuriCumparate[i] = planuriCumparate[i];

  // for(int i = 0; i < nrPlanuri; i++)
  //   this->preturiPlanuri[i] = preturiPlanuri[i];
// }
// Copy constructor
Proiect::Proiect(const Proiect &p):idProiect(contorId++){
  this->denumireProiect = p.denumireProiect;
  this->durata = p.durata;
  this->costuri = p.costuri;
  this->nrVoluntari = p.nrVoluntari;
};
// Setters
void Proiect::setCosturi(double costuri){
  this->costuri = costuri;
}
// Getters
int Proiect::getIdProiect()const{
  return this->idProiect;
};
double Proiect::getCosturi(){
  return this->costuri;
}
// Operatorul =
Proiect& Proiect::operator=(const Proiect &p){
  if(this!=&p){
    this->denumireProiect = p.denumireProiect;
    this->durata = p.durata;
    this->costuri = p.costuri;
    this->nrVoluntari = p.nrVoluntari;
  }
  return *this;
}
// Operatorul <<
ostream& operator <<(ostream& out, const Proiect& p){
  out<< "ID: "<< p.idProiect<<endl;
  out<< "Denumire: "<< p.denumireProiect <<endl;
  out<< "Durata: "<< p.durata<<endl;
  out<< "Buget: "<< p.costuri<<endl;
  // if(p.nrSponsori == 0) 
  //   out<<"Proiectul nu are sponsori!";
  // else{
  //   out<< "Nr de sponsori: "<< p.nrSponsori<<endl;
  //   out<< "Sponsori: ";
  //   for(int i = 0; i < p.nrSponsori; i++)
  //     out<<p.sponsori[i];

  //   out<<"Planuri cumparate: ";
  //   for(int i = 0; i < p.nrSponsori; i++)
  //     out<<p.planuriCumparate[i];
  // }
  if(p.nrVoluntari == 0){
     out<<"Proiectul nu are voluntari!";
  }
  else
  out<< "Nr de voluntari: "<< p.nrVoluntari<<endl;
  // out<< "Voluntari: ";
  // for(int i = 0; i < p.nrVoluntari; i++)
  //   out<<p.listaVoluntari[i];
  // }

  // out<<"Preturi Planuri: ";
  // for(int i = 0; i < p.nrPlanuri; i++)
  //   out<<p.preturiPlanuri[i];

  return out;
}
// Operatorul >>
istream& operator>>(istream& in, Proiect& p){
  cout<<"Nume proiect: ";
  in >> p.denumireProiect;
  cout<<"Durata proiectului (nr. de zile): ";
  in>> p.durata;
  cout<<"Costuri: ";
  in>>p.costuri;
  cout<<"Nr de voluntari: ";
  in>>p.nrVoluntari;
  return in;
}
// Operatorul ++(pre)
Proiect& Proiect::operator++(){
  this->durata++;
  return *this;
}
// Operatorul ++(post)
Proiect Proiect::operator++(int){
  Proiect aux(*this);
  this->durata++;
  return aux;
}
// Operatorul +(int)
Proiect Proiect::operator +(float x){
  Proiect aux(*this);
  aux.costuri += x;
  return aux;
}
// Operatorul + (comutativiate)
Proiect operator +(float x, const Proiect& p){
  Proiect aux(p);
  aux.costuri += x;
  return aux;
}
// Operatorul cast double
Proiect::operator double(){
  return this->costuri;
}
// Operatorul < 
bool Proiect::operator<(int nrZile){
  return this->durata<nrZile;
}
// Operatorul ==
bool Proiect::operator==(const Proiect& p){
  if(this->denumireProiect == p.denumireProiect &&
  this->costuri == p.costuri &&
  this->durata == p.durata &&
  this->nrVoluntari == p.nrVoluntari)
    return true;
  return false;
}
// Functionalitate: nr de voluntari necesari bazat pe durata proiectului
int Proiect::nrVoluntariNecesari(){
  return this->durata*5;
}
// Destructor
Proiect::~Proiect(){
  // if(this->listaVoluntari != NULL){
  //   delete[] this->listaVoluntari;
  //   this->listaVoluntari = NULL;
  // }
  // if(this->sponsori != NULL){
  //   delete[] this->sponsori;
  //   this->sponsori = NULL;
  // }
  // if(this->planuriCumparate != NULL){
  //   delete[] this->planuriCumparate;
  //   this->planuriCumparate = NULL;
  // }
  // if(this->preturiPlanuri != NULL){
  //   delete[] this->preturiPlanuri;
  //   this->preturiPlanuri = NULL;
  // }

}
// Sponsor* sponsoriUpdated = new Sponsor[nrSponsori+1];
// if(this->sponsori != NULL){
//   for(int i=0; i < this->nrVoluntari; i++)
//     sponsoriUpdated[i] = this->sponsori[i];
  
//   delete[] this->sponsori;
// }
// sponsoriUpdated[nrVoluntari] = s;
// this->sponsori = sponsoriUpdated;


class Departament {
private:
  const int idDepartament;
  static int contorId;
  string denumire;
  string rol;
  int nrVoluntari;
  Voluntar* voluntari;
  int aniDeActivitate;
public:
  // Constructori
  Departament();
  Departament(string denumire);
  Departament(string denumire, string rol);
  Departament(string denumire, string rol, int nrVoluntari, Voluntar* voluntari, int aniDeActivitate);
  // Copy Constructor
  Departament(const Departament&);
  //Getters
  int getIdDepartament() const;
  // Operatori
  Departament& operator =(const Departament&);
  friend ostream& operator <<(ostream& out, const Departament&);
  friend istream& operator >>(istream& in, Departament&);
  Voluntar operator[](int);
  Departament& operator ++(); // pre-incrementare
  Departament operator ++(int); //post incrementare
  Departament operator +(int);
  friend Departament operator + (int x, const Departament&);
  operator int();
  bool operator >=(int);
  bool operator ==(const Departament&);
  // Functii
  int voluntariActivi();
  friend Departament operator +(const Voluntar& v, const Departament&);
  friend Departament operator+(const Departament&, const Voluntar& v);
  // Destructor
  ~Departament();
};
int Departament::contorId = 1000;
// Constructori
Departament::Departament():idDepartament(contorId++){
  denumire = "Departamentul X";
  rol = "Departamentul X isi propune sa Y";
  nrVoluntari = 0;
  voluntari = NULL;
  aniDeActivitate = 0;
}
Departament::Departament(string denumire):idDepartament(contorId++){
  this->denumire = denumire;
  rol = "Departamentul X isi propune sa Y";
  nrVoluntari = 0;
  voluntari = NULL;
  aniDeActivitate = 0;
}
Departament::Departament(string denumire, string rol):idDepartament(contorId++){
  this->denumire = denumire;
  this->rol = rol;
  nrVoluntari = 0;
  voluntari = NULL;
  aniDeActivitate = 0;
}
Departament::Departament(string denumire, string rol,  int nrVoluntari, Voluntar* voluntari, int aniDeActivitate):idDepartament(contorId++){
  this->denumire = denumire;
  this->rol = rol;
  this->nrVoluntari = nrVoluntari;
  this->voluntari = new Voluntar[nrVoluntari];
  for(int i=0; i < nrVoluntari; i++){
    this->voluntari[i] = voluntari[i];
  }
  this->aniDeActivitate = aniDeActivitate;
}
// Copy constructor
Departament::Departament(const Departament& d):idDepartament(contorId++){
  this->denumire = d.denumire;
  this->rol = d.rol;
  this->nrVoluntari = d.nrVoluntari;
  this->voluntari = new Voluntar[d.nrVoluntari];
  for(int i = 0; i < this->nrVoluntari; i++)
    this->voluntari[i] = d.voluntari[i];
  this->aniDeActivitate = d.aniDeActivitate;
};
// Getters
int Departament::getIdDepartament()const {
  return this->idDepartament;
}
// Operatorul =
Departament& Departament::operator=(const Departament& d){
  if(this!=&d){
    if(this->voluntari != NULL){
      delete[] this->voluntari;
      this->voluntari = NULL;
    }
    this->denumire = d.denumire;
    this->rol = d.rol;
    this->nrVoluntari = d.nrVoluntari;
    this->voluntari = new Voluntar[d.nrVoluntari];
    for(int i = 0; i < this->nrVoluntari; i++)
      this->voluntari[i] = d.voluntari[i];
  }
  return *this;
}
// Operatorul []
Voluntar Departament::operator [](int i){
  if(this->voluntari == NULL)
    throw runtime_error("Departamentul nu are voluntari.");
  if(i < 0 || i >= this->nrVoluntari)
    throw runtime_error("Index invalid.");
  else
    return this->voluntari[i];
}
// Operatorul <<
ostream& operator <<(ostream& out, const Departament& d){
  out<< "ID: "<< d.idDepartament<<endl;
  out<<"Nume departament: "<<d.denumire<<endl;
  out<<"Scop: "<<d.rol<<endl;
  if(d.nrVoluntari!=0){
  out<<"Nr de voluntari: "<<d.nrVoluntari<<endl;
  for(int i = 0; i < d.nrVoluntari; i++)
    out<<d.voluntari[i]<<" ";
  }
  out<<endl;
  return out;
}
// Operatorul >>
istream& operator >>(istream& in, Departament& d){
  cout<<"Nume departament: ";
  in>>d.denumire;
  cout<<"Scop: ";
  in>>d.rol;
  cout<<"Nr de voluntari: ";
  in>>d.nrVoluntari;
  if(d.voluntari != NULL){
    delete[] d.voluntari;
    d.voluntari = NULL;
  }
  for(int i = 0; i < d.nrVoluntari; i++)
    in>>d.voluntari[i];
  cout<<endl;
  return in;
}
// Operatorul ++(pre)
Departament& Departament::operator++(){
  this->aniDeActivitate++;
  return *this;
}
// Operatorul ++(post)
Departament Departament::operator++(int){
  Departament aux(*this);
  this->aniDeActivitate++;
  return aux;
}
// Operatorul +(int)
Departament Departament::operator+(int x){
  Departament aux(*this);
  aux.aniDeActivitate += x;
  return aux;
}
// Operatorul +(comutativitate)
Departament operator +(int x, const Departament& d){
  Departament aux(d);
  aux.aniDeActivitate += x;
  return aux;
}
// Operatorul cast int
Departament::operator int(){
  return this->nrVoluntari;
}
// Operatorul >=
bool Departament::operator>=(int x){
  return this->nrVoluntari >= x;
}
// Operatorul ==
bool Departament::operator==(const Departament& d){
  if(this->denumire == d.denumire &&
  this->rol == d.rol &&
  this->aniDeActivitate == d.aniDeActivitate &&
  this->nrVoluntari == d.nrVoluntari &&
  this->voluntari == d.voluntari)
    return true;
  return false;
}
// Functionalitate: returneaza nr de voluntari activi din departament
int Departament::voluntariActivi(){
  int nr = 0;
  if(this->voluntari == NULL)
   throw runtime_error("Departamentul nu are voluntari.");
  else
    for(int i = 0; i < this->nrVoluntari; i++)
      if(voluntari[i].getEsteActiv())
        nr+=1;
  return nr;
}
// Operatorul + intre departament si voluntar (adauga un voluntar la departament)
Departament operator+(const Departament& d, const Voluntar& v){ 
  Departament aux(d);

  if(aux.voluntari != NULL){
    delete[] aux.voluntari;
    aux.voluntari = NULL;
  }
  aux.voluntari = new Voluntar[aux.nrVoluntari+1];

  for(int i=0; i < d.nrVoluntari; i++)
    aux.voluntari[i] = d.voluntari[i];
    
  aux.voluntari[aux.nrVoluntari] = v;
  aux.nrVoluntari++;
  return aux;
}
Departament operator+(const Voluntar& v, const Departament& d){ 
  Departament aux(d);

  if(aux.voluntari != NULL){
    delete[] aux.voluntari;
    aux.voluntari = NULL;
  }
  aux.voluntari = new Voluntar[aux.nrVoluntari+1];

  for(int i=0; i < d.nrVoluntari; i++)
    aux.voluntari[i] = d.voluntari[i];
    
  aux.voluntari[aux.nrVoluntari] = v;
  aux.nrVoluntari++;
  return aux;
}
// Departament Departament::operator+(const Voluntar& v){ 
//   Departament aux(*this);

//   if(aux.voluntari != NULL){
//     delete[] aux.voluntari;
//     aux.voluntari = NULL;
//   }
//   aux.voluntari = new Voluntar[aux.nrVoluntari+1];

//   for(int i=0; i < this->nrVoluntari; i++)
//     aux.voluntari[i] = this->voluntari[i];
    
//   aux.voluntari[aux.nrVoluntari] = v;
//   aux.nrVoluntari++;
//   return aux;
// }
// Departament Voluntar::operator+(const Departament& d){ 
//   Departament aux(d);

//   if(aux.voluntari != NULL){
//     delete[] aux.voluntari;
//     aux.voluntari = NULL;
//   }
//   aux.voluntari = new Voluntar[aux.nrVoluntari+1];

//   for(int i=0; i < d.nrVoluntari; i++)
//     aux.voluntari[i] = d.voluntari[i];
    
//   aux.voluntari[aux.nrVoluntari] = (*this);
//   aux.nrVoluntari++;
//   return aux;
// }
// Destructor
Departament::~Departament(){
  if(this->voluntari != NULL){
    delete[] this->voluntari;
    this->voluntari = NULL;
  }
}
/*---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
int main(){
// DATE
// Voluntari
  char nume1[] = {"Rosu"};
  char nume2[] = {"Cret"};
  char nume3[] = {"Popescu"};
  Voluntar V1(nume1, "Ana", "HR", 18, 'F', true);
  Voluntar V2(nume2, "Patrick", "MF", 20, 'M', true);
  Voluntar V3(nume3, "Paul");
  int contorVoluntari = 3;
  Voluntar listaVoluntari[100] = {V1, V2, V3};
  
// Departamente
  Departament D1("HR","Noi suntem, pe scurt, \"inima Asociatiei\"! Ne asiguram de dezvoltarea si motivarea constanta a voluntarilor nostri prin organizarea activitatilor de socializare.");
  Departament D2("Design","Daca am putea descrie acest departament in doua cuvinte acelea sigur ar fi \"imaginea Asociatiei\".");
  Departament D3("Edu","Departamentul Educational se ocupa direct de intreaga interactiune atat cu studentii facultatii noastre, cat si cu elevi care si-ar dori sa urmeze FMI. In cateva cuvinte, Edu este cu si pentru studenti!");
  Departament D4("MF","Noi suntem reprezentantii externi fiind primii cu care iau legatura firmele atunci cand ne ofera sprijinul lor.");
  int contorDepartamente = 4;
  Departament listaDepartamente[10] = {D1,D2,D3,D4};

// Proiecte
  Proiect P1("Zilele ASMI", 7, 500.0, 30);
  Proiect P2("Mentoratul de o zi", 1, 100.0, 20);
  int contorProiecte = 2;
  Proiect listaProiecte[10] = {P1,P2};

// Sponsori
  Sponsor S1;
  Sponsor S2;

  system("cls");
  cout << "Bine ai venit la asociatia de voluntariat ASMI!\n\n";
  cout <<"Selecteaza tipul userului: \n1. Admin\n2. Voluntar\n3. Sponsor\n\n";

  
  int user;
  cin>>user;
  
  switch(user) {
    // ADMIN
    case 1:{
      int actiune=1;
      while(actiune){
      system("cls");
      cout<<"Buna ziua, Admin!\n\nSelectati tipul de actiune pe care doriti sa o efectuati: \n1. Afiseaza lista de voluntari\n2. Afiseaza lista de departamente\n3. Afiseaza lista de proiecte\n\n4. Creeaza voluntar\n5. Creeaza departament\n6. Creeaza proiect\n\n7. Modifica voluntar\n8. Modifica departament\n9. Modifica proiect\n\n10. Sterge voluntar\n11. Sterge departament\n12. Sterge proiect\n\n0. Exit\n\n";
      cin>>actiune;
        switch(actiune){
          case 1:{
            system("cls");
            for(int i = 0; i < contorVoluntari; i++)
              cout<<listaVoluntari[i]<<endl;
            cout<<"Doriti sa efectuati si alta actiune?[0/1] ";
            cin>>actiune;
            break;
          }
          case 2:{
            system("cls");
            for(int i = 0; i < contorDepartamente; i++)
              cout<<listaDepartamente[i]<<endl;
            cout<<"Doriti sa efectuati si alta actiune?[0/1] ";
            cin>>actiune;
            break;
          }
          case 3:{
            system("cls");
            for(int i = 0; i < contorProiecte; i++)
              cout<<listaProiecte[i]<<endl;

            cout<<"Doriti sa efectuati si alta actiune?[0/1] ";
            cin>>actiune;
            break;
          }
          case 4:{
            Voluntar V;
            cin>>V;
            listaVoluntari[contorVoluntari++] = V;
            cout<<"Voluntarul a fost creat cu succes";

            cout<<"Doriti sa efectuati si alta actiune?[0/1] ";
            cin>>actiune;
            break;
          }
          case 5:{
            Departament D;
            cin>>D;
            listaDepartamente[contorDepartamente++] = D;
            cout<<"Departamentul a fost creat cu succes";
            
            cout<<"Doriti sa efectuati si alta actiune?[0/1] ";
            cin>>actiune;
            break;
          }
          case 6:{
            Proiect P;
            cin>>P;
            listaProiecte[contorProiecte++] = P;
            cout<<"Proiectul a fost creat cu succes";

            cout<<"Doriti sa efectuati si alta actiune?[0/1] ";
            cin>>actiune;
            break;
          }
          case 7:{
          // Modifica voluntar
          cout<<"LISTA DE VOLUNTARI: \n";
          for(int i = 0; i < contorVoluntari; i++)
              cout<<listaVoluntari[i]<<endl;
          cout<<"Introduceti ID-ul voluntarului pe care vreti sa-l modificati: ";
          int input;
          cin>>input;
          bool gasit = false;
          for(int i = 0; i < contorVoluntari; i++)
            if(input == listaVoluntari[i].getIdVoluntar()){
              gasit = true;
              cin>>listaVoluntari[i];
            }
          (gasit) ? cout<<"Datele voluntarului cu ID-ul "<<input<<" au fost modificate cu succes.\n" : cout<<"ID inexistent!\n";
          cout<<"Doriti sa efectuati si alta actiune?[0/1] ";
          cin>>actiune;
          break;
          }
          case 8:{
          // Modifica departament
          cout<<"LISTA DE DEPARTAMENTE: \n";
          for(int i = 0; i < contorDepartamente; i++)
              cout<<listaDepartamente[i]<<endl;
          cout<<"Introduceti ID-ul departamentului pe care vreti sa-l modificati: ";
          int input;
          bool gasit = false;
          cin>>input;
          for(int i = 0; i < contorDepartamente; i++)
            if(input == listaDepartamente[i].getIdDepartament()){
              cin>>listaDepartamente[i];
              gasit = true;
            }
          (gasit) ? cout<<"Datele departamentului cu ID-ul "<<input<<" au fost modificate cu succes.\n" : cout<<"ID inexistent!\n";
          cout<<"Doriti sa efectuati si alta actiune?[0/1] ";
          cin>>actiune;
            break;
          }
          case 9:{
          // Modifica proiect
          cout<<"LISTA DE PROIECTE: \n";
          for(int i = 0; i < contorProiecte; i++)
              cout<<listaProiecte[i]<<endl;
          cout<<"Introduceti ID-ul proiectului pe care vreti sa-l modificati: ";
          int input;
          bool gasit=false;
          cin>>input;
          for(int i = 0; i < contorProiecte; i++)
            if(input == listaProiecte[i].getIdProiect()){
              gasit = true;
              cin>>listaProiecte[i];
            }
          (gasit) ? cout<<"Datele proiectului cu ID-ul "<<input<<" au fost modificate cu succes.\n" : cout<<"ID inexistent!\n";
          cout<<"Doriti sa efectuati si alta actiune?[0/1] ";
          cin>>actiune;
            break;
          }
          case 10:{
          // Sterge voluntar
          int input;
          cout<<"\nIntroduceti ID-ul voluntarului pe care doriti sa-l stergeti:";
          cin>>input;
          Voluntar* aux = new Voluntar[contorVoluntari];
          for(int i = 0; i < contorVoluntari; i++)
            if(input != listaVoluntari[i].getIdVoluntar())
              aux[i] = listaVoluntari[i];
          contorVoluntari--;
          for(int i = 0; i < contorVoluntari; i++)
            listaVoluntari[i] = aux[i];
          delete[] aux;

          cout<<"Ati sters cu succes voluntarul cu ID-ul "<<input<<" din asociatie!";
          cout<<"Doriti sa efectuati si alta actiune?[0/1] ";
          cin>>actiune;
          break;
          }
          case 11:{
          // Sterge departament
           int input;
          cout<<"\nIntroduceti ID-ul departamentului pe care doriti sa-l stergeti:";
          cin>>input;
          Departament* aux = new Departament[contorDepartamente];
          for(int i = 0; i < contorDepartamente; i++)
            if(input != listaDepartamente[i].getIdDepartament())
              aux[i] = listaDepartamente[i];
          contorDepartamente--;
          for(int i = 0; i < contorDepartamente; i++)
            listaDepartamente[i] = aux[i];
          delete[] aux;

          cout<<"Ati sters cu succes departamentul cu ID-ul "<<input<<"!";
          cout<<"Doriti sa efectuati si alta actiune?[0/1] ";
          cin>>actiune;
            break;
          }
          case 12:{
          // Sterge proiect
           int input;
          cout<<"\nIntroduceti ID-ul proiectului pe care doriti sa-l stergeti:";
          cin>>input;
          Proiect* aux = new Proiect[contorProiecte];
          for(int i = 0; i < contorProiecte; i++)
            if(input != listaProiecte[i].getIdProiect())
              aux[i] = listaProiecte[i];
          contorProiecte--;
          for(int i = 0; i < contorProiecte; i++)
            listaProiecte[i] = aux[i];
          delete[] aux;

          cout<<"Ati sters cu succes proiectul cu ID-ul "<<input<<" !";
          cout<<"Doriti sa efectuati si alta actiune?[0/1] ";
          cin>>actiune;
            break;
          }
        }

      }
      break;
    }
    // VOLUNTAR
    case 2: {
      int actiune=1;
      while(actiune){
        system("cls");
        cout<<"Buna ziua, voluntar!\n\nSelectati tipul de actiune pe care doriti sa o efectuati: \n1. Afiseaza proiecte\n2. Inscrie-te intr-un proiect\n\n3. Afiseaza departamente\n4. Inscrie-te intr-un departament\n\n5. Updateaza-ti datele\n6. Iesi din asociatie\n\n0. Exit\n\n";
        cin>>actiune;
        switch (actiune){
          case 1:{
            system("cls");
            for(int i = 0; i < contorProiecte; i++)
              cout<<listaProiecte[i]<<endl;

            cout<<"Doriti sa efectuati si alta actiune?[0/1] ";
            cin>>actiune;
            break;
          }
          case 2:{
            
            break;
          }
          case 3:{
            system("cls");
            for(int i = 0; i < contorDepartamente; i++)
              cout<<listaDepartamente[i]<<endl;
            cout<<"Doriti sa efectuati si alta actiune?[0/1] ";
            cin>>actiune;
            break;
          }
          case 4:{
            break;
          }
          case 5:{
            cout<<"Introduceti-va ID-ul: ";
            int input;
            cin>>input;
            bool gasit = false;
            for(int i = 0; i < contorVoluntari; i++)
              if(input == listaVoluntari[i].getIdVoluntar()){
                gasit = true;
                cin>>listaVoluntari[i];
              }
            (gasit) ? cout<<"Datele dvs "<<input<<" au fost modificate cu succes.\n" : cout<<"ID inexistent!\n";
            cout<<"Doriti sa efectuati si alta actiune?[0/1] ";
            cin>>actiune;
            break;
          }
          case 6:{
              // Sterge voluntar
              int input;
              cout<<"Sunteti sigur ca doriti sa iesiti din asociatie?[0/1]:";
              cin>>input;
              (input == 1) ? cout<<"\nIntroduceti-va ID-ul:": cout<<"Ok. Nu ati parasit asociatia.";
              if (input){
                cin>>input;
                bool gasit = false;
                Voluntar* aux = new Voluntar[contorVoluntari];
                for(int i = 0; i < contorVoluntari; i++)
                  if(input != listaVoluntari[i].getIdVoluntar())
                    aux[i] = listaVoluntari[i];
                  else gasit = true;
                contorVoluntari--;
                for(int i = 0; i < contorVoluntari; i++)
                  listaVoluntari[i] = aux[i];
                delete[] aux;

                (gasit) ? cout<<"Ati iesit din asociatie! Multumim pentru tot sprijinul acordat de-a lungul timpului!\n" : cout<<"ID inexistent!\n";
                cout<<"Doriti sa efectuati si alta actiune?[0/1] ";
                cin>>actiune;
              }
              break;
          }
        }
    }
    break;
    }
    // SPONSOR
    case 3:{
      int actiune=1;
      while(actiune){
        system("cls");
        cout<<"Buna ziua, sponsor!\n\nSelectati tipul de actiune pe care doriti sa o efectuati: \n1. Afiseaza proiecte\n2. Sponsorizeaza un proiect\n2. Afiseaza proiecte sponsorizate\n\n0. Exit\n\n";
        cin>>actiune;
        switch (actiune){
          case 1:{
            system("cls");
            for(int i = 0; i < contorProiecte; i++)
              cout<<listaProiecte[i]<<endl;

            cout<<"Doriti sa efectuati si alta actiune?[0/1] ";
            cin>>actiune;
            break;
          }
          case 2:{
            break;
          }
        }
      }
    break;
    }
    default: {
      cout<<"User invalid!";
      break;
    }
  }
  return 0;
}



// Meniu - Schita
// Selecteaza tipul userului: 1. Admin, 2. Voluntar, 3. Sponsor
//1. => CRUD voluntari, proiecte, departamente
//2. => RU proiecte, departamente (voluntarul se poate inscrie intr-un departament/proiect)
//   => UD voluntar (voluntarul poate iesi din asociatie/sa-si modifice datele)
//3. => RU proiecte (sponsorizeaza proiect)

