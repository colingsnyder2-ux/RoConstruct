// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: function-local static of ServiceProvider::newIndex() result; guard bit 0 at 0x97145c, value at 0x971458.
extern "C" unsigned int __cdecl fn_00572690();

extern "C" unsigned int fn_004ab470() {
    static unsigned int value = fn_00572690();
    return value;
}
