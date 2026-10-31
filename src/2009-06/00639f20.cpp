// from server: 99% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005aeea0  unit: RBX::ScriptContext  size: 246 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005aeea0
//
// 005aeea0  6aff                 push -1
// 005aeea2  6868917d00           push 0x7d9168
// 005aeea7  64a100000000         mov eax, dword ptr fs:[0]
// 005aeead  50                   push eax
// 005aeeae  64892500000000       mov dword ptr fs:[0], esp
// 005aeeb5  83ec0c               sub esp, 0xc
// 005aeeb8  56                   push esi
// 005aeeb9  57                   push edi
// 005aeeba  685c8c8100           push 0x818c5c
// 005aeebf  6a01                 push 1
// 005aeec1  e89a48eeff           call 0x493760
// 005aeec6  8bc8                 mov ecx, eax
// 005aeec8  e843a9edff           call 0x489810
// 005aeecd  8b742424             mov esi, dword ptr [esp + 0x24]
// 005aeed1  6a43                 push 0x43
// 005aeed3  56                   push esi
// 005aeed4  e837350600           call 0x612410
// 005aeed9  68eed8ffff           push 0xffffd8ee
// 005aeede  56                   push esi
// 005aeedf  e87c350600           call 0x612460
// 005aeee4  6aff                 push -1
// 005aeee6  56                   push esi
// 005aeee7  e834320600           call 0x612120
// 005aeeec  6afe                 push -2
// 005aeeee  56                   push esi
// 005aeeef  8bf8                 mov edi, eax
// 005aeef1  e82a2d0600           call 0x611c20
// 005aeef6  57                   push edi
// 005aeef7  e8d4fdffff           call 0x5aecd0
// 005aeefc  50                   push eax
// 005aeefd  8d442434             lea eax, [esp + 0x34]
// 005aef01  50                   push eax
// 005aef02  e8399b0600           call 0x618a40
// 005aef07  8b08                 mov ecx, dword ptr [eax]
// 005aef09  83c424               add esp, 0x24
// 005aef0c  c744242400000000     mov dword ptr [esp + 0x24], 0
// 005aef14  89642410             mov dword ptr [esp + 0x10], esp
// 005aef18  8bd4                 mov edx, esp
// 005aef1a  85c9                 test ecx, ecx
// 005aef1c  7405                 je 0x5aef23
// 005aef1e  83c114               add ecx, 0x14
// 005aef21  eb02                 jmp 0x5aef25
// 005aef23  33c9                 xor ecx, ecx
// 005aef25  890a                 mov dword ptr [edx], ecx
// 005aef27  8b4004               mov eax, dword ptr [eax + 4]
// 005aef2a  894204               mov dword ptr [edx + 4], eax
// 005aef2d  85c0                 test eax, eax
// 005aef2f  740c                 je 0x5aef3d
// 005aef31  83c004               add eax, 4
// 005aef34  b901000000           mov ecx, 1
// 005aef39  f00fc108             lock xadd dword ptr [eax], ecx
// 005aef3d  56                   push esi
// 005aef3e  e8edb7ffff           call 0x5aa730
// 005aef43  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 005aef47  83c40c               add esp, 0xc
// 005aef4a  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 005aef52  85f6                 test esi, esi
// 005aef54  742a                 je 0x5aef80
// 005aef56  8d5604               lea edx, [esi + 4]
// 005aef59  83c8ff               or eax, 0xffffffff
// 005aef5c  f00fc102             lock xadd dword ptr [edx], eax
// 005aef60  751e                 jne 0x5aef80
// 005aef62  8b16                 mov edx, dword ptr [esi]
// 005aef64  8b4204               mov eax, dword ptr [edx + 4]
// 005aef67  8bce                 mov ecx, esi
// 005aef69  ffd0                 call eax
// 005aef6b  8d4e08               lea ecx, [esi + 8]
// 005aef6e  83caff               or edx, 0xffffffff
// 005aef71  f00fc111             lock xadd dword ptr [ecx], edx
// 005aef75  7509                 jne 0x5aef80
// 005aef77  8b06                 mov eax, dword ptr [esi]
// 005aef79  8b5008               mov edx, dword ptr [eax + 8]
// 005aef7c  8bce                 mov ecx, esi
// 005aef7e  ffd2                 call edx
// 005aef80  8b4c2414             mov ecx, dword ptr [esp + 0x14]
// 005aef84  5f                   pop edi
// 005aef85  b801000000           mov eax, 1
// 005aef8a  64890d00000000       mov dword ptr fs:[0], ecx
// 005aef91  5e                   pop esi
// 005aef92  83c418               add esp, 0x18
// 005aef95  c3                   ret 

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
extern "C" long __cdecl _InterlockedDecrement(volatile long*);
#pragma intrinsic(_InterlockedIncrement)
#pragma intrinsic(_InterlockedDecrement)

struct Count {
    virtual ~Count();
    virtual void dispose();
    virtual void destroy();
    volatile long strong;
    volatile long weak;
};

struct Prefix { char storage[20]; };
struct Context { int storage; };
struct Source : Prefix, Context {};

template<class T> struct Shared {
    T* pointer;
    Count* count;

    template<class U> Shared(const Shared<U>& other);
    ~Shared();
};

template<class T>
template<class U>
__forceinline Shared<T>::Shared(const Shared<U>& other)
    : pointer(other.pointer), count(other.count)
{
    if (count)
        _InterlockedIncrement(&count->strong);
}

template<class T>
__forceinline Shared<T>::~Shared()
{
    Count* c = count;
    if (c && _InterlockedDecrement(&c->strong) == 0) {
        c->dispose();
        if (_InterlockedDecrement(&c->weak) == 0)
            c->destroy();
    }
}

struct Channel {
    void activate();
};

namespace RBX {
    class Instance;
    class ServiceProvider;
}

extern Channel* __stdcall findChannel(int, const char*);
extern void __cdecl prepare(void*, int);
extern void __cdecl selectValue(void*, int);
extern RBX::Instance* __cdecl readInstance(void*, int);
extern void __cdecl removeValue(void*, int);
extern RBX::ServiceProvider* __cdecl func_005aecd0(RBX::Instance*);
extern Shared<Source> __cdecl obtainContext(RBX::ServiceProvider*);
extern void __cdecl publishContext(void*, Shared<Context>);

int __cdecl reconstructed(void* state)
{
    findChannel(1, "Stats")->activate();
    prepare(state, 67);
    selectValue(state, -10002);
    RBX::Instance* instance = readInstance(state, -1);
    removeValue(state, -2);
    publishContext(state, obtainContext(func_005aecd0(instance)));
    return 1;
}
