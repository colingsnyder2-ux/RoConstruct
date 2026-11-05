// from server: 100% by Yeetserama
// roc 2010-06 0052fa70  unit: RBX::PartChunk  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0052fa70
//
// 0052fa70  83ec10               sub esp, 0x10
// 0052fa73  53                   push ebx
// 0052fa74  56                   push esi
// 0052fa75  57                   push edi
// 0052fa76  8b7c2424             mov edi, dword ptr [esp + 0x24]
// 0052fa7a  57                   push edi
// 0052fa7b  8bf1                 mov esi, ecx
// 0052fa7d  e84ed5ffff           call 0x52cfd0
// 0052fa82  8bd8                 mov ebx, eax
// 0052fa84  895c2410             mov dword ptr [esp + 0x10], ebx
// 0052fa88  85f6                 test esi, esi
// 0052fa8a  7506                 jne 0x52fa92
// 0052fa8c  ff150ca99e00         call dword ptr [0x9ea90c]
// 0052fa92  8b06                 mov eax, dword ptr [esi]
// 0052fa94  55                   push ebp
// 0052fa95  8b6e18               mov ebp, dword ptr [esi + 0x18]
// 0052fa98  89442410             mov dword ptr [esp + 0x10], eax
// 0052fa9c  85c0                 test eax, eax
// 0052fa9e  7404                 je 0x52faa4
// 0052faa0  3bc0                 cmp eax, eax
// 0052faa2  7406                 je 0x52faaa
// 0052faa4  ff150ca99e00         call dword ptr [0x9ea90c]
// 0052faaa  3bdd                 cmp ebx, ebp
// 0052faac  5d                   pop ebp
// 0052faad  742a                 je 0x52fad9
// 0052faaf  8d430c               lea eax, [ebx + 0xc]
// 0052fab2  8d4810               lea ecx, [eax + 0x10]
// 0052fab5  8d5710               lea edx, [edi + 0x10]
// 0052fab8  3bd1                 cmp edx, ecx
// 0052faba  721d                 jb 0x52fad9
// 0052fabc  7715                 ja 0x52fad3
// 0052fabe  8b4f0c               mov ecx, dword ptr [edi + 0xc]
// 0052fac1  8b500c               mov edx, dword ptr [eax + 0xc]
// 0052fac4  3bca                 cmp ecx, edx
// 0052fac6  7c11                 jl 0x52fad9
// 0052fac8  7f09                 jg 0x52fad3
// 0052faca  3bf8                 cmp edi, eax
// 0052facc  0f92c0               setb al
// 0052facf  84c0                 test al, al
// 0052fad1  7506                 jne 0x52fad9
// 0052fad3  8d4c240c             lea ecx, [esp + 0xc]
// 0052fad7  eb11                 jmp 0x52faea
// 0052fad9  8b0e                 mov ecx, dword ptr [esi]
// 0052fadb  8b4618               mov eax, dword ptr [esi + 0x18]
// 0052fade  894c2414             mov dword ptr [esp + 0x14], ecx
// 0052fae2  89442418             mov dword ptr [esp + 0x18], eax
// 0052fae6  8d4c2414             lea ecx, [esp + 0x14]
// 0052faea  8b11                 mov edx, dword ptr [ecx]
// 0052faec  8b442420             mov eax, dword ptr [esp + 0x20]
// 0052faf0  8b4904               mov ecx, dword ptr [ecx + 4]
// 0052faf3  5f                   pop edi
// 0052faf4  5e                   pop esi
// 0052faf5  8910                 mov dword ptr [eax], edx
// 0052faf7  894804               mov dword ptr [eax + 4], ecx
// 0052fafa  5b                   pop ebx
// 0052fafb  83c410               add esp, 0x10
// 0052fafe  c20800               ret 8
// copied from an identical function in another client (function ?fn_ROCX00000c_004e8720@S@ns_ROCX00000c@@QAE?AUIterator@2@ABUKey@2@@Z)

namespace ns_ROCX00000c {
// from server: 100% by king_originala
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
    Iterator fn_ROCX00000c_004e8720(const Key& key);
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

Iterator S::fn_ROCX00000c_004e8720(const Key& key)
{
    Iterator result(find(key), this);
    return result != end() && !(key < result.node->key) ? result : end();
}
}
