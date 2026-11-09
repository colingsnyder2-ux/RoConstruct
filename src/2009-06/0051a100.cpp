// from server: 100% by EspClaude
// roc 2009-06 0051a100  unit: G3D::VVector3::?$Table  size: 133 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0051a100
//
// 0051a100  83ec10               sub esp, 0x10
// 0051a103  53                   push ebx
// 0051a104  56                   push esi
// 0051a105  57                   push edi
// 0051a106  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0051a10a  57                   push edi
// 0051a10b  8bf1                 mov esi, ecx
// 0051a10d  e8aed5ffff           call 0x5176c0
// 0051a112  8bd8                 mov ebx, eax
// 0051a114  895c2410             mov dword ptr [esp + 0x10], ebx
// 0051a118  85f6                 test esi, esi
// 0051a11a  7506                 jne 0x51a122
// 0051a11c  ff15ace98900         call dword ptr [0x89e9ac]
// 0051a122  8b06                 mov eax, dword ptr [esi]
// 0051a124  55                   push ebp
// 0051a125  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 0051a128  89442410             mov dword ptr [esp + 0x10], eax
// 0051a12c  85c0                 test eax, eax
// 0051a12e  7404                 je 0x51a134
// 0051a130  3bc0                 cmp eax, eax
// 0051a132  7406                 je 0x51a13a
// 0051a134  ff15ace98900         call dword ptr [0x89e9ac]
// 0051a13a  3bdd                 cmp ebx, ebp
// 0051a13c  5d                   pop ebp
// 0051a13d  741e                 je 0x51a15d
// 0051a13f  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0051a142  8b5318               mov edx, dword ptr [ebx + 0x18]
// 0051a145  3bca                 cmp ecx, edx
// 0051a147  8d430c               lea eax, [ebx + 0xc]
// 0051a14a  7c11                 jl 0x51a15d
// 0051a14c  7f09                 jg 0x51a157
// 0051a14e  3bf8                 cmp edi, eax
// 0051a150  0f92c0               setb al
// 0051a153  84c0                 test al, al
// 0051a155  7506                 jne 0x51a15d
// 0051a157  8d4c240c             lea ecx, [esp + 0xc]
// 0051a15b  eb11                 jmp 0x51a16e
// 0051a15d  8b0e                 mov ecx, dword ptr [esi]
// 0051a15f  8b4618               mov eax, dword ptr [esi + 0x18]
// 0051a162  894c2414             mov dword ptr [esp + 0x14], ecx
// 0051a166  89442418             mov dword ptr [esp + 0x18], eax
// 0051a16a  8d4c2414             lea ecx, [esp + 0x14]
// 0051a16e  8b11                 mov edx, dword ptr [ecx]
// 0051a170  8b442420             mov eax, dword ptr [esp + 0x20]
// 0051a174  8b4904               mov ecx, dword ptr [ecx + 4]
// 0051a177  5f                   pop edi
// 0051a178  5e                   pop esi
// 0051a179  8910                 mov dword ptr [eax], edx
// 0051a17b  894804               mov dword ptr [eax + 4], ecx
// 0051a17e  5b                   pop ebx
// 0051a17f  83c410               add esp, 0x10
// 0051a182  c20800               ret 8
// copied from an identical function in another client (function ?find@S@@QAE?AUIterator@@PBUKey@@@Z)

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