// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 0061c830  unit: RBX::Lua::LuaArguments  size: 142 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0061c830
//
// 0061c830  8b442408             mov eax, dword ptr [esp + 8]
// 0061c834  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0061c838  50                   push eax
// 0061c839  51                   push ecx
// 0061c83a  e82157ffff           call 0x611f60
// 0061c83f  8b0dac248000         mov ecx, dword ptr [0x8024ac]
// 0061c845  dd01                 fld qword ptr [ecx]
// 0061c847  83c408               add esp, 8
// 0061c84a  dde9                 fucomp st(1)
// 0061c84c  dfe0                 fnstsw ax
// 0061c84e  f6c444               test ah, 0x44
// 0061c851  7a0b                 jp 0x61c85e
// 0061c853  8b150c258000         mov edx, dword ptr [0x80250c]
// 0061c859  ddd8                 fstp st(0)
// 0061c85b  d902                 fld dword ptr [edx]
// 0061c85d  c3                   ret 
// 0061c85e  dd01                 fld qword ptr [ecx]
// 0061c860  d9e0                 fchs 
// 0061c862  dde9                 fucomp st(1)
// 0061c864  dfe0                 fnstsw ax
// 0061c866  f6c444               test ah, 0x44
// 0061c869  7a0c                 jp 0x61c877
// 0061c86b  a10c258000           mov eax, dword ptr [0x80250c]
// 0061c870  ddd8                 fstp st(0)
// 0061c872  d900                 fld dword ptr [eax]
// 0061c874  d9e0                 fchs 
// 0061c876  c3                   ret 
// 0061c877  d9ee                 fldz 
// 0061c879  d8d1                 fcom st(1)
// 0061c87b  dfe0                 fnstsw ax
// 0061c87d  f6c441               test ah, 0x41
// 0061c880  740a                 je 0x61c88c
// 0061c882  d8d9                 fcomp st(1)
// 0061c884  dfe0                 fnstsw ax
// 0061c886  f6c441               test ah, 0x41
// 0061c889  7b03                 jnp 0x61c88e
// 0061c88b  c3                   ret 
// 0061c88c  ddd8                 fstp st(0)
// 0061c88e  dd0588448400         fld qword ptr [0x844488]
// 0061c894  d8d9                 fcomp st(1)
// 0061c896  dfe0                 fnstsw ax
// 0061c898  f6c405               test ah, 5
// 0061c89b  7a09                 jp 0x61c8a6
// 0061c89d  ddd8                 fstp st(0)
// 0061c89f  d905247a8200         fld dword ptr [0x827a24]
// 0061c8a5  c3                   ret 
// 0061c8a6  dd0580448400         fld qword ptr [0x844480]
// 0061c8ac  d8d9                 fcomp st(1)
// 0061c8ae  dfe0                 fnstsw ax
// 0061c8b0  f6c441               test ah, 0x41
// 0061c8b3  7508                 jne 0x61c8bd
// 0061c8b5  ddd8                 fstp st(0)
// 0061c8b7  d905207a8200         fld dword ptr [0x827a20]
// 0061c8bd  c3                   ret 

extern double __cdecl getNumber(void *, int);

extern const double *infinity;
extern const float *floatInfinity;
extern const double upperLimit;
extern const double lowerLimit;
extern const float upperResult;
extern const float lowerResult;

double __cdecl convertNumber(void *state, int index)
{
    double value = getNumber(state, index);

    if (value == *infinity)
        return *floatInfinity;
    if (value == -*infinity)
        return -*floatInfinity;

    if (!(value < 0.0) && !(value >= 0.0))
        return value;

    if (value > upperLimit)
        return upperResult;
    if (value < lowerLimit)
        return lowerResult;

    return value;
}
