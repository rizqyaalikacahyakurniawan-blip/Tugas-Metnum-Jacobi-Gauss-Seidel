#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {
    double x = 0, y = 0, z = 0;
    double x_lama, y_lama, z_lama;
    double error, tol = 0.0001;

    cout << fixed << setprecision(6);
    cout << "====================================\n";
    cout << "        METODE GAUSS-SEIDEL\n";
    cout << "====================================\n";
    cout << "Iterasi     x          y          z       Error\n";

    for (int i = 1; i <= 100; i++) {
        x_lama = x;
        y_lama = y;
        z_lama = z;

        // Gauss-Seidel
        x = (3 + y) / 4;
        y = (2 + x + z) / 4;
        z = (1 + y) / 3;

        // Error terbesar
        error = fabs(x - x_lama);

        if (fabs(y - y_lama) > error)
            error = fabs(y - y_lama);

        if (fabs(z - z_lama) > error)
            error = fabs(z - z_lama);

        cout << i << "       "
             << x << "   "
             << y << "   "
             << z << "   "
             << error << endl;

        if (error < tol) {
            cout << "\nKonvergen pada iterasi ke-" << i << endl;
            break;
        }
    }
    cout << "\nHasil akhir:\n";
    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;
    return 0;
}