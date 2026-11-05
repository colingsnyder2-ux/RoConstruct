// from server: 92% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0049df90  unit: RBX::Network::Players::Plugin  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0049df90
//
// 0049df90  55                   push ebp
// 0049df91  8bec                 mov ebp, esp
// 0049df93  6aff                 push -1
// 0049df95  68a0747c00           push 0x7c74a0
// 0049df9a  64a100000000         mov eax, dword ptr fs:[0]
// 0049dfa0  50                   push eax
// 0049dfa1  64892500000000       mov dword ptr fs:[0], esp
// 0049dfa8  51                   push ecx
// 0049dfa9  53                   push ebx
// 0049dfaa  56                   push esi
// 0049dfab  57                   push edi
// 0049dfac  8965f0               mov dword ptr [ebp - 0x10], esp
// 0049dfaf  8bf1                 mov esi, ecx
// 0049dfb1  6a10                 push 0x10
// 0049dfb3  c70600000000         mov dword ptr [esi], 0
// 0049dfb9  c745fc00000000       mov dword ptr [ebp - 4], 0
// 0049dfc0  e85b292000           call 0x6a0920
// 0049dfc5  83c404               add esp, 4
// 0049dfc8  85c0                 test eax, eax
// 0049dfca  7419                 je 0x49dfe5
// 0049dfcc  b901000000           mov ecx, 1
// 0049dfd1  894804               mov dword ptr [eax + 4], ecx
// 0049dfd4  894808               mov dword ptr [eax + 8], ecx
// 0049dfd7  8b4d08               mov ecx, dword ptr [ebp + 8]
// 0049dfda  c70060268200         mov dword ptr [eax], 0x822660
// 0049dfe0  89480c               mov dword ptr [eax + 0xc], ecx
// 0049dfe3  eb02                 jmp 0x49dfe7
// 0049dfe5  33c0                 xor eax, eax
// 0049dfe7  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 0049dfea  8906                 mov dword ptr [esi], eax
// 0049dfec  5f                   pop edi
// 0049dfed  8bc6                 mov eax, esi
// 0049dfef  5e                   pop esi
// 0049dff0  64890d00000000       mov dword ptr fs:[0], ecx
// 0049dff7  5b                   pop ebx
// 0049dff8  8be5                 mov esp, ebp
// 0049dffa  5d                   pop ebp
// 0049dffb  c20400               ret 4

void* __cdecl operator new(unsigned int);
void __cdecl operator delete(void*);

struct Object {
    virtual ~Object();
};

namespace boost { template<class T> void checked_delete(T*); }

struct CountBase {
    long useCount;
    long weakCount;

    CountBase() : useCount(1), weakCount(1) {}
    virtual ~CountBase();
    virtual void dispose() = 0;
    virtual void destroy();
    virtual void* getDeleter(const void*) = 0;
};

struct Count : CountBase {
    Object* object;

    explicit Count(Object* p) : object(p) {}
    virtual ~Count();
    virtual void dispose();
    virtual void* getDeleter(const void*);
};

struct S {
    CountBase* count;
    explicit S(Object*);
};

S::S(Object* p) : count(0)
{
    try {
        count = new Count(p);
    }
    catch (...) {
        boost::checked_delete(p);
        throw;
    }
}
