// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00552830  unit: RBX::RenderBase::AggregateChunk  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00552830
//
// 00552830  55                   push ebp
// 00552831  8bec                 mov ebp, esp
// 00552833  51                   push ecx
// 00552834  894dfc               mov dword ptr [ebp - 4], ecx
// 00552837  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0055283a  e8d1c91c00           call 0x71f210
// 0055283f  50                   push eax
// 00552840  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 00552843  e88804efff           call 0x442cd0
// 00552848  50                   push eax
// 00552849  8b4508               mov eax, dword ptr [ebp + 8]
// 0055284c  50                   push eax
// 0055284d  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 00552850  e80b000000           call 0x552860
// 00552855  8be5                 mov esp, ebp
// 00552857  5d                   pop ebp
// 00552858  c20800               ret 8

struct S_func_00442cd0
{
    char pad0[4];
    int m_x;
    int f();
};

struct S_func_0071f210
{
    int m_x;
    int f();
};

struct S
{
    void func_00552830(int, S_func_0071f210*);
    void func_00552860(int, int, int);
};

#pragma optimize("", off)
void S::func_00552830(int a, S_func_0071f210* p)
{
    func_00552860(a, ((S_func_00442cd0*)p)->f(), p->f());
}
