for(int i = 1; i < Nx; i++)
{
    int j = Ny-1;

    I = i+(Nx-1)*j-1;
    J = I;
    S[I] += (-u[i][j]*rho*dx*dy); // u do tempo anterior

    U[I][J] += (-rho*dx*dy);

    // calcula os fluxos convectivos nas faces (upwind)
        #include "UPWIND.H"
    // calcula a contribuicao dos fluxos difusivos nas faces
    
    // face N
    U[I][J+(Nx-1)] += ((mu*dx*dt)/dy);
    U[I][J] -= ((mu*dx*dt)/dy);

    // face S

    U[I][J] +=((-2*mu*dx*dt)/dy);// calcula a contribuicao dos fluxos difusivos nas faces

    // face N
    S[I] += ((2*mu*dx*dt)/dy)*velTampa;
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

    //face W 
    U[I][J]  +=((-mu*dy*dt)/dx);
    U[I-1][J] += ((mu*dy*dt)/dx);

    //face E
    U[I][J]   += ((-mu*dy*dt))/dx;
    U[I+1][J] +=((mu*dy*dt)/dx);

    // termo fornte relativo a pressao
    S[I] += ( (p[i-1][j] - p[i][j])/dx );

}