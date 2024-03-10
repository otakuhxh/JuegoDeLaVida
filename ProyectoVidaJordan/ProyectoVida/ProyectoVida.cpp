#include <iostream>
#include "Persona.cpp"
#include <cstdlib>
#include <string>
#include <windows.h>

#include <sstream>
#include <fstream> //archivo escritura
#define NOMBRE_ARCHIVO "Libro1.csv"
#include <json/json.h>

const char FILENAME[] = "data.bin";
//puerto
#pragma comment(lib, "wsock32.lib")
#include <winsock.h>
#pragma warning(disable: 4996
//Color
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;
using namespace Json;

//variables para intercambiar datos al revivir
int codigo, edad, animo, familia2, posx, posy, conthijo2, sangre, resistencia, vida, ataque, defensa, arma;
string nombre1, nombre2, apellido1, apellido2, posicion2;
float sueldo;
bool trabaja, sexo, viudo, teletransportado, casado, hijo, infectado, vivo, revivido, desaparece;

int indicedetectado;
PCSTR ippcstr;
string IP;
int padre = 0, contadormenu = 0, madre = 0, revividostotal = 0, revividocont = 0, vivotemp = 0, reemplazado = 0, cualx=0;
int salidarevivir = 0, x = 0, y = 0, xmarco = 0, esposomuertos = 0, ymarco = 0, esposo2 = 0, contadorpuesto = 0;
int contadorasientofam, esposo = 0, porcentajeRevivir = 0, comparacion, guardado = 0;
int contarevivir = 0;
int coso1, coso2, vida1, vida2, ataque1, ataque2, defensa1, defensa2, arma1, arma2, contadorlucha = 1;
int muertosedad = 0;
int menuvar, numfami, viudos = 0, familiaMue = 0, catas = 0, VIVOS = 100, cposicion = 0;
int anterior, porcentajemuertocovid = 0, contadorcovid = 0, booleano;
int contador = 0, caso = 1, conthijo = 0, sangreM, sangreH, respuesta, indiceH, indiceM, diferenciaE;
int contfamilia = 0, familia = 0, contmuerto2=0, contmuerto=0;

string nom1, auxiliar, nom2, apel1, apel2, posicion;
Persona objpersona;
Persona cosos[600];//Se guardan

void guardadobinario() {
    //guardar los datos en el binario
    std::ofstream outputFile(FILENAME, std::ios::binary);
    if (outputFile.is_open()) {

        //Guardar el arreglo de objetos
        outputFile.write(reinterpret_cast<char*>(&contador), sizeof(contador));
        
        // Escribir el arreglo de personas en el archivo
        for (int i = 0; i <= contador; ++i) {
            
            //Codigo
            int codigoFinal = cosos[i].getCodigo();
            outputFile.write(reinterpret_cast<char*>(&codigoFinal), sizeof(codigoFinal));

            //Nombre1
            int nombre1Length = cosos[i].getNombre1().length();
            outputFile.write(reinterpret_cast<char*>(&nombre1Length), sizeof(nombre1Length));

            outputFile.write(cosos[i].getNombre1().c_str(), nombre1Length);

            //Nombre2
            int nombre2Length = cosos[i].getNombre2().length();
            outputFile.write(reinterpret_cast<char*>(&nombre2Length), sizeof(nombre2Length));

            outputFile.write(cosos[i].getNombre2().c_str(), nombre2Length);

            //Apellido1
            int apellido1Length = cosos[i].getApellido1().length();
            outputFile.write(reinterpret_cast<char*>(&apellido1Length), sizeof(apellido1Length));

            outputFile.write(cosos[i].getApellido1().c_str(), apellido1Length);

            //Apellido2
            int apellido2Length = cosos[i].getApellido2().length();
            outputFile.write(reinterpret_cast<char*>(&apellido2Length), sizeof(apellido2Length));

            outputFile.write(cosos[i].getApellido2().c_str(), apellido2Length);

            //Edad
            int edadFinal = cosos[i].getEdad();
            outputFile.write(reinterpret_cast<char*>(&edadFinal), sizeof(edadFinal));

            //Trabaja
            int trabajaFinal = cosos[i].getTrabaja();
            outputFile.write(reinterpret_cast<char*>(&trabajaFinal), sizeof(trabajaFinal));

            //Sueldo
            int sueldoFinal = cosos[i].getSueldo();
            outputFile.write(reinterpret_cast<char*>(&sueldoFinal), sizeof(sueldoFinal));

            //Animo
            int animoFinal = cosos[i].getAnimo();
            outputFile.write(reinterpret_cast<char*>(&animoFinal), sizeof(animoFinal));

            //Familia
            int familiaFinal = cosos[i].getFamilia();
            outputFile.write(reinterpret_cast<char*>(&familiaFinal), sizeof(familiaFinal));

            //Sexo
            int sexoFinal = cosos[i].getSexo();
            outputFile.write(reinterpret_cast<char*>(&sexoFinal), sizeof(sexoFinal));

            //Viudo
            int viudoFinal = cosos[i].getViudo();
            outputFile.write(reinterpret_cast<char*>(&viudoFinal), sizeof(viudoFinal));

            //Teletransportado
            int teletransportadoFinal = cosos[i].getTeletransportado();
            outputFile.write(reinterpret_cast<char*>(&teletransportadoFinal), sizeof(teletransportadoFinal));

            //Posx
            int posxFinal = cosos[i].getPosx();
            outputFile.write(reinterpret_cast<char*>(&posxFinal), sizeof(posxFinal));

            //Posy
            int posyFinal = cosos[i].getPosy();
            outputFile.write(reinterpret_cast<char*>(&posyFinal), sizeof(posyFinal));

            //Conthijo
            int conthijoFinal = cosos[i].getConthijo();
            outputFile.write(reinterpret_cast<char*>(&conthijoFinal), sizeof(conthijoFinal));

            //Casado
            int casadoFinal = cosos[i].getCasado();
            outputFile.write(reinterpret_cast<char*>(&casadoFinal), sizeof(casadoFinal));

            //Hijo
            int hijoFinal = cosos[i].getHijo();
            outputFile.write(reinterpret_cast<char*>(&hijoFinal), sizeof(hijoFinal));

            //Sangre
            int sangreFinal = cosos[i].getSangre();
            outputFile.write(reinterpret_cast<char*>(&sangreFinal), sizeof(sangreFinal));

            //Vivo
            int vivoFinal = cosos[i].getVivo();
            outputFile.write(reinterpret_cast<char*>(&vivoFinal), sizeof(vivoFinal));

            //Revivido
            int revividoFinal = cosos[i].getRevivido();
            outputFile.write(reinterpret_cast<char*>(&revividoFinal), sizeof(revividoFinal));

            //Desaparece
            int desapareceFinal = cosos[i].getDesaparece();
            outputFile.write(reinterpret_cast<char*>(&desapareceFinal), sizeof(desapareceFinal));

            //Resistencia
            int resistenciaFinal = cosos[i].getResistencia();
            outputFile.write(reinterpret_cast<char*>(&resistenciaFinal), sizeof(resistenciaFinal));

            //Posicion
            int posicionLength = cosos[i].getPosicion().length();
            outputFile.write(reinterpret_cast<char*>(&posicionLength), sizeof(posicionLength));

            outputFile.write(cosos[i].getPosicion().c_str(), posicionLength);

            //Infectado
            int infectadoFinal = cosos[i].getInfectado();
            outputFile.write(reinterpret_cast<char*>(&infectadoFinal), sizeof(infectadoFinal));

            //Vida
            int vidaFinal = cosos[i].getVida();
            outputFile.write(reinterpret_cast<char*>(&vidaFinal), sizeof(vidaFinal));

            //Ataque
            int ataqueFinal = cosos[i].getAtaque();
            outputFile.write(reinterpret_cast<char*>(&ataqueFinal), sizeof(ataqueFinal));

            //Defensa
            int defensaFinal = cosos[i].getDefensa();
            outputFile.write(reinterpret_cast<char*>(&defensaFinal), sizeof(defensaFinal));

            //Arma
            int armaFinal = cosos[i].getArma();
            outputFile.write(reinterpret_cast<char*>(&armaFinal), sizeof(armaFinal));

        }
        
        //Guardar las variables adicionales
        outputFile.write(reinterpret_cast<char*>(&revividostotal), sizeof(revividostotal));
        outputFile.write(reinterpret_cast<char*>(&familia), sizeof(familia));
        outputFile.write(reinterpret_cast<char*>(&cposicion), sizeof(cposicion));
        outputFile.write(reinterpret_cast<char*>(&VIVOS), sizeof(VIVOS));
        outputFile.close();
    }
}

int cargadabinario() {
    //Persona loadedCosos[600];
    int loadedRevividostotal;
    int loadedFamilia;
    int loadedContador;
    int loadedCposicion;
    int loadedVIVOS;

        std::ifstream inputFile(FILENAME, std::ios::binary);
        if (!inputFile.is_open()) {
            
            return 1; // Salir del programa indicando un error
        }

        try {

            //cargar las variables adicionales
            inputFile.read(reinterpret_cast<char*>(&loadedContador), sizeof(loadedContador));
            contador = loadedContador;

            for (int i = 0; i <= contador; ++i) {
                // Codigo
                int codigoFinal;
                inputFile.read(reinterpret_cast<char*>(&codigoFinal), sizeof(codigoFinal));
                cosos[i].setCodigo(codigoFinal);

                //Nombre1
                int nombre1Length;
                inputFile.read(reinterpret_cast<char*>(&nombre1Length), sizeof(nombre1Length));

                char* nombreBuffer = new char[nombre1Length + 1]; // +1 para el carácter nulo
                inputFile.read(nombreBuffer, nombre1Length);
                nombreBuffer[nombre1Length] = '\0';
                cosos[i].setNombre1(string(nombreBuffer));

                delete[] nombreBuffer;

                //Nombre2
                int nombre2Length;
                inputFile.read(reinterpret_cast<char*>(&nombre2Length), sizeof(nombre2Length));

                char* nombreBuffer1 = new char[nombre2Length + 1]; // +1 para el carácter nulo
                inputFile.read(nombreBuffer1, nombre2Length);
                nombreBuffer1[nombre2Length] = '\0';
                cosos[i].setNombre2(string(nombreBuffer1));

                delete[] nombreBuffer1;

                //Apellido1
                int apellido1Length;
                inputFile.read(reinterpret_cast<char*>(&apellido1Length), sizeof(apellido1Length));

                char* nombreBuffer2 = new char[apellido1Length + 1]; // +1 para el carácter nulo
                inputFile.read(nombreBuffer2, apellido1Length);
                nombreBuffer2[apellido1Length] = '\0';
                cosos[i].setApellido1(string(nombreBuffer2));

                delete[] nombreBuffer2;

                //Apellido2

                int apellido2Length;
                inputFile.read(reinterpret_cast<char*>(&apellido2Length), sizeof(apellido2Length));

                char* nombreBuffer3 = new char[apellido2Length + 1]; // +1 para el carácter nulo
                inputFile.read(nombreBuffer3, apellido2Length);
                nombreBuffer3[apellido2Length] = '\0';
                cosos[i].setApellido2(string(nombreBuffer3));

                delete[] nombreBuffer3;

                // Edad
                int edadFinal;
                inputFile.read(reinterpret_cast<char*>(&edadFinal), sizeof(edadFinal));
                cosos[i].setEdad(edadFinal);

                // Trabaja
                int trabajaFinal;
                inputFile.read(reinterpret_cast<char*>(&trabajaFinal), sizeof(trabajaFinal));
                cosos[i].setTrabaja(trabajaFinal);

                // Sueldo
                int sueldoFinal;
                inputFile.read(reinterpret_cast<char*>(&sueldoFinal), sizeof(sueldoFinal));
                cosos[i].setSueldo(sueldoFinal);

                // Animo
                int animoFinal;
                inputFile.read(reinterpret_cast<char*>(&animoFinal), sizeof(animoFinal));
                cosos[i].setAnimo(animoFinal);

                // Familia
                int familiaFinal;
                inputFile.read(reinterpret_cast<char*>(&familiaFinal), sizeof(familiaFinal));
                cosos[i].setFamilia(familiaFinal);

                // Sexo
                int sexoFinal;
                inputFile.read(reinterpret_cast<char*>(&sexoFinal), sizeof(sexoFinal));
                cosos[i].setSexo(sexoFinal);

                // Viudo
                int viudoFinal;
                inputFile.read(reinterpret_cast<char*>(&viudoFinal), sizeof(viudoFinal));
                cosos[i].setViudo(viudoFinal);

                // Teletransportado
                int teletransportadoFinal;
                inputFile.read(reinterpret_cast<char*>(&teletransportadoFinal), sizeof(teletransportadoFinal));
                cosos[i].setTeletransportado(teletransportadoFinal);

                // Posx
                int posxFinal;
                inputFile.read(reinterpret_cast<char*>(&posxFinal), sizeof(posxFinal));
                cosos[i].setPosx(posxFinal);

                // Posy
                int posyFinal;
                inputFile.read(reinterpret_cast<char*>(&posyFinal), sizeof(posyFinal));
                cosos[i].setPosy(posyFinal);

                // Conthijo
                int conthijoFinal;
                inputFile.read(reinterpret_cast<char*>(&conthijoFinal), sizeof(conthijoFinal));
                cosos[i].setConthijo(conthijoFinal);

                // Casado
                int casadoFinal;
                inputFile.read(reinterpret_cast<char*>(&casadoFinal), sizeof(casadoFinal));
                cosos[i].setCasado(casadoFinal);

                // Hijo
                int hijoFinal;
                inputFile.read(reinterpret_cast<char*>(&hijoFinal), sizeof(hijoFinal));
                cosos[i].setHijo(hijoFinal);

                // Sangre
                int sangreFinal;
                inputFile.read(reinterpret_cast<char*>(&sangreFinal), sizeof(sangreFinal));
                cosos[i].setSangre(sangreFinal);

                // Vivo
                int vivoFinal;
                inputFile.read(reinterpret_cast<char*>(&vivoFinal), sizeof(vivoFinal));
                cosos[i].setVivo(vivoFinal);

                // Revivido
                int revividoFinal;
                inputFile.read(reinterpret_cast<char*>(&revividoFinal), sizeof(revividoFinal));
                cosos[i].setRevivido(revividoFinal);

                // Desaparece
                int desapareceFinal;
                inputFile.read(reinterpret_cast<char*>(&desapareceFinal), sizeof(desapareceFinal));
                cosos[i].setDesaparece(desapareceFinal);

                // Resistencia
                int resistenciaFinal;
                inputFile.read(reinterpret_cast<char*>(&resistenciaFinal), sizeof(resistenciaFinal));
                cosos[i].setResistencia(resistenciaFinal);

                //Posicion
                int posicionLength;
                inputFile.read(reinterpret_cast<char*>(&posicionLength), sizeof(posicionLength));

                char* nombreBuffer4 = new char[posicionLength + 1]; // +1 para el carácter nulo
                inputFile.read(nombreBuffer4, posicionLength);
                nombreBuffer4[posicionLength] = '\0';
                cosos[i].setPosicion(string(nombreBuffer4));

                delete[] nombreBuffer4;

                // Infectado
                int infectadoFinal;
                inputFile.read(reinterpret_cast<char*>(&infectadoFinal), sizeof(infectadoFinal));
                cosos[i].setInfectado(infectadoFinal);

                // Vida
                int vidaFinal;
                inputFile.read(reinterpret_cast<char*>(&vidaFinal), sizeof(vidaFinal));
                cosos[i].setVida(vidaFinal);

                // Ataque
                int ataqueFinal;
                inputFile.read(reinterpret_cast<char*>(&ataqueFinal), sizeof(ataqueFinal));
                cosos[i].setAtaque(ataqueFinal);

                // Defensa
                int defensaFinal;
                inputFile.read(reinterpret_cast<char*>(&defensaFinal), sizeof(defensaFinal));
                cosos[i].setDefensa(defensaFinal);

                // Arma
                int armaFinal;
                inputFile.read(reinterpret_cast<char*>(&armaFinal), sizeof(armaFinal));
                cosos[i].setArma(armaFinal);
            }
            inputFile.read(reinterpret_cast<char*>(&loadedRevividostotal), sizeof(loadedRevividostotal));
            inputFile.read(reinterpret_cast<char*>(&loadedFamilia), sizeof(loadedFamilia));
            inputFile.read(reinterpret_cast<char*>(&loadedCposicion), sizeof(loadedCposicion));
            inputFile.read(reinterpret_cast<char*>(&loadedVIVOS), sizeof(loadedVIVOS));
            revividostotal = loadedRevividostotal;
            familia = loadedFamilia;
            cposicion = loadedCposicion;
            VIVOS = loadedVIVOS;
            if (inputFile.fail()) {
                throw std::runtime_error("Error al leer desde el archivo.");
            }

            inputFile.close();
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return 1; // Salir del programa indicando un error
        }
}

void gotoxy(int x, int y) {
    HANDLE hcon;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void presentacionmenu() {

    if (contador == 99 && contmuerto == 0) {
        contmuerto++;
        system("cls");
        gotoxy(0, 39); cout << "-------ESTADOS DE ANIMO------";
        gotoxy(0, 40); cout << "Azul: Feliz";
        gotoxy(0, 41); cout << "Verde: Triste";
        gotoxy(0, 42); cout << "Aguamarina: Enojado";
        gotoxy(0, 43); cout << "Rojo: Deprimido";
        gotoxy(0, 44); cout << "Purpura: Neutro";
        for (int i = 0; i < 100; i++) {

            x = cosos[i].getPosx() + 1;
            y = cosos[i].getPosy();
            if (cosos[i].getVivo() == 1) {
                if (cosos[i].getAnimo() == 0) { //Feliz
                    SetConsoleTextAttribute(hConsole, 1);
                    gotoxy((x * 3), y + 2); cout << "*";
                }
                if (cosos[i].getAnimo() == 1) { //Triste
                    SetConsoleTextAttribute(hConsole, 2);
                    gotoxy((x * 3), y + 2); cout << "*";
                }
                if (cosos[i].getAnimo() == 2) { //Enojado
                    SetConsoleTextAttribute(hConsole, 3);
                    gotoxy((x * 3), y + 2); cout << "*";
                }
                if (cosos[i].getAnimo() == 3) { //Deprimido
                    SetConsoleTextAttribute(hConsole, 4);
                    gotoxy((x * 3), y + 2); cout << "*";
                }
                if (cosos[i].getAnimo() == 4) { //neutro
                    SetConsoleTextAttribute(hConsole, 5);
                    gotoxy((x * 3), y + 2); cout << "*";
                }
                
            }
            if (cosos[i].getVivo() == 0) {
                gotoxy((x * 3), y + 2); cout << " ";
            }
            SetConsoleTextAttribute(hConsole, 7);
        }

    }
    else {
        gotoxy(0, 39); cout << "-------ESTADOS DE ANIMO------";
        gotoxy(0, 40); cout << "Azul: Feliz";
        gotoxy(0, 41); cout << "Verde: Triste";
        gotoxy(0, 42); cout << "Aguamarina: Enojado";
        gotoxy(0, 43); cout << "Rojo: Deprimido";
        gotoxy(0, 44); cout << "Purpura: Neutro";
        for (int i = 0; i <= contador; i++) {
            x = cosos[i].getPosx() + 1;
            y = cosos[i].getPosy();

            if (cosos[i].getVivo() == 1) {
      
                    if (cosos[i].getAnimo() == 0) { //Feliz
                        SetConsoleTextAttribute(hConsole, 1);
                        gotoxy((x * 3), y + 2); cout << "*";
                    }
                    if (cosos[i].getAnimo() == 1) { //Triste
                        SetConsoleTextAttribute(hConsole, 2);
                        gotoxy((x * 3), y + 2); cout << "*";
                    }
                    if (cosos[i].getAnimo() == 2) { //Enojado
                        SetConsoleTextAttribute(hConsole, 3);
                        gotoxy((x * 3), y + 2); cout << "*";
                    }
                    if (cosos[i].getAnimo() == 3) { //Deprimido
                        SetConsoleTextAttribute(hConsole, 4);
                        gotoxy((x * 3), y + 2); cout << "*";
                    }
                    if (cosos[i].getAnimo() == 4) { //neutro
                        SetConsoleTextAttribute(hConsole, 5);
                        gotoxy((x * 3), y + 2); cout << "*";
                    }
                    
                
            }
            if (cosos[i].getVivo() == 0) {
                gotoxy((x * 3), y + 2); cout << " ";
            }
            SetConsoleTextAttribute(hConsole, 7);
        }
    }
    //10 filas
    for (int i = 0; i < 16; i++) {
        if (i <= 9) {
            gotoxy(0, i + 2); cout << "0" << i;
        }
        if (i > 9) {
            gotoxy(0, i + 2); cout << i;
        }
    }

    //100 columnas
    for (int i = 0; i < 36; i++) {
        if (i <= 9) {
            gotoxy(i + 3 + (i * 2), 0); cout << "0" << i;
        }
        if (i > 9) {
            gotoxy(i + 3 + (i * 2), 0); cout << i;
        }
    }
}

int pruebaservidor() {//ENVIA
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 1);
    if (WSAStartup(DLLVersion, &wsaData) != 0) {
        gotoxy(45, 28); cout << "Error";
        exit(1);
    }

    SOCKADDR_IN addr;
    int sizeofaddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr(ippcstr); //IP DEL SERVIDOR
    addr.sin_port = htons(1111);
    addr.sin_family = AF_INET;

    SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
    bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
    listen(sListen, SOMAXCONN);

    SOCKET newConnection;

    newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr); 
   
    int contdetectado = 0;
    for (int i = 0; i <= contador; i++) {
        if ((cosos[i].getCasado()==0) && (cosos[i].getFamilia()==0) && (cosos[i].getVivo()==1)) {
            contdetectado++;
        }
    }

    booleano = rand() % (contador + 1);

    if ((cosos[booleano].getCasado() == 1) || (cosos[booleano].getFamilia() != 0) || (cosos[booleano].getVivo() == 0)) {
        do {
            booleano = rand() % (contador + 1);
        } while ((cosos[booleano].getCasado() == 1) || (cosos[booleano].getFamilia() != 0) || (cosos[booleano].getVivo() == 0));
    }
    indicedetectado = booleano;


    if (newConnection ==0) {
        gotoxy(45, 28); cout << "Error #2\n";
    }
    else {
        gotoxy(45, 28); cout << "Cliente Connected!\n";
        if (contdetectado >= 1) {
            //Enteros
            string codigo9 = to_string(cosos[indicedetectado].getCodigo());
            string edad9 = to_string(cosos[indicedetectado].getEdad());
            string animo9 = to_string(cosos[indicedetectado].getAnimo());
            string familia9 = to_string(cosos[indicedetectado].getFamilia());
            string posx9 = to_string(cosos[indicedetectado].getPosx());
            string posy9 = to_string(cosos[indicedetectado].getPosy());
            string conthijo9 = to_string(cosos[indicedetectado].getConthijo());
            string sangre9 = to_string(cosos[indicedetectado].getSangre());
            string resistencia9 = to_string(cosos[indicedetectado].getResistencia());
            string vida9 = to_string(cosos[indicedetectado].getVida());
            string ataque9 = to_string(cosos[indicedetectado].getAtaque());
            string defensa9 = to_string(cosos[indicedetectado].getDefensa());
            string arma9 = to_string(cosos[indicedetectado].getArma());
            
            //String
            string nombre9 = cosos[indicedetectado].getNombre1();
            string nombre10 = cosos[indicedetectado].getNombre2();
            string apellido9 = cosos[indicedetectado].getApellido1();
            string apellido10 = cosos[indicedetectado].getApellido2();
            string posicion9 = cosos[indicedetectado].getPosicion();
            
            //Float
            string sueldo9 = to_string(cosos[indicedetectado].getSueldo());
            
            //Bool
            int trabajaNum = cosos[indicedetectado].getTrabaja() ? 1 : 0;
            string trabaja9 = to_string(trabajaNum);
            
            int trabajaNum1 = cosos[indicedetectado].getSexo() ? 1 : 0;
            string sexo9 = to_string(trabajaNum1);
            
            int trabajaNum2 = cosos[indicedetectado].getViudo() ? 1 : 0;
            string viudo9 = to_string(trabajaNum2);
            
            int trabajaNum3 = cosos[indicedetectado].getTeletransportado() ? 1 : 0;
            string teletransportado9 = to_string(trabajaNum3);
            
            int trabajaNum4 = cosos[indicedetectado].getCasado() ? 1 : 0;
            string casado9 = to_string(trabajaNum4);
           
            int trabajaNum5 = cosos[indicedetectado].getHijo() ? 1 : 0;
            string hijo9 = to_string(trabajaNum5);
            
            int trabajaNum6 = cosos[indicedetectado].getInfectado() ? 1 : 0;
            string infectado9 = to_string(trabajaNum6);
            
            int trabajaNum7 = cosos[indicedetectado].getVivo() ? 1 : 0;
            string vivo9 = to_string(trabajaNum7);
           
            int trabajaNum8 = cosos[indicedetectado].getRevivido() ? 1 : 0;
            string revivido9 = to_string(trabajaNum8);

            //enteros
            stringstream ss;
            ss << codigo9 << "," << edad9 << "," << animo9 << "," << familia9 << "," << posx9 << "," << posy9 << "," << conthijo9 << "," << sangre9 << "," << resistencia9 << "," << vida9 <<","<<ataque9<< "," << defensa9 << "," << arma9 << "," << trabaja9 << "," << sexo9 << "," << viudo9 << "," << teletransportado9 << "," << casado9 << "," << hijo9 << "," << infectado9 << "," << vivo9 << "," << revivido9;
            string message = ss.str();

            //string
            stringstream texto;
            texto << nombre9 << "," << nombre10 << "," << apellido9 << "," << apellido10 << "," << posicion9;
            string texto2 = texto.str();
            
            send(newConnection, message.c_str(), message.size(), 0);

            send(newConnection, sueldo9.c_str(), sueldo9.size(), 0);
            send(newConnection, texto2.c_str(), texto2.size(), 0);
          
            //CAMBIA ESTADO
            VIVOS = VIVOS - 1;

            gotoxy(45, 30); cout << "Se envio el coso: " << cosos[indicedetectado].getCodigo() << " ";
            cosos[indicedetectado].setDesaparece(1);
            cosos[indicedetectado].setVivo(0);
        }
        if (contdetectado ==0) {
             gotoxy(45, 30); cout << "No hay candidato (soltero y primeros creados) para enviar";
        }
        
    }
    presentacionmenu();

    closesocket(newConnection);
    closesocket(sListen);
}

int cliente() { //RECIBE
    //WSAStartup
    
    WSAData wsaData;
    WORD DLLVersion = MAKEWORD(2, 1);
    if (WSAStartup(DLLVersion, &wsaData) != 0) {
        gotoxy(45, 28); cout << "Error";
        exit(1);
    }

    SOCKADDR_IN addr;
    int sizeofaddr = sizeof(addr);
    addr.sin_addr.s_addr = inet_addr(ippcstr); //IP DEL SERVIDOR
    addr.sin_port = htons(1111);
    addr.sin_family = AF_INET;

    SOCKET Connection = socket(AF_INET, SOCK_STREAM, NULL);
    if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
        gotoxy(45, 28); cout << "Error: failed connect to server.\n";
        return 1;
    }
    gotoxy(45, 28); cout << "Connected!\n";

        int receivedcodigo9 = 5;
        int receivededad9 = 5;
        int receivedanimo9 = 5;
        int receivedfamilia9 = 5;
        int receivedposx9 = 5;
        int receivedposy9 = 5;
        int receivedconthijo9 = 5;
        int receivedsangre9 = 5;
        int receivedresistencia9 = 5;
        int receivedvida9 = 5;
        int receivedataque9 = 5;
        int receiveddefensa9 = 5;
        int receivedarma9 = 5;
        
        float receivedsueldo9 = 5;

        int receivedtrabaja9 = 5;
        int receivedsexo9 = 5;
        int receivedviudo9 = 5;
        int receivedteletransportado9 = 5;
        int receivedcasado9 = 5;
        int receivedhijo9 = 5;
        int receivedinfectado9 = 5;
        int receivedvivo9 = 5;
        int receivedrevivido9 = 5;

    int cuenta = 0;
    char buffer[4096];
 
    int bytesReceived = recv(Connection, buffer, sizeof(buffer), 0);
    string message(buffer, bytesReceived);

        stringstream ss(message);
     
        string item;
        while (getline(ss, item, ',')) {
            int dato = stoi(item);
            cuenta++;
            if (cuenta==1) {
                receivedcodigo9 = dato;
            }
            if (cuenta == 2) {
                receivededad9 = dato;
            }
            if (cuenta == 3) {
                receivedanimo9 = dato;
            }
            if (cuenta == 4) {
                receivedfamilia9 = dato;
            }
            if (cuenta == 5) {
                receivedposx9 = dato;
            }         
            if (cuenta == 6) {
                receivedposy9 = dato;
            }
            if (cuenta == 7) {
                receivedconthijo9 = dato;
            }
            if (cuenta == 8) {
                receivedsangre9 = dato;
            }
            if (cuenta == 9) {
                receivedresistencia9 = dato;
            }
            if (cuenta == 10) {
                receivedvida9 = dato;
            }
            if (cuenta == 11) {
                receivedataque9 = dato;
            }
            if (cuenta == 12) {
                receiveddefensa9 = dato;
            }
            if (cuenta == 13) {
                receivedarma9 = dato;
            }
            //bool
            if (cuenta == 14) {
                receivedtrabaja9 = dato;
            }
            if (cuenta == 15) {
                receivedsexo9 = dato;
            }            
            if (cuenta == 16) {
                receivedviudo9 = dato;
            }
            if (cuenta == 17) {
                receivedteletransportado9 = dato;
            }
            if (cuenta == 18) {
                receivedcasado9 = dato;
            }
            if (cuenta == 19) {
                receivedhijo9 = dato;
            }
            if (cuenta == 20) {
                receivedinfectado9 = dato;
            }
            if (cuenta == 21) {
                receivedvivo9 = dato;
            }
            if (cuenta == 22) {
                receivedrevivido9 = dato;
            }
            
        }
    
    char buffer3[10];

    int bytesReceived3 = recv(Connection, buffer3, sizeof(buffer3), 0);
    string message3(buffer3, bytesReceived3);
    receivedsueldo9 = stof(message3); 

    string receivednombre9 = "a";
    string receivednombre10 = "a";
    string receivedapellido9 = "a";
    string receivedapellido10 = "a";
    string receivedposicion9 = "a";

    cuenta = 0;
    char buffer2[170];
    //ZeroMemory(buffer2, sizeof(buffer2))
    int bytesReceived2 = recv(Connection, buffer2, sizeof(buffer2), 0);
        string message2(buffer2, bytesReceived2);

        // Parsear los datos recibidos usando el delimitador
        stringstream texto(message2);
        string item2;
        while (getline(texto, item2, ',')) {
            cuenta++;
            if (cuenta == 1) {
                receivednombre9 = item2;
            }
            if (cuenta == 2) {
                receivednombre10 = item2;
            }
            if (cuenta == 3) {
                receivedapellido9 = item2;
            }
            if (cuenta == 4) {
                receivedapellido10 = item2;
            }
            if (cuenta == 5) {
                receivedposicion9 = item2;
            }
        }
    contador++;
    //Enteros
    objpersona.setCodigo(contador);
    objpersona.setEdad(receivededad9);
    objpersona.setAnimo(receivedanimo9);
    objpersona.setFamilia(receivedfamilia9);
    objpersona.setPosx(receivedposx9);
    objpersona.setPosy(receivedposy9);
    objpersona.setConthijo(receivedconthijo9);
    objpersona.setSangre(receivedsangre9);
    objpersona.setResistencia(receivedresistencia9);
    objpersona.setVida(receivedvida9);
    objpersona.setAtaque(receivedataque9);
    objpersona.setDefensa(receiveddefensa9);
    objpersona.setArma(receivedarma9);

    //String
    objpersona.setNombre1(receivednombre9);
    objpersona.setNombre2(receivednombre10);
    objpersona.setApellido1(receivedapellido9);
    objpersona.setApellido2(receivedapellido10);
    objpersona.setPosicion(receivedposicion9);

    //Float
    objpersona.setSueldo(receivedsueldo9);

    //Bool
    if (receivedtrabaja9 == 1) {
        objpersona.setTrabaja(true);
    }
    if (receivedtrabaja9 == 0) {
        objpersona.setTrabaja(false);
    }
    
    if (receivedsexo9 == 1) {
        objpersona.setSexo(true);
    }
    if (receivedsexo9 == 0) {
        objpersona.setSexo(false);
    }

    if (receivedviudo9 == 1) {
        objpersona.setViudo(true);
    }
    if (receivedviudo9 == 0) {
        objpersona.setViudo(false);
    }
    objpersona.setTeletransportado(1);

    if (receivedcasado9 == 1) {
        objpersona.setCasado(true);
    }
    if (receivedcasado9 == 0) {
        objpersona.setCasado(false);
    }

    if (receivedhijo9 == 1) {
        objpersona.setHijo(true);
    }
    if (receivedhijo9 == 0) {
        objpersona.setHijo(false);
    }
    
    if (receivedinfectado9 == 1) {
        objpersona.setInfectado(true);
    }
    if (receivedinfectado9 == 0) {
        objpersona.setInfectado(false);
    }
    objpersona.setVivo(1);

    if (receivedrevivido9 == 1) {
        objpersona.setRevivido(true);
    }
    if (receivedrevivido9 == 0) {
        objpersona.setRevivido(false);
    }
    objpersona.setDesaparece(0);

    cosos[contador] = objpersona;
    
    gotoxy(45, 30); cout << "Se creo un nuevo coso";
    gotoxy(45, 31); cout << "Codigo Antiguo: " << receivedcodigo9;
    gotoxy(45, 32); cout << "Codigo Nuevo: " << cosos[contador].getCodigo();
    gotoxy(45, 33); cout << "Posicion X: " << cosos[contador].getPosx();
    gotoxy(45, 34); cout << "Posicion Y: " << cosos[contador].getPosy();
    
    presentacionmenu();

    closesocket(Connection);
}


int servidor1() {
    gotoxy(0, 31); cout << "               ";
    gotoxy(45, 19); cout << "***Seleccione:";
    gotoxy(45, 20); cout << "1) Cliente: ";
    gotoxy(45, 21); cout << "2) Servidor: "; 
    gotoxy(45, 22); cin >> respuesta;
        while (respuesta > 2 || respuesta <= 0) {
            gotoxy(45, 22); cout<<"          ";
            gotoxy(45, 22); cin >> respuesta;
        }

        gotoxy(45, 19); cout << "                             ";
        gotoxy(45, 20); cout << "                             ";
        gotoxy(45, 21); cout << "                             ";
        gotoxy(45, 22); cout << "                             ";
        if (respuesta==1) {
            
            gotoxy(45, 19); cout << "Ingresa la IP del Servidor";
            gotoxy(45, 20); cin >> IP;
            gotoxy(45, 19); cout << "                             ";
            gotoxy(45, 20); cout << "                             ";
            ippcstr = IP.c_str();
            cliente();
        }
        if (respuesta == 2) {
            
            gotoxy(45, 19); cout << "Ingresa la IP del Servidor";
            gotoxy(45, 20); cin >> IP;
            gotoxy(45, 19); cout << "                             ";
            gotoxy(45, 20); cout << "                             ";
            ippcstr = IP.c_str();
            pruebaservidor();
        }

        return 0;
}


//Menu crear primer grupo
void menuprimer() {
    //Menu se debe presentar debajo de la presentacion de los cosos
    gotoxy(0, 0); cout << "----Hecho por Tiffany Jordan----";
    gotoxy(0, 1); cout << "---------------Menu-------------";
    gotoxy(0, 2); cout << "0) Creacion de Primer Grupo (Valido solo una vez)";
    gotoxy(0, 3); cout << "***Seleccione la opcion***";
    gotoxy(0, 4); cin >> menuvar;
    while (menuvar !=0) {
        gotoxy(0, 4); cout << "               ";
        gotoxy(0, 4); cin >> menuvar;
    }
}

void bucleposicion() {
        do {
            caso = 0;
            posicion = to_string(x) + to_string(y);

            for (int i = 0; i <contador; i++) {
                if (cosos[i].getPosicion() == posicion) {
                    caso++;
                }
            }
            if (caso == 0) {
                objpersona.setPosx(x);
                objpersona.setPosy(y);
                posicion = to_string(x) + to_string(y);
                objpersona.setPosicion(posicion);
            }
            if (caso != 0) {
                x = rand() % 36;
                y = rand() % 16;
            }
        } while (caso != 0);
    
}
void creacionprimergrupo() {

    setlocale(LC_CTYPE, "Spanish");

    ifstream archivo(NOMBRE_ARCHIVO);
    string linea;
    char delimitador = ';';
   

    for (int i = 0; i < 100; i++) {
        objpersona.setCodigo(contador);
        contador++;

        //leemos todas las lineas
        getline(archivo, linea);
        stringstream stream(linea);

        //Extrar todos los valores
        getline(stream, nom1, delimitador);
        getline(stream, nom2, delimitador);
        getline(stream, apel1, delimitador);
        getline(stream, apel2, delimitador);

        objpersona.setTeletransportado(0);
        objpersona.setHijo(1);
        objpersona.setConthijo(0);
        objpersona.setResistencia(0);
        objpersona.setDesaparece(0);
        objpersona.setFamilia(0);
        objpersona.setNombre1(nom1);
        objpersona.setNombre2(nom2);
        objpersona.setApellido1(apel1);
        objpersona.setApellido2(apel2);
        objpersona.setEdad(18+rand()%23);
        objpersona.setViudo(0);

        //lucha
        objpersona.setVida(50+rand()%76);
        objpersona.setAtaque(30+rand()%56);
        objpersona.setDefensa(20+rand()%31);
        objpersona.setArma(5+rand()%6);

        booleano = rand() % 2;
        objpersona.setTrabaja(booleano);
        objpersona.setAnimo(4);

        //Sueldo
        if (booleano == 1) {
            objpersona.setSueldo(float(10000+rand()%10000000)/100);
        }
        if (booleano == 0) {
            objpersona.setSueldo(0);
            objpersona.setAnimo(3);
        }

        
        objpersona.setSexo(rand()%2); //0 hombre 1-mujer

        x = rand() % 36;
        y = rand() % 16;

        objpersona.setCasado(0);
        objpersona.setSangre(rand()%8);
        objpersona.setVivo(1);
        objpersona.setRevivido(0);

        if (cposicion==0) {
            objpersona.setPosx(x);
            objpersona.setPosy(y);
            posicion = to_string(x) + to_string(y);
            objpersona.setPosicion(posicion);
            cposicion = 1;
        }
        if (cposicion >= 2) {
            bucleposicion();
        }

        cposicion++;

        cosos[i] = objpersona;
    }
    archivo.close();
    contador = contador - 1;
}

void creacionhijo(int familia, int indiceM, int indiceH) {
        
        //Archivo abierto
        setlocale(LC_CTYPE, "Spanish");

        ifstream archivo(NOMBRE_ARCHIVO);
        string linea;
        char delimitador = ';';

        contador++;
        VIVOS = VIVOS + 1;

        objpersona.setCodigo(contador);
        objpersona.setFamilia(familia);
        objpersona.setEdad(1);
        objpersona.setSueldo(0); //sueldo 0 porque es un niño
        objpersona.setTrabaja(0);
        objpersona.setRevivido(0);
        objpersona.setDesaparece(0);
        objpersona.setViudo(0);
        objpersona.setResistencia(0);
        objpersona.setHijo(1);
        objpersona.setAnimo(4); //nacen neutros
        objpersona.setCasado(0);
        objpersona.setSangre(rand() % 8);
        objpersona.setVivo(1);
        objpersona.setConthijo(0);
        objpersona.setTeletransportado(0);

        //lucha
        objpersona.setVida(50 + rand() % 76);
        objpersona.setAtaque(30 + rand() % 56);
        objpersona.setDefensa(20 + rand() % 31);
        objpersona.setArma(5 + rand() % 6);

        booleano = rand() % 2;
        objpersona.setSexo(booleano); //0 hombre 1-mujer

        for (int i = 0; i < contador; i++) { //el recien creado es el hijo
            //leemos todas las lineas
            getline(archivo, linea);
            stringstream stream(linea);

            //Extrar todos los valores
            getline(stream, nom1, delimitador);
            getline(stream, nom2, delimitador);
            getline(stream, apel1, delimitador);
            getline(stream, apel2, delimitador);

            //APELLIDOS
            if (indiceM==i) {
                objpersona.setApellido2(cosos[indiceM].getApellido1());
            }
            if (indiceH == i) {
                objpersona.setApellido1(cosos[indiceH].getApellido1());
            }
            if (booleano == 0) {//hombre-nombre
                objpersona.setNombre1(cosos[indiceH].getNombre1());
                objpersona.setNombre2(cosos[indiceH].getNombre2());
            }
            if (booleano == 1) {//mujer-nombre
                objpersona.setNombre1(cosos[indiceM].getNombre1());
                objpersona.setNombre2(cosos[indiceM].getNombre2());
            }
        }

        x = rand() % 36;
        y = rand() % 16;

        bucleposicion();

        cosos[contador] = objpersona;
        archivo.close();
}

void hijos() {
    //familia sigue indefinidamente

    for (int i = 1; i <= familia; i++) {

        for (int j = 0; j <= contador; j++) {

            //Mujer
            if ((cosos[j].getFamilia() == i) && (cosos[j].getSexo() == 1) && (cosos[j].getCasado() == 1) && (cosos[j].getVivo() == 1)) {
                sangreM= cosos[j].getSangre();
                indiceM = j;

                //MUJERES
                if (sangreM == 0 || sangreM == 2 || sangreM == 4 || sangreM == 6) {
                    sangreM = 11; //positivo
                }
                if (sangreM == 1 || sangreM == 3 || sangreM == 5 || sangreM == 7) {
                    sangreM = 10; //negativo
                }
            }

            //Hombre
            if ((cosos[j].getFamilia() == i) && (cosos[j].getSexo() == 0) && (cosos[j].getCasado() == 1) && (cosos[j].getVivo() == 1)) {
                sangreH = cosos[j].getSangre();
                indiceH = j;

                //HOMBRES
                if (sangreH == 0 || sangreH == 2 || sangreH == 4 || sangreH == 6) {
                    sangreH = 11;//positivo
                }
                if (sangreH == 1 || sangreH == 3 || sangreH == 5 || sangreH == 7) {
                    sangreH = 10;//negativo
                }
            }
        }
        //En el for principal se crean los hijos
        if ((sangreM == sangreH) && (cosos[indiceM].getFamilia() == cosos[indiceH].getFamilia()) && (cosos[indiceM].getFamilia() !=0)) {
            cosos[indiceM].setConthijo(cosos[indiceM].getConthijo()+1);
            cosos[indiceH].setConthijo(cosos[indiceH].getConthijo() + 1);
            creacionhijo(cosos[indiceM].getFamilia(), indiceM, indiceH);
            conthijo++;
        }
    }

    gotoxy(45, 19); cout << "Se han generado "<<conthijo<<" hijos";
    presentacionmenu();
    conthijo = 0;
}
void volversolteros() {
    viudos = 0;
    //casado a soltero, solo se da si una pareja muerta y el otro vive, si ambos murieron saldran casados pero muertos
    for (int j = 0; j <= contador; j++) {
        if ((cosos[j].getCasado() == 1) && (cosos[j].getVivo() == 0) &&(cosos[j].getDesaparece()==0)) { //casado y 
            familiaMue = cosos[j].getFamilia();


            for (int i = 0; i <= contador; i++) {
                if ((cosos[i].getSexo() != cosos[j].getSexo())&&(cosos[i].getFamilia() == familiaMue) && (cosos[i].getCasado() == 1) && (cosos[i].getVivo() == 1)) {
                    cosos[i].setCasado(0);
                    cosos[i].setHijo(1);
                    cosos[i].setViudo(1);
                    cosos[i].setAnimo(1);

                    cosos[j].setCasado(0);
                    cosos[j].setViudo(1);
                    cosos[j].setResistencia(0);
                    cosos[j].setHijo(0);

                    //No trabaja
                    viudos++;
                }//si ambos muertos no cambias sus valores
            }
        }
    }
}
void covid() {//problema infectados y resistencia cuentan mas de lo que deberian

    //Escritura
    gotoxy(0, 31); cout << "               ";
    gotoxy(45, 19); cout << "Que porcentaje quiere que se contagie de covid?";
    gotoxy(45, 20); cin >> respuesta;

    while (respuesta>101 || respuesta<0) {
        gotoxy(45, 22); cout << "Ingrese un porcentaje valido";
        gotoxy(45, 20); cout << "                 ";
        gotoxy(45, 22); cout << "                               ";
        gotoxy(45, 20); cin >> respuesta;
    }

    gotoxy(45, 19); cout << "                                                  ";
    gotoxy(45, 20); cout << "                 ";
    gotoxy(45, 22); cout << "                               ";
    
    //del porcentaje ingresado por el usuario el 20% de los infectados y que cumplan con las condiciones de esos se pueden morir
    //Contar los que cumplen con las condiciones
    if (respuesta!=100) {
        respuesta = ((VIVOS - 1) * respuesta) / 100;
    }
    if (respuesta==100) {
        respuesta = VIVOS;
    }
    //infectacion 
    for (int j = 1; j <= respuesta; j++) {
        //infectados
        booleano = rand() % (contador+1);

        if ((cosos[booleano].getInfectado() == 1) && (cosos[booleano].getVivo() == 1)) {
            do {
                booleano = rand() % (contador+1);
            } while ((cosos[booleano].getInfectado() == 1) && (cosos[booleano].getVivo() == 1) || (cosos[booleano].getInfectado() == 1) && (cosos[booleano].getVivo() == 0) || (cosos[booleano].getInfectado() == 0) && (cosos[booleano].getVivo() == 0)); //se detendra cuando me vuelva 0 y viva
            cosos[booleano].setInfectado(1);
        }

        if ((cosos[booleano].getInfectado() == 0) && (cosos[booleano].getVivo() == 1)) {
            cosos[booleano].setInfectado(1);
        }
    }
    
    //resistencia
    for (int j = 0; j <= contador; j++) {
        if (cosos[j].getInfectado() == 1) {
            anterior = cosos[j].getResistencia();
            cosos[j].setResistencia(anterior + 1);
        }
    }
    //infectados a muertos
    contadorcovid=0;
    for (int j = 0; j <= contador; j++) {
        if ((cosos[j].getEdad() > 40) && (cosos[j].getSexo() == 0) && (cosos[j].getCasado() == 0) && (cosos[booleano].getInfectado() == 1) && (cosos[booleano].getVivo() == 1)) {
            contadorcovid++;
        }
    }
    
    porcentajemuertocovid = (contadorcovid * 20)/100;

    VIVOS = VIVOS - porcentajemuertocovid;
    //muertos
    for (int i = 1; i <= porcentajemuertocovid; i++) {
        contmuerto2 = 0;
        for (int j = 0; (j <= contador) && (contmuerto2==0); j++) { //recorro todos, pero solo necesito que me cambie uno
            if ((cosos[j].getEdad() > 40) && (cosos[j].getSexo() == 0) && (cosos[j].getCasado() == 0) && (cosos[j].getInfectado() == 1) && (cosos[j].getVivo() == 1)) {
                cosos[j].setInfectado(0);
                cosos[j].setResistencia(0);
                cosos[j].setRevivido(0);
                cosos[j].setVivo(0);
                contmuerto2++;
            }
        }
    }

    //SI fallecio debe pasar su pareja a soltero
    // impresion
    presentacionmenu();
    gotoxy(45, 19); cout << "                                                                   ";
    gotoxy(45, 28); cout << "---Estadisticas de Covid---";
    gotoxy(45, 29); cout << "Poblacion: " << VIVOS;
    gotoxy(45, 30); cout << "Infectados total: "<< respuesta;
    respuesta = respuesta - contadorcovid;
 
    gotoxy(45, 31); cout << "Infectados poblacion general: " << respuesta;
    gotoxy(45, 32); cout << "Infectados vulnerables total: " << contadorcovid;
    gotoxy(45, 33); cout << "Vulnerables muertos: " << porcentajemuertocovid;
 
    //volverlo a estado sin infectar
    for (int j = 0; j <= contador; j++) {
        if (cosos[j].getInfectado() == 1) {
            cosos[j].setInfectado(0);
        }
    }

}

void destruccion() {
    gotoxy(0, 31); cout << "               ";

    //Pregunta por el desastre
    gotoxy(45, 19); cout << "Selecciona el desastre natural";
    gotoxy(45, 20); cout << "1) Meteorito";
    gotoxy(45, 21); cout << "2) Terremoto";
    gotoxy(45, 22); cin >> respuesta;

    while (respuesta >= 3 || respuesta <= 0) {
        gotoxy(45, 22); cout << "               ";
        gotoxy(45, 22); cin >> respuesta;
    }
    catas = respuesta;

    
    gotoxy(45, 19); cout << "                                                   ";
    gotoxy(45, 20); cout << "                       ";
    gotoxy(45, 21); cout << "                       ";
    gotoxy(45, 22); cout << "                       ";

    if (respuesta==1) {
        gotoxy(45, 19); cout << "Que porcentaje de mortandad para el Meteorito?";
        gotoxy(45, 20); cin >> respuesta;
    }
    if (respuesta == 2) {
        gotoxy(45, 19); cout << "Que porcentaje de mortandad para el Terremoto?";
        gotoxy(45, 20); cin >> respuesta;
    }

    
    while (respuesta>100 || respuesta<0) {
        gotoxy(45, 22); cout << "Ingrese un porcentaje valido"; 
        gotoxy(45, 22); cout << "                             ";
        gotoxy(45, 20); cout << "                              ";
        gotoxy(45, 20); cin >> respuesta;
    }

    gotoxy(45, 19); cout << "                                                      ";
    gotoxy(45, 20); cout << "                                              ";
    gotoxy(45, 22); cout << "                                                         ";
    
    //calculos - a matar
    respuesta=(VIVOS*respuesta) / 100;

    VIVOS = VIVOS - respuesta;
    //muertos
    for (int j = 1; j <= respuesta; j++) {
        booleano = rand() % (contador+1);

        if (cosos[booleano].getVivo() == 0) {
            do {
                booleano = rand() % (contador + 1);
            } while (cosos[booleano].getVivo() == 0); //se detendra cuando detecte vivo

            cosos[booleano].setVivo(0);
            cosos[booleano].setRevivido(0);
        }

        if (cosos[booleano].getVivo() == 1) {
            cosos[booleano].setVivo(0);
            cosos[booleano].setRevivido(0);
        }
    }
    
    //aumento de resistencia
    for (int j = 0; j <= contador; j++) {
        if (cosos[j].getVivo() == 1) {
            anterior = cosos[j].getResistencia();
            cosos[j].setResistencia(anterior + 1); //se aumenta la resistencia
        }
    }
    volversolteros();
    presentacionmenu();
    //Impresion
    //gotoxy(45, 11); cout << "                                                                   ";
    gotoxy(45, 28); cout << "---Estadisticas de Destruccion---";
    if (catas==1) {
        gotoxy(45, 29); cout << "Fenomeno: Meteorito";
    }
    if (catas==2) {
        gotoxy(45, 29); cout << "Fenomeno: Terremoto";
    }

    gotoxy(45, 30); cout << "Poblacion: " << VIVOS;
    gotoxy(45, 31); cout << "Muertos total: " << respuesta;
    gotoxy(45, 32); cout << "Viudos: " << viudos;
    viudos = 0;
}

void lucha() {
    //deben estar vivos
    booleano = rand() % (contador + 1);

    if (cosos[booleano].getVivo()==0) {
        do {
            booleano = rand() % (contador + 1);
        } while (cosos[booleano].getVivo() == 0);
    }
    coso1 = booleano;

    //segundo coso
    booleano = rand() % (contador + 1);

    if ((coso1==booleano) || (cosos[booleano].getVivo()==0)) {
        do {
            booleano = rand() % (contador + 1);
        } while ((cosos[booleano].getVivo() == 1) && (coso1==booleano)|| (cosos[booleano].getVivo() == 0) && (coso1 == booleano) || (cosos[booleano].getVivo() == 0) && (coso1 != booleano));
    }
    coso2 = booleano;
   
    //asignacion de valores a coso 1
    vida1 = cosos[coso1].getVida();
    ataque1 = cosos[coso1].getAtaque();
    defensa1 = cosos[coso1].getDefensa() + cosos[coso1].getResistencia();
    arma1 = cosos[coso1].getArma();
    //vida total 
    vida1 = vida1 + defensa1;
    //ataque total
    ataque1 = ataque1 + arma1;

    //asignacion de valores a coso 2
    vida2 = cosos[coso2].getVida();
    ataque2 = cosos[coso2].getAtaque();
    defensa2 = cosos[coso2].getDefensa() + cosos[coso2].getResistencia();
    arma2 = cosos[coso2].getArma();

    //vida total 
    vida2 = vida2 + defensa2;
    //ataque total
    ataque2 = ataque2 + arma2;

    do {
        //impresion
        gotoxy(45, 30); cout << "                         ";
        gotoxy(45, 31); cout << "                         ";
        gotoxy(45, 34); cout << "                         ";
        gotoxy(45, 33); cout << "                         ";
        gotoxy(45, 29); cout << "---Datos del Coso 1---";
        gotoxy(45, 30); cout << "Vida total: " << vida1;
        gotoxy(45, 31); cout << "Ataque total: " << ataque1;
        gotoxy(45, 33); cout << "---Datos del Coso 2---";
        gotoxy(45, 34); cout << "Vida total: " << vida2;
        gotoxy(45, 35); cout << "Ataque total: " << ataque2; Sleep(2500);

        if ((contadorlucha%2)!=0) {//turno impar coso 1
            //al coso 2 se le baja la vida
            vida2 = vida2 - ataque1;
            gotoxy(45, 28); cout << "Turno: Coso 1";
        }
        if ((contadorlucha % 2) == 0) {//turno par coso 2
            
            vida1 = vida1 - ataque2;
            gotoxy(45, 28); cout << "Turno: Coso 2";
        }

        contadorlucha++;
    } while ((vida1>0) && (vida2>0));//hasta que alguno muera
    
    if (vida1>vida2) {
        //aumento de resistencia
        anterior = cosos[coso1].getResistencia();
        cosos[coso1].setResistencia(anterior+1);

       cosos[coso2].setVivo(0);
       gotoxy(45, 37); cout << "Muerto: Coso 2";
       gotoxy(45, 38); cout << "Codigo: " << cosos[coso2].getCodigo();
       gotoxy(45, 34); cout << "Vida total: 000";
    }
    if (vida2>vida1) {
        //aumento de resistencia
        anterior = cosos[coso2].getResistencia();
        cosos[coso2].setResistencia(anterior + 1);

        cosos[coso1].setVivo(0);

       gotoxy(45, 37); cout << "Muerto: Coso 1";
       gotoxy(45, 38); cout << "Codigo: "<<cosos[coso1].getCodigo();
       gotoxy(45, 30); cout << "Vida total: 000";
    }
    VIVOS = VIVOS - 1;
    volversolteros();
    gotoxy(45, 40); cout << "Viudos: "<<viudos;
    presentacionmenu();
}

void tiempo() {
    //aumenta la edad 1 
    muertosedad = 0;
    gotoxy(45, 19); cout << "Cuantos años desea adelantar (max 60)?";
    gotoxy(45, 20); cin >> respuesta;

    while (respuesta > 60) {
        gotoxy(45, 20); cout << "               ";
        gotoxy(45, 20); cin >> respuesta;
    }

    gotoxy(45, 19); cout << "                                        ";
    gotoxy(45, 20); cout << "                       ";

    for (int j = 0; j <= contador; j++) {
        //si vivo le aumento la edad
        if (cosos[j].getVivo()==1) {
            anterior = cosos[j].getEdad();
            cosos[j].setEdad(anterior+respuesta);
        }
        //muerto por edad - mujer
        if ((cosos[j].getEdad()>=85) && (cosos[j].getSexo()==1) && (cosos[j].getVivo() == 1)) {
            cosos[j].setVivo(0);
            cosos[j].setTrabaja(0);
            cosos[j].setSueldo(0);
            VIVOS = VIVOS - 1;
            muertosedad++;
        }
        //muerto por edad - hombre
        if ((cosos[j].getEdad() >= 70) && (cosos[j].getSexo() == 0) && (cosos[j].getVivo() == 1)) {
            cosos[j].setVivo(0);
            cosos[j].setTrabaja(0);
            cosos[j].setSueldo(0);
            VIVOS = VIVOS - 1;
            muertosedad++;
        }
        //trabajo
        if ((cosos[j].getVivo() == 1) && (cosos[j].getEdad() >= 18) && (cosos[j].getTrabaja() == 0) && (((cosos[j].getSexo() == 0) && (cosos[j].getEdad() < 70)) || ((cosos[j].getSexo() == 1) && (cosos[j].getEdad() < 85)))) {//vivo y mayor de edad recien
            //trabaja
            booleano = rand() % 2;
            cosos[j].setTrabaja(booleano);

            //Sueldo
            if (booleano == 1) {
                cosos[j].setSueldo(float(10000 + rand() % 10000000) / 100);//el sueldo
                cosos[j].setAnimo(4);
            }
            if (booleano == 0) {
                cosos[j].setSueldo(0);//no gana nada porque no trabaja
                cosos[j].setAnimo(3);
            }
        }

    }
    gotoxy(45, 28); cout << "Muertos por edad: "<<muertosedad;
    volversolteros();
    gotoxy(45, 29); cout << "Viudos: " << viudos;

    presentacionmenu();
}

void resucitar() {
    //Escritura
    gotoxy(0, 31); cout << "               ";
    gotoxy(45, 19); cout << "Que porcentaje de muertos desea revivir?";
    gotoxy(45, 20); cin >> respuesta;

    while (respuesta > 101 || respuesta < 0) {
        gotoxy(45, 22); cout << "Ingrese un porcentaje valido";
        gotoxy(45, 20); cout << "                 ";
        gotoxy(45, 22); cout << "                               ";
        gotoxy(45, 20); cin >> respuesta;
    }
    gotoxy(45, 19); cout << "                                                      ";
    gotoxy(45, 20); cout << "                                              ";
    gotoxy(45, 22); cout << "                                                         ";

    //Resucitar
    vivotemp = 0;
    for (int j = 0; j <=contador; j++) {
        if ((cosos[j].getSexo() == 0 && cosos[j].getEdad() < 70) || (cosos[j].getSexo() == 1 && cosos[j].getEdad() < 85)) {
            if ((cosos[j].getVivo() == 0) && (cosos[j].getDesaparece() == 0)) {
                vivotemp++;
            }
        }
    }

    porcentajeRevivir = (vivotemp * respuesta)/100;//porcentaje a revivir
    revividocont = 0;
    reemplazado = 0;

    for (int j = 0; j < porcentajeRevivir; j++) {
        salidarevivir = 0;

        do {
            booleano = rand() % (contador + 1);
            if ((cosos[booleano].getSexo() == 0 && cosos[booleano].getEdad() < 70) || (cosos[booleano].getSexo() == 1 && cosos[booleano].getEdad() < 85)) {
                //si estan solteros y muertos HIJOS
                if ((cosos[booleano].getVivo() == 0) && (cosos[booleano].getViudo() == 0) && (cosos[booleano].getDesaparece() == 0)) {
                    cosos[booleano].setVivo(1);
                    cosos[booleano].setRevivido(1);
                    revividocont++;
                    salidarevivir++;
                }

                //Muerto 
                if ((cosos[booleano].getVivo() == 0) && (cosos[booleano].getHijo() == 0) && (cosos[booleano].getViudo() == 1) && (cosos[booleano].getDesaparece() == 0)) {

                    contarevivir = 0;

                    //Buscar la familia y si hay alguien del mismo genero que lo reemplazo casado y vivo
                    for (int i = 0; i <= contador; i++) {
                        if ((cosos[i].getVivo() == 1) && (cosos[i].getCasado() == 1) && (cosos[i].getHijo() == 0) && (cosos[i].getFamilia() == cosos[booleano].getFamilia()) && (cosos[i].getSexo() == cosos[booleano].getSexo()) && (cosos[i].getDesaparece() == 0)) {
                            contarevivir++;
                            esposo = i; //la pareja encontrada se la almacena
                        }
                    }

                    //marcar desaparecidos reducirlos en VIVOS
                    if (contarevivir == 1) { //la esposa se caso
                        //booleano es el esposo muerto
                        // esposo es el esposo vivo
                        reemplazado++;
                        //guardo los datos del vivo (esposo)
                        codigo = cosos[esposo].getCodigo();
                        edad = cosos[esposo].getEdad();
                        animo = cosos[esposo].getAnimo();
                        familia2 = cosos[esposo].getFamilia();
                        posx = cosos[esposo].getPosx();
                        posy = cosos[esposo].getPosy();
                        conthijo2 = cosos[esposo].getConthijo();
                        sangre = cosos[esposo].getSangre();
                        resistencia = cosos[esposo].getResistencia();
                        vida = cosos[esposo].getVida();
                        ataque = cosos[esposo].getAtaque();
                        defensa = cosos[esposo].getDefensa();
                        arma = cosos[esposo].getArma();
                        nombre1 = cosos[esposo].getNombre1();
                        nombre2 = cosos[esposo].getNombre2();
                        apellido1 = cosos[esposo].getApellido1();
                        apellido2 = cosos[esposo].getApellido2();
                        posicion2 = cosos[esposo].getPosicion();
                        sueldo = cosos[esposo].getSueldo();
                        trabaja = cosos[esposo].getTrabaja();
                        sexo = cosos[esposo].getSexo();
                        viudo = cosos[esposo].getViudo();
                        teletransportado = cosos[esposo].getTeletransportado();
                        casado = cosos[esposo].getCasado();
                        hijo = cosos[esposo].getHijo();
                        infectado = cosos[esposo].getInfectado();
                        vivo = cosos[esposo].getVivo();
                        revivido = cosos[esposo].getRevivido();
                        desaparece = cosos[esposo].getDesaparece();

                        //reemplazo los datos del vivo (esposo), lo paso a muerto
                        cosos[esposo].setCodigo(cosos[booleano].getCodigo());
                        cosos[esposo].setEdad(cosos[booleano].getEdad());
                        cosos[esposo].setAnimo(cosos[booleano].getAnimo());
                        cosos[esposo].setFamilia(cosos[booleano].getFamilia());

                        cosos[esposo].setPosx(cosos[booleano].getPosx());
                        cosos[esposo].setPosy(cosos[booleano].getPosy());
                        cosos[esposo].setConthijo(cosos[booleano].getConthijo());
                        cosos[esposo].setSangre(cosos[booleano].getSangre());

                        cosos[esposo].setResistencia(cosos[booleano].getResistencia());
                        cosos[esposo].setVida(cosos[booleano].getVida());
                        cosos[esposo].setAtaque(cosos[booleano].getAtaque());
                        cosos[esposo].setDefensa(cosos[booleano].getDefensa());

                        cosos[esposo].setArma(cosos[booleano].getArma());
                        cosos[esposo].setNombre1(cosos[booleano].getNombre1());
                        cosos[esposo].setNombre2(cosos[booleano].getNombre2());
                        cosos[esposo].setApellido1(cosos[booleano].getApellido1());

                        cosos[esposo].setApellido2(cosos[booleano].getApellido2());
                        cosos[esposo].setPosicion(cosos[booleano].getPosicion());
                        cosos[esposo].setSueldo(cosos[booleano].getSueldo());
                        cosos[esposo].setTrabaja(cosos[booleano].getTrabaja());

                        cosos[esposo].setSexo(cosos[booleano].getSexo());
                        cosos[esposo].setViudo(cosos[booleano].getViudo());
                        cosos[esposo].setTeletransportado(cosos[booleano].getTeletransportado());
                        cosos[esposo].setCasado(cosos[booleano].getCasado());

                        cosos[esposo].setHijo(cosos[booleano].getHijo());
                        cosos[esposo].setInfectado(cosos[booleano].getInfectado());
                        cosos[esposo].setVivo(cosos[booleano].getVivo());
                        cosos[esposo].setRevivido(cosos[booleano].getRevivido());

                        cosos[esposo].setDesaparece(1);

                        //reemplazo los datos del muerto (booleano), lo paso a vivo
                        cosos[booleano].setCodigo(codigo);
                        cosos[booleano].setEdad(edad);
                        cosos[booleano].setAnimo(animo);
                        cosos[booleano].setFamilia(familia2);

                        cosos[booleano].setPosx(posx);
                        cosos[booleano].setPosy(posy);
                        cosos[booleano].setConthijo(conthijo2);
                        cosos[booleano].setSangre(sangre);

                        cosos[booleano].setResistencia(resistencia);
                        cosos[booleano].setVida(vida);
                        cosos[booleano].setAtaque(ataque);
                        cosos[booleano].setDefensa(defensa);

                        cosos[booleano].setArma(arma);
                        cosos[booleano].setNombre1(nombre1);
                        cosos[booleano].setNombre2(nombre2);
                        cosos[booleano].setApellido1(apellido1);

                        cosos[booleano].setApellido2(apellido2);
                        cosos[booleano].setPosicion(posicion2);
                        cosos[booleano].setSueldo(sueldo);
                        cosos[booleano].setTrabaja(trabaja);

                        cosos[booleano].setSexo(sexo);
                        cosos[booleano].setViudo(viudo);
                        cosos[booleano].setTeletransportado(teletransportado);
                        cosos[booleano].setCasado(casado);

                        cosos[booleano].setHijo(hijo);
                        cosos[booleano].setInfectado(infectado);
                        cosos[booleano].setVivo(vivo);
                        cosos[booleano].setRevivido(1);

                        cosos[booleano].setDesaparece(desaparece);

                        //datos de la mujer

                        //busca a la esposa

                        for (int i = 0; i <= contador; i++) {
                            if ((cosos[i].getVivo() == 1) && (cosos[i].getFamilia() == cosos[booleano].getFamilia()) && (cosos[i].getSexo() != cosos[booleano].getSexo()) && (cosos[i].getViudo() == 1) && (cosos[i].getDesaparece() == 0)) {
                                esposo2 = i;
                            }
                        }
                        //no se le cambia nada porq esta casada, solo la parte de viuda

                        //busca cuantos esposo muertos tiene a parte del que recien revivio
                        esposomuertos = 0;
                        for (int i = 0; i <= contador; i++) {
                            if ((cosos[i].getVivo() == 0) && (cosos[esposo2].getFamilia() == cosos[i].getFamilia()) && (cosos[i].getSexo() != cosos[esposo2].getSexo()) && (cosos[i].getViudo() == 1) && (cosos[i].getDesaparece() == 0)) {
                                esposomuertos++;
                            }
                        }
                        if (esposomuertos == 0) {
                            cosos[esposo2].setViudo(0);

                        }
                        if (esposomuertos >= 1) {
                            cosos[esposo2].setViudo(1);
                        }

                    }

                    if (contarevivir == 0) {//la esposa nunca se caso
                        //esposo revivido
                        cosos[booleano].setVivo(1);
                        cosos[booleano].setRevivido(1);
                        cosos[booleano].setCasado(1);
                        cosos[booleano].setHijo(0);
                        cosos[booleano].setViudo(0);
                        cosos[booleano].setAnimo(0);
                        //viudo cero

                        //busca a la esposa
                        for (int i = 0; i <= contador; i++) {
                            if ((cosos[i].getVivo() == 1) && (cosos[i].getFamilia() == cosos[booleano].getFamilia()) && (cosos[i].getSexo() != cosos[booleano].getSexo()) && (cosos[i].getViudo() == 1) && (cosos[i].getDesaparece() == 0)) {
                                esposo = i;
                            }
                        }

                        //busca cuantos esposo muertos tiene a parte del que recien revivio
                        esposomuertos = 0;
                        for (int i = 0; i <= contador; i++) {
                            if ((cosos[i].getVivo() == 0) && (cosos[esposo].getFamilia() == cosos[i].getFamilia()) && (cosos[i].getSexo() != cosos[esposo].getSexo()) && (cosos[i].getViudo() == 1) && (cosos[i].getDesaparece() == 0)) {
                                esposomuertos++;
                            }
                        }
                        //esposa casado ahora con el revivido
                        cosos[esposo].setCasado(1);
                        cosos[esposo].setHijo(0);
                        cosos[esposo].setAnimo(0);

                        if (esposomuertos == 0) {
                            cosos[esposo].setViudo(0);
                        }
                        if (esposomuertos >= 1) {
                            cosos[esposo].setViudo(1);
                        }
                        VIVOS++;
                    }
                    revividocont++;
                    salidarevivir++;
                }
            }
         } while (salidarevivir < 1); //se detendra cuando detecte 1
            revividostotal++;
    }
    
    gotoxy(45, 28); cout << "---Estadisticas de Revividos---";
    gotoxy(45, 29); cout << "Revividos: "<<revividocont;
    gotoxy(45, 30); cout << "Reemplazados: " << reemplazado;
    presentacionmenu();
}
void asientosPos(int contadorpuesto) {
    //fila 0
    if (contadorpuesto <= 16){
        xmarco = contadorpuesto;
        ymarco = 0;
    }
    //fila 1
    if ((contadorpuesto >= 17) && (contadorpuesto <=33)) {
        xmarco = contadorpuesto - 17;
        ymarco = 1;
    }
    //fila 2
    if ((contadorpuesto >= 34) && (contadorpuesto <= 50)) {
        xmarco = contadorpuesto - 34;
        ymarco = 2;
    }
    //fila 3
    if ((contadorpuesto >= 51) && (contadorpuesto <= 67)) {
        xmarco = contadorpuesto - 51;
        ymarco = 3;
    }
    //fila 4
    if ((contadorpuesto >= 68) && (contadorpuesto <= 84)) {
        xmarco = contadorpuesto - 68;
        ymarco = 4;
    }
    //fila 5
    if ((contadorpuesto >= 85) && (contadorpuesto <= 101)) {
        xmarco = contadorpuesto - 85;
        ymarco = 5;
    }
    //fila 6
    if ((contadorpuesto >= 102) && (contadorpuesto <= 118)) {
        xmarco = contadorpuesto - 102;
        ymarco = 6;
    }
    //fila 7
    if ((contadorpuesto >= 119) && (contadorpuesto <= 135)) {
        xmarco = contadorpuesto - 119;
        ymarco = 7;
    }
    //fila 8
    if ((contadorpuesto >= 136) && (contadorpuesto <= 152)) {
        xmarco = contadorpuesto - 136;
        ymarco = 8;
    }
    //fila 9
    if ((contadorpuesto >= 153) && (contadorpuesto <= 169)) {
        xmarco = contadorpuesto - 153;
        ymarco = 9;
    }
    //fila 10
    if ((contadorpuesto >= 170) && (contadorpuesto <= 186)) {
        xmarco = contadorpuesto - 170;
        ymarco = 10;
    }
    //fila 11
    if ((contadorpuesto >= 187) && (contadorpuesto <= 203)) {
        xmarco = contadorpuesto - 187;
        ymarco = 11;
    }
    //fila 12
    if ((contadorpuesto >= 204) && (contadorpuesto <= 220)) {
        xmarco = contadorpuesto - 204;
        ymarco = 12;
    }
    //fila 13
    if ((contadorpuesto >= 221) && (contadorpuesto <= 237)) {
        xmarco = contadorpuesto - 221;
        ymarco = 13;
    }
    //fila 14
    if ((contadorpuesto >= 238) && (contadorpuesto <= 254)) {
        xmarco = contadorpuesto - 238;
        ymarco = 14;
    }
}
void cine() {
    //limpieza
    system("cls");
    gotoxy(10, 1); cout << "--------------------Pantalla----------------------";

    //asientos fila
    for (int j = 0; j <= 14; j++) {
        for (int i = 0; i <= 32; i++) { //asientos columna

            gotoxy((i * 2) + 5, j + 3); cout << "-";
        }
    }
    ymarco = 0;
    xmarco = 0; //contador de asiento
    contadorpuesto = 0;
    //Seleccion de familia
    //familia 0, solteros

    Value personasObj; //JSON

    for (int j = 0; j <= contador; j++) {
        if ((cosos[j].getVivo() == 1) && (cosos[j].getFamilia() == 0)) {

            booleano = rand() % 2; //si 0 no sale, 1 va al cine

            if (booleano == 1) {
                //decisiones por asiento 
                Value persona;
                persona.append("Codigo: " + to_string(cosos[j].getCodigo()));
                persona.append("Nombre1: " + cosos[j].getNombre1());
                persona.append("Nombre2: " + cosos[j].getNombre2());
                persona.append("Apellido1: " + cosos[j].getApellido1());
                persona.append("Apellido2: " + cosos[j].getApellido2());

                asientosPos(contadorpuesto);
                persona.append("Posicion Fila: " + to_string(ymarco));
                persona.append("Posicion Columna: " + to_string(xmarco * 2));
                persona.append("Estado: Solteros");
                personasObj.append(persona);

                if (cosos[booleano].getAnimo() == 0) { //Feliz
                    SetConsoleTextAttribute(hConsole, 1);
                    gotoxy((xmarco * 4 + 5), (ymarco + 3)); cout << "*";
                }
                if (cosos[booleano].getAnimo() == 1) { //Triste
                    SetConsoleTextAttribute(hConsole, 2);
                    gotoxy((xmarco * 4 + 5), (ymarco + 3)); cout << "*";
                }
                if (cosos[booleano].getAnimo() == 2) { //Enojado
                    SetConsoleTextAttribute(hConsole, 3);
                    gotoxy((xmarco * 4 + 5), (ymarco + 3)); cout << "*";
                }
                if (cosos[booleano].getAnimo() == 3) { //Deprimido
                    SetConsoleTextAttribute(hConsole, 4);
                    gotoxy((xmarco * 4 + 5), (ymarco + 3)); cout << "*";
                }
                if (cosos[booleano].getAnimo() == 4) { //neutro
                    SetConsoleTextAttribute(hConsole, 5);
                    gotoxy((xmarco * 4 + 5), (ymarco + 3)); cout << "*";
                }

                contadorpuesto++;

            }

        }

    }

    //familias diferentes, e hijos
    guardado = xmarco * 4 + 4;
    comparacion = guardado;
    xmarco = xmarco * 2+1;
    for (int j = 1; j <= familia; j++) { //empieza buscar familias

        booleano = rand() % 2;

        if (booleano == 1) {

            contadorasientofam = 0;

            for (int i = 0; i <= contador; i++) { //cuento integrantes de la familia

                if ((cosos[i].getFamilia() == j) && (cosos[i].getVivo() == 1)) {
                    contadorasientofam++;


                }

            }

            //impresion familias
            if (contadorasientofam <= 33) {//max 32 asientos por fila
                //entra en la fila
                if ((33 * 2 - comparacion) >= (contadorasientofam * 2)) { //xmarco son los asientos usados
                    //ymarco se lo deja tal cual

                    //continua en xmarco

                    cualx = 0;
                        for (int i = 0; i <= contador; i++) {
                            
                            if (cosos[i].getVivo() == 1 && cosos[i].getFamilia()==j ) {
                                xmarco++;
                                if (cosos[i].getAnimo() == 0) { //Feliz
                                    SetConsoleTextAttribute(hConsole, 1);
                                    gotoxy(5 + guardado + (cualx * 2), (ymarco + 3)); cout << "*";
                                }
                                if (cosos[i].getAnimo() == 1) { //Triste
                                    SetConsoleTextAttribute(hConsole, 2);
                                    gotoxy(5 + guardado + (cualx * 2), (ymarco + 3)); cout << "*";
                                }
                                if (cosos[i].getAnimo() == 2) { //Enojado
                                    SetConsoleTextAttribute(hConsole, 3);
                                    gotoxy(5 + guardado + (cualx * 2), (ymarco + 3)); cout << "*";
                                }
                                if (cosos[i].getAnimo() == 3) { //Deprimido
                                    SetConsoleTextAttribute(hConsole, 4);
                                    gotoxy(5 + guardado + (cualx * 2), (ymarco + 3)); cout << "*";
                                }
                                if (cosos[i].getAnimo() == 4) { //neutro
                                    SetConsoleTextAttribute(hConsole, 5);
                                    gotoxy(5 + guardado + (cualx * 2), (ymarco + 3)); cout << "*";
                                }

                                //JSON
                                Value persona;
                                persona.append("Codigo: " + to_string(cosos[i].getCodigo()));
                                persona.append("Nombre1: " + cosos[i].getNombre1());
                                persona.append("Nombre2: " + cosos[i].getNombre2());
                                persona.append("Apellido1: " + cosos[i].getApellido1());
                                persona.append("Apellido2: " + cosos[i].getApellido2());
                                persona.append("Posicion Fila: " + to_string(ymarco));
                                
                                persona.append("Posicion Columna: " + to_string(xmarco));
                                persona.append("Familia: " +to_string(cosos[i].getFamilia()));
                                personasObj.append(persona);
                                cualx++;
                            }
                        }
                    xmarco++;
                    guardado = guardado + (contadorasientofam * 2) + 2;

                }

                //no entra en la fila
                if ((33 * 2 - comparacion) < (contadorasientofam * 2)) {
                    xmarco = 0;
                    ymarco = ymarco + 1;
                    cualx = 0;
                    for (int i = 0; i <= contador; i++) {
                        if (cosos[i].getVivo() == 1 && cosos[i].getFamilia() == j) {
                            if (cosos[i].getAnimo() == 0) { //Feliz
                                SetConsoleTextAttribute(hConsole, 1);
                                gotoxy((cualx * 2 + 5), (ymarco + 3)); cout << "*";
                            }
                            if (cosos[i].getAnimo() == 1) { //Triste
                                SetConsoleTextAttribute(hConsole, 2);
                                gotoxy((cualx * 2 + 5), (ymarco + 3)); cout << "*";
                            }
                            if (cosos[i].getAnimo() == 2) { //Enojado
                                SetConsoleTextAttribute(hConsole, 3);
                                gotoxy((cualx * 2 + 5), (ymarco + 3)); cout << "*";
                            }
                            if (cosos[i].getAnimo() == 3) { //Deprimido
                                SetConsoleTextAttribute(hConsole, 4);
                                gotoxy((cualx* 2 + 5), (ymarco + 3)); cout << "*";
                            }
                            if (cosos[i].getAnimo() == 4) { //neutro
                                SetConsoleTextAttribute(hConsole, 5);
                                gotoxy((cualx * 2 + 5), (ymarco + 3)); cout << "*";
                            }

                            //JSON
                            Value persona;
                            persona.append("Codigo: " + to_string(cosos[i].getCodigo()));
                            persona.append("Nombre1: " + cosos[i].getNombre1());
                            persona.append("Nombre2: " + cosos[i].getNombre2());
                            persona.append("Apellido1: " + cosos[i].getApellido1());
                            persona.append("Apellido2: " + cosos[i].getApellido2());
                            persona.append("Posicion Fila: " + to_string(ymarco));
                            persona.append("Posicion Columna: " + to_string(cualx));
                            persona.append("Familia: " + to_string(cosos[i].getFamilia()));
                            personasObj.append(persona);
                            cualx++;
                            xmarco++;
                        }
                    }
                    guardado = (contadorasientofam * 2) + 2;
                }
                comparacion = guardado;

            }

        }
    }
    SetConsoleTextAttribute(hConsole, 7);
    gotoxy(5, 20); cout << "Se genero el archivo cine.json";
    
    //Exporta el objeto JSON a un archivo
    std::ofstream archivo("cine.json");
    archivo << personasObj;
    archivo.close();

};

void exportar() {
    //crea un objeto json
    Value personasObj;
    for (int i = 0; i <= contador; i++) {
        Value persona;
        //generamos y guardamos en el objeto json
        persona.append("Codigo: " + to_string(cosos[i].getCodigo()));
        persona.append("Nombre1: " + cosos[i].getNombre1());
        persona.append("Nombre2: " + cosos[i].getNombre2());

        persona.append("Apellido1: " + cosos[i].getApellido1());
        persona.append("Apellido2: " + cosos[i].getApellido2());
        persona.append("Edad: " + to_string(cosos[i].getEdad()));

        if (cosos[i].getTrabaja() == 0) {
            auxiliar = "No";
        }
        if (cosos[i].getTrabaja() == 1) {
            auxiliar = "Si";
        }
        persona.append("Trabaja: " + auxiliar);
        persona.append("Sueldo: $" + to_string(cosos[i].getSueldo()));


        if (cosos[i].getAnimo() == 0) {
            auxiliar = "Feliz";
        }
        if (cosos[i].getAnimo() == 1) {
            auxiliar = "Triste";
        }
        if (cosos[i].getAnimo() == 2) {
            auxiliar = "Enojado";
        }
        if (cosos[i].getAnimo() == 3) {
            auxiliar = "Deprimido";
        }
        if (cosos[i].getAnimo() == 4) {
            auxiliar = "Neutro";
        }

        persona.append("Animo: " + auxiliar);

        if (cosos[i].getFamilia() == 0) {
            auxiliar = "Son los primeros creados";
        }
        if (cosos[i].getFamilia() != 0) {
            auxiliar = to_string(cosos[i].getFamilia());
        }

        persona.append("Familia: " + auxiliar);

        if (cosos[i].getSexo() == 0) {
            auxiliar = "Masculino";
        }
        if (cosos[i].getSexo() == 1) {
            auxiliar = "Femenino";
        }

        persona.append("Sexo: " + auxiliar);

        if (cosos[i].getCasado() == 1) {
            auxiliar = "Si";
        }
        if (cosos[i].getCasado() == 0) {
            auxiliar = "No";
        }
        persona.append("Casado: " + auxiliar);

        if (cosos[i].getViudo() == 1) {
            auxiliar = "Si";
        }
        if (cosos[i].getViudo() == 0) {
            auxiliar = "No";
        }
        persona.append("Viudo: " + auxiliar);

        if (cosos[i].getTeletransportado() == 1) {
            auxiliar = "Si";
        }
        if (cosos[i].getTeletransportado() == 0) {
            auxiliar = "No";
        }
        persona.append("Teletransportado: " + auxiliar);

        persona.append("PosX: " + to_string(cosos[i].getPosx()));
        persona.append("PosY: " + to_string(cosos[i].getPosy()));
        persona.append("Hijos: " + to_string(cosos[i].getConthijo()));

        if (cosos[i].getSangre() == 0) {
            auxiliar = "A+";
        }
        if (cosos[i].getSangre() == 1) {
            auxiliar = "A-";
        }
        if (cosos[i].getSangre() == 2) {
            auxiliar = "B+";
        }
        if (cosos[i].getSangre() == 3) {
            auxiliar = "B-";
        }
        if (cosos[i].getSangre() == 4) {
            auxiliar = "O+";
        }
        if (cosos[i].getSangre() == 5) {
            auxiliar = "O-";
        }
        if (cosos[i].getSangre() == 6) {
            auxiliar = "AB+";
        }
        if (cosos[i].getSangre() == 7) {
            auxiliar = "AB-";
        }

        persona.append("Sangre: " + auxiliar);

        if (cosos[i].getVivo() == 1) {
            auxiliar = "Si";
        }
        if (cosos[i].getVivo() == 0) {
            auxiliar = "No";
        }
        persona.append("Vivo: " + auxiliar);

        if (cosos[i].getRevivido() == 1) {
            auxiliar = "Si";
        }
        if (cosos[i].getRevivido() == 0) {
            auxiliar = "No";
        }
        persona.append("Revivido: " + auxiliar);

        if (cosos[i].getDesaparece() == 1) {
            auxiliar = "Si";
        }
        if (cosos[i].getDesaparece() == 0) {
            auxiliar = "No";
        }
        persona.append("Reemplazado: " + auxiliar);

        persona.append("Resistencia: " + to_string(cosos[i].getResistencia()));

        if (cosos[i].getInfectado() == 1) {
            auxiliar = "Si";
        }
        if (cosos[i].getInfectado() == 0) {
            auxiliar = "No";
        }
        persona.append("Infectado_covid: " + auxiliar);

        persona.append("Vida: " + to_string(cosos[i].getVida()));
        persona.append("Ataque: " + to_string(cosos[i].getAtaque()));
        persona.append("Defensa: " + to_string(cosos[i].getDefensa()));
        persona.append("Arma: " + to_string(cosos[i].getArma()));
        personasObj["Persona " + to_string(i)] = persona;
    }

    //Exporta el objeto JSON a un archivo
    std::ofstream archivo("todos.json");
    archivo << personasObj;
    archivo.close();

};

void cososmuertos() {
    //crea un objeto json
    Value personasObj;
    for (int i = 0; i <= contador; i++) {
        if (cosos[i].getVivo() == 0 && cosos[i].getDesaparece() == 0) {
            Value persona;
            //generamos y guardamos en el objeto json
            persona.append("Codigo: " + to_string(cosos[i].getCodigo()));
            persona.append("Nombre1: " + cosos[i].getNombre1());
            persona.append("Nombre2: " + cosos[i].getNombre2());

            persona.append("Apellido1: " + cosos[i].getApellido1());
            persona.append("Apellido2: " + cosos[i].getApellido2());
            persona.append("Edad: " + to_string(cosos[i].getEdad()));

            if (cosos[i].getTrabaja() == 0) {
                auxiliar = "No";
            }
            if (cosos[i].getTrabaja() == 1) {
                auxiliar = "Si";
            }
            persona.append("Trabaja: " + auxiliar);
            persona.append("Sueldo: $" + to_string(cosos[i].getSueldo()));


            if (cosos[i].getAnimo() == 0) {
                auxiliar = "Feliz";
            }
            if (cosos[i].getAnimo() == 1) {
                auxiliar = "Triste";
            }
            if (cosos[i].getAnimo() == 2) {
                auxiliar = "Enojado";
            }
            if (cosos[i].getAnimo() == 3) {
                auxiliar = "Deprimido";
            }
            if (cosos[i].getAnimo() == 4) {
                auxiliar = "Neutro";
            }

            persona.append("Animo: " + auxiliar);

            if (cosos[i].getFamilia() == 0) {
                auxiliar = "Son los primeros creados";
            }
            if (cosos[i].getFamilia() != 0) {
                auxiliar = to_string(cosos[i].getFamilia());
            }

            persona.append("Familia: " + auxiliar);

            if (cosos[i].getSexo() == 0) {
                auxiliar = "Masculino";
            }
            if (cosos[i].getSexo() == 1) {
                auxiliar = "Femenino";
            }

            persona.append("Sexo: " + auxiliar);

            if (cosos[i].getCasado() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getCasado() == 0) {
                auxiliar = "No";
            }
            persona.append("Casado: " + auxiliar);

            if (cosos[i].getViudo() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getViudo() == 0) {
                auxiliar = "No";
            }
            persona.append("Viudo: " + auxiliar);

            if (cosos[i].getTeletransportado() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getTeletransportado() == 0) {
                auxiliar = "No";
            }
            persona.append("Teletransportado: " + auxiliar);

            persona.append("PosX: " + to_string(cosos[i].getPosx()));
            persona.append("PosY: " + to_string(cosos[i].getPosy()));
            persona.append("Hijos: " + to_string(cosos[i].getConthijo()));

            if (cosos[i].getSangre() == 0) {
                auxiliar = "A+";
            }
            if (cosos[i].getSangre() == 1) {
                auxiliar = "A-";
            }
            if (cosos[i].getSangre() == 2) {
                auxiliar = "B+";
            }
            if (cosos[i].getSangre() == 3) {
                auxiliar = "B-";
            }
            if (cosos[i].getSangre() == 4) {
                auxiliar = "O+";
            }
            if (cosos[i].getSangre() == 5) {
                auxiliar = "O-";
            }
            if (cosos[i].getSangre() == 6) {
                auxiliar = "AB+";
            }
            if (cosos[i].getSangre() == 7) {
                auxiliar = "AB-";
            }

            persona.append("Sangre: " + auxiliar);

            if (cosos[i].getVivo() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getVivo() == 0) {
                auxiliar = "No";
            }
            persona.append("Vivo: " + auxiliar);

            if (cosos[i].getRevivido() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getRevivido() == 0) {
                auxiliar = "No";
            }
            persona.append("Revivido: " + auxiliar);

            if (cosos[i].getDesaparece() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getDesaparece() == 0) {
                auxiliar = "No";
            }
            persona.append("Reemplazado: " + auxiliar);

            persona.append("Resistencia: " + to_string(cosos[i].getResistencia()));

            if (cosos[i].getInfectado() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getInfectado() == 0) {
                auxiliar = "No";
            }
            persona.append("Infectado_covid: " + auxiliar);

            persona.append("Vida: " + to_string(cosos[i].getVida()));
            persona.append("Ataque: " + to_string(cosos[i].getAtaque()));
            persona.append("Defensa: " + to_string(cosos[i].getDefensa()));
            persona.append("Arma: " + to_string(cosos[i].getArma()));
            personasObj.append(persona);
        }
    }
    //Exporta el objeto JSON a un archivo
    std::ofstream archivo("muertos.json");
    archivo << personasObj;
    archivo.close();

};

void cososhijos() {
    //crea un objeto json
    Value personasObj;
    for (int i = 0; i <= contador; i++) {
        if (cosos[i].getConthijo() >= 1) {
            Value persona;
            //generamos y guardamos en el objeto json
            persona.append("Codigo: " + to_string(cosos[i].getCodigo()));
            persona.append("Nombre1: " + cosos[i].getNombre1());
            persona.append("Nombre2: " + cosos[i].getNombre2());

            persona.append("Apellido1: " + cosos[i].getApellido1());
            persona.append("Apellido2: " + cosos[i].getApellido2());
            persona.append("Edad: " + to_string(cosos[i].getEdad()));

            if (cosos[i].getTrabaja() == 0) {
                auxiliar = "No";
            }
            if (cosos[i].getTrabaja() == 1) {
                auxiliar = "Si";
            }
            persona.append("Trabaja: " + auxiliar);
            persona.append("Sueldo: $" + to_string(cosos[i].getSueldo()));


            if (cosos[i].getAnimo() == 0) {
                auxiliar = "Feliz";
            }
            if (cosos[i].getAnimo() == 1) {
                auxiliar = "Triste";
            }
            if (cosos[i].getAnimo() == 2) {
                auxiliar = "Enojado";
            }
            if (cosos[i].getAnimo() == 3) {
                auxiliar = "Deprimido";
            }
            if (cosos[i].getAnimo() == 4) {
                auxiliar = "Neutro";
            }

            persona.append("Animo: " + auxiliar);

            if (cosos[i].getFamilia() == 0) {
                auxiliar = "Son los primeros creados";
            }
            if (cosos[i].getFamilia() != 0) {
                auxiliar = to_string(cosos[i].getFamilia());
            }

            persona.append("Familia: " + auxiliar);

            if (cosos[i].getSexo() == 0) {
                auxiliar = "Masculino";
            }
            if (cosos[i].getSexo() == 1) {
                auxiliar = "Femenino";
            }

            persona.append("Sexo: " + auxiliar);

            if (cosos[i].getCasado() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getCasado() == 0) {
                auxiliar = "No";
            }
            persona.append("Casado: " + auxiliar);

            if (cosos[i].getViudo() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getViudo() == 0) {
                auxiliar = "No";
            }
            persona.append("Viudo: " + auxiliar);

            if (cosos[i].getTeletransportado() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getTeletransportado() == 0) {
                auxiliar = "No";
            }
            persona.append("Teletransportado: " + auxiliar);

            persona.append("PosX: " + to_string(cosos[i].getPosx()));
            persona.append("PosY: " + to_string(cosos[i].getPosy()));
            persona.append("Hijos: " + to_string(cosos[i].getConthijo()));

            if (cosos[i].getSangre() == 0) {
                auxiliar = "A+";
            }
            if (cosos[i].getSangre() == 1) {
                auxiliar = "A-";
            }
            if (cosos[i].getSangre() == 2) {
                auxiliar = "B+";
            }
            if (cosos[i].getSangre() == 3) {
                auxiliar = "B-";
            }
            if (cosos[i].getSangre() == 4) {
                auxiliar = "O+";
            }
            if (cosos[i].getSangre() == 5) {
                auxiliar = "O-";
            }
            if (cosos[i].getSangre() == 6) {
                auxiliar = "AB+";
            }
            if (cosos[i].getSangre() == 7) {
                auxiliar = "AB-";
            }

            persona.append("Sangre: " + auxiliar);

            if (cosos[i].getVivo() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getVivo() == 0) {
                auxiliar = "No";
            }
            persona.append("Vivo: " + auxiliar);

            if (cosos[i].getRevivido() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getRevivido() == 0) {
                auxiliar = "No";
            }
            persona.append("Revivido: " + auxiliar);

            if (cosos[i].getDesaparece() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getDesaparece() == 0) {
                auxiliar = "No";
            }
            persona.append("Reemplazado: " + auxiliar);

            persona.append("Resistencia: " + to_string(cosos[i].getResistencia()));

            if (cosos[i].getInfectado() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getInfectado() == 0) {
                auxiliar = "No";
            }
            persona.append("Infectado_covid: " + auxiliar);

            persona.append("Vida: " + to_string(cosos[i].getVida()));
            persona.append("Ataque: " + to_string(cosos[i].getAtaque()));
            persona.append("Defensa: " + to_string(cosos[i].getDefensa()));
            persona.append("Arma: " + to_string(cosos[i].getArma()));
            personasObj.append(persona);
        }
    }
    //Exporta el objeto JSON a un archivo
    std::ofstream archivo("conhijos.json");
    archivo << personasObj;
    archivo.close();

};

void cososvivos() {
    //crea un objeto json
    Value personasObj;
    for (int i = 0; i <= contador; i++) {
        if (cosos[i].getVivo() == 1) {
            Value persona;
            //generamos y guardamos en el objeto json
            persona.append("Codigo: " + to_string(cosos[i].getCodigo()));
            persona.append("Nombre1: " + cosos[i].getNombre1());
            persona.append("Nombre2: " + cosos[i].getNombre2());

            persona.append("Apellido1: " + cosos[i].getApellido1());
            persona.append("Apellido2: " + cosos[i].getApellido2());
            persona.append("Edad: " + to_string(cosos[i].getEdad()));

            if (cosos[i].getTrabaja() == 0) {
                auxiliar = "No";
            }
            if (cosos[i].getTrabaja() == 1) {
                auxiliar = "Si";
            }
            persona.append("Trabaja: " + auxiliar);
            persona.append("Sueldo: $" + to_string(cosos[i].getSueldo()));


            if (cosos[i].getAnimo() == 0) {
                auxiliar = "Feliz";
            }
            if (cosos[i].getAnimo() == 1) {
                auxiliar = "Triste";
            }
            if (cosos[i].getAnimo() == 2) {
                auxiliar = "Enojado";
            }
            if (cosos[i].getAnimo() == 3) {
                auxiliar = "Deprimido";
            }
            if (cosos[i].getAnimo() == 4) {
                auxiliar = "Neutro";
            }

            persona.append("Animo: " + auxiliar);

            if (cosos[i].getFamilia() == 0) {
                auxiliar = "Son los primeros creados";
            }
            if (cosos[i].getFamilia() != 0) {
                auxiliar = to_string(cosos[i].getFamilia());
            }

            persona.append("Familia: " + auxiliar);

            if (cosos[i].getSexo() == 0) {
                auxiliar = "Masculino";
            }
            if (cosos[i].getSexo() == 1) {
                auxiliar = "Femenino";
            }

            persona.append("Sexo: " + auxiliar);

            if (cosos[i].getCasado() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getCasado() == 0) {
                auxiliar = "No";
            }
            persona.append("Casado: " + auxiliar);

            if (cosos[i].getViudo() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getViudo() == 0) {
                auxiliar = "No";
            }
            persona.append("Viudo: " + auxiliar);

            if (cosos[i].getTeletransportado() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getTeletransportado() == 0) {
                auxiliar = "No";
            }
            persona.append("Teletransportado: " + auxiliar);

            persona.append("PosX: " + to_string(cosos[i].getPosx()));
            persona.append("PosY: " + to_string(cosos[i].getPosy()));
            persona.append("Hijos: " + to_string(cosos[i].getConthijo()));

            if (cosos[i].getSangre() == 0) {
                auxiliar = "A+";
            }
            if (cosos[i].getSangre() == 1) {
                auxiliar = "A-";
            }
            if (cosos[i].getSangre() == 2) {
                auxiliar = "B+";
            }
            if (cosos[i].getSangre() == 3) {
                auxiliar = "B-";
            }
            if (cosos[i].getSangre() == 4) {
                auxiliar = "O+";
            }
            if (cosos[i].getSangre() == 5) {
                auxiliar = "O-";
            }
            if (cosos[i].getSangre() == 6) {
                auxiliar = "AB+";
            }
            if (cosos[i].getSangre() == 7) {
                auxiliar = "AB-";
            }

            persona.append("Sangre: " + auxiliar);

            if (cosos[i].getVivo() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getVivo() == 0) {
                auxiliar = "No";
            }
            persona.append("Vivo: " + auxiliar);

            if (cosos[i].getRevivido() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getRevivido() == 0) {
                auxiliar = "No";
            }
            persona.append("Revivido: " + auxiliar);

            if (cosos[i].getDesaparece() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getDesaparece() == 0) {
                auxiliar = "No";
            }
            persona.append("Reemplazado: " + auxiliar);

            persona.append("Resistencia: " + to_string(cosos[i].getResistencia()));

            if (cosos[i].getInfectado() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getInfectado() == 0) {
                auxiliar = "No";
            }
            persona.append("Infectado_covid: " + auxiliar);

            persona.append("Vida: " + to_string(cosos[i].getVida()));
            persona.append("Ataque: " + to_string(cosos[i].getAtaque()));
            persona.append("Defensa: " + to_string(cosos[i].getDefensa()));
            persona.append("Arma: " + to_string(cosos[i].getArma()));
            personasObj.append(persona);
        }
    }
    //Exporta el objeto JSON a un archivo
    std::ofstream archivo("vivos.json");
    archivo << personasObj;
    archivo.close();

};

void cososresucitados() {
    //crea un objeto json
    Value personasObj;
    for (int i = 0; i <= contador; i++) {
        if (cosos[i].getRevivido()==1) {
            Value persona;
            //generamos y guardamos en el objeto json
            persona.append("Codigo: " + to_string(cosos[i].getCodigo()));
            persona.append("Nombre1: " + cosos[i].getNombre1());
            persona.append("Nombre2: " + cosos[i].getNombre2());

            persona.append("Apellido1: " + cosos[i].getApellido1());
            persona.append("Apellido2: " + cosos[i].getApellido2());
            persona.append("Edad: " + to_string(cosos[i].getEdad()));

            if (cosos[i].getTrabaja() == 0) {
                auxiliar = "No";
            }
            if (cosos[i].getTrabaja() == 1) {
                auxiliar = "Si";
            }
            persona.append("Trabaja: " + auxiliar);
            persona.append("Sueldo: $" + to_string(cosos[i].getSueldo()));


            if (cosos[i].getAnimo() == 0) {
                auxiliar = "Feliz";
            }
            if (cosos[i].getAnimo() == 1) {
                auxiliar = "Triste";
            }
            if (cosos[i].getAnimo() == 2) {
                auxiliar = "Enojado";
            }
            if (cosos[i].getAnimo() == 3) {
                auxiliar = "Deprimido";
            }
            if (cosos[i].getAnimo() == 4) {
                auxiliar = "Neutro";
            }

            persona.append("Animo: " + auxiliar);

            if (cosos[i].getFamilia() == 0) {
                auxiliar = "Son los primeros creados";
            }
            if (cosos[i].getFamilia() != 0) {
                auxiliar = to_string(cosos[i].getFamilia());
            }

            persona.append("Familia: " + auxiliar);

            if (cosos[i].getSexo() == 0) {
                auxiliar = "Masculino";
            }
            if (cosos[i].getSexo() == 1) {
                auxiliar = "Femenino";
            }

            persona.append("Sexo: " + auxiliar);

            if (cosos[i].getCasado() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getCasado() == 0) {
                auxiliar = "No";
            }
            persona.append("Casado: " + auxiliar);

            if (cosos[i].getViudo() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getViudo() == 0) {
                auxiliar = "No";
            }
            persona.append("Viudo: " + auxiliar);

            if (cosos[i].getTeletransportado() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getTeletransportado() == 0) {
                auxiliar = "No";
            }
            persona.append("Teletransportado: " + auxiliar);

            persona.append("PosX: " + to_string(cosos[i].getPosx()));
            persona.append("PosY: " + to_string(cosos[i].getPosy()));
            persona.append("Hijos: " + to_string(cosos[i].getConthijo()));

            if (cosos[i].getSangre() == 0) {
                auxiliar = "A+";
            }
            if (cosos[i].getSangre() == 1) {
                auxiliar = "A-";
            }
            if (cosos[i].getSangre() == 2) {
                auxiliar = "B+";
            }
            if (cosos[i].getSangre() == 3) {
                auxiliar = "B-";
            }
            if (cosos[i].getSangre() == 4) {
                auxiliar = "O+";
            }
            if (cosos[i].getSangre() == 5) {
                auxiliar = "O-";
            }
            if (cosos[i].getSangre() == 6) {
                auxiliar = "AB+";
            }
            if (cosos[i].getSangre() == 7) {
                auxiliar = "AB-";
            }

            persona.append("Sangre: " + auxiliar);

            if (cosos[i].getVivo() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getVivo() == 0) {
                auxiliar = "No";
            }
            persona.append("Vivo: " + auxiliar);

            if (cosos[i].getRevivido() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getRevivido() == 0) {
                auxiliar = "No";
            }
            persona.append("Revivido: " + auxiliar);

            if (cosos[i].getDesaparece() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getDesaparece() == 0) {
                auxiliar = "No";
            }
            persona.append("Reemplazado: " + auxiliar);

            persona.append("Resistencia: " + to_string(cosos[i].getResistencia()));

            if (cosos[i].getInfectado() == 1) {
                auxiliar = "Si";
            }
            if (cosos[i].getInfectado() == 0) {
                auxiliar = "No";
            }
            persona.append("Infectado_covid: " + auxiliar);

            persona.append("Vida: " + to_string(cosos[i].getVida()));
            persona.append("Ataque: " + to_string(cosos[i].getAtaque()));
            persona.append("Defensa: " + to_string(cosos[i].getDefensa()));
            persona.append("Arma: " + to_string(cosos[i].getArma()));
            personasObj.append(persona);
        }
    }
    //Exporta el objeto JSON a un archivo
    std::ofstream archivo("resucitados.json");
    archivo << personasObj;
    archivo.close();

};

void exportuno(int codigo) {
    //crea un objeto json
    Value persona;

    //generamos y guardamos en el objeto json
    persona.append("Codigo: "+ to_string(cosos[codigo].getCodigo()));
    persona.append("Nombre1: "+cosos[codigo].getNombre1());
    persona.append("Nombre2: "+ cosos[codigo].getNombre2());
    
    persona.append("Apellido1: "+cosos[codigo].getApellido1());
    persona.append("Apellido2: "+cosos[codigo].getApellido2());
    persona.append("Edad: "+to_string(cosos[codigo].getEdad()));

    if (cosos[codigo].getTrabaja() == 0) {
        auxiliar = "No";
    }
    if (cosos[codigo].getTrabaja() == 1) {
        auxiliar = "Si";
    }
    persona.append("Trabaja: "+ auxiliar);
    persona.append("Sueldo: $"+ to_string(cosos[codigo].getSueldo()));


    if (cosos[codigo].getAnimo() == 0) {
        auxiliar = "Feliz";
    }
    if (cosos[codigo].getAnimo() == 1) {
        auxiliar = "Triste";
    }
    if (cosos[codigo].getAnimo() == 2) {
        auxiliar = "Enojado";
    }
    if (cosos[codigo].getAnimo() == 3) {
        auxiliar = "Deprimido";
    }
    if (cosos[codigo].getAnimo() == 4) {
        auxiliar = "Neutro";
    }

    persona.append("Animo: "+ auxiliar);

    if (cosos[codigo].getFamilia() == 0) {
        auxiliar = "Son los primeros creados";
    }
    if (cosos[codigo].getFamilia() != 0) {
        auxiliar = to_string(cosos[codigo].getFamilia());
    }

    persona.append("Familia: "+ auxiliar);

    if (cosos[codigo].getSexo() == 0) {
        auxiliar = "Masculino";
    }
    if (cosos[codigo].getSexo() == 1) {
        auxiliar = "Femenino";
    }

    persona.append("Sexo: "+ auxiliar);

    if (cosos[codigo].getCasado() == 1) {
        auxiliar = "Si";
    }
    if (cosos[codigo].getCasado() == 0) {
        auxiliar = "No";
    }
    persona.append("Casado: " + auxiliar);

    if (cosos[codigo].getViudo() == 1) {
        auxiliar = "Si";
    }
    if (cosos[codigo].getViudo() == 0) {
        auxiliar = "No";
    }

    persona.append("Viudo: "+ auxiliar);

    if (cosos[codigo].getTeletransportado() == 1) {
        auxiliar = "Si";
    }
    if (cosos[codigo].getTeletransportado() == 0) {
        auxiliar = "No";
    }
    persona.append("Teletransportado: " + auxiliar);

    persona.append("PosX: "+ to_string(cosos[codigo].getPosx()));
    persona.append("PosY: "+ to_string(cosos[codigo].getPosy()));
    persona.append("Hijos: "+ to_string(cosos[codigo].getConthijo()));

    if (cosos[codigo].getSangre() == 0) {
        auxiliar = "A+";
    }
    if (cosos[codigo].getSangre() == 1) {
        auxiliar = "A-";
    }
    if (cosos[codigo].getSangre() == 2) {
        auxiliar = "B+";
    }
    if (cosos[codigo].getSangre() == 3) {
        auxiliar = "B-";
    }
    if (cosos[codigo].getSangre() == 4) {
        auxiliar = "O+";
    }
    if (cosos[codigo].getSangre() == 5) {
        auxiliar = "O-";
    }
    if (cosos[codigo].getSangre() == 6) {
        auxiliar = "AB+";
    }
    if (cosos[codigo].getSangre() == 7) {
        auxiliar = "AB-";
    }

    persona.append("Sangre: "+auxiliar);

    if (cosos[codigo].getVivo() == 1) {
        auxiliar = "Si";
    }
    if (cosos[codigo].getVivo() == 0) {
        auxiliar = "No";
    }
    persona.append("Vivo: "+ auxiliar);

    if (cosos[codigo].getRevivido() == 1) {
        auxiliar = "Si";
    }
    if (cosos[codigo].getRevivido() == 0) {
        auxiliar = "No";
    }
    persona.append("Revivido: "+ auxiliar);

    if (cosos[codigo].getDesaparece() == 1) {
        auxiliar = "Si";
    }
    if (cosos[codigo].getDesaparece() == 0) {
        auxiliar = "No";
    }
    persona.append("Reemplazado: "+ auxiliar);

    persona.append("Resistencia: "+ to_string(cosos[codigo].getResistencia()));

    if (cosos[codigo].getInfectado() == 1) {
        auxiliar = "Si";
    }
    if (cosos[codigo].getInfectado() == 0) {
        auxiliar = "No";
    }
    persona.append("Infectado_covid: "+auxiliar);

    persona.append("Vida: "+ to_string(cosos[codigo].getVida()));
    persona.append("Ataque: "+ to_string(cosos[codigo].getAtaque()));
    persona.append("Defensa: "+ to_string(cosos[codigo].getDefensa()));
    persona.append("Arma: "+ to_string(cosos[codigo].getArma()));
    
    //crea un array
    Value objetoJson;
    objetoJson["Persona"] = persona;

    //Exporta el objeto JSON a un archivo
    std::ofstream archivo("persona.json");
    archivo << objetoJson;
    archivo.close();
};

void identificacion() {
    gotoxy(0, 31); cout << "               ";

    //Pregunta por el desastre
    gotoxy(45, 19); cout << "Que deseas hacer?";
    gotoxy(45, 20); cout << "1) Obtener la informacion de un coso";
    gotoxy(45, 21); cout << "2) Generar un archivo JSON de un solo individuo";
    gotoxy(45, 22); cout << "3) Generar un archivo JSON de todos los individuos";
    gotoxy(45, 23); cin >> respuesta;

    while (respuesta >= 4 || respuesta <= 0) {
        gotoxy(45, 23); cout << "               ";
        gotoxy(45, 23); cin >> respuesta;
    }

    gotoxy(45, 19); cout << "                                                   ";
    gotoxy(45, 20); cout << "                                                   ";
    gotoxy(45, 21); cout << "                                                   ";
    gotoxy(45, 22); cout << "                                                   ";
    gotoxy(45, 23); cout << "                                                   ";

    //Obtener informacion
    if (respuesta==1) {
        gotoxy(45, 19); cout << "****Selecciona el Coso:";
        
        //FILA
        gotoxy(45, 20); cout << "Escribe la fila";
        gotoxy(45, 21); cin >> posy;

        while (posy > 15 || posy < 0) {
            gotoxy(45, 21); cout << "               ";
            gotoxy(45, 21); cin >> posy;
        }
        gotoxy(45, 20); cout << "                                                   ";
        gotoxy(45, 21); cout << "                                                   ";

        //COLUMNA
        gotoxy(45, 20); cout << "Escribe la columna";
        gotoxy(45, 21); cin >> posx;

        while (posx > 35 || posx < 0) {
            gotoxy(45, 21); cout << "               ";
            gotoxy(45, 21); cin >> posx;
        }
        gotoxy(45, 19); cout << "                                                   ";
        gotoxy(45, 20); cout << "                                                   ";
        gotoxy(45, 21); cout << "                                                   ";

        //UBICACION DEL COSO
        for (int i = 0; i <= contador; i++) {
            if ((cosos[i].getPosx() == posx)&& (cosos[i].getPosy() == posy)) {
                codigo=i;
            }
        }


        if ((cosos[codigo].getVivo() == 1) && cosos[codigo].getPosx() ==posx && cosos[codigo].getPosy() == posy) {
            //nombre del padre, de la madre y su codigo

            //falta decision logica de que si vivo lo muestra
            gotoxy(45, 28); cout << "---Datos del Coso---";
            gotoxy(45, 29); cout << "Codigo: " << codigo;
            gotoxy(45, 30); cout << "Nombre: " << cosos[codigo].getNombre1() << " " << cosos[codigo].getNombre2() << " " << cosos[codigo].getApellido1() << " " << cosos[codigo].getApellido2(); //nombre completo
            gotoxy(45, 31); cout << "Edad: " << cosos[codigo].getEdad();
            gotoxy(45, 32); cout << "Trabajo: "; //trabajo con sueldo

            if (cosos[codigo].getTrabaja() == 0) {
                cout << "No";
            }
            if (cosos[codigo].getTrabaja() == 1) {
                cout << "Si, con $" << cosos[codigo].getSueldo();
            }

            gotoxy(45, 33); cout << "Animo: "; //agregar la palabra de animo

            if (cosos[codigo].getAnimo() == 0) {
                cout << "Feliz";
            }
            if (cosos[codigo].getAnimo() == 1) {
                cout << "Triste";
            }
            if (cosos[codigo].getAnimo() == 2) {
                cout << "Enojado";
            }
            if (cosos[codigo].getAnimo() == 3) {
                cout << "Deprimido";
            }
            if (cosos[codigo].getAnimo() == 4) {
                cout << "Neutro";
            }

            gotoxy(45, 34); cout << "Familia: ";
            if (cosos[codigo].getFamilia() == 0) {
                cout << "Son los primeros creados";
            }
            if (cosos[codigo].getFamilia() != 0) {
                cout << cosos[codigo].getFamilia();
            }

            gotoxy(45, 35); cout << "Sexo: "; //femenina o masculina
            if (cosos[codigo].getSexo() == 0) {
                cout << "Masculino";
            }
            if (cosos[codigo].getSexo() == 1) {
                cout << "Femenino";
            }
            gotoxy(45, 36); cout << "Casado: ";
            if (cosos[codigo].getCasado() == 1) {
                cout << "Si";
            }
            if (cosos[codigo].getCasado() == 0) {
                cout << "No";
            }

            gotoxy(45, 37); cout << "Viudo: ";
            if (cosos[codigo].getViudo() == 1) {
                cout << "Si";
            }
            if (cosos[codigo].getViudo() == 0) {
                cout << "No";
            }

            gotoxy(45, 38); cout << "Teletransportado: ";
            if (cosos[codigo].getTeletransportado() == 1) {
                cout << "Si";
            }
            if (cosos[codigo].getTeletransportado() == 0) {
                cout << "No";
            }

            gotoxy(45, 39); cout << "Posicion X: " << cosos[codigo].getPosx();
            gotoxy(45, 40); cout << "Posicion Y: " << cosos[codigo].getPosy();
            gotoxy(45, 41); cout << "Hijos: " << cosos[codigo].getConthijo();
            gotoxy(45, 42); cout << "Sangre: ";
            if (cosos[codigo].getSangre() == 0) {
                cout << "A+";
            }
            if (cosos[codigo].getSangre() == 1) {
                cout << "A-";
            }
            if (cosos[codigo].getSangre() == 2) {
                cout << "B+";
            }
            if (cosos[codigo].getSangre() == 3) {
                cout << "B-";
            }
            if (cosos[codigo].getSangre() == 4) {
                cout << "O+";
            }
            if (cosos[codigo].getSangre() == 5) {
                cout << "O-";
            }
            if (cosos[codigo].getSangre() == 6) {
                cout << "AB+";
            }
            if (cosos[codigo].getSangre() == 7) {
                cout << "AB-";
            }

            gotoxy(45, 43); cout << "Vivo: ";
            if (cosos[codigo].getVivo() == 1) {
                cout << "Si";
            }
            if (cosos[codigo].getVivo() == 0) {
                cout << "No";
            }
            gotoxy(45, 44); cout << "Revivido: ";
            if (cosos[codigo].getRevivido() == 1) {
                cout << "Si";
            }
            if (cosos[codigo].getRevivido() == 0) {
                cout << "No";
            }

            gotoxy(45, 45); cout << "Desaparecido: " ;
            if (cosos[codigo].getDesaparece() == 1) {
                cout << "Si";
            }
            if (cosos[codigo].getDesaparece() == 0) {
                cout << "No";
            }

            gotoxy(45, 46); cout << "Resistencia: " << cosos[codigo].getResistencia();
            gotoxy(45, 47); cout << "Infectado de covid: ";
            if (cosos[codigo].getInfectado() == 1) {
                cout << "Si";
            }
            if (cosos[codigo].getInfectado() == 0) {
                cout << "No";
            }

            gotoxy(45, 49); cout << "---Datos de la lucha---";
            gotoxy(45, 50); cout << "Vida: " << cosos[codigo].getVida();
            gotoxy(45, 51); cout << "Ataque: " << cosos[codigo].getAtaque();
            gotoxy(45, 52); cout << "Defensa: " << cosos[codigo].getDefensa();
            gotoxy(45, 53); cout << "Arma: " << cosos[codigo].getArma();

            if (cosos[codigo].getFamilia() == 0) {
                gotoxy(45, 55); cout << "---Datos de los padres---";
                gotoxy(45, 56); cout << "No tiene padres";
            }

            if (cosos[codigo].getFamilia() != 0) {
                gotoxy(45, 55); cout << "---Datos de los padres---";

                //Busca al padre que tiene el mismo nombre

                for (int i = 0; i <= contador; i++) {
                    if ((cosos[codigo].getFamilia() != 0) && (cosos[codigo].getFamilia() == cosos[i].getFamilia()) && (cosos[codigo].getNombre1() == cosos[i].getNombre1()) && (cosos[codigo].getNombre2() == cosos[i].getNombre2())) {
                        padre = i;
                    }
                }
                //busco a otro miembro de la familia vivo o muerto que tenga el mismo apellido y que tenga con hijo 0

                if (cosos[codigo].getSexo() == 0) { //hombre
                    padre = padre;
                    for (int i = 0; i <= contador; i++) {
                        if ((cosos[padre].getFamilia() == cosos[i].getFamilia()) && (cosos[i].getCasado() == 1 || cosos[i].getViudo() == 1) && (cosos[i].getSexo() != cosos[padre].getSexo()) && (cosos[codigo].getApellido2() == cosos[i].getApellido1())) {
                            madre = i;
                        }
                    }
                }

                if (cosos[codigo].getSexo() == 1) { //mujer
                    madre = padre;
                    for (int i = 0; i <= contador; i++) {
                        if ((cosos[madre].getFamilia() == cosos[i].getFamilia()) && (cosos[i].getCasado() == 1 || cosos[i].getViudo() == 1) && (cosos[i].getSexo() != cosos[madre].getSexo()) && (cosos[codigo].getApellido1() == cosos[i].getApellido1())) {
                            padre = i;
                        }
                    }
                }

                gotoxy(45, 56); cout << "Codigo del padre: " << padre;
                gotoxy(45, 57); cout << "Nombre del Padre: " << cosos[padre].getNombre1() << " " << cosos[padre].getNombre2() << " " << cosos[padre].getApellido1() << " " << cosos[padre].getApellido2();
                gotoxy(45, 58); cout << "Codigo de la madre: " << madre;
                gotoxy(45, 59); cout << "Nombre de la madre: " << cosos[madre].getNombre1() << " " << cosos[madre].getNombre2() << " " << cosos[madre].getApellido1() << " " << cosos[madre].getApellido2();
            }
        } else {
            gotoxy(45, 28); cout << "Se ha seleccionado un espacio vacio";
        }
        
    
    }
    
    //Generar archivo de un solo individuo
    if (respuesta == 2) {
        gotoxy(45, 19); cout << "****Selecciona el Coso:";

        //FILA
        gotoxy(45, 20); cout << "Escribe el codigo";
        gotoxy(45, 21); cin >> codigo;

        while (codigo > contador || codigo < 0) {
            gotoxy(45, 21); cout << "               ";
            gotoxy(45, 21); cin >> codigo;
        }
        gotoxy(45, 20); cout << "                                                   ";
        gotoxy(45, 21); cout << "                                                   ";
        gotoxy(45, 19); cout << "                                                   ";
        gotoxy(45, 28); cout << "Se exporto el archivo persona.json existosamente";

        exportuno(codigo);
    }
    //Generar archivo de todos los individuos por filtros
    if (respuesta == 3) {
        contadormenu = 0;
        gotoxy(45, 19); cout << "****Selecciona el Coso:";
        gotoxy(45, 20); cout << "1) Todos los cosos muertos";
        gotoxy(45, 21); cout << "2) Todos los cosos vivos";
        gotoxy(45, 22); cout << "3) Todos los cosos con hijos";
        gotoxy(45, 23); cout << "4) Todos los cosos resucitados";
        gotoxy(45, 24); cout << "5) Todos los cosos";
        gotoxy(45, 25); cin >> codigo;

        while (codigo > 5 || codigo < 1) {
            gotoxy(45, 25); cout << "               ";
            gotoxy(45, 25); cin >> codigo;
        }
        gotoxy(45, 20); cout << "                                                        ";
        gotoxy(45, 21); cout << "                                                        ";
        gotoxy(45, 19); cout << "                                                        ";
        gotoxy(45, 22); cout << "                                                        ";
        gotoxy(45, 23); cout << "                                                        ";
        gotoxy(45, 24); cout << "                                                        ";
        gotoxy(45, 25); cout << "                                                        ";
        if (codigo==1) {
            for (int i = 0; i <= contador; i++) {
                if (cosos[i].getVivo() == 0 && cosos[i].getDesaparece()==0) {
                    contadormenu++;
                }
            }
            if (contadormenu == 0) {
                gotoxy(45, 28); cout << "No hay ningun cosos muerto, no se genero el JSON";
            }
            if (contadormenu != 0) {
                gotoxy(45, 28); cout << "Se exporto el archivo muertos.json existosamente";
                gotoxy(45, 29); cout << "Con "<<contadormenu<<" muertos";
                cososmuertos();
            }
           
        }
        if (codigo == 2) {
            for (int i = 0; i <= contador; i++) {
                if (cosos[i].getVivo() == 1) {
                    contadormenu++;
                }
            }
            if (contadormenu == 0) {
                gotoxy(45, 28); cout << "No hay ningun cosos vivos, no se genero el JSON";
            }
            if (contadormenu != 0) {
                gotoxy(45, 28); cout << "Se exporto el archivo vivos.json existosamente";
                gotoxy(45, 29); cout << "Con " << contadormenu << " vivos";
                cososvivos();
            }
        
        }
        if (codigo == 3) {
            for (int i = 0; i <= contador; i++) {
                if (cosos[i].getConthijo() >= 1) {
                    contadormenu++;
                }
            }
            if (contadormenu == 0) {
                gotoxy(45, 28); cout << "No hay ningun cosos con hijo, no se genero el JSON";
            }
            if (contadormenu != 0) {
                gotoxy(45, 28); cout << "Se exporto el archivo conhijos.json existosamente";
                gotoxy(45, 29); cout << "Con " << contadormenu << " cosos con hijos";
                cososhijos();
            }

        }
        if (codigo == 4) {
            for (int i = 0; i <= contador; i++) {
                if (cosos[i].getRevivido() == 1) {
                    contadormenu++;
                }
            }
            if (contadormenu==0) {
                gotoxy(45, 28); cout << "No hay ningun cosos revivido, no se genero el JSON";
            }
            if (contadormenu!=0) {
                gotoxy(45, 28); cout << "Se exporto el archivo resucitados.json existosamente";
                gotoxy(45, 29); cout << "Con " << contadormenu << " resucitados";
                cososresucitados();
            }
            
        }
        if (codigo == 5) {
            exportar();
            gotoxy(45, 28); cout << "Se exporto el archivo todos.json existosamente";
        }
  
    }
    presentacionmenu();
}


void generarparejas() {
    //Puse el minimo de edad para casarse de 18
    contfamilia = 0;
    for (int i = 0; i <= contador; i++) {//Mujeres
        if ((cosos[i].getVivo() == 1) && (cosos[i].getCasado() == 0) && (cosos[i].getSexo() == 1) && (cosos[i].getEdad() >= 18) && (cosos[i].getHijo()==1)) {
            indiceM = i;

            for (int j = 0; j <= contador; j++) {//Hombres
                if ((cosos[j].getVivo() == 1) && (cosos[j].getCasado() == 0) && (cosos[j].getSexo() == 0) && (cosos[j].getEdad() >= 18) && (cosos[i].getHijo() == 1)) {
                    
                    
                    if ((cosos[j].getSueldo() >= cosos[i].getSueldo()) && (cosos[j].getSueldo()!=0)&&((cosos[j].getFamilia() != cosos[i].getFamilia()) || ((cosos[i].getFamilia()==0)|| (cosos[j].getFamilia() == 0)))) {//sueldo
                        
                        diferenciaE = (cosos[j].getEdad() - cosos[i].getEdad());//diferencia de edad
                        if (diferenciaE >= 5) {
                            //si ambos familia 0
                            if ((cosos[j].getFamilia()==0) && (cosos[i].getFamilia()==0)) {
                                indiceH = j;
                                familia++;
                                contfamilia++;
                                cosos[indiceM].setCasado(1);
                                cosos[indiceM].setFamilia(familia);

                                cosos[indiceH].setFamilia(familia);
                                cosos[indiceH].setCasado(1);

                                cosos[indiceH].setHijo(0);
                                cosos[indiceM].setHijo(0);
                                //feliz
                                cosos[indiceH].setAnimo(0);
                                cosos[indiceM].setAnimo(0);
                            }
                            //si ambos viudos
                            if ((cosos[j].getFamilia() != cosos[i].getFamilia()) && (cosos[j].getFamilia()!=0) &&(cosos[i].getFamilia() != 0) && (cosos[j].getViudo() == 1) && (cosos[i].getViudo() == 1)) {
                                //Trasladar (NUM familia) TODO incluido hijos y pareja fallecida a la familia de la mujer
                                
                                numfami = cosos[j].getFamilia();//familia padre
                                cosos[j].setCasado(1);
                                cosos[i].setCasado(1);//mujer
                                cosos[j].setHijo(0);
                                cosos[i].setHijo(0);
                                //feliz
                                cosos[i].setAnimo(0);
                                cosos[j].setAnimo(0);

                                contfamilia++;
                                //Familia Hombre
                                    for (int k = 0; k <= contador; k++) {
                                        //se busca al hijo y la viuda del hombre, se le pone el numero de la familia
                                        if ((cosos[k].getFamilia() == numfami)) { //vivo a muerto lo traslada, incluyendo al esposo
                                            cosos[k].setFamilia(cosos[i].getFamilia());
                                        }
                                        if ((cosos[k].getVivo()==1) && (cosos[k].getHijo()==1) && (cosos[k].getFamilia() == cosos[i].getFamilia())) {
                                            cosos[k].setAnimo(2);
                                        }
                                    }
                            }

                            //si uno viudo, y si el otro man no es de la familia cero
                            if (((cosos[j].getViudo() == 1) || (cosos[i].getViudo()==1))) {

                                if (not((cosos[j].getViudo() == 1) && (cosos[i].getViudo() == 1))) {
                                    
                                    //Si hombre viudo

                                    contfamilia++;

                                    if (cosos[j].getViudo() == 1) {

                                        //la mujer se agrega a la familia del hombre
                                        numfami = cosos[j].getFamilia();

                                        cosos[i].setFamilia(numfami); //la mujer se agrega la familia

                                    }


                                    //Si mujer viuda
                                    if (cosos[i].getViudo() == 1) {
                                        numfami = cosos[i].getFamilia();
                                        //el hombre se agrega a la familia de la mujer

                                        cosos[j].setFamilia(numfami); //el hombre se agrega la familia
                                    }
                                    cosos[j].setCasado(1);
                                    cosos[i].setCasado(1);
                                    cosos[j].setHijo(0);
                                    cosos[i].setHijo(0);

                                    for (int k = 0; k <= contador; k++) {
                                        //se busca al hijo cambio de animo a enojado
                                        if ((cosos[k].getVivo() == 1) && (cosos[k].getHijo() == 1) && (cosos[k].getFamilia() == cosos[i].getFamilia())) {
                                            cosos[k].setAnimo(2);
                                        }
                                    }
                                   
                                    //feliz
                                    cosos[i].setAnimo(0);
                                    cosos[j].setAnimo(0);
                                }
                                
                            }
                            //si ambos no viudos, ni familia 0, y son de diferente familia
                            if ((cosos[j].getFamilia()!=cosos[i].getFamilia()) && (cosos[j].getViudo() == 0) && (cosos[i].getViudo() == 0)) {
                                indiceH = j;
                                familia++;
                                contfamilia++;
                                cosos[indiceM].setCasado(1);
                                cosos[indiceM].setFamilia(familia);

                                cosos[indiceH].setFamilia(familia);
                                cosos[indiceH].setCasado(1);

                                cosos[indiceH].setHijo(0);
                                cosos[indiceM].setHijo(0);
                                //feliz
                                cosos[indiceH].setAnimo(0);
                                cosos[indiceM].setAnimo(0);

                            }
                        }
                    }
                }
            }
        }
    }
  
    gotoxy(45, 19); cout << "***Se han creado " << contfamilia << " familias";

}

void decisiones(int menuvar) {
    if (menuvar == 1) {
        generarparejas();
        presentacionmenu();
        guardadobinario();
    }
    if (menuvar == 2) {
        hijos();
        guardadobinario();
    }
    if (menuvar == 3) {
        covid();
        guardadobinario();
    }
    if (menuvar == 4) {
        destruccion();
        guardadobinario();
    }
    if (menuvar == 5) {
        lucha();
        guardadobinario();
    }
    if (menuvar == 6) {
        tiempo();
        guardadobinario();

    }
    if (menuvar == 7) {
        resucitar();
        guardadobinario();
    }
    if (menuvar == 8) {
        cine();
        guardadobinario();
    }
    if (menuvar == 9) {
        identificacion();
        guardadobinario();
    }
    if (menuvar == 10) {
        servidor1();
        guardadobinario();
        
    }
}
void vueltapregunta() {

    gotoxy(45, 20); cout << "Quieres volver al menu?                       ";
    gotoxy(45, 21); cout << "1) Si";
    gotoxy(45, 22); cout << "2) No";
    gotoxy(45, 23); cin >> respuesta;

    if (guardado != 0 && respuesta==1) {
        system("cls");
        guardado = 0;
        presentacionmenu();
        gotoxy(0, 19); cout << "------------Menu-----------";
        gotoxy(0, 20); cout << "1) Generar parejas";
        gotoxy(0, 21); cout << "2) Generar hijos";
        gotoxy(0, 22); cout << "3) Enfermedad covid";
        gotoxy(0, 23); cout << "4) Destruccion global";
        gotoxy(0, 24); cout << "5) Lucha del mas fuerte";
        gotoxy(0, 25); cout << "6) Avance de tiempo";
        gotoxy(0, 26); cout << "7) Resucitar";
        gotoxy(0, 27); cout << "8) Ir al cine";
        gotoxy(0, 28); cout << "9) Identificacion y reporte";
        gotoxy(0, 29); cout << "10) Cliente - Servidor";
        gotoxy(0, 30); cout << "***Seleccione una opcion***(Salir con 11)";
    }
    if (respuesta == 2) {
        menuvar = 11;
    }
    if (respuesta == 1) {

        gotoxy(45, 23); cout << "                               ";
        gotoxy(45, 40); cout << "                               ";
        gotoxy(45, 22); cout << "                               ";
        gotoxy(45, 20); cout << "                               ";
        gotoxy(45, 21); cout << "                 ";
        gotoxy(45, 19); cout << "                                               ";
        gotoxy(45, 19); cout << "                                                                   ";
        gotoxy(45, 28); cout << "                                                                   ";
        gotoxy(45, 29); cout << "                                                ";
        gotoxy(45, 30); cout << "                                                ";
        gotoxy(45, 31); cout << "                                                ";
        gotoxy(45, 32); cout << "                                             ";
        gotoxy(45, 33); cout << "                                              ";
        gotoxy(45, 34); cout << "                                              ";
        gotoxy(45, 35); cout << "                                              ";
        gotoxy(45, 36); cout << "                                              ";
        gotoxy(45, 37); cout << "                                              ";
        gotoxy(45, 38); cout << "                                              ";
        gotoxy(45, 39); cout << "                                              ";
        gotoxy(45, 40); cout << "                                              ";
        gotoxy(45, 41); cout << "                                              ";
        gotoxy(45, 42); cout << "                                              ";
        gotoxy(45, 43); cout << "                                              ";
        gotoxy(45, 44); cout << "                                              ";
        gotoxy(45, 45); cout << "                                              ";
        gotoxy(45, 46); cout << "                                              ";
        gotoxy(45, 47); cout << "                                              ";
        gotoxy(45, 48); cout << "                                              ";
        gotoxy(45, 49); cout << "                                              ";
        gotoxy(45, 50); cout << "                                              ";
        gotoxy(45, 51); cout << "                                                  ";
        gotoxy(45, 52); cout << "                                                  ";
        gotoxy(45, 53); cout << "                                                  ";
        gotoxy(45, 54); cout << "                                                  ";
        gotoxy(45, 55); cout << "                                                  ";
        gotoxy(45, 56); cout << "                                                 ";
        gotoxy(45, 57); cout << "                                                    ";
        gotoxy(45, 58); cout << "                                                    ";
        gotoxy(45, 59); cout << "                                                    ";
        gotoxy(0, 31); cout << "                                                     ";
        gotoxy(0, 31); cin >> menuvar;

        while (menuvar > 11 || menuvar <= 0) {
            gotoxy(0, 31); cout << "               ";
            gotoxy(0, 31); cin >> menuvar;
        }
        decisiones(menuvar);
    }

    gotoxy(45, 23); cout << "                               ";
}
//Menu 
void menu() {
    //Menu se debe presentar debajo de la presentacion de los cosos
    gotoxy(0, 19); cout << "------------Menu-----------";
    gotoxy(0, 20); cout << "1) Generar parejas";
    gotoxy(0, 21); cout << "2) Generar hijos";
    gotoxy(0, 22); cout << "3) Enfermedad covid";
    gotoxy(0, 23); cout << "4) Destruccion global";
    gotoxy(0, 24); cout << "5) Lucha del mas fuerte";
    gotoxy(0, 25); cout << "6) Avance de tiempo";
    gotoxy(0, 26); cout << "7) Resucitar";
    gotoxy(0, 27); cout << "8) Ir al cine";
    gotoxy(0, 28); cout << "9) Identificacion y reporte";
    gotoxy(0, 29); cout << "10) Cliente - Servidor";
    gotoxy(0, 30); cout << "***Seleccione una opcion***(Salir con 11)";
    gotoxy(0, 31); cin >> menuvar;
    while (menuvar > 11 || menuvar <= 0) {
        gotoxy(0, 31); cout << "               ";
        gotoxy(0, 31); cin >> menuvar;
    }
    decisiones(menuvar);
    while (menuvar!=11) {
        vueltapregunta();
    }
}


int main()
{
    srand(time(NULL));
    menuprimer();//decision logica
    creacionprimergrupo();//decision logica
    if (cargadabinario()) {
      system("cls");
    }
    guardadobinario();
    presentacionmenu();
    menu();
    return 0;
}
