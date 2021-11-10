unsigned* in_stepen(unsigned N, unsigned *arr, unsigned stepen)
{
    unsigned *a = (unsigned*) calloc (N * N, sizeof(unsigned));
    for (int st_counter = 0; st_counter < stepen - 1; st_counter++) 
    {
        unsigned *a = (unsigned*) calloc (N * N, sizeof(unsigned));
        for (int i = 0; i< N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                for (int k = 0; k < N; ++k)
                {  
                    *(a + N * i + j) = *(res + N * i + k) * *(res + j + N * k);  
                }            
            }
        }
        //copy
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                
                *(res + N * i + j) =  *(a + N * i + j);
                        
            }
        }

        free(a);
    }
    return res;
}

void powNxN (unsigned N, unsigned *arr, unsigned x) 
{
    unsigned *res = (unsigned*) calloc (N * N, sizeof(unsigned));
    unsigned *past = (unsigned*) calloc (N * N, sizeof(unsigned));
    unsigned *new = (unsigned*) calloc (N * N, sizeof(unsigned));

    int bit = -1;
    int mul = 0;
    while (x != 0)
    {
        ++bit;
        while (x % 2 == 0 && x != 0)
        {
            x = x / 2;
            ++bit;
        }
        mul++
        //возвести в степень нач матрицу и сохрнаить это значение
        res = in_stepen(N, arr, bit);
        //умножить на прошлую матрицу и сохранить значение 
        if (mul >= 2)
            for (int i = 0; i< N; ++i)
            {
                for (int j = 0; j < N; ++j)
                {
                    for (int k = 0; k < N; ++k)
                    {  
                        *(new + N * i + j) = *(res + N * i + k) * *(past + j + N * k);  
                    }            
                }
            }
        //copy
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                
                *(past + N * i + j) =  *(new + N * i + j);
                        
            }
        }

        x = x / 2;
        
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            
            *(n + N * i + j) =  *(new + N * i + j);
                    
        }
    }
    free(res);
    free(past);
    free(new);
   
}
