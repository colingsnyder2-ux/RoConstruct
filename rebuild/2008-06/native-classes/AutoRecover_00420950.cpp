// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: unnamed getter returning the dword at offset 0x6c of the object.
struct Obj_00420950 {
    char pad[0x6c];
    int field_6c;
};

extern "C" int __fastcall fn_00420950(Obj_00420950* self, int unusedEdx)
{
    return self->field_6c;
}
