// from server: 100% by Yeetserama
// roc 2010-06 0043bad0  unit: Vector3Item  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0043bad0
//
// 0043bad0  6aff                 push -1
// 0043bad2  68da209800           push 0x9820da
// 0043bad7  64a100000000         mov eax, dword ptr fs:[0]
// 0043badd  50                   push eax
// 0043bade  64892500000000       mov dword ptr fs:[0], esp
// 0043bae5  51                   push ecx
// 0043bae6  53                   push ebx
// 0043bae7  56                   push esi
// 0043bae8  57                   push edi
// 0043bae9  8bf9                 mov edi, ecx
// 0043baeb  e8d0d23d00           call 0x818dc0
// 0043baf0  33f6                 xor esi, esi
// 0043baf2  8d9f30010000         lea ebx, [edi + 0x130]
// 0043baf8  eb06                 jmp 0x43bb00
// 0043bafa  8d9b00000000         lea ebx, [ebx]
// 0043bb00  6840010000           push 0x140
// 0043bb05  e896be3600           call 0x7a79a0
// 0043bb0a  83c404               add esp, 4
// 0043bb0d  8944240c             mov dword ptr [esp + 0xc], eax
// 0043bb11  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0043bb19  85c0                 test eax, eax
// 0043bb1b  7418                 je 0x43bb35
// 0043bb1d  8b8f28010000         mov ecx, dword ptr [edi + 0x128]
// 0043bb23  8b972c010000         mov edx, dword ptr [edi + 0x12c]
// 0043bb29  56                   push esi
// 0043bb2a  51                   push ecx
// 0043bb2b  52                   push edx
// 0043bb2c  8bc8                 mov ecx, eax
// 0043bb2e  e8bdfcffff           call 0x43b7f0
// 0043bb33  eb02                 jmp 0x43bb37
// 0043bb35  33c0                 xor eax, eax
// 0043bb37  50                   push eax
// 0043bb38  8bcf                 mov ecx, edi
// 0043bb3a  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 0043bb42  8903                 mov dword ptr [ebx], eax
// 0043bb44  e817ee3d00           call 0x81a960
// 0043bb49  46                   inc esi
// 0043bb4a  83c304               add ebx, 4
// 0043bb4d  83fe03               cmp esi, 3
// 0043bb50  7cae                 jl 0x43bb00
// 0043bb52  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0043bb56  5f                   pop edi
// 0043bb57  5e                   pop esi
// 0043bb58  5b                   pop ebx
// 0043bb59  64890d00000000       mov dword ptr fs:[0], ecx
// 0043bb60  83c410               add esp, 0x10
// 0043bb63  c3                   ret 
// copied from an identical function in another client (function ?OnAddChildItem@Vector3Item@@QAEXXZ)

// from server: 100% by king_originala
void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct PropertyGridItem {
    char padding[0x128];

    void OnAddChildItem();
    PropertyGridItem* AddChildItem(PropertyGridItem*);
};

struct ComponentItem : PropertyGridItem {
    char data[0x18];

    ComponentItem(void*, void*, int);
};

struct Vector3Item : PropertyGridItem {
    void* first;
    void* second;
    ComponentItem* children[3];

    void OnAddChildItem();
};

void Vector3Item::OnAddChildItem()
{
    PropertyGridItem::OnAddChildItem();
    for (int i = 0; i < 3; ++i) {
        children[i] = new ComponentItem(second, first, i);
        AddChildItem(children[i]);
    }
}