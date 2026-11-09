// from server: 100% by EspClaude
// roc 2009-06 0051a060  unit: G3D::VVector3::?$Table  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0051a060
//
// 0051a060  83ec10               sub esp, 0x10
// 0051a063  53                   push ebx
// 0051a064  56                   push esi
// 0051a065  57                   push edi
// 0051a066  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0051a06a  57                   push edi
// 0051a06b  8bf1                 mov esi, ecx
// 0051a06d  e80ee8ffff           call 0x518880
// 0051a072  8bd8                 mov ebx, eax
// 0051a074  895c2410             mov dword ptr [esp + 0x10], ebx
// 0051a078  85f6                 test esi, esi
// 0051a07a  7506                 jne 0x51a082
// 0051a07c  ff15ace98900         call dword ptr [0x89e9ac]
// 0051a082  8b06                 mov eax, dword ptr [esi]
// 0051a084  55                   push ebp
// 0051a085  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 0051a088  89442410             mov dword ptr [esp + 0x10], eax
// 0051a08c  85c0                 test eax, eax
// 0051a08e  7404                 je 0x51a094
// 0051a090  3bc0                 cmp eax, eax
// 0051a092  7406                 je 0x51a09a
// 0051a094  ff15ace98900         call dword ptr [0x89e9ac]
// 0051a09a  3bdd                 cmp ebx, ebp
// 0051a09c  5d                   pop ebp
// 0051a09d  742a                 je 0x51a0c9
// 0051a09f  8d430c               lea eax, [ebx + 0xc]
// 0051a0a2  8d4810               lea ecx, [eax + 0x10]
// 0051a0a5  8d5710               lea edx, [edi + 0x10]
// 0051a0a8  3bd1                 cmp edx, ecx
// 0051a0aa  721d                 jb 0x51a0c9
// 0051a0ac  7715                 ja 0x51a0c3
// 0051a0ae  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0051a0b1  8b500c               mov edx, dword ptr [eax + 0xc]
// 0051a0b4  3bca                 cmp ecx, edx
// 0051a0b6  7c11                 jl 0x51a0c9
// 0051a0b8  7f09                 jg 0x51a0c3
// 0051a0ba  3bf8                 cmp edi, eax
// 0051a0bc  0f92c0               setb al
// 0051a0bf  84c0                 test al, al
// 0051a0c1  7506                 jne 0x51a0c9
// 0051a0c3  8d4c240c             lea ecx, [esp + 0xc]
// 0051a0c7  eb11                 jmp 0x51a0da
// 0051a0c9  8b0e                 mov ecx, dword ptr [esi]
// 0051a0cb  8b4618               mov eax, dword ptr [esi + 0x18]
// 0051a0ce  894c2414             mov dword ptr [esp + 0x14], ecx
// 0051a0d2  89442418             mov dword ptr [esp + 0x18], eax
// 0051a0d6  8d4c2414             lea ecx, [esp + 0x14]
// 0051a0da  8b11                 mov edx, dword ptr [ecx]
// 0051a0dc  8b442420             mov eax, dword ptr [esp + 0x20]
// 0051a0e0  8b4904               mov ecx, dword ptr [ecx + 4]
// 0051a0e3  5f                   pop edi
// 0051a0e4  5e                   pop esi
// 0051a0e5  8910                 mov dword ptr [eax], edx
// 0051a0e7  894804               mov dword ptr [eax + 4], ecx
// 0051a0ea  5b                   pop ebx
// 0051a0eb  83c410               add esp, 0x10
// 0051a0ee  c20800               ret 8
// copied from an identical function in another client (function ?fn_ROCX000010_004e8720@S@ns_ROCX000010@@QAE?AUIterator@2@ABUKey@2@@Z)

namespace ns_ROCX000010 {
extern "C" void (__cdecl* const invalid_parameter_noinfo)();

struct Key
{
    int padding[3];
    int value;
    bool operator<(const Key& other) const;
};

inline bool Key::operator<(const Key& other) const
{
    if (this + 1 < &other + 1)
        return true;
    if (this + 1 > &other + 1)
        return false;
    if (value < other.value)
        return true;
    if (value > other.value)
        return false;
    return this < &other;
}

struct Node
{
    int padding[3];
    Key key;
};

struct S;

struct Iterator
{
    void* owner;
    Node* node;
    Iterator(Node* n, const S* container);
    bool operator!=(const Iterator& other) const;
};

struct S
{
    void* owner;
    int padding[5];
    Node* head;

    Node* find(const Key& key);
    Iterator end() const;
    Iterator fn_ROCX000010_004e8720(const Key& key);
};

inline Iterator::Iterator(Node* n, const S* container)
{
    node = n;
    if (!container)
        invalid_parameter_noinfo();
    owner = container->owner;
}

inline bool Iterator::operator!=(const Iterator& other) const
{
    if (!owner || owner != other.owner)
        invalid_parameter_noinfo();
    return node != other.node;
}

inline Iterator S::end() const
{
    return Iterator(head, this);
}

Iterator S::fn_ROCX000010_004e8720(const Key& key)
{
    Iterator result(find(key), this);
    return result != end() && !(key < result.node->key) ? result : end();
}
}
