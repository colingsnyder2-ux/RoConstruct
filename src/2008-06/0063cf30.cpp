// from server: 100% by user
// from server: 99% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_spawnowner_b54ccf3f5948c4a4.cpp

// Candidate translation unit (score above; library headers required).
#include <boost/shared_ptr.hpp>
// from server: 96% by king_originala
// roc 2008-06 0063cf30  unit: RBX::P8SpawnLocation::?$GetSetImpl  size: 415 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0063cf30
//
// 0063cf30  6aff                 push -1
// 0063cf32  6818a77d00           push 0x7da718
// 0063cf37  64a100000000         mov eax, dword ptr fs:[0]
// 0063cf3d  50                   push eax
// 0063cf3e  64892500000000       mov dword ptr fs:[0], esp
// 0063cf45  83ec50               sub esp, 0x50
// 0063cf48  53                   push ebx
// 0063cf49  55                   push ebp
// 0063cf4a  56                   push esi
// 0063cf4b  57                   push edi
// 0063cf4c  8bf9                 mov edi, ecx
// 0063cf4e  33db                 xor ebx, ebx
// 0063cf50  895c2468             mov dword ptr [esp + 0x68], ebx
// 0063cf54  e8b7b4ecff           call 0x508410
// 0063cf59  dca710040000         fsub qword ptr [edi + 0x410]
// 0063cf5f  dc1d908b8200         fcomp qword ptr [0x828b90]
// 0063cf65  dfe0                 fnstsw ax
// 0063cf67  f6c441               test ah, 0x41
// 0063cf6a  0f8510010000         jne 0x63d080
// 0063cf70  399f18040000         cmp dword ptr [edi + 0x418], ebx
// 0063cf76  0f8504010000         jne 0x63d080
// 0063cf7c  8b442470             mov eax, dword ptr [esp + 0x70]
// 0063cf80  8b8004010000         mov eax, dword ptr [eax + 0x104]
// 0063cf86  3bc3                 cmp eax, ebx
// 0063cf88  0f84f2000000         je 0x63d080
// 0063cf8e  50                   push eax
// 0063cf8f  e88ccaf9ff           call 0x5d9a20
// 0063cf94  8bf0                 mov esi, eax
// 0063cf96  83c404               add esp, 4
// 0063cf99  3bf3                 cmp esi, ebx
// 0063cf9b  0f84df000000         je 0x63d080
// 0063cfa1  8bce                 mov ecx, esi
// 0063cfa3  e868bbf9ff           call 0x5d8b10
// 0063cfa8  85c0                 test eax, eax
// 0063cfaa  0f84d0000000         je 0x63d080
// 0063cfb0  8a86e8010000         mov al, byte ptr [esi + 0x1e8]
// 0063cfb6  a80a                 test al, 0xa
// 0063cfb8  0f85c2000000         jne 0x63d080
// 0063cfbe  8bce                 mov ecx, esi
// 0063cfc0  e84bbbf9ff           call 0x5d8b10
// 0063cfc5  50                   push eax
// 0063cfc6  e80564f6ff           call 0x5a33d0
// 0063cfcb  83c404               add esp, 4
// 0063cfce  84c0                 test al, al
// 0063cfd0  0f84aa000000         je 0x63d080
// 0063cfd6  57                   push edi
// 0063cfd7  e8f463f6ff           call 0x5a33d0
// 0063cfdc  83c404               add esp, 4
// 0063cfdf  84c0                 test al, al
// 0063cfe1  0f8499000000         je 0x63d080
// 0063cfe7  8daffc030000         lea ebp, [edi + 0x3fc]
// 0063cfed  8bcd                 mov ecx, ebp
// 0063cfef  e83c82f5ff           call 0x595230
// 0063cff4  56                   push esi
// 0063cff5  8bcf                 mov ecx, edi
// 0063cff7  e8a4f8ffff           call 0x63c8a0
// 0063cffc  6a01                 push 1
// 0063cffe  8bce                 mov ecx, esi
// 0063d000  e8abf2f9ff           call 0x5dc2b0
// 0063d005  0fb60584d59700       movzx eax, byte ptr [0x97d584]
// 0063d00c  50                   push eax
// 0063d00d  57                   push edi
// 0063d00e  83ec0c               sub esp, 0xc
// 0063d011  8bc4                 mov eax, esp
// 0063d013  b910c86300           mov ecx, 0x63c810
// 0063d018  8908                 mov dword ptr [eax], ecx
// 0063d01a  33d2                 xor edx, edx
// 0063d01c  8d4c2434             lea ecx, [esp + 0x34]
// 0063d020  895004               mov dword ptr [eax + 4], edx
// 0063d023  51                   push ecx
// 0063d024  895808               mov dword ptr [eax + 8], ebx
// 0063d027  e844f8ffff           call 0x63c870
// 0063d02c  83c418               add esp, 0x18
// 0063d02f  50                   push eax
// 0063d030  8d4c243c             lea ecx, [esp + 0x3c]
// 0063d034  e857fdffff           call 0x63cd90
// 0063d039  6a0a                 push 0xa
// 0063d03b  8d54243c             lea edx, [esp + 0x3c]
// 0063d03f  52                   push edx
// 0063d040  83c614               add esi, 0x14
// 0063d043  56                   push esi
// 0063d044  8d44241c             lea eax, [esp + 0x1c]
// 0063d048  50                   push eax
// 0063d049  b958a59700           mov ecx, 0x97a558
// 0063d04e  c644247801           mov byte ptr [esp + 0x78], 1
// 0063d053  e838b3e9ff           call 0x4d8390
// 0063d058  50                   push eax
// 0063d059  8bcd                 mov ecx, ebp
// 0063d05b  c644246c02           mov byte ptr [esp + 0x6c], 2
// 0063d060  e8db84f5ff           call 0x595540
// 0063d065  8d4c2410             lea ecx, [esp + 0x10]
// 0063d069  c644246801           mov byte ptr [esp + 0x68], 1
// 0063d06e  e8fd82f5ff           call 0x595370
// 0063d073  8d4c2438             lea ecx, [esp + 0x38]
// 0063d077  885c2468             mov byte ptr [esp + 0x68], bl
// 0063d07b  e89026e6ff           call 0x49f710
// 0063d080  8b742474             mov esi, dword ptr [esp + 0x74]
// 0063d084  c7442468ffffffff     mov dword ptr [esp + 0x68], 0xffffffff
// 0063d08c  3bf3                 cmp esi, ebx
// 0063d08e  742a                 je 0x63d0ba
// 0063d090  8d4e04               lea ecx, [esi + 4]
// 0063d093  83caff               or edx, 0xffffffff
// 0063d096  f00fc111             lock xadd dword ptr [ecx], edx
// 0063d09a  751e                 jne 0x63d0ba
// 0063d09c  8b06                 mov eax, dword ptr [esi]
// 0063d09e  8b5004               mov edx, dword ptr [eax + 4]
// 0063d0a1  8bce                 mov ecx, esi
// 0063d0a3  ffd2                 call edx
// 0063d0a5  8d4608               lea eax, [esi + 8]
// 0063d0a8  83c9ff               or ecx, 0xffffffff
// 0063d0ab  f00fc108             lock xadd dword ptr [eax], ecx
// 0063d0af  7509                 jne 0x63d0ba
// 0063d0b1  8b16                 mov edx, dword ptr [esi]
// 0063d0b3  8b4208               mov eax, dword ptr [edx + 8]
// 0063d0b6  8bce                 mov ecx, esi
// 0063d0b8  ffd0                 call eax
// 0063d0ba  8b4c2460             mov ecx, dword ptr [esp + 0x60]
// 0063d0be  5f                   pop edi
// 0063d0bf  5e                   pop esi
// 0063d0c0  5d                   pop ebp
// 0063d0c1  64890d00000000       mov dword ptr fs:[0], ecx
// 0063d0c8  5b                   pop ebx
// 0063d0c9  83c45c               add esp, 0x5c
// 0063d0cc  c20800               ret 8

extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Reference {
    virtual void unused() = 0;
    virtual void dispose() = 0;
    virtual void destroy() = 0;
    volatile long strong;
    volatile long weak;
};

struct Object {
    char padding[0x104];
    void* owner;
};

typedef boost::shared_ptr<Object> SharedObject;

struct Character {
    char padding[0x1e8];
    unsigned char flags;
    void* getObject();
    void setEnabled(bool);
};

struct Connection {
    char storage[16];
    ~Connection();
};

struct Signal {
    char storage[20];
    void clear();
    void assign(const Connection&);
};

struct Spawn;

struct MemberPointer {
    void (__cdecl *function)(Spawn*);
    int adjustment;
    int extra;
};

struct BoundFunction {
    char storage[24];
};

struct Function {
    char storage[40];
    Function(const BoundFunction&);
    ~Function();
};

struct Dispatcher {
    Connection connect(void*, const Function&, int);
};

extern double threshold;
extern unsigned char option;
extern Dispatcher dispatcher;

extern double __cdecl currentTime();
extern Character* __cdecl findCharacter(void*);
extern bool __cdecl isValid(void*);
extern void __cdecl callback(Spawn*);
extern BoundFunction* __cdecl bindFunction(
    BoundFunction*, MemberPointer, Spawn*, unsigned char);

struct Spawn {
    char padding[0x3fc];
    Signal signal;
    double lastTime;
    int blocked;
    void apply(Character*);
    void process(SharedObject);
};

void Spawn::process(SharedObject object)
{
    if (currentTime() - lastTime > threshold && !blocked) {
        void* owner = object->owner;
        if (owner) {
            Character* character = findCharacter(owner);
            if (character && character->getObject() &&
                !(character->flags & 2) &&
                !(character->flags & 8) &&
                isValid(character->getObject()) && isValid(this)) {
                signal.clear();
                apply(character);
                character->setEnabled(true);

                BoundFunction bound;
                MemberPointer member = { callback, 0, 0 };
                Function function(*bindFunction(&bound, member, this, option));
                signal.assign(dispatcher.connect(
                    reinterpret_cast<char*>(character) + 0x14,
                    function, 10));
            }
        }
    }
}
