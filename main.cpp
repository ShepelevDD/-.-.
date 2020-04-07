#include "plant.h"
#include <iostream>
#include <cmath>
#include <unistd.h>

using namespace std;


void raschet(double *ptr[], double R[], int d, int L, int s)
	{
		double Xmax, Xmin, raznost;
		Xmax = ptr[0][d];
		Xmin = ptr[0][d];
		for (int i = 1; i <= L; i++)
		{
			if (ptr[L][d] > Xmax)
			{
				Xmax = ptr[L][d];
			}
			if (ptr[L][d] < Xmin)
			{
				Xmin = ptr[L][d];
			}
		}
		cout<<"N: "<<s<<"     ";
		cout << "X" << d << "min= " << Xmin<<"      X" << d << "max= " << Xmax<<endl;
		raznost = Xmax - Xmin;
		if ((raznost) > R[d])
		{
			cout <<"значение разности: "<< raznost <<" "<< " номер датчика: " << d<<endl;
		}
        cout<<endl;
	}


	int main()
	{   setlocale(LC_ALL, "Russian");
		Plant plant;
		plant_init(plant);
		int K, M[10], L, N, F;
		double X[10][10], R[10];
        cout << "Введите число опрашиваемых датчиков: K= ";
		cin >> K;
		cout << "Введите номера датчиков: ";
		for (int i = 1; i <= K; i++)
		{
			cout << "M[" << i << "]= ";
			cin >> M[i];
		}
		cout << "Введите число опросов каждого датчика в серии: L= ";
		cin >> L;
		cout << "Введите число серий: N= ";
		cin>> N;
		cout << "Введите граничные значения контролируемых показателей: ";
           for (int i = 1; i <= K; i++)
		  {
			cout << "R[" << i << "]= ";
			cin >> R[i];
		  }
		  for (int s=1; s<=N; s++)
        {
		   for (int j = 1; j <= L; j++)
			{
				for (int d = 1; d <= K; d++)
				{
					X[j][d] = plant_measure(M[d], plant);
                    cout<<"X["<<j<<"]["<<d<<"]= "<<X[j][d]<<endl; //Матрица выводится только один раз, а должна выводиться N раз
				}
			}
			 double *p[L];
			 for (int q=1; q<=L; q++)
             {
                 p[q]=X[q];
             }
			for (int d = 1; d <= K; d++)
			{
				raschet( p, R, d, L, s);
			}
        }
		return 0;
 }
