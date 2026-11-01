// from server: 100% by colin
// roc 2007-08 0046a670  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 68 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046a670
//
// 0046a670  56                   push esi
// 0046a671  8b742408             mov esi, dword ptr [esp + 8]
// 0046a675  3b74240c             cmp esi, dword ptr [esp + 0xc]
// 0046a679  7437                 je 0x46a6b2
// 0046a67b  53                   push ebx
// 0046a67c  55                   push ebp
// 0046a67d  57                   push edi
// 0046a67e  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0046a682  8d5f08               lea ebx, [edi + 8]
// 0046a685  8d6f24               lea ebp, [edi + 0x24]
// 0046a688  8b07                 mov eax, dword ptr [edi]
// 0046a68a  8906                 mov dword ptr [esi], eax
// 0046a68c  8b4f04               mov ecx, dword ptr [edi + 4]
// 0046a68f  894e04               mov dword ptr [esi + 4], ecx
// 0046a692  53                   push ebx
// 0046a693  8d4e08               lea ecx, [esi + 8]
// 0046a696  ff1590e67700         call dword ptr [0x77e690]
// 0046a69c  55                   push ebp
// 0046a69d  8d4e24               lea ecx, [esi + 0x24]
// 0046a6a0  ff1590e67700         call dword ptr [0x77e690]
// 0046a6a6  83c640               add esi, 0x40
// 0046a6a9  3b742418             cmp esi, dword ptr [esp + 0x18]
// 0046a6ad  75d9                 jne 0x46a688
// 0046a6af  5f                   pop edi
// 0046a6b0  5d                   pop ebp
// 0046a6b1  5b                   pop ebx
// 0046a6b2  5e                   pop esi
// 0046a6b3  c3                   ret 
// copied from an identical function in another client (function ?fillEntries@@YAXPAUEntry@@0PBU1@@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct String {
    char storage[28];
};

typedef String& (__thiscall *StringAssign)(String*, const String&);
extern StringAssign assignString;

struct Entry {
    unsigned int first;
    unsigned int second;
    String name;
    String value;
};

void __cdecl fillEntries(Entry* first, Entry* last, const Entry* source)
{
    for (; first != last; ++first) {
        first->first = source->first;
        first->second = source->second;
        assignString(&first->name, source->name);
        assignString(&first->value, source->value);
    }
}