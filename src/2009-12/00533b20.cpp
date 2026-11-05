// from server: 59% by atomic.potato
struct Ray
{
    int field0;
    short field4;
    int field8;
    int field12;
    int field16;

    Ray& __cdecl f(int, int);
};

extern "C" Ray& __cdecl sub_532f10(Ray&, int);
extern "C" Ray& __cdecl sub_532d00(Ray&, int*);

Ray& Ray::f(int a, int b)
{
    sub_532f10(*this, b);
    sub_532d00(*this, &field16);
    field4 = *((short*)&field16);
    return *this;
}
