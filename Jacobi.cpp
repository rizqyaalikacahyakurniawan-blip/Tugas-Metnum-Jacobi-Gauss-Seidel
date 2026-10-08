#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
int main() {
    // Nilai awal
    double x = 0.0;
    double y = 0.0;
    double z = 0.0;

    // Nilai baru
    double x_new, y_new, z_new;

    // Toleransi
    double tol = 0.0001;

    // Maksimum iterasi
    int max_iter = 100;

    cout << fixed << setprecision(6);

    cout << "=============================================\n";
    cout << "              METODE JACOBI\n";
    cout << "=============================================\n";

    cout << "Iterasi       x          y          z       Error\n";

    for (int i = 1; i <= max_iter; i++) {
        // Rumus Jacobi
        x_new = (3.0 + y) / 4.0;
        y_new = (2.0 + x + z) / 4.0;
        z_new = (1.0 + y) / 3.0;

        // Menghitung error masing-masing
        double error_x = fabs(x_new - x);
        double error_y = fabs(y_new - y);
        double error_z = fabs(z_new - z);

        // Menentukan error terbesar
        double error = error_x;

        if (error_y > error)
            error = error_y;

        if (error_z > error)
            error = error_z;

        // Menampilkan hasil iterasi
        cout << setw(3) << i << "       "
             << setw(9) << x_new << "   "
             << setw(9) << y_new << "   "
             << setw(9) << z_new << "   "
             << setw(9) << error << endl;

        // Mengecek apakah sudah konvergen
        if (error < tol) {

            x = x_new;
            y = y_new;
            z = z_new;

            cout << "\nKonvergen pada iterasi ke-" << i << endl;

            break;
        }

        // Memperbarui nilai untuk iterasi berikutnya
        x = x_new;
        y = y_new;
        z = z_new;
    }

    cout << "\n=============================================\n";
    cout << "                HASIL AKHIR\n";
    cout << "=============================================\n";

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    return 0;
}