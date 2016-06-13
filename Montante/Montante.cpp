//Montante
//Carmelo Ramirez, Miguel Cuéllar, Carlos Serret
//Marzo 3 2016

#include <iostream>
using namespace std;
double Ecuacion[80], MatEcuaciones[80][80], Aux[80][80];
void montante(int inc){
    double pivAnt = 1;
    for (int actual=1; actual<=inc; actual++) {
        if (MatEcuaciones[actual-1][actual-1] == 0) {
            for (int x = 0; x<=inc; x++) {
                Ecuacion[x] = MatEcuaciones[actual-1][x]*(-1);
                MatEcuaciones[actual-1][x] = MatEcuaciones[actual][x];
                MatEcuaciones[actual][x] = Ecuacion[x];
            }
        }
        for (int ix = 0; ix<=inc; ix++) {
            Aux[actual-1][ix] = MatEcuaciones[actual-1][ix];
        }
        double pivAct = MatEcuaciones[actual-1][actual-1];
        for (int m = 0; m<inc; m++) {
            for (int iy= 0; iy<=inc; iy++) {
                if (m == iy && m<= actual-1 && iy<= actual-1) {
                    Aux[m][iy] = pivAct;
                }
                if (m>actual-1 && iy>actual-1) {
                    Aux[m][iy] = (pivAct*MatEcuaciones[m][iy])-(MatEcuaciones[actual-1][iy]*MatEcuaciones[m][actual-1]);
                    Aux[m][iy] = Aux[m][iy]/pivAnt;
                }
                if (m<actual-1 && iy>actual-1) {
                    Aux[m][iy] = (MatEcuaciones[m][actual-1]*MatEcuaciones[actual-1][iy])-(MatEcuaciones[m][iy]*pivAct);
                    Aux[m][iy] = (Aux[m][iy]/pivAnt)*(-1);
                }
            }
        }
            for (int i = 0; i<inc; i++) {
                for (int j= 0; j<=inc; j++) {
                MatEcuaciones[i][j] = Aux[i][j];
                Aux[i][j]=0;
            }
        }
        pivAnt = pivAct;
        pivAct = MatEcuaciones[actual][actual];
    }
}
int main() {
        int e,inc;
    string continuar="si";
    while (continuar!="no"||continuar!="NO"||continuar!="No") {
        do{
        cout << "¿Cuantas ecuaciones?" << endl;
        cin >> e;
        cout << "¿Cuantas incognitas(Debe coincidir con el número de ecuaciones)?" << endl;
        cin >> inc;
    }while (e!=inc);
    
    cout << "Introduzca los coeficientes separados por espacios"<< endl;
    for (int ix = 0; ix<inc; ix++) {
        cout<<"Ingrese la ecuacion número "<<ix+1<<endl;
        for (int iy= 0; iy<=inc; iy++) {
            cin >> MatEcuaciones[ix][iy];
            Aux[ix][iy]=0;
        }
    }
    if (MatEcuaciones[0][0]==0&&MatEcuaciones[1][0]==0){
        cout << "No existe solución" << endl;
    }
    else{
    montante(inc);
        cout << "Solución única" << endl;
        for (int ix = 0; ix<inc; ix++) {
            cout << "x" << ix+1 << " = " << MatEcuaciones[ix][inc]/MatEcuaciones[ix][ix] << endl;
        }
    }
        cout<<"Quieres realizar el metodo de nuevo?"<<endl;
        cin>>continuar;
    }
    return 0;
}
