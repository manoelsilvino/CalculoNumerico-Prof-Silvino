for(int j = 1; j < Ny-1; j++)
{
    int i = 1;
    
    I = j*(Nx-1)+i-1;
    cout << "volume :"<< I << endl;

    Su[I] += (-u[i][j]*rho*dx*dy); // u do tempo anterior

    dU[I] += (-rho*dx*dy);
    // calcula os fluxos convectivos nas faces (upwind)
    #include "UPWIND.H"

    // calcula a contribuicao dos fluxos difusivos nas faces
    
    dU[I]       += (-mu*(2*(dx/dy) + (dy/dx)))*dt;
    aU[I-Nx]    += mu*(dx/dy)*dt;
    fU[I]       += mu*(dx/dy)*dt;
    eU[I]       += mu*(dy/dx)*dt;   

    // termo fornte relativo a pressao
    Su[I] += ( (p[i-1][j] - p[i][j])/dx );
    
}