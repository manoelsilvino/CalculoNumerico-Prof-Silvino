#ifndef PGS_H
#define PGS_H
using namespace std;

void PGS
(
    double** phi,
    double* dA,
    double* dB,
    double* dD,
    double* dE,
    double* dF,
    double* S_phi,
    const int & dim_dA,
    const int & dim_dB,
    const int & dim_dD,
    const int & dim_dE,
    const int & dim_dF,
    const int & Nx,
    const int & Ny
)
{
    int I;
    {
        int j = 0;
        int i = 0;

        I = j*(Nx-1)+i-1;

        phi[i][j] = ( S_phi[I]
                        - (dE[I]*phi[i+1][j] + dF[I]*phi[i][j+1])
                    )/(dD[I]);
    }

    {
        int j =0;
        for(int i = 1; i < Nx; i++)
        {
            I = j*(Nx-1)+i-1;
            phi[i][j] = ( S_phi[I]
                        -   ( dB[I-1]*phi[i-1][j]
                            + dE[I]*phi[i+1][j] 
                            + dF[I]*phi[i][j+1]
                            )
                    )/(dD[I]);
        }
    }

    for(int j = 1; j<(Ny-1); j++)
    {
        for(int i=1; i<Nx; i++)
        {
            I = j*(Nx-1)+i-1;
            phi[i][j] = ( S_phi[I]
                        -   ( dA[I-Nx]*phi[i][j-1]
                            + dB[I-1] *phi[i-1][j]
                            + dE[I]   *phi[i+1][j] 
                            + dF[I]   *phi[i][j+1]
                            )
                         )/(dD[I]);
        }
    }

    {
        int j = Ny-1;
        for(int i = 1; i<(Nx-2); i++)
        {
            I = j*(Nx-1)+i-1;
            phi[i][j] = ( S_phi[I]
                        -   ( dA[I-Nx]*phi[i][j-1]
                            + dB[I-1] *phi[i-1][j]
                            + dE[I]   *phi[i+1][j] 
                            )
                        )/(dD[I]);
        }
    }

    {
        int j = Ny-1;
        int i = Nx-1;
        I = j*(Nx-1)+i-1;
            phi[i][j] = ( S_phi[I]
                        -   ( dA[I-Nx]*phi[i][j-1]
                            + dB[I-1] *phi[i-1][j] 
                            )
                        )/(dD[I]);
    }


    for(int i = 0; i < Nx; i++)
    for(int j = 0; j<Ny; j++)
    {
        cout << "u["<< i <<"]["<<j<<"]="<< phi[i][j] << endl;
    }
}

#endif