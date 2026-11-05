// from server: 100% by Espeon
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// from server: 90% by colin
// roc 2008-06 004e5f80  unit: RBX::Block  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004e5f80
//
// 004e5f80  83b9d400000000       cmp dword ptr [ecx + 0xd4], 0
// 004e5f87  755e                 jne 0x4e5fe7
// 004e5f89  8b89bc000000         mov ecx, dword ptr [ecx + 0xbc]
// 004e5f8f  83b9dc01000001       cmp dword ptr [ecx + 0x1dc], 1
// 004e5f96  754f                 jne 0x4e5fe7
// 004e5f98  e8332d0b00           call 0x598cd0
// 004e5f9d  d900                 fld dword ptr [eax]
// 004e5f9f  d94004               fld dword ptr [eax + 4]
// 004e5fa2  d94008               fld dword ptr [eax + 8]
// 004e5fa5  d9ca                 fxch st(2)
// 004e5fa7  d9e1                 fabs 
// 004e5fa9  d9c9                 fxch st(1)
// 004e5fab  d9e1                 fabs 
// 004e5fad  d9ca                 fxch st(2)
// 004e5faf  d9e1                 fabs 
// 004e5fb1  d9c9                 fxch st(1)
// 004e5fb3  d8d2                 fcom st(2)
// 004e5fb5  dfe0                 fnstsw ax
// 004e5fb7  f6c441               test ah, 0x41
// 004e5fba  7504                 jne 0x4e5fc0
// 004e5fbc  ddda                 fstp st(2)
// 004e5fbe  eb02                 jmp 0x4e5fc2
// 004e5fc0  ddd8                 fstp st(0)
// 004e5fc2  d8d1                 fcom st(1)
// 004e5fc4  dfe0                 fnstsw ax
// 004e5fc6  f6c405               test ah, 5
// 004e5fc9  7a04                 jp 0x4e5fcf
// 004e5fcb  ddd8                 fstp st(0)
// 004e5fcd  eb02                 jmp 0x4e5fd1
// 004e5fcf  ddd9                 fstp st(1)
// 004e5fd1  d81d884d8700         fcomp dword ptr [0x874d88]
// 004e5fd7  dfe0                 fnstsw ax
// 004e5fd9  f6c405               test ah, 5
// 004e5fdc  7a06                 jp 0x4e5fe4
// 004e5fde  b801000000           mov eax, 1
// 004e5fe3  c3                   ret 
// 004e5fe4  33c0                 xor eax, eax
// 004e5fe6  c3                   ret 
// 004e5fe7  32c0                 xor al, al
// 004e5fe9  c3                   ret 

// from server: 80% by colin
// roc 2008-06 004e5f80  unit: RBX::Block  size: 106 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 004e5f80
//
// 004e5f80  83b9d400000000       cmp dword ptr [ecx + 0xd4], 0
// 004e5f87  755e                 jne 0x4e5fe7
// 004e5f89  8b89bc000000         mov ecx, dword ptr [ecx + 0xbc]
// 004e5f8f  83b9dc01000001       cmp dword ptr [ecx + 0x1dc], 1
// 004e5f96  754f                 jne 0x4e5fe7
// 004e5f98  e8332d0b00           call 0x598cd0
// 004e5f9d  d900                 fld dword ptr [eax]
// 004e5f9f  d94004               fld dword ptr [eax + 4]
// 004e5fa2  d94008               fld dword ptr [eax + 8]
// 004e5fa5  d9ca                 fxch st(2)
// 004e5fa7  d9e1                 fabs 
// 004e5fa9  d9c9                 fxch st(1)
// 004e5fab  d9e1                 fabs 
// 004e5fad  d9ca                 fxch st(2)
// 004e5faf  d9e1                 fabs 
// 004e5fb1  d9c9                 fxch st(1)
// 004e5fb3  d8d2                 fcom st(2)
// 004e5fb5  dfe0                 fnstsw ax
// 004e5fb7  f6c441               test ah, 0x41
// 004e5fba  7504                 jne 0x4e5fc0
// 004e5fbc  ddda                 fstp st(2)
// 004e5fbe  eb02                 jmp 0x4e5fc2
// 004e5fc0  ddd8                 fstp st(0)
// 004e5fc2  d8d1                 fcom st(1)
// 004e5fc4  dfe0                 fnstsw ax
// 004e5fc6  f6c405               test ah, 5
// 004e5fc9  7a04                 jp 0x4e5fcf
// 004e5fcb  ddd8                 fstp st(0)
// 004e5fcd  eb02                 jmp 0x4e5fd1
// 004e5fcf  ddd9                 fstp st(1)
// 004e5fd1  d81d884d8700         fcomp dword ptr [0x874d88]
// 004e5fd7  dfe0                 fnstsw ax
// 004e5fd9  f6c405               test ah, 5
// 004e5fdc  7a06                 jp 0x4e5fe4
// 004e5fde  b801000000           mov eax, 1
// 004e5fe3  c3                   ret 
// 004e5fe4  33c0                 xor eax, eax
// 004e5fe6  c3                   ret 
// 004e5fe7  32c0                 xor al, al
// 004e5fe9  c3                   ret 
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)

extern "C" double __cdecl fabs(double);
#pragma intrinsic(fabs)

extern const float threshold;

struct S_func_00598cd0 {
    char pad0[708];
    int m_x;
    int f();
};

struct S {
    char pad0[188];
    S_func_00598cd0* object;
    char pad1[20];
    int state;
    bool f();
};

bool S::f()
{
    if (state == 0 &&
        *reinterpret_cast<int*>(reinterpret_cast<char*>(object) + 476) == 1)
    {
        const float* v = reinterpret_cast<const float*>(object->f());
        float x = v[0];
        float y = v[1];
        float z = v[2];
        _ReadWriteBarrier();

        x = fabs(x);
        y = fabs(y);
        z = fabs(z);

        float m = x > y ? x : y;
        return (z < m ? m : z) < threshold;
    }
    return false;
}
