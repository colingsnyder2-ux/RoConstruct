// from server: 100% by Yeetserama
// roc 2007-08 00404090  unit: VCWorkspace::?$CComObject  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00404090
//
// 00404090  56                   push esi
// 00404091  8d7104               lea esi, [ecx + 4]
// 00404094  c701fc4e7800         mov dword ptr [ecx], 0x784efc
// 0040409a  57                   push edi
// 0040409b  8bce                 mov ecx, esi
// 0040409d  e83ef1ffff           call 0x4031e0
// 004040a2  8bce                 mov ecx, esi
// 004040a4  e837f1ffff           call 0x4031e0
// 004040a9  8b06                 mov eax, dword ptr [esi]
// 004040ab  85c0                 test eax, eax
// 004040ad  8b3dc4e67700         mov edi, dword ptr [0x77e6c4]
// 004040b3  740c                 je 0x4040c1
// 004040b5  50                   push eax
// 004040b6  ffd7                 call edi
// 004040b8  83c404               add esp, 4
// 004040bb  c70600000000         mov dword ptr [esi], 0
// 004040c1  8b4604               mov eax, dword ptr [esi + 4]
// 004040c4  85c0                 test eax, eax
// 004040c6  740d                 je 0x4040d5
// 004040c8  50                   push eax
// 004040c9  ffd7                 call edi
// 004040cb  83c404               add esp, 4
// 004040ce  c7460400000000       mov dword ptr [esi + 4], 0
// 004040d5  5f                   pop edi
// 004040d6  c7460800000000       mov dword ptr [esi + 8], 0
// 004040dd  5e                   pop esi
// 004040de  c3                   ret 
// copied from an identical function in another client (function ?destroy@S@ns_ROCX000015@@QAEXXZ)

namespace ns_ROCX000015 {
// from server: 100% by king_originala
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
