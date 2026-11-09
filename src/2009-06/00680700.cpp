// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005e5350  unit: RBX::SimJob  size: 71 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005e5350
//
// 005e5350  51                   push ecx
// 005e5351  56                   push esi
// 005e5352  8bf1                 mov esi, ecx
// 005e5354  8b06                 mov eax, dword ptr [esi]
// 005e5356  57                   push edi
// 005e5357  85c0                 test eax, eax
// 005e5359  741b                 je 0x5e5376
// 005e535b  8d4c2408             lea ecx, [esp + 8]
// 005e535f  51                   push ecx
// 005e5360  83c004               add eax, 4
// 005e5363  50                   push eax
// 005e5364  89742410             mov dword ptr [esp + 0x10], esi
// 005e5368  e893feffff           call 0x5e5200
// 005e536d  83c408               add esp, 8
// 005e5370  c70600000000         mov dword ptr [esi], 0
// 005e5376  8b7c2410             mov edi, dword ptr [esp + 0x10]
// 005e537a  85ff                 test edi, edi
// 005e537c  7413                 je 0x5e5391
// 005e537e  8d542410             lea edx, [esp + 0x10]
// 005e5382  52                   push edx
// 005e5383  8d4f04               lea ecx, [edi + 4]
// 005e5386  89742414             mov dword ptr [esp + 0x14], esi
// 005e538a  e811c0e3ff           call 0x4213a0
// 005e538f  893e                 mov dword ptr [esi], edi
// 005e5391  5f                   pop edi
// 005e5392  5e                   pop esi
// 005e5393  59                   pop ecx
// 005e5394  c20400               ret 4

struct Listener {
    void attach(void** owner);
};

struct SimJob {
    void* object;
    void setObject(void* value);
};

extern "C" void __cdecl detach(Listener* listener, void** owner);

void SimJob::setObject(void* value) {
    if (object) {
        void* owner = this;
        detach(reinterpret_cast<Listener*>(static_cast<char*>(object) + 0xc),
               &owner);
        object = 0;
    }

    void* next = value;
    if (next) {
        value = this;
        reinterpret_cast<Listener*>(static_cast<char*>(next) + 0xc)->attach(&value);
        object = next;
    }
}
