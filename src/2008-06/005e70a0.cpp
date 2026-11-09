// from server: 100% by Espeon
#include <intrin.h>
// roc 2008-06 005e70a0  unit: RBX::Clump  size: 476 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e70a0
//
// 005e70a0  6aff                 push -1
// 005e70a2  6876687d00           push 0x7d6876
// 005e70a7  64a100000000         mov eax, dword ptr fs:[0]
// 005e70ad  50                   push eax
// 005e70ae  64892500000000       mov dword ptr fs:[0], esp
// 005e70b5  83ec0c               sub esp, 0xc
// 005e70b8  56                   push esi
// 005e70b9  8bf1                 mov esi, ecx
// 005e70bb  57                   push edi
// 005e70bc  89742410             mov dword ptr [esp + 0x10], esi
// 005e70c0  c706acf78300         mov dword ptr [esi], 0x83f7ac
// 005e70c6  8b461c               mov eax, dword ptr [esi + 0x1c]
// 005e70c9  50                   push eax
// 005e70ca  c744242001000000     mov dword ptr [esp + 0x20], 1
// 005e70d2  e819efffff           call 0x5e5ff0
// 005e70d7  c6461401             mov byte ptr [esi + 0x14], 1
// 005e70db  c6465401             mov byte ptr [esi + 0x54], 1
// 005e70df  c6466901             mov byte ptr [esi + 0x69], 1
// 005e70e3  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 005e70e6  33ff                 xor edi, edi
// 005e70e8  3bcf                 cmp ecx, edi
// 005e70ea  7405                 je 0x5e70f1
// 005e70ec  e8aff1ffff           call 0x5e62a0
// 005e70f1  8b4638               mov eax, dword ptr [esi + 0x38]
// 005e70f4  2b4634               sub eax, dword ptr [esi + 0x34]
// 005e70f7  a9fcffffff           test eax, 0xfffffffc
// 005e70fc  0f84dc000000         je 0x5e71de
// 005e7102  53                   push ebx
// 005e7103  55                   push ebp
// 005e7104  8b6e38               mov ebp, dword ptr [esi + 0x38]
// 005e7107  396e34               cmp dword ptr [esi + 0x34], ebp
// 005e710a  7606                 jbe 0x5e7112
// 005e710c  ff1590288000         call dword ptr [0x802890]
// 005e7112  8b7e28               mov edi, dword ptr [esi + 0x28]
// 005e7115  8bdf                 mov ebx, edi
// 005e7117  896c2414             mov dword ptr [esp + 0x14], ebp
// 005e711b  85ff                 test edi, edi
// 005e711d  7518                 jne 0x5e7137
// 005e711f  ff1590288000         call dword ptr [0x802890]
// 005e7125  33c0                 xor eax, eax
// 005e7127  8d4dfc               lea ecx, [ebp - 4]
// 005e712a  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 005e712d  7713                 ja 0x5e7142
// 005e712f  85ff                 test edi, edi
// 005e7131  7408                 je 0x5e713b
// 005e7133  8b3f                 mov edi, dword ptr [edi]
// 005e7135  eb06                 jmp 0x5e713d
// 005e7137  8b07                 mov eax, dword ptr [edi]
// 005e7139  ebec                 jmp 0x5e7127
// 005e713b  33ff                 xor edi, edi
// 005e713d  3b4f0c               cmp ecx, dword ptr [edi + 0xc]
// 005e7140  7306                 jae 0x5e7148
// 005e7142  ff1590288000         call dword ptr [0x802890]
// 005e7148  8d7dfc               lea edi, [ebp - 4]
// 005e714b  85db                 test ebx, ebx
// 005e714d  0f8522010000         jne 0x5e7275
// 005e7153  ff1590288000         call dword ptr [0x802890]
// 005e7159  33c0                 xor eax, eax
// 005e715b  3b7810               cmp edi, dword ptr [eax + 0x10]
// 005e715e  7206                 jb 0x5e7166
// 005e7160  ff1590288000         call dword ptr [0x802890]
// 005e7166  8b3f                 mov edi, dword ptr [edi]
// 005e7168  8b4720               mov eax, dword ptr [edi + 0x20]
// 005e716b  85c0                 test eax, eax
// 005e716d  7459                 je 0x5e71c8
// 005e716f  8d4c2410             lea ecx, [esp + 0x10]
// 005e7173  51                   push ecx
// 005e7174  83c028               add eax, 0x28
// 005e7177  50                   push eax
// 005e7178  897c2418             mov dword ptr [esp + 0x18], edi
// 005e717c  e87fe0ffff           call 0x5e5200
// 005e7181  8b4720               mov eax, dword ptr [edi + 0x20]
// 005e7184  c6401401             mov byte ptr [eax + 0x14], 1
// 005e7188  c6405401             mov byte ptr [eax + 0x54], 1
// 005e718c  c6406901             mov byte ptr [eax + 0x69], 1
// 005e7190  8b4020               mov eax, dword ptr [eax + 0x20]
// 005e7193  83c408               add esp, 8
// 005e7196  85c0                 test eax, eax
// 005e7198  7407                 je 0x5e71a1
// 005e719a  8bc8                 mov ecx, eax
// 005e719c  e8fff0ffff           call 0x5e62a0
// 005e71a1  57                   push edi
// 005e71a2  8bcf                 mov ecx, edi
// 005e71a4  c7472000000000       mov dword ptr [edi + 0x20], 0
// 005e71ab  e890f0ffff           call 0x5e6240
// 005e71b0  c6471401             mov byte ptr [edi + 0x14], 1
// 005e71b4  c6475401             mov byte ptr [edi + 0x54], 1
// 005e71b8  c6476901             mov byte ptr [edi + 0x69], 1
// 005e71bc  8b4f20               mov ecx, dword ptr [edi + 0x20]
// 005e71bf  85c9                 test ecx, ecx
// 005e71c1  7405                 je 0x5e71c8
// 005e71c3  e8d8f0ffff           call 0x5e62a0
// 005e71c8  8b5638               mov edx, dword ptr [esi + 0x38]
// 005e71cb  2b5634               sub edx, dword ptr [esi + 0x34]
// 005e71ce  f7c2fcffffff         test edx, 0xfffffffc
// 005e71d4  0f852affffff         jne 0x5e7104
// 005e71da  5d                   pop ebp
// 005e71db  33ff                 xor edi, edi
// 005e71dd  5b                   pop ebx
// 005e71de  8b4620               mov eax, dword ptr [esi + 0x20]
// 005e71e1  3bc7                 cmp eax, edi
// 005e71e3  7440                 je 0x5e7225
// 005e71e5  8d4c2408             lea ecx, [esp + 8]
// 005e71e9  51                   push ecx
// 005e71ea  83c028               add eax, 0x28
// 005e71ed  50                   push eax
// 005e71ee  89742410             mov dword ptr [esp + 0x10], esi
// 005e71f2  e809e0ffff           call 0x5e5200
// 005e71f7  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 005e71fa  83c408               add esp, 8
// 005e71fd  e89ef0ffff           call 0x5e62a0
// 005e7202  56                   push esi
// 005e7203  8bce                 mov ecx, esi
// 005e7205  897e20               mov dword ptr [esi + 0x20], edi
// 005e7208  e833f0ffff           call 0x5e6240
// 005e720d  c6461401             mov byte ptr [esi + 0x14], 1
// 005e7211  c6465401             mov byte ptr [esi + 0x54], 1
// 005e7215  c6466901             mov byte ptr [esi + 0x69], 1
// 005e7219  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 005e721c  3bcf                 cmp ecx, edi
// 005e721e  7405                 je 0x5e7225
// 005e7220  e87bf0ffff           call 0x5e62a0
// 005e7225  8b4634               mov eax, dword ptr [esi + 0x34]
// 005e7228  3bc7                 cmp eax, edi
// 005e722a  7409                 je 0x5e7235
// 005e722c  50                   push eax
// 005e722d  e848940b00           call 0x6a067a
// 005e7232  83c404               add esp, 4
// 005e7235  8b4628               mov eax, dword ptr [esi + 0x28]
// 005e7238  50                   push eax
// 005e7239  897e34               mov dword ptr [esi + 0x34], edi
// 005e723c  897e38               mov dword ptr [esi + 0x38], edi
// 005e723f  897e3c               mov dword ptr [esi + 0x3c], edi
// 005e7242  e833940b00           call 0x6a067a
// 005e7247  8b5608               mov edx, dword ptr [esi + 8]
// 005e724a  52                   push edx
// 005e724b  c7442424ffffffff     mov dword ptr [esp + 0x24], 0xffffffff
// 005e7253  e8c80af2ff           call 0x507d20
// 005e7258  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005e725c  83c408               add esp, 8
// 005e725f  897e08               mov dword ptr [esi + 8], edi
// 005e7262  897e0c               mov dword ptr [esi + 0xc], edi
// 005e7265  897e10               mov dword ptr [esi + 0x10], edi
// 005e7268  5f                   pop edi
// 005e7269  5e                   pop esi
// 005e726a  64890d00000000       mov dword ptr fs:[0], ecx
// 005e7271  83c418               add esp, 0x18
// 005e7274  c3                   ret 
// 005e7275  8b03                 mov eax, dword ptr [ebx]
// 005e7277  e9dffeffff           jmp 0x5e715b

template<class T> inline T roc_val(T v) { return v; }
#include <vector>

void alignedFree(void* p);

struct Buffer {
    int tag;
    void* data;
    void* end;
    void* capacity;
    ~Buffer() { alignedFree(data); data = 0; end = 0; capacity = 0; }
};

class Clump;

template<class T> void fastRemove(std::vector<T>& v, const T& item);



class Clump {
public:
    Buffer buffer;
    bool dirty14;
    char pad15[7];
    int id;
    Clump* parent;
    int x24;
    std::vector<Clump*> children;
    char pad40[0x14];
    bool dirty54;
    char pad55[0x14];
    bool dirty69;

    virtual ~Clump();
    void setDirty() {
        dirty14 = true;
        dirty54 = true;
        dirty69 = true;
        if (parent)
            parent->setDirty();
    }
    void setDirtyOrdered() {
        dirty14 = true;
        dirty54 = true;
        dirty69 = true;
        _ReadWriteBarrier();
        if (parent)
            parent->setDirtyOrdered();
    }
    void onAncestorChanged(Clump* root);
    void removeClumpId(int id);
    void setParent(Clump* p) {
        if (p != parent) {
            if (parent) {
                fastRemove(parent->children, this);
                parent->setDirty();
            }
            parent = p;
            if (p) {
                p->children.push_back(this);
                p->setDirty();
            }
            onAncestorChanged(this);
            setDirtyOrdered();
        }
    }
};

Clump::~Clump()
{
    removeClumpId(roc_val(id));
    setDirtyOrdered();
    while (children.size() != 0)
        children.back()->setParent(0);
    setParent(0);
}
