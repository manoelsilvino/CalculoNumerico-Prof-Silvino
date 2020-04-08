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

    double t;
    double dt = 1e-3;

    double t_final = 3e-3;
    
    // numero de volumes em cada direção
    int Nx = 3;
    int Ny = 3;
    
    double velTampa = 0.2;
    double comprimentoL = 1;
    double alturaH      = 1;
    
    double dx   = comprimentoL/Nx ;
    double dy   = alturaH/Ny ;

// fluxos nas faces
    double flux_N;
    double flux_S;
    double flux_W;
    double flux_E;    
    
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


    // matriz para a solucao de u-momentum
    
    double **U;

    int dim_U = (Nx-1)*Ny;
    U = new double* [dim_U];
    for (int i = 0; i < dim_U; i++)
    {
        U[i] = new double [dim_U];
    }

    for (int i = 0; i < dim_U; i++)
    {
        for(int j = 0; j < dim_U; j++)
        {
            U[i][j]= 0.0;
        }
    }

    // matriz para a solucao de v-momentum
    double** V;
    int dim_V = Nx*(Ny-1);

    V = new double* [dim_V];
    for (int i = 0; i <dim_V ; i++)
    {
        V[i] = new double [dim_V];
    }
    for(int i = 0; i<dim_V; i++)
    {
        for(int j = 0; j<dim_V; j++)
        {
            V[i][j]= 0.0;
        }
    }

    // matriz para a solucao de pressao
    double** P;
    int dim_P = Nx*Ny;

    V = new double* [dim_P];
    for (int i = 0; i <dim_P ; i++)
    {
        V[i] = new double [dim_P];
    }
    for(int i = 0; i<dim_P; i++)
    {
        for(int j = 0; j<dim_P; j++)
        {
            V[i][j]= 0.0;
        }
    }


    // termo fonte
    double* S;
    S = new double[dim_U];
    for(int i = 0; i < dim_U; i++)
    {
        S[i] = 0.0;
    }


     // loop no tempo
     int I; // indices das matrizes de solucao
     int J;

     for(t = dt; t< t_final; t+=dt)
     {
         cout << "\n==============\n \t t = "<< t
              << "\n==============\n ";
         // -- atualizar a matriz U
         // percorrendo todos os volumes de controle u

         // - volumes adjacentes aos contornos
         // - PAREDE INFERIOR

        // #include "bottomWall.H"
        // #include "topWall.H"
        // #include "leftWall.H"
        // #include "rightWall.H"


        for (int i = 1; i < Nx-2; i++)
        {
            for(int j = 1; j < Ny-1; j++)
            {
                I = j*(Nx-1)+i-1;
                cout << "volume :"<< I << endl;
                J = I;
                S[I] += (-u[i][j]*rho*dx*dy); // u do tempo anterior

                U[I][I] += (-rho*dx*dy);
                // calcula os fluxos convectivos nas faces (upwind)
                #include "UPWIND.H"

                // calcula a contribuicao dos fluxos difusivos nas faces
                
                // face N
                U[I][J+(Nx-1)] += ((mu*dx*dt)/dy);
                U[I][J] -= ((mu*dx*dt)/dy);

                // face S
                U[I][J-(Nx-1)] += ((mu*dx*dt)/dy);
                U[I][J] +=((-mu*dx*dt)/dy);

                //face W 
                U[I][J]  +=((-mu*dy*dt)/dx);
                U[I-1][J] += ((mu*dy*dt)/dx);

                //face E
                U[I][J]   += ((-mu*dy*dt))/dx;
                U[I+1][J] +=((mu*dy*dt)/dx);

                // termo fornte relativo a pressao
                S[I] += ( (p[i-1][j] - p[i][j])/dx );
                
            }
        }
     }
     
    



   
   return 0;
    
}