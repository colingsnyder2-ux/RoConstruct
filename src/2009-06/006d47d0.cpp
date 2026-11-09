// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00614560  unit: RBX::RevoluteLink  size: 113 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00614560
//
// 00614560  83ec4c               sub esp, 0x4c
// 00614563  56                   push esi
// 00614564  8bf1                 mov esi, ecx
// 00614566  d9868c000000         fld dword ptr [esi + 0x8c]
// 0061456c  d95c2404             fstp dword ptr [esp + 4]
// 00614570  e8eb4df8ff           call 0x599360
// 00614575  8d4668               lea eax, [esi + 0x68]
// 00614578  50                   push eax
// 00614579  8d4c240c             lea ecx, [esp + 0xc]
// 0061457d  e89eecefff           call 0x513220
// 00614582  8d8e94000000         lea ecx, [esi + 0x94]
// 00614588  51                   push ecx
// 00614589  8d54240c             lea edx, [esp + 0xc]
// 0061458d  52                   push edx
// 0061458e  8d442434             lea eax, [esp + 0x34]
// 00614592  50                   push eax
// 00614593  e8d895fcff           call 0x5ddb70
// 00614598  83c40c               add esp, 0xc
// 0061459b  8bce                 mov ecx, esi
// 0061459d  e8be4df8ff           call 0x599360
// 006145a2  d9442404             fld dword ptr [esp + 4]
// 006145a6  8b542458             mov edx, dword ptr [esp + 0x58]
// 006145aa  51                   push ecx
// 006145ab  d91c24               fstp dword ptr [esp]
// 006145ae  8d4c2430             lea ecx, [esp + 0x30]
// 006145b2  51                   push ecx
// 006145b3  52                   push edx
// 006145b4  81c6b8000000         add esi, 0xb8
// 006145ba  56                   push esi
// 006145bb  8b742464             mov esi, dword ptr [esp + 0x64]
// 006145bf  56                   push esi
// 006145c0  e8ab94fcff           call 0x5dda70
// 006145c5  83c414               add esp, 0x14
// 006145c8  8bc6                 mov eax, esi
// 006145ca  5e                   pop esi
// 006145cb  83c44c               add esp, 0x4c
// 006145ce  c20800               ret 8

struct Matrix {
    float data[9];
    Matrix(const Matrix&);
    Matrix() {}
};

struct Result {
    float data[12];
};

extern void __cdecl combine(Matrix*, const Matrix*, const Matrix*);
extern void __cdecl evaluate(Result*, const Result&, const Result&, const Matrix&, float);

struct S {
    char reserved0[0x70];
    Matrix rotation;
    float angle;
    char reserved1[4];
    Matrix adjustment;
    Result frame;

    const void* get();
    Result* f(Result*, const Result&);
};

Result* S::f(Result* output, const Result& value)
{
    float savedAngle = angle;
    get();
    Matrix local(rotation);
    Matrix adjusted;
    combine(&adjusted, &local, &adjustment);
    get();
    evaluate(output, frame, value, adjusted, savedAngle);
    return output;
}
