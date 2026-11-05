// from server: 100% by EspClaude
// roc 2009-06 00445d80  unit: CBrowserDocManager  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00445d80
//
// 00445d80  8b4158               mov eax, dword ptr [ecx + 0x58]
// 00445d83  8b4824               mov ecx, dword ptr [eax + 0x24]
// 00445d86  8b11                 mov edx, dword ptr [ecx]
// 00445d88  8b8288000000         mov eax, dword ptr [edx + 0x88]
// 00445d8e  6a01                 push 1
// 00445d90  6a00                 push 0
// 00445d92  ffd0                 call eax
// 00445d94  8bc8                 mov ecx, eax
// 00445d96  e945dd0000           jmp 0x453ae0
// copied from an identical function in another client (function ?method@CRbxPlayDocTemplate@ns_ROCX000000@@QAEXXZ)

namespace ns_ROCX000000 {
struct Result {
    void finish();
};

struct CRbxPlayDocTemplate {
    char pad[0x58];
    void* field_58;
    void method();
};

void CRbxPlayDocTemplate::method()
{
    void* q = *(void**)((char*)field_58 + 0x24);
    void** vtable = *(void***)q;
    Result* (__thiscall *fn)(void*, int, int) =
        (Result* (__thiscall *)(void*, int, int))vtable[0x88 / 4];
    fn(q, 0, 1)->finish();
}
}
