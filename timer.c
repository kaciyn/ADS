# include <time.h>
# include <stdio.h>

struct timedata
{
    int stopped;
    double elapsed;
    int iterations;
    double average;
} ;

void timer ()
{
    for ( int i = 0; i < 10000; i ++)
    {
        printf (".");
    }
    printf ("\n");
}


void onedarray()
{
    char oboard[9] =
    {
       
            ' ', ' ', ' ',
            ' ', ' ', ' ',
            ' ', ' ', ' '
        
    };

    oboard[5] = 'x';
    oboard[9] = 'o';
    oboard[1] = 'x';

    for (int i = 0; i < 9; i++)
    {
        printf("%c ", oboard[i]  );
    }
}

void twodarray()
{
    char board[3][3] =
    {
        {'X', 'X', 'X'  },
        {'Y', 'Y', 'Y'},
        {'O', 'O', 'O'}
    };
    board[2][2] = 'x';
    board[3][3] = 'o';
    board[1][1] = 'x';

     int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%c ", board[i][j]  );

        }
        putchar('\n');
    }
}



void writeToCSV(struct timedata td)
{
    FILE *report;
    char path[] = "D:\\Uni\\ADS\\Scripts\\Output\\timereport.csv";

    if(report = fopen(path, "r"))
    {
        printf( "Appending existing csv report...");

        report = fopen(path, "a");
    }
    else
    {
        printf( "Creating new csv report...");

        report = fopen(path, "a");

        fprintf(report, "Stopped,Elapsed,Iterations,Average\n");
    }

    fprintf(report, "%d,%f,%d,%f\n", td.stopped, td.elapsed, td.iterations, td.average );

    fclose(report);
}

int main ()
{
    struct timedata td;

    printf( "Enter how many times you want the program to run: ");
    scanf("%d", &td.iterations);
    clock_t t;
    printf (" start : %d \n", ( int ) (t = clock ()));

    for ( int i = 0; i < td.iterations; i ++)
    {
        // timer();
        // onedarray();
        twodarray();

    }

    int stopped = (int ) (t = clock () - t);
    double elapsed = ( double ) t / CLOCKS_PER_SEC;
    double average = elapsed / td.iterations;

    td.stopped = stopped;
    td.elapsed = elapsed;
    td.average = average;

    printf (" Stopped at: %d ms\n", td.stopped);
    printf (" Elapsed: %f seconds \n", td.elapsed);
    printf (" Function iterated: %d times \n", td.iterations);
    printf (" Average run time for function: %f seconds \n", td.average );

    writeToCSV(td);

    return 0;
}

