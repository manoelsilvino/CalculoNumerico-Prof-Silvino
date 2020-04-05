/*
 * Solucao numerica do problema da cavidade 2D
 *  - usa o metodo de volumes finitos
 *  - malha descolada e uniforme
 * 
 *      *** v ***
 *      *       *
 *      *   p   u
 *      *       *
 *      *********
 * 
 * autor: Manoel Silvino
 */


#include <iostream>

using namespace std;

int main()
{
    double rho  = 100;
    double mu   = 0.1;
    
    // numero de volumes em cada direção
    int Nx = 5;
    int Ny = 5;
    
    double velTampa = 0.2;
    double comprimentoL = 1;
    double alturaH      = 1;
    
    double dx   = comprimentoL/Nx ;
    double dy   = alturaH/Ny ;    
    
    // define a malha
    double **p;
    
    p = new double* [Nx];
    
    for(int i = 0; i < Nx; i++)
    {
        p[i] = new double [Ny];
    }
    
    double **u;
    double **v;
    
    // para cada volume de p existem dois volumes de u e v associados
    // totalizando uma entrada a mais por causa dos contornos
    // a pressao nao eh definida nos contornos
    u = new double* [Nx+1];
    v = new double* [Nx]; // na direcao x a veloc. v tem o no. de entradas de p
    
    for(int i = 0; i < Nx+1; i++)
    {
        u[i] = new double [Ny];
    }
    for(int i = 0; i < Nx; i++)
    {
        v[i] = new double [Ny+1];
    }
    
    // condicoes iniciais
    
    for(int i = 0; i< Nx ; i++)
    {
        for(int j = 0; j <Ny; j++)
        {
            p[i][j] = 0.0;
        }
    }
    //para u
    for(int i = 0; i< Nx+1 ; i++)
    {
        for(int j = 0; j <Ny; j++)
        {
            u[i][j] = 0.0;
        }
    }
    //para v
    for(int i = 0; i< Nx ; i++)
    {
        for(int j = 0; j <Ny+1; j++)
        {
            v[i][j] = 0.0;
        }
    }

    // condicoes de contorno
    // left e right
    for(int j = 0; j < Ny; j++)
    {
        //obs: pressao nao tem 
        //      na malha deslocada nao ha 'v' nas laterais, somente 'u'
        
        u[0][j] = 0.0;        
        u[Nx][j] = 0.0;
    }
    
    // bottom and top
    for(int i= 0; i < Nx; i++)
    {
        v[i][0] = 0.0;
        v[i][Ny] = 0.0;
    }
     // teste
    



   
   return 0;
    
}
