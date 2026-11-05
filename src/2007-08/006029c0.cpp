// from server: 40% by colin
struct Humanoid;
struct RunningBase;

struct Running {
    char pad0[4];
    Humanoid* humanoid;
    char pad8[0x0c];
    void* field14;
    char pad18[4];
    float field1c;
    float field20;
    char pad24[4];
    float field28;
    float field2c;
    float field30;
    float field34;
    float field38;
    char pad3c[0x10];
    float field4c;
    void* onComputeForceImpl(void*);
};

extern "C" void __stdcall func_005a8210(int);
extern "C" void __stdcall func_005a8250(int);
extern "C" void* __stdcall func_0062fef6(unsigned int);
extern "C" void* __stdcall func_00626760(void*, void*);
extern "C" void* __stdcall func_00626e00(void*, void*);
extern "C" void* __stdcall func_00626a20(void*, void*);
extern "C" void* __stdcall func_005a91c0(void*, void*);
extern "C" void* __stdcall func_005a61f0(void*);
extern "C" void* __stdcall func_005a6210(void*);
extern "C" void* __stdcall func_005a6230(void*);
extern "C" void* __stdcall func_005fbeb0();
extern "C" void* __stdcall func_00530100(void*);
extern "C" void* __stdcall func_0052fbd0(void*, void*, void*);
extern "C" void* __stdcall func_00602820(void*, void*);

extern float g_797e9c;

void* Running::onComputeForceImpl(void* arg)
{
    void* result = func_00626760(this, arg);
    if (result != this)
        return result;

    if (field38 == 0.0f)
    {
        if (*(unsigned char*)((char*)humanoid + 0x164) & 1)
        {
            func_005a8210(0);
            void* p = func_0062fef6(0x34);
            if (p)
            {
                return func_00626e00(p, humanoid);
            }
            return 0;
        }
    }

    func_005a8210(0);
    if (*(unsigned char*)((char*)humanoid + 0x164) & 8)
    {
        func_005a8250(0);
        void* p = func_0062fef6(8);
        if (p)
        {
            return func_00626a20(p, humanoid);
        }
        return 0;
    }

    if (field14)
    {
        void* v = *(void**)((char*)field14 + 0x1d8);
        void* c = *(void**)((char*)humanoid + 0x198);
        func_005a91c0(c, v);
    }

    field4c = field20;

    if (func_005a61f0(humanoid))
    {
        void* a = func_005a61f0(humanoid);
        float f = *(float*)((char*)a + 0x60);
        field4c = field4c + f * g_797e9c;
    }

    if (func_005a6210(humanoid))
    {
        void* a = func_005a6210(humanoid);
        float f = *(float*)((char*)a + 0x60);
        field4c = field4c + f;
    }
    else if (func_005a6230(humanoid))
    {
        void* a = func_005a6230(humanoid);
        float f = *(float*)((char*)a + 0x60);
        field4c = field4c + f;
    }

    void* e;
    if (field14)
    {
        void* v = *(void**)((char*)field14 + 0x1d8);
        void* edi = *(void**)((char*)v + 0x64);
        func_00530100(edi);
        func_0052fbd0((char*)edi + 0x84, &e, &field1c);
    }
    else
    {
        e = func_005fbeb0();
    }

    field28 = *(float*)((char*)e + 0);
    field2c = *(float*)((char*)e + 4);
    field30 = *(float*)((char*)e + 8);
    field34 = *(float*)((char*)e + 0x10);

    func_00602820(this, arg);
    return this;
}
