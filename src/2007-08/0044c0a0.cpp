// from server: 100% by colin
// roc 2007-08 0044c0a0  unit: CRobloxControlColorSelector  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044c0a0
//
// 0044c0a0  55                   push ebp
// 0044c0a1  8b6c240c             mov ebp, dword ptr [esp + 0xc]
// 0044c0a5  56                   push esi
// 0044c0a6  8b74240c             mov esi, dword ptr [esp + 0xc]
// 0044c0aa  3bf5                 cmp esi, ebp
// 0044c0ac  7426                 je 0x44c0d4
// 0044c0ae  53                   push ebx
// 0044c0af  57                   push edi
// 0044c0b0  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 0044c0b4  8d5f08               lea ebx, [edi + 8]
// 0044c0b7  8b07                 mov eax, dword ptr [edi]
// 0044c0b9  8906                 mov dword ptr [esi], eax
// 0044c0bb  8b4f04               mov ecx, dword ptr [edi + 4]
// 0044c0be  894e04               mov dword ptr [esi + 4], ecx
// 0044c0c1  53                   push ebx
// 0044c0c2  8d4e08               lea ecx, [esi + 8]
// 0044c0c5  ff1534d47700         call dword ptr [0x77d434]
// 0044c0cb  83c60c               add esi, 0xc
// 0044c0ce  3bf5                 cmp esi, ebp
// 0044c0d0  75e5                 jne 0x44c0b7
// 0044c0d2  5f                   pop edi
// 0044c0d3  5b                   pop ebx
// 0044c0d4  5e                   pop esi
// 0044c0d5  5d                   pop ebp
// 0044c0d6  c3                   ret 
// copied from an identical function in another client (function ?fillItems@@YAXPAUItem@@0PBU1@@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct Component {
    unsigned int value;
};

extern void (__thiscall *assignComponent)(Component *, const Component *);

struct Item {
    unsigned int first;
    unsigned int second;
    Component component;
};

void fillItems(Item *first, Item *last, const Item *value)
{
    for (; first != last; ++first) {
        first->first = value->first;
        first->second = value->second;
        assignComponent(&first->component, &value->component);
    }
}