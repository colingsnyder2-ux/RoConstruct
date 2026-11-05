// from server: 100% by EspClaude
// roc 2009-06 0068b1d0  unit: G3D::VCoordinateFrame::V?$Value::?$BoundPropGetSet  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0068b1d0
//
// 0068b1d0  64a100000000         mov eax, dword ptr fs:[0]
// 0068b1d6  6aff                 push -1
// 0068b1d8  6848c38500           push 0x85c348
// 0068b1dd  50                   push eax
// 0068b1de  64892500000000       mov dword ptr fs:[0], esp
// 0068b1e5  83ec2c               sub esp, 0x2c
// 0068b1e8  833900               cmp dword ptr [ecx], 0
// 0068b1eb  7517                 jne 0x68b204
// 0068b1ed  8d4c2404             lea ecx, [esp + 4]
// 0068b1f1  e8eae2d7ff           call 0x4094e0
// 0068b1f6  50                   push eax
// 0068b1f7  c744243800000000     mov dword ptr [esp + 0x38], 0
// 0068b1ff  e85cf0d7ff           call 0x40a260
// 0068b204  d944243c             fld dword ptr [esp + 0x3c]
// 0068b208  83ec0c               sub esp, 0xc
// 0068b20b  8bc4                 mov eax, esp
// 0068b20d  d918                 fstp dword ptr [eax]
// 0068b20f  83c108               add ecx, 8
// 0068b212  d944244c             fld dword ptr [esp + 0x4c]
// 0068b216  8964240c             mov dword ptr [esp + 0xc], esp
// 0068b21a  d95804               fstp dword ptr [eax + 4]
// 0068b21d  51                   push ecx
// 0068b21e  d9442454             fld dword ptr [esp + 0x54]
// 0068b222  d95808               fstp dword ptr [eax + 8]
// 0068b225  8b41f8               mov eax, dword ptr [ecx - 8]
// 0068b228  8b4804               mov ecx, dword ptr [eax + 4]
// 0068b22b  ffd1                 call ecx
// 0068b22d  8b4c243c             mov ecx, dword ptr [esp + 0x3c]
// 0068b231  83c410               add esp, 0x10
// 0068b234  64890d00000000       mov dword ptr fs:[0], ecx
// 0068b23b  83c438               add esp, 0x38
// 0068b23e  c20c00               ret 0xc
// copied from an identical function in another client (function ?set@BoundPropGetSet@ns_ROCX000017@@QAEXUVector3@2@@Z)

namespace ns_ROCX000017 {
struct Vector3
{
    float x, y, z;

    Vector3(const Vector3& v) : x(v.x), y(v.y), z(v.z) {}
    ~Vector3() {}
};

struct CallError
{
    char data[40];

    CallError();
    ~CallError();
};

__declspec(noreturn) void __cdecl raiseCallError(const CallError&);

struct Operations
{
    void (__cdecl *unused)();
    void (__cdecl *invoke)(void*, Vector3);
};

struct BoundPropGetSet
{
    Operations* operations;
    unsigned int reserved;
    char storage[4];

    void set(Vector3 value);
};

void BoundPropGetSet::set(Vector3 value)
{
    if (!operations)
        raiseCallError(CallError());

    operations->invoke(storage, value);
}
}
