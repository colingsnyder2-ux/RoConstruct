// from server: 100% by EspClaude
// from server: 100% by colin
// roc 2008-06 00623ec0  unit: lua_exception  size: 128 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00623ec0
//
// 00623ec0  6aff                 push -1
// 00623ec2  6889977d00           push 0x7d9789
// 00623ec7  64a100000000         mov eax, dword ptr fs:[0]
// 00623ecd  50                   push eax
// 00623ece  64892500000000       mov dword ptr fs:[0], esp
// 00623ed5  51                   push ecx
// 00623ed6  8b442414             mov eax, dword ptr [esp + 0x14]
// 00623eda  56                   push esi
// 00623edb  85c0                 test eax, eax
// 00623edd  7405                 je 0x623ee4
// 00623edf  8d70f4               lea esi, [eax - 0xc]
// 00623ee2  eb02                 jmp 0x623ee6
// 00623ee4  33f6                 xor esi, esi
// 00623ee6  89742418             mov dword ptr [esp + 0x18], esi
// 00623eea  89742404             mov dword ptr [esp + 4], esi
// 00623eee  c744241000000000     mov dword ptr [esp + 0x10], 0
// 00623ef6  85f6                 test esi, esi
// 00623ef8  7436                 je 0x623f30
// 00623efa  c70600000000         mov dword ptr [esi], 0
// 00623f00  c7460400000000       mov dword ptr [esi + 4], 0
// 00623f07  6a04                 push 4
// 00623f09  c644241401           mov byte ptr [esp + 0x14], 1
// 00623f0e  c6460800             mov byte ptr [esi + 8], 0
// 00623f12  e809ca0700           call 0x6a0920
// 00623f17  83c404               add esp, 4
// 00623f1a  85c0                 test eax, eax
// 00623f1c  7408                 je 0x623f26
// 00623f1e  c70001000000         mov dword ptr [eax], 1
// 00623f24  eb02                 jmp 0x623f28
// 00623f26  33c0                 xor eax, eax
// 00623f28  50                   push eax
// 00623f29  8bce                 mov ecx, esi
// 00623f2b  e8b0eefeff           call 0x612de0
// 00623f30  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00623f34  5e                   pop esi
// 00623f35  64890d00000000       mov dword ptr fs:[0], ecx
// 00623f3c  83c410               add esp, 0x10
// 00623f3f  c3                   ret 

void* __cdecl operator new(unsigned int);
inline void* __cdecl operator new(unsigned int, void* p) { return p; }
inline void __cdecl operator delete(void*, void*) {}

struct Pointer {
    int* value;
    void* count;

    Pointer();
    ~Pointer();
    void reset(int*);
};

struct Header {
    Pointer pointer;
    bool flag;

    Header();
};

__forceinline Pointer::Pointer() : value(0), count(0) {}

__forceinline Header::Header() : pointer(), flag(false) {
    pointer.reset(new int(1));
}

void __cdecl construct_header(char* p) {
    Header* h = p ? (Header*)(p - 12) : 0;
    new (h) Header;
}
