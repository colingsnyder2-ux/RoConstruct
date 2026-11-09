// from server: 100% by EspClaude
// from server: 100% by tester
// roc 2008-06 005527d0  unit: RBX::RenderBase::AggregateChunk  size: 21 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005527d0
//
// 005527d0  55                   push ebp
// 005527d1  8bec                 mov ebp, esp
// 005527d3  51                   push ecx
// 005527d4  894dfc               mov dword ptr [ebp - 4], ecx
// 005527d7  6a00                 push 0
// 005527d9  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 005527dc  e8efdff2ff           call 0x4807d0
// 005527e1  8be5                 mov esp, ebp
// 005527e3  5d                   pop ebp
// 005527e4  c3                   ret 

struct S {
    void resize(int);
    void f();
};

#pragma optimize("", off)
void S::f()
{
    resize(0);
}
