// from server: 100% by EspClaude
// roc 2009-06 0042da90  unit: CDeclarationView  size: 161 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0042da90
//
// 0042da90  56                   push esi
// 0042da91  8bf1                 mov esi, ecx
// 0042da93  c70664318b00         mov dword ptr [esi], 0x8b3164
// 0042da99  8b8610010000         mov eax, dword ptr [esi + 0x110]
// 0042da9f  85c0                 test eax, eax
// 0042daa1  7408                 je 0x42daab
// 0042daa3  8b08                 mov ecx, dword ptr [eax]
// 0042daa5  8b5108               mov edx, dword ptr [ecx + 8]
// 0042daa8  50                   push eax
// 0042daa9  ffd2                 call edx
// 0042daab  8b860c010000         mov eax, dword ptr [esi + 0x10c]
// 0042dab1  85c0                 test eax, eax
// 0042dab3  7408                 je 0x42dabd
// 0042dab5  8b08                 mov ecx, dword ptr [eax]
// 0042dab7  8b5108               mov edx, dword ptr [ecx + 8]
// 0042daba  50                   push eax
// 0042dabb  ffd2                 call edx
// 0042dabd  8b8608010000         mov eax, dword ptr [esi + 0x108]
// 0042dac3  85c0                 test eax, eax
// 0042dac5  7408                 je 0x42dacf
// 0042dac7  8b08                 mov ecx, dword ptr [eax]
// 0042dac9  8b5108               mov edx, dword ptr [ecx + 8]
// 0042dacc  50                   push eax
// 0042dacd  ffd2                 call edx
// 0042dacf  8b8604010000         mov eax, dword ptr [esi + 0x104]
// 0042dad5  85c0                 test eax, eax
// 0042dad7  7408                 je 0x42dae1
// 0042dad9  8b08                 mov ecx, dword ptr [eax]
// 0042dadb  8b5108               mov edx, dword ptr [ecx + 8]
// 0042dade  50                   push eax
// 0042dadf  ffd2                 call edx
// 0042dae1  8b8600010000         mov eax, dword ptr [esi + 0x100]
// 0042dae7  85c0                 test eax, eax
// 0042dae9  7408                 je 0x42daf3
// 0042daeb  8b08                 mov ecx, dword ptr [eax]
// 0042daed  8b5108               mov edx, dword ptr [ecx + 8]
// 0042daf0  50                   push eax
// 0042daf1  ffd2                 call edx
// 0042daf3  8b86fc000000         mov eax, dword ptr [esi + 0xfc]
// 0042daf9  85c0                 test eax, eax
// 0042dafb  7408                 je 0x42db05
// 0042dafd  8b08                 mov ecx, dword ptr [eax]
// 0042daff  8b5108               mov edx, dword ptr [ecx + 8]
// 0042db02  50                   push eax
// 0042db03  ffd2                 call edx
// 0042db05  8b86f8000000         mov eax, dword ptr [esi + 0xf8]
// 0042db0b  85c0                 test eax, eax
// 0042db0d  7408                 je 0x42db17
// 0042db0f  8b08                 mov ecx, dword ptr [eax]
// 0042db11  8b5108               mov edx, dword ptr [ecx + 8]
// 0042db14  50                   push eax
// 0042db15  ffd2                 call edx
// 0042db17  8b86f4000000         mov eax, dword ptr [esi + 0xf4]
// 0042db1d  85c0                 test eax, eax
// 0042db1f  7408                 je 0x42db29
// 0042db21  8b08                 mov ecx, dword ptr [eax]
// 0042db23  8b5108               mov edx, dword ptr [ecx + 8]
// 0042db26  50                   push eax
// 0042db27  ffd2                 call edx
// 0042db29  8bce                 mov ecx, esi
// 0042db2b  5e                   pop esi
// 0042db2c  e959ba2e00           jmp 0x71958a
// copied from an identical function in another client (function ?cleanup@CDeclarationView@ns_ROCX000004@@QAEXXZ)

namespace ns_ROCX000004 {
struct Interface;

struct InterfaceTable {
    void* reserved[2];
    unsigned long (__stdcall *release)(Interface*);
};

struct Interface {
    InterfaceTable* table;
};

extern void* declarationViewTable[];

struct Base {
    void** volatile table;
    char storage[0xF0];
    void cleanup();
};

struct CDeclarationView : Base {
    Interface* pF4;
    Interface* pF8;
    Interface* pFC;
    Interface* p100;
    Interface* p104;
    Interface* p108;
    Interface* p10C;
    Interface* volatile p110;

    void cleanup();
};

void CDeclarationView::cleanup()
{
    table = declarationViewTable;
    Interface* p = p110;
    if (p) p->table->release(p);
    if (p10C) p10C->table->release(p10C);
    if (p108) p108->table->release(p108);
    if (p104) p104->table->release(p104);
    if (p100) p100->table->release(p100);
    if (pFC) pFC->table->release(pFC);
    if (pF8) pF8->table->release(pF8);
    if (pF4) pF4->table->release(pF4);
    Base::cleanup();
}
}
