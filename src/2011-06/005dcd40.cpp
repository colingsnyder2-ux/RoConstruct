// from server: 65% by atomic.potato
struct Elem {
    int value;
};

struct Inner {
    Elem* begin;
    Elem* end;
};

struct Outer {
    char pad[0x68];
    Inner inner;
    int get(int idx);
};

extern "C" int* __stdcall sub_5c3650(int* p);

int Outer::get(int idx)
{
    int* p = sub_5c3650(&idx);
    int v = *p;
    if (v < 0)
        return 0;
    int count = (int)((inner.end - inner.begin));
    if ((unsigned)v >= (unsigned)count)
        return 0;
    return inner.begin[v].value;
}
