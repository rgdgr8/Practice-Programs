for(int i=0;i<vertices;i++){
       pos[i] = false;//hex_position unoccupied
       if((i+1)%size==0 || i%size==0 || i<size || i>=(vertices-size))
          conns[i][0] = 4;//number of edges
       else
          conns[i][0] = 6;//number of edges
    }

   //corner cases
    conns[0][0] = 2;
    conns[vertices-1][0] = 2;
    conns[vertices-size][0] = 3;
    conns[size-1][0] = 3;
    
    for(int i=0;i<vertices;i++){//storing edges position
       conns[i][1] = i+1;
       conns[i][2] = i-1;
       conns[i][3] = i-size;
       conns[i][4] = i-size+1;
       conns[i][5] = i+size;
       conns[i][6] = i+size-1;
       if((i+1)%size==0){
          conns[i][4] = -1;
          conns[i][1] = -1;
       }else if(i%size==0){
          conns[i][2] = -1;
          conns[i][6] = -1;
       }else if(i<size){
          conns[i][3] = conns[i][4] = -1;
       }else if(i>=(vertices-size)){
          conns[i][5] = conns[i][6] = -1;
       }
    }

   //corner cases
    conns[0][2] = conns[0][3] = conns[0][4] = conns[0][6] = -1;
    conns[vertices-1][1] = conns[vertices-1][4] = conns[vertices-1][5] = conns[vertices-1][6] = -1;
    conns[vertices-size][2] = conns[vertices-size][5] = conns[vertices-size][6] = -1;
    conns[size-1][1] = conns[size-1][3] = conns[size-1][4] = -1;
    conn = conns;
