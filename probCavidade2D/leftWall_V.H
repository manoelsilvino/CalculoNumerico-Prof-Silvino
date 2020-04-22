// VOLUMES-v

for(int j = 1; j < Ny; j++)
{
    int i = 0;

    I = (j-1)*Nx+i; // indice do volume (diagonal da matriz U)
    cout << "volume v :"<< I << endl;
    
    Sv[I] += (-u[i][j]*rho*dx*dy); // u do tempo anterior

    dV[I] += (-rho*dx*dy);
    // calcula os fluxos convectivos nas faces (upwind)
    #include "UPWIND_V.H"

    // calcula a contribuicao dos fluxos difusivos nas faces
    
    dV[I]       += (-mu*(2*(dx/dy) + 3*(dy/dx)))*dt;
    aV[I-Nx]    += mu*(dx/dy)*dt;
    fV[I]       += mu*(dx/dy)*dt;
    eV[I]       += mu*(dy/dx)*dt;

    // termo fornte relativo a pressao
    Sv[I] += ( (p[i][j-1] - p[i][j])/dy );
        
}