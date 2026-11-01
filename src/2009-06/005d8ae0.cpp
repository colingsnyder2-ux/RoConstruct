// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

struct Obj {
    char pad[0x94];
    bool flag;
    void setFlag(bool value);
};

extern void __stdcall notifyChange(unsigned long);

void Obj::setFlag(bool value)
{
    if (flag != value)
    {
        flag = value;
        notifyChange(0xa44470);
    }
}
