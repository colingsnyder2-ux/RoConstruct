// from server: 100% by Xemicl
// from server: 100% by tajop
// roc 2012-06 0077a170  unit: RBX::PAVDebugSettings::?$sp_counted_impl_pd  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0077a170
//
// 0077a170  6aff                 push -1
// 0077a172  682baeab00           push 0xabae2b
// 0077a177  64a100000000         mov eax, dword ptr fs:[0]
// 0077a17d  50                   push eax
// 0077a17e  64892500000000       mov dword ptr fs:[0], esp
// 0077a185  51                   push ecx
// 0077a186  8b442418             mov eax, dword ptr [esp + 0x18]
// 0077a18a  53                   push ebx
// 0077a18b  56                   push esi
// 0077a18c  8b74241c             mov esi, dword ptr [esp + 0x1c]
// 0077a190  57                   push edi
// 0077a191  8bf9                 mov edi, ecx
// 0077a193  50                   push eax
// 0077a194  8d5f04               lea ebx, [edi + 4]
// 0077a197  56                   push esi
// 0077a198  8bcb                 mov ecx, ebx
// 0077a19a  897c2414             mov dword ptr [esp + 0x14], edi
// 0077a19e  8937                 mov dword ptr [edi], esi
// 0077a1a0  e83bffffff           call 0x77a0e0
// 0077a1a5  33c0                 xor eax, eax
// 0077a1a7  89442418             mov dword ptr [esp + 0x18], eax
// 0077a1ab  3bf0                 cmp esi, eax
// 0077a1ad  7403                 je 0x77a1b2
// 0077a1af  8d4620               lea eax, [esi + 0x20]
// 0077a1b2  56                   push esi
// 0077a1b3  50                   push eax
// 0077a1b4  53                   push ebx
// 0077a1b5  e82603feff           call 0x75a4e0
// 0077a1ba  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 0077a1be  83c40c               add esp, 0xc
// 0077a1c1  8bc7                 mov eax, edi
// 0077a1c3  5f                   pop edi
// 0077a1c4  5e                   pop esi
// 0077a1c5  5b                   pop ebx
// 0077a1c6  64890d00000000       mov dword ptr fs:[0], ecx
// 0077a1cd  83c410               add esp, 0x10
// 0077a1d0  c20800               ret 8

struct Pad { int a[8]; };
struct Esft { int w; };
struct T : Pad, Esft { };
typedef void (*Deleter)(T*);

struct shared_count {
    int* pi;
    shared_count(T* p, Deleter d);
    ~shared_count();
};

void sp_enable_shared_from_this(shared_count const* pn, Esft const* e, T const* p);

struct shared_ptr_T {
    T* px;
    shared_count pn;
    shared_ptr_T(T* p, Deleter d);
};

shared_ptr_T::shared_ptr_T(T* p, Deleter d) : px(p), pn(p, d) {
    sp_enable_shared_from_this(&pn, p, p);
}
