#include "ejercicios.h"
#include "auxiliares.h"
#include "definiciones.h"

using namespace std;
// Implementacion Problema 1
bool esEncuestaValida ( eph_h th, eph_i ti ) {
    //bool resp = false;


    return esValida(th, ti);
    //return resp;
}
// Implementacion Problema 2
vector < int > histHabitacional ( eph_h th, eph_i ti, int region ) {
    vector<int> res(cantMaxDeHabitacionesEnRegion(th, region));
    int i = 0;
    while(i<th.size()){
        if(th[i][REGION] == region && th[i][IV1] == 1){
            res[(th[i][IV2])-1] = res[(th[i][IV2])-1]+1;
        }
        i++;
    }
    return res;
}


// Implementacion Problema 3
vector< pair < int, float > > laCasaEstaQuedandoChica ( eph_h th, eph_i ti ) {

    vector<pair<int,float>> resp = {make_pair(1,-1.0),
                                    make_pair(40, -1.0),
                                    make_pair(41, -1.0),
                                    make_pair(42,-1.0),
                                    make_pair(43,-1.0),
                                    make_pair(44,-1.0)};
    int i=0;
    while (i< 6) {
        resp[i].second = proporcionDeCasasConHCPorRegion(resp[i].first,th,ti);
        i++;
    }
    return resp;
}


// Implementacion Problema 4
bool creceElTeleworkingEnCiudadesGrandes ( eph_h t1h, eph_i t1i, eph_h t2h, eph_i t2i ) {
    return(proporcionTeleworking(t2h,t2i) > proporcionTeleworking(t1h, t1i));
}

// Implementacion Problema 5

int costoSubsidioMejora( eph_h th, eph_i ti, int monto){
    int res = 0;
    int k=0;
    while (k<th.size()){
        if(tieneCasaPropia(th[k]) && tieneCasaChica(th[k],ti)){
            res = res+monto;
        }
        k++;
    }
    return  res;
}

// Implementacion Problema 6
join_hi generarJoin( eph_h th, eph_i ti ){
    /*hogar h = {};
    individuo i = {};
	join_hi resp = {make_pair(h,i)};
	*/
    join_hi junta = {};
    int k =0;
    while (k< ti.size()){
        individuo i = ti[k];
        hogar h= hogarCorrespondienteAIndividuo(th,i);
        par_hi temp (h,i);
        junta.push_back(temp);
        k++;
    }
    return junta;
}

// Implementacion Problema 7
void ordenarRegionYCODUSU (eph_h & th, eph_i & ti) {
    ordenarPorRegionYCodusu(th);
    ordenarPorCodusuDeHogarYComponente(ti,th);
}

// Implementacion Problema 8
vector < hogar > muestraHomogenea( eph_h & th, eph_i & ti ){
    //hogar h = {};
    //vector < hogar > resp = {h};
    //eph_h ordenada = ordenadaPorIngresos(th, ti);

    vector<hogar> resp = secuenciaMasLarga(th, ti);

    if (resp.size() <= 2)
        resp = {{}};

    return  resp;
}

// Implementacion Problema 9
void corregirRegion( eph_h & th, eph_i ti ) {
    int i = 0;
    while(i<th.size()){
        if(th[i][REGION] == 1){
            th[i][REGION] = 43;
        }
        i++;
    }
}


// Implementacion Problema 10
vector < int > histogramaDeAnillosConcentricos( eph_h th, eph_i ti, pair < int, int > centro, vector < int > distancias ){
    vector < int > res(distancias.size());
    int i=0;
    while(i<th.size()){
        float distanciaHogar = distanciaEuclideana(centro,th[i][HOGLATITUD],th[i][HOGLONGITUD]);
        int posicion = enQueAnilloEsta(distanciaHogar, distancias)-1;
        res[posicion]=res[posicion]+1;
        i++;
    }
    return res;
}
// Implementacion Problema 11 //figura como problema 10
pair < eph_h, eph_i > quitarIndividuos(eph_i & ti, eph_h & th, vector < pair < int, dato > >  busqueda ){
    //eph_h rth = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    //eph_i rti = {{-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}};
    //pair < eph_h, eph_i > resp = make_pair(rth, rti);

    // TODO

    //return resp;


    eph_i indQuecoinciden = coincidenConTodasLasBusquedas(busqueda, ti);
    eph_i complementoIndiv = complementoBusqueda(busqueda, ti);

    eph_h hogQueCoinciden = hogaresSegunBusqueda(busqueda, th, ti);
    eph_h conIndQueNocumplenBusqueda = hogaresConIndNoCumplenBusq(busqueda, th, ti);

    ti = complementoIndiv;
    th = conIndQueNocumplenBusqueda;

    pair < eph_h, eph_i > resp = make_pair(hogQueCoinciden, indQuecoinciden);
    return resp;


}
