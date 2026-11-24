// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

// INFERRED: unnamed thiscall member (this in ecx, float[4] out on stack); signed 16-bit fields at +0x1c8..+0x1ce widened to float.
extern "C" void __fastcall fn_00489910(char* self, int unusedEdx, float* out)
{
    out[0] = (float)*(short*)(self + 0x1c8);
    out[1] = (float)*(short*)(self + 0x1ca);
    out[2] = (float)*(short*)(self + 0x1cc);
    out[3] = (float)*(short*)(self + 0x1ce);
}
