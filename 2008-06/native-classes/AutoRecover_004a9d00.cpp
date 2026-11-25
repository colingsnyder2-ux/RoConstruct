// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: object layout unknown; only vtable slots at the offsets the code writes are modeled.
// INFERRED: original is a __thiscall member (ecx = this, plain ret), so it is modeled as a member function, not a free __fastcall.
struct Local_004a9d00
{
    unsigned long data[50];
    void fn_004a9d00();
    void fn_004a9b70();
};

void Local_004a9d00::fn_004a9d00()
{
    data[0] = 0x824074;
    data[4] = 0x824068;
    data[5] = 0x824060;
    data[8] = 0x824058;
    data[9] = 0x824048;
    data[17] = 0x824038;
    data[25] = 0x824028;
    data[33] = 0x824018;
    data[41] = 0x824008;
    data[49] = 0x823ff8;
    *(unsigned long*)0x9706d0 = 0;
    fn_004a9b70();
}
