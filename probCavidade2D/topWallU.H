for(int i = 1; i < Nx; i++)
{
    int j = Ny-1;

    I = j*(Nx-1)+i-1;
    cout << "volume :"<< I << endl;
    J = I;
    Su[I] += (-u[i][j]*rho*dx*dy); // u do tempo anterior

    U[I][I] += (-rho*dx*dy);
    // calcula os fluxos convectivos nas faces (upwind)
    #include "UPWIND.H"

    // calcula a contribuicao dos fluxos difusivos nas faces
    
        // face N
    /*
    J = (j+1)*(Nx-1)+i-1;
    if((J>0) && (J<dim_U))
    {
        U[I][J] += ((mu*dx*dt)/dy);
    }*/
    Su[I] += ((2*mu*dx*dt*velTampa)/dy);
    
    U[I][I] += (-(mu*dx*dt)/dy);

    // face S
    J = (j-1)*(Nx-1)+i-1;
    if((J>0) && (J<dim_U))
    {
        U[I][J] += ((mu*dx*dt)/dy); 
    }
    U[I][I] +=((-mu*dx*dt)/dy);

    //face W 
    J = j*(Nx-1)+i-2;//i-1-1
    if((J>0) && (J<dim_U))
    {
        U[I][I]  +=((-mu*dy*dt)/dx);
    }
    U[I][J] += ((mu*dy*dt)/dx);

    //face E 
    J = j*(Nx-1)+i;//i+1-1;
    if((J>0) && (J<dim_U))
    {
        U[I][J]   += ((mu*dy*dt)/dx);
    }
    U[I][I]   += ((-mu*dy*dt))/dx;
    

    // termo fornte relativo a pressao
    Su[I] += ( (p[i-1][j] - p[i][j])/dx );

}