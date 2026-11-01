// from server: 100% by Yeetserama
// roc 2010-06 0041b570  unit: CInstanceRecord  size: 141 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0041b570
//
// 0041b570  56                   push esi
// 0041b571  57                   push edi
// 0041b572  8bf9                 mov edi, ecx
// 0041b574  e8d7fe1700           call 0x59b450
// 0041b579  8b350ca99e00         mov esi, dword ptr [0x9ea90c]
// 0041b57f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041b583  85c0                 test eax, eax
// 0041b585  7406                 je 0x41b58d
// 0041b587  3b442414             cmp eax, dword ptr [esp + 0x14]
// 0041b58b  7406                 je 0x41b593
// 0041b58d  ffd6                 call esi
// 0041b58f  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041b593  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 0041b597  3b4c2418             cmp ecx, dword ptr [esp + 0x18]
// 0041b59b  745b                 je 0x41b5f8
// 0041b59d  85c0                 test eax, eax
// 0041b59f  750a                 jne 0x41b5ab
// 0041b5a1  ffd6                 call esi
// 0041b5a3  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041b5a7  85c0                 test eax, eax
// 0041b5a9  7404                 je 0x41b5af
// 0041b5ab  8b00                 mov eax, dword ptr [eax]
// 0041b5ad  eb02                 jmp 0x41b5b1
// 0041b5af  33c0                 xor eax, eax
// 0041b5b1  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041b5b5  3b5010               cmp edx, dword ptr [eax + 0x10]
// 0041b5b8  7202                 jb 0x41b5bc
// 0041b5ba  ffd6                 call esi
// 0041b5bc  8b442410             mov eax, dword ptr [esp + 0x10]
// 0041b5c0  8b08                 mov ecx, dword ptr [eax]
// 0041b5c2  51                   push ecx
// 0041b5c3  8bcf                 mov ecx, edi
// 0041b5c5  e826081800           call 0x59bdf0
// 0041b5ca  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041b5ce  85c0                 test eax, eax
// 0041b5d0  750a                 jne 0x41b5dc
// 0041b5d2  ffd6                 call esi
// 0041b5d4  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041b5d8  85c0                 test eax, eax
// 0041b5da  7404                 je 0x41b5e0
// 0041b5dc  8b08                 mov ecx, dword ptr [eax]
// 0041b5de  eb02                 jmp 0x41b5e2
// 0041b5e0  33c9                 xor ecx, ecx
// 0041b5e2  8b542410             mov edx, dword ptr [esp + 0x10]
// 0041b5e6  3b5110               cmp edx, dword ptr [ecx + 0x10]
// 0041b5e9  7206                 jb 0x41b5f1
// 0041b5eb  ffd6                 call esi
// 0041b5ed  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0041b5f1  8344241004           add dword ptr [esp + 0x10], 4
// 0041b5f6  eb8b                 jmp 0x41b583
// 0041b5f8  5f                   pop edi
// 0041b5f9  5e                   pop esi
// 0041b5fa  c21000               ret 0x10
// copied from an identical function in another client (function ?assign@CInstanceExplorer@ns_ROCX00001d@@QAEXUIterator@2@0@Z)

namespace ns_ROCX00001d {
// from server: 100% by king_originala
extern "C" void (__cdecl* invalid_parameter_handler)();

struct Container
{
    char padding[16];
    unsigned int* end;
};

struct Iterator
{
    Container** owner;
    unsigned int* current;
};

struct CInstanceExplorer
{
    void clear();
    void append(unsigned int value);
    void assign(Iterator first, Iterator last);
};

void CInstanceExplorer::assign(Iterator first, Iterator last)
{
    clear();
    void (__cdecl* report)() = invalid_parameter_handler;

    for (;;)
    {
        if (!first.owner || first.owner != last.owner)
            report();

        if (first.current == last.current)
            break;

        if (!first.owner)
            report();

        Container* container = first.owner ? *first.owner : 0;
        if (first.current >= container->end)
            report();

        append(*first.current);

        if (!first.owner)
            report();

        container = first.owner ? *first.owner : 0;
        if (first.current >= container->end)
            report();

        ++first.current;
    }
}
}
