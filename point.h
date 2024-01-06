#ifndef POINT_H
#define POINT_H


class point
{
    public:
        point(int x, int y);
        virtual ~point();
        int getXPos() const;
        int getYPos() const;

    protected:

    private:
        int d_xPos;
        int d_yPos;
};

#endif // POINT_H
