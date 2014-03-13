//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "UTorneo.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

//---------------------------------------------------------------------------

void torneo_inicializar(TTorneo &t){

        t.num_equipos = 0;
        t.equipos.ultimo = NULL;
        t.equipos.primero = t.equipos.ultimo;
        t.clasificacion.ultimo = NULL;
        t.clasificacion.primero = t.clasificacion.ultimo;
        t.partidos = NULL;
}

int torneo_numero_equipos(TTorneo t){

        return t.num_equipos;
}

bool torneo_nombre_equipo(TTorneo t, int id_equipo, AnsiString &nombre_equipo){

        if((id_equipo >= 0) && (id_equipo < t.num_equipos)){
                ListaEquipos *aux;
                aux = t.equipos.primero;
                for(int i = 0; i < id_equipo;i++){
                        aux = aux->sig;
                }
                nombre_equipo = aux->info->nombre;
                aux = NULL;
                delete aux;
                return true;
        }
        else
                return false;
}

int torneo_info_partido(TTorneo &t, int id_local, int id_visitante, int &goles_local, int &goles_visitante){

        if((id_local != id_visitante) && ((id_local >= 0) && (id_local < t.num_equipos) &&
        (id_visitante >= 0) && (id_visitante < t.num_equipos))){
                ListaEquipos *local;
                local = t.equipos.primero;
                for(int i = 0; i < id_local;i++){
                        local = local->sig;
                }
                ListaEquipos *visitante;
                visitante = t.equipos.primero;
                for(int i = 0; i < id_visitante;i++){
                        visitante = visitante->sig;
                }
                ListaPartidos* aux;
                aux = t.partidos;
                bool encontrado = false;
                while((aux != NULL)&&(!encontrado)){
                        if((aux->info.equipo_local == local->info)&&(aux->info.equipo_visitante == visitante->info))
                                encontrado = true;
                        else{
                                aux = aux->sig;
                        }
                }
                if(encontrado){
                goles_local = aux->info.goles_local;
                goles_visitante = aux->info.goles_visitante;
                local = visitante = NULL;
                aux = NULL;
                delete local;
                delete visitante;
                delete aux;
                return 0;
                }
                else{
                        local = visitante = NULL;
                        aux = NULL;
                        delete local;
                        delete visitante;
                        delete aux;
                        return -2;
                }
        }
        else
                return -1;
}

bool torneo_linea_clasificacion(TTorneo t, int pos, int &id_equipo, int &partidos_casa,
int &partidos_fuera, int &partidos_ganados, int &partidos_empatados,int &partidos_perdidos,
int &goles_favor, int &goles_contra, int &puntos){

        if((pos >= 0) && (pos < t.num_equipos)){
                ListaEquipos *aux;
                aux = t.clasificacion.primero;
                for(int i = 0; i< pos; i++)
                        aux = aux->sig;
                partidos_casa = aux->info->partidos_casa;
                partidos_fuera = aux->info->partidos_fuera;
                partidos_ganados = aux->info->partidos_ganados;
                partidos_empatados = aux->info->partidos_empatados;
                partidos_perdidos = aux->info->partidos_perdidos;
                goles_favor = aux->info->goles_favor;
                goles_contra = aux->info->goles_contra;
                puntos = aux->info->puntos;
                ListaEquipos *aux2;
                aux2 = t.equipos.primero;
                int i = 0;
                while(aux2->info != aux->info){
                        aux2 = aux2->sig;
                        i++;
                }
                id_equipo = i;
                aux = aux2 = NULL;
                delete aux;
                delete aux2;
                return true;
        }
        else
                return false;
}

int torneo_anyadir_equipo(TTorneo &t, AnsiString nombre_equipo){

        if (existe_equipo(t, nombre_equipo))
                return -2;
        else{
                TEquipo *aux = new TEquipo;
                aux->nombre = nombre_equipo;
                aux->partidos_casa = 0;
                aux->partidos_fuera = 0;
                aux->partidos_ganados = 0;
                aux->partidos_empatados = 0;
                aux->partidos_perdidos = 0;
                aux->goles_favor = 0;
                aux->goles_contra = 0;
                aux->puntos = 0;
                ListaEquipos *e = new ListaEquipos;
                ListaEquipos *c = new ListaEquipos;
                c->info = aux;
                c->sig = NULL;
                e->info = aux;
                e->sig = NULL;
                if(t.num_equipos == 0){
                        t.equipos.ultimo = e;
                        t.equipos.primero = t.equipos.ultimo;
                        t.clasificacion.ultimo= c;
                        t.clasificacion.primero = t.clasificacion.ultimo;
                }
                else{
                        t.equipos.ultimo->sig = e;
                        t.equipos.ultimo = t.equipos.ultimo->sig;
                        t.clasificacion.ultimo->sig = c;
                        t.clasificacion.ultimo = t.clasificacion.ultimo->sig;
                }
                t.num_equipos++;
                ordenaTablas(t,aux);
                return 0;
        }
}

bool existe_equipo(TTorneo t, AnsiString s){

        int i =0;
        ListaEquipos *aux;
        aux = t.equipos.primero;
        bool encontrado = false;
        while((!encontrado) && (i < t.num_equipos)){
                encontrado = aux->info->nombre == s;
                aux = aux->sig;
                i++;
       }
       aux = NULL;
       delete aux;
       return encontrado;
}

void ordenaTablas(TTorneo &t,TEquipo *a){

        ListaEquipos *i = t.clasificacion.primero; // posicion nueva en la lista
        int pos_nueva = 0;
        bool encontrado = false;
        ListaEquipos *b = t.clasificacion.primero; // posicion actual en la lista
        int pos_act = 0;
        while(b->info != a){
                pos_act++;
                b = b->sig;
        }
        while((i->info->puntos > a->puntos)&&(i != NULL)){
                i = i->sig;
                pos_nueva++;
        }
        while((!encontrado)&&(pos_nueva < t.num_equipos)){
                        if(i->info->nombre == a->nombre)
                                encontrado = true;
                        else
                        if(i->info->puntos == a->puntos){
                                if(i->info->goles_favor > a->goles_favor){
                                        i = i->sig;
                                        pos_nueva++;
                                }
                                else
                                if ((i->info->goles_favor == a->goles_favor)&&(i->info->goles_favor-i->info->goles_contra > a->goles_favor-a->goles_contra)){
                                        i = i->sig;
                                        pos_nueva++;
                                }
                                else
                                if ((i->info->goles_favor == a->goles_favor)&&(i->info->goles_favor-i->info->goles_contra == a->goles_favor-a->goles_contra)&&
                                (i->info->nombre < a->nombre)){
                                        i = i->sig;
                                        pos_nueva++;
                                }
                                else
                                        encontrado = true;
                        }
                        else
                                encontrado = true;
        }
        if(pos_nueva < pos_act){//cuando se juegan partidos o cuando se añade equipo nuevo que va por encima del ultimo
                quitarEquipoClasificacion(t,pos_act);
                ListaEquipos *aux = new ListaEquipos;
                aux->info = a;
                aux->sig = NULL;
                i = t.clasificacion.primero;
                if(pos_nueva == 0){
                        aux->sig = t.clasificacion.primero;
                        t.clasificacion.primero = aux;
                }
                else{
                        for(int j = 0; j < pos_nueva-1;j++)
                                i = i->sig;
                        aux->sig = i->sig;
                        i->sig = aux;
                }
        }
        i = b = NULL;
        delete i;
        delete b;
}

void quitarEquipoClasificacion(TTorneo &t,int pos){
        ListaEquipos *aux = t.clasificacion.primero;
        if(pos == 0){
                t.clasificacion.primero = t.clasificacion.primero->sig;
                aux->sig = NULL;
                aux->info = NULL;
                delete aux;
        }
        else{
                ListaEquipos *a;
                for(int i = 0; i < pos-1;i++)
                        aux = aux->sig;
                a = aux->sig;
                aux->sig = a->sig;
                a->sig = NULL;
                if(pos == t.num_equipos-1){
                        t.clasificacion.ultimo = aux;
                }
                a->info = NULL;
                delete a;
        }
}

int torneo_anyadir_partido(TTorneo &t, int id_local, int id_visitante, int goles_local, int goles_visitante){

        if((id_local < 0) || (id_local >= t.num_equipos) || (id_visitante < 0) || (id_visitante >= t.num_equipos) ||
        (id_local == id_visitante))
                return -1;
        else
                if((goles_local < 0) || (goles_visitante < 0))
                        return -3;
        else{
                ListaEquipos *l = t.equipos.primero;
                ListaEquipos *v = t.equipos.primero;
                for(int i = 0; i < id_local;i++)//localiza equipo local
                        l = l->sig;
                for(int i = 0; i < id_visitante;i++)//localiza equipo visitante
                        v = v->sig;
                bool encontrado = false;
                ListaPartidos *p;
                p = t.partidos;
                while((p != NULL) && (!encontrado)){
                        encontrado = (p->info.equipo_local == l->info) && (p->info.equipo_visitante == v->info);
                        p = p->sig;
                }
                if(encontrado)
                        return -2;
                ListaPartidos *partido = new ListaPartidos;
                partido->info.goles_local = goles_local;
                partido->info.goles_visitante = goles_visitante;
                partido->info.equipo_local = l->info;
                partido->info.equipo_visitante = v->info;
                partido->sig = t.partidos;
                t.partidos = partido;
                if(goles_local > goles_visitante){ //EQUIPO LOCAL GANA
                        l->info->partidos_casa++;
                        l->info->partidos_ganados++;
                        l->info->goles_favor = l->info->goles_favor + goles_local;
                        l->info->goles_contra = l->info->goles_contra + goles_visitante;
                        l->info->puntos = l->info->puntos + 3;
                        ordenaTablas(t,l->info);
                        v->info->partidos_fuera++;
                        v->info->partidos_perdidos++;
                        v->info->goles_favor = v->info->goles_favor + goles_visitante;
                        v->info->goles_contra = v->info->goles_contra + goles_local;
                        ordenaTablas(t,v->info);
                }
                if(goles_local < goles_visitante){
                        l->info->partidos_casa++;
                        l->info->partidos_perdidos++;
                        l->info->goles_favor = l->info->goles_favor + goles_local;
                        l->info->goles_contra = l->info->goles_contra + goles_visitante;
                        ordenaTablas(t,l->info);
                        v->info->partidos_fuera++;
                        v->info->partidos_ganados++;
                        v->info->goles_favor = v->info->goles_favor + goles_visitante;
                        v->info->goles_contra = v->info->goles_contra + goles_local;
                        v->info->puntos = v->info->puntos + 3;
                        ordenaTablas(t,v->info);
                }
                if(goles_local == goles_visitante){
                        l->info->partidos_casa++;
                        l->info->partidos_empatados++;
                        l->info->goles_favor = l->info->goles_favor + goles_local;
                        l->info->goles_contra = l->info->goles_contra + goles_visitante;
                        l->info->puntos = l->info->puntos + 1;
                        ordenaTablas(t,l->info);
                        v->info->partidos_fuera++;
                        v->info->partidos_empatados++;
                        v->info->goles_favor = v->info->goles_favor + goles_visitante;
                        v->info->goles_contra = v->info->goles_contra + goles_local;
                        v->info->puntos = v->info->puntos + 1;
                        ordenaTablas(t,v->info);
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
                ListaEquipos *c = t.clasificacion.primero;
                int pos = 0;
                ListaEquipos *aux = t.equipos.primero;
                for(int i = 0; i < id_equipo;i++)
                        aux = aux->sig;
                while(c->info != aux->info){
                        c = c->sig;
                        pos++;
                }
                quitarEquipoClasificacion(t,pos);
                aux = t.equipos.primero;
                if(id_equipo == 0){
                        t.equipos.primero = t.equipos.primero->sig;
                        delete aux->info;
                        aux->info = NULL;
                        aux->sig = NULL;
                        delete aux;
                }
                else{
                        for(int i = 0; i < id_equipo-1;i++)
                                aux = aux->sig;
                        ListaEquipos *a = aux->sig;
                        aux->sig = a->sig;
                        a->sig = NULL;
                        delete a->info;
                        a->info = NULL;
                        delete a;
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
        else{
                ListaEquipos *l = t.equipos.primero;
                ListaEquipos *v = t.equipos.primero;
                for(int i = 0; i < id_local;i++)
                        l = l->sig;
                for(int i = 0; i < id_visitante;i++)
                        v = v->sig;
                ListaPartidos *par = t.partidos;
                bool encontrado = false;
                int pos_partido = 0;
                while((par != NULL) && (!encontrado)){
                        encontrado = (par->info.equipo_local == l->info) && (par->info.equipo_visitante == v->info);
                        if(!encontrado){
                                par = par->sig;
                                pos_partido++;
                        }
                }
                if(!encontrado)
                        return -2;
                else{
                        l->info->partidos_casa--;
                        v->info->partidos_fuera--;
                        l->info->goles_favor = l->info->goles_favor - par->info.goles_local;
                        l->info->goles_contra = l->info->goles_contra - par->info.goles_visitante;
                        v->info->goles_favor = v->info->goles_favor - par->info.goles_visitante;
                        v->info->goles_contra = v->info->goles_contra - par->info.goles_local;
                        if(par->info.goles_local > par->info.goles_visitante){
                                l->info->puntos = l->info->puntos-3;
                                l->info->partidos_ganados--;
                                v->info->partidos_perdidos--;
                        }
                        else
                        if(par->info.goles_local < par->info.goles_visitante){
                                v->info->puntos = v->info->puntos-3;
                                v->info->partidos_ganados--;
                                l->info->partidos_perdidos--;
                        }
                        else
                        if(par->info.goles_local == par->info.goles_visitante){
                                l->info->puntos--;
                                v->info->puntos--;
                                l->info->partidos_empatados--;
                                v->info->partidos_empatados--;
                        }
                        ListaEquipos *aux = t.clasificacion.primero;
                        int pos_aux = 0;
                        while(aux->info != l->info){
                                aux = aux->sig;
                                pos_aux++;
                        }
                        quitarEquipoClasificacion(t,pos_aux);
                        ListaEquipos *nuevo = new ListaEquipos;
                        nuevo->info = l->info;
                        nuevo->sig = NULL;
                        t.clasificacion.ultimo->sig = nuevo;
                        t.clasificacion.ultimo = nuevo;
                        aux = t.clasificacion.primero;
                        pos_aux = 0;
                        while(aux->info != v->info){
                                aux = aux->sig;
                                pos_aux++;
                        }
                        quitarEquipoClasificacion(t,pos_aux);
                        ListaEquipos *nuevo2 = new ListaEquipos;
                        nuevo2->info = v->info;
                        nuevo2->sig = NULL;
                        t.clasificacion.ultimo->sig = nuevo2;
                        t.clasificacion.ultimo = nuevo2;
                        ordenaTablas(t,l->info);
                        ordenaTablas(t,v->info);
                        par = t.partidos;
                        for(int i = 0; i < pos_partido-1; i++)
                                par = par->sig;
                        ListaPartidos *a = par->sig;
                        if(pos_partido != 0){
                                par->sig = a->sig;
                                a->sig = NULL;
                                a->info.equipo_local = NULL;
                                a->info.equipo_visitante = NULL;
                                delete a;
                        }
                        else{
                                t.partidos = par->sig;
                                par->sig = NULL;
                                par->info.equipo_local = NULL;
                                par->info.equipo_visitante = NULL;
                                delete par;
                        }
                        return 0;
                }
        }
}

void torneo_abrir(TTorneo &t, AnsiString f){

        ifstream a;
        a.open(f.c_str());
        torneo_limpiar(t);
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
        ListaEquipos *aux = t.equipos.primero;
        for(int i = 0; i < t.num_equipos; i++){
                a << aux->info->nombre.c_str() << endl;
                aux = aux->sig;
        }
        ListaPartidos *par = t.partidos;
        while(par != NULL){
                ListaEquipos *l = t.equipos.primero;//id_equipo_local
                int pos_local = 0;
                while(l->info != par->info.equipo_local){
                        pos_local++;
                        l = l->sig;
                }
                ListaEquipos *v = t.equipos.primero;//id_equipo_visitante
                int pos_visitante = 0;
                while(v->info != par->info.equipo_visitante){
                        pos_visitante++;
                        v = v->sig;
                }
                l = v = NULL;
                delete l;
                delete v;
                a << pos_local <<" "<< pos_visitante <<" "<< par->info.goles_local <<" "<< par->info.goles_visitante << endl;
                par = par->sig;
        }
        a.close();
}

void torneo_limpiar(TTorneo &t){

        while(t.partidos != NULL){
                ListaPartidos *p = t.partidos;
                t.partidos = t.partidos->sig;
                p->sig = NULL;
                p->info.equipo_local = NULL;
                p->info.equipo_visitante = NULL;
                delete p;
        }
        delete t.partidos;
        t.clasificacion.ultimo = NULL;
        for(int i = 0; i < t.num_equipos;i++){
                ListaEquipos *c = t.clasificacion.primero;
                t.clasificacion.primero = c->sig;
                delete c->info;
                c->info = NULL;
                c->sig = NULL;
                delete c;
        }
        t.clasificacion.primero = NULL;
        delete t.clasificacion.primero;
        delete t.clasificacion.ultimo;
        t.equipos.ultimo = NULL;
        for(int i = 0; i < t.num_equipos;i++){
                ListaEquipos *e = t.equipos.primero;
                t.equipos.primero = e->sig;
                e->info = NULL;
                e->sig = NULL;
                delete e;
        }
        t.equipos.primero = NULL;
        delete t.equipos.primero;
        delete t.equipos.ultimo;
        t.num_equipos = 0;
}


