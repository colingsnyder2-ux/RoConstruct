// from server: 100% by EspClaude
// from server: 100% by EspClaude
// roc 2008-06 0064c6b0  unit: RBX::SleepStage  size: 410 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064c6b0
//
// 0064c6b0  6aff                 push -1
// 0064c6b2  6818b17d00           push 0x7db118
// 0064c6b7  64a100000000         mov eax, dword ptr fs:[0]
// 0064c6bd  50                   push eax
// 0064c6be  64892500000000       mov dword ptr fs:[0], esp
// 0064c6c5  83ec2c               sub esp, 0x2c
// 0064c6c8  53                   push ebx
// 0064c6c9  55                   push ebp
// 0064c6ca  56                   push esi
// 0064c6cb  57                   push edi
// 0064c6cc  8bf1                 mov esi, ecx
// 0064c6ce  6a04                 push 4
// 0064c6d0  89742414             mov dword ptr [esp + 0x14], esi
// 0064c6d4  e847420500           call 0x6a0920
// 0064c6d9  33c9                 xor ecx, ecx
// 0064c6db  83c404               add esp, 4
// 0064c6de  3bc1                 cmp eax, ecx
// 0064c6e0  7408                 je 0x64c6ea
// 0064c6e2  8d54241c             lea edx, [esp + 0x1c]
// 0064c6e6  8910                 mov dword ptr [eax], edx
// 0064c6e8  eb02                 jmp 0x64c6ec
// 0064c6ea  33c0                 xor eax, eax
// 0064c6ec  8944241c             mov dword ptr [esp + 0x1c], eax
// 0064c6f0  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0064c6f4  894c2430             mov dword ptr [esp + 0x30], ecx
// 0064c6f8  894c2434             mov dword ptr [esp + 0x34], ecx
// 0064c6fc  894c2438             mov dword ptr [esp + 0x38], ecx
// 0064c700  ff86d8010000         inc dword ptr [esi + 0x1d8]
// 0064c706  8b7c244c             mov edi, dword ptr [esp + 0x4c]
// 0064c70a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0064c70d  8b18                 mov ebx, dword ptr [eax]
// 0064c70f  8b37                 mov esi, dword ptr [edi]
// 0064c711  894c2444             mov dword ptr [esp + 0x44], ecx
// 0064c715  895c2418             mov dword ptr [esp + 0x18], ebx
// 0064c719  89742414             mov dword ptr [esp + 0x14], esi
// 0064c71d  8d4900               lea ecx, [ecx]
// 0064c720  8b6f18               mov ebp, dword ptr [edi + 0x18]
// 0064c723  8b07                 mov eax, dword ptr [edi]
// 0064c725  85f6                 test esi, esi
// 0064c727  7404                 je 0x64c72d
// 0064c729  3bf0                 cmp esi, eax
// 0064c72b  7406                 je 0x64c733
// 0064c72d  ff1590288000         call dword ptr [0x802890]
// 0064c733  3bdd                 cmp ebx, ebp
// 0064c735  7455                 je 0x64c78c
// 0064c737  85f6                 test esi, esi
// 0064c739  754d                 jne 0x64c788
// 0064c73b  ff1590288000         call dword ptr [0x802890]
// 0064c741  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 0064c744  7506                 jne 0x64c74c
// 0064c746  ff1590288000         call dword ptr [0x802890]
// 0064c74c  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0064c74f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0064c753  8b91d8010000         mov edx, dword ptr [ecx + 0x1d8]
// 0064c759  895044               mov dword ptr [eax + 0x44], edx
// 0064c75c  8944244c             mov dword ptr [esp + 0x4c], eax
// 0064c760  c7404800000000       mov dword ptr [eax + 0x48], 0
// 0064c767  8d44244c             lea eax, [esp + 0x4c]
// 0064c76b  50                   push eax
// 0064c76c  8d4c2420             lea ecx, [esp + 0x20]
// 0064c770  e8bbcbf3ff           call 0x589330
// 0064c775  8d4c2414             lea ecx, [esp + 0x14]
// 0064c779  e8c2cbf9ff           call 0x5e9340
// 0064c77e  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0064c782  8b742414             mov esi, dword ptr [esp + 0x14]
// 0064c786  eb98                 jmp 0x64c720
// 0064c788  8b36                 mov esi, dword ptr [esi]
// 0064c78a  ebb5                 jmp 0x64c741
// 0064c78c  8b442438             mov eax, dword ptr [esp + 0x38]
// 0064c790  85c0                 test eax, eax
// 0064c792  0f847c000000         je 0x64c814
// 0064c798  8b5c2450             mov ebx, dword ptr [esp + 0x50]
// 0064c79c  83cdff               or ebp, 0xffffffff
// 0064c79f  90                   nop 
// 0064c7a0  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0064c7a4  8d1401               lea edx, [ecx + eax]
// 0064c7a7  8bf1                 mov esi, ecx
// 0064c7a9  3bca                 cmp ecx, edx
// 0064c7ab  7606                 jbe 0x64c7b3
// 0064c7ad  ff1590288000         call dword ptr [0x802890]
// 0064c7b3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0064c7b7  8d4c2414             lea ecx, [esp + 0x14]
// 0064c7bb  89442414             mov dword ptr [esp + 0x14], eax
// 0064c7bf  89742418             mov dword ptr [esp + 0x18], esi
// 0064c7c3  e8589cdeff           call 0x436420
// 0064c7c8  8b30                 mov esi, dword ptr [eax]
// 0064c7ca  33ff                 xor edi, edi
// 0064c7cc  397c2438             cmp dword ptr [esp + 0x38], edi
// 0064c7d0  7427                 je 0x64c7f9
// 0064c7d2  8b442434             mov eax, dword ptr [esp + 0x34]
// 0064c7d6  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0064c7da  40                   inc eax
// 0064c7db  8d148d00000000       lea edx, [ecx*4]
// 0064c7e2  89442434             mov dword ptr [esp + 0x34], eax
// 0064c7e6  3bd0                 cmp edx, eax
// 0064c7e8  7704                 ja 0x64c7ee
// 0064c7ea  897c2434             mov dword ptr [esp + 0x34], edi
// 0064c7ee  836c243801           sub dword ptr [esp + 0x38], 1
// 0064c7f3  7504                 jne 0x64c7f9
// 0064c7f5  897c2434             mov dword ptr [esp + 0x34], edi
// 0064c7f9  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0064c7fd  53                   push ebx
// 0064c7fe  8d442420             lea eax, [esp + 0x20]
// 0064c802  50                   push eax
// 0064c803  56                   push esi
// 0064c804  e867fcffff           call 0x64c470
// 0064c809  896e48               mov dword ptr [esi + 0x48], ebp
// 0064c80c  8b442438             mov eax, dword ptr [esp + 0x38]
// 0064c810  3bc7                 cmp eax, edi
// 0064c812  758c                 jne 0x64c7a0
// 0064c814  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0064c818  c681dc01000000       mov byte ptr [ecx + 0x1dc], 0
// 0064c81f  8d4c241c             lea ecx, [esp + 0x1c]
// 0064c823  e8e8310000           call 0x64fa10
// 0064c828  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0064c82c  52                   push edx
// 0064c82d  e8483e0500           call 0x6a067a
// 0064c832  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0064c836  83c404               add esp, 4
// 0064c839  5f                   pop edi
// 0064c83a  5e                   pop esi
// 0064c83b  5d                   pop ebp
// 0064c83c  5b                   pop ebx
// 0064c83d  64890d00000000       mov dword ptr fs:[0], ecx
// 0064c844  83c438               add esp, 0x38
// 0064c847  c20c00               ret 0xc

// from server: 72% by colin
// roc 2008-06 0064c6b0  unit: RBX::SleepStage  size: 410 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0064c6b0
// 0064c6b0  6aff                 push -1
// 0064c6b2  6818b17d00           push 0x7db118
// 0064c6b7  64a100000000         mov eax, dword ptr fs:[0]
// 0064c6bd  50                   push eax
// 0064c6be  64892500000000       mov dword ptr fs:[0], esp
// 0064c6c5  83ec2c               sub esp, 0x2c
// 0064c6c8  53                   push ebx
// 0064c6c9  55                   push ebp
// 0064c6ca  56                   push esi
// 0064c6cb  57                   push edi
// 0064c6cc  8bf1                 mov esi, ecx
// 0064c6ce  6a04                 push 4
// 0064c6d0  89742414             mov dword ptr [esp + 0x14], esi
// 0064c6d4  e847420500           call 0x6a0920
// 0064c6d9  33c9                 xor ecx, ecx
// 0064c6db  83c404               add esp, 4
// 0064c6de  3bc1                 cmp eax, ecx
// 0064c6e0  7408                 je 0x64c6ea
// 0064c6e2  8d54241c             lea edx, [esp + 0x1c]
// 0064c6e6  8910                 mov dword ptr [eax], edx
// 0064c6e8  eb02                 jmp 0x64c6ec
// 0064c6ea  33c0                 xor eax, eax
// 0064c6ec  8944241c             mov dword ptr [esp + 0x1c], eax
// 0064c6f0  894c242c             mov dword ptr [esp + 0x2c], ecx
// 0064c6f4  894c2430             mov dword ptr [esp + 0x30], ecx
// 0064c6f8  894c2434             mov dword ptr [esp + 0x34], ecx
// 0064c6fc  894c2438             mov dword ptr [esp + 0x38], ecx
// 0064c700  ff86d8010000         inc dword ptr [esi + 0x1d8]
// 0064c706  8b7c244c             mov edi, dword ptr [esp + 0x4c]
// 0064c70a  8b4718               mov eax, dword ptr [edi + 0x18]
// 0064c70d  8b18                 mov ebx, dword ptr [eax]
// 0064c70f  8b37                 mov esi, dword ptr [edi]
// 0064c711  894c2444             mov dword ptr [esp + 0x44], ecx
// 0064c715  895c2418             mov dword ptr [esp + 0x18], ebx
// 0064c719  89742414             mov dword ptr [esp + 0x14], esi
// 0064c71d  8d4900               lea ecx, [ecx]
// 0064c720  8b6f18               mov ebp, dword ptr [edi + 0x18]
// 0064c723  8b07                 mov eax, dword ptr [edi]
// 0064c725  85f6                 test esi, esi
// 0064c727  7404                 je 0x64c72d
// 0064c729  3bf0                 cmp esi, eax
// 0064c72b  7406                 je 0x64c733
// 0064c72d  ff1590288000         call dword ptr [0x802890]
// 0064c733  3bdd                 cmp ebx, ebp
// 0064c735  7455                 je 0x64c78c
// 0064c737  85f6                 test esi, esi
// 0064c739  754d                 jne 0x64c788
// 0064c73b  ff1590288000         call dword ptr [0x802890]
// 0064c741  3b5e18               cmp ebx, dword ptr [esi + 0x18]
// 0064c744  7506                 jne 0x64c74c
// 0064c746  ff1590288000         call dword ptr [0x802890]
// 0064c74c  8b430c               mov eax, dword ptr [ebx + 0xc]
// 0064c74f  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0064c753  8b91d8010000         mov edx, dword ptr [ecx + 0x1d8]
// 0064c759  895044               mov dword ptr [eax + 0x44], edx
// 0064c75c  8944244c             mov dword ptr [esp + 0x4c], eax
// 0064c760  c7404800000000       mov dword ptr [eax + 0x48], 0
// 0064c767  8d44244c             lea eax, [esp + 0x4c]
// 0064c76b  50                   push eax
// 0064c76c  8d4c2420             lea ecx, [esp + 0x20]
// 0064c770  e8bbcbf3ff           call 0x589330
// 0064c775  8d4c2414             lea ecx, [esp + 0x14]
// 0064c779  e8c2cbf9ff           call 0x5e9340
// 0064c77e  8b5c2418             mov ebx, dword ptr [esp + 0x18]
// 0064c782  8b742414             mov esi, dword ptr [esp + 0x14]
// 0064c786  eb98                 jmp 0x64c720
// 0064c788  8b36                 mov esi, dword ptr [esi]
// 0064c78a  ebb5                 jmp 0x64c741
// 0064c78c  8b442438             mov eax, dword ptr [esp + 0x38]
// 0064c790  85c0                 test eax, eax
// 0064c792  0f847c000000         je 0x64c814
// 0064c798  8b5c2450             mov ebx, dword ptr [esp + 0x50]
// 0064c79c  83cdff               or ebp, 0xffffffff
// 0064c79f  90                   nop 
// 0064c7a0  8b4c2434             mov ecx, dword ptr [esp + 0x34]
// 0064c7a4  8d1401               lea edx, [ecx + eax]
// 0064c7a7  8bf1                 mov esi, ecx
// 0064c7a9  3bca                 cmp ecx, edx
// 0064c7ab  7606                 jbe 0x64c7b3
// 0064c7ad  ff1590288000         call dword ptr [0x802890]
// 0064c7b3  8b44241c             mov eax, dword ptr [esp + 0x1c]
// 0064c7b7  8d4c2414             lea ecx, [esp + 0x14]
// 0064c7bb  89442414             mov dword ptr [esp + 0x14], eax
// 0064c7bf  89742418             mov dword ptr [esp + 0x18], esi
// 0064c7c3  e8589cdeff           call 0x436420
// 0064c7c8  8b30                 mov esi, dword ptr [eax]
// 0064c7ca  33ff                 xor edi, edi
// 0064c7cc  397c2438             cmp dword ptr [esp + 0x38], edi
// 0064c7d0  7427                 je 0x64c7f9
// 0064c7d2  8b442434             mov eax, dword ptr [esp + 0x34]
// 0064c7d6  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 0064c7da  40                   inc eax
// 0064c7db  8d148d00000000       lea edx, [ecx*4]
// 0064c7e2  89442434             mov dword ptr [esp + 0x34], eax
// 0064c7e6  3bd0                 cmp edx, eax
// 0064c7e8  7704                 ja 0x64c7ee
// 0064c7ea  897c2434             mov dword ptr [esp + 0x34], edi
// 0064c7ee  836c243801           sub dword ptr [esp + 0x38], 1
// 0064c7f3  7504                 jne 0x64c7f9
// 0064c7f5  897c2434             mov dword ptr [esp + 0x34], edi
// 0064c7f9  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0064c7fd  53                   push ebx
// 0064c7fe  8d442420             lea eax, [esp + 0x20]
// 0064c802  50                   push eax
// 0064c803  56                   push esi
// 0064c804  e867fcffff           call 0x64c470
// 0064c809  896e48               mov dword ptr [esi + 0x48], ebp
// 0064c80c  8b442438             mov eax, dword ptr [esp + 0x38]
// 0064c810  3bc7                 cmp eax, edi
// 0064c812  758c                 jne 0x64c7a0
// 0064c814  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0064c818  c681dc01000000       mov byte ptr [ecx + 0x1dc], 0
// 0064c81f  8d4c241c             lea ecx, [esp + 0x1c]
// 0064c823  e8e8310000           call 0x64fa10
// 0064c828  8b54241c             mov edx, dword ptr [esp + 0x1c]
// 0064c82c  52                   push edx
// 0064c82d  e8483e0500           call 0x6a067a
// 0064c832  8b4c2440             mov ecx, dword ptr [esp + 0x40]
// 0064c836  83c404               add esp, 4
// 0064c839  5f                   pop edi
// 0064c83a  5e                   pop esi
// 0064c83b  5d                   pop ebp
// 0064c83c  5b                   pop ebx
// 0064c83d  64890d00000000       mov dword ptr fs:[0], ecx
// 0064c844  83c438               add esp, 0x38
// 0064c847  c20c00               ret 0xc
#include <set>
#include <deque>

struct Body {
    char padding[96];
    int stamp;
    int state;
};

typedef std::set<Body*> BodySet;
typedef std::deque<Body*> BodyQueue;

struct Stage {
    char padding[496];
    int stamp;
    unsigned char active;

    void process(Body*, BodyQueue*, void*);
    void f(const BodySet&, void*, void*);
};

void Stage::f(const BodySet& tree, void* context, void*)
{
    BodyQueue queue;
    ++stamp;
    for (BodySet::const_iterator it = tree.begin(); it != tree.end(); ++it) {
        Body* body = *it;
        body->stamp = stamp;
        body->state = 0;
        queue.push_back(body);
    }
    while (!queue.empty()) {
        Body* body = queue.front();
        queue.pop_front();
        process(body, &queue, context);
        body->state = -1;
    }
    active = 0;
}
