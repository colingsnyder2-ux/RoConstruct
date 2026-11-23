// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
extern "C" int __fastcall fn_00503100(void* self, int unusedEdx, int a1); // INFERRED: G3D Array<const void*>::resize
extern "C" int __fastcall fn_004806b0(void* self, int unusedEdx, int a1); // INFERRED: G3D Array resize
extern "C" int __fastcall fn_0054bda0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_0054ae90(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_0054ad30(void* self, int unusedEdx);

// INFERRED: unknown globals (static objects) in the original image
extern "C" char g_009738ac[];
extern "C" char g_009738c4[];
extern "C" char g_009738f0[];
extern "C" char g_009738fc[];
extern "C" char g_00973928[];
extern "C" char g_00973934[];

extern "C" void fn_00547f60()
{
    fn_00503100(g_009738f0, 0, 1);
    fn_00503100(g_009738fc, 0, 1);
    fn_0054bda0(g_00973934, 0, 1);
    fn_00503100(g_00973928, 0, 1);
    fn_004806b0(g_009738c4, 0, 1);
    *(int*)fn_0054ae90(g_009738c4, 0, 0) = 1;
    fn_0054ad30(g_009738ac, 0);
}
