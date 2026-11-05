// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005fdfa0  unit: RBX::VTool::?$FactoryProduct  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005fdfa0
//
// 005fdfa0  56                   push esi
// 005fdfa1  8b742408             mov esi, dword ptr [esp + 8]
// 005fdfa5  57                   push edi
// 005fdfa6  56                   push esi
// 005fdfa7  e8d453faff           call 0x5a3380
// 005fdfac  8bf8                 mov edi, eax
// 005fdfae  83c404               add esp, 4
// 005fdfb1  85ff                 test edi, edi
// 005fdfb3  741e                 je 0x5fdfd3
// 005fdfb5  8bce                 mov ecx, esi
// 005fdfb7  e844ffffff           call 0x5fdf00
// 005fdfbc  85c0                 test eax, eax
// 005fdfbe  7413                 je 0x5fdfd3
// 005fdfc0  57                   push edi
// 005fdfc1  8bc8                 mov ecx, eax
// 005fdfc3  e828c9f5ff           call 0x55a8f0
// 005fdfc8  8bce                 mov ecx, esi
// 005fdfca  e831ffffff           call 0x5fdf00
// 005fdfcf  85c0                 test eax, eax
// 005fdfd1  75ed                 jne 0x5fdfc0
// 005fdfd3  5f                   pop edi
// 005fdfd4  5e                   pop esi
// 005fdfd5  c3                   ret 

struct Item {
    void consume(void* product);
};

struct Source {
    Item* next();
};

extern void* __cdecl func_005a3380(Source* source);

void __cdecl func_005fdfa0(Source* source)
{
    void* product = func_005a3380(source);
    if (product) {
        Item* item = source->next();
        while (item) {
            item->consume(product);
            item = source->next();
        }
    }
}
