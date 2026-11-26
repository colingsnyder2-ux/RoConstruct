// from server: 100% by Xemicl
// roc 2012-06 0047b450  unit: VCWorkspace::?$CComObject  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0047b450
//
// 0047b450  8b442404             mov eax, dword ptr [esp + 4]
// 0047b454  8b08                 mov ecx, dword ptr [eax]
// 0047b456  83c104               add ecx, 4
// 0047b459  ff258425b200         jmp dword ptr [0xb22584]
// copied from an identical function in another client (function ?sub_0044d6d0@@YAHPAPAUA@@@Z)

// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD

struct B { __declspec(dllimport) int m(); };
struct A { int x; B b; };

int sub_0044d6d0(A** a)
{
    return (*a)->b.m();
}