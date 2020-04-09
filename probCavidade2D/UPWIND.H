if (j==0)
{
    flux_N = 0.5*rho*(v[i-1][j+1] + v[i][j+1] );
    if (flux_N >= 0)
    {
        U[I][I] += flux_N*dx*dt;
    }else
    {
        J = (j+1)*(Nx-1) + i-1;
        U[I][ J ] += flux_N*dx*dt;
    }

    flux_S = 0;
    
    

    flux_W = -0.5*rho*( u[i][j]+u[i-1][j] );
    if (flux_W>=0)
    {
        U[I][I] += flux_W *dx*dy*dt;
    }else
    {
        J = j*(Nx-1) + i-2;// (i-1)-1;
        U[I][J] += flux_W *dx*dy*dt;
    }

    flux_E = 0.5*rho*( u[i][j]+u[i+1][j] );
    if (flux_E > 0)
    {
        U[I][J] += flux_E *dx*dy*dt;
    }else
    {
        J = j*(Nx-1) + i;// (i+1)-1; -> u[i+1][j]
        U[I][J] += flux_E *dx*dy*dt;
    }

}else if(j==(Ny-1))
{
    flux_N = 0;
    

    flux_S = -0.5*rho*(v[i-1][j] + v[i][j]);
    if (flux_S >= 0)
    {
        U[I][I] += flux_S *dx*dt;
    }else
    {
        J = (j-1)*(Nx-1) + i-1;
        U[I][ J ] += flux_S *dx*dt;
    }

    flux_W = -0.5*rho*( u[i][j]+u[i-1][j] );
    if (flux_W>=0)
    {
        U[I][I] += flux_W *dx*dy*dt;
    }else
    {
        J = j*(Nx-1) + i-2;// (i-1)-1;
        U[I][J] += flux_W *dx*dy*dt;
    }

    flux_E = 0.5*rho*( u[i][j]+u[i+1][j] );
    if (flux_E > 0)
    {
        U[I][J] += flux_E *dx*dy*dt;
    }else
    {
        J = j*(Nx-1) + i;// (i+1)-1; -> u[i+1][j]
        U[I][J] += flux_E *dx*dy*dt;
    }
}
else
{
    flux_N = 0.5*rho*(v[i-1][j+1] + v[i][j+1] );
    if (flux_N >= 0)
    {
        U[I][I] += flux_N*dx*dt;
    }else
    {
        J = (j+1)*(Nx-1) + i-1;
        U[I][ J ] += flux_N*dx*dt;
    }

    flux_S = -0.5*rho*(v[i-1][j] + v[i][j]);
    if (flux_S >= 0)
    {
        U[I][I] += flux_S *dx*dt;
    }else
    {
        J = (j-1)*(Nx-1) + i-1;
        U[I][ J ] += flux_S *dx*dt;
    }

    flux_W = -0.5*rho*( u[i][j]+u[i-1][j] );
    if (flux_W>=0)
    {
        U[I][I] += flux_W *dx*dy*dt;
    }else
    {
        J = j*(Nx-1) + i-2;// (i-1)-1;
        U[I][J] += flux_W *dx*dy*dt;
    }

    flux_E = 0.5*rho*( u[i][j]+u[i+1][j] );
    if (flux_E > 0)
    {
        U[I][J] += flux_E *dx*dy*dt;
    }else
    {
        J = j*(Nx-1) + i;// (i+1)-1; -> u[i+1][j]
        U[I][J] += flux_E *dx*dy*dt;
    }


}