// from server: 91% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0057df80  unit: RBX::ClearBackpack  size: 69 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0057df80
//
// 0057df80  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0057df83  50                   push eax
// 0057df84  e8f7ccf1ff           call 0x49ac80
// 0057df89  83c404               add esp, 4
// 0057df8c  85c0                 test eax, eax
// 0057df8e  7432                 je 0x57dfc2
// 0057df90  8bc8                 mov ecx, eax
// 0057df92  e8d9e4f0ff           call 0x48c470
// 0057df97  85c0                 test eax, eax
// 0057df99  7427                 je 0x57dfc2
// 0057df9b  8b8808010000         mov ecx, dword ptr [eax + 0x108]
// 0057dfa1  85c9                 test ecx, ecx
// 0057dfa3  7412                 je 0x57dfb7
// 0057dfa5  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0057dfa8  2b410c               sub eax, dword ptr [ecx + 0xc]
// 0057dfab  33c9                 xor ecx, ecx
// 0057dfad  c1f803               sar eax, 3
// 0057dfb0  3bc8                 cmp ecx, eax
// 0057dfb2  1bc0                 sbb eax, eax
// 0057dfb4  f7d8                 neg eax
// 0057dfb6  c3                   ret 
// 0057dfb7  33c0                 xor eax, eax
// 0057dfb9  33c9                 xor ecx, ecx
// 0057dfbb  3bc8                 cmp ecx, eax
// 0057dfbd  1bc0                 sbb eax, eax
// 0057dfbf  f7d8                 neg eax
// 0057dfc1  c3                   ret 
// 0057dfc2  32c0                 xor al, al
// 0057dfc4  c3                   ret 

struct Entry {
    void* value;
    void* owner;
};

struct Children {
    char padding[12];
    Entry* first;
    Entry* last;
};

struct Backpack {
    char padding[0x108];
    Children* children;
};

struct Service {
    Backpack* getBackpack();
};

extern "C" Service* findService(void*);

struct ClearBackpack {
    char padding[12];
    void* context;
    bool enabled();
};

bool ClearBackpack::enabled()
{
    Service* service = findService(context);
    if (service) {
        Backpack* backpack = service->getBackpack();
        if (backpack) {
            Children* children = backpack->children;
            unsigned int count = children
                ? children->last - children->first
                : 0;
            return 0U < count;
        }
    }
    return false;
}
