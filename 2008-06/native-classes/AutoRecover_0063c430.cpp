// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" char g_00849b9c[];   // INFERRED: unnamed global at 0x00849b9c in the original
extern "C" char g_00849bb8[];   // INFERRED: unnamed global at 0x00849bb8 in the original
extern "C" char g_00849bc0[];   // INFERRED: unnamed global at 0x00849bc0 in the original
extern "C" char g_00849bcc[];   // INFERRED: unnamed global at 0x00849bcc in the original
extern "C" char g_00849be4[];   // INFERRED: unnamed global at 0x00849be4 in the original
extern "C" char g_00849bf0[];   // INFERRED: unnamed global at 0x00849bf0 in the original
extern "C" char g_00849c00[];   // INFERRED: unnamed global at 0x00849c00 in the original
extern "C" char g_00849c0c[];   // INFERRED: unnamed global at 0x00849c0c in the original
extern "C" char g_00849c1c[];   // INFERRED: unnamed global at 0x00849c1c in the original
extern "C" char g_00849c2c[];   // INFERRED: unnamed global at 0x00849c2c in the original
extern "C" char g_00849c3c[];   // INFERRED: unnamed global at 0x00849c3c in the original
extern "C" char g_00849c4c[];   // INFERRED: unnamed global at 0x00849c4c in the original
extern "C" char g_00849c5c[];   // INFERRED: unnamed global at 0x00849c5c in the original
extern "C" char g_00849c6c[];   // INFERRED: unnamed global at 0x00849c6c in the original
extern "C" char g_00849c74[];   // INFERRED: unnamed global at 0x00849c74 in the original
extern "C" char g_00849c7c[];   // INFERRED: unnamed global at 0x00849c7c in the original
extern "C" char g_00849c8c[];   // INFERRED: unnamed global at 0x00849c8c in the original

struct Local_0063c430 {
    unsigned int words[77];
    int* offsets;
    unsigned int rest[38];
};

// INFERRED: tail-called base destructor body at 0x59b970 (thiscall, no stack args)
extern "C" void __fastcall fn_0059b970(Local_0063c430* self, int unusedEdx);

extern "C" void __fastcall fn_0063c430(Local_0063c430* self, int unusedEdx)
{
    int* table = self->offsets;
    self->words[0] = ((int)&g_00849c8c);
    self->words[4] = ((int)&g_00849c7c);
    self->words[5] = ((int)&g_00849c74);
    self->words[8] = ((int)&g_00849c6c);
    self->words[9] = ((int)&g_00849c5c);
    self->words[17] = ((int)&g_00849c4c);
    self->words[25] = ((int)&g_00849c3c);
    self->words[33] = ((int)&g_00849c2c);
    self->words[41] = ((int)&g_00849c1c);
    self->words[49] = ((int)&g_00849c0c);
    self->words[76] = ((int)&g_00849c00);
    self->rest[26] = ((int)&g_00849bf0);
    self->rest[34] = ((int)&g_00849be4);
    self->rest[37] = ((int)&g_00849bcc);

    *reinterpret_cast<unsigned int*>(
        reinterpret_cast<char*>(self) + 0x134 + table[1]) = ((int)&g_00849bc0);
    *reinterpret_cast<unsigned int*>(
        reinterpret_cast<char*>(self) + 0x134 + self->offsets[2]) = ((int)&g_00849bb8);
    *reinterpret_cast<unsigned int*>(
        reinterpret_cast<char*>(self) + 0x134 + self->offsets[3]) = ((int)&g_00849b9c);

    int displacement = self->offsets[1];
    *reinterpret_cast<int*>(
        reinterpret_cast<char*>(self) + 0x130 + displacement) =
        displacement - 0x2b8;

    displacement = self->offsets[2];
    *reinterpret_cast<int*>(
        reinterpret_cast<char*>(self) + 0x130 + displacement) =
        displacement - 0x2c0;

    displacement = self->offsets[3];
    *reinterpret_cast<int*>(
        reinterpret_cast<char*>(self) + 0x130 + displacement) =
        displacement - 0x2c8;

    fn_0059b970(self, unusedEdx);
}
