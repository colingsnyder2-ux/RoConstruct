// from server: 65% by atomic.potato
struct Inner {
    int value;
};

struct Outer {
    char pad[0x68];
    Inner* begin;
    Inner* end;
    int get(int idx);
};

extern "C" int* __stdcall sub_5c8f40(int* p);

int Outer::get(int idx) {
    int* p = sub_5c8f40(&idx);
    int v = *p;
    if (v < 0) return 0;
    int count = (int)(end - begin);
    if ((unsigned)v >= (unsigned)count) return 0;
    return begin[v].value;
}
