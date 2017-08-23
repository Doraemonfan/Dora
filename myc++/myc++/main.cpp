#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
using namespace std;

int main() {
    int velocity_x = 1, velocity_y = 1;
    int top = 5, bottom = 20;
    int left = 10, right = 60;

    int x = 5, y = 10;
    for(;;) {
        x += velocity_x; y += velocity_y;
        system("cls");
        for(int i = 0; i <= bottom; i++) {
            if(i < top) { cout << "\n"; continue; }
            else if(i == top || i == bottom) {
                for(int j = 0; j <= right; j++) {
                    if(j < left) cout << ' ';
                    else cout << '-';
                }
                cout << "\n";
            }
            else if(i == x+top) {
                for(int j = 0; j <= right; j++) {
                    if(j == y+left) cout << "o";
                    else if(j == left || j == right) cout << '|';
                    else cout << ' ';
                }
                cout << "\n";
            }
            else {
                for(int j = 0; j <= right; j++) {
                    if(j == left || j == right) cout << '|';
                    else cout << ' ';
                }
                cout << "\n";
            }
        }
        Sleep(50);
        if(x == 0 || x == bottom-top) { cout << '\a'; velocity_x = -velocity_x; }
        if(y == 0 || y == right-left) { cout << '\a'; velocity_y = -velocity_y; }
    }
    return 0;
}
