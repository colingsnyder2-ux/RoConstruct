// from server: 100% by colin
struct CMap {
    char pad[0x114];
    int field_114;
    int field_118;
    int field_11c;
    void sub_69dd50();
    void sub_43a8a0();
};

extern "C" void __cdecl sub_62fc62(void*);

void CMap::sub_43a8a0()
{
    CMap* p = this;
    int* esi;
    if (p != 0)
        esi = (int*)((char*)p + 0x114);
    else
        esi = 0;
    if (esi[2] != 0)
        sub_62fc62((void*)esi[2]);
    esi[2] = 0;
    esi[3] = 0;
    esi[4] = 0;
    sub_69dd50();
}
