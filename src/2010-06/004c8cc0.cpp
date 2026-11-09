// from server: 31% by atomic.potato
struct Value { int x; };

extern "C" void __stdcall sub_00401690(void*, void*);
extern "C" void __stdcall sub_00402090(void*, void*);
extern "C" void* __stdcall sub_004c03a0();
extern "C" Value* __stdcall sub_004c0090();
extern "C" void __stdcall sub_005a10c0(void*);
extern "C" void __stdcall sub_005cb650(void*, void*, void*);
extern "C" void __stdcall sub_006abca0(void*, int, void*);
extern "C" void __stdcall sub_009ea90c();

struct Inner {
    char pad0[0xc];
    void* begin;
    void* end;
    void* cap;
};

struct S {
    char pad0[0x94];
    Inner inner;
    char pad1[0x8];
    void* begin2;
    void* end2;
    void* f();
};

void* S::f()
{
    sub_00401690((void*)0x00c049f4, (void*)0x004c1010);
    sub_004c03a0();
    int n = (int)((char*)end2 - (char*)begin2) >> 3;
    void* p = (void*)sub_004c0090();
    int idx = (int)p;
    int need = idx + 1;
    if ((unsigned)need > (unsigned)n) {
        void* tmp[2];
        tmp[0] = 0;
        tmp[1] = 0;
        sub_006abca0(&inner, need, tmp);
    } else {
        int cnt = (int)((char*)inner.end - (char*)inner.begin) >> 3;
        if (idx >= cnt)
            sub_009ea90c();
        void* e = *(void**)((char*)inner.begin + idx * 8);
        if (e != 0)
            return e;
    }
    sub_00401690((void*)0x00c049c8, (void*)0x004c0ed0);
    void* v = (void*)sub_004c0090();
    void* out;
    sub_005cb650(this, &out, v);
    void* r = out;
    if (r == 0) {
        sub_005a10c0(&out);
        return 0;
    }
    int cnt2 = (int)((char*)inner.end - (char*)inner.begin) >> 3;
    if (idx >= cnt2)
        sub_009ea90c();
    void* slot = (char*)inner.begin + idx * 8;
    *(void**)slot = r;
    sub_00402090((char*)slot + 4, &out);
    sub_005a10c0(&out);
    return r;
}
