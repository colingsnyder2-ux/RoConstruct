// from server: 26% by colin
struct IDataState;

struct Verb {
    virtual void doIt(IDataState*);
};

struct EditSelectionVerb : Verb {
    void doIt(IDataState*);
};

struct CanNotSelectCommand : EditSelectionVerb {
    void doIt(IDataState*);
};

extern "C" void __stdcall _invalid_parameter_noinfo();

void CanNotSelectCommand::doIt(IDataState* dataState)
{
    char* base = (char*)this;
    void* p20 = *(void**)(base + 0x20);
    ((void (__thiscall*)(void*))0x55e290)(p20);

    int v;
    void* q = *(void**)(base + 0x20);
    if (q) {
        v = ((int (__thiscall*)(void*))0x5618e0)(q);
    } else {
        v = 0;
    }

    char* edi = base + 0x14;
    ((void (__thiscall*)(char*, int))0x562300)(edi, 1);
    void* eax = (void*)0;
    (void)eax;

    ((void (__thiscall*)(char*, int))0x562300)(edi, 1);

    ((void (__cdecl*)(void*, void*, void*, void*, void*))0x55f3b0)(
        (void*)0, (void*)0, (void*)0, (void*)0, (void*)0x55e8a0);

    void* dm = *(void**)((char*)dataState + 0xec);
    ((void (__thiscall*)(void*))0x5330f0)(dm);

    ((void (__thiscall*)(IDataState*, int))0x4108b0)(dataState, -1);

    void** vt = *(void***)dataState;
    void* fn = vt[1];
    *(int*)((char*)dataState + 4) = -1;
    ((void (__thiscall*)(IDataState*, int))fn)(dataState, 1);
}
