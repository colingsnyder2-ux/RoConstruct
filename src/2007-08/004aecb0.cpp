// from server: 92% by EspClaude
// roc 2007-08 004aecb0  unit: RBX::VWeld::?$FactoryProduct::Creator  size: 121 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004aecb0
// 004aecb0  55                   push ebp
// 004aecb1  8bec                 mov ebp, esp
// 004aecb3  6aff                 push -1
// 004aecb5  6870a57400           push 0x74a570
// 004aecba  64a100000000         mov eax, dword ptr fs:[0]
// 004aecc0  50                   push eax
// 004aecc1  51                   push ecx
// 004aecc2  53                   push ebx
// 004aecc3  56                   push esi
// 004aecc4  57                   push edi
// 004aecc5  a188518b00           mov eax, dword ptr [0x8b5188]
// 004aecca  33c5                 xor eax, ebp
// 004aeccc  50                   push eax
// 004aeccd  8d45f4               lea eax, [ebp - 0xc]
// 004aecd0  64a300000000         mov dword ptr fs:[0], eax
// 004aecd6  8965f0               mov dword ptr [ebp - 0x10], esp
// 004aecd9  8bf1                 mov esi, ecx
// 004aecdb  6a14                 push 0x14
// 004aecdd  c70600000000         mov dword ptr [esi], 0
// 004aece3  c745fc00000000       mov dword ptr [ebp - 4], 0
// 004aecea  e807121800           call 0x62fef6
// 004aecef  83c404               add esp, 4
// 004aecf2  85c0                 test eax, eax
// 004aecf4  7419                 je 0x4aed0f
// 004aecf6  b901000000           mov ecx, 1
// 004aecfb  894804               mov dword ptr [eax + 4], ecx
// 004aecfe  894808               mov dword ptr [eax + 8], ecx
// 004aed01  8b4d08               mov ecx, dword ptr [ebp + 8]
// 004aed04  c7007cd87900         mov dword ptr [eax], 0x79d87c
// 004aed0a  89480c               mov dword ptr [eax + 0xc], ecx
// 004aed0d  eb02                 jmp 0x4aed11
// 004aed0f  33c0                 xor eax, eax
// 004aed11  8906                 mov dword ptr [esi], eax
// 004aed13  8bc6                 mov eax, esi
// 004aed15  8b4df4               mov ecx, dword ptr [ebp - 0xc]
// 004aed18  64890d00000000       mov dword ptr fs:[0], ecx
// 004aed1f  59                   pop ecx
// 004aed20  5f                   pop edi
// 004aed21  5e                   pop esi
// 004aed22  5b                   pop ebx
// 004aed23  8be5                 mov esp, ebp
// 004aed25  5d                   pop ebp
// 004aed26  c20800               ret 8
// boost::detail::shared_count(P p, D d) with sp_counted_impl_pd<P,D>:
// new(0x14) = vptr, use_count=1, weak_count=1, ptr at +0xc, empty deleter at +0x10.

void* __cdecl operator new(unsigned int);

struct Deleter {
    void operator()(void*) const;
};

struct ControlBase {
    int strong;
    int weak;
    ControlBase() : strong(1), weak(1) {}
    virtual ~ControlBase() {}
    virtual void dispose() = 0;
};

struct Control : ControlBase {
    void* object;
    Deleter deleter;
    Control(void* p, const Deleter& d) : object(p), deleter(d) {}
    virtual void dispose() { deleter(object); }
};

struct S {
    ControlBase* control;
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
