// from server: 100% by EspClaude
// from server: 92% by colin
// roc 2008-06 005db560  unit: RBX::Humanoid  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005db560
//
// 005db560  8b442404             mov eax, dword ptr [esp + 4]
// 005db564  56                   push esi
// 005db565  57                   push edi
// 005db566  50                   push eax
// 005db567  8bf1                 mov esi, ecx
// 005db569  e852f7f7ff           call 0x55acc0
// 005db56e  56                   push esi
// 005db56f  e81c7efcff           call 0x5a3390
// 005db574  8b8e1c020000         mov ecx, dword ptr [esi + 0x21c]
// 005db57a  8bf8                 mov edi, eax
// 005db57c  83c404               add esp, 4
// 005db57f  3bf9                 cmp edi, ecx
// 005db581  7469                 je 0x5db5ec
// 005db583  85c9                 test ecx, ecx
// 005db585  7413                 je 0x5db59a
// 005db587  8d8630010000         lea eax, [esi + 0x130]
// 005db58d  50                   push eax
// 005db58e  e8bddb0000           call 0x5e9150
// 005db593  8bc8                 mov ecx, eax
// 005db595  e8e6f70100           call 0x5fad80
// 005db59a  89be1c020000         mov dword ptr [esi + 0x21c], edi
// 005db5a0  85ff                 test edi, edi
// 005db5a2  7448                 je 0x5db5ec
// 005db5a4  56                   push esi
// 005db5a5  e8d67c0600           call 0x643280
// 005db5aa  8b8e20020000         mov ecx, dword ptr [esi + 0x220]
// 005db5b0  8bf8                 mov edi, eax
// 005db5b2  83c404               add esp, 4
// 005db5b5  3bf9                 cmp edi, ecx
// 005db5b7  740d                 je 0x5db5c6
// 005db5b9  85c9                 test ecx, ecx
// 005db5bb  7409                 je 0x5db5c6
// 005db5bd  8b11                 mov edx, dword ptr [ecx]
// 005db5bf  8b4218               mov eax, dword ptr [edx + 0x18]
// 005db5c2  6a01                 push 1
// 005db5c4  ffd0                 call eax
// 005db5c6  8d8630010000         lea eax, [esi + 0x130]
// 005db5cc  89be20020000         mov dword ptr [esi + 0x220], edi
// 005db5d2  8b8e1c020000         mov ecx, dword ptr [esi + 0x21c]
// 005db5d8  50                   push eax
// 005db5d9  e872db0000           call 0x5e9150
// 005db5de  8bc8                 mov ecx, eax
// 005db5e0  e86bf70100           call 0x5fad50
// 005db5e5  8bce                 mov ecx, esi
// 005db5e7  e8d4feffff           call 0x5db4c0
// 005db5ec  5f                   pop edi
// 005db5ed  5e                   pop esi
// 005db5ee  c20400               ret 4

// from server: 91% by king_originala
// roc 2008-06 005db560  unit: RBX::Humanoid  size: 145 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005db560
//
// 005db560  8b442404             mov eax, dword ptr [esp + 4]
// 005db564  56                   push esi
// 005db565  57                   push edi
// 005db566  50                   push eax
// 005db567  8bf1                 mov esi, ecx
// 005db569  e852f7f7ff           call 0x55acc0
// 005db56e  56                   push esi
// 005db56f  e81c7efcff           call 0x5a3390
// 005db574  8b8e1c020000         mov ecx, dword ptr [esi + 0x21c]
// 005db57a  8bf8                 mov edi, eax
// 005db57c  83c404               add esp, 4
// 005db57f  3bf9                 cmp edi, ecx
// 005db581  7469                 je 0x5db5ec
// 005db583  85c9                 test ecx, ecx
// 005db585  7413                 je 0x5db59a
// 005db587  8d8630010000         lea eax, [esi + 0x130]
// 005db58d  50                   push eax
// 005db58e  e8bddb0000           call 0x5e9150
// 005db593  8bc8                 mov ecx, eax
// 005db595  e8e6f70100           call 0x5fad80
// 005db59a  89be1c020000         mov dword ptr [esi + 0x21c], edi
// 005db5a0  85ff                 test edi, edi
// 005db5a2  7448                 je 0x5db5ec
// 005db5a4  56                   push esi
// 005db5a5  e8d67c0600           call 0x643280
// 005db5aa  8b8e20020000         mov ecx, dword ptr [esi + 0x220]
// 005db5b0  8bf8                 mov edi, eax
// 005db5b2  83c404               add esp, 4
// 005db5b5  3bf9                 cmp edi, ecx
// 005db5b7  740d                 je 0x5db5c6
// 005db5b9  85c9                 test ecx, ecx
// 005db5bb  7409                 je 0x5db5c6
// 005db5bd  8b11                 mov edx, dword ptr [ecx]
// 005db5bf  8b4218               mov eax, dword ptr [edx + 0x18]
// 005db5c2  6a01                 push 1
// 005db5c4  ffd0                 call eax
// 005db5c6  8d8630010000         lea eax, [esi + 0x130]
// 005db5cc  89be20020000         mov dword ptr [esi + 0x220], edi
// 005db5d2  8b8e1c020000         mov ecx, dword ptr [esi + 0x21c]
// 005db5d8  50                   push eax
// 005db5d9  e872db0000           call 0x5e9150
// 005db5de  8bc8                 mov ecx, eax
// 005db5e0  e86bf70100           call 0x5fad50
// 005db5e5  8bce                 mov ecx, esi
// 005db5e7  e8d4feffff           call 0x5db4c0
// 005db5ec  5f                   pop edi
// 005db5ed  5e                   pop esi
// 005db5ee  c20400               ret 4
#include <intrin.h>
#include <memory>

struct Link {
    void connect();
    void disconnect();
};

struct Node {
    Link* getLink(void*);
};

struct Resource {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual ~Resource();
};

struct PadBase { char padding[0x130]; };
struct SignalBase { char signal[0xEC]; };
struct Humanoid : PadBase, SignalBase {
    Node* node;
    std::auto_ptr<Resource> resource;

    void baseUpdate(void*);
    void refresh();
    void update(void*);
};

Node* __cdecl findNode(Humanoid*);
Resource* __cdecl findResource(Humanoid*);

void Humanoid::update(void* argument)
{
    baseUpdate(argument);

    Node* nextNode = findNode(this);
    if (nextNode != node) {
        if (node)
            node->getLink(static_cast<SignalBase*>(this))->disconnect();

        node = nextNode;
        if (nextNode) {
            resource.reset(findResource(this));
            node->getLink(static_cast<SignalBase*>(this))->connect();
            refresh();
        }
    }
}
