# 🌱 Juego de la Vida — Simulación Social en C++

Proyecto desarrollado en **C++** utilizando **Microsoft Visual Studio**.  
Implementa una versión extendida y creativa del clásico *Juego de la Vida* de **John Conway**, adaptada al comportamiento humano.  
En esta simulación, las "personas" evolucionan en un entorno social donde pueden **interactuar, enfermar, reproducirse, luchar y sobrevivir** a eventos globales.

---

## 🧩 Descripción general

El programa permite observar cómo una población simulada evoluciona a lo largo del tiempo.  
Cada persona tiene atributos propios (nombre, edad, casado, hijo, sangre, etc.) y puede interactuar con otros según reglas lógicas.

La ejecución se realiza completamente en **consola**, mostrando un **menú interactivo** que ofrece distintas acciones.  
Cada opción modifica el estado de la sociedad, almacenando los datos de forma persistente para futuras sesiones.

---

## ⚙️ Características principales

- ✅ Implementación completa en **C++ (Visual Studio)**  
- ✅ **Simulación social compleja** con múltiples factores  
- ✅ **Menú interactivo** con más de 10 opciones  
- ✅ **Persistencia de datos** para mantener el progreso  
- ✅ **Modelado orientado a objetos** (clases como `Persona`)  
- ✅ **Eventos dinámicos:** enfermedad, destrucción, paso del tiempo, resurrección  
- ✅ **Modo cliente-servidor** para el intercambio de personas de un equipo a otro.

---

## 🧮 Menú principal

Al iniciar el programa, se solicita ingresar el número 0 para empezar con las creación
de las 100 personas con las que se va a jugar y la información de cada uno se 
almacenará en un archivo binario, y en caso de que este archivo se halla generado anteriormente en otra jugada,
se el programa omite esta opción y simplemente cargará el binario con la información de las personas almacenadas. 
Después de ese punto, se muestra el siguiente menú:

1. **Generar Parejas:**  
   Empareja personas disponibles siguiendo reglas de compatibilidad (edad, género, estado civil).  
   Las parejas se almacenan en el sistema y pueden luego generar descendencia.

2. **Generar Hijos:**  
   Crea descendencia a partir de las parejas establecidas, heredando características de los padres.  
   Los hijos se añaden a la población y participan en eventos posteriores.

3. **Enfermedad COVID:**  
   Simula una pandemia global donde parte de la población puede enfermar o morir según una probabilidad.  
   Aplica un modelo de contagio aleatorio y tasas de supervivencia.

4. **Destrucción Global:**  
   Evento catastrófico (como guerra o desastre natural) que elimina un porcentaje significativo de la población.  

5. **Luchas del más fuerte:**  
   Simulación de competencia por supervivencia.  
   Dos personas se enfrentan, se atacan de forma aleatoria y sólo una sobrevive.

6. **Avance del Tiempo:**  
   Aumenta la edad de todos los individuos y actualiza sus estados vitales (vejez, muerte natural, nuevas generaciones).

7. **Resucitar:**  
   Permite traer de vuelta a la vida a individuos previamente eliminados, demostrando control sobre el ciclo vital.

8. **Ir al Cine:**  
   Evento social que permite interacción entre individuos, las familias, parejas e individuos que asistan de forma aleatoria deberán tener una distancia de 1 puesto.

9. **Identificación y Reporte:**  
   Permite mostrar la información de una persona seleccionada o exportar su información o el de toda la población mediante un JSON.

10. **Cliente - Servidor:**  
    Implementa un modo básico de comunicación entre programas de distintos equipos pero estos deben estar conectados mediante cable de red.  
    Permite enviar o recibir personas.

11. **Salir:**  
    Finaliza la simulación y guarda el estado actual de la población en archivo.

---

## 🧠 Lógica del sistema

El sistema se basa en **clases y estructuras** que representan personas y relaciones sociales.  
Cada acción del menú modifica los atributos de los objetos almacenados en memoria y actualiza el archivo de datos.

**Conceptos principales:**
- Ciclo de vida: nacimiento → madurez → muerte → posible resurrección.  
- Relaciones: cada persona puede tener pareja e hijos.  
- Eventos: afectan a toda la población (enfermedad, destrucción, luchas).  
- Persistencia: los datos se guardan y cargan automáticamente entre ejecuciones.  
- Cliente-servidor: comunicación experimental para compartir datos entre ejecuciones.

---

## 🕹️ Instrucciones de uso

1. Abre **Microsoft Visual Studio**.  
2. Carga el archivo de solución:
3. Compila con **Ctrl + Shift + B**.  
4. Ejecuta con **Ctrl + F5**.  
5. Usa el menú en consola para explorar las distintas simulaciones.

Durante la ejecución:
- Las acciones se eligen escribiendo el número correspondiente.  
- Algunos eventos afectan aleatoriamente a los personajes.  
- El programa mostrará resultados y actualizaciones en tiempo real.

---

## 💾 Archivos incluidos

| Archivo | Descripción |
|----------|-------------|
| `ProyectoVida.cpp` | Código principal (menú y flujo de ejecución). |
| `Persona.cpp` | Clase o estructura que define las características de cada persona. |
| `Proyecto del juego de la vida.pdf` | Manual del usuario con reglas y menús del sistema. |
| `ProyectoVida.sln`, `.vcxproj` | Archivos del entorno de Visual Studio. |

---

## 📊 Requisitos

- **Microsoft Visual Studio 2019 o superior**  
- Compilador compatible con **C++17**  
- Sistema operativo **Windows 10/11**

---

## 🧑‍💻 Autoría

**Proyecto realizado por:**  
> 👩‍💻 **Tiffany Andrea Jordán Uquillas**  

Desarrollado como práctica académica de simulación, estructuras de datos y programación orientada a objetos.

---

## 📝 Licencia

Este proyecto se publica con fines **educativos y personales**.  
Puede ser utilizado, modificado o ampliado siempre que se cite la autoría original.

---
