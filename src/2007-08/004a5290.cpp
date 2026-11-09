// from server: 35% by colin
struct ClientProxy {
    void setX(float);
    void setY(float);
    void setZ(float);
    void setW(float);
    void setSomething(int, int, int);
    void setSomething2(int, int, int);
    void setSomething3(int, int, int);
    void doWork(float, float, float, float);
};

void ClientProxy::doWork(float a, float b, float c, float d)
{
    if (a != 0.0f)
        setX(a);
    else
        setX(0.0f);

    if (b != 0.0f)
        setY(b);
    else
        setY(0.0f);

    if (c != 0.0f)
        setZ(c);
    else
        setZ(0.0f);

    if (d != 0.0f)
        setW(d);
    else
        setW(0.0f);

    float f1 = b;
    if (f1 < 0.0f) f1 = -f1;
    int i1 = (int)(f1 * 100.0);
    setSomething(1, 16, i1);

    float f2 = c;
    if (f2 < 0.0f) f2 = -f2;
    int i2 = (int)(f2 * 100.0);
    setSomething2(1, 16, i2);

    float f3 = d;
    if (f3 < 0.0f) f3 = -f3;
    int i3 = (int)(f3 * 100.0);
    setSomething3(1, 16, i3);
}
