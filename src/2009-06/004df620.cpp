// from server: 100% by EspClaude
// roc 2009-06 004df620  unit: RBX::Network::IdSerializer  size: 299 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004df620
//
// 004df620  6aff                 push -1
// 004df622  6878b98500           push 0x85b978
// 004df627  64a100000000         mov eax, dword ptr fs:[0]
// 004df62d  50                   push eax
// 004df62e  64892500000000       mov dword ptr fs:[0], esp
// 004df635  83ec18               sub esp, 0x18
// 004df638  53                   push ebx
// 004df639  55                   push ebp
// 004df63a  56                   push esi
// 004df63b  57                   push edi
// 004df63c  8bf9                 mov edi, ecx
// 004df63e  8d442413             lea eax, [esp + 0x13]
// 004df642  50                   push eax
// 004df643  8d4c2417             lea ecx, [esp + 0x17]
// 004df647  51                   push ecx
// 004df648  8bcf                 mov ecx, edi
// 004df64a  897c2424             mov dword ptr [esp + 0x24], edi
// 004df64e  e88d8c1100           call 0x5f82e0
// 004df653  68f0ec4d00           push 0x4decf0
// 004df658  6820f1a300           push 0xa3f120
// 004df65d  c744243800000000     mov dword ptr [esp + 0x38], 0
// 004df665  e8a620f2ff           call 0x401710
// 004df66a  83c408               add esp, 8
// 004df66d  e81ef6ffff           call 0x4dec90
// 004df672  8bf0                 mov esi, eax
// 004df674  8b5e0c               mov ebx, dword ptr [esi + 0xc]
// 004df677  3b5e10               cmp ebx, dword ptr [esi + 0x10]
// 004df67a  7606                 jbe 0x4df682
// 004df67c  ff15ace98900         call dword ptr [0x89e9ac]
// 004df682  8b2e                 mov ebp, dword ptr [esi]
// 004df684  68f0ec4d00           push 0x4decf0
// 004df689  6820f1a300           push 0xa3f120
// 004df68e  e87d20f2ff           call 0x401710
// 004df693  83c408               add esp, 8
// 004df696  e8f5f5ffff           call 0x4dec90
// 004df69b  8bf0                 mov esi, eax
// 004df69d  8b4610               mov eax, dword ptr [esi + 0x10]
// 004df6a0  89442414             mov dword ptr [esp + 0x14], eax
// 004df6a4  39460c               cmp dword ptr [esi + 0xc], eax
// 004df6a7  7606                 jbe 0x4df6af
// 004df6a9  ff15ace98900         call dword ptr [0x89e9ac]
// 004df6af  8b16                 mov edx, dword ptr [esi]
// 004df6b1  89542420             mov dword ptr [esp + 0x20], edx
// 004df6b5  85ed                 test ebp, ebp
// 004df6b7  7406                 je 0x4df6bf
// 004df6b9  3b6c2420             cmp ebp, dword ptr [esp + 0x20]
// 004df6bd  740a                 je 0x4df6c9
// 004df6bf  8b35ace98900         mov esi, dword ptr [0x89e9ac]
// 004df6c5  ffd6                 call esi
// 004df6c7  eb06                 jmp 0x4df6cf
// 004df6c9  8b35ace98900         mov esi, dword ptr [0x89e9ac]
// 004df6cf  3b5c2414             cmp ebx, dword ptr [esp + 0x14]
// 004df6d3  7461                 je 0x4df736
// 004df6d5  85ed                 test ebp, ebp
// 004df6d7  7553                 jne 0x4df72c
// 004df6d9  ffd6                 call esi
// 004df6db  33c0                 xor eax, eax
// 004df6dd  3b5810               cmp ebx, dword ptr [eax + 0x10]
// 004df6e0  7202                 jb 0x4df6e4
// 004df6e2  ffd6                 call esi
// 004df6e4  8b03                 mov eax, dword ptr [ebx]
// 004df6e6  8b771c               mov esi, dword ptr [edi + 0x1c]
// 004df6e9  8d4c2418             lea ecx, [esp + 0x18]
// 004df6ed  51                   push ecx
// 004df6ee  8bcf                 mov ecx, edi
// 004df6f0  8944241c             mov dword ptr [esp + 0x1c], eax
// 004df6f4  e8d79d1b00           call 0x6994d0
// 004df6f9  8930                 mov dword ptr [eax], esi
// 004df6fb  8b471c               mov eax, dword ptr [edi + 0x1c]
// 004df6fe  83c9ff               or ecx, 0xffffffff
// 004df701  85c0                 test eax, eax
// 004df703  7607                 jbe 0x4df70c
// 004df705  d1e8                 shr eax, 1
// 004df707  41                   inc ecx
// 004df708  85c0                 test eax, eax
// 004df70a  77f9                 ja 0x4df705
// 004df70c  41                   inc ecx
// 004df70d  894f20               mov dword ptr [edi + 0x20], ecx
// 004df710  85ed                 test ebp, ebp
// 004df712  751d                 jne 0x4df731
// 004df714  ff15ace98900         call dword ptr [0x89e9ac]
// 004df71a  33c0                 xor eax, eax
// 004df71c  3b5810               cmp ebx, dword ptr [eax + 0x10]
// 004df71f  7206                 jb 0x4df727
// 004df721  ff15ace98900         call dword ptr [0x89e9ac]
// 004df727  83c304               add ebx, 4
// 004df72a  eb89                 jmp 0x4df6b5
// 004df72c  8b4500               mov eax, dword ptr [ebp]
// 004df72f  ebac                 jmp 0x4df6dd
// 004df731  8b4500               mov eax, dword ptr [ebp]
// 004df734  ebe6                 jmp 0x4df71c
// 004df736  8b4c2428             mov ecx, dword ptr [esp + 0x28]
// 004df73a  8bc7                 mov eax, edi
// 004df73c  5f                   pop edi
// 004df73d  5e                   pop esi
// 004df73e  5d                   pop ebp
// 004df73f  5b                   pop ebx
// 004df740  64890d00000000       mov dword ptr fs:[0], ecx
// 004df747  83c424               add esp, 0x24
// 004df74a  c3                   ret 
// copied from an identical function in another client (function ??0S@@QAE@XZ)

#include <vector>
extern "C" void (__cdecl * const invalid_parameter_noinfo)();

struct Empty {
    Empty();
};

struct Empty2 {
    Empty2();
};

inline Empty::Empty() {}
inline Empty2::Empty2() {}

typedef std::vector<unsigned> Vector;
typedef Vector::iterator Iterator;
extern Vector* __cdecl getValues();
extern void __cdecl ensureInitialized(void (__cdecl*)(), unsigned*);
extern void __cdecl initializeRegistry();
extern unsigned registryGuard;

struct Base {
    unsigned storage[7];
    unsigned count;
    unsigned bits;
struct BothEmpty : Empty, Empty2 { BothEmpty() {} };


    Base(const Empty&, const Empty2&);
    ~Base();
    unsigned* lookup(const unsigned*);
};

struct S : Base {
    S();
};

S::S() : Base(BothEmpty(), BothEmpty())
{
    ensureInitialized(initializeRegistry, &registryGuard);
    Iterator current = getValues()->begin();
    ensureInitialized(initializeRegistry, &registryGuard);
    Iterator end = getValues()->end();
    for (; !(current == end); ++current) {
        unsigned key = *current;
        unsigned value = count;
        *lookup(&key) = value;

        unsigned n = count;
        unsigned result = ~0u;
        while (n > 0) {
            n >>= 1;
            ++result;
        }
        bits = result + 1;
    }
}