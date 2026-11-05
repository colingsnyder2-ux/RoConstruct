// from server: 100% by Yeetserama
// roc 2010-06 00480a90  unit: RBX::LDraw2Lua::LDraw2RobloxColorMap  size: 344 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00480a90
//
// 00480a90  6aff                 push -1
// 00480a92  6834579800           push 0x985734
// 00480a97  64a100000000         mov eax, dword ptr fs:[0]
// 00480a9d  50                   push eax
// 00480a9e  64892500000000       mov dword ptr fs:[0], esp
// 00480aa5  83ec1c               sub esp, 0x1c
// 00480aa8  53                   push ebx
// 00480aa9  68842ea100           push 0xa12e84
// 00480aae  8d4c2408             lea ecx, [esp + 8]
// 00480ab2  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 00480aba  ff1510a49e00         call dword ptr [0x9ea410]
// 00480ac0  8d442404             lea eax, [esp + 4]
// 00480ac4  50                   push eax
// 00480ac5  8d4c2434             lea ecx, [esp + 0x34]
// 00480ac9  51                   push ecx
// 00480aca  c644243001           mov byte ptr [esp + 0x30], 1
// 00480acf  e8ec2c0000           call 0x4837c0
// 00480ad4  83c408               add esp, 8
// 00480ad7  85c0                 test eax, eax
// 00480ad9  8d4c2404             lea ecx, [esp + 4]
// 00480add  0f94c3               sete bl
// 00480ae0  c644242800           mov byte ptr [esp + 0x28], 0
// 00480ae5  ff1500a49e00         call dword ptr [0x9ea400]
// 00480aeb  84db                 test bl, bl
// 00480aed  7426                 je 0x480b15
// 00480aef  8d4c2430             lea ecx, [esp + 0x30]
// 00480af3  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 00480afb  ff1500a49e00         call dword ptr [0x9ea400]
// 00480b01  33c0                 xor eax, eax
// 00480b03  5b                   pop ebx
// 00480b04  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00480b08  64890d00000000       mov dword ptr fs:[0], ecx
// 00480b0f  83c428               add esp, 0x28
// 00480b12  c21c00               ret 0x1c
// 00480b15  68506ca000           push 0xa06c50
// 00480b1a  8d4c2408             lea ecx, [esp + 8]
// 00480b1e  ff1510a49e00         call dword ptr [0x9ea410]
// 00480b24  8d542404             lea edx, [esp + 4]
// 00480b28  52                   push edx
// 00480b29  8d442434             lea eax, [esp + 0x34]
// 00480b2d  50                   push eax
// 00480b2e  c644243002           mov byte ptr [esp + 0x30], 2
// 00480b33  e8882c0000           call 0x4837c0
// 00480b38  83c408               add esp, 8
// 00480b3b  85c0                 test eax, eax
// 00480b3d  8d4c2404             lea ecx, [esp + 4]
// 00480b41  0f94c3               sete bl
// 00480b44  c644242800           mov byte ptr [esp + 0x28], 0
// 00480b49  ff1500a49e00         call dword ptr [0x9ea400]
// 00480b4f  84db                 test bl, bl
// 00480b51  7429                 je 0x480b7c
// 00480b53  8d4c2430             lea ecx, [esp + 0x30]
// 00480b57  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 00480b5f  ff1500a49e00         call dword ptr [0x9ea400]
// 00480b65  b801000000           mov eax, 1
// 00480b6a  5b                   pop ebx
// 00480b6b  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00480b6f  64890d00000000       mov dword ptr fs:[0], ecx
// 00480b76  83c428               add esp, 0x28
// 00480b79  c21c00               ret 0x1c
// 00480b7c  68782ea100           push 0xa12e78
// 00480b81  8d4c2408             lea ecx, [esp + 8]
// 00480b85  ff1510a49e00         call dword ptr [0x9ea410]
// 00480b8b  8d4c2404             lea ecx, [esp + 4]
// 00480b8f  51                   push ecx
// 00480b90  8d542434             lea edx, [esp + 0x34]
// 00480b94  52                   push edx
// 00480b95  c644243003           mov byte ptr [esp + 0x30], 3
// 00480b9a  e8212c0000           call 0x4837c0
// 00480b9f  83c408               add esp, 8
// 00480ba2  85c0                 test eax, eax
// 00480ba4  8d4c2404             lea ecx, [esp + 4]
// 00480ba8  0f94c3               sete bl
// 00480bab  c644242800           mov byte ptr [esp + 0x28], 0
// 00480bb0  ff1500a49e00         call dword ptr [0x9ea400]
// 00480bb6  8d4c2430             lea ecx, [esp + 0x30]
// 00480bba  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 00480bc2  ff1500a49e00         call dword ptr [0x9ea400]
// 00480bc8  b802000000           mov eax, 2
// 00480bcd  84db                 test bl, bl
// 00480bcf  7505                 jne 0x480bd6
// 00480bd1  b8e7030000           mov eax, 0x3e7
// 00480bd6  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00480bda  5b                   pop ebx
// 00480bdb  64890d00000000       mov dword ptr fs:[0], ecx
// 00480be2  83c428               add esp, 0x28
// 00480be5  c21c00               ret 0x1c
// copied from an identical function in another client (function ?mapColor@ns_ROCX000012@@YGHUString@1@@Z)

namespace ns_ROCX000012 {
// from server: 100% by king_originala
struct String {
    unsigned char storage[28];
    String(const char*);
    ~String();
};

extern void (__thiscall *string_construct)(String*, const char*);
extern void (__thiscall *string_destroy)(String*);
extern int __cdecl compare(const String&, const String&);

inline String::String(const char* text)
{
    string_construct(this, text);
}

inline String::~String()
{
    string_destroy(this);
}

int __stdcall mapColor(String value)
{
    if (compare(value, String("ball")) == 0)
        return 0;
    if (compare(value, String("block")) == 0)
        return 1;
    if (compare(value, String("cylinder")) == 0)
        return 2;
    return 999;
}
}
