for(int i = 1; i < Nx; i++)
{
    int j = Ny-1;

    I = j*(Nx-1)+i-1;
                cout << "volume xx :"<< I << endl;
                cout << "i :"<< i << endl;
                J = I;
                S[I] += (-u[i][j]*rho*dx*dy); // u do tempo anterior

                U[I][I] += (-rho*dx*dy);
                // calcula os fluxos convectivos nas faces (upwind)
                #include "UPWIND.H"

                // calcula a contribuicao dos fluxos difusivos nas faces
                
                 // face N

                cout << " face N:"<< endl;
                S[I] += (2*(mu*dx*dt)/dy)*velTampa;
                U[I][I] += (-2*(mu*dx*dt)/dy);

                // face S
                cout << " face S:"<< endl;
                J = (j-1)*(Nx-1)+i-1;
                U[I][J] += ((mu*dx*dt)/dy);
                U[I][I] +=((-mu*dx*dt)/dy);

                //face W 
                cout << " face W:"<< endl;
                J = j*(Nx-1)+i-2;//i-1-1
                U[I][I]  +=((-mu*dy*dt)/dx);
                U[I][J] += ((mu*dy*dt)/dx);

                //face E 
                cout << " face E:"<< endl;
                J = j*(Nx-1)+i;//i+1-1
                U[I][I]   += ((-mu*dy*dt))/dx;
                U[I][J]   += ((mu*dy*dt)/dx);

                // termo fornte relativo a pressao
                S[I] += ( (p[i-1][j] - p[i][j])/dx );

}