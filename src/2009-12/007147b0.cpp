// from server: 39% by atomic.potato
struct Lighting {
    char pad0[0x18];
    char field18[0x14];
    void* field2c;
    int field34;
    Lighting(int, int, int, int);
};

extern "C" void* __stdcall sub_6509c0(int, int);
extern "C" void __fastcall sub_702820(void*, void*);
extern "C" void* __stdcall sub_6322e0(void*);
extern "C" void* __stdcall sub_643110();
extern "C" void __fastcall sub_6aa720(void*);
extern "C" void* __fastcall sub_4f8c90(void*, void*, void*, void*);
extern "C" void __fastcall sub_4f73d0(void*, int);

extern int dword_B8FEB8;

Lighting::Lighting(int a, int b, int c, int d)
{
    void* p = sub_6509c0(b, a);
    sub_702820(this, p);
    field34 = c;
    void* q = sub_6322e0((void*)d);
    dword_B8FEB8++;
    void* r = sub_643110();
    sub_6aa720(&r);
    void* ebp = field2c;
    void* edx = *(void**)((char*)ebp + 4);
    void* ebx = sub_4f8c90(field18, ebp, edx, &r);
    sub_4f73d0(field18, 1);
    *(void**)((char*)ebp + 4) = ebx;
    void* eax = *(void**)((char*)ebx + 4);
    *(void**)eax = ebx;
    if (r) {
        void** vt = *(void***)r;
        void (*fn)(void*, int) = (void (*)(void*, int))vt[0];
        fn(r, 1);
    }
}
