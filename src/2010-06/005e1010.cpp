// from server: 44% by atomic.potato
struct Inner {
    void* vt;
    void* field4;
    char pad[0x14];
    int field1c;
};

struct Mid {
    char pad[0x4];
    Inner* field4;
    char pad2[0x4];
    void* fieldc;
};

struct Outer {
    void* vt;
    char pad[0x8];
    Mid* fieldc;

    void func_005e1010();
};

extern "C" void __stdcall func_005ee8e0(void*, void*);
extern "C" void __stdcall func_00653a30(void*);

void Outer::func_005e1010() {
    Mid* m = this->fieldc;
    void* p = (void*)((char*)m + 0x120);
    void* q = *(void**)p;
    void* (*fn)(void*, int) = *(void* (**)(void*, int))((char*)q + 4);
    void* r = fn(p, 0);
    func_00653a30(r);
    Inner* in = m->field4;
    void* s;
    if (in->field1c < 0x10) {
        s = (char*)in + 4;
    } else {
        s = in->field4;
    }
    func_005ee8e0(s, m->fieldc);
    void** v = *(void***)m->fieldc;
    void (*fn2)() = (void (*)())v[0];
    fn2();
}
