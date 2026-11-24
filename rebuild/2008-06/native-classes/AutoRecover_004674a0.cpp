// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: object with a vtable; slot 5 (+0x14) is a bool(int key) query (e.g. isKeyDown).
struct KeyQuery {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual bool isKeyDown(int key);
};

extern "C" bool __fastcall fn_004674a0(KeyQuery* self, int unusedEdx)
{
    return self->isKeyDown(0x77) || self->isKeyDown(0x73) ||
           self->isKeyDown(0x61) || self->isKeyDown(0x64) ||
           self->isKeyDown(0x111) || self->isKeyDown(0x112) ||
           self->isKeyDown(0x114) || self->isKeyDown(0x113);
}
