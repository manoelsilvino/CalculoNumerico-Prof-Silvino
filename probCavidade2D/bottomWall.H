for(int i = 1; i < Nx; i++)
{
    int j = 0;

    I = j*(Nx-1)+i-1;
                cout << "volume :"<< I << endl;
                J = I;
                S[I] += (-u[i][j]*rho*dx*dy); // u do tempo anterior

                U[I][I] += (-rho*dx*dy);
                // calcula os fluxos convectivos nas faces (upwind)
                #include "UPWIND.H"

                // calcula a contribuicao dos fluxos difusivos nas faces
                
                 // face N

                J = (j+1)*(Nx-1)+i-1;
                U[I][J] += ((mu*dx*dt)/dy);
                U[I][I] += (-(mu*dx*dt)/dy);

                // face S
                J = (j-1)*(Nx-1)+i-1;
                U[I][J] += ((mu*dx*dt)/dy);
                U[I][I] +=((-mu*dx*dt)/dy);

                //face W 
                J = j*(Nx-1)+i-2;//i-1-1
                U[I][I]  +=((-mu*dy*dt)/dx);
                U[I][J] += ((mu*dy*dt)/dx);

                //face E 
                J = j*(Nx-1)+i;//i+1-1
                U[I][I]   += ((-mu*dy*dt))/dx;
                U[I][J]   += ((mu*dy*dt)/dx);

                // termo fornte relativo a pressao
                S[I] += ( (p[i-1][j] - p[i][j])/dx );

}