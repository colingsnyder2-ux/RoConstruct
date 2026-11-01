// from server: 49% by Intel
struct Slot {
    char pad0[0x1C];
    void* field_1C;
    char pad20[0xC];
    void* field_2C;
};

struct Signal {
    char pad0[0x38];
    Slot* field_38;
};

struct PropertyDescriptor {
    char pad0[0x220];
    unsigned char field_220;

    unsigned char func_00798770();
};

extern "C" void* __cdecl func_0052acb0(void*);
extern "C" int __cdecl func_006c8100(void*, void*);
extern "C" int __cdecl func_0054a980(int);

unsigned char PropertyDescriptor::func_00798770() {
    if (!this)
        return 0;

    Signal* signal = *reinterpret_cast<Signal**>(reinterpret_cast<char*>(this) + 0x38);
    if (!signal)
        return 0;

    Slot* slot = signal->field_38;
    if (!slot)
        return 0;

    void* edi = slot->field_2C;
    void* eax = func_0052acb0(slot->field_1C);
    int result = func_006c8100(edi, eax);

    if (!result)
        return 0;

    if (func_0054a980(0))
        return field_220;

    return 1;
}
