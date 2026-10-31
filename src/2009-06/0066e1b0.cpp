// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005df140  unit: RBX::Message  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005df140
//
// 005df140  b801000000           mov eax, 1
// 005df145  83ec48               sub esp, 0x48
// 005df148  8405a4289700         test byte ptr [0x9728a4], al
// 005df14e  751c                 jne 0x5df16c
// 005df150  d9ee                 fldz 
// 005df152  0905a4289700         or dword ptr [0x9728a4], eax
// 005df158  d91598289700         fst dword ptr [0x972898]
// 005df15e  d9e8                 fld1 
// 005df160  d91d9c289700         fstp dword ptr [0x97289c]
// 005df166  d91da0289700         fstp dword ptr [0x9728a0]
// 005df16c  d9442450             fld dword ptr [esp + 0x50]
// 005df170  56                   push esi
// 005df171  57                   push edi
// 005df172  51                   push ecx
// 005df173  d91c24               fstp dword ptr [esp]
// 005df176  8d44240c             lea eax, [esp + 0xc]
// 005df17a  6898289700           push 0x972898
// 005df17f  50                   push eax
// 005df180  e8fb44f3ff           call 0x513680
// 005df185  8b7c2460             mov edi, dword ptr [esp + 0x60]
// 005df189  83c40c               add esp, 0xc
// 005df18c  57                   push edi
// 005df18d  8d4c2430             lea ecx, [esp + 0x30]
// 005df191  51                   push ecx
// 005df192  8d4c2410             lea ecx, [esp + 0x10]
// 005df196  e8b541f3ff           call 0x513350
// 005df19b  b909000000           mov ecx, 9
// 005df1a0  8bf0                 mov esi, eax
// 005df1a2  f3a5                 rep movsd dword ptr es:[edi], dword ptr [esi]
// 005df1a4  5f                   pop edi
// 005df1a5  5e                   pop esi
// 005df1a6  83c448               add esp, 0x48
// 005df1a9  c3                   ret 

struct Vector3 {
    float x, y, z;
    Vector3(float, float, float);
};

Vector3::Vector3(float a, float b, float c)
    : x(a), y(b), z(c) {
}

struct Matrix3 {
    float elements[9];
    static Matrix3 __cdecl fromAxisAngle(const Vector3&, float);
    Matrix3 operator*(const Matrix3&) const;
};

void __cdecl rotate(Matrix3& matrix, float angle) {
    static const Vector3 axis(0.0f, 1.0f, 0.0f);
    Matrix3 rotation = Matrix3::fromAxisAngle(axis, angle);
    matrix = rotation * matrix;
}
