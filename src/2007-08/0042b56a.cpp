// from server: 48% by colin
// roc 2007-08 0042b56a  unit: EventHandler  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0042b56a
//
// 0042b56a  b805400080           mov eax, 0x80004005
// 0042b56f  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0042b572  64890d00000000       mov dword ptr fs:[0], ecx
// 0042b579  59                   pop ecx
// 0042b57a  5f                   pop edi
// 0042b57b  5e                   pop esi
// 0042b57c  5b                   pop ebx
// 0042b57d  8be5                 mov esp, ebp
// 0042b57f  5d                   pop ebp
// 0042b580  c22400               ret 0x24

struct EventHandler
{
    long __stdcall func_0042b56a(int, int, int, int, int, int, int, int);
};

long __stdcall EventHandler::func_0042b56a(int, int, int, int, int, int, int, int)
{
    return (long)0x80004005;
}
