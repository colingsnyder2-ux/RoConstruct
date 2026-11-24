// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: global G3D::Table<std::string,int> instance at 0x9336b0; symbol name is a placeholder.
extern "C" char dat_009336b0[];

// G3D::Table<std::string,int>::containsKey (__thiscall, one stack arg, callee pops)
extern "C" bool __fastcall fn_00470600(void* self, int unusedEdx, const void* key);

extern "C" bool fn_00471060(const void* key)
{
    return fn_00470600(dat_009336b0, 0, key);
}
