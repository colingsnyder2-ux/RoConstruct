// from server: 100% by EspClaude
// roc-flags: /O2 /GS- /EHsc /MD
// from server: 87% by tajop
// roc 2007-08 0055f080  unit: RBX::ClearBackpack  size: 140 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0055f080
//
// 0055f080  64a100000000         mov eax, dword ptr fs:[0]
// 0055f086  6aff                 push -1
// 0055f088  68880a7500           push 0x750a88
// 0055f08d  50                   push eax
// 0055f08e  64892500000000       mov dword ptr fs:[0], esp
// 0055f095  56                   push esi
// 0055f096  8b4c2418             mov ecx, dword ptr [esp + 0x18]
// 0055f09a  8b01                 mov eax, dword ptr [ecx]
// 0055f09c  8b503c               mov edx, dword ptr [eax + 0x3c]
// 0055f09f  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 0055f0a7  ffd2                 call edx
// 0055f0a9  85c0                 test eax, eax
// 0055f0ab  7415                 je 0x55f0c2
// 0055f0ad  8b542414             mov edx, dword ptr [esp + 0x14]
// 0055f0b1  8b4a08               mov ecx, dword ptr [edx + 8]
// 0055f0b4  85c9                 test ecx, ecx
// 0055f0b6  7505                 jne 0x55f0bd
// 0055f0b8  894204               mov dword ptr [edx + 4], eax
// 0055f0bb  eb02                 jmp 0x55f0bf
// 0055f0bd  8901                 mov dword ptr [ecx], eax
// 0055f0bf  894208               mov dword ptr [edx + 8], eax
// 0055f0c2  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0055f0c6  85f6                 test esi, esi
// 0055f0c8  c744240cffffffff     mov dword ptr [esp + 0xc], 0xffffffff
// 0055f0d0  742a                 je 0x55f0fc
// 0055f0d2  8d4604               lea eax, [esi + 4]
// 0055f0d5  83c9ff               or ecx, 0xffffffff
// 0055f0d8  f00fc108             lock xadd dword ptr [eax], ecx
// 0055f0dc  751e                 jne 0x55f0fc
// 0055f0de  8b16                 mov edx, dword ptr [esi]
// 0055f0e0  8b4204               mov eax, dword ptr [edx + 4]
// 0055f0e3  8bce                 mov ecx, esi
// 0055f0e5  ffd0                 call eax
// 0055f0e7  8d4e08               lea ecx, [esi + 8]
// 0055f0ea  83caff               or edx, 0xffffffff
// 0055f0ed  f00fc111             lock xadd dword ptr [ecx], edx
// 0055f0f1  7509                 jne 0x55f0fc
// 0055f0f3  8b06                 mov eax, dword ptr [esi]
// 0055f0f5  8b5008               mov edx, dword ptr [eax + 8]
// 0055f0f8  8bce                 mov ecx, esi
// 0055f0fa  ffd2                 call edx
// 0055f0fc  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0055f100  64890d00000000       mov dword ptr fs:[0], ecx
// 0055f107  5e                   pop esi
// 0055f108  83c40c               add esp, 0xc
// 0055f10b  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedDecrement)

struct Node
{
    Node* next;
};

struct Item
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual Node* getNode();
};

struct NodeList
{
    int pad;
    Node* head;
    Node* tail;
};

struct CountedBase
{
    virtual ~CountedBase();
    virtual void dispose() = 0;
    virtual void destroy();
    long useCount;
    long weakCount;

    void release()
    {
        if (_InterlockedDecrement(&useCount) == 0)
        {
            dispose();
            if (_InterlockedDecrement(&weakCount) == 0)
                destroy();
        }
    }
};

struct ItemPtr
{
    Item* px;
    CountedBase* pn;

    ~ItemPtr()
    {
        if (pn)
            pn->release();
    }
};

void collectBackpackItem(NodeList* list, ItemPtr item)
{
    Node* n = item.px->getNode();
    if (n)
    {
        if (list->tail == 0)
            list->head = n;
        else
            list->tail->next = n;
        list->tail = n;
    }
}
