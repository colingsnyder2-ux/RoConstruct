// from server: 100% by tester
// roc 2008-06 0054cce0  unit: RBX::RenderBase::Mesh  size: 41 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0054cce0
//
// 0054cce0  55                   push ebp
// 0054cce1  8bec                 mov ebp, esp
// 0054cce3  51                   push ecx
// 0054cce4  894dfc               mov dword ptr [ebp - 4], ecx
// 0054cce7  8b45fc               mov eax, dword ptr [ebp - 4]
// 0054ccea  50                   push eax
// 0054cceb  8b4d0c               mov ecx, dword ptr [ebp + 0xc]
// 0054ccee  51                   push ecx
// 0054ccef  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 0054ccf2  e8391e0000           call 0x54eb30
// 0054ccf7  50                   push eax
// 0054ccf8  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0054ccfb  e820160000           call 0x54e320
// 0054cd00  8b4508               mov eax, dword ptr [ebp + 8]
// 0054cd03  8be5                 mov esp, ebp
// 0054cd05  5d                   pop ebp
// 0054cd06  c20800               ret 8

struct Mesh;

struct Result {
    void initialize(void *, Mesh *);
};

struct Mesh {
    void *lookup(void *);
    Result *f(Result *, void *);
};

#pragma optimize("", off)
Result *Mesh::f(Result *result, void *arg)
{
    result->initialize(lookup(arg), this);
    return result;
}
#pragma optimize("", on)
