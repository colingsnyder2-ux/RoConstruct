// from server: 6% by colin
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

extern "C" void __cdecl func_004f6180();
extern "C" void* __cdecl func_0062fef6(unsigned int);
extern "C" void __cdecl func_004dd250();
extern "C" void __cdecl func_00457dd0();
extern "C" void __cdecl func_00474f70();
extern "C" void __cdecl func_004eb510();
extern "C" void __cdecl func_004eec20();

struct HeadBuilder {
    void construct(float* a, float* b);
};

void HeadBuilder::construct(float* a, float* b)
{
    func_004f6180();
    *(void**)this = (void*)0x79f4ac;

    float* p = (float*)((char*)a + 8);
    if (!(a[0] < p[0]))
        p = a;

    float f = p[0] * *(double*)0x79f348;

    void* obj = func_0062fef6(0x1c);
    void* v = 0;
    if (obj) {
        *(void**)obj = (void*)0x797984;
        *(void**)((char*)obj + 4) = 0;
        *(void**)((char*)obj + 8) = 0;
        *(void**)obj = (void*)0x79f304;
        *(void**)((char*)obj + 0x10) = 0;
        *(void**)((char*)obj + 0x14) = 0;
        *(void**)((char*)obj + 0xc) = 0;
        *(int*)((char*)obj + 0x18) = 5;
        v = obj;
    }

    if (v) {
        InterlockedIncrement((long*)((char*)v + 4));
    }

    func_004dd250();

    if (v) {
        if (InterlockedDecrement((long*)((char*)v + 4)) == 0) {
            func_00457dd0();
            (*(void(__thiscall**)(void*, int))*(void**)v)(v, 1);
        }
    }

    func_00474f70();
    func_004eb510();
    func_004eec20();
}
