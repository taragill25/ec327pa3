#include <iostream>
#include "View.h"

using namespace std;

View::View(){
    size = 11;
    scale = 2;
    origin = Point2D(); 
}

void View::Clear() {
    for(int i = 0; i < view_maxsize; i++){
        for(int j = 0; j < view_maxsize; j++){
            grid[i][j][0] = '.';
            grid[i][j][1] = ' ';
        }
    }
}

void View::Plot(GameObject * ptr) {
    int i,j;
    bool check;
    check = GetSubscripts(i, j, ptr->GetLocation());
    if (check && grid[i][j][0] == '.') {
        ptr->DrawSelf(grid[i][j]);
    }
    else if (check) {
        grid[i][j][0] = '*';
        grid[i][j][1] = ' ';
    return; 
}
}

//from piazza
void View::Draw() { 
for (int j = size-1; j >= -1; j--) {
        for (int i = -1; i <= size-1; i++) {
            if (i == -1 && j%2 == 0) {
                cout << j*2;
                if (j/5 == 0) {
                    cout << " ";
                }
            }
            else if (i == -1 && j%2 != 0) {
                cout << "  ";
            }
            else if (j == -1 && i%2 == 0) {
                cout << i*2;
                if (i/5 == 0) {
                    cout << " ";
                }
                cout << "  ";
            }
            if (i >= 0 && j >=0) {
                cout << grid[i][j][0] << grid[i][j][1];
            }
        }
        cout << endl;
    }
}

bool View::GetSubscripts(int& out_x, int& out_y, Point2D location){
    Vector2D vec;
    vec = (location - origin) / scale;
    out_x = vec.x;
    out_y = vec.y;
    if (out_x >= 0 && out_x <= size - 1 && out_y >= 0 && out_y <= size - 1) {
        return true;
    }
    else{
        cout << "An object is outside the display" << endl;
        return false;
    }
}
