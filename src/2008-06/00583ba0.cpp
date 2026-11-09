// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_modelfrontvolatileb61dda8044e2a937.cpp

// Candidate translation unit (score above; library headers required).
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 88% by king_originala
// roc 2008-06 00583ba0  unit: RBX::ModelInstance  size: 234 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00583ba0
//
// 00583ba0  81eca8000000         sub esp, 0xa8
// 00583ba6  55                   push ebp
// 00583ba7  8be9                 mov ebp, ecx
// 00583ba9  83bde001000000       cmp dword ptr [ebp + 0x1e0], 0
// 00583bb0  0f84ca000000         je 0x583c80
// 00583bb6  53                   push ebx
// 00583bb7  56                   push esi
// 00583bb8  57                   push edi
// 00583bb9  8d4c2440             lea ecx, [esp + 0x40]
// 00583bbd  e80e47efff           call 0x4782d0
// 00583bc2  8b8424bc000000       mov eax, dword ptr [esp + 0xbc]
// 00583bc9  50                   push eax
// 00583bca  8d4c2444             lea ecx, [esp + 0x44]
// 00583bce  e84d52f9ff           call 0x518e20
// 00583bd3  bb01000000           mov ebx, 1
// 00583bd8  841d50f09600         test byte ptr [0x96f050], bl
// 00583bde  751a                 jne 0x583bfa
// 00583be0  d9ee                 fldz 
// 00583be2  091d50f09600         or dword ptr [0x96f050], ebx
// 00583be8  d91544f09600         fst dword ptr [0x96f044]
// 00583bee  d91548f09600         fst dword ptr [0x96f048]
// 00583bf4  d91d4cf09600         fstp dword ptr [0x96f04c]
// 00583bfa  8d4c2440             lea ecx, [esp + 0x40]
// 00583bfe  51                   push ecx
// 00583bff  8b8de0010000         mov ecx, dword ptr [ebp + 0x1e0]
// 00583c05  8d942498000000       lea edx, [esp + 0x98]
// 00583c0c  52                   push edx
// 00583c0d  8d442478             lea eax, [esp + 0x78]
// 00583c11  50                   push eax
// 00583c12  e899500100           call 0x598cb0
// 00583c17  8bc8                 mov ecx, eax
// 00583c19  e8f2f8f8ff           call 0x513510
// 00583c1e  8bc8                 mov ecx, eax
// 00583c20  e82bf7f8ff           call 0x513350
// 00583c25  50                   push eax
// 00583c26  8d4c2414             lea ecx, [esp + 0x14]
// 00583c2a  e8f1f5f8ff           call 0x513220
// 00583c2f  d90544f09600         fld dword ptr [0x96f044]
// 00583c35  d9542434             fst dword ptr [esp + 0x34]
// 00583c39  8d85b0010000         lea eax, [ebp + 0x1b0]
// 00583c3f  d90548f09600         fld dword ptr [0x96f048]
// 00583c45  b909000000           mov ecx, 9
// 00583c4a  d9542438             fst dword ptr [esp + 0x38]
// 00583c4e  8d742410             lea esi, [esp + 0x10]
// 00583c52  d9054cf09600         fld dword ptr [0x96f04c]
// 00583c58  8bf8                 mov edi, eax
// 00583c5a  d954243c             fst dword ptr [esp + 0x3c]
// 00583c5e  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 00583c60  d9ca                 fxch st(2)
// 00583c62  d95824               fstp dword ptr [eax + 0x24]
// 00583c65  d95828               fstp dword ptr [eax + 0x28]
// 00583c68  d9582c               fstp dword ptr [eax + 0x2c]
// 00583c6b  889d40020000         mov byte ptr [ebp + 0x240], bl
// 00583c71  5f                   pop edi
// 00583c72  889d70020000         mov byte ptr [ebp + 0x270], bl
// 00583c78  5e                   pop esi
// 00583c79  889d0c020000         mov byte ptr [ebp + 0x20c], bl
// 00583c7f  5b                   pop ebx
// 00583c80  5d                   pop ebp
// 00583c81  81c4a8000000         add esp, 0xa8
// 00583c87  c20400               ret 4

#pragma float_control(precise, off)
#include <G3D/CoordinateFrame.h>
typedef G3D::Matrix3 Matrix;
typedef G3D::Vector3 Vec;
typedef G3D::CoordinateFrame Result;
struct Frame {
    Matrix rotation;
    float position[3];
    Frame();
    void set(int);
};

struct Source {
    const Frame& getFrame() const;
};

extern Vec zero;
extern unsigned int zeroFlags;

struct Model {
    char pad0[0x1b0];
    Result transform;
    Source* source;
    char pad1[0x28];
    volatile unsigned char dirty0;
    char pad2[0x33];
    volatile unsigned char dirty1;
    char pad3[0x2f];
    volatile unsigned char dirty2;

    void update(int);
};

void Model::update(int value)
{
    if (source) {
        Frame frame;
        frame.set(value);

        if (!(zeroFlags & 1)) {
            zeroFlags |= 1;
            zero.x = 0.0f;
            zero.y = 0.0f;
            zero.z = 0.0f;
        }

        Result result(source->getFrame().rotation.transpose() * frame.rotation,zero);

        transform = result;

        dirty1 = 1;
        dirty2 = 1;
        dirty0 = 1;
    }
}
