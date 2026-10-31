// from server: 100% by EspClaude
// roc 2009-06 004382b0  unit: Vector3Item  size: 148 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004382b0
//
// 004382b0  6aff                 push -1
// 004382b2  687aef8400           push 0x84ef7a
// 004382b7  64a100000000         mov eax, dword ptr fs:[0]
// 004382bd  50                   push eax
// 004382be  64892500000000       mov dword ptr fs:[0], esp
// 004382c5  51                   push ecx
// 004382c6  53                   push ebx
// 004382c7  56                   push esi
// 004382c8  57                   push edi
// 004382c9  8bf9                 mov edi, ecx
// 004382cb  e8201b3500           call 0x789df0
// 004382d0  33f6                 xor esi, esi
// 004382d2  8d9f30010000         lea ebx, [edi + 0x130]
// 004382d8  eb06                 jmp 0x4382e0
// 004382da  8d9b00000000         lea ebx, [ebx]
// 004382e0  6840010000           push 0x140
// 004382e5  e84e072e00           call 0x718a38
// 004382ea  83c404               add esp, 4
// 004382ed  8944240c             mov dword ptr [esp + 0xc], eax
// 004382f1  c744241800000000     mov dword ptr [esp + 0x18], 0
// 004382f9  85c0                 test eax, eax
// 004382fb  7418                 je 0x438315
// 004382fd  8b8f28010000         mov ecx, dword ptr [edi + 0x128]
// 00438303  8b972c010000         mov edx, dword ptr [edi + 0x12c]
// 00438309  56                   push esi
// 0043830a  51                   push ecx
// 0043830b  52                   push edx
// 0043830c  8bc8                 mov ecx, eax
// 0043830e  e8edfcffff           call 0x438000
// 00438313  eb02                 jmp 0x438317
// 00438315  33c0                 xor eax, eax
// 00438317  50                   push eax
// 00438318  8bcf                 mov ecx, edi
// 0043831a  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00438322  8903                 mov dword ptr [ebx], eax
// 00438324  e867363500           call 0x78b990
// 00438329  46                   inc esi
// 0043832a  83c304               add ebx, 4
// 0043832d  83fe03               cmp esi, 3
// 00438330  7cae                 jl 0x4382e0
// 00438332  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00438336  5f                   pop edi
// 00438337  5e                   pop esi
// 00438338  5b                   pop ebx
// 00438339  64890d00000000       mov dword ptr fs:[0], ecx
// 00438340  83c410               add esp, 0x10
// 00438343  c3                   ret 
// copied from an identical function in another client (function ?OnAddChildItem@Vector3Item@@QAEXXZ)

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