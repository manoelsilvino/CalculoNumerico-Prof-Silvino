

function[s] = bissecteste(s1,t,nActFields)
    
       MaxIter = 30;
       Niter   = 0;
        
      // sc;   
        bissecTOL    = 1e-8;    
   
       // scalar csi    = xb;
        
      nActFields = nActFields -1;/// !!!!!
       
        
        xa    = 1e-10;
        xb    = 2.5; // this value is enough to reach a value of s1 of the order until 1e-10
        
        sc = t;
        
                       
                    
        Fa =  sc*(  ( exp(xa) - 1 )/( exp(xa*nActFields) -1 )  ) - s1;
        Fb =  sc*(  ( exp(xb) - 1 )/( exp(xb*nActFields) -1 )  ) - s1;
        
        if Fa*Fb >= 0 then
        
            disp( "\nERROR in calcElapsedTime.H: We need a and b such that Fa*Fb < 0" );
            disp( "\nTry to use a larger value for maxNFields\n\n" );
             return 10000;
        end
        
        while( ( bissecTOL < (xb-xa)) ),
        
            csi = 0.5*(xa+xb);
            Fx = sc*(  ( exp(csi) - 1 )/( exp(csi*nActFields) -1 )  )- s1;
            if (Fa*Fx < 0) then
            
                xb =csi;
                
            else
            
                xa=csi;
                Fa = Fx;
                
            end
           
            
            Niter=Niter +1;
            
            if (Niter > MaxIter) then
                
                disp([ "\nERROR in calcElapsedTime.H: Max iter. reached\n" , string( Niter)]) ;
                return 10000;
            
            end
            
                   
        end
        
        disp(["\ncsi = ", string(csi) ]);
    
    Nfields = nActFields:-1:0; // com isso o vetor s esta na ordem decrescente - isso foi feito por causa da funcao tau.sci
    s = ( sc* (exp(csi.*Nfields) -1)./(exp(csi*nActFields) -1) )
    
endfunction
