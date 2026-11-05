// from server: 55% by colin
struct CMap {
    void sub_43a470();
};

extern "C" void __cdecl sub_62fc62(void*);
extern "C" void __cdecl sub_69a150();

void CMap::sub_43a470()
{
    CMap* p = this;
    int* esi;
    if (p != 0)
        esi = (int*)((char*)p + 0x100);
    else
        esi = 0;
    if (esi[2] != 0)
        sub_62fc62((void*)esi[2]);
    esi[2] = 0;
    esi[3] = 0;
    esi[4] = 0;
    sub_69a150();
}
