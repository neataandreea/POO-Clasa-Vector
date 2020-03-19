#include <iostream>
#include<stdio.h>
#include<stdlib.h>

using namespace std;
class vector
{
private:
    int *v;
    int dim;
public:
    vector(int a, int b );//initializare cu o val
    vector();//initializare    // care i faza cu constructorii dc am 2??
    ~vector();//destructor
    int operator[](int);
    friend istream& operator>> (istream &in, vector& v);
    friend ostream& operator<<(ostream &out, vector &v);
    void citire(istream & in);
    void afisare(ostream& out);
    vector (const vector &);
    vector & operator=(const vector&);
    void reinit(int n, int val );
    int sum();
    int maxi();
    void sortare();
}a;

vector:: vector (int n, int val)
{
    dim=n;
    v=new int[n];
    int i=0;
    while(i<n)
    {
        v[i]=val;
        i++;
    }
}
vector :: vector()
{
    v=new int[1];
    v[0]=0;
    dim=0;
}
vector :: ~vector ()
{
    delete [] v;
}
int vector :: operator[](int i)
{
    return v[i];
}
ostream &operator <<(ostream &out, vector&v)
{
    v.afisare(out);
    return out;
}
istream & operator>>(istream & in, vector& v)
{
    v.citire(in);
    return in;
}
void vector :: citire (istream & in)
{
    cout<<"introduceti dimensiunea vectorului:"<<endl;
    in>>dim;
    cout<<endl<<"introduceti elemntele vectorului:"<<endl;
    for (int i=0; i<dim; i++)
        in>>v[i];

}
void vector:: afisare(ostream &out)
{
    for (int i=0; i<dim; i++)
        out<<v[i]<<" ";
}

//copy constructor
vector :: vector(const vector& ob)
{
    dim=ob.dim;
    v=new int[ob.dim];
    for (int i=0;i<ob.dim;i++)
    {
        v[i]=ob.v[i];

    }
        }

 vector & vector:: operator= (const vector &ob)
{
    if(this!=&ob)
    {dim=ob.dim;
    delete [] v;
    v=new int[ob.dim];
    for (int i=0;i<ob.dim;i++)
    {
        v[i]=ob.v[i];

    }
        }
        return *this;}
void vector :: reinit(int n, int val )

    {
        dim=n;
    delete [] v;
    v=new int[n];
    for (int i=0;i<n;i++)
        v[i]=val;
    }
int vector :: sum()
{
    int suma=0;
    for(int i=0;i<dim;i++)
        suma=suma+v[i];
    return suma;
}

int vector :: maxi()
{
    int maxim=v[0];
    for (int i=1;i<dim;i++)
        if(maxim<v[i])
        maxim=v[i];
    return maxim;
}
void vector :: sortare()
{int aux;
    for(int i=0;i<dim-1;i++)
        for (int j=i+1;j<dim;j++)
        if(v[i]>v[j])
    {
        aux=v[i];
        v[i]=v[j];
        v[j]=aux;
    }
}
void menu_output()
{
    printf("\n Neata Andreea 211 - Tema 3 - Clasa 'vector': \n");
    printf("\n\t MENIU:");
    printf("\n===========================================\n");
    printf("\n");
    printf("1. Citire vector"); printf("\n");
    printf("2. Afisare vector"); printf("\n");
    printf("3. Reinitializeaza vector"); printf("\n");
    printf("4. Suma elementelor"); printf("\n");
    printf("5. Elementul maxim"); printf("\n");
    printf("6. Ordoneaza elementele"); printf("\n");
    printf("0. Iesire."); printf("\n");
}
void menu()
{
    int option;///optiunea aleasa din meniu
    option=0;

    do
    {
        menu_output();

        printf("\nIntroduceti numarul actiunii: ");
        scanf("%d", &option);

        if (option==1)
        {

            a.citire(cin);
        }
        if (option==2)
        {
            a.afisare(cout);
        }

        if (option==3)
        {
           int c,b;
            cout<<"introduceti dimensiunea vectorului:";
            cin>>c;
            cout<<endl<<"introduceti valoarea:";
            cin>>b;
            a.reinit(c,b);
        }
        if (option==4)
        {
            cout<<a.sum()<<endl;
        }
        if (option==0)
        {
            printf("\nEXIT!\n");
        }
        if (option<0||option>6)
        {
            printf("\nSelectie invalida\n");
        }
        if (option==5)
        {
            cout<<a.maxi()<<endl;
        }
        if (option==6)
        {
            a.sortare();
        }
        printf("\n");
        system("pause"); ///Pauza - Press any key to continue...
        system("cls");   ///Sterge continutul curent al consolei
    }
    while(option!=0);
}
int main()
{//apel constructor de initializare cu o valoare data
    int f,g;
    cout<<"introduceti dimensiunea";
    cin>>f;
    cout<<endl<<"introduceti valoarea";
    cin>>g;
    vector b(f,g);
    b.afisare(cout);
    //menu();
    return 0;
}
