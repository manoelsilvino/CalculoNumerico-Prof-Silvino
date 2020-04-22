for(int i = 1; i < Nx ; i++)
{
    int j = 0;

    I = j*(Nx-1)+i-1;
    cout << "volume :"<< I << endl;
    //J = I;
    Su[I] += (-u[i][j]*rho*dx*dy); // u do tempo anterior

    dU[I] += (-rho*dx*dy);
    // calcula os fluxos convectivos nas faces (upwind)
    #include "UPWIND.H"

    // calcula a contribuicao dos fluxos difusivos nas faces
    

    dU[I]       += (-mu*(3*(dx/dy) + 2*(dy/dx)))*dt;
    fU[I]       += mu*(dx/dy)*dt;
    bU[I-1]     += mu*(dy/dx)*dt;
    eU[I]       += mu*(dy/dx)*dt;
    

    // termo fornte relativo a pressao
    Su[I] += ( (p[i-1][j] - p[i][j])/dx );

}