
if (j==0)
{
    flux_N = 0.5*rho*(v[i][j] + v[i][j+1] );
    if (flux_N >= 0)
    {
        V[I][I] += flux_N*dx*dt;
    }else
    {
        J = (j)*Nx + i;
        V[I][ J ] += flux_N*dx*dt;
    }

    flux_S = -0.5*rho*(v[i][j] + v[i][j-1]);
    if (flux_S >= 0)
    {
        V[I][I] += flux_S *dx*dt;
    }else
    {
        J = (j-2)*Nx + i;
        V[I][ J ] += flux_S *dx*dt;
    }

    flux_W = -0.5*rho*( u[i][j]+u[i][j-1] );
    if (flux_W>=0)
    {
        V[I][I] += flux_W *dx*dy*dt;
    }else
    {
        J = (j-1)*Nx + i-1;
        V[I][J] += flux_W *dx*dy*dt;
    }

    flux_E = 0.5*rho*( u[i+1][j]+u[i+1][j+1] );
    if (flux_E > 0)
    {
        V[I][J] += flux_E *dx*dy*dt;
    }else
    {
        J = (j-1)*Nx + i+1;
        V[I][J] += flux_E *dx*dy*dt;
    }

}else if(j==(Ny-1))
{
    flux_N = 0.5*rho*(v[i][j] + v[i][j+1] );
    if (flux_N >= 0)
    {
        V[I][I] += flux_N*dx*dt;
    }else
    {
        J = (j)*Nx + i;
        V[I][ J ] += flux_N*dx*dt;
    }

    flux_S = -0.5*rho*(v[i][j] + v[i][j-1]);
    if (flux_S >= 0)
    {
        V[I][I] += flux_S *dx*dt;
    }else
    {
        J = (j-2)*Nx + i;
        V[I][ J ] += flux_S *dx*dt;
    }

    flux_W = -0.5*rho*( u[i][j]+u[i][j-1] );
    if (flux_W>=0)
    {
        V[I][I] += flux_W *dx*dy*dt;
    }else
    {
        J = (j-1)*Nx + i-1;
        V[I][J] += flux_W *dx*dy*dt;
    }

    flux_E = 0.5*rho*( u[i+1][j]+u[i+1][j+1] );
    if (flux_E > 0)
    {
        V[I][J] += flux_E *dx*dy*dt;
    }else
    {
        J = (j-1)*Nx + i+1;
        V[I][J] += flux_E *dx*dy*dt;
    }

}else if(i==0)
{
    flux_N = 0.5*rho*(v[i][j] + v[i][j+1] );
    if (flux_N >= 0)
    {
        V[I][I] += flux_N*dx*dt;
    }else
    {
        J = (j)*Nx + i;
        V[I][ J ] += flux_N*dx*dt;
    }

    flux_S = -0.5*rho*(v[i][j] + v[i][j-1]);
    if (flux_S >= 0)
    {
        V[I][I] += flux_S *dx*dt;
    }else
    {
        J = (j-2)*Nx + i;
        V[I][ J ] += flux_S *dx*dt;
    }

    flux_W = 0;

    flux_E = 0.5*rho*( u[i+1][j]+u[i+1][j+1] );
    if (flux_E > 0)
    {
        V[I][J] += flux_E *dx*dy*dt;
    }else
    {
        J = (j-1)*Nx + i+1;
        V[I][J] += flux_E *dx*dy*dt;
    }
    
}else if (i==(Nx-1))
{
    flux_N = 0.5*rho*(v[i][j] + v[i][j+1] );
    if (flux_N >= 0)
    {
        V[I][I] += flux_N*dx*dt;
    }else
    {
        J = (j)*Nx + i;
        V[I][ J ] += flux_N*dx*dt;
    }

    flux_S = -0.5*rho*(v[i][j] + v[i][j-1]);
    if (flux_S >= 0)
    {
        V[I][I] += flux_S *dx*dt;
    }else
    {
        J = (j-2)*Nx + i;
        V[I][ J ] += flux_S *dx*dt;
    }

    flux_W = -0.5*rho*( u[i][j]+u[i][j-1] );
    if (flux_W>=0)
    {
        V[I][I] += flux_W *dx*dy*dt;
    }else
    {
        J = (j-1)*Nx + i-1;
        V[I][J] += flux_W *dx*dy*dt;
    }

    flux_E = 0;

}
else
{
    flux_N = 0.5*rho*(v[i][j] + v[i][j+1] );
    if (flux_N >= 0)
    {
        V[I][I] += flux_N*dx*dt;
    }else
    {
        J = j*Nx + i;
        V[I][ J ] += flux_N*dx*dt;
    }

    flux_S = -0.5*rho*(v[i][j] + v[i][j-1]);
    if (flux_S >= 0)
    {
        V[I][I] += flux_S *dx*dt;
    }else
    {
        J = (j-2)*Nx + i;
        V[I][ J ] += flux_S *dx*dt;
    }

    flux_W = -0.5*rho*( u[i][j]+u[i][j-1] );
    if (flux_W>=0)
    {
        V[I][I] += flux_W *dx*dy*dt;
    }else
    {
        J = (j-1)*Nx + i-1;
        V[I][J] += flux_W *dx*dy*dt;
    }

    flux_E = 0.5*rho*( u[i+1][j]+u[i+1][j+1] );
    if (flux_E > 0)
    {
        V[I][J] += flux_E *dx*dy*dt;
    }else
    {
        J = (j-1)*Nx + i+1;
        V[I][J] += flux_E *dx*dy*dt;
    }


}