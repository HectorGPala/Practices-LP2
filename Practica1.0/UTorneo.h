//---------------------------------------------------------------------------

#ifndef UTorneoH
#define UTorneoH
#define MAX_EQUIPOS 20
#include "iostream.h"
#include <fstream>

//---------------------------------------------------------------------------

struct TPartido{
        boolean jugado;
        int goles_local;
        int  goles_visitante;
};

//---------------------------------------------------------------------------

struct TResumenEquipo{
        int id_equipo;
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

struct TTorneo{
        int num_equipos;
        AnsiString equipos_nombres[MAX_EQUIPOS];
        TPartido partidos[MAX_EQUIPOS][MAX_EQUIPOS];
        TResumenEquipo clasificacion[MAX_EQUIPOS];
        int equipos_posiciones[MAX_EQUIPOS];
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
//AUXILIARES
void ordenaTablas(TTorneo &t, TResumenEquipo a); //ordena la clasificacion y equipos_posiciones
void ordenaPosiciones(TTorneo &t, TResumenEquipo a);
bool existe_equipo(TTorneo t, AnsiString s);

//---------------------------------------------------------------------------

#endif
