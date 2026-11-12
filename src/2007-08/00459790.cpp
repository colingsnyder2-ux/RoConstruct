// from server: 97% by EspClaude
// from server: 61% by colin
// roc 2007-08 00459790  unit: RBX::VInstance::?$NonFactoryProduct  size: 247 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00459790
//
// 00459790  6aff                 push -1
// 00459792  685f217400           push 0x74215f
// 00459797  64a100000000         mov eax, dword ptr fs:[0]
// 0045979d  50                   push eax
// 0045979e  51                   push ecx
// 0045979f  53                   push ebx
// 004597a0  56                   push esi
// 004597a1  a188518b00           mov eax, dword ptr [0x8b5188]
// 004597a6  33c4                 xor eax, esp
// 004597a8  50                   push eax
// 004597a9  8d442410             lea eax, [esp + 0x10]
// 004597ad  64a300000000         mov dword ptr fs:[0], eax
// 004597b3  8bf1                 mov esi, ecx
// 004597b5  8974240c             mov dword ptr [esp + 0xc], esi
// 004597b9  e81c6e1d00           call 0x6305da
// 004597be  c7465410327900       mov dword ptr [esi + 0x54], 0x793210
// 004597c5  33db                 xor ebx, ebx
// 004597c7  c706c4347900         mov dword ptr [esi], 0x7934c4
// 004597cd  c74654b4347900       mov dword ptr [esi + 0x54], 0x7934b4
// 004597d4  895e5c               mov dword ptr [esi + 0x5c], ebx
// 004597d7  895c2418             mov dword ptr [esp + 0x18], ebx
// 004597db  895e60               mov dword ptr [esi + 0x60], ebx
// 004597de  895e64               mov dword ptr [esi + 0x64], ebx
// 004597e1  895e68               mov dword ptr [esi + 0x68], ebx
// 004597e4  895e6c               mov dword ptr [esi + 0x6c], ebx
// 004597e7  b001                 mov al, 1
// 004597e9  884670               mov byte ptr [esi + 0x70], al
// 004597ec  895e74               mov dword ptr [esi + 0x74], ebx
// 004597ef  dd05a8347900         fld qword ptr [0x7934a8]
// 004597f5  8a4c2420             mov cl, byte ptr [esp + 0x20]
// 004597f9  dd9e80000000         fstp qword ptr [esi + 0x80]
// 004597ff  6840000200           push 0x20040
// 00459804  c644241c04           mov byte ptr [esp + 0x1c], 4
// 00459809  884e78               mov byte ptr [esi + 0x78], cl
// 0045980c  885e79               mov byte ptr [esi + 0x79], bl
// 0045980f  885e7a               mov byte ptr [esi + 0x7a], bl
// 00459812  88467b               mov byte ptr [esi + 0x7b], al
// 00459815  e8dc661d00           call 0x62fef6
// 0045981a  83c404               add esp, 4
// 0045981d  89442420             mov dword ptr [esp + 0x20], eax
// 00459821  3bc3                 cmp eax, ebx
// 00459823  c644241805           mov byte ptr [esp + 0x18], 5
// 00459828  740e                 je 0x459838
// 0045982a  689c347900           push 0x79349c
// 0045982f  8bc8                 mov ecx, eax
// 00459831  e82a841300           call 0x591c60
// 00459836  eb02                 jmp 0x45983a
// 00459838  33c0                 xor eax, eax
// 0045983a  898688000000         mov dword ptr [esi + 0x88], eax
// 00459840  889e8c000000         mov byte ptr [esi + 0x8c], bl
// 00459846  899e90000000         mov dword ptr [esi + 0x90], ebx
// 0045984c  899e94000000         mov dword ptr [esi + 0x94], ebx
// 00459852  889e98000000         mov byte ptr [esi + 0x98], bl
// 00459858  899e9c000000         mov dword ptr [esi + 0x9c], ebx
// 0045985e  899ea0000000         mov dword ptr [esi + 0xa0], ebx
// 00459864  899ea4000000         mov dword ptr [esi + 0xa4], ebx
// 0045986a  c7465802000000       mov dword ptr [esi + 0x58], 2
// 00459871  8bc6                 mov eax, esi
// 00459873  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00459877  64890d00000000       mov dword ptr fs:[0], ecx
// 0045987e  59                   pop ecx
// 0045987f  5e                   pop esi
// 00459880  5b                   pop ebx
// 00459881  83c410               add esp, 0x10
// 00459884  c20400               ret 4


// Base at +0: out-of-line ctor (call 0x6305da), size 0x54 (second base vptr at +0x54).
struct InstanceBase {
    InstanceBase();
    virtual ~InstanceBase();
    char pad4[0x50];
};

// Second base at +0x54: inline ctor only stores its vptr (0x793210); +0x58 assigned 2 in derived body.
struct Interface54 {
    virtual void i0();
    int m58;
};

// Four members with non-trivial destructors are constructed before the new (EH state 4).
struct Pair60 { int a; int b; Pair60() : a(0), b(0) {} ~Pair60(); };
struct Pair68 { int a; int b; Pair68() : a(0), b(0) {} ~Pair68(); };
struct Mem70 { bool f; int c; Mem70() : f(true), c(0) {} ~Mem70(); };
struct Mem80 { double v; Mem80() : v(666.0) {} ~Mem80(); };

struct Big88 {
    Big88(const char*);
    char data[0x20040];
};

struct NonFactoryProduct : InstanceBase, Interface54 {
    int m5c;
    Pair60 m60;
    Pair68 m68;
    Mem70 m70;
    bool m78;
    bool m79;
    bool m7a;
    bool m7b;
    Mem80 m80;
    Big88* m88;
    bool m8c;
    int m90;
    int m94;
    bool m98;
    int m9c;
    int ma0;
    int ma4;
    NonFactoryProduct(bool arg);
    virtual void i0();
};

NonFactoryProduct::NonFactoryProduct(bool arg)
    : m5c(0)
{
    m78 = arg;
    m79 = false;
    m7a = false;
    m7b = true;
    m88 = new Big88("Render");
    m8c = false;
    m90 = 0;
    m94 = 0;
    m98 = false;
    m9c = 0;
    ma0 = 0;
    ma4 = 0;
    m58 = 2;
}
