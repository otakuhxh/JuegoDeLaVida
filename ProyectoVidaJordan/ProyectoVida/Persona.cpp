#include <iostream>
#include <string>

using namespace std;

class Persona
{
private:
    int codigo;
    string nombre1;
    string nombre2;
    string apellido1;
    string apellido2;
    int edad;
    bool trabaja;
    float sueldo;
    int animo; // 0 feliz (casado) - 1 triste (si se muere la pareja) - 2 enojado (si el padre de un coso se casa) - 3 deprimido (no trabaja) - 4 neutro (nacen)
    int familia;
    bool sexo; //0 hombre - 1 mujer
    bool viudo;
    bool teletransportado;
    int posx;
    int posy;
    int conthijo;
    bool casado;
    bool hijo;
    int sangre; //0,2,4,6 positivos      1,3,5,7 negativo
    bool vivo;
    bool revivido;
    bool desaparece;
    string posicion;
    int resistencia;

    bool infectado;
    //lucha
    int vida;
    int ataque;
    int defensa;
    int arma;


public:
    void setVida(int valor) {
        vida = valor;
    }
    int getVida()
    {
        return vida;
    }

    void setAtaque(int valor) {
        ataque = valor;
    }
    int getAtaque()
    {
        return ataque;
    }

    void setDefensa(int valor) {
        defensa = valor;
    }
    int getDefensa()
    {
        return defensa;
    }

    void setArma(int valor) {
        arma = valor;
    }
    int getArma()
    {
        return arma;
    }

    void setCodigo(int valor) {
        codigo = valor;
    }
    int getCodigo()
    {
        return codigo;
    }

   void setConthijo(int valor) {
        conthijo = valor;
    }
    int getConthijo()
    {
        return conthijo;
    }

    void setResistencia(int valor) {
        resistencia = valor;
    }
    int getResistencia()
    {
        return resistencia;
    }
    void setNombre1(string valor) {
        nombre1 = valor;
    }
    string getNombre1()
    {
        return nombre1;
    }

    void setNombre2(string valor) {
        nombre2 = valor;
    }
    string getNombre2()
    {
        return nombre2;
    }

    void setApellido1(string valor) {
        apellido1 = valor;
    }
    string getApellido1()
    {
        return apellido1;
    }

    void setApellido2(string valor) {
        apellido2 = valor;
    }
    string getApellido2()
    {
        return apellido2;
    }

    void setEdad(int valor) {
        edad = valor;
    }
    int getEdad()
    {
        return edad;
    }

    void setTrabaja(bool valor) {
        trabaja = valor;
    }
    bool getTrabaja()
    {
        return trabaja;
    }

    void setDesaparece(bool valor) {
        desaparece = valor;
    }
    bool getDesaparece()
    {
        return desaparece;
    }

    void setViudo(bool valor) {
        viudo = valor;
    }
    bool getViudo()
    {
        return viudo;
    }

    void setInfectado(bool valor) {
        infectado = valor;
    }
    bool getInfectado()
    {
        return infectado;
    }

    void setTeletransportado(bool valor) {
        teletransportado = valor;
    }
    bool getTeletransportado()
    {
        return teletransportado;
    }

    void setSueldo(float valor) {
        sueldo = valor;
    }
    float getSueldo()
    {
        return sueldo;
    }

    void setAnimo(int valor) {
        animo = valor;
    }
    int getAnimo()
    {
        return animo;
    }

    void setSexo(bool valor) {
        sexo = valor;
    }
    bool getSexo()
    {
        return sexo;
    }

    void setHijo(bool valor) {
        hijo = valor;
    }
    bool getHijo()
    {
        return hijo;
    }

    void setPosx(int valor) {
        posx = valor;
    }
    int getPosx()
    {
        return posx;
    }

    void setPosy(int valor) {
        posy = valor;
    }
    int getPosy()
    {
        return posy;
    }

    void setCasado(bool valor) {
        casado = valor;
    }
    bool getCasado()
    {
        return casado;
    }

    void setSangre(int valor) {
        sangre = valor;
    }
    int getSangre()
    {
        return sangre;
    }

    void setFamilia(int valor) {
        familia = valor;
    }
    int getFamilia()
    {
        return familia;
    }

    void setVivo(bool valor) {
        vivo = valor;
    }
    bool getVivo()
    {
        return vivo;
    }

    void setRevivido(bool valor) {
        revivido = valor;
    }
    bool getRevivido()
    {
        return revivido;
    }

    void setPosicion(string valor) {
        posicion = valor;
    }
    string getPosicion()
    {
        return posicion;
    }


};