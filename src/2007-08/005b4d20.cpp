// from server: 100% by colin
struct Geometry {
    int getSomething(void* arg);
};

int Geometry::getSomething(void* arg)
{
    int* p = (int*)arg;
    if ((int)this == p[2])
        return p[4];
    return p[5];
}
