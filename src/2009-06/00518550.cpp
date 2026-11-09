// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004e6b50  unit: RBX::ViewNew::PartChunk  size: 61 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004e6b50
//
// 004e6b50  51                   push ecx
// 004e6b51  56                   push esi
// 004e6b52  57                   push edi
// 004e6b53  8bf9                 mov edi, ecx
// 004e6b55  83bfcc00000000       cmp dword ptr [edi + 0xcc], 0
// 004e6b5c  c744240800000000     mov dword ptr [esp + 8], 0
// 004e6b64  7507                 jne 0x4e6b6d
// 004e6b66  8b07                 mov eax, dword ptr [edi]
// 004e6b68  8b5028               mov edx, dword ptr [eax + 0x28]
// 004e6b6b  ffd2                 call edx
// 004e6b6d  8b742410             mov esi, dword ptr [esp + 0x10]
// 004e6b71  c70600000000         mov dword ptr [esi], 0
// 004e6b77  8b87cc000000         mov eax, dword ptr [edi + 0xcc]
// 004e6b7d  50                   push eax
// 004e6b7e  8bce                 mov ecx, esi
// 004e6b80  e81b240b00           call 0x598fa0
// 004e6b85  5f                   pop edi
// 004e6b86  8bc6                 mov eax, esi
// 004e6b88  5e                   pop esi
// 004e6b89  59                   pop ecx
// 004e6b8a  c20400               ret 4

struct Chunk;

struct ChunkVTable {
    void *unused[11];
    void (__thiscall *initialize)(Chunk *);
};

struct StrongPointer {
    void *value;
    void assign(void *);
};

struct Chunk {
    ChunkVTable *vtable;
    unsigned char padding[0x84];
    void *cached;
    StrongPointer get();
};

StrongPointer Chunk::get()
{
    volatile int temporary = 0;
    if (cached == 0)
        vtable->initialize(this);

    StrongPointer result;
    result.value = 0;
    result.assign(cached);
    return result;
}
