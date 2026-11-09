// from server: 100% by EspClaude
// from server: 91% by EspClaude
// roc 2009-06 0060b700  unit: RBX::ClearBackpack  size: 66 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0060b700
//
// 0060b700  8b410c               mov eax, dword ptr [ecx + 0xc]
// 0060b703  50                   push eax
// 0060b704  e887f8ebff           call 0x4caf90
// 0060b709  83c404               add esp, 4
// 0060b70c  85c0                 test eax, eax
// 0060b70e  742f                 je 0x60b73f
// 0060b710  8bc8                 mov ecx, eax
// 0060b712  e819baeaff           call 0x4b7130
// 0060b717  85c0                 test eax, eax
// 0060b719  7424                 je 0x60b73f
// 0060b71b  8b484c               mov ecx, dword ptr [eax + 0x4c]
// 0060b71e  85c9                 test ecx, ecx
// 0060b720  7412                 je 0x60b734
// 0060b722  8b4110               mov eax, dword ptr [ecx + 0x10]
// 0060b725  2b410c               sub eax, dword ptr [ecx + 0xc]
// 0060b728  33c9                 xor ecx, ecx
// 0060b72a  c1f803               sar eax, 3
// 0060b72d  3bc8                 cmp ecx, eax
// 0060b72f  1bc0                 sbb eax, eax
// 0060b731  f7d8                 neg eax
// 0060b733  c3                   ret 
// 0060b734  33c0                 xor eax, eax
// 0060b736  33c9                 xor ecx, ecx
// 0060b738  3bc8                 cmp ecx, eax
// 0060b73a  1bc0                 sbb eax, eax
// 0060b73c  f7d8                 neg eax
// 0060b73e  c3                   ret 
// 0060b73f  32c0                 xor al, al
// 0060b741  c3                   ret 

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
    char padding[0x4c];
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
