// from server: 65% by atomic.potato
struct Inner {
    int value;
};

struct Outer {
    char pad0[0x68];
    Inner* begin;
    Inner* end;
    int get(int idx);
};

extern "C" int* __stdcall sub_4b3c60(int* p);

int Outer::get(int idx) {
    int* p = sub_4b3c60((int*)((char*)&idx + 4));
    int v = *p;
    if (v < 0) return 0;
    int count = (int)(((char*)end - (char*)begin) >> 2);
    if ((unsigned)v >= (unsigned)count) return 0;
    return begin[v].value;
}
