// from server: 100% by EspClaude
// roc 2009-06 00472990  unit: RBX::LDraw2Lua::LDrawCommand  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00472990
//
// 00472990  64a100000000         mov eax, dword ptr fs:[0]
// 00472996  6aff                 push -1
// 00472998  68f9788600           push 0x8678f9
// 0047299d  50                   push eax
// 0047299e  64892500000000       mov dword ptr fs:[0], esp
// 004729a5  56                   push esi
// 004729a6  8d4c2418             lea ecx, [esp + 0x18]
// 004729aa  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 004729b2  ff15bce48900         call dword ptr [0x89e4bc]
// 004729b8  8b742414             mov esi, dword ptr [esp + 0x14]
// 004729bc  50                   push eax
// 004729bd  68b4da8b00           push 0x8bdab4
// 004729c2  56                   push esi
// 004729c3  e8483dfdff           call 0x446710
// 004729c8  83c408               add esp, 8
// 004729cb  50                   push eax
// 004729cc  e83f3dfdff           call 0x446710
// 004729d1  682cdb8b00           push 0x8bdb2c
// 004729d6  56                   push esi
// 004729d7  e8343dfdff           call 0x446710
// 004729dc  68a0da8b00           push 0x8bdaa0
// 004729e1  56                   push esi
// 004729e2  e8293dfdff           call 0x446710
// 004729e7  682cdb8b00           push 0x8bdb2c
// 004729ec  56                   push esi
// 004729ed  e81e3dfdff           call 0x446710
// 004729f2  83c420               add esp, 0x20
// 004729f5  8d4c2418             lea ecx, [esp + 0x18]
// 004729f9  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 00472a01  ff15c4e48900         call dword ptr [0x89e4c4]
// 00472a07  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00472a0b  32c0                 xor al, al
// 00472a0d  64890d00000000       mov dword ptr fs:[0], ecx
// 00472a14  5e                   pop esi
// 00472a15  83c40c               add esp, 0xc
// 00472a18  c22000               ret 0x20
// copied from an identical function in another client (function ?f@ns_ROCX00000a@@YG_NPAXUString@1@@Z)

namespace ns_ROCX00000a {
struct String;
typedef const char *(__thiscall *StringData)(const String *);
typedef void (__thiscall *StringDestroy)(String *);

extern StringData stringData;
extern StringDestroy stringDestroy;

struct String {
    unsigned char storage[28];
    ~String();
};

inline String::~String()
{
    stringDestroy(this);
}

extern void *__cdecl writeText(void *, const char *);
extern const char text81cb54[];
extern const char text81cbcc[];
extern const char text81cb40[];

bool __stdcall f(void *stream, String text)
{
    writeText(writeText(stream, text81cb54), stringData(&text));
    writeText(stream, text81cbcc);
    writeText(stream, text81cb40);
    writeText(stream, text81cbcc);
    return false;
}
}
