// from server: 100% by EspClaude
// from server: 68% by colin
// roc 2008-06 0046ae30  unit: VCWorkspace::?$CComObject  size: 349 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046ae30
// 0046ae30  6aff                 push -1
// 0046ae32  6812397c00           push 0x7c3912
// 0046ae37  64a100000000         mov eax, dword ptr fs:[0]
// 0046ae3d  50                   push eax
// 0046ae3e  64892500000000       mov dword ptr fs:[0], esp
// 0046ae45  83ec28               sub esp, 0x28
// 0046ae48  53                   push ebx
// 0046ae49  55                   push ebp
// 0046ae4a  56                   push esi
// 0046ae4b  57                   push edi
// 0046ae4c  8bf9                 mov edi, ecx
// 0046ae4e  8bb708010000         mov esi, dword ptr [edi + 0x108]
// 0046ae54  c744244000000000     mov dword ptr [esp + 0x40], 0
// 0046ae5c  85f6                 test esi, esi
// 0046ae5e  0f8400010000         je 0x46af64
// 0046ae64  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0046ae67  895c2410             mov dword ptr [esp + 0x10], ebx
// 0046ae6b  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0046ae6e  7606                 jbe 0x46ae76
// 0046ae70  ff1590288000         call dword ptr [0x802890]
// 0046ae76  8b06                 mov eax, dword ptr [esi]
// 0046ae78  8bb708010000         mov esi, dword ptr [edi + 0x108]
// 0046ae7e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0046ae81  89442414             mov dword ptr [esp + 0x14], eax
// 0046ae85  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0046ae88  7606                 jbe 0x46ae90
// 0046ae8a  ff1590288000         call dword ptr [0x802890]
// 0046ae90  8b36                 mov esi, dword ptr [esi]
// 0046ae92  8b2d44248000         mov ebp, dword ptr [0x802444]
// 0046ae98  85f6                 test esi, esi
// 0046ae9a  7406                 je 0x46aea2
// 0046ae9c  3b742414             cmp esi, dword ptr [esp + 0x14]
// 0046aea0  7406                 je 0x46aea8
// 0046aea2  ff1590288000         call dword ptr [0x802890]
// 0046aea8  3bfb                 cmp edi, ebx
// 0046aeaa  0f84b4000000         je 0x46af64
// 0046aeb0  85f6                 test esi, esi
// 0046aeb2  7564                 jne 0x46af18
// 0046aeb4  ff1590288000         call dword ptr [0x802890]
// 0046aeba  33c0                 xor eax, eax
// 0046aebc  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0046aebf  7206                 jb 0x46aec7
// 0046aec1  ff1590288000         call dword ptr [0x802890]
// 0046aec7  8b0f                 mov ecx, dword ptr [edi]
// 0046aec9  8d54241c             lea edx, [esp + 0x1c]
// 0046aecd  52                   push edx
// 0046aece  e8dd43fbff           call 0x41f2b0
// 0046aed3  8d4c2448             lea ecx, [esp + 0x48]
// 0046aed7  51                   push ecx
// 0046aed8  50                   push eax
// 0046aed9  c644244801           mov byte ptr [esp + 0x48], 1
// 0046aede  ffd5                 call ebp
// 0046aee0  83c408               add esp, 8
// 0046aee3  8d4c241c             lea ecx, [esp + 0x1c]
// 0046aee7  8ad8                 mov bl, al
// 0046aee9  c644244000           mov byte ptr [esp + 0x40], 0
// 0046aeee  ff1568248000         call dword ptr [0x802468]
// 0046aef4  84db                 test bl, bl
// 0046aef6  7528                 jne 0x46af20
// 0046aef8  85f6                 test esi, esi
// 0046aefa  7520                 jne 0x46af1c
// 0046aefc  ff1590288000         call dword ptr [0x802890]
// 0046af02  33c0                 xor eax, eax
// 0046af04  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0046af07  7206                 jb 0x46af0f
// 0046af09  ff1590288000         call dword ptr [0x802890]
// 0046af0f  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0046af13  83c708               add edi, 8
// 0046af16  eb80                 jmp 0x46ae98
// 0046af18  8b06                 mov eax, dword ptr [esi]
// 0046af1a  eba0                 jmp 0x46aebc
// 0046af1c  8b06                 mov eax, dword ptr [esi]
// 0046af1e  ebe4                 jmp 0x46af04
// 0046af20  85f6                 test esi, esi
// 0046af22  753c                 jne 0x46af60
// 0046af24  ff1590288000         call dword ptr [0x802890]
// 0046af2a  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0046af2d  7206                 jb 0x46af35
// 0046af2f  ff1590288000         call dword ptr [0x802890]
// 0046af35  8b3f                 mov edi, dword ptr [edi]
// 0046af37  8d4c2448             lea ecx, [esp + 0x48]
// 0046af3b  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 0046af43  ff1568248000         call dword ptr [0x802468]
// 0046af49  8bc7                 mov eax, edi
// 0046af4b  5f                   pop edi
// 0046af4c  5e                   pop esi
// 0046af4d  5d                   pop ebp
// 0046af4e  5b                   pop ebx
// 0046af4f  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 0046af53  64890d00000000       mov dword ptr fs:[0], ecx
// 0046af5a  83c434               add esp, 0x34
// 0046af5d  c21c00               ret 0x1c
// 0046af60  8b36                 mov esi, dword ptr [esi]
// 0046af62  ebc6                 jmp 0x46af2a
// 0046af64  8d4c2448             lea ecx, [esp + 0x48]
// 0046af68  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 0046af70  ff1568248000         call dword ptr [0x802468]
// 0046af76  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 0046af7a  5f                   pop edi
// 0046af7b  5e                   pop esi
// 0046af7c  5d                   pop ebp
// 0046af7d  33c0                 xor eax, eax
// 0046af7f  5b                   pop ebx
// 0046af80  64890d00000000       mov dword ptr fs:[0], ecx
// 0046af87  83c434               add esp, 0x34
// 0046af8a  c21c00               ret 0x1c
// from server: 64% by king_originala
// roc 2008-06 0046ae30  unit: VCWorkspace::?$CComObject  size: 349 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0046ae30
// 0046ae30  6aff                 push -1
// 0046ae32  6812397c00           push 0x7c3912
// 0046ae37  64a100000000         mov eax, dword ptr fs:[0]
// 0046ae3d  50                   push eax
// 0046ae3e  64892500000000       mov dword ptr fs:[0], esp
// 0046ae45  83ec28               sub esp, 0x28
// 0046ae48  53                   push ebx
// 0046ae49  55                   push ebp
// 0046ae4a  56                   push esi
// 0046ae4b  57                   push edi
// 0046ae4c  8bf9                 mov edi, ecx
// 0046ae4e  8bb708010000         mov esi, dword ptr [edi + 0x108]
// 0046ae54  c744244000000000     mov dword ptr [esp + 0x40], 0
// 0046ae5c  85f6                 test esi, esi
// 0046ae5e  0f8400010000         je 0x46af64
// 0046ae64  8b5e10               mov ebx, dword ptr [esi + 0x10]
// 0046ae67  895c2410             mov dword ptr [esp + 0x10], ebx
// 0046ae6b  395e0c               cmp dword ptr [esi + 0xc], ebx
// 0046ae6e  7606                 jbe 0x46ae76
// 0046ae70  ff1590288000         call dword ptr [0x802890]
// 0046ae76  8b06                 mov eax, dword ptr [esi]
// 0046ae78  8bb708010000         mov esi, dword ptr [edi + 0x108]
// 0046ae7e  8b7e0c               mov edi, dword ptr [esi + 0xc]
// 0046ae81  89442414             mov dword ptr [esp + 0x14], eax
// 0046ae85  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0046ae88  7606                 jbe 0x46ae90
// 0046ae8a  ff1590288000         call dword ptr [0x802890]
// 0046ae90  8b36                 mov esi, dword ptr [esi]
// 0046ae92  8b2d44248000         mov ebp, dword ptr [0x802444]
// 0046ae98  85f6                 test esi, esi
// 0046ae9a  7406                 je 0x46aea2
// 0046ae9c  3b742414             cmp esi, dword ptr [esp + 0x14]
// 0046aea0  7406                 je 0x46aea8
// 0046aea2  ff1590288000         call dword ptr [0x802890]
// 0046aea8  3bfb                 cmp edi, ebx
// 0046aeaa  0f84b4000000         je 0x46af64
// 0046aeb0  85f6                 test esi, esi
// 0046aeb2  7564                 jne 0x46af18
// 0046aeb4  ff1590288000         call dword ptr [0x802890]
// 0046aeba  33c0                 xor eax, eax
// 0046aebc  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0046aebf  7206                 jb 0x46aec7
// 0046aec1  ff1590288000         call dword ptr [0x802890]
// 0046aec7  8b0f                 mov ecx, dword ptr [edi]
// 0046aec9  8d54241c             lea edx, [esp + 0x1c]
// 0046aecd  52                   push edx
// 0046aece  e8dd43fbff           call 0x41f2b0
// 0046aed3  8d4c2448             lea ecx, [esp + 0x48]
// 0046aed7  51                   push ecx
// 0046aed8  50                   push eax
// 0046aed9  c644244801           mov byte ptr [esp + 0x48], 1
// 0046aede  ffd5                 call ebp
// 0046aee0  83c408               add esp, 8
// 0046aee3  8d4c241c             lea ecx, [esp + 0x1c]
// 0046aee7  8ad8                 mov bl, al
// 0046aee9  c644244000           mov byte ptr [esp + 0x40], 0
// 0046aeee  ff1568248000         call dword ptr [0x802468]
// 0046aef4  84db                 test bl, bl
// 0046aef6  7528                 jne 0x46af20
// 0046aef8  85f6                 test esi, esi
// 0046aefa  7520                 jne 0x46af1c
// 0046aefc  ff1590288000         call dword ptr [0x802890]
// 0046af02  33c0                 xor eax, eax
// 0046af04  3b7810               cmp edi, dword ptr [eax + 0x10]
// 0046af07  7206                 jb 0x46af0f
// 0046af09  ff1590288000         call dword ptr [0x802890]
// 0046af0f  8b5c2410             mov ebx, dword ptr [esp + 0x10]
// 0046af13  83c708               add edi, 8
// 0046af16  eb80                 jmp 0x46ae98
// 0046af18  8b06                 mov eax, dword ptr [esi]
// 0046af1a  eba0                 jmp 0x46aebc
// 0046af1c  8b06                 mov eax, dword ptr [esi]
// 0046af1e  ebe4                 jmp 0x46af04
// 0046af20  85f6                 test esi, esi
// 0046af22  753c                 jne 0x46af60
// 0046af24  ff1590288000         call dword ptr [0x802890]
// 0046af2a  3b7e10               cmp edi, dword ptr [esi + 0x10]
// 0046af2d  7206                 jb 0x46af35
// 0046af2f  ff1590288000         call dword ptr [0x802890]
// 0046af35  8b3f                 mov edi, dword ptr [edi]
// 0046af37  8d4c2448             lea ecx, [esp + 0x48]
// 0046af3b  c7442440ffffffff     mov dword ptr [esp + 0x40], 0xffffffff
// 0046af43  ff1568248000         call dword ptr [0x802468]
// 0046af49  8bc7                 mov eax, edi
// 0046af4b  5f                   pop edi
// 0046af4c  5e                   pop esi
// 0046af4d  5d                   pop ebp
// 0046af4e  5b                   pop ebx
#include <string>
#include <vector>

struct Item {
    std::string getText();
};

template <class T> struct Ptr {
    T *px;
    void *pn;
    T *operator->() const { return px; }
    T *get() const { return px; }
};

typedef std::vector<Ptr<Item> > Items;

struct S {
    char reserved[264];
    Items *items;
    Item *find(std::string text);
};

Item *S::find(std::string text)
{
    if (items) {
        Items::const_iterator end = items->end();
        for (Items::const_iterator it = items->begin(); it != end; ++it) {
            if ((*it)->getText() == text)
                return it->get();
        }
    }
    return 0;
}
