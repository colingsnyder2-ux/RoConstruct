// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Script {
    char pad[0x94];
    int field_x;
    void setValue(const int& value);
};

void Script::setValue(const int& value)
{
    if (value != field_x)
    {
        field_x = value;
        extern void __stdcall notifyChange(unsigned long);
        notifyChange(0xa3ec74);
    }
}
