// from server: 100% by EspClaude
// roc 2009-06 004047b0  unit: VCApp::?$CComObject  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 004047b0
//
// 004047b0  56                   push esi
// 004047b1  8d7104               lea esi, [ecx + 4]
// 004047b4  c7013cce8a00         mov dword ptr [ecx], 0x8ace3c
// 004047ba  57                   push edi
// 004047bb  8bce                 mov ecx, esi
// 004047bd  e88efaffff           call 0x404250
// 004047c2  8bce                 mov ecx, esi
// 004047c4  e887faffff           call 0x404250
// 004047c9  8b06                 mov eax, dword ptr [esi]
// 004047cb  8b3dcce98900         mov edi, dword ptr [0x89e9cc]
// 004047d1  85c0                 test eax, eax
// 004047d3  740c                 je 0x4047e1
// 004047d5  50                   push eax
// 004047d6  ffd7                 call edi
// 004047d8  83c404               add esp, 4
// 004047db  c70600000000         mov dword ptr [esi], 0
// 004047e1  8b4604               mov eax, dword ptr [esi + 4]
// 004047e4  85c0                 test eax, eax
// 004047e6  740d                 je 0x4047f5
// 004047e8  50                   push eax
// 004047e9  ffd7                 call edi
// 004047eb  83c404               add esp, 4
// 004047ee  c7460400000000       mov dword ptr [esi + 4], 0
// 004047f5  5f                   pop edi
// 004047f6  c7460800000000       mov dword ptr [esi + 8], 0
// 004047fd  5e                   pop esi
// 004047fe  c3                   ret 
// copied from an identical function in another client (function ?destroy@S@ns_ROCX000019@@QAEXXZ)

namespace ns_ROCX000019 {
extern void (__cdecl *free_memory)(void *);
extern unsigned char object_table[];

struct Buffer
{
    void *first;
    void *second;
    unsigned int count;

    void clear();
};

struct S
{
    void *table;
    Buffer buffer;

    void destroy();
};

void S::destroy()
{
    Buffer *b = &buffer;
    table = object_table;
    b->clear();
    b->clear();

    void (__cdecl *release)(void *) = free_memory;

    if (b->first)
    {
        release(b->first);
        b->first = 0;
    }

    if (b->second)
    {
        release(b->second);
        b->second = 0;
    }

    b->count = 0;
}
}
