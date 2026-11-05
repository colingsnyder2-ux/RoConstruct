// from server: 33% by colin
struct LDraw2RobloxMapRoot {
    char pad0[4];
    char field4[0x1c];
    char field20[0x1c];
    char field3c[0x20];
    char field5c[4];
    char field60[4];
    char field64[4];
    char field68[4];
    void destruct();
};

extern "C" void __stdcall sub_46A900(void*, void*, void*, void*);
extern "C" void __cdecl sub_62FC62(void*);
extern "C" void __stdcall sub_77E6AC(void*);

void LDraw2RobloxMapRoot::destruct()
{
    *(void**)this = (void*)0x7961a0;
    char* esi = (char*)this + 0x5c;
    if (*(void**)((char*)this + 0x60) == 0) {
        sub_46A900(*(void**)((char*)this + 0x60), esi, *(void**)(esi + 8), this);
        sub_62FC62(*(void**)(esi + 4));
    }
    *(void**)(esi + 4) = 0;
    *(void**)(esi + 8) = 0;
    *(void**)(esi + 0xc) = 0;
    sub_77E6AC((char*)this + 0x3c);
    sub_77E6AC((char*)this + 0x20);
    sub_77E6AC((char*)this + 4);
}
