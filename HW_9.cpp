#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.1416;

double distance(double x1, double y1, double x2, double y2) {
    double hasil = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
    return hasil;
}

double radius(double x1, double y1, double x2, double y2) {
    double r = distance(x1, y1, x2, y2);
    return r;
}

double circumference(double r) {
    return 2 * pi * r;
}

double area(double r) {
    return pi * r * r;
}


int main() {

double x1, y1, x2, y2;

cout << "masukkan koordinat titik pertama: ";
cin >> x1 >> y1;

cout << "masukkan koordinat titik kedua: ";
cin >> x2 >> y2;

double r = distance(x1, y1, x2, y2);
double k = circumference(r);
double l = area(r);

cout << "jarak antar dua titik tersebut adalah: " << distance(x1, y1, x2, y2) << endl;
cout << "panjang jari-jari lingkaran: " << r << endl;
cout << "keliling lingkaran: " << k << endl;
cout << "luas lingkaran: " << l;

return 0;
}