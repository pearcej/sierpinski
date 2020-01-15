 /* File:   main_sierpinski.cpp
 * Authors: Python version:    Jan Pearce 
 *          Conversion to C++: Jesse W. Walker
 */

#include "CTurtle.hpp"   //This brings in the CTurtle library for use
namespace ct = cturtle;  //This makes it possible to use the CTurtle commands using ct::

void draw_triangle(ct::Point a, ct::Point b, ct::Point c, ct::Color color, ct::Turtle& myTurtle){
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

//getMid already defined as "middle" function in C-Turtle namespace :)

void sierpinski(ct::Point a, ct::Point b, ct::Point c, int degree, ct::Turtle& myTurtle){
    const std::string colormap[] = {"blue", "red", "green", "white", "yellow", "violet", "orange"};
    draw_triangle(a,b,c, {colormap[degree]}, myTurtle);
    if(degree > 0){
        sierpinski(a, ct::middle(a, b), ct::middle(a, c), degree - 1, myTurtle);
        sierpinski(b, ct::middle(a, b), ct::middle(b, c), degree - 1, myTurtle);
        sierpinski(c, ct::middle(c, b), ct::middle(a, c), degree - 1, myTurtle);
    }
}

int main() {
    ct::TurtleScreen scr; //makes screen
    ct::Turtle rt(scr);   //makes Turtle on screen
    
	//graphing commands go below here
    ct::Point myPoints[] = {{-200, -100}, {0, 200}, {200, -100}};
    sierpinski(myPoints[0], myPoints[1], myPoints[2], 3, rt);
    
    scr.exitonclick();  //exists graphics screen
    return 0;
}
