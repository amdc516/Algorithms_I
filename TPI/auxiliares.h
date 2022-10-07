#ifndef SOLUCION_AUXILIARES_H
#define SOLUCION_AUXILIARES_H

#include "definiciones.h"
bool vacia (vector<vector<dato>> m);
bool esMatriz (vector<vector<dato>> m);
bool individuoEnTabla (individuo p, eph_i ti);
bool hogarEnTabla (hogar h, eph_h th);
bool cantidadCorrectaDeColumnasI (eph_i ti);
bool cantidadCorrectaDeColumnasH (eph_h th);
bool hayHogarConCodigo (eph_h th, int c);
bool hayIndividuoConCodigo (eph_i ti, int c);
bool hayIndividuosSinHogares (eph_i ti, eph_h th);
bool hayHogaresSinIndividuos (eph_i ti, eph_h th);
bool mismoCodusuYComponente (individuo i1, individuo i2);
bool hayRepetidosI (eph_i ti);
bool hayRepetidosH (eph_h th);
bool mismoAnioYTrimestre (eph_i ti, eph_h th);
int cantHabitantes (hogar h, eph_i ti);
bool menosDe21MiembrosPorHogar (eph_h th, eph_i ti);
bool cantidadValidaDormitorios (eph_h th);
bool individuoValido (individuo ind);
bool valoresEnRangoI (eph_i ti);
bool hogarValido (hogar h);
bool valorRegionValido (int r);
bool valoresEnRangoH (eph_h th);
bool esValida (eph_h th, eph_i ti);

int cantMaxDeHabitacionesEnRegion(eph_h th, int region);

int encuentraHogar(int ind, eph_h th, eph_i ti);
float individuosValidosQueTrabajan(eph_h th, eph_i ti);
float individuosValidosQueTrabajanEnSuVivienda(eph_h th, eph_i ti);
float proporcionTeleworking(eph_h th, eph_i ti);

bool tieneCasaPropia(hogar h);
bool tieneCasaChica(hogar h, eph_i ti);

hogar hogarCorrespondienteAIndividuo(eph_h th, individuo i);

void ordenarPorRegionYCodusu(eph_h &th);
void ordenarPorCodusuDeHogarYComponente(eph_i &ti, eph_h &th);
void swap2(eph_h &th, int i, int j);
void ordenarPorCodusuDeHogarYComponente(eph_i &ti, eph_h &th);
void insertarIndividuo(eph_h &th, eph_i &ti, int i);
bool vivenJuntos(individuo ind1, individuo ind2);
bool suHogarEstaAntes(individuo ind1, individuo ind2, eph_h th);
void insertarHogar(eph_h &th, int i);

bool hogarEnTabla (hogar h, eph_h th);
bool esMuestraDeHogares (vector<hogar> mh, eph_h th);
int ingresos (hogar h, eph_i ti);
bool ordenadaPorIngresosConMismaDiferencia (vector<hogar> mh, eph_i ti);
bool esSolucionMuestraHomogenea (vector<hogar> mh, eph_h th, eph_i ti);
void swap (eph_h &th, int i, int j);
void insertar (eph_h &th, int i, eph_i ti);
eph_h insertionSort (eph_h th, eph_i ti);
eph_h  ordenadaPorIngresos (eph_h th, eph_i ti);
vector<hogar> secuenciaMasLarga (eph_h th, eph_i ti);

bool esCasa(hogar h);
bool esHogarValido(hogar h, int region);
int cantHogaresValidos(eph_h th, int region);
int cantHogaresValidosConHC(eph_h th, eph_i ti, int region);
float proporcionDeCasasConHCPorRegion(int region, eph_h th,eph_i ti);

eph_i coincidenConTodasLasBusquedas (vector<pair<int, dato>> busquedas, eph_i ti);
eph_i complementoBusqueda (vector<pair<int, dato>> busqueda, eph_i ti);
eph_h hogaresSegunBusqueda (vector<pair<int, dato>> busqueda, eph_h th, eph_i ti);
eph_h complementoHogaresEnBusqueda (vector<pair<int, dato>> busquedas, eph_h th, eph_i ti);
eph_h hogaresConIndNoCumplenBusq (vector<pair<int, dato>> busqueda, eph_h th, eph_i ti);
bool esBusquedaValida (vector<pair<int, dato>> busqueda);


float distanciaEuclideana(pair <int,int> centro, int latitud, int longitud);
int enQueAnilloEsta(float d, vector < int > distancias);


#endif //SOLUCION_AUXILIARES_H
