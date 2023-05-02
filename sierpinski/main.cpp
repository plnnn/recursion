#include "CTurtle.hpp"

namespace ct = cturtle;

void draw_triangle(ct::Point a, ct::Point b, ct::Point c, const ct::Color& color, ct::Turtle& myTurtle) {
    myTurtle.fillcolor(color);
    myTurtle.penup();
    myTurtle.goTo(a.x, a.y);
    myTurtle.pendown();
    myTurtle.begin_fill();
    myTurtle.goTo(c.x, c.y);
    myTurtle.goTo(b.x, b.y);
    myTurtle.goTo(a.x, a.y);
    myTurtle.end_fill();
}

void sierpinski(ct::Point a, ct::Point b, ct::Point c, int degree, ct::Turtle& myTurtle) {
    const std::string colormap[] = {"blue", "red", "green", "white", "yellow", "violet", "orange", "pink", "magenta"};
    draw_triangle(a, b, c, {colormap[degree]}, myTurtle);
    if(degree > 0) {
        sierpinski(a, ct::middle(a, b), ct::middle(a, c), degree - 1, myTurtle);
        sierpinski(b, ct::middle(a, b), ct::middle(b, c), degree - 1, myTurtle);
        sierpinski(c, ct::middle(c, b), ct::middle(a, c), degree - 1, myTurtle);
    }
}

int main() {
    ct::TurtleScreen scr;
    ct::Turtle rt(scr);

    rt.speed(ct::TS_FASTEST);
    ct::Point myPoints[] = {{-200, -100}, {0, 200}, {200, -100}};
    sierpinski(myPoints[0], myPoints[1], myPoints[2], 6, rt);

    scr.exitonclick();
    return 0;
}
