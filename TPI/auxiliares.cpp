#include "definiciones.h"
#include "auxiliares.h"
#include "gtest/gtest.h"
#include "ejercicios.h"

//Ej 1

bool vacia (vector<vector<dato>> m){
    return  (m.size() == 0);
}

bool esMatriz (vector<vector<dato>> m){
    int i = 0;
    bool res = true;
    while (i < m.size() && res == true){
        if (m[i].size() != m[0].size()) {
            res = false;
        }
        i++;
    }
    return res;
}


bool individuoEnTabla (individuo p, eph_i ti){
    int i = 0;
    bool res = false;
    while (i < ti.size() && !res){
        if (p[INDCODUSU] == ti[i][INDCODUSU]) {
            res = true;
        }
        i++;
    }
    return res;
}


bool hogarEnTabla (hogar h, eph_h th){
    int i = 0;
    bool res = false;
    while (i < th.size() && !res){
        if (h[HOGCODUSU] == th[i][HOGCODUSU]) {
            res = true;
        }
        i++;
    }
    return res;
}

//Ya estoy suponiendo que vale que todas las filas tienen la misma cantidad de elementos
bool cantidadCorrectaDeColumnasI (eph_i ti){
    return ti[0].size() == FILAS_INDIVIDUO;
}
bool cantidadCorrectaDeColumnasH (eph_h th){
    return th[0].size() == FILAS_HOGAR;
}

bool hayHogarConCodigo (eph_h th, int c){
    bool res = false;
    int i = 0;
    while (i < th.size() && ! res){
        if (th[i][HOGCODUSU] == c)
            res = true;
        i++;
    }
    return res;
}

bool hayIndividuoConCodigo (eph_i ti, int c){
    bool res = false;
    int i = 0;
    while (i < ti.size() && ! res){
        if (ti[i][INDCODUSU] == c)
            res = true;
        i++;
    }
    return res;
}

bool hayIndividuosSinHogares (eph_i ti, eph_h th){
    bool res = false;

    int i = 0;
    while (i < ti.size() && !res){
        if (!hayHogarConCodigo(th, ti[i][INDCODUSU]))
            res = true;
        i++;
    }
    return res;
}

bool hayHogaresSinIndividuos (eph_i ti, eph_h th){
    bool res = false;

    int i = 0;
    while (i < th.size()){ //&& !res){
        if (!hayIndividuoConCodigo(ti, th[i][HOGCODUSU]))
            res = true;
        i++;
    }
    return res;
}

bool mismoCodusuYComponente (individuo i1, individuo i2){
    return i1[INDCODUSU] == i2[INDCODUSU] && i1[COMPONENTE] == i2[COMPONENTE];
}

bool hayRepetidosI (eph_i ti){
    bool res = false;

    int i = 0;
    while (i < ti.size() && ! res){
        int j = i + 1;
        while (j < ti.size() && ! res){
            if (mismoCodusuYComponente(ti[i], ti[j]))
                res = true;
            j++;
        }
        i++;
    }
    return res;
}

bool hayRepetidosH (eph_h th){
    bool res = false;

    int i = 0;
    while (i < th.size()){
        int j = i + 1;
        while (j < th.size()){
            if (th[i][HOGCODUSU] == th[j][HOGCODUSU])
                res = true;
            j++;
        }
        i++;
    }
    return res;
}

bool mismoAnioYTrimestre (eph_i ti, eph_h th){
    bool res = true;

    //bloque para determinar que todas las filas de ti tengan el mismo año y trimestre
    int i = 0;
    while (i < ti.size() && res){
        int j = i + 1;
        while (j < ti.size() && res){
            if ((ti[i][INDANIO] != ti[j][INDANIO]) ||
                (ti[i][INDTRIMESTRE] != ti[j][INDTRIMESTRE]))
                res = false;
            j++;
        }
        i++;
    }

    //bloque para determinar que todas las filas de th tengan el mismo año y trimestre
    int s = 0;
    while (s < th.size() && res){
        int k = s + 1;
        while (k < th.size() && res){
            if ((th[s][HOGANIO] != th[k][HOGANIO]) ||
                (th[s][HOGTRIMESTRE] != th[k][HOGTRIMESTRE]))
                res = false;
            k++;
        }
        s++;
    }

    //bloque para determinar que ambas tablas tengan el mismo año y trimestre
    if ((ti[0][INDANIO] != th[0][HOGANIO]) || (ti[0][INDTRIMESTRE] != th[0][HOGTRIMESTRE]))
        res = false;

    return res;
}

int cantHabitantes (hogar h, eph_i ti){
    int res = 0;

    int i = 0;
    while (i < ti.size()){
        if (ti[i][INDCODUSU] == h[HOGCODUSU])
            res += 1;
        i++;
    }
    return res;
}

bool menosDe21MiembrosPorHogar (eph_h th, eph_i ti){
    bool res = true;

    int i = 0;
    while (i < th.size()){
        if (cantHabitantes(th[i], ti) >= 21) {
            res = false;
        }
        i++;
    }
    return res;
}

bool cantidadValidaDormitorios (eph_h th){
    bool  res = true;

    int i = 0;
    while (i < th.size()){
        if (th[i][IV2] < th[i][II2]) //IV2 es cant de habitaciones, II2 es cant de dormitorios
            res = false;
        i++;
    }
    return res;
}

bool individuoValido (individuo ind){
    return (ind[INDCODUSU] > 0 &&
            ind[COMPONENTE] > 0 &&
            (0 < ind[INDTRIMESTRE] && ind[INDTRIMESTRE] <= 4) &&
            (0 < ind[CH4] && ind[CH4] <= 2) && //CH4 representa el género
            (ind[CH6]>=0) && //edad
            (ind[NIVEL_ED] == 0 || ind[NIVEL_ED] == 1) &&
            (-1 <= ind[ESTADO] && ind[ESTADO] <= 1) &&
            (0 <= ind[CAT_OCUP] && ind[CAT_OCUP] <= 4) &&
            (ind[p47T] >= 0 || ind[p47T] == -1) && //ingresos
            (0 <= ind[PP04G] && ind[PP04G] <= 10)); //lugar de trabajo
}

bool valoresEnRangoI (eph_i ti){
    bool res = true;

    int i = 0;
    while (i < ti.size() && res){
        if (!individuoValido(ti[i]))
            res = false;
        i++;
    }
    return res;
}

bool hogarValido (hogar h){
    return (h[HOGCODUSU] > 0 &&
            (0 < h[HOGTRIMESTRE] && h[HOGTRIMESTRE] <= 4) &&
            (0 < h[II7] && h[II7] <= 3) && //tenencia
            valorRegionValido(h[REGION]) &&
            (h[MAS_500] == 0 || h[MAS_500] == 1) &&
            (0 < h[IV1] && h[IV1] <= 5) && //tipo de hogar
            h[IV2] > 0 && //cant de habitaciones
            h[II2] >= 1 && //cantidad de dormitorios
            (h[II3] == 1 || h[II3] == 2)); //¿Alguna se usa para trabajar?
}

bool valorRegionValido (int r){
    return (r == 1 || (40 <= r <= 44));
}

bool valoresEnRangoH (eph_h th){
    bool res = true;

    int i = 0;
    while (i < th.size() && res){
        if (!hogarValido(th[i]))
            res = false;
        i++;
    }
    return res;
}

bool esValida (eph_h th, eph_i ti){
    /*
    bool tiVacia = vacia(ti);
    bool thVacia = vacia(th);
    bool tiMatriz = esMatriz(ti);
    bool thMatriz = esMatriz(th);
    bool ticantidadCorrectaDeColumnasI = cantidadCorrectaDeColumnasI(ti);
    bool thcantidadCorrectaDeColumnasH = cantidadCorrectaDeColumnasH(th);
    bool indSinHogares = hayIndividuosSinHogares(ti, th);
    bool hogSinIndividuos = hayHogaresSinIndividuos(ti, th);
    bool hayRepeI = hayRepetidosI(ti);
    bool hayRepeH = hayRepetidosH(th);
    bool bienAnioYTrim = mismoAnioYTrimestre(ti, th);
    bool menosDe21 = menosDe21MiembrosPorHogar(th, ti);
    bool valDorm = cantidadValidaDormitorios(th);
    bool valRangoI = valoresEnRangoI(ti);
    bool valRangoH = valoresEnRangoH(th);
    */

    return !vacia(ti) &&
           !vacia(th) &&
           esMatriz(ti) &&
           esMatriz(th) &&
           cantidadCorrectaDeColumnasI(ti) &&
           cantidadCorrectaDeColumnasH(th) &&
           !hayIndividuosSinHogares(ti, th) &&
           !hayHogaresSinIndividuos(ti, th) &&
           !hayRepetidosI(ti) &&
           !hayRepetidosH(th) &&
           mismoAnioYTrimestre(ti, th) &&
           menosDe21MiembrosPorHogar(th, ti) &&
           cantidadValidaDormitorios(th) &&
           valoresEnRangoI(ti) &&
           valoresEnRangoH(th);
}
//Fin Ej 1

//Ej 2

int cantMaxDeHabitacionesEnRegion(eph_h th, int region){
    int i= 0;
    int max = 0;
    while(i<th.size()){
        if(max<th[i][IV2] && th[i][REGION] == region){ //&& th[i][IV1] == 1){
            max = th[i][IV2];
        }
        i++;
    }
    return max;
}
//Fin Ej 2

//Ej 3
bool esCasa(hogar h){
    return h[IV1]==1;

}

bool esHogarValido(hogar h, int region){
    return esCasa(h) && h[REGION]==region && h[MAS_500]==0;
}

bool hogarConHacinamientoCritico(hogar h, eph_i ti){
    bool resp= cantHabitantes(h,ti) > 3*h[II2];
    return resp;
}

int cantHogaresValidos(eph_h th, int region){
    int sum=0;
    int k=0;
    while(k<th.size()){
        if(esHogarValido((th[k]), region)){
            sum=sum+1;
        }
        k++;
    }
    return sum;
}

int cantHogaresValidosConHC(eph_h th, eph_i ti, int region){
    int sum=0;
    int k=0;
    while (k < th.size()){
        if (esHogarValido(th[k],region) && hogarConHacinamientoCritico(th[k],ti)) {
            sum = sum + 1;
        }
        k++;

    }
    return sum;
}

float proporcionDeCasasConHCPorRegion(int region, eph_h th,eph_i ti){
    float resp= 0;
    if (cantHogaresValidos(th,region)>0){
        resp= cantHogaresValidosConHC(th,ti,region)/(cantHogaresValidos(th,region));
    }
    return resp;
}

//Fin ej 3

//Ej 4
int encuentraHogar(int ind, eph_h th, eph_i ti) {
    int i = 0;
    int res;
    while (i<th.size()) {
        if(ti[ind][INDCODUSU] == th[i][HOGCODUSU]){
            res = i;
            i=1+th.size();
        }
        i++;
    }
    return res;
}

float individuosValidosQueTrabajan(eph_h th, eph_i ti){
    int i = 0;
    int cantidad = 0;
    while(i < ti.size()){
        int h = encuentraHogar(i,th,ti);
        if(ti[i][ESTADO] == 1 && th[h][MAS_500] == 1 && (th[h][IV1] == 1 || th[h][IV1] == 2)){
            cantidad=cantidad+1;
        }
        i++;
    }
    return cantidad;
}

float individuosValidosQueTrabajanEnSuVivienda(eph_h th, eph_i ti){
    int i = 0;
    int cantidad = 0;
    while(i < ti.size()){
        int h = encuentraHogar(i,th,ti);
        if(ti[i][ESTADO] == 1 &&
           th[h][MAS_500] == 1 &&
           (th[h][IV1] == 1 || th[h][IV1] == 2) &&
           ti[i][PP04G] == 6 &&
           th[h][II3] == 1){
            cantidad=cantidad+1;
        }
        i++;
    }
    return cantidad;
}

float proporcionTeleworking(eph_h th, eph_i ti){
    float proporcion = 0;
    if(individuosValidosQueTrabajan(th,ti) > 0){
        proporcion = individuosValidosQueTrabajanEnSuVivienda(th,ti)/ individuosValidosQueTrabajan(th,ti);
    }
    return proporcion;
}

//Fin ej 4

// Ej 5

bool tieneCasaPropia(hogar h){
    return h[II7]==1;
}
bool tieneCasaChica(hogar h, eph_i ti){
    return cantHabitantes(h,ti)-2 > h[II2];
}
//Fin Ej 5

//Ej 6

hogar hogarCorrespondienteAIndividuo(eph_h th, individuo i){
    hogar h;
    int k=0;
    while(k<th.size()){
        if (th[k][HOGCODUSU]==i[INDCODUSU]){
            h= th[k];
        }
        k++;
    }
    return h;
}
//Fin ej 6

// Ej 7

void insertarHogar(eph_h &th, int i){
    while(i>0 && (th[i][REGION] < th[i-1][REGION] ||
                  (th[i][REGION]==th[i-1][REGION] && th[i][HOGCODUSU]< th[i-1][HOGCODUSU]))){
        swap(th,i,i-1);
        i--;
    }
}

void ordenarPorRegionYCodusu(eph_h &th){
    for(int i=0; i < th.size() ; i++){
        insertarHogar(th,i);
    }
}


bool suHogarEstaAntes(individuo ind1, individuo ind2, eph_h th){
    bool res = false;
    int i =0;
    while(i<th.size() && th[i][HOGCODUSU]!=ind1[INDCODUSU]){
        i++;
    }
    hogar h1 = th[i];
    int j=0;
    while(i<th.size() && th[j][HOGCODUSU]!=ind2[INDCODUSU]){
        j++;
    }
    hogar h2 = th[j];
    return i<j;
}

bool vivenJuntos(individuo ind1, individuo ind2){
    return ind1[INDCODUSU]==ind2[INDCODUSU];
}

void insertarIndividuo(eph_h &th, eph_i &ti, int i){
    while(i>0 && (suHogarEstaAntes(ti[i],ti[i-1],th) ||
                  (vivenJuntos(ti[i],ti[i-1]) && ti[i][COMPONENTE]<ti[i-1][COMPONENTE]))){
        swap(ti,i,i-1);
        i--;
    }
}

void ordenarPorCodusuDeHogarYComponente(eph_i &ti, eph_h &th){
    for(int i=0; i < ti.size() ; i++){
        insertarIndividuo(th,ti,i);
    }
}
//Fin Ej 7

//Ej 8
//Auxiliares Ej 8

/*
bool esMuestraDeHogares (vector<hogar> mh, eph_h th){
    bool res = true;

    int i = 0;
    while (i < mh.size()){
        if (!hogarEnTabla(mh[i], th))
            res = false;
        i++;
    }
    return res;
}
*/

int ingresos (hogar h, eph_i ti){ //calcula el ingreso total de un hogar
    int res = 0;

    int i = 0;
    while (i < ti.size()){
        if (ti[i][INDCODUSU] == h[HOGCODUSU] && ti[i][p47T] > -1) //p47T es ingreso total de la persona
            res += ti[i][p47T];
        i++;
    }
    return res;
}
/*
bool ordenadaPorIngresosConMismaDiferencia (vector<hogar> mh, eph_i ti){
    //supongo que |mh| >= 2
    bool res = true;

    int i = 0;
    int dif = ingresos(mh[1], ti) - ingresos(mh[0], ti);
    while (i < mh.size() - 1){
        if (! (ingresos(mh[i+1], ti) - ingresos(mh[i], ti)) == dif)
            res = false;
        i++;
    }
    return res;
}


bool esSolucionMuestraHomogenea (vector<hogar> mh, eph_h th, eph_i ti){
    return esMuestraDeHogares(mh, th) && ordenadaPorIngresosConMismaDiferencia(mh, ti);
}
*/

void swap (eph_h &th, int i, int j){ //intercambia dos posiciones de la tabla hogar
    hogar k = th[i];
    th[i] = th[j];
    th[j] = k;
}

void insertar (eph_h &th, int i, eph_i ti){
    while (i > 0 && ingresos(th[i], ti) < ingresos(th[i-1], ti)) {
        swap(th, i, i - 1);
        i--;
    }
}

eph_h insertionSort (eph_h th, eph_i ti){
    for (int i = 0; i < th.size(); i++) {
        insertar(th, i, ti);
    }
    return th;
}

eph_h  ordenadaPorIngresos (eph_h th, eph_i ti){
    return insertionSort(th, ti);
}

vector<hogar> secuenciaMasLarga (eph_h th, eph_i ti){

    eph_h ord = ordenadaPorIngresos(th, ti); //tabla de hogares ord por ingresos

    //vector<hogar> aux = {ord[0], ord[1]};
    vector<hogar> res;

    int i = 0; //define el primer hogar inicial
    while (i < ord.size()-1) {

        int j = i + 1; //define el segundo hogar inicial
        while (j < ord.size()) {

            int dif = ingresos(ord[j], ti) - ingresos(ord[i], ti); //defino el def con el cual voy a comparar
            vector<hogar> aux = {ord[i], ord[j]};

            int s = j + 1;
            while (s < ord.size()) {
                int difAux = ingresos(ord[s], ti) - ingresos(ord[j], ti);
                if (difAux == dif){
                    aux.push_back(ord[s]);
                    j = s;
                }
                s++;
            }
            if (aux.size() > res.size() && dif > 0)
                res = aux;
            j++;
        }
        i++;
    }
/*
    int i = 1;
    while (i < ord.size()-1){

        vector<hogar> aux = {ord[i-1], ord[i]};
        int dif = ingresos(ord[i], ti) - ingresos(ord[i-1], ti);

        int k = i;
        int j = i+1;
        while (j < ord.size()){

            int difAux = ingresos(ord[j], ti) - ingresos(ord[k], ti);
            if (difAux == dif){
                aux.push_back(ord[j]);
                k = j;
            }
            j++;
        }
        if (aux.size() > res.size() && dif > 0)
            res = aux;

        aux.clear();
        //aux = {ord[i-1], ord[i]};
        //dif = ingresos(ord[i], ti) - ingresos(ord[i-1], ti);
        i++;
    }**/
    return res;

}

//Fin Ej 8

//Ej 10
//Ejercicio 10

eph_i coincidenConTodasLasBusquedas (vector<pair<int, dato>> busquedas, eph_i ti){
    eph_i res;

    int i = 0;
    while (i < ti.size()){
        bool coincide = true;

        int j = 0;
        while (j < busquedas.size()){
            if (ti[i][busquedas[j].first] != busquedas[j].second)
                coincide = false;
            j++;
        }
        if (coincide)
            res.push_back(ti[i]);
        i++;
    }
    return res;
}

eph_i complementoBusqueda (vector<pair<int, dato>> busqueda, eph_i ti){

    eph_i coinciden = coincidenConTodasLasBusquedas(busqueda, ti);
    eph_i res;

    int i = 0;
    while (i < ti.size()){
        if (! individuoEnTabla(ti[i], coinciden))
            res.push_back(ti[i]);
        i++;
    }
    return res;
}

//Quiero ahora quitar los hogares que tienen individuos que coinciden con la búsqueda
//pero no con su complemento

eph_h hogaresSegunBusqueda (vector<pair<int, dato>> busqueda, eph_h th, eph_i ti){

    eph_i coinciden = coincidenConTodasLasBusquedas(busqueda, ti);
    //eph_i complemento = complementoBusqueda(busqueda, ti);

    eph_h res;

    int i = 0;
    while (i < th.size()){

        bool tieneIndEnCoincide = false;
        int j = 0;
        while (j < coinciden.size()){
            if (coinciden[j][INDCODUSU] == th[i][HOGCODUSU])
                tieneIndEnCoincide = true;
            j++;
        }
        /*
        bool tieneIndEnComplemento = false;
        int k = 0;
        while (k < complemento.size()){
            if (complemento[k][INDCODUSU] == th[i][HOGCODUSU])
                tieneIndEnComplemento = true;
            k++;
        }
        */
        //if (tieneIndEnCoincide && ! tieneIndEnComplemento)
        if (tieneIndEnCoincide)
            res.push_back(th[i]);

        i++;
    }
    return res;
}

//Hogares que tengo que quitar de la tabla original
//Si todos sus individuos asociados coinciden con la búsqueda
//Equivale a decir que no tienen individuos asociados en complementoIndividuos

//Genero la tabla hogar SIN los hogares que tienen todos sus individuos que cumplen la búsqueda.

eph_h hogaresConIndNoCumplenBusq (vector<pair<int, dato>> busqueda, eph_h th, eph_i ti){

    eph_i complementoInd = complementoBusqueda(busqueda, ti);
    eph_h res;

    int i = 0;
    while (i < th.size()){

        int j = 0;
        bool tieneIndEnComplemento = false;
        while (j < complementoInd.size()){

            if (th[i][HOGCODUSU] == complementoInd[j][INDCODUSU])
                tieneIndEnComplemento = true;
            j++;
        }
        if (tieneIndEnComplemento)
            res.push_back(th[i]);

        i++;
    }
    return res;
}

eph_h complementoHogaresEnBusqueda (vector<pair<int, dato>> busquedas, eph_h th, eph_i ti){

    eph_h hogEnBusqueda = hogaresSegunBusqueda(busquedas, th, ti);
    eph_h res;

    int i = 0;
    while (i < th.size()){
        if (! hogarEnTabla(th[i], hogEnBusqueda))
            res.push_back(th[i]);
        i++;
    }
    return res;
}

bool esBusquedaValida (vector<pair<int, dato>> busqueda){
    if (busqueda.size() == 0)
        return false;

    bool res = false;
    int i = 0;
    while (i < busqueda.size()){
        if (busqueda[i].first == INDCODUSU && busqueda[i].second > 0)
            res = true;
        if (busqueda[i].first == COMPONENTE && busqueda[i].second > 0)
            res = true;
        if (busqueda[i].first == CH4 && 0 < busqueda[i].second && busqueda[i].second <= 4)//CH4 = Genero
            res = true;
        if (busqueda[i].first == CH6 && busqueda[i].second >= 0)
            res = true;
        if (busqueda[i].first == NIVEL_ED && 0 <= busqueda[i].second && busqueda[i].second < 2)
            res = true;
        if (busqueda[i].first == ESTADO && -1 <= busqueda[i].second && busqueda[i].second <= 1)
            res = true;
        if (busqueda[i].first == CAT_OCUP && 0 <= busqueda[i].second && busqueda[i].second <= 4)
            res = true;
        if (busqueda[i].first == p47T && -1 <= busqueda[i].second)
            res = true;
        if (busqueda[i].first == PP04G && 0 < busqueda[i].second && busqueda[i].second <= 10)
            res = true;

        i++;
    }

    //Verifico que la búsqueda no esté repetida
    int j = 0;
    while (j < busqueda.size()){
        int k = j+1;
        while (k < busqueda.size()-1){
            if (busqueda[j].first == busqueda[k].first)
                res = false;
            k++;
        }
        j++;
    }
    return res;
}

//Fin Ej 10

// Ej 11

float distanciaEuclideana(pair <int,int> centro, int latitud, int longitud){
    return(sqrt((centro.first - latitud)*(centro.first - latitud) + (centro.second - longitud)*(centro.second - longitud)));
}

int enQueAnilloEsta(float d, vector < int > distancias){
    int i=0;
    int res;
    while(i<distancias.size()){
        if(distancias[i] >= d){
            res = i+1;
            i = distancias.size()+1; // esto es un corte
        }
        i++;
    }
    return res;
}
//Fin Ej 11
