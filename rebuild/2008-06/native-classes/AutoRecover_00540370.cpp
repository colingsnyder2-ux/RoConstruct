// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: object at +8 is a G3D::ReferenceCountedPointer<VertexAndPixelShader>; the callee is its private zeroPointer(), called directly on this+8.
struct fn_00540370_Object {
    char pad[8];
};

extern "C" void __fastcall fn_00502a70(void* self, int unusedEdx);

extern "C" void __fastcall fn_00540370(fn_00540370_Object* self, int unusedEdx)
{
    fn_00502a70((char*)self + 8, 0);
}
