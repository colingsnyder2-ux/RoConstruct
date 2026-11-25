// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: this looks like boost::iostreams stream_buffer<basic_null_device<char,output>>
// close-style code. The function calls vtable slot 15 (+0x3c) with 1, then with 2,
// each inside try/catch(...) { }. It then clears a flag byte at +0x44 and zeroes the
// dword at +0x58. The class layout below is a guess.
struct NullStreamBuf
{
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void close_impl(int which); // vtable + 0x3c

    char pad[0x44 - sizeof(void*)];
    volatile char flag;     // +0x44
    char pad2[0x58 - 0x45];
    int field58;            // +0x58
};

extern "C" void __fastcall fn_005f3d80(NullStreamBuf* self, int unusedEdx)
{
    // INFERRED: two independent try/catch(...) blocks, then state reset
    try
    {
        self->close_impl(1);
    }
    catch (...)
    {
    }
    try
    {
        self->close_impl(2);
    }
    catch (...)
    {
    }
    if (self->flag)
        self->flag = 0;
    self->field58 = 0;
}
