// from server: 100% by atomic.potato
extern "C" int __stdcall sub_4057F0(int, int, int, int);

struct CComAggObject
{
    int f(int);
};

int CComAggObject::f(int value)
{
    return sub_4057F0(*(int*)0x96C268, 0x6E, value, 0);
}
