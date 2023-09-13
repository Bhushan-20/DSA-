#include <iostream>
using namespace std;

struct petrolPump {
    int petrol;
    int distance;
};

int tour(petrolPump p[], int n){
    int kami=0;
       int balance = 0;
       int start = 0;
       
       for(int i=0; i<n; i++){
           balance += p[i].petrol - p[i].distance;
           if(balance < 0){
               kami += balance;
               start = i+1;
               balance = 0;
           }
       }
       
       if(kami + balance >= 0)
       {
           return start;
       }
       else{
           return -1;
       }
}

int main() {
    int n;
    cout << "Enter the number of petrol pumps: ";
    cin >> n;

    petrolPump p[n];

    cout << "Enter petrol and distance for each petrol pump:\n";
    for (int i = 0; i < n; i++) {
        cout << "Petrol for pump " << i + 1 << ": ";
        cin >> p[i].petrol;
        cout << "Distance to next pump from pump " << i + 1 << ": ";
        cin >> p[i].distance;
    }

    int start = tour(p, n);

    if (start == -1) {
        cout << "No circular tour is possible.\n";
    } else {
        cout << "Start from petrol pump " << start + 1 << " to complete the circular tour.\n";
    }

    return 0;
}
