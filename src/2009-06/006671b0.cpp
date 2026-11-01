// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005d7c30  unit: RBX::P8Humanoid::?$GetSetImpl  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005d7c30
//
// 005d7c30  8b442404             mov eax, dword ptr [esp + 4]
// 005d7c34  8bd1                 mov edx, ecx
// 005d7c36  85c0                 test eax, eax
// 005d7c38  7405                 je 0x5d7c3f
// 005d7c3a  83c0ec               add eax, -0x14
// 005d7c3d  eb02                 jmp 0x5d7c41
// 005d7c3f  33c0                 xor eax, eax
// 005d7c41  56                   push esi
// 005d7c42  8b7220               mov esi, dword ptr [edx + 0x20]
// 005d7c45  51                   push ecx
// 005d7c46  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 005d7c4a  d901                 fld dword ptr [ecx]
// 005d7c4c  8b8850010000         mov ecx, dword ptr [eax + 0x150]
// 005d7c52  8b0c31               mov ecx, dword ptr [ecx + esi]
// 005d7c55  d91c24               fstp dword ptr [esp]
// 005d7c58  034a1c               add ecx, dword ptr [edx + 0x1c]
// 005d7c5b  8b5218               mov edx, dword ptr [edx + 0x18]
// 005d7c5e  8d8c0150010000       lea ecx, [ecx + eax + 0x150]
// 005d7c65  ffd2                 call edx
// 005d7c67  5e                   pop esi
// 005d7c68  c20800               ret 8

struct S
{
    char padding[0x18];
    void (__thiscall *setter)(void *, float);
    int adjustment;
    int virtualOffset;

    void f(void *object, const float *value);
};

void S::f(void *object, const float *value)
{
    char *base = object ? static_cast<char *>(object) - 0x18 : 0;
    float argument = *value;
    int offset = *reinterpret_cast<int *>(
        *reinterpret_cast<char **>(base + 0x140) + virtualOffset);
    setter(base + 0x140 + offset + adjustment, argument);
}
