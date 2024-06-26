#include <iostream>
#include "Point2D.h"
#include "GameObject.h"

#ifndef View_h
#define View_h

using namespace std;

const int view_maxsize = 20;

class View {
public:
    View();
    void Clear();
    void Plot(GameObject* ptr);
    void Draw();
private:
    int size;
    double scale;
    Point2D origin;
    char grid[view_maxsize][view_maxsize][2];
    bool GetSubscripts(int& out_x, int& out_y, Point2D location);
};

#endif
