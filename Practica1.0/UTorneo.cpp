//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UTorneo.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------

void torneo_inicializar(TTorneo &t){

        t.num_equipos = 0;
}

int torneo_numero_equipos(TTorneo t){

        return t.num_equipos;
}

bool torneo_nombre_equipo(TTorneo t, int id_equipo, AnsiString &nombre_equipo){

        if((id_equipo >= 0) && (id_equipo < t.num_equipos)){
                nombre_equipo = t.equipos_nombres[id_equipo];
                return true;
        }
        else
                return false;
}

int torneo_info_partido(TTorneo &t, int id_local, int id_visitante, int &goles_local, int &goles_visitante){

        if((id_local != id_visitante) && ((id_local >= 0) && (id_local < t.num_equipos) &&
        (id_visitante >= 0) && (id_visitante < t.num_equipos))){
                if(t.partidos[id_local][id_visitante].jugado){
                        goles_local = t.partidos[id_local][id_visitante].goles_local;
                        goles_visitante = t.partidos[id_local][id_visitante].goles_visitante;
                        return 0;
                }
                else
                        return -2;

        }
        else
                return -1;
}

bool torneo_linea_clasificacion(TTorneo t, int pos, int &id_equipo, int &partidos_casa,
int &partidos_fuera, int &partidos_ganados, int &partidos_empatados,int &partidos_perdidos,
int &goles_favor, int &goles_contra, int &puntos){

        if((pos >= 0) && (pos < t.num_equipos)){
                partidos_casa = t.clasificacion[pos].partidos_casa;
                partidos_fuera = t.clasificacion[pos].partidos_fuera;
                partidos_ganados = t.clasificacion[pos].partidos_ganados;
                partidos_empatados = t.clasificacion[pos].partidos_empatados;
                partidos_perdidos = t.clasificacion[pos].partidos_perdidos;
                goles_favor = t.clasificacion[pos].goles_favor;
                goles_contra = t.clasificacion[pos].goles_contra;
                puntos = t.clasificacion[pos].puntos;
                id_equipo =  t.clasificacion[pos].id_equipo;
                return true;
        }
        else
                return false;
}

int torneo_anyadir_equipo(TTorneo &t, AnsiString nombre_equipo){

        if (MAX_EQUIPOS == t.num_equipos) return -1;
        else
                if (existe_equipo(t, nombre_equipo)) return -2;
        else{
                t.equipos_nombres[t.num_equipos] = nombre_equipo;
                int id_equipo = t.num_equipos;
                t.num_equipos++;
                for(int i = 0; i< t.num_equipos;i++){
                        t.partidos[i][id_equipo].jugado = false;
                        t.partidos[id_equipo][i].jugado = false;
                }
                TResumenEquipo aux;
                aux.id_equipo = id_equipo;
                aux.partidos_casa = 0;
                aux.partidos_fuera = 0;
                aux.partidos_ganados = 0;
                aux.partidos_empatados = 0;
                aux.partidos_perdidos = 0;
                aux.goles_favor = 0;
                aux.goles_contra = 0;
                aux.puntos = 0;
                t.clasificacion[t.num_equipos-1] = aux; //lo añade el ultimo y luego ordena
                t.equipos_posiciones[id_equipo] = t.num_equipos-1;
                ordenaTablas(t,aux);
                return id_equipo;
        }
}

bool existe_equipo(TTorneo t, AnsiString s){

        int i =0;
        bool encontrado = false;
        while((!encontrado) && (i < t.num_equipos)){
                encontrado = t.equipos_nombres[i] == s;
                i++;
       }
       return encontrado;
}

void ordenaTablas(TTorneo &t,TResumenEquipo a){

        int aux = t.equipos_posiciones[a.id_equipo];
        int i =0;
        bool encontrado = false;
        while((t.clasificacion[i].puntos > a.puntos)&&(i < t.num_equipos))
                i++;
        while(!encontrado){
                        if(i == aux)
                                encontrado = true;
                        else
                        if(t.clasificacion[i].puntos == a.puntos){
                                TResumenEquipo b = t.clasificacion[i];
                                if(b.goles_favor > a.goles_favor)
                                        i++;
                                else
                                if ((b.goles_favor == a.goles_favor)&&(b.goles_favor-b.goles_contra > a.goles_favor-a.goles_contra))
                                        i++;
                                else
                                if ((b.goles_favor == a.goles_favor)&&(b.goles_favor-b.goles_contra == a.goles_favor-a.goles_contra)&&
                                (t.equipos_nombres[b.id_equipo] < t.equipos_nombres[a.id_equipo]))
                                        i++;
                                else
                                        encontrado = true;
                        }
                        else
                                encontrado = true;
        }
        for(int j = aux; j > i; j--){
                t.clasificacion[j] = t.clasificacion[j-1];
                t.equipos_posiciones[t.clasificacion[j].id_equipo] = j;
        }
        t.clasificacion[i] = a;
        t.equipos_posiciones[a.id_equipo] = i;
}

int torneo_anyadir_partido(TTorneo &t, int id_local, int id_visitante, int goles_local, int goles_visitante){

        if((id_local < 0) || (id_local >= t.num_equipos) || (id_visitante < 0) || (id_visitante >= t.num_equipos) ||
        (id_local == id_visitante))
                return -1;
        else
        if(t.partidos[id_local][id_visitante].jugado)
                return -2;
        else
        if((goles_local < 0) || (goles_visitante < 0))
                return -3;
        else{
                t.partidos[id_local][id_visitante].jugado = true;
                t.partidos[id_local][id_visitante].goles_local = goles_local;
                t.partidos[id_local][id_visitante].goles_visitante = goles_visitante;
                if(goles_local > goles_visitante){ //EQUIPO LOCAL GANA
                        TResumenEquipo local = t.clasificacion[t.equipos_posiciones[id_local]];
                        TResumenEquipo visitante = t.clasificacion[t.equipos_posiciones[id_visitante]];
                        local.partidos_casa++;
                        visitante.partidos_fuera++;
                        local.partidos_ganados++;
                        visitante.partidos_perdidos++;
                        local.goles_favor = local.goles_favor + goles_local;
                        local.goles_contra = local.goles_contra + goles_visitante;
                        visitante.goles_favor = visitante.goles_favor + goles_visitante;
                        visitante.goles_contra = visitante.goles_contra + goles_local;
                        local.puntos = local.puntos + 3;
                        t.clasificacion[t.equipos_posiciones[id_local]] = local;
                        ordenaTablas(t,local);
                        t.clasificacion[t.equipos_posiciones[id_visitante]] = visitante;
                        ordenaTablas(t,visitante);
                }
                if(goles_local < goles_visitante){
                        TResumenEquipo local = t.clasificacion[t.equipos_posiciones[id_local]];
                        TResumenEquipo visitante = t.clasificacion[t.equipos_posiciones[id_visitante]];
                        local.partidos_casa++;
                        visitante.partidos_fuera++;
                        visitante.partidos_ganados++;
                        local.partidos_perdidos++;
                        local.goles_favor = local.goles_favor + goles_local;
                        local.goles_contra = local.goles_contra + goles_visitante;
                        visitante.goles_favor = visitante.goles_favor + goles_visitante;
                        visitante.goles_contra = visitante.goles_contra + goles_local;
                        visitante.puntos = visitante.puntos + 3;
                        t.clasificacion[t.equipos_posiciones[id_local]] = local;
                        ordenaTablas(t,local);
                        t.clasificacion[t.equipos_posiciones[id_visitante]] = visitante;
                        ordenaTablas(t,visitante);
                }
                if(goles_local == goles_visitante){
                        TResumenEquipo local = t.clasificacion[t.equipos_posiciones[id_local]];
                        TResumenEquipo visitante = t.clasificacion[t.equipos_posiciones[id_visitante]];
                        local.partidos_casa++;
                        visitante.partidos_fuera++;
                        local.partidos_empatados++;
                        visitante.partidos_empatados++;
                        local.goles_favor = local.goles_favor + goles_local;
                        local.goles_contra = local.goles_contra + goles_visitante;
                        visitante.goles_favor = visitante.goles_favor + goles_visitante;
                        visitante.goles_contra = visitante.goles_contra + goles_local;
                        local.puntos = local.puntos + 1;
                        visitante.puntos = visitante.puntos + 1;
                        t.clasificacion[t.equipos_posiciones[id_local]] = local;
                        ordenaTablas(t,local);
                        t.clasificacion[t.equipos_posiciones[id_visitante]] = visitante;
                        ordenaTablas(t,visitante);
                }
        return 0;
        }
}

bool torneo_borrar_equipo(TTorneo &t, int id_equipo){

	if((id_equipo >= 0) && (id_equipo < t.num_equipos)){
                for(int i = 0; i < t.num_equipos; i++){
                        torneo_borrar_partido(t,id_equipo,i);
                        torneo_borrar_partido(t,i,id_equipo);
                }
                for(int i = id_equipo; i < t.num_equipos-1; i++){
                        for(int j = id_equipo; j < t.num_equipos-1; j++){
                                t.partidos[i-id_equipo][j] = t.partidos[i-id_equipo][j+1];
                                t.partidos[i][j-id_equipo] = t.partidos[i+1][j-id_equipo];
                                t.partidos[i][j] = t.partidos[i+1][j+1];
                        }
                }
                int pos = t.equipos_posiciones[id_equipo];// si pos se pone arriba no tiene en cuenta los borrar_partido!!
                for(int i = pos; i < t.num_equipos-1; i++){
                        t.clasificacion[i] = t.clasificacion[i+1];
                        t.equipos_posiciones[t.clasificacion[i].id_equipo] = i;
                }
                for(int i = id_equipo; i < t.num_equipos-1; i++){
                        t.equipos_posiciones[i] = t.equipos_posiciones[i+1];
                        t.equipos_nombres[i] = t.equipos_nombres[i+1];
                        t.clasificacion[t.equipos_posiciones[i]].id_equipo--;
                }
                t.num_equipos--;
                return  true;
	}
	else
                return false;
}

int torneo_borrar_partido(TTorneo &t, int id_local, int id_visitante){

        if((id_local < 0) || (id_local >= t.num_equipos) || (id_visitante < 0) || (id_visitante >= t.num_equipos) ||
        (id_local == id_visitante))
                return -1;
        else
        if(!t.partidos[id_local][id_visitante].jugado)
                return -2;
        else{
                TPartido p = t.partidos[id_local][id_visitante];
                TResumenEquipo equipoL = t.clasificacion[t.equipos_posiciones[id_local]];
                TResumenEquipo equipoV = t.clasificacion[t.equipos_posiciones[id_visitante]];
                equipoL.partidos_casa--;
                equipoV.partidos_fuera--;
                equipoL.goles_favor = equipoL.goles_favor - p.goles_local;
                equipoL.goles_contra = equipoL.goles_contra - p.goles_visitante;
                equipoV.goles_favor = equipoV.goles_favor - p.goles_visitante;
                equipoV.goles_contra = equipoV.goles_contra - p.goles_local;
                if(p.goles_local > p.goles_visitante){
                        equipoL.puntos = equipoL.puntos-3;
                        equipoL.partidos_ganados--;
                        equipoV.partidos_perdidos--;
                }
                else
                if(p.goles_local < p.goles_visitante){
                        equipoV.puntos = equipoV.puntos-3;
                        equipoV.partidos_ganados--;
                        equipoL.partidos_perdidos--;
                }
                else
                if(p.goles_local == p.goles_visitante){
                        equipoL.puntos--;
                        equipoV.puntos--;
                        equipoL.partidos_empatados--;
                        equipoV.partidos_empatados--;
                }
                int pos = t.equipos_posiciones[id_local];
                for(int i = pos; i < t.num_equipos-1; i++){
                        t.clasificacion[i] = t.clasificacion[i+1];
                        t.equipos_posiciones[t.clasificacion[i].id_equipo] = i;
                }
                t.clasificacion[t.num_equipos-1] = equipoL;
                t.equipos_posiciones[id_local] = t.num_equipos-1;
                pos = t.equipos_posiciones[id_visitante];
                for(int i = pos; i < t.num_equipos-1; i++){
                        t.clasificacion[i] = t.clasificacion[i+1];
                        t.equipos_posiciones[t.clasificacion[i].id_equipo] = i;
                }
                t.clasificacion[t.num_equipos-1] = equipoV;
                t.equipos_posiciones[id_visitante] = t.num_equipos-1;
                ordenaTablas(t,equipoL);
                ordenaTablas(t,equipoV);
                t.partidos[id_local][id_visitante].jugado = false;
                return 0;
        }
}

void torneo_abrir(TTorneo &t, AnsiString f){

        ifstream a;
        a.open(f.c_str());
        torneo_inicializar(t);
        int equiposN;
        string tmp;
        AnsiString s;
        getline(a, tmp);
        s = tmp.c_str();
        equiposN = StrToInt(s);
        for(int i = 0; i < equiposN; i++){
                string tmp;
                AnsiString s;
                getline(a,tmp);
                s = tmp.c_str();
                torneo_anyadir_equipo(t,s);
        }
        while(!a.eof()){
                int idL,idV,gL,gV;
                string s;
                a >> idL >> idV >> gL >> gV;
                getline(a,s);
                torneo_anyadir_partido(t,idL,idV,gL,gV);
        }
        a.close();
}

void torneo_guardar(TTorneo &t, AnsiString f){

        ofstream a;
        a.open(f.c_str());
        a << t.num_equipos << endl;
        for(int i = 0; i < t.num_equipos; i++){
                a << t.equipos_nombres[i].c_str() << endl;
        }
        for(int i = 0; i < t.num_equipos; i++){
                for(int j = 0; j < t.num_equipos; j++){
                        if(t.partidos[i][j].jugado)
                                a << i <<" "<< j <<" "<< t.partidos[i][j].goles_local <<" "<< t.partidos[i][j].goles_visitante << endl;
                }
        }
        a.close();
}

