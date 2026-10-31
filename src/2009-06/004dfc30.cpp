// from server: 81% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 004a8cc0  unit: RBX::VHint::?$FactoryProduct::Creator  size: 129 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004a8cc0
//
// 004a8cc0  83ec08               sub esp, 8
// 004a8cc3  56                   push esi
// 004a8cc4  8b742414             mov esi, dword ptr [esp + 0x14]
// 004a8cc8  57                   push edi
// 004a8cc9  8bf9                 mov edi, ecx
// 004a8ccb  85f6                 test esi, esi
// 004a8ccd  744f                 je 0x4a8d1e
// 004a8ccf  8bce                 mov ecx, esi
// 004a8cd1  e8ca2effff           call 0x49bba0
// 004a8cd6  8b4608               mov eax, dword ptr [esi + 8]
// 004a8cd9  8b4e0c               mov ecx, dword ptr [esi + 0xc]
// 004a8cdc  8b742414             mov esi, dword ptr [esp + 0x14]
// 004a8ce0  89442408             mov dword ptr [esp + 8], eax
// 004a8ce4  83c004               add eax, 4
// 004a8ce7  50                   push eax
// 004a8ce8  894c2410             mov dword ptr [esp + 0x10], ecx
// 004a8cec  56                   push esi
// 004a8ced  8d8f30010000         lea ecx, [edi + 0x130]
// 004a8cf3  e8a8eeffff           call 0x4a7ba0
// 004a8cf8  84c0                 test al, al
// 004a8cfa  7508                 jne 0x4a8d04
// 004a8cfc  5f                   pop edi
// 004a8cfd  5e                   pop esi
// 004a8cfe  83c408               add esp, 8
// 004a8d01  c20800               ret 8
// 004a8d04  6a01                 push 1
// 004a8d06  6a18                 push 0x18
// 004a8d08  8d542414             lea edx, [esp + 0x14]
// 004a8d0c  52                   push edx
// 004a8d0d  8bce                 mov ecx, esi
// 004a8d0f  e8ecc8ffff           call 0x4a5600
// 004a8d14  5f                   pop edi
// 004a8d15  b001                 mov al, 1
// 004a8d17  5e                   pop esi
// 004a8d18  83c408               add esp, 8
// 004a8d1b  c20800               ret 8
// 004a8d1e  e84db50a00           call 0x554270
// 004a8d23  83c004               add eax, 4
// 004a8d26  50                   push eax
// 004a8d27  8b442418             mov eax, dword ptr [esp + 0x18]
// 004a8d2b  50                   push eax
// 004a8d2c  8d8f30010000         lea ecx, [edi + 0x130]
// 004a8d32  e8e9f0ffff           call 0x4a7e20
// 004a8d37  5f                   pop edi
// 004a8d38  b001                 mov al, 1
// 004a8d3a  5e                   pop esi
// 004a8d3b  83c408               add esp, 8
// 004a8d3e  c20800               ret 8

struct Stream {
    void write(const void* data, int bits, bool flag);
};

struct Source {
    unsigned char padding[8];
    unsigned char* data;
    unsigned int value;

    void prepare();
};

struct State {
    bool encode(Stream* stream, const void* data);
    void encodeDefault(Stream* stream, const void* data);
};

extern "C" unsigned char* __cdecl defaultData();

struct S {
    unsigned char padding[0x130];
    State state;

    bool f(Stream* stream, Source* source);
};

bool S::f(Stream* stream, Source* source)
{
    if (source) {
        source->prepare();

        struct Record {
            unsigned char* data;
            unsigned int value;
        } record;

        record.data = source->data;
        record.value = source->value;

        if (!state.encode(stream, record.data + 4))
            return false;

        stream->write(&record.value, 24, true);
        return true;
    }

    state.encodeDefault(stream, defaultData() + 4);
    return true;
}
