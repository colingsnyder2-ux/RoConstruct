// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 005cce40  unit: RBX::P8Camera::?$GetSetImpl  size: 50 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 005cce40
//
// 005cce40  56                   push esi
// 005cce41  57                   push edi
// 005cce42  8b7c240c             mov edi, dword ptr [esp + 0xc]
// 005cce46  d94704               fld dword ptr [edi + 4]
// 005cce49  51                   push ecx
// 005cce4a  d80d48a48300         fmul dword ptr [0x83a448]
// 005cce50  8bf1                 mov esi, ecx
// 005cce52  d91c24               fstp dword ptr [esp]
// 005cce55  e8e6f8ffff           call 0x5cc740
// 005cce5a  d907                 fld dword ptr [edi]
// 005cce5c  51                   push ecx
// 005cce5d  d80d44a48300         fmul dword ptr [0x83a444]
// 005cce63  8bce                 mov ecx, esi
// 005cce65  d91c24               fstp dword ptr [esp]
// 005cce68  e8a3f9ffff           call 0x5cc810
// 005cce6d  5f                   pop edi
// 005cce6e  5e                   pop esi
// 005cce6f  c20400               ret 4

#pragma float_control(precise, off)

extern const float scaleX;
extern const float scaleY;

struct Pair {
    float x;
    float y;
};

struct S {
    void setY(float);
    void setX(float);
    void f(const Pair&);
};

void S::f(const Pair& value)
{
    setY(value.y * scaleY);
    setX(value.x * scaleX);
}
