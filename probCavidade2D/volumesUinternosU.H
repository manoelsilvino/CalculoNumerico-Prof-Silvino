// VOLUMES-u INTERNOS


for(int j = 1; j < Ny-1; j++)
{
    for (int i = 2; i < Nx-1; i++)
    {
        I = j*(Nx-1)+i-1; // indice do volume (diagonal da matriz U)
        cout << "volume :"<< I << endl;
        //J = I;
        
        Su[I] = Su[I] + (-u[i][j]*rho*dx*dy); // u do tempo anterior

        dU[I] += (-rho*dx*dy);
        // calcula os fluxos convectivos nas faces (upwind)
        #include "UPWIND.H"

        // calcula a contribuicao dos fluxos difusivos nas faces
        
        dU[I]       += (-2*mu*((dx/dy) + (dy/dx)))*dt;
        aU[I-Nx]    += mu*(dx/dy)*dt;
        fU[I]       += mu*(dx/dy)*dt;
        eU[I]       += mu*(dy/dx)*dt; 
        bU[I-1]     += mu*(dy/dx)*dt; 

        // termo fornte relativo a pressao
        Su[I] += ( (p[i-1][j] - p[i][j])/dx );
        
    }
}