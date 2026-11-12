// from server: 92% by EspClaude
// from server: 49% by colin
// roc 2007-08 004ae7b0  unit: RBX::VLighting::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004ae7b0
//
// 004ae7b0  55                   push ebp
// 004ae7b1  8bec                 mov ebp, esp
// 004ae7b3  6aff                 push -1
// 004ae7b5  6800a57400           push 0x74a500
// 004ae7ba  64a100000000         mov eax, dword ptr fs:[0]
// 004ae7c0  50                   push eax
// 004ae7c1  51                   push ecx
// 004ae7c2  53                   push ebx
// 004ae7c3  56                   push esi
// 004ae7c4  57                   push edi
// 004ae7c5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004ae7ca  33c5                 xor eax, ebp
// 004ae7cc  50                   push eax
// 004ae7cd  8d45f4               lea eax, [ebp - 0xc]
// 004ae7d0  64a300000000         mov dword ptr fs:[0], eax
// 004ae7d6  8965f0               mov dword ptr [ebp - 0x10], esp
// 004ae7d9  8bf1                 mov esi, ecx
// 004ae7db  6a14                 push 0x14
// 004ae7dd  c70600000000         mov dword ptr [esi], 0
// 004ae7e3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004ae7ea  e807171800           call 0x62fef6
// 004ae7ef  83c404               add esp, 4
// 004ae7f2  85c0                 test eax, eax
// 004ae7f4  7419                 je 0x4ae80f
// 004ae7f6  b901000000           mov ecx, 1
// 004ae7fb  894804               mov dword ptr [eax + 4], ecx
// 004ae7fe  894808               mov dword ptr [eax + 8], ecx
// 004ae801  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004ae804  c70044d87900         mov dword ptr [eax], 0x79d844
// 004ae80a  89480c               mov dword ptr [eax + 0xc], ecx
// 004ae80d  eb02                 jmp 0x4ae811
// 004ae80f  33c0                 xor eax, eax
// 004ae811  8906                 mov dword ptr [esi], eax
// 004ae813  8bc6                 mov eax, esi
// 004ae815  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004ae818  64890d00000000       mov dword ptr fs:[0], ecx
// 004ae81f  59                   pop ecx
// 004ae820  5f                   pop edi
// 004ae821  5e                   pop esi
// 004ae822  5b                   pop ebx
// 004ae823  8be5                 mov esp, ebp
// 004ae825  5d                   pop ebp
// 004ae826  c20800               ret 8

void* __cdecl operator new(unsigned int);

struct Deleter {
    void operator()(void*) const;
};

struct sp_counted_base {
    int use_count_;
    int weak_count_;
    sp_counted_base() : use_count_(1), weak_count_(1) {}
    virtual ~sp_counted_base() {}
    virtual void dispose() = 0;
    virtual void destroy() { delete this; }
};

struct Control : sp_counted_base {
    void* ptr;
    Deleter del;
    Control(void* p, const Deleter& d) : ptr(p), del(d) {}
    virtual void dispose();
};

struct S {
    Control* control;
    S(void*, Deleter);
};

S::S(void* p, Deleter d) : control(0)
{
    try {
        control = new Control(p, d);
    }
    catch (...) {
        d(p);
        throw;
    }
}
