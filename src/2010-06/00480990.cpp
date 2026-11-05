// from server: 100% by Yeetserama
// roc 2010-06 00480990  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 241 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00480990
//
// 00480990  6aff                 push -1
// 00480992  68fb569800           push 0x9856fb
// 00480997  64a100000000         mov eax, dword ptr fs:[0]
// 0048099d  50                   push eax
// 0048099e  64892500000000       mov dword ptr fs:[0], esp
// 004809a5  83ec1c               sub esp, 0x1c
// 004809a8  53                   push ebx
// 004809a9  68702ea100           push 0xa12e70
// 004809ae  8d4c2408             lea ecx, [esp + 8]
// 004809b2  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 004809ba  ff1510a49e00         call dword ptr [0x9ea410]
// 004809c0  8d442404             lea eax, [esp + 4]
// 004809c4  50                   push eax
// 004809c5  8d4c2434             lea ecx, [esp + 0x34]
// 004809c9  51                   push ecx
// 004809ca  c644243001           mov byte ptr [esp + 0x30], 1
// 004809cf  e8ec2d0000           call 0x4837c0
// 004809d4  83c408               add esp, 8
// 004809d7  85c0                 test eax, eax
// 004809d9  8d4c2404             lea ecx, [esp + 4]
// 004809dd  0f94c3               sete bl
// 004809e0  c644242800           mov byte ptr [esp + 0x28], 0
// 004809e5  ff1500a49e00         call dword ptr [0x9ea400]
// 004809eb  84db                 test bl, bl
// 004809ed  7426                 je 0x480a15
// 004809ef  8d4c2430             lea ecx, [esp + 0x30]
// 004809f3  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 004809fb  ff1500a49e00         call dword ptr [0x9ea400]
// 00480a01  33c0                 xor eax, eax
// 00480a03  5b                   pop ebx
// 00480a04  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00480a08  64890d00000000       mov dword ptr fs:[0], ecx
// 00480a0f  83c428               add esp, 0x28
// 00480a12  c21c00               ret 0x1c
// 00480a15  68682ea100           push 0xa12e68
// 00480a1a  8d4c2408             lea ecx, [esp + 8]
// 00480a1e  ff1510a49e00         call dword ptr [0x9ea410]
// 00480a24  8d542404             lea edx, [esp + 4]
// 00480a28  52                   push edx
// 00480a29  8d442434             lea eax, [esp + 0x34]
// 00480a2d  50                   push eax
// 00480a2e  c644243002           mov byte ptr [esp + 0x30], 2
// 00480a33  e8882d0000           call 0x4837c0
// 00480a38  83c408               add esp, 8
// 00480a3b  85c0                 test eax, eax
// 00480a3d  8d4c2404             lea ecx, [esp + 4]
// 00480a41  0f94c3               sete bl
// 00480a44  c644242800           mov byte ptr [esp + 0x28], 0
// 00480a49  ff1500a49e00         call dword ptr [0x9ea400]
// 00480a4f  8d4c2430             lea ecx, [esp + 0x30]
// 00480a53  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 00480a5b  ff1500a49e00         call dword ptr [0x9ea400]
// 00480a61  b801000000           mov eax, 1
// 00480a66  84db                 test bl, bl
// 00480a68  7505                 jne 0x480a6f
// 00480a6a  b802000000           mov eax, 2
// 00480a6f  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00480a73  5b                   pop ebx
// 00480a74  64890d00000000       mov dword ptr fs:[0], ecx
// 00480a7b  83c428               add esp, 0x28
// 00480a7e  c21c00               ret 0x1c
// copied from an identical function in another client (function ?classify@ns_ROCX000011@@YGHUString@1@@Z)

namespace ns_ROCX000011 {
// from server: 100% by king_originala
struct String
{
    char storage[28];

    String(const char *);
    ~String();
};

extern void (__thiscall *constructString)(String *, const char *);
extern void (__thiscall *destroyString)(String *);
extern int __cdecl compare(const String &, const String &);

inline String::String(const char *text)
{
    constructString(this, text);
}

inline String::~String()
{
    destroyString(this);
}

int __stdcall classify(String value)
{
    if (compare(value, String("exact")) == 0)
        return 0;

    bool matched = compare(value, String("close")) == 0;
    if (matched)
        return 1;
    return 2;
}
}
