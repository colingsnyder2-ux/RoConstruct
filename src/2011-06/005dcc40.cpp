// from server: 65% by atomic.potato
struct Inner {
    int field0;
};

struct Outer {
    char pad0[0x68];
    Inner* begin;
    Inner* end;
    int get(int idx);
};

extern "C" int* __stdcall sub_5c2b40(int* p);

int Outer::get(int idx)
{
    int* p = sub_5c2b40((int*)((char*)&idx + 4));
    int v = *p;
    if (v < 0)
        return 0;
    int count = (int)(end - begin);
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return begin[v].field0;
}
