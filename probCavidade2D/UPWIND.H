
if (j==0)
{
    flux_N = 0.5*rho*(v[i-1][j+1] + v[i][j+1] );
    if (flux_N >= 0)
    {
        dU[I] += flux_N*dx*dt;
    }else
    {
        //J = (j+1)*(Nx-1) + i-1;
        fU[I] += flux_N*dx*dt;
    }

    flux_S = 0;
    
    

    flux_W = -0.5*rho*( u[i][j]+u[i-1][j] );
    if (flux_W>=0)
    {
        dU[I] += flux_W *dx*dy*dt;
    }else
    {
        //J = j*(Nx-1) + i-2;// (i-1)-1;
        bU[I-1] += flux_W *dx*dy*dt;
    }

    flux_E = 0.5*rho*( u[i][j]+u[i+1][j] );
    if (flux_E > 0)
    {
        dU[I] += flux_E *dx*dy*dt;
    }else
    {
        //J = j*(Nx-1) + i;// (i+1)-1; -> u[i+1][j]
        bU[I+1] += flux_E *dx*dy*dt;
        
    }

}else if(j==(Ny-1))
{
    flux_N = 0;
    

    flux_S = -0.5*rho*(v[i-1][j] + v[i][j]);
    if (flux_S >= 0)
    {
        dU[I] += flux_S *dx*dt;
    }else
    {
        //J = (j-1)*(Nx-1) + i-1;
        aU[I-Nx] += flux_S *dx*dt;
    }

    flux_W = -0.5*rho*( u[i][j]+u[i-1][j] );
    if (flux_W>=0)
    {
        dU[I] += flux_W *dx*dy*dt;
    }else
    {
        //J = j*(Nx-1) + i-2;// (i-1)-1;
        bU[I-1] += flux_W *dx*dy*dt;
    }

    flux_E = 0.5*rho*( u[i][j]+u[i+1][j] );
    if (flux_E > 0)
    {
        dU[I] += flux_E *dx*dy*dt;
    }else
    {
        //J = j*(Nx-1) + i;// (i+1)-1; -> u[i+1][j] = 0 qdo i=Nx-1
        eU[I+1] += flux_E *dx*dy*dt;
    }
}else if(i==1)
{
    flux_N = 0.5*rho*(v[i-1][j+1] + v[i][j+1] );
    if (flux_N >= 0)
    {
        dU[I] += flux_N*dx*dt;
    }else
    {
        //J = (j+1)*(Nx-1) + i-1;
        fU[I] += flux_N*dx*dt;
    }

    flux_S = -0.5*rho*(v[i-1][j] + v[i][j]);
    if (flux_S >= 0)
    {
        dU[I] += flux_S *dx*dt;
    }else
    {
        //J = (j-1)*(Nx-1) + i-1;
        aU[I-Nx] += flux_S *dx*dt;
    }

    flux_W = -0.5*rho*( u[i][j]+u[i-1][j] );
    if (flux_W>=0)
    {
        dU[I] += flux_W *dx*dy*dt;
    }else
    {
        //J = j*(Nx-1) + i-2;// (i-1)-1;
        bU[I-1] += flux_W *dx*dy*dt;
    }

    flux_E = 0.5*rho*( u[i][j]+u[i+1][j] );
    if (flux_E > 0)
    {
        dU[I] += flux_E *dx*dy*dt;
    }else
    {
        //J = j*(Nx-1) + i;// (i+1)-1; -> u[i+1][j]
        eU[I] += flux_E *dx*dy*dt;
    }
}else if (i==(Nx-1))
{
    flux_N = 0.5*rho*(v[i-1][j+1] + v[i][j+1] );
    if (flux_N >= 0)
    {
        dU[I] += flux_N*dx*dt;
    }else
    {
        //J = (j+1)*(Nx-1) + i-1;
        fU[I] += flux_N*dx*dt;
    }

    flux_S = -0.5*rho*(v[i-1][j] + v[i][j]);
    if (flux_S >= 0)
    {
        dU[I] += flux_S *dx*dt;
    }else
    {
        //J = (j-1)*(Nx-1) + i-1;
        aU[I-Nx] += flux_S *dx*dt;
    }

    flux_W = -0.5*rho*( u[i][j]+u[i-1][j] );
    if (flux_W>=0)
    {
        dU[I] += flux_W *dx*dy*dt;
    }else
    {
        //J = j*(Nx-1) + i-2;// (i-1)-1;
        bU[I-1] += flux_W *dx*dy*dt;
    }

    flux_E = 0.5*rho*( u[i][j]+u[i+1][j] );
    if (flux_E > 0)
    {
        dU[I] += flux_E *dx*dy*dt;
    }else
    {
        //J = j*(Nx-1) + i;// (i+1)-1; -> u[i+1][j]
        eU[I] += flux_E *dx*dy*dt;
    }
}
else
{
    flux_N = 0.5*rho*(v[i-1][j+1] + v[i][j+1] );
    if (flux_N >= 0)
    {
        dU[I] += flux_N*dx*dt;
    }else
    {
        //J = (j+1)*(Nx-1) + i-1;
        fU[I] += flux_N*dx*dt;
    }

    flux_S = -0.5*rho*(v[i-1][j] + v[i][j]);
    if (flux_S >= 0)
    {
        dU[I] += flux_S *dx*dt;
    }else
    {
        //J = (j-1)*(Nx-1) + i-1;
        aU[I-Nx] += flux_S *dx*dt;
    }

    flux_W = -0.5*rho*( u[i][j]+u[i-1][j] );
    if (flux_W>=0)
    {
        dU[I] += flux_W *dx*dy*dt;
    }else
    {
        //J = j*(Nx-1) + i-2;// (i-1)-1;
        bU[I-1] += flux_W *dx*dy*dt;
    }

    flux_E = 0.5*rho*( u[i][j]+u[i+1][j] );
    if (flux_E > 0)
    {
        dU[I] += flux_E *dx*dy*dt;
    }else
    {
        //J = j*(Nx-1) + i;// (i+1)-1; -> u[i+1][j]
        eU[I] += flux_E *dx*dy*dt;
    }


}