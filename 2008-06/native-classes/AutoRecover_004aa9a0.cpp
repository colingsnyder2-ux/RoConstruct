// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_004aa700[];   // INFERRED: unnamed global at 0x004aa700 in the original
extern "C" char g_00971204[];   // INFERRED: unnamed global at 0x00971204 in the original

// INFERRED: callees keep the fn_<addr> convention.
extern "C" void __cdecl fn_00557330(void *, void *);   // boost::call_once
extern "C" void * __cdecl fn_004aa6a0();               // getter
extern "C" void * __cdecl fn_0049ec80();               // classDescriptor

extern void *g_0082422c[];                             // INFERRED: vtable at 0x82422c

struct Local_004aa9a0_Owner {
    int *pointer;
    Local_004aa9a0_Owner(int *p) : pointer(p) {}
    ~Local_004aa9a0_Owner() { if (pointer) delete pointer; }
    int *release() { int *p = pointer; pointer = 0; return p; }
};

// INFERRED: getset helper at 0x4a9c50
extern Local_004aa9a0_Owner __cdecl fn_004a9c50(int, int, int, int);

struct Local_004aa9a0_S {
    unsigned char data[24];
    void *descriptor;
    int *owned;
    void *secondary;
};

// INFERRED: PropertyDescriptor ctor at 0x56c650
extern "C" void __fastcall fn_0056c650(void *self, int unusedEdx, void *creator, void *d, int a, int b, int g);

extern "C" Local_004aa9a0_S * __fastcall fn_004aa9a0(Local_004aa9a0_S *self, int unusedEdx,
                                                     int a, int b, int c, int d, int e, int f, int g)
{
    fn_00557330((void *)g_004aa700, (void *)g_00971204);
    void *desc = fn_004aa6a0();
    void *creator = fn_0049ec80();
    fn_0056c650(self, 0, creator, desc, a, b, g);
    self->descriptor = desc;
    *reinterpret_cast<void ***>(self) = g_0082422c;
    self->owned = fn_004a9c50(c, d, e, f).release();
    fn_00557330((void *)g_004aa700, (void *)g_00971204);
    self->secondary = fn_004aa6a0();
    return self;
}
