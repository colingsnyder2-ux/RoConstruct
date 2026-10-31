// from server: 100% by EspClaude
// roc 2009-06 0046b3e0  unit: DxUserInput  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0046b3e0
//
// 0046b3e0  e8ab171000           call 0x56cb90
// 0046b3e5  d900                 fld dword ptr [eax]
// 0046b3e7  8b4c2408             mov ecx, dword ptr [esp + 8]
// 0046b3eb  d919                 fstp dword ptr [ecx]
// 0046b3ed  d94004               fld dword ptr [eax + 4]
// 0046b3f0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0046b3f4  d95904               fstp dword ptr [ecx + 4]
// 0046b3f7  8b4c2404             mov ecx, dword ptr [esp + 4]
// 0046b3fb  d901                 fld dword ptr [ecx]
// 0046b3fd  d800                 fadd dword ptr [eax]
// 0046b3ff  d918                 fstp dword ptr [eax]
// 0046b401  d94104               fld dword ptr [ecx + 4]
// 0046b404  d84004               fadd dword ptr [eax + 4]
// 0046b407  d95804               fstp dword ptr [eax + 4]
// 0046b40a  c3                   ret 
// copied from an identical function in another client (function ?fn_ROCX000016_004692f0@ns_ROCX000016@@YAXPBUVec2@1@PAU21@1@Z)

namespace ns_ROCX000016 {
struct Vec2 {
    float x;
    float y;
};

extern const Vec2& __cdecl zeroVector();

void __cdecl fn_ROCX000016_004692f0(const Vec2* input, Vec2* first, Vec2* second)
{
    const Vec2& zero = zeroVector();
    first->x = zero.x;
    first->y = zero.y;
    second->x = input->x + second->x;
    second->y = input->y + second->y;
}
}
