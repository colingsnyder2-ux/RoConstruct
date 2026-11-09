// from server: 100% by atomic.potato
extern "C" int __stdcall sub_00809F44(int, char*);

struct S
{
    char padding[0x98];
    int field98;
    char f();
};

char S::f()
{
    if (field98 == 0)
        return 1;

    char value;
    if (sub_00809F44(field98, &value) == 0x24)
        return 1;
    return value;
}
