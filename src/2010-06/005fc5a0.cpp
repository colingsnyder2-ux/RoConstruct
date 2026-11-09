// from server: 69% by atomic.potato
extern "C" void __stdcall sub_5fc4e0(int);

struct Tool
{
    char pad[0x168];
    int field_168;
    void func();
};

void Tool::func()
{
    int value = field_168;
    int remainder = value & 0x80000001;
    if (remainder < 0)
        remainder = ((remainder - 1) | -2) + 1;
    sub_5fc4e0(remainder + value + 1);
}
