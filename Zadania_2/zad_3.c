#include <stdio.h>
#include <math.h>
typedef struct
{
    int x;
    int y;
}Point;
typedef struct
{
    Point* p1;
    Point* p2;
    Point* p3;
    Point* p4;
}Rectangle;
void move(Point* p)
{
    (*p).x++;
    (*p).y++;
}
void areaAndCimcunference(Rectangle* r)
{
    float length =sqrt(pow((*r).p2->x - (*r).p1->x, 2) + pow((*r).p2->y - (*r).p1->y, 2));
    float width = sqrt(pow((*r).p3->x - (*r).p1->x, 2) + pow((*r).p3->y - (*r).p1->y, 2));
    printf("Area: %f\n",  length*width);
    printf("Cimcunference: %f\n", 2*length+2*width);
}

int main()
{
    Point p = { 3,4 };
    printf("x: %d\n", p.x);
    printf("y: %d\n", p.y);
    move(&p);
    printf("x: %d\n", p.x);
    printf("y: %d\n", p.y);
    Point p2 = { 1,1 };
    Point p3 = { 1,5 };
    Point p4 = { 4,1 };
    Rectangle r1 = { &p,&p2,&p3,&p4 };
    areaAndCimcunference(&r1);
}//
// Created by wawrz on 11.03.2024.
//
