#include <iostream>

using namespace std;

int tabla[5],x;

main(){
cout << "inserte valor x" << endl; cin >> x;
for(x=1;x<=5;x++){ tabla[x]=x;} for(x=5;x>=1;x--){cout << "el valor es " << tabla[x] << endl;}
return 0;}

