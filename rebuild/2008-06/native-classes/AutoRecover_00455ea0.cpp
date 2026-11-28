// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: RBX::ServiceProvider::newIndex() is a static member (SAIXZ, no this), so a plain cdecl extern stands in for it.
// The header 'v8datamodel/ServiceProvider.h' does not exist in native-headers, so I declare it directly.
extern "C" unsigned int fn_00572690();

// INFERRED: function-local static initialized once with ServiceProvider::newIndex()
extern "C" unsigned int fn_00455ea0()
{
    static unsigned int value = fn_00572690();
    return value;
}
