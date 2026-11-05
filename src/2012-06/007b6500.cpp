// from server: 76% by atomic.potato
extern "C" void __fastcall Function_007b64a0(void *, int);

struct S_func_007b6500
{
    char pad[132];
    int field_84;
    char pad_88[4];
    int field_8c;
    void SetImpl(int);
};

void S_func_007b6500::SetImpl(int value)
{
    if (value != 0)
        field_84 = 0xb90484;
    Function_007b64a0(this, value);
    field_8c = 0;
}
