// roc 2009-12 00728610  unit: boost::iostreams::Uinput::?$filtering_stream  size: 89 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00728610
//
// 00728610  51                   push ecx
// 00728611  53                   push ebx
// 00728612  56                   push esi
// 00728613  8b742414             mov esi, dword ptr [esp + 0x14]
// 00728617  57                   push edi
// 00728618  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 0072861c  56                   push esi
// 0072861d  57                   push edi
// 0072861e  e81df7ffff           call 0x727d40
// 00728623  56                   push esi
// 00728624  57                   push edi
// 00728625  8ad8                 mov bl, al
// 00728627  e814f7ffff           call 0x727d40
// 0072862c  56                   push esi
// 0072862d  57                   push edi
// 0072862e  88442427             mov byte ptr [esp + 0x27], al
// 00728632  e809f7ffff           call 0x727d40
// 00728637  56                   push esi
// 00728638  57                   push edi
// 00728639  8844242e             mov byte ptr [esp + 0x2e], al
// 0072863d  e8fef6ffff           call 0x727d40
// 00728642  0fb64c242e           movzx ecx, byte ptr [esp + 0x2e]
// 00728647  0fb654242f           movzx edx, byte ptr [esp + 0x2f]
// 0072864c  0fb6c0               movzx eax, al
// 0072864f  c1e008               shl eax, 8
// 00728652  03c1                 add eax, ecx
// 00728654  83c420               add esp, 0x20
// 00728657  c1e008               shl eax, 8
// 0072865a  03c2                 add eax, edx
// 0072865c  0fb6cb               movzx ecx, bl
// 0072865f  5f                   pop edi
// 00728660  c1e008               shl eax, 8
// 00728663  5e                   pop esi
// 00728664  03c1                 add eax, ecx
// 00728666  5b                   pop ebx
// 00728667  59                   pop ecx
// 00728668  c3                   ret 
// copied from an identical function in another client (function ?sub_005523f0@ns_ROCX00000d@ns_ROCX0000c0@@YAIHH@Z)

namespace ns_ROCX00000d {
namespace ns_ROCX000004 {
struct S {
    char pad[0x14];
    void* field14;
    void init();
};

extern void* g_77e4dc;
extern void* g_77e4e0;
extern void (__cdecl *g_77e4e4)(void*);

extern "C" void __cdecl sub_54d430();

void S::init()
{
    sub_54d430();
    field14 = g_77e4dc;
    field14 = g_77e4e0;
    g_77e4e4(&field14);
}
}
}
