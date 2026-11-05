// from server: 44% by colin
struct DataState;
struct Selection;

struct EditSelectionVerb {
    char pad[0x14];
    int field14;
    void* field20;
    void doIt(DataState*);
};

struct SnapSelectionVerb : EditSelectionVerb {
    void doIt(DataState* dataState);
};

extern "C" void __stdcall _invalid_parameter_noinfo();

void SnapSelectionVerb::doIt(DataState* dataState)
{
    void* p = this->field20;
    ((void (__thiscall*)(void*))0x55e290)(p);
    void* q = this->field20;
    if (q) {
        ((void (__thiscall*)(void*))0x410d40)(q);
    }

    unsigned char flag = *(unsigned char*)((char*)dataState + 0x18);

    char local = (char)flag;

    void* r = ((void* (__thiscall*)(void*, int))0x562300)((char*)this + 0x14, 1);
    Selection* sel1 = *(Selection**)((char*)r + 0x104);
    int ebp = *(int*)((char*)sel1 + 8);
    if (*(unsigned int*)((char*)sel1 + 4) > (unsigned int)ebp) {
        _invalid_parameter_noinfo();
    }

    void* r2 = ((void* (__thiscall*)(void*, int))0x562300)((char*)this + 0x14, 1);
    Selection* sel2 = *(Selection**)((char*)r2 + 0x104);
    unsigned int eax = *(unsigned int*)((char*)sel2 + 4);
    if (eax > *(unsigned int*)((char*)sel2 + 8)) {
        _invalid_parameter_noinfo();
        eax = *(unsigned int*)((char*)sel2 + 4);
    }

    ((void (__cdecl*)(void*, void*, int, void*, void*, void*, void*))0x55f400)(
        (void*)0x55f460,
        (void*)0x55f460,
        ebp,
        sel1,
        (void*)eax,
        sel2,
        (void*)&local);

    void* b = this->field20;
    int result;
    if (b) {
        result = ((int (__thiscall*)(void*))0x55a920)(b);
    } else {
        result = 0;
    }

    ((void (__thiscall*)(int, int))0x58c810)(result, 8);

    void* esi = *(void**)((char*)dataState + 0x18);
    ((void (__thiscall*)(void*, int))0x4108b0)(esi, -1);

    void** vtbl = *(void***)esi;
    void (*fn)(void*) = (void (*)(void*))vtbl[1];
    *(int*)((char*)esi + 4) = -1;
    fn(esi);
}
