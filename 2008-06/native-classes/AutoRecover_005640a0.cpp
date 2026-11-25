// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: vtable-slots-only object (0xc8 bytes). Target is __thiscall (ecx) and tail-jumps to 0x563b40, so the "cdecl" ABI guess comes from the jmp. A member function matches the server-verified analog.
struct Local_005640a0
{
    unsigned long data[50];
    void fn_005640a0();
    void fn_00563b40();
};

void Local_005640a0::fn_005640a0()
{
    data[0] = 0x82e2ac;
    data[4] = 0x82e29c;
    data[5] = 0x82e294;
    data[8] = 0x82e28c;
    data[9] = 0x82e27c;
    data[17] = 0x82e26c;
    data[25] = 0x82e25c;
    data[33] = 0x82e24c;
    data[41] = 0x82e23c;
    data[49] = 0x82e22c;
    *(unsigned long*)0x96c318 = 0;
    fn_00563b40();
}
