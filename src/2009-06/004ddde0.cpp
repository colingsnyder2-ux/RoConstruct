// from server: 100% by EspClaude
// roc 2009-06 004ddde0  unit: RBX::Network::IdSerializer  size: 126 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004ddde0
//
// 004ddde0  53                   push ebx
// 004ddde1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 004ddde5  56                   push esi
// 004ddde6  8d44240c             lea eax, [esp + 0xc]
// 004dddea  50                   push eax
// 004dddeb  53                   push ebx
// 004dddec  8bf1                 mov esi, ecx
// 004dddee  e8bdf4ffff           call 0x4dd2b0
// 004dddf3  8a442414             mov al, byte ptr [esp + 0x14]
// 004dddf7  83c408               add esp, 8
// 004dddfa  84c0                 test al, al
// 004dddfc  750f                 jne 0x4dde0d
// 004dddfe  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004dde02  ff1568e58900         call dword ptr [0x89e568]
// 004dde08  5e                   pop esi
// 004dde09  5b                   pop ebx
// 004dde0a  c20800               ret 8
// 004dde0d  7930                 jns 0x4dde3f
// 004dde0f  57                   push edi
// 004dde10  8b7c2414             mov edi, dword ptr [esp + 0x14]
// 004dde14  57                   push edi
// 004dde15  53                   push ebx
// 004dde16  e805f7ffff           call 0x4dd520
// 004dde1b  0fb6442418           movzx eax, byte ptr [esp + 0x18]
// 004dde20  83e07f               and eax, 0x7f
// 004dde23  8d0cc500000000       lea ecx, [eax*8]
// 004dde2a  83c408               add esp, 8
// 004dde2d  2bc8                 sub ecx, eax
// 004dde2f  57                   push edi
// 004dde30  8d0c8e               lea ecx, [esi + ecx*4]
// 004dde33  ff1564e48900         call dword ptr [0x89e464]
// 004dde39  5f                   pop edi
// 004dde3a  5e                   pop esi
// 004dde3b  5b                   pop ebx
// 004dde3c  c20800               ret 8
// 004dde3f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004dde43  0fb6c0               movzx eax, al
// 004dde46  8d14c500000000       lea edx, [eax*8]
// 004dde4d  2bd0                 sub edx, eax
// 004dde4f  8d0496               lea eax, [esi + edx*4]
// 004dde52  50                   push eax
// 004dde53  ff1564e48900         call dword ptr [0x89e464]
// 004dde59  5e                   pop esi
// 004dde5a  5b                   pop ebx
// 004dde5b  c20800               ret 8
// copied from an identical function in another client (function ?read@Creator@ns_ROCX00006b@@QAEXPAUStream@2@PAUString@2@@Z)

namespace ns_ROCX00006b {
struct Stream;

struct String {
    char storage[28];
};

extern void (__thiscall *stringClear)(String*);
extern String& (__thiscall *stringAssign)(String*, const String&);

extern void __cdecl readTag(Stream*, unsigned char*);
extern void __cdecl readString(Stream*, String*);

struct Creator {
    String strings[128];
    void read(Stream*, String*);
};

void Creator::read(Stream* stream, String* result)
{
    unsigned char tag;
    readTag(stream, &tag);

    if (tag == 0) {
        stringClear(result);
    } else if (tag & 128) {
        readString(stream, result);
        stringAssign(&strings[tag & 127], *result);
    } else {
        stringAssign(result, strings[tag]);
    }
}
}
