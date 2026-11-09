// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /Od /Ob1 /GS- /MT
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char *fileName);

unsigned long fileAttributes(const char *fileName)
{
    return GetFileAttributesA(fileName);
}
