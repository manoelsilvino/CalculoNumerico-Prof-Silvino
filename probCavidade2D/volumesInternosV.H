// VOLUMES-v INTERNOS


for(int j = 2; j < Ny-1; j++)
{
    for (int i = 1; i < Nx-1; i++)
    {
        I = (j-1)*Nx+i; // indice do volume (diagonal da matriz U)
        cout << "volume v :"<< I << endl;
        
        Sv[I] = Sv[I] + (-u[i][j]*rho*dx*dy); // u do tempo anterior

        V[I][I] = V[I][I] -rho*dx*dy;
        // calcula os fluxos convectivos nas faces (upwind)
        #include "UPWIND_V.H"

        // calcula a contribuicao dos fluxos difusivos nas faces
        
        // face N

         J = j*Nx+i;
        V[I][J] += ((mu*dx*dt)/dy);
        V[I][I] += (-(mu*dx*dt)/dy);

        // face S
        J = (j-2)*Nx+i;
        V[I][J] += ((mu*dx*dt)/dy);
        V[I][I] +=((-mu*dx*dt)/dy);

        //face W 
        J = (j-1)*Nx+i-1;
        V[I][I]  +=((-mu*dy*dt)/dx);
        V[I][J] += ((mu*dy*dt)/dx);

        //face E 
        J = (j-1)*Nx+i+1;
        V[I][I]   += ((-mu*dy*dt))/dx;
        V[I][J]   += ((mu*dy*dt)/dx);


        // termo fornte relativo a pressao
        Sv[I] += ( (p[i][j-1] - p[i][j])/dy );
        
    }
}