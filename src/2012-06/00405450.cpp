// from server: 100% by Xemicl
// roc 2012-06 00405450  unit: VCApp::?$CComObject  size: 79 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00405450
//
// 00405450  56                   push esi
// 00405451  8d7104               lea esi, [ecx + 4]
// 00405454  c7017838b400         mov dword ptr [ecx], 0xb43878
// 0040545a  57                   push edi
// 0040545b  8bce                 mov ecx, esi
// 0040545d  e85efcffff           call 0x4050c0
// 00405462  8bce                 mov ecx, esi
// 00405464  e857fcffff           call 0x4050c0
// 00405469  8b06                 mov eax, dword ptr [esi]
// 0040546b  8b3dc829b200         mov edi, dword ptr [0xb229c8]
// 00405471  85c0                 test eax, eax
// 00405473  740c                 je 0x405481
// 00405475  50                   push eax
// 00405476  ffd7                 call edi
// 00405478  83c404               add esp, 4
// 0040547b  c70600000000         mov dword ptr [esi], 0
// 00405481  8b4604               mov eax, dword ptr [esi + 4]
// 00405484  85c0                 test eax, eax
// 00405486  740d                 je 0x405495
// 00405488  50                   push eax
// 00405489  ffd7                 call edi
// 0040548b  83c404               add esp, 4
// 0040548e  c7460400000000       mov dword ptr [esi + 4], 0
// 00405495  5f                   pop edi
// 00405496  c7460800000000       mov dword ptr [esi + 8], 0
// 0040549d  5e                   pop esi
// 0040549e  c3                   ret 
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