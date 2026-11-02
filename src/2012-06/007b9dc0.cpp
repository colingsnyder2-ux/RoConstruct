// from server: 85% by Intel
struct BlockVTable {
    int (__thiscall *func10)(void* thisptr);
    int (__thiscall *func14)(void* thisptr);
    int (__thiscall *func18)(void* thisptr);
    int (__thiscall *func1C)(void* thisptr);
};

struct Block {
    BlockVTable* vptr;
};

int __cdecl func_007b9dc0(Block* esi) {
    int eax = esi->vptr->func10(esi);
    if (eax == 0) {
        eax = esi->vptr->func18(esi);
        if (eax == 0xB) {
            return 0;
        }
        if (eax == 0) {
            return 0;
        }
    }
    eax = esi->vptr->func10(esi);
    if (eax == 0) {
        eax = esi->vptr->func18(esi);
        if (eax == 0xC) {
            return 0;
        }
    }
    eax = esi->vptr->func10(esi);
    if (eax == 0) {
        eax = esi->vptr->func18(esi);
        if (eax == 2 || eax == 0xA) {
            return 0;
        }
    }
    return 1;
}
