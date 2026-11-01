// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005fadd0  unit: UString_sink::?$stream_buffer  size: 35 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005fadd0
//
// 005fadd0  51                   push ecx
// 005fadd1  8b4110               mov eax, dword ptr [ecx + 0x10]
// 005fadd4  8b4804               mov ecx, dword ptr [eax + 4]
// 005fadd7  8b5028               mov edx, dword ptr [eax + 0x28]
// 005fadda  8d0c49               lea ecx, [ecx + ecx*2]
// 005faddd  8d444a04             lea eax, [edx + ecx*2 + 4]
// 005fade1  890424               mov dword ptr [esp], eax
// 005fade4  db0424               fild dword ptr [esp]
// 005fade7  d9fa                 fsqrt 
// 005fade9  d9fa                 fsqrt 
// 005fadeb  e8006a0a00           call 0x6a17f0
// 005fadf0  40                   inc eax
// 005fadf1  59                   pop ecx
// 005fadf2  c3                   ret 

#pragma float_control(precise, off)

extern "C" double __cdecl sqrt(double);
#pragma intrinsic(sqrt)

struct Data {
    char reserved0[4];
    int count;
    char reserved1[0x20];
    int value;
};

struct S {
    char reserved[0x14];
    Data* data;
    int f();
};

int S::f()
{
    return (int)sqrt(sqrt((double)(data->count * 6 + data->value + 4))) + 1;
}
