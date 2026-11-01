// from server: 100% by EspClaude
// roc 2009-06 00667000  unit: RBX::P8Humanoid::?$GetSetImpl  size: 56 bytes
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

struct S
{
    char padding[0x18];
    void (__thiscall *setter)(void *, int);
    int adjustment;
    int virtualOffset;

    void f(void *object, const int *value);
};

void S::f(void *object, const int *value)
{
    char *base = object ? static_cast<char *>(object) - 0x18 : 0;
    int argument = *value;
    int offset = *reinterpret_cast<int *>(
        *reinterpret_cast<char **>(base + 0x140) + virtualOffset);
    setter(base + 0x140 + offset + adjustment, argument);
}
