// from server: 62% by atomic.potato
struct Elem {
    int value;
};

struct Inner {
    Elem* begin;
    Elem* end;
};

struct Outer {
    char pad0[0x68];
    Elem* begin;
    Elem* end;
    char pad1[0x70 - 0x6c];

    int get(int idx);
};

extern "C" Inner* __stdcall getInner(int* p);

int Outer::get(int idx) {
    Inner* in = getInner(&idx);
    int v = in->begin->value;
    if (v < 0) return 0;
    int count = (int)((char*)end - (char*)begin) >> 2;
    if ((unsigned)v >= (unsigned)count) return 0;
    return begin[v].value;
}
