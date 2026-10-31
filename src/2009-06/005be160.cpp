// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0053f200  unit: RBX::RenderBase::AggregatingSceneManager  size: 125 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0053f200
//
// 0053f200  55                   push ebp
// 0053f201  8bec                 mov ebp, esp
// 0053f203  83ec10               sub esp, 0x10
// 0053f206  894dfc               mov dword ptr [ebp - 4], ecx
// 0053f209  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0053f20c  e8ffff1d00           call 0x71f210
// 0053f211  8945f8               mov dword ptr [ebp - 8], eax
// 0053f214  8b45f8               mov eax, dword ptr [ebp - 8]
// 0053f217  8b10                 mov edx, dword ptr [eax]
// 0053f219  8b4df8               mov ecx, dword ptr [ebp - 8]
// 0053f21c  8b420c               mov eax, dword ptr [edx + 0xc]
// 0053f21f  ffd0                 call eax
// 0053f221  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0053f224  8801                 mov byte ptr [ecx], al
// 0053f226  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0053f229  e8e2ff1d00           call 0x71f210
// 0053f22e  8945f4               mov dword ptr [ebp - 0xc], eax
// 0053f231  8b55f4               mov edx, dword ptr [ebp - 0xc]
// 0053f234  8b02                 mov eax, dword ptr [edx]
// 0053f236  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0053f239  8b5010               mov edx, dword ptr [eax + 0x10]
// 0053f23c  ffd2                 call edx
// 0053f23e  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0053f241  884101               mov byte ptr [ecx + 1], al
// 0053f244  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0053f247  e8c4ff1d00           call 0x71f210
// 0053f24c  8b55fc               mov edx, dword ptr [ebp - 4]
// 0053f24f  d94018               fld dword ptr [eax + 0x18]
// 0053f252  d95a04               fstp dword ptr [edx + 4]
// 0053f255  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0053f258  e8b3ff1d00           call 0x71f210
// 0053f25d  8945f0               mov dword ptr [ebp - 0x10], eax
// 0053f260  8b45fc               mov eax, dword ptr [ebp - 4]
// 0053f263  83c008               add eax, 8
// 0053f266  50                   push eax
// 0053f267  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 0053f26a  8b11                 mov edx, dword ptr [ecx]
// 0053f26c  8b4df0               mov ecx, dword ptr [ebp - 0x10]
// 0053f26f  8b4214               mov eax, dword ptr [edx + 0x14]
// 0053f272  ffd0                 call eax
// 0053f274  8b45fc               mov eax, dword ptr [ebp - 4]
// 0053f277  8be5                 mov esp, ebp
// 0053f279  5d                   pop ebp
// 0053f27a  c20400               ret 4

#pragma optimize("", off)

struct S_func_0071f210 {
    int m_x;
    int f();
};

struct Color {
    float r, g, b;
};

struct Source {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual bool first();
    virtual bool second();
    virtual Color color();

    unsigned char padding[12];
    float value;
};

struct S {
    bool first;
    bool second;
    float value;
    Color color;

    S(S_func_0071f210* source);
};

S::S(S_func_0071f210* source)
    : first(reinterpret_cast<Source*>(source->f())->first()),
      second(reinterpret_cast<Source*>(source->f())->second()),
      value(reinterpret_cast<Source*>(source->f())->value),
      color(reinterpret_cast<Source*>(source->f())->color())
{
}
