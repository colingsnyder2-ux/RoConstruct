// from server: 29% by atomic.potato
struct Inner {
    char pad0[4];
    void* vtbl;
};

struct Outer {
    Inner* p;
    char pad4[4];
    void f(float, float, float, float, float, float, float, float, float, float, float, float);
};

extern "C" void __stdcall sub_40a170(void*);
extern "C" void __cdecl sub_409480(void*);
extern "C" void __cdecl sub_5f3900(void*, void*);

void Outer::f(float a1, float a2, float a3, float a4, float a5, float a6, float a7, float a8, float a9, float a10, float a11, float a12)
{
    char buf[0x30];
    if (this->p == 0) {
        sub_409480(buf);
        sub_40a170(buf);
    }
    sub_5f3900(buf, &a1);
    *(float*)(buf + 0x24) = a10;
    *(float*)(buf + 0x28) = a11;
    *(float*)(buf + 0x2c) = a12;
    Inner* q = this->p;
    void* fn = q->vtbl;
    ((void (__stdcall *)(void*))fn)((char*)this + 8);
}
