// from server: 60% by colin
// roc 2007-08 005241f0  unit: G3D::Line  size: 64 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005241f0
//
// 005241f0  1000                 adc byte ptr [eax], al
// 005241f2  d95c2438             fstp dword ptr [esp + 0x38]
// 005241f6  d9442438             fld dword ptr [esp + 0x38]
// 005241fa  8b442434             mov eax, dword ptr [esp + 0x34]
// 005241fe  d95c2438             fstp dword ptr [esp + 0x38]
// 00524202  d90424               fld dword ptr [esp]
// 00524205  d9442438             fld dword ptr [esp + 0x38]
// 00524209  d9c0                 fld st(0)
// 0052420b  defa                 fdivp st(2)
// 0052420d  d9c9                 fxch st(1)
// 0052420f  d918                 fstp dword ptr [eax]
// 00524211  d9442404             fld dword ptr [esp + 4]
// 00524215  d8f1                 fdiv st(1)
// 00524217  d95804               fstp dword ptr [eax + 4]
// 0052421a  d9442408             fld dword ptr [esp + 8]
// 0052421e  d8f1                 fdiv st(1)
// 00524220  d95808               fstp dword ptr [eax + 8]
// 00524223  d87c240c             fdivr dword ptr [esp + 0xc]
// 00524227  d9580c               fstp dword ptr [eax + 0xc]
// 0052422a  83c430               add esp, 0x30
// 0052422d  c20c00               ret 0xc

struct Vector3d {
    float x;
    float y;
    float z;
};

struct Line {
    Vector3d mP1;
    Vector3d mP2;
    void func(float a, float b, float c, float d, Vector3d* out);
};

void Line::func(float a, float b, float c, float d, Vector3d* out)
{
    float t = d / a;
    out->x = b / a;
    out->y = c / a;
    out->z = t;
}
