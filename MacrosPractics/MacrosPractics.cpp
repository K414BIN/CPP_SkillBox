#include <iostream>

const int totalCars = 10;
const int totalSits = 20;

#define CARTOTAL(s,X) ((s == 0 ) ?  std::cout << "\n" << X << " car is empty!" : std::cout << "\n" << X << " car full for "<< s << " people")
#define CAR(_n,X) (_n=totalSits-X)

#define CALL_FUNCS(Sum,z,_n,x) \
do { \
    (std::cout << "\nPlease, enter number of people in car "<< z << " - "); \
    (std::cin >> x); \
    CAR(_n, x); \
    CARTOTAL(x,z); \
    (z = z - 1); \
    (Sum = Sum + _n); \
} while (z)

int main(int argc, char* argv[])
{
    int sum = 0;
    int sits = 0;
    int n = totalCars;
    int freesits = 0;
    std::cout << "\t\tWelcome, User!\nToday we will work as the head of the train!\n";
    CALL_FUNCS(sum,n, freesits, sits);
    std::cout << " \n ";
    n = totalSits * totalCars - sum; //people
    
    if (sum < 0)
    {
        std::cout << "The train is overloaded! \n";
        std::cout << "Total people in cars " << n << " \n ";

    }    else {

        std::cout << "Total free space " << sum << " \n ";
        std::cout << "Total people in cars " << n << " \n ";
    }
    return 0;
}
