// from server: 84% by atomic.potato
struct Inner {
    int field0;
};

struct Outer {
    char pad0[0x68];
    Inner* begin;
    Inner* end;
    int get(int* idx);
};

extern "C" int* __cdecl sub_58e800(int* p);

int Outer::get(int* idx)
{
    int* p = sub_58e800(idx + 1);
    int v = *p;
    if (v < 0)
        return 0;
    int count = (int)((char*)end - (char*)begin) >> 2;
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return begin[v].field0;
}
