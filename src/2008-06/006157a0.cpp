// from server: 100% by colin
// from server: 98% by king_originala
// roc 2008-06 006157a0  unit: RBX::VContentId::?$TypedPropertyDescriptor  size: 123 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006157a0
//
// 006157a0  8b442404             mov eax, dword ptr [esp + 4]
// 006157a4  56                   push esi
// 006157a5  57                   push edi
// 006157a6  6a00                 push 0
// 006157a8  68b8819400           push 0x9481b8
// 006157ad  8db004010000         lea esi, [eax + 0x104]
// 006157b3  687c909200           push 0x92907c
// 006157b8  8bf8                 mov edi, eax
// 006157ba  8b06                 mov eax, dword ptr [esi]
// 006157bc  6a00                 push 0
// 006157be  50                   push eax
// 006157bf  e802c00800           call 0x6a17c6
// 006157c4  83c414               add esp, 0x14
// 006157c7  85c0                 test eax, eax
// 006157c9  754b                 jne 0x615816
// 006157cb  eb03                 jmp 0x6157d0
// 006157cd  8d4900               lea ecx, [ecx]
// 006157d0  8b36                 mov esi, dword ptr [esi]
// 006157d2  6a00                 push 0
// 006157d4  6818869400           push 0x948618
// 006157d9  687c909200           push 0x92907c
// 006157de  6a00                 push 0
// 006157e0  56                   push esi
// 006157e1  e8e0bf0800           call 0x6a17c6
// 006157e6  83c414               add esp, 0x14
// 006157e9  85c0                 test eax, eax
// 006157eb  7402                 je 0x6157ef
// 006157ed  8bfe                 mov edi, esi
// 006157ef  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 006157f5  6a00                 push 0
// 006157f7  68b8819400           push 0x9481b8
// 006157fc  687c909200           push 0x92907c
// 00615801  81c604010000         add esi, 0x104
// 00615807  6a00                 push 0
// 00615809  50                   push eax
// 0061580a  e8b7bf0800           call 0x6a17c6
// 0061580f  83c414               add esp, 0x14
// 00615812  85c0                 test eax, eax
// 00615814  74ba                 je 0x6157d0
// 00615816  8bc7                 mov eax, edi
// 00615818  5f                   pop edi
// 00615819  5e                   pop esi
// 0061581a  c3                   ret 

extern "C" void* __cdecl runtime_cast(void*, long, void*, void*, int);

extern char instance_type[];
extern char workspace_type[];
extern char selectable_type[];

struct Node
{
    char padding[0x104];
    Node* parent;
};

Node* __cdecl findSelectable(Node* node)
{
    Node* result = node;
    Node** link = &node->parent;

    for (;;)
    {
        Node* next = *link;
        if (runtime_cast(next, 0, instance_type, workspace_type, 0))
            break;
        Node* parent = *link;
        if (runtime_cast(parent, 0, instance_type, selectable_type, 0))
            result = parent;
        link = &parent->parent;
    }

    return result;
}
