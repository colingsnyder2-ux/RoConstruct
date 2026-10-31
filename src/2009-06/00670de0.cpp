// from server: 96% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005e81b0  unit: RBX::Primitive  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e81b0
//
// 005e81b0  83ec30               sub esp, 0x30
// 005e81b3  56                   push esi
// 005e81b4  8bf1                 mov esi, ecx
// 005e81b6  57                   push edi
// 005e81b7  8bbea0000000         mov edi, dword ptr [esi + 0xa0]
// 005e81bd  8bcf                 mov ecx, edi
// 005e81bf  e89c11fbff           call 0x599360
// 005e81c4  8b442440             mov eax, dword ptr [esp + 0x40]
// 005e81c8  81c794000000         add edi, 0x94
// 005e81ce  57                   push edi
// 005e81cf  8b7c2440             mov edi, dword ptr [esp + 0x40]
// 005e81d3  57                   push edi
// 005e81d4  50                   push eax
// 005e81d5  8d4c2414             lea ecx, [esp + 0x14]
// 005e81d9  51                   push ecx
// 005e81da  8bce                 mov ecx, esi
// 005e81dc  e80ff5ffff           call 0x5e76f0
// 005e81e1  8bc8                 mov ecx, eax
// 005e81e3  e888170600           call 0x649970
// 005e81e8  8bc7                 mov eax, edi
// 005e81ea  5f                   pop edi
// 005e81eb  5e                   pop esi
// 005e81ec  83c430               add esp, 0x30
// 005e81ef  c20800               ret 8

struct Source {
    char reserved[0x94];
    char data;
    const void* get();
};

struct Temporary {
    char data[0x30];
    ~Temporary();
};

struct Primitive {
    char reserved[0xA0];
    Source* source;

    Temporary* process(Temporary*, const void*, void*, const void*);
    void* func_005e81b0(void*, const void*);
};

void* Primitive::func_005e81b0(void* output, const void* input)
{
    char storage[0x30];
    Source* s = source;
    s->get();
    process(reinterpret_cast<Temporary*>(storage), input, output, &s->data)->~Temporary();
    return output;
}
