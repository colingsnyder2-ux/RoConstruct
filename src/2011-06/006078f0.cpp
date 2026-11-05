// from server: 33% by atomic.potato
struct Inner {
    char pad0[4];
    int* begin;
    int* end;
};

struct Mid {
    char pad0[0x48];
    Inner* inner;
};

struct Outer {
    char pad0[0xc];
    void* ptr;
};

extern "C" Mid* __stdcall sub_4b1b80(void*);

struct RBX_ClearStarterpack {
    char pad0[0xc];
    void* field_c;
    bool check();
};

bool RBX_ClearStarterpack::check() {
    void* p = field_c;
    if (!p) return false;
    Mid* m = sub_4b1b80(p);
    if (!m) return false;
    Inner* in = m->inner;
    if (!in) {
        int eax = 0;
        int ecx = 0;
        return (ecx < eax) ? false : true;
    }
    int eax = (int)((char*)in->end - (char*)in->begin);
    int ecx = 0;
    eax >>= 3;
    return (ecx < eax) ? false : true;
}
