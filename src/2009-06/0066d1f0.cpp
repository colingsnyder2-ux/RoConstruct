// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005de190  unit: RBX::Message  size: 54 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005de190
//
// 005de190  d9e8                 fld1 
// 005de192  8b4c2404             mov ecx, dword ptr [esp + 4]
// 005de196  d85904               fcomp dword ptr [ecx + 4]
// 005de199  dfe0                 fnstsw ax
// 005de19b  f6c441               test ah, 0x41
// 005de19e  7a07                 jp 0x5de1a7
// 005de1a0  d90574e38100         fld dword ptr [0x81e374]
// 005de1a6  c3                   ret 
// 005de1a7  d905b8c38100         fld dword ptr [0x81c3b8]
// 005de1ad  d85904               fcomp dword ptr [ecx + 4]
// 005de1b0  dfe0                 fnstsw ax
// 005de1b2  f6c401               test ah, 1
// 005de1b5  7507                 jne 0x5de1be
// 005de1b7  d90570e38100         fld dword ptr [0x81e370]
// 005de1bd  c3                   ret 
// 005de1be  d94104               fld dword ptr [ecx + 4]
// 005de1c1  e9fa3b0c00           jmp 0x6a1dc0

extern "C" double __cdecl acos(double);
#pragma intrinsic(acos)

extern const float upperResult;
extern const float lowerResult;

struct S {
    float x;
    float y;
};

double __cdecl f(const S& v)
{
    if (v.y >= 1.0f)
        return upperResult;
    if (v.y <= -1.0f)
        return lowerResult;
    return acos(v.y);
}
