class Wektor2D
{
private:
    double     x;
    double     y;
    static int num_vek;

public:
    Wektor2D()
    {
        x = 0.;
        y = 0.;
        std::cout << "x: " << x << ", y: " << y << std::endl;
        ++num_vek;
    }

    Wektor2D(double xInit, double yInit)
    {
        x = xInit;
        y = yInit;
        std::cout << "x: " << x << ", y: " << y << std::endl;
        ++num_vek;
    }

    ~Wektor2D()
    {
        std::cout << "Destroy\n";
        std::cout << "x: " << x << ", y: " << y << std::endl;
        --num_vek;
    }

    Wektor2D static kart(double xInit, double yInit) { return Wektor2D(xInit, yInit); }

    Wektor2D static bieg(double r, double fi)
    {
        /// @brief
        /// @param r - meters
        /// @param fi - in radians
        /// @return wektor2

        double xInit = r * cos(fi);
        double yInit = r * sin(fi);
        return Wektor2D(xInit, yInit);
    }

    double getX() { return x; }
    double getY() { return y; }

    void setX(double value) { x = value; }
    void setY(double value) { y = value; }

    double norm() { return sqrt(x * x + y * y); }

    void print() { std::cout << "x: " << x << ", y: " << y << std::endl; }

    void getNumOfVec() { std::cout << num_vek << std::endl; }
    
};
int  Wektor2D::num_vek = 0; // init of total vector number
Wektor2D operator+(Wektor2D w1, Wektor2D w2)
{
    return Wektor2D::kart(w1.getX() + w2.getX(), w1.getY() + w2.getY());
}

double operator*(Wektor2D w1, Wektor2D w2)
{
    double result = w1.getX() * w2.getX() + w1.getY()*w2.getY();
    return result;
}
std::ostream& operator<<(std::ostream& out, Wektor2D w)
{
    return out << w.getX() << "," << w.getY() << "\t";
}