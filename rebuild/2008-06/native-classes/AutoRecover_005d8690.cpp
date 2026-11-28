// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00802890[];
extern "C" char g_00936908[];
extern "C" char g_009534e0[];
// INFERRED: target is a member of an unnamed class; layout taken from disassembly and analog.
extern "C" void* __cdecl __RTDynamicCast(
    void*, long, void*, void*, int);

struct Local_005d8690_Container {
    unsigned char padding[16];
    void** finish;
};

struct Local_005d8690_Proxy {
    Local_005d8690_Container* container;
};

struct Local_005d8690_Iterator {
    Local_005d8690_Proxy* proxy;
    void** position;
};

struct Local_005d8690_Self {
    unsigned char padding0[0x1ec];
    Local_005d8690_Proxy* proxy;
    unsigned char padding1[8];
    void** first;
    void** last;
};

extern "C" void* __fastcall fn_005d8690(Local_005d8690_Self* self, int unusedEdx)
{
    void (__cdecl *invalid)() =
        *reinterpret_cast<void (__cdecl **)()>(g_00802890);

    Local_005d8690_Iterator finish;
    finish.position = self->last;
    if (self->first > finish.position)
        invalid();

    void** current = self->first;
    finish.proxy = self->proxy;
    if (current > self->last)
        invalid();

    Local_005d8690_Proxy* currentProxy = self->proxy;
    for (;;) {
        if (!currentProxy || currentProxy != finish.proxy)
            invalid();

        if (current == finish.position)
            return 0;

        if (!currentProxy)
            invalid();

        Local_005d8690_Container* container =
            currentProxy ? currentProxy->container : 0;
        if (current >= container->finish)
            invalid();

        void* result = __RTDynamicCast(
            *current, 0,
            reinterpret_cast<void*>(g_00936908),
            reinterpret_cast<void*>(g_009534e0), 0);

        if (result)
            return result;

        if (!currentProxy)
            invalid();

        container = currentProxy ? currentProxy->container : 0;
        if (current >= container->finish)
            invalid();

        ++current;
    }
}
