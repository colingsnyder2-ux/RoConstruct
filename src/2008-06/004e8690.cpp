// from server: 100% by colin
// from server: 95% by king_originala
// roc 2008-06 004e8690  unit: RBX::Network::Players::Plugin  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004e8690
//
// 004e8690  83ec10               sub esp, 0x10
// 004e8693  53                   push ebx
// 004e8694  56                   push esi
// 004e8695  57                   push edi
// 004e8696  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 004e869a  57                   push edi
// 004e869b  8bf1                 mov esi, ecx
// 004e869d  e83edbffff           call 0x4e61e0
// 004e86a2  8bd8                 mov ebx, eax
// 004e86a4  895c2410             mov dword ptr [esp + 0x10], ebx
// 004e86a8  85f6                 test esi, esi
// 004e86aa  7506                 jne 0x4e86b2
// 004e86ac  ff1590288000         call dword ptr [0x802890]
// 004e86b2  8b06                 mov eax, dword ptr [esi]
// 004e86b4  55                   push ebp
// 004e86b5  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 004e86b8  89442410             mov dword ptr [esp + 0x10], eax
// 004e86bc  85c0                 test eax, eax
// 004e86be  7404                 je 0x4e86c4
// 004e86c0  3bc0                 cmp eax, eax
// 004e86c2  7406                 je 0x4e86ca
// 004e86c4  ff1590288000         call dword ptr [0x802890]
// 004e86ca  3bdd                 cmp ebx, ebp
// 004e86cc  5d                   pop ebp
// 004e86cd  741e                 je 0x4e86ed
// 004e86cf  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 004e86d2  8b5318               mov edx, dword ptr [ebx + 0x18]
// 004e86d5  3bca                 cmp ecx, edx
// 004e86d7  8d430c               lea eax, [ebx + 0xc]
// 004e86da  7c11                 jl 0x4e86ed
// 004e86dc  7f09                 jg 0x4e86e7
// 004e86de  3bf8                 cmp edi, eax
// 004e86e0  0f92c0               setb al
// 004e86e3  84c0                 test al, al
// 004e86e5  7506                 jne 0x4e86ed
// 004e86e7  8d4c240c             lea ecx, [esp + 0xc]
// 004e86eb  eb11                 jmp 0x4e86fe
// 004e86ed  8b0e                 mov ecx, dword ptr [esi]
// 004e86ef  8b4618               mov eax, dword ptr [esi + 0x18]
// 004e86f2  894c2414             mov dword ptr [esp + 0x14], ecx
// 004e86f6  89442418             mov dword ptr [esp + 0x18], eax
// 004e86fa  8d4c2414             lea ecx, [esp + 0x14]
// 004e86fe  8b11                 mov edx, dword ptr [ecx]
// 004e8700  8b442420             mov eax, dword ptr [esp + 0x20]
// 004e8704  8b4904               mov ecx, dword ptr [ecx + 4]
// 004e8707  5f                   pop edi
// 004e8708  5e                   pop esi
// 004e8709  8910                 mov dword ptr [eax], edx
// 004e870b  894804               mov dword ptr [eax + 4], ecx
// 004e870e  5b                   pop ebx
// 004e870f  83c410               add esp, 0x10
// 004e8712  c20800               ret 8
#include <intrin.h>

extern "C" void (__cdecl *invalid_parameter_noinfo)();

struct Key
{
    unsigned char padding[12];
    int value;

    bool less(const Key& other) const;
};

struct Node
{
    unsigned char padding[12];
    Key key;
};

struct Iterator
{
    void* owner;
    Node* node;

    bool equal(void* otherOwner, Node* otherNode) const;
    bool operator==(const Iterator& o) const { if (!(owner && owner == o.owner)) invalid_parameter_noinfo(); return node == o.node; }
};

struct S
{
    void* owner;
    unsigned char padding[20];
    Node* head;

    Node* lower_bound(const Key* key);
    Iterator find(const Key* key);
    Iterator end() { Iterator it; it.owner = owner; it.node = head; return it; }
};

inline bool Key::less(const Key& other) const
{
    if (value < other.value)
        return true;
    if (value > other.value)
        return false;
    return this < &other;
}

inline bool Iterator::equal(void* otherOwner, Node* otherNode) const
{
    if (!(owner && owner == otherOwner))
        invalid_parameter_noinfo();
    return node == otherNode;
}

Iterator S::find(const Key* key)
{
    Iterator found;
    found.node = lower_bound(key);
    if (!this)
        invalid_parameter_noinfo();
    found.owner = owner;
    Iterator finish;
    Iterator* selected;
    if (found == end() || key->less(found.node->key)) {
        finish.node = head;
        finish.owner = owner;
        selected = &finish;
    } else
        selected = &found;
    return *selected;
}
