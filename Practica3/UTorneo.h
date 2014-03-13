//---------------------------------------------------------------------------

#ifndef UTorneoH
#define UTorneoH
#include "iostream.h"
#include <fstream>

//---------------------------------------------------------------------------

struct TEquipo{
        AnsiString nombre;
        int partidos_casa;
        int partidos_fuera;
        int partidos_ganados;
        int partidos_empatados;
        int partidos_perdidos;
        int goles_favor;
        int goles_contra;
        int puntos;
};

//---------------------------------------------------------------------------

struct ListaEquipos{
        TEquipo *info;
        ListaEquipos *sig;
};

//---------------------------------------------------------------------------

struct TEquipos{
        ListaEquipos *primero;
        ListaEquipos *ultimo;
};

//---------------------------------------------------------------------------

struct TPartido{
        TEquipo *equipo_local;
        TEquipo *equipo_visitante;
        int goles_local;
        int goles_visitante;
};

//---------------------------------------------------------------------------

struct ArbolPartidos{
        TPartido info;
        ArbolPartidos *izq;
        ArbolPartidos *der;
};

//---------------------------------------------------------------------------

struct TTorneo{
        int num_equipos;
        TEquipos equipos;
        TEquipos clasificacion;
        ArbolPartidos *partidos;
};

//---------------------------------------------------------------------------

void torneo_inicializar(TTorneo &t);

int torneo_numero_equipos(TTorneo t);

bool torneo_nombre_equipo(TTorneo t, int id_equipo, AnsiString &nombre_equipo);

int torneo_info_partido(TTorneo &t, int id_local, int id_visitante, int &goles_local, int &goles_visitante);

bool torneo_linea_clasificacion(TTorneo t, int pos, int &id_equipo, int &partidos_casa,
int &partidos_fuera, int &partidos_ganados, int &partidos_empatados,int &partidos_perdidos,
int &goles_favor, int &goles_contra, int &puntos);

int torneo_anyadir_equipo(TTorneo &t, AnsiString nombre_equipo);

int torneo_anyadir_partido(TTorneo &t, int id_local, int id_visitante, int goles_local,int goles_visitante);

bool torneo_borrar_equipo(TTorneo &t, int id_equipo);

int torneo_borrar_partido(TTorneo &t, int id_local, int id_visitante);

void torneo_abrir(TTorneo &t, AnsiString f);

void torneo_guardar(TTorneo &t, AnsiString f);

void torneo_limpiar(TTorneo &t);

bool partido_mayor(TPartido A,TPartido B);
//AUXILIARES
void ordenaTablas(TTorneo &t, TEquipo *a); //ordena la clasificacion y equipos_posiciones
bool existe_equipo(TTorneo t, AnsiString s);
void quitarEquipoClasificacion(TTorneo &t, int pos);
void borrar_arbol(ArbolPartidos *p);
void guardar_partidos(TTorneo t,ArbolPartidos *p,ofstream &a);

//---------------------------------------------------------------------------

#endif
