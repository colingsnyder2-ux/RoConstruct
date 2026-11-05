// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005527b0  unit: RBX::RenderBase::AggregateChunk  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005527b0
//
// 005527b0  55                   push ebp
// 005527b1  8bec                 mov ebp, esp
// 005527b3  51                   push ecx
// 005527b4  894dfc               mov dword ptr [ebp - 4], ecx
// 005527b7  6a00                 push 0
// 005527b9  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005527bc  e83f09fbff           call 0x503100
// 005527c1  8be5                 mov esp, ebp
// 005527c3  5d                   pop ebp
// 005527c4  c3                   ret 

struct S {
    void resize(int);
    void f();
};

#pragma optimize("", off)
void S::f()
{
    resize(0);
}
