// from server: 100% by intel
// roc 2012-06 008275f0  unit: RBX::$01::?$SurfaceDescriptor  size: 36 bytes
// from server: 55% by colin (header only)
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE

struct Vector3 { float x, y, z; Vector3() {} Vector3(float a, float b, float c) : x(a), y(b), z(c) {} };

Vector3 func_008275f0(const Vector3& v)
{
    return Vector3(-v.x, v.z, v.y);
}
