#include <iostream>
using namespace std;

class FibonacciSeries {
private:
    int *series;
    int length;

public:
    FibonacciSeries() {
        length = 0;
        series = nullptr;
    }

    FibonacciSeries(int n) {
        length = n;
        series = new int[length];
        series[0] = 0;
        series[1] = 1;

        for (int i = 2; i < length; i++) {
            series[i] = series[i - 1] + series[i - 2];
        }
    }

    FibonacciSeries(const FibonacciSeries& other) {
        length = other.length;
        series = new int[length];
        for (int i = 0; i < length; i++) {
            series[i] = other.series[i];
        }
    }

    ~FibonacciSeries() {
        delete[] series;
    }

    void printSeries() {
        for (int i = 0; i < length; i++) {
            cout << series[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    FibonacciSeries f1(10);
    f1.printSeries();

    FibonacciSeries f2 = f1;
    f2.printSeries();

    return 0;
}
