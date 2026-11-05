// from server: 51% by atomic.potato
struct Inner {
    char pad0[0xc];
    int* begin;
    int* end;
};

struct Mid {
    char pad0[0x50];
    Inner* inner;
};

struct Outer {
    char pad0[0xc];
    void* ptr;

    bool Check();
};

extern "C" Mid* __stdcall sub_4b0ad0(void*);

bool Outer::Check() {
    if (ptr == 0) return false;
    Mid* m = sub_4b0ad0(ptr);
    if (m == 0) return false;
    Inner* in = m->inner;
    if (in == 0) return false;
    return (in->end - in->begin) >> 3 != 0;
}
