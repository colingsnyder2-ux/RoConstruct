// from server: 56% by colin
struct TGenericSlotWrapper_005c4b00 {
    void __cdecl construct(const void* slot);
};

extern "C" void __cdecl sub_00412dc0();
extern "C" void __cdecl sub_00630b9e(void*, const void*);

void TGenericSlotWrapper_005c4b00::construct(const void* slot)
{
    char buf[80];
    *(int*)(buf + 76) = 2;
    sub_00412dc0();
    sub_00630b9e(buf, (const void*)0x8410c0);
}
