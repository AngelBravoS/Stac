#include <iostream>
#include <cmath>
#include "calculosNVar.hpp"
#include "funcMatematicasBasicas.hpp"

//Límite máximo en unsigned short int: 65535
//Límite máximo en unsigned int: 4.294.967.295

using namespace std;
typedef unsigned short int unShortInt;

double CalculosNVar::getSumatoria() {
	return sumatoria;
	}

void CalculosNVar::setSumatoria ( double sumatoriaPublica ) {
	sumatoria = sumatoriaPublica;
	}	

double  CalculosNVar::calculoSumatoria(int indiceVariable, unsigned short int exponente) {
	unsigned int n = getColumna();
	double resultado = 0;
	for(unsigned int j = 0; j < n; j++) {
		resultado += potencia(matriz[indiceVariable][j], exponente);
	}
	return resultado;
}

double  CalculosNVar::calculoMediaAritmetica(int indiceVariable) {
	unsigned int n = getColumna();
	double resultado = 0;
	resultado = (calculoSumatoria(indiceVariable, 1) / n);
	return resultado;
}

double CalculosNVar::calculoMediaGeometrica(int indiceVariable) {
	unsigned int n = getColumna();
	double mediaGeometrica = 1;
	for(unsigned int j = 0; j < n; j++) {
		mediaGeometrica *= matriz[indiceVariable][j];
	}
	mediaGeometrica = pow(mediaGeometrica, 1.0 / n);
	return mediaGeometrica;
}

double CalculosNVar::calculoMediaArmonica(int indiceVariable) {
	unsigned int n = getColumna();
	double mediaArmonica = 0;
	for(unsigned int j = 0; j < n; j++) {
		mediaArmonica +=  1 / (potencia(matriz[indiceVariable][j], 1));
	}
	mediaArmonica = (n / mediaArmonica);
	return mediaArmonica;
}

double CalculosNVar::calculoMediaCuadratica(int indiceVariable) {
	unsigned int n = getColumna();
	double mediaCuadratica;
	mediaCuadratica = calculoSumatoria(indiceVariable, 2) * (1.0 / n);
	mediaCuadratica = sqrt(mediaCuadratica);
	return mediaCuadratica;
}

//Suma de diferencias respecto a la media con exponente
double CalculosNVar::difRespecMedia(int indiceVariable, int exponente) {
	unsigned int n = getColumna();
	double difRespecMedia = 0;
	for(unsigned int j = 0; j < n; j++) {
		difRespecMedia += pow(matriz[indiceVariable][j] - calculoMediaAritmetica(indiceVariable), exponente);
	}
	return difRespecMedia;
}

double CalculosNVar::calculoVarianza(int indiceVariable) {
	unsigned int n = getColumna();
	double resultado;
	resultado = (difRespecMedia(indiceVariable, 2)) / n;
	return resultado;
}

double CalculosNVar::calculoCuasiVarianza(int indiceVariable) {
	unsigned int n = getColumna();
	double resultado;
	resultado = (difRespecMedia(indiceVariable, 2)) / (n - 1);
	return resultado;
}

double CalculosNVar::desviacionTipica(int indiceVariable) {
	double desviacionTipica;
	desviacionTipica = sqrt(calculoVarianza(indiceVariable));
	return desviacionTipica;
}

double CalculosNVar::cuasiDesviacionTipica(int indiceVariable) {
	double cuasiDesviacionTipica;
	cuasiDesviacionTipica = sqrt(calculoCuasiVarianza(indiceVariable));
	return cuasiDesviacionTipica;
}

double CalculosNVar::momentos(int indiceVariable, int exponente) {
	unsigned int n = getColumna();
	double momentos;
	momentos = difRespecMedia(indiceVariable, exponente) / n;
	return momentos;
}

double CalculosNVar::coeficientePearson(int indiceVariable) {
	double coeficientePearson;
	coeficientePearson = cuasiDesviacionTipica(indiceVariable) / calculoMediaAritmetica(indiceVariable);
	return coeficientePearson;
}

//funciona MAAAAL
double CalculosNVar::coeficienteAsimetriaFisher(int indiceVariable) {
	double coeficienteAsimetriaFisher;
	coeficienteAsimetriaFisher = (momentos(indiceVariable, 3) / pow(cuasiDesviacionTipica(indiceVariable), 3));
	return coeficienteAsimetriaFisher;
}

double CalculosNVar::curtosis(int indiceVariable) {
	double curtosis;
	unsigned int n = getColumna();
	curtosis = ((difRespecMedia(indiceVariable, 4) / ((n - 1) * pow(cuasiDesviacionTipica(indiceVariable), 4))));
	//curtosis = curtosis -3;
	return curtosis;
}

/*
	// Método Quicksort y opción de Arrays.sort(vectorOrdenado);
	// con import java.util.Arrays; habilitado
	double Vector::ordenamientoVector() {
        double [] vectorOrdenado = (double[])vector.clone(); //===> Clonar ==> al clonar el vector original no se modifica
        Arrays.sort(vectorOrdenado);
        return vectorOrdenado;
    }

    double Vector::mediana(double []vectorOrdenado) {
        double [] vector = vectorOrdenado;
        double mediana=0;
        if (vector.length mod 2) = 1
			mediana = orden[i,(vector.length div 2)+1]
		else
			mediana = orden[i,(vector.length div 2)] + orden[i,(vector.length div 2)+1])  /  2
        return mediana;
    }
    void Vector::moda() {
    }
}*/
