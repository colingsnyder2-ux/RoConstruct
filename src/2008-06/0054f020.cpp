// from server: 100% by colin
// roc 2008-06 0054bda0  unit: RBX::RenderBase::Mesh  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0054bda0
//
// 0054bda0  55                   push ebp
// 0054bda1  8bec                 mov ebp, esp
// 0054bda3  51                   push ecx
// 0054bda4  894dfc               mov dword ptr [ebp - 4], ecx
// 0054bda7  6a01                 push 1
// 0054bda9  8b4508               mov eax, dword ptr [ebp + 8]
// 0054bdac  50                   push eax
// 0054bdad  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054bdb0  e8ab130000           call 0x54d160
// 0054bdb5  8be5                 mov esp, ebp
// 0054bdb7  5d                   pop ebp
// 0054bdb8  c20400               ret 4

#pragma optimize("", off)

struct Mesh {
    void f(void* p);
    void g(void* p, int flag);
};

void Mesh::f(void* p)
{
    g(p, 1);
}
