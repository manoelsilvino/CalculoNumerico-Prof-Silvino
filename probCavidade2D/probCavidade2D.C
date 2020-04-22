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
#include "PGS.H"

using namespace std;

int main()
{
    double rho  = 100;
    double mu   = 0.1;

    double t;
    double dt = 1e-3;

    double t_final = 3e-3;
    
    // numero de volumes em cada direção
    int Nx = 4;
    int Ny = 4;
    if( (Nx<=1)||(Ny<=1))
    {
        cerr << "ERRO: Nx e Nx devem ser maior que 1 "<< endl;
        return 11;
    }
    
    double velTampa = 0.2;
    double comprimentoL = 1;
    double alturaH      = 1;
    
    double dx   = comprimentoL/(Nx-1) ;
    double dy   = alturaH/(Ny-1) ;

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


    // diagonais da matriz para a solucao de u-momentum
    // as diagonais sao ordenada de baixo para cima como aU;bU,  dU, eU e fU;
    // sendo dU a diagonal princiapal
    
    double* dU;
    double* aU;
    double* bU;
    double* eU;
    double* fU;
    double* Su;

    int dim_U = (Nx-1)*Ny;

    dU = new double [dim_U];
    bU = new double [dim_U-1];
    eU = new double [dim_U-1];
    aU = new double [dim_U-Nx+1];
    fU = new double [dim_U-Nx+1];
    Su = new double[dim_U];

    for (int i = 0; i < dim_U; i++)
    {
        dU[i] = 0.0;
        Su[i] = 0.0;
    }
    for (int i = 0; i < (dim_U-1); i++)
    {
        bU[i] = 0.0;
        eU[i] = 0.0;
    }
    for (int i = 0; i < (dim_U- Nx+1); i++)
    {
        aU[i] = 0.0;
        fU[i] = 0.0;
    }

    
    // matriz para a solucao de v-momentum
    int dim_V = Nx*(Ny-1);
    double* dV;
    double* aV;
    double* bV;
    double* eV;
    double* fV;
    double* Sv;

    dV  =   new double [dim_V];
    Sv  =   new double [dim_V];
    aV  =   new double [dim_V - Nx+1];
    bV  =   new double [dim_V-1];
    eV  =   new double [dim_V-1];
    fV  =   new double [dim_V - Nx+1];
    
    for (int i = 0; i < dim_V; i++)
    {
        dV[i] = 0.0;
        Sv[i] = 0.0;
    }
    for (int i = 0; i < (dim_V-1); i++)
    {
        bV[i] = 0.0;
        eV[i] = 0.0;
    }
    for (int i = 0; i < (dim_V- Nx+1); i++)
    {
        aV[i] = 0.0;
        fV[i] = 0.0;
    }
    
    // matriz para a solucao de pressao. SOMENTE AS DIAGONAIS
    double* dP;
    double* aP;
    double* bP;
    double* eP;
    double* fP;
    double* Sp ; // termo fonte da pressao

    int dim_P = Nx*Ny;

    dP      = new double [dim_P];
    Sp      = new double [dim_P];

    aP      = new double [dim_P-Nx+1];
    bP      = new double [dim_P-1];
    eP      = new double [dim_P-1];
    fP      = new double [dim_P-Nx+1];

    
    for(int i = 0; i<(dim_P); i++)
    {
        dP [i]  = 0.0;
        Sp[i]   = 0.0;
    }
    for(int i = 0; i<(dim_P-1); i++)
    {
        bP [i]  = 0.0;
        eP[i]   = 0.0;
    }
    for(int i = 0; i<(dim_P-Nx+1); i++)
    {
        aP [i]  = 0.0;
        fP[i]   = 0.0;
    }
     // loop no tempo
     int I=0; // indices das matrizes de solucao
     //int J=0;

    for(t = dt; t<t_final; t+=dt)
     {
         
         cout << "\n==============\n \t t = "<< t
              << "\n==============\n ";
         // -- atualizar a matriz U
         // percorrendo todos os volumes de controle u
                

          #include "topWallU.H"
          #include "bottomWallU.H"
          #include "leftWallU.H"
          #include "rightWallU.H"
          #include "volumesUinternosU.H"

          // solve u-momentum
          PGS
          (
              u,aU,bU,dU,eU,fU,Su,
              dim_U-Nx+1,
              dim_U-1,
              dim_U,
              dim_U-1,
              dim_U-Nx+1,
              Nx,
              Ny
          );
        
          #include "rightWall_V.H"
          #include "leftWall_V.H"
          #include "bottomWall_V.H"
          #include "topWall_V.H"
          #include "volumesInternosV.H"

         // atualizar os elementos da matriz para o calculo da pressao
         

     }
        
   return 0;
    
}
