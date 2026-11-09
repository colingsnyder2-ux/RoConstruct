// from server: 38% by atomic.potato
struct VPlayers {
    char pad0[0x8c];
    void* field_8c;
    char pad1[0x18];
    void* field_a8;

    void* sub_006521e0();
};

extern "C" {
    void* __stdcall sub_0089e4b4();
    void* __stdcall sub_0089e4c4();
}

void sub_00651c70();
void sub_005d1c30();

extern void* g_008b8b1c;
extern void* g_008b862c;

void* VPlayers::sub_006521e0()
{
    sub_00651c70();
    *(void**)((char*)this + 0x8c) = 0;
    *(void**)this = (void*)0x8df9ec;
    *(void**)((char*)this + 0x14) = (void*)0x8df9dc;
    *(void**)((char*)this + 0x18) = (void*)0x8df9d4;
    *(void**)((char*)this + 0x20) = (void*)0x8df9cc;
    sub_0089e4b4();
    *(void**)((char*)this + 0xa8) = 0;
    sub_0089e4b4();
    sub_005d1c30();
    sub_0089e4c4();

    return this;
}
