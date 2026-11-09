// roc 2012-06 00a4c520  unit: CXTPTabManagerItem  size: 36 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00a4c520
//
// 00a4c520  8b442404             mov eax, dword ptr [esp + 4]
// 00a4c524  56                   push esi
// 00a4c525  8bf1                 mov esi, ecx
// 00a4c527  6a01                 push 1
// 00a4c529  c7460400000000       mov dword ptr [esi + 4], 0
// 00a4c530  c70600000000         mov dword ptr [esi], 0
// 00a4c536  894608               mov dword ptr [esi + 8], eax
// 00a4c539  e8f2f8ffff           call 0xa4be30
// 00a4c53e  8bc6                 mov eax, esi
// 00a4c540  5e                   pop esi
// 00a4c541  c20400               ret 4
// copied from an identical function in another client (function ?f@CXTPTabManagerItem@ns_ROCX00000d@@QAEHH@Z)

namespace ns_ROCX00000d {
struct CXTPTabManagerItem {
    int f(int);
};

extern void __stdcall g_006fdbc0(int);

int CXTPTabManagerItem::f(int a)
{
    *(int*)((char*)this + 4) = 0;
    *(int*)this = 0;
    *(int*)((char*)this + 8) = a;
    g_006fdbc0(1);
    return (int)this;
}
}
