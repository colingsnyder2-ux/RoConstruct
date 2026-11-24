// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS

extern "C" int __fastcall fn_004dd7d0(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004dd360(void* self, int unusedEdx, int a1);
extern "C" int __fastcall fn_004de250(void* self, int unusedEdx, int a1);
extern "C" int fn_004de1d0(int a1, int a2, int a3);

// INFERRED: builds the 8 corner vertices and 12 triangles (36 indices) of a box
// from half-extents. The disassembly also sets edi (4,1,2,4,5,0) and uses esi
// before each fn_004de1d0 call. That is a register-based convention which cannot
// be reproduced from the declared signature, so those values are not passed.
extern "C" void fn_004e3570(const float* size, void* vertexBuf, void* indexBuf)
{
    float v[3];

    fn_004dd7d0(vertexBuf, 0, 8);
    fn_004dd360(indexBuf, 0, 0x24);

    v[0] = -size[0]; v[1] = -size[1]; v[2] = -size[2];
    fn_004de250(vertexBuf, 0, (int)v);

    v[0] = -size[0]; v[1] = -size[1]; v[2] = size[2];
    fn_004de250(vertexBuf, 0, (int)v);

    v[0] = -size[0]; v[1] = size[1]; v[2] = -size[2];
    fn_004de250(vertexBuf, 0, (int)v);

    v[0] = -size[0]; v[1] = size[1]; v[2] = size[2];
    fn_004de250(vertexBuf, 0, (int)v);

    v[0] = size[0]; v[1] = -size[1]; v[2] = -size[2];
    fn_004de250(vertexBuf, 0, (int)v);

    v[0] = size[0]; v[1] = -size[1]; v[2] = size[2];
    fn_004de250(vertexBuf, 0, (int)v);

    v[0] = size[0]; v[1] = size[1]; v[2] = -size[2];
    fn_004de250(vertexBuf, 0, (int)v);

    v[0] = size[0]; v[1] = size[1]; v[2] = size[2];
    fn_004de250(vertexBuf, 0, (int)v);

    fn_004de1d0(7, 5, 6);
    fn_004de1d0(2, 0, 3);
    fn_004de1d0(7, 6, 3);
    fn_004de1d0(1, 0, 5);
    fn_004de1d0(3, 1, 7);
    fn_004de1d0(6, 4, 2);
}
