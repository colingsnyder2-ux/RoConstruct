// from server: 44% by tester
struct CPropGrid {
    char pad0[0x17c];
    void* m_field17c;
    char pad180[8];
    int m_field188;
    char pad18c[4];
    int m_field190;
    int m_field194;
    int m_field198;
    char pad19c[0x18];
    char m_field1b4;
    char m_field1b5;
    char pad1b6[2];
    char pad1b8[0x10];
    char pad1c8[0x10];
    int m_field5c;
    CPropGrid();
};

extern "C" void __stdcall sub_006841C0();
extern "C" void __stdcall sub_00725700();
extern "C" void* __stdcall sub_005835B0();
extern "C" void* __stdcall sub_005A93B0();
extern "C" void* __stdcall sub_004D8640();

CPropGrid::CPropGrid()
{
    sub_006841C0();
    m_field17c = (void*)0x788344;
    m_field17c = (void*)0x78f40c;
    *(void**)this = (void*)0x78f41c;
    sub_00725700();
    m_field188 = 0;
    m_field190 = 0;
    m_field194 = 0;
    m_field198 = 0;

    void* p1 = sub_005835B0();
    *(void**)((char*)this + 0x1a0) = p1;
    *(char*)((char*)p1 + 0x15) = 1;
    *(void**)((char*)p1 + 4) = p1;
    *(void**)p1 = p1;
    *(void**)((char*)p1 + 8) = p1;
    *(void**)((char*)this + 0x1a4) = 0;

    void* p2 = sub_005835B0();
    *(void**)((char*)this + 0x1ac) = p2;
    *(char*)((char*)p2 + 0x15) = 1;
    *(void**)((char*)p2 + 4) = p2;
    *(void**)p2 = p2;
    *(void**)((char*)p2 + 8) = p2;
    *(void**)((char*)this + 0x1b0) = 0;

    m_field1b4 = 0;
    m_field1b5 = 0;

    void* p3 = sub_005A93B0();
    *(void**)((char*)this + 0x1bc) = p3;
    *(char*)((char*)p3 + 0x11) = 1;
    *(void**)((char*)p3 + 4) = p3;
    *(void**)p3 = p3;
    *(void**)((char*)p3 + 8) = p3;
    *(void**)((char*)this + 0x1c0) = 0;

    void* p4 = sub_004D8640();
    *(void**)((char*)this + 0x1c8) = p4;
    *(char*)((char*)p4 + 0x21) = 1;
    *(void**)((char*)p4 + 4) = p4;
    *(void**)p4 = p4;
    *(void**)((char*)p4 + 8) = p4;
    *(void**)((char*)this + 0x1cc) = 0;

    m_field5c = 0;
}
