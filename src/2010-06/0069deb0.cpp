// from server: 71% by atomic.potato
struct SurfaceEnumPropDescriptor
{
    struct Base
    {
        virtual int Get(int) = 0;
    };

    int pad[8];
    Base* base;
    int f(int);
};

extern "C" int sub_005c5760(int*, int);

int SurfaceEnumPropDescriptor::f(int value)
{
    Base* p = base;
    int result = p->Get(value);
    return sub_005c5760(&value, result);
}
