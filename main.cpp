#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>

struct child
{
    int sex = 0;
    int day = 0;
    int month = 0;
};

void generateEvent(child parents[1000000][2], bool month)
{
    srand(time(NULL));
    
    if (!month) //month flag not set
    {
        for (size_t i = 0; i < 1000000; i++)
        {
            parents[i][0].sex = 1+(rand() % 2); //1 = boy, 2 = girl
            parents[i][0].day = 1+(rand() % 7); //1 == Sunday, 2 == Monday, ... 7 == Saturday
            parents[i][1].sex = 1+(rand() % 2);
            parents[i][1].day = 1+(rand() % 7);
        
            /*
            std::cout << "Couple "  << i+1 << "'s first child's sex is " << parents[i][0].sex << std::endl;
            std::cout << "Couple "  << i+1 << "'s first child's birthday is " << parents[i][0].day << std::endl;
            std::cout << "Couple "  << i+1 << "'s second child's sex is " << parents[i][1].sex << std::endl;
            std::cout << "Couple "  << i+1 << "'s second child's birthday is " << parents[i][1].day << std::endl << std::endl;
             */
        }
    }
    else //month flag set
    {
        for (size_t i = 0; i < 1000000; i++)
        {

             parents[i][0].sex   = 1+(rand() % 2); //1 = boy, 2 = girl
             parents[i][0].month = 1+(rand() % 12); //1 = January, 2 = February, ... 12 = December
             parents[i][1].sex   = 1+(rand() % 2);
             parents[i][1].month = 1+(rand() % 12);
         
            /*
             std::cout << "Couple "  << i << "'s child 1's sex = " << parents[i][0].sex << std::endl;
             std::cout << "Couple "  << i << "'s child 1's birth month = " << parents[i][0].month << std::endl;
             std::cout << "Couple "  << i << "'s child 2's sex = " << parents[i][1].sex << std::endl;
             std::cout << "Couple "  << i << "'s child 2's birth month = " << parents[i][1].month << std::endl << std::endl;
             */
        }
    }
}

void count(child parents[1000000][2], bool month, long double &twogirls, long double &gbirth)
{
    
    if (!month) //month flag not set
    {
    for (size_t i = 0; i < 1000000; i++)
    {
        if ((parents[i][0].day == 2 && parents[i][0].sex == 2)  || (parents[i][1].day == 2 && parents[i][1].sex == 2)) //the first child and/or the second child is a girl and born on a Monday
        {
            gbirth++;
            
            if (parents[i][0].sex == 2 && parents[i][1].sex == 2) //first and second child are girls
            {
                twogirls++;
            }
        }
        
    }
    
}
    else //month flag set
    {
        for (size_t i = 0; i < 1000000; i++)
        {
            if ((parents[i][0].month == 1 && parents[i][0].sex == 2)  || (parents[i][1].month == 1 && parents[i][1].sex == 2)) //the first child and/or the second child is a girl and born on a January
            {
                gbirth++;
                
                if (parents[i][0].sex == 2 && parents[i][1].sex == 2) //first and second child are girls
                {
                    twogirls++;
                }
            }
            
        }
    }
}

int main()
{
    
    child parents[1000000][2];
    
    bool month = 0; //set to 1 if simulating birth month instead of birth day
    
    generateEvent(parents, month); //generates 1000000 couples
    
    long double twogirls = 0.0;
    long double gbirth = 0.0;
    
    count(parents, month, twogirls, gbirth);
     
    
    long double probability = (twogirls/gbirth); //calculates probability of a couple having two girls given at least one of the girls is born on a Monday/January
    std::cout << probability;
     
}
    
   
    
    

