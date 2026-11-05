// from server: 68% by atomic.potato
struct S
{
    int pad0[137];
    int field224;
    int pad1[93];
    int field198;

    int f();
};

extern "C" int __stdcall func_00796ae0(int, int*);

int S::f()
{
    int* p = reinterpret_cast<int*>(reinterpret_cast<char*>(this) + 0x224);
    int* q = reinterpret_cast<int*>(func_00796ae0(0, p));
    if (!q)
        return 0;
    int* r = reinterpret_cast<int*>(q[0x198 / 4]);
    if (!r)
        return 0;
    r = reinterpret_cast<int*>(r[0x108 / 4]);
    if (!r)
        return 0;
    return r[0x30 / 4];
}
