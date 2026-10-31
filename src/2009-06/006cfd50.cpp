// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00644420  unit: RBX::HUMAN::Climbing  size: 208 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00644420
//
// 00644420  6aff                 push -1
// 00644422  68788c7d00           push 0x7d8c78
// 00644427  64a100000000         mov eax, dword ptr fs:[0]
// 0064442d  50                   push eax
// 0064442e  64892500000000       mov dword ptr fs:[0], esp
// 00644435  83ec14               sub esp, 0x14
// 00644438  56                   push esi
// 00644439  57                   push edi
// 0064443a  8bf9                 mov edi, ecx
// 0064443c  8d44242c             lea eax, [esp + 0x2c]
// 00644440  50                   push eax
// 00644441  8d4c240f             lea ecx, [esp + 0xf]
// 00644445  51                   push ecx
// 00644446  8bcf                 mov ecx, edi
// 00644448  897c2414             mov dword ptr [esp + 0x14], edi
// 0064444c  e84f6e0000           call 0x64b2a0
// 00644451  8b3590288000         mov esi, dword ptr [0x802890]
// 00644457  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 0064445b  c744242400000000     mov dword ptr [esp + 0x24], 0
// 00644463  85c0                 test eax, eax
// 00644465  7406                 je 0x64446d
// 00644467  3b442434             cmp eax, dword ptr [esp + 0x34]
// 0064446b  7406                 je 0x644473
// 0064446d  ffd6                 call esi
// 0064446f  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00644473  8b542430             mov edx, dword ptr [esp + 0x30]
// 00644477  3b542438             cmp edx, dword ptr [esp + 0x38]
// 0064447b  745e                 je 0x6444db
// 0064447d  85c0                 test eax, eax
// 0064447f  750a                 jne 0x64448b
// 00644481  ffd6                 call esi
// 00644483  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 00644487  85c0                 test eax, eax
// 00644489  7404                 je 0x64448f
// 0064448b  8b00                 mov eax, dword ptr [eax]
// 0064448d  eb02                 jmp 0x644491
// 0064448f  33c0                 xor eax, eax
// 00644491  8b4c2430             mov ecx, dword ptr [esp + 0x30]
// 00644495  3b4810               cmp ecx, dword ptr [eax + 0x10]
// 00644498  7202                 jb 0x64449c
// 0064449a  ffd6                 call esi
// 0064449c  8b542430             mov edx, dword ptr [esp + 0x30]
// 006444a0  52                   push edx
// 006444a1  8d442414             lea eax, [esp + 0x14]
// 006444a5  50                   push eax
// 006444a6  8bcf                 mov ecx, edi
// 006444a8  e89347faff           call 0x5e8c40
// 006444ad  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006444b1  85c0                 test eax, eax
// 006444b3  750a                 jne 0x6444bf
// 006444b5  ffd6                 call esi
// 006444b7  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006444bb  85c0                 test eax, eax
// 006444bd  7404                 je 0x6444c3
// 006444bf  8b08                 mov ecx, dword ptr [eax]
// 006444c1  eb02                 jmp 0x6444c5
// 006444c3  33c9                 xor ecx, ecx
// 006444c5  8b542430             mov edx, dword ptr [esp + 0x30]
// 006444c9  3b5110               cmp edx, dword ptr [ecx + 0x10]
// 006444cc  7206                 jb 0x6444d4
// 006444ce  ffd6                 call esi
// 006444d0  8b44242c             mov eax, dword ptr [esp + 0x2c]
// 006444d4  8344243004           add dword ptr [esp + 0x30], 4
// 006444d9  eb88                 jmp 0x644463
// 006444db  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006444df  8bc7                 mov eax, edi
// 006444e1  5f                   pop edi
// 006444e2  5e                   pop esi
// 006444e3  64890d00000000       mov dword ptr fs:[0], ecx
// 006444ea  83c420               add esp, 0x20
// 006444ed  c21000               ret 0x10

extern "C" void (__cdecl* _invalid_parameter_noinfo)();

struct Allocator {
    Allocator();
};

inline Allocator::Allocator() {}

struct Container {
    char padding[16];
    unsigned int* end;
};

struct Proxy {
    Container* container;
};

struct Iterator {
    Proxy* proxy;
    unsigned int* current;
};

struct Result {
    void* data[3];
};

struct Base {
    Base(const Allocator&, const Iterator&);
    ~Base();
};

struct S : Base {
    S(Iterator first, Iterator last);
    Result append(const unsigned int&);
};

S::S(Iterator first, Iterator last)
    : Base(Allocator(), first)
{
    void (__cdecl* invalid)() = _invalid_parameter_noinfo;

    for (;;) {
        if (!first.proxy || first.proxy != last.proxy)
            invalid();

        if (first.current == last.current)
            break;

        if (!first.proxy)
            invalid();

        Container* container = first.proxy ? first.proxy->container : 0;
        if (first.current >= container->end)
            invalid();

        append(*first.current);

        if (!first.proxy)
            invalid();

        container = first.proxy ? first.proxy->container : 0;
        if (first.current >= container->end)
            invalid();

        ++first.current;
    }
}
