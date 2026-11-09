// from server: 100% by colin
// roc 2007-08 0046a6c0  unit: RBX::LDraw2Lua::LDraw2RobloxMapRoot  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0046a6c0
//
// 0046a6c0  53                   push ebx
// 0046a6c1  8b5c2408             mov ebx, dword ptr [esp + 8]
// 0046a6c5  56                   push esi
// 0046a6c6  8b742410             mov esi, dword ptr [esp + 0x10]
// 0046a6ca  3bde                 cmp ebx, esi
// 0046a6cc  743a                 je 0x46a708
// 0046a6ce  57                   push edi
// 0046a6cf  8b7c2418             mov edi, dword ptr [esp + 0x18]
// 0046a6d3  8b46c0               mov eax, dword ptr [esi - 0x40]
// 0046a6d6  83ee40               sub esi, 0x40
// 0046a6d9  83ef40               sub edi, 0x40
// 0046a6dc  8907                 mov dword ptr [edi], eax
// 0046a6de  8b4e04               mov ecx, dword ptr [esi + 4]
// 0046a6e1  8d5608               lea edx, [esi + 8]
// 0046a6e4  894f04               mov dword ptr [edi + 4], ecx
// 0046a6e7  52                   push edx
// 0046a6e8  8d4f08               lea ecx, [edi + 8]
// 0046a6eb  ff1590e67700         call dword ptr [0x77e690]
// 0046a6f1  8d4624               lea eax, [esi + 0x24]
// 0046a6f4  50                   push eax
// 0046a6f5  8d4f24               lea ecx, [edi + 0x24]
// 0046a6f8  ff1590e67700         call dword ptr [0x77e690]
// 0046a6fe  3bf3                 cmp esi, ebx
// 0046a700  75d1                 jne 0x46a6d3
// 0046a702  8bc7                 mov eax, edi
// 0046a704  5f                   pop edi
// 0046a705  5e                   pop esi
// 0046a706  5b                   pop ebx
// 0046a707  c3                   ret 
// 0046a708  8b442414             mov eax, dword ptr [esp + 0x14]
// 0046a70c  5e                   pop esi
// 0046a70d  5b                   pop ebx
// 0046a70e  c3                   ret 
// copied from an identical function in another client (function ?copyBackward@@YAPAUEntry@@PAU1@00@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct StringStorage {
    char data[28];
};

extern StringStorage& (__thiscall *assignString)(
    StringStorage*, const StringStorage*);

struct Entry {
    unsigned int first;
    unsigned int second;
    StringStorage name;
    StringStorage value;
};

Entry* __cdecl copyBackward(Entry* first, Entry* last, Entry* result)
{
    while (first != last) {
        --last;
        --result;
        result->first = last->first;
        result->second = last->second;
        assignString(&result->name, &last->name);
        assignString(&result->value, &last->value);
    }
    return result;
}