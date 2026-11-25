// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: this looks like a destructor-like routine that resets the vtable pointer and restores a GDI object via SelectObject(hdc, hobj)
struct GdiSelectGuard {
    void* field0;
    void* field4;
    void* field8;
};

// INFERRED: 0x85a488 is the vtable of the base class this object is reset to; its real name is unknown.
extern "C" char g_0085a488[];

extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* h);

extern "C" void __fastcall fn_006f6a30(GdiSelectGuard* self, int unusedEdx)
{
    void* p8 = self->field8;
    self->field0 = (void*)g_0085a488;
    void* p4 = self->field4;
    SelectObject(p4, p8);
}
