// from server: 100% by Xemicl
// roc 2012-06 007bd810  unit: RBX::Geometry  size: 127 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 007bd810
//
// 007bd810  64a100000000         mov eax, dword ptr fs:[0]
// 007bd816  6aff                 push -1
// 007bd818  682e7bac00           push 0xac7b2e
// 007bd81d  50                   push eax
// 007bd81e  b801000000           mov eax, 1
// 007bd823  64892500000000       mov dword ptr fs:[0], esp
// 007bd82a  8405c4b5e400         test byte ptr [0xe4b5c4], al
// 007bd830  754a                 jne 0x7bd87c
// 007bd832  0905c4b5e400         or dword ptr [0xe4b5c4], eax
// 007bd838  d9e8                 fld1 
// 007bd83a  83ec24               sub esp, 0x24
// 007bd83d  d9542420             fst dword ptr [esp + 0x20]
// 007bd841  d9ee                 fldz 
// 007bd843  b9a0b5e400           mov ecx, 0xe4b5a0
// 007bd848  d954241c             fst dword ptr [esp + 0x1c]
// 007bd84c  c744242c00000000     mov dword ptr [esp + 0x2c], 0
// 007bd854  d9542418             fst dword ptr [esp + 0x18]
// 007bd858  d9542414             fst dword ptr [esp + 0x14]
// 007bd85c  d9542410             fst dword ptr [esp + 0x10]
// 007bd860  d9c9                 fxch st(1)
// 007bd862  d95c240c             fstp dword ptr [esp + 0xc]
// 007bd866  d9542408             fst dword ptr [esp + 8]
// 007bd86a  d905b8abb500         fld dword ptr [0xb5abb8]
// 007bd870  d95c2404             fstp dword ptr [esp + 4]
// 007bd874  d91c24               fstp dword ptr [esp]
// 007bd877  e834fbe6ff           call 0x62d3b0
// 007bd87c  8b0c24               mov ecx, dword ptr [esp]
// 007bd87f  b8a0b5e400           mov eax, 0xe4b5a0
// 007bd884  64890d00000000       mov dword ptr fs:[0], ecx
// 007bd88b  83c40c               add esp, 0xc
// 007bd88e  c3                   ret 
// copied from an identical function in another client (function ?getMatrix@ns_ROCX000001@@YAABUMatrix@1@XZ)

namespace ns_ROCX000001 {
struct Matrix
{
    float values[9];
    Matrix(float, float, float, float, float, float, float, float, float);
};

const Matrix& getMatrix()
{
    static Matrix value(
        0.0f, -1.0f, 0.0f,
        1.0f,  0.0f, 0.0f,
        0.0f,  0.0f, 1.0f
    );
    return value;
}
}
