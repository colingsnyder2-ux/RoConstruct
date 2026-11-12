// from server: 100% by EspClaude
// from server: 68% by Intel
// roc 2007-08 004f5b90  unit: boost::bad_lexical_cast  size: 91 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004f5b90
//
// 004f5b90  6aff                 push -1
// 004f5b92  681edd7400           push 0x74dd1e
// 004f5b97  64a100000000         mov eax, dword ptr fs:[0]
// 004f5b9d  50                   push eax
// 004f5b9e  51                   push ecx
// 004f5b9f  a188518b00           mov eax, dword ptr [0x8b5188]
// 004f5ba4  33c4                 xor eax, esp
// 004f5ba6  50                   push eax
// 004f5ba7  8d442408             lea eax, [esp + 8]
// 004f5bab  64a300000000         mov dword ptr fs:[0], eax
// 004f5bb1  8bc1                 mov eax, ecx
// 004f5bb3  33c9                 xor ecx, ecx
// 004f5bb5  894804               mov dword ptr [eax + 4], ecx
// 004f5bb8  894808               mov dword ptr [eax + 8], ecx
// 004f5bbb  8908                 mov dword ptr [eax], ecx
// 004f5bbd  894810               mov dword ptr [eax + 0x10], ecx
// 004f5bc0  894814               mov dword ptr [eax + 0x14], ecx
// 004f5bc3  89480c               mov dword ptr [eax + 0xc], ecx
// 004f5bc6  89481c               mov dword ptr [eax + 0x1c], ecx
// 004f5bc9  894820               mov dword ptr [eax + 0x20], ecx
// 004f5bcc  894818               mov dword ptr [eax + 0x18], ecx
// 004f5bcf  894828               mov dword ptr [eax + 0x28], ecx
// 004f5bd2  89482c               mov dword ptr [eax + 0x2c], ecx
// 004f5bd5  894824               mov dword ptr [eax + 0x24], ecx
// 004f5bd8  894830               mov dword ptr [eax + 0x30], ecx
// 004f5bdb  8b4c2408             mov ecx, dword ptr [esp + 8]
// 004f5bdf  64890d00000000       mov dword ptr fs:[0], ecx
// 004f5be6  59                   pop ecx
// 004f5be7  83c410               add esp, 0x10

// The target reserves one 4-byte local (push ecx) inside an EH frame whose
// state is never advanced: an inlined temporary whose dtor folded away.
void release(void *p);

struct Ptr {
    void *p;
    Ptr() : p(0) {}
    ~Ptr() { if (p) release(p); }
};

struct Slot {
    void *head;
    int a;
    int b;
    Slot() : a(0), b(0) { head = 0; }
};

struct bad_lexical_cast {
    Slot s0;
    Slot s1;
    Slot s2;
    Slot s3;
    Ptr last;
    bad_lexical_cast();
};

bad_lexical_cast::bad_lexical_cast()
{
    last.p = Ptr().p;
}
