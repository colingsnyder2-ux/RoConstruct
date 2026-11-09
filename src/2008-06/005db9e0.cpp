// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_listenerclasstypesb23cf820a44cdb4c.cpp

// Candidate translation unit (score above; library headers required).
// from server: 88% by king_originala
// roc 2008-06 005db9e0  unit: RBX::Humanoid  size: 238 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005db9e0
//
// 005db9e0  51                   push ecx
// 005db9e1  55                   push ebp
// 005db9e2  56                   push esi
// 005db9e3  8db1b4feffff         lea esi, [ecx - 0x14c]
// 005db9e9  85f6                 test esi, esi
// 005db9eb  7433                 je 0x5dba20
// 005db9ed  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 005db9f3  6a00                 push 0
// 005db9f5  68402a9300           push 0x932a40
// 005db9fa  687c909200           push 0x92907c
// 005db9ff  6a00                 push 0
// 005dba01  50                   push eax
// 005dba02  e8bf5d0c00           call 0x6a17c6
// 005dba07  83c414               add esp, 0x14
// 005dba0a  85c0                 test eax, eax
// 005dba0c  7412                 je 0x5dba20
// 005dba0e  8b542410             mov edx, dword ptr [esp + 0x10]
// 005dba12  b9109d5d00           mov ecx, 0x5d9d10
// 005dba17  52                   push edx
// 005dba18  51                   push ecx
// 005dba19  8bc8                 mov ecx, eax
// 005dba1b  e820cbffff           call 0x5d8540
// 005dba20  56                   push esi
// 005dba21  e80af8ffff           call 0x5db230
// 005dba26  8be8                 mov ebp, eax
// 005dba28  83c404               add esp, 4
// 005dba2b  85ed                 test ebp, ebp
// 005dba2d  0f8495000000         je 0x5dbac8
// 005dba33  57                   push edi
// 005dba34  8bbd48010000         mov edi, dword ptr [ebp + 0x148]
// 005dba3a  3bbd4c010000         cmp edi, dword ptr [ebp + 0x14c]
// 005dba40  7606                 jbe 0x5dba48
// 005dba42  ff1590288000         call dword ptr [0x802890]
// 005dba48  8bb53c010000         mov esi, dword ptr [ebp + 0x13c]
// 005dba4e  53                   push ebx
// 005dba4f  90                   nop 
// 005dba50  8b9d4c010000         mov ebx, dword ptr [ebp + 0x14c]
// 005dba56  399d48010000         cmp dword ptr [ebp + 0x148], ebx
// 005dba5c  7606                 jbe 0x5dba64
// 005dba5e  ff1590288000         call dword ptr [0x802890]
// 005dba64  8b853c010000         mov eax, dword ptr [ebp + 0x13c]
// 005dba6a  85f6                 test esi, esi
// 005dba6c  7404                 je 0x5dba72
// 005dba6e  3bf0                 cmp esi, eax
// 005dba70  7406                 je 0x5dba78
// 005dba72  ff1590288000         call dword ptr [0x802890]
// 005dba78  3bfb                 cmp edi, ebx
// 005dba7a  744a                 je 0x5dbac6
// 005dba7c  8b1d90288000         mov ebx, dword ptr [0x802890]
// 005dba82  85f6                 test esi, esi
// 005dba84  7538                 jne 0x5dbabe
// 005dba86  ffd3                 call ebx
// 005dba88  33c0                 xor eax, eax
// 005dba8a  3b7810               cmp edi, dword ptr [eax + 0x10]
// 005dba8d  7202                 jb 0x5dba91
// 005dba8f  ffd3                 call ebx
// 005dba91  8b07                 mov eax, dword ptr [edi]
// 005dba93  8d4c2410             lea ecx, [esp + 0x10]
// 005dba97  0528020000           add eax, 0x228
// 005dba9c  51                   push ecx
// 005dba9d  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 005dbaa1  89442414             mov dword ptr [esp + 0x14], eax
// 005dbaa5  e8f658e4ff           call 0x4213a0
// 005dbaaa  85f6                 test esi, esi
// 005dbaac  7514                 jne 0x5dbac2
// 005dbaae  ffd3                 call ebx
// 005dbab0  33c0                 xor eax, eax
// 005dbab2  3b7810               cmp edi, dword ptr [eax + 0x10]
// 005dbab5  7202                 jb 0x5dbab9
// 005dbab7  ffd3                 call ebx
// 005dbab9  83c704               add edi, 4
// 005dbabc  eb92                 jmp 0x5dba50
// 005dbabe  8b06                 mov eax, dword ptr [esi]
// 005dbac0  ebc8                 jmp 0x5dba8a
// 005dbac2  8b06                 mov eax, dword ptr [esi]
// 005dbac4  ebec                 jmp 0x5dbab2
// 005dbac6  5b                   pop ebx
// 005dbac7  5f                   pop edi
// 005dbac8  5e                   pop esi
// 005dbac9  5d                   pop ebp
// 005dbaca  59                   pop ecx
// 005dbacb  c20400               ret 4



struct Signal {};

struct Listener {
    void notify(Signal*const&);
};

struct Node {
    char padding[0x228];
    Signal signal;
};

#include <vector>
typedef std::vector<Node*> Vector;
struct VisitAction{void(*callback)();Listener*listener;};
namespace RBX {
    class Instance {public:
        virtual ~Instance();
        char padding[0x100];
        Instance* next;
    };

    class ModelInstance : public Instance {public:
        void visit(VisitAction);
    };

    struct ServiceProvider : Instance {
        char padding2[0x34];
        Vector children;
    };
}

RBX::ServiceProvider* __cdecl func_005db230(RBX::Instance*);
void __cdecl callback_005d9d10();

struct S {
    void f(Listener*);
};

void S::f(Listener* listener) {
    RBX::Instance* instance =
        reinterpret_cast<RBX::Instance*>(reinterpret_cast<char*>(this) - 0x14c);

    if (instance) {
        RBX::ModelInstance* model =
            dynamic_cast<RBX::ModelInstance*>(instance->next);
        if (model)
            {VisitAction action={callback_005d9d10,listener};model->visit(action);}
    }

    RBX::ServiceProvider* provider = func_005db230(instance);
    if (provider) {
        Vector&children=provider->children;
        for(Vector::iterator current=children.begin();current!=children.end();++current){
            listener->notify(reinterpret_cast<Signal*>(reinterpret_cast<char*>(*current)+0x228));
        }
    }
}
