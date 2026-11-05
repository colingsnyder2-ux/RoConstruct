// from server: 100% by Yeetserama
// roc 2010-06 00482df0  unit: RBX::LDraw2Lua::LDrawCommand  size: 139 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00482df0
//
// 00482df0  64a100000000         mov eax, dword ptr fs:[0]
// 00482df6  6aff                 push -1
// 00482df8  68a97e9900           push 0x997ea9
// 00482dfd  50                   push eax
// 00482dfe  64892500000000       mov dword ptr fs:[0], esp
// 00482e05  56                   push esi
// 00482e06  8d4c2418             lea ecx, [esp + 0x18]
// 00482e0a  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00482e12  ff1508a49e00         call dword ptr [0x9ea408]
// 00482e18  8b742414             mov esi, dword ptr [esp + 0x14]
// 00482e1c  50                   push eax
// 00482e1d  68ec30a100           push 0xa130ec
// 00482e22  56                   push esi
// 00482e23  e8f8b0fcff           call 0x44df20
// 00482e28  83c408               add esp, 8
// 00482e2b  50                   push eax
// 00482e2c  e8efb0fcff           call 0x44df20
// 00482e31  686431a100           push 0xa13164
// 00482e36  56                   push esi
// 00482e37  e8e4b0fcff           call 0x44df20
// 00482e3c  68d830a100           push 0xa130d8
// 00482e41  56                   push esi
// 00482e42  e8d9b0fcff           call 0x44df20
// 00482e47  686431a100           push 0xa13164
// 00482e4c  56                   push esi
// 00482e4d  e8ceb0fcff           call 0x44df20
// 00482e52  83c420               add esp, 0x20
// 00482e55  8d4c2418             lea ecx, [esp + 0x18]
// 00482e59  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 00482e61  ff1500a49e00         call dword ptr [0x9ea400]
// 00482e67  8b4c2404             mov ecx, dword ptr [esp + 4]
// 00482e6b  32c0                 xor al, al
// 00482e6d  64890d00000000       mov dword ptr fs:[0], ecx
// 00482e74  5e                   pop esi
// 00482e75  83c40c               add esp, 0xc
// 00482e78  c22000               ret 0x20
// copied from an identical function in another client (function ?f@ns_ROCX00001f@@YG_NPAXUString@1@@Z)

namespace ns_ROCX00001f {
// from server: 100% by king_originala
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
