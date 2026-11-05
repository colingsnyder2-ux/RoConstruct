// from server: 36% by atomic.potato
struct Str_0068cdd0 { int words[8]; };

struct X_0068cdd0 {
    char pad[0x4];
    Str_0068cdd0 value;
    Str_0068cdd0* copy(Str_0068cdd0* out);
};

extern "C" void __stdcall sub_00594180();
extern "C" void __stdcall sub_0068cdd0();

struct TextBox {
    char pad0[0x208];
    X_0068cdd0 field_208;
    int getValue();
};

int TextBox::getValue()
{
    Str_0068cdd0 local;
    Str_0068cdd0* p = field_208.copy(&local);
    int v = *(int*)((char*)p + 0x14);
    int q = (int)(((unsigned long long)v * 0x51eb851fULL) >> 32) >> 5;
    int r = q;
    int one = 1;
    int* sel = (r > 1) ? &r : &one;
    int base = *sel;
    return base + 6;
}
