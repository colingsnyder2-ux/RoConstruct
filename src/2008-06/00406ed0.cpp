// from server: 100% by coldek
// from server: 100% by tester
// roc 2008-06 00406ed0  unit: boost::thread_exception  size: 110 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00406ed0
//
// 00406ed0  55                   push ebp
// 00406ed1  8bec                 mov ebp, esp
// 00406ed3  6aff                 push -1
// 00406ed5  68b0ce7b00           push 0x7bceb0
// 00406eda  64a100000000         mov eax, dword ptr fs:[0]
// 00406ee0  50                   push eax
// 00406ee1  64892500000000       mov dword ptr fs:[0], esp
// 00406ee8  51                   push ecx
// 00406ee9  53                   push ebx
// 00406eea  56                   push esi
// 00406eeb  57                   push edi
// 00406eec  8965f0               mov dword ptr [ebp - 0x10], esp
// 00406eef  8bf1                 mov esi, ecx
// 00406ef1  6a14                 push 0x14
// 00406ef3  c70600000000         mov dword ptr [esi], 0
// 00406ef9  c745fc00000000       mov dword ptr [ebp - 4], 0
// 00406f00  e81b9a2900           call 0x6a0920
// 00406f05  83c404               add esp, 4
// 00406f08  85c0                 test eax, eax
// 00406f0a  7419                 je 0x406f25
// 00406f0c  b901000000           mov ecx, 1
// 00406f11  894804               mov dword ptr [eax + 4], ecx
// 00406f14  894808               mov dword ptr [eax + 8], ecx
// 00406f17  8b4d08               mov ecx, dword ptr [ebp + 8]
// 00406f1a  c700f8b38000         mov dword ptr [eax], 0x80b3f8
// 00406f20  89480c               mov dword ptr [eax + 0xc], ecx
// 00406f23  eb02                 jmp 0x406f27
// 00406f25  33c0                 xor eax, eax
// 00406f27  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 00406f2a  8906                 mov dword ptr [esi], eax
// 00406f2c  5f                   pop edi
// 00406f2d  8bc6                 mov eax, esi
// 00406f2f  5e                   pop esi
// 00406f30  64890d00000000       mov dword ptr fs:[0], ecx
// 00406f37  5b                   pop ebx
// 00406f38  8be5                 mov esp, ebp
// 00406f3a  5d                   pop ebp
// 00406f3b  c20800               ret 8

extern void* __cdecl operator new(unsigned int);
extern const unsigned char control_table[];

struct Object {
    virtual ~Object();
};

struct Deleter { void operator()(Object*) const; };

struct Control {
    const void* table;
    long strong;
    long weak;
    Object* object;
    Deleter deleter;
};

struct S {
    Control* control;
    S(Object* object, Deleter deleter);
};

S::S(Object* object, Deleter deleter) : control(0)
{
    try {
        Control* p = static_cast<Control*>(operator new(sizeof(Control)));
        if (p) {
            p->strong = 1;
            p->weak = 1;
            p->table = control_table;
            p->object = object;
        } else {
            p = 0;
        }
        control = p;
    } catch (...) {
        deleter(object);
        throw;
    }
}
