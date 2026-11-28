// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: 0x802890 is the import slot for MSVCR90!_invalid_parameter_noinfo,
// modelled as a function pointer variable, as in the byte-exact analog.
extern "C" void (__cdecl *g_00802890)();

// INFERRED: the two type descriptors passed to ___RTDynamicCast (source and target types).
extern "C" char g_0092907c;
extern "C" char g_00951950;

// ___RTDynamicCast
extern "C" void* __cdecl fn_006a17c6(void*, long, const void*, const void*, int);

struct Container;

struct Proxy {
    Container* container;
};

struct Container {
    Proxy* proxy;
    unsigned char padding[8];
    unsigned char* first;
    unsigned char* last;
};

struct Service {
    unsigned char padding[0x108];
    Container* items;
};

extern "C" void* __fastcall fn_005cfc30(Service* self, int unusedEdx)
{
    Container* c = self->items;
    if (c) {
        unsigned char* finish = c->last;
        void (__cdecl *report)() = g_00802890;

        if (c->first > finish)
            report();
        Proxy* finishOwner = c->proxy;

        c = self->items;
        unsigned char* current = c->first;
        if (current > c->last)
            report();
        Proxy* owner = c->proxy;

        for (;;) {
            if (!owner || owner != finishOwner)
                report();

            if (current == finish)
                break;

            if (!owner)
                report();
            Container* range = owner ? owner->container : 0;
            if (current >= range->last)
                report();

            void* result = fn_006a17c6(
                *reinterpret_cast<void**>(current), 0,
                &g_0092907c,
                &g_00951950, 0);
            if (result)
                return result;

            if (!owner)
                report();
            range = owner ? owner->container : 0;
            if (current >= range->last)
                report();

            current += 8;
        }
    }
    return 0;
}
