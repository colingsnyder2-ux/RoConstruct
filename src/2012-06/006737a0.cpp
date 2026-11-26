// from server: 100% by Xemicl
// roc 2012-06 006737a0  unit: RBX::AdornBillboarder  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006737a0
//
// 006737a0  55                   push ebp
// 006737a1  8bec                 mov ebp, esp
// 006737a3  83ec08               sub esp, 8
// 006737a6  894df8               mov dword ptr [ebp - 8], ecx
// 006737a9  c745fc00000000       mov dword ptr [ebp - 4], 0
// 006737b0  6a00                 push 0
// 006737b2  8b4508               mov eax, dword ptr [ebp + 8]
// 006737b5  50                   push eax
// 006737b6  8b4df8               mov ecx, dword ptr [ebp - 8]
// 006737b9  e812000000           call 0x6737d0
// 006737be  8b4dfc               mov ecx, dword ptr [ebp - 4]
// 006737c1  83c901               or ecx, 1
// 006737c4  894dfc               mov dword ptr [ebp - 4], ecx
// 006737c7  8b4508               mov eax, dword ptr [ebp + 8]
// 006737ca  8be5                 mov esp, ebp
// 006737cc  5d                   pop ebp
// 006737cd  c20400               ret 4
// copied from an identical function in another client (function ?begin@C@@QBE?AUIt@@XZ)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
struct It {
    int a, b;
    ~It();
};
struct C {
    It make(int i) const;
    It begin() const;
};
It C::begin() const
{
    return make(0);
}