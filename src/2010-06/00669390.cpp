// from server: 48% by atomic.potato
// roc 2010-06 00669390  unit: RBX::VSpawnLocation::?$FactoryProduct  size: 308 bytes

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);
extern "C" __declspec(dllimport) void* __cdecl basic_string_ctor(void*, const char*);
extern "C" __declspec(dllimport) void __cdecl basic_string_dtor(void*);

struct VSpawnLocation {
    char pad0[0x94];
    void* field94;
    void* field98;
    char pad9c[0x8];
    void* fielda4;
    char pada8[0x8];
    void* fieldb0;
    char padb4[0xc];
    void* fieldc0;
    char padc4[0x1cc];
    int field290;
    int field294;
    int field298;
    char field29c;
    char field29d;
    char pad29e[2];
    int field2a0;

    void FactoryProduct(int arg);
};

void sub_669290(void*, int);
void sub_637500(void*, void*);

void VSpawnLocation::FactoryProduct(int arg) {
    if (arg != 0) {
        *(void**)((char*)this + 0x98) = (void*)0xa45ab0;
        *(void**)((char*)this + 0xc4) = (void*)0xa45aa8;
    }
    sub_669290(this, 0);
    void* eax = *(void**)((char*)this + 0x98);
    *(void**)this = (void*)0xa3bc0c;
    *(void**)((char*)this + 4) = (void*)0xa3bc00;
    *(void**)((char*)this + 0x18) = (void*)0xa3bbf4;
    *(void**)((char*)this + 0x1c) = (void*)0xa3bbe8;
    *(void**)((char*)this + 0x94) = (void*)0xa3bbe0;
    *(void**)((char*)this + 0xa4) = (void*)0xa3bbcc;
    *(void**)((char*)this + 0xb0) = (void*)0xa3bbb4;
    *(void**)((char*)this + 0xc0) = (void*)0xa3bb8c;
    void* ecx = *(void**)((char*)eax + 4);
    *(void**)((char*)ecx + (int)this + 0x98) = (void*)0xa3bb84;
    void* edx = *(void**)((char*)this + 0x98);
    void* eax2 = *(void**)((char*)edx + 4);
    void* ecx2 = (void*)((char*)eax2 - 0x214);
    *(void**)((char*)eax2 + (int)this + 0x94) = ecx2;
    InterlockedIncrement((long volatile*)0xc007a8);
    *(int*)((char*)this + 0x290) = 0xc2;
    *(int*)((char*)this + 0x294) = 0;
    *(int*)((char*)this + 0x298) = 0;
    char buf[0x1c];
    basic_string_ctor(buf, (const char*)0xbbd898);
    *(char*)((char*)this + 0x29c) = 1;
    *(char*)((char*)this + 0x29d) = 0;
    *(int*)((char*)this + 0x2a0) = 0xa;
    sub_637500(this, buf);
    basic_string_dtor(buf);
}
