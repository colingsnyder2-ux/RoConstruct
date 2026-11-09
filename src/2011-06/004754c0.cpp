// from server: 51% by atomic.potato
extern "C" int __stdcall sub_0040dd60(int);

struct BoundVerb
{
    int pad0[2];
    int value;
    int pad1[15];
    int flag;
    int f();
};

int BoundVerb::f()
{
    if (flag == 0)
        return 0;
    return sub_0040dd60(value);
}
