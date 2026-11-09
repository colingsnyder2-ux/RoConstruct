// from server: 65% by atomic.potato
struct Inner {
    int field0;
};

struct Outer {
    char pad0[0x68];
    Inner* begin;
    Inner* end;
    int get(int index);
};

extern "C" int* __stdcall sub_5c6330(int* p);

int Outer::get(int index) {
    int* p = sub_5c6330(&index);
    int v = *p;
    if (v < 0) return 0;
    int count = (int)(end - begin);
    if ((unsigned)v >= (unsigned)count) return 0;
    return begin[v].field0;
}
