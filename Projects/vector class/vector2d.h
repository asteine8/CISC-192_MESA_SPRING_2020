#ifndef VECTOR2D_H
#define VECTOR2D_H

class Vector2D {

    public:
        double x,y;

        Vector2D();
        Vector2D(double a, double b);

        Vector2D add(Vector2D vect);
        static Vector2D add(Vector2D v1, Vector2D v2);

        Vector2D subtract(Vector2D vect);
        static Vector2D subtract(Vector2D v1, Vector2D v2);

        Vector2D mult(double scale);
        static Vector2D mult(Vector2D vect, double scale);

        Vector2D div(double denom);
        static Vector2D div(Vector2D vect, double denom);

        double dot(Vector2D vect);
        static double dot(Vector2D v1, Vector2D v2);

        double norm();
        static double norm(Vector2D vect);

        bool equals(Vector2D vect);
        static bool equals(Vector2D v1, Vector2D v2);
};

#endif