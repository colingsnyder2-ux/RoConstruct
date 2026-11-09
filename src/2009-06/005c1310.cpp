// from server: 100% by EspClaude
// from server: 84% by EspClaude
// roc 2009-06 005c1310  unit: RBX::VChunk::?$WeakReferenceCountedPointer  size: 163 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005c1310
//
// 005c1310  55                   push ebp
// 005c1311  8bec                 mov ebp, esp
// 005c1313  6aff                 push -1
// 005c1315  689b1e8600           push 0x861e9b
// 005c131a  64a100000000         mov eax, dword ptr fs:[0]
// 005c1320  50                   push eax
// 005c1321  64892500000000       mov dword ptr fs:[0], esp
// 005c1328  83ec14               sub esp, 0x14
// 005c132b  894de4               mov dword ptr [ebp - 0x1c], ecx
// 005c132e  8b4de4               mov ecx, dword ptr [ebp - 0x1c]
// 005c1331  e88a000000           call 0x5c13c0
// 005c1336  8b45e4               mov eax, dword ptr [ebp - 0x1c]
// 005c1339  8b4d08               mov ecx, dword ptr [ebp + 8]
// 005c133c  894804               mov dword ptr [eax + 4], ecx
// 005c133f  8b55e4               mov edx, dword ptr [ebp - 0x1c]
// 005c1342  837a0400             cmp dword ptr [edx + 4], 0
// 005c1346  745b                 je 0x5c13a3
// 005c1348  6a08                 push 8
// 005c134a  e8e9761500           call 0x718a38
// 005c134f  83c404               add esp, 4
// 005c1352  8945e8               mov dword ptr [ebp - 0x18], eax
// 005c1355  c745fc00000000       mov dword ptr [ebp - 4], 0
// 005c135c  837de800             cmp dword ptr [ebp - 0x18], 0
// 005c1360  741b                 je 0x5c137d
// 005c1362  8b45e4               mov eax, dword ptr [ebp - 0x1c]
// 005c1365  8b4804               mov ecx, dword ptr [eax + 4]
// 005c1368  8b5108               mov edx, dword ptr [ecx + 8]
// 005c136b  52                   push edx
// 005c136c  8b45e4               mov eax, dword ptr [ebp - 0x1c]
// 005c136f  50                   push eax
// 005c1370  8b4de8               mov ecx, dword ptr [ebp - 0x18]
// 005c1373  e8b8110c00           call 0x682530
// 005c1378  8945e0               mov dword ptr [ebp - 0x20], eax
// 005c137b  eb07                 jmp 0x5c1384
// 005c137d  c745e000000000       mov dword ptr [ebp - 0x20], 0
// 005c1384  8b4de0               mov ecx, dword ptr [ebp - 0x20]
// 005c1387  894dec               mov dword ptr [ebp - 0x14], ecx
// 005c138a  c745fcffffffff       mov dword ptr [ebp - 4], 0xffffffff
// 005c1391  8b55ec               mov edx, dword ptr [ebp - 0x14]
// 005c1394  8955f0               mov dword ptr [ebp - 0x10], edx
// 005c1397  8b45e4               mov eax, dword ptr [ebp - 0x1c]
// 005c139a  8b4804               mov ecx, dword ptr [eax + 4]
// 005c139d  8b55f0               mov edx, dword ptr [ebp - 0x10]
// 005c13a0  895108               mov dword ptr [ecx + 8], edx
// 005c13a3  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 005c13a6  64890d00000000       mov dword ptr fs:[0], ecx
// 005c13ad  8be5                 mov esp, ebp
// 005c13af  5d                   pop ebp
// 005c13b0  c20400               ret 4

// from server: 100% by colin
// roc-cl: 21022
// roc-flags: /Od /Ob0 /GS- /EHsc /MD
#pragma optimize("", off)

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct S;
struct Node;

struct Object
{
    unsigned char reserved[8];
    Node* head;
};

struct Node
{
    S* owner;
    Node* next;

    Node(S*, Node*);
};

struct S
{
    unsigned int reserved;
    Object* object;

    void __thiscall reset();
    void __thiscall f(Object*);
};

void S::f(Object* value)
{
    reset();
    object = value;
    if (object)
    {
        Node* node = new Node(this, object->head);
        object->head = node;
    }
}
