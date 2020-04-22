for(int i = 1; i < Nx; i++)
{
    int j = Ny-1;

    I = j*(Nx-1)+i-1;
    cout << "volume :"<< I << endl;

    Su[I] += (-u[i][j]*rho*dx*dy); // u do tempo anterior

    dU[I] += (-rho*dx*dy);
    // calcula os fluxos convectivos nas faces (upwind)
    #include "UPWIND.H"

    // termo difusivo
    Su[I] += ( (2*mu*(dx/dy)*velTampa)*dt );
    
    dU[I]       += (-mu*(3*(dx/dy) + 2*(dy/dx)))*dt;
    aU[I-Nx]    += mu*(dx/dy)*dt;
    bU[I-1]     += mu*(dy/dx)*dt;
    eU[I]       += mu*(dy/dx)*dt;

    // termo fornte relativo a pressao
    Su[I] += ( (p[i-1][j] - p[i][j])/dx )*dt;

}