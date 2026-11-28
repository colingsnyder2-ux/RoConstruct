// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: __RTDynamicCast(value, 0, srcTypeDescriptor 0x92907c, targetTypeDescriptor 0x92ac78, isReference 0); result != 0
extern "C" char g_0092907c[];
extern "C" char g_0092ac4c[];

extern "C" void* __cdecl __RTDynamicCast(void* inptr, long vfDelta, void* srcType, void* targetType, int isReference);

extern "C" int __stdcall fn_00442fc0(void* value)
{
    return __RTDynamicCast(value, 0, g_0092907c, g_0092ac4c, 0) != 0;
}
