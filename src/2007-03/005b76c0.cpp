// from server: 100% by colin
// roc 2007-03 005b76c0  unit: seg_005b0000  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 005b76c0
//
// 005b76c0  8b542404             mov edx, dword ptr [esp + 4]
// 005b76c4  d9420c               fld dword ptr [edx + 0xc]
// 005b76c7  d819                 fcomp dword ptr [ecx]
// 005b76c9  dfe0                 fnstsw ax
// 005b76cb  f6c405               test ah, 5
// 005b76ce  7b45                 jnp 0x5b7715
// 005b76d0  d94210               fld dword ptr [edx + 0x10]
// 005b76d3  d85904               fcomp dword ptr [ecx + 4]
// 005b76d6  dfe0                 fnstsw ax
// 005b76d8  f6c405               test ah, 5
// 005b76db  7b38                 jnp 0x5b7715
// 005b76dd  d94214               fld dword ptr [edx + 0x14]
// 005b76e0  d85908               fcomp dword ptr [ecx + 8]
// 005b76e3  dfe0                 fnstsw ax
// 005b76e5  f6c405               test ah, 5
// 005b76e8  7b2b                 jnp 0x5b7715
// 005b76ea  d94204               fld dword ptr [edx + 4]
// 005b76ed  d85910               fcomp dword ptr [ecx + 0x10]
// 005b76f0  dfe0                 fnstsw ax
// 005b76f2  f6c441               test ah, 0x41
// 005b76f5  741e                 je 0x5b7715
// 005b76f7  d902                 fld dword ptr [edx]
// 005b76f9  d8590c               fcomp dword ptr [ecx + 0xc]
// 005b76fc  dfe0                 fnstsw ax
// 005b76fe  f6c441               test ah, 0x41
// 005b7701  7412                 je 0x5b7715
// 005b7703  d94208               fld dword ptr [edx + 8]
// 005b7706  d85914               fcomp dword ptr [ecx + 0x14]
// 005b7709  dfe0                 fnstsw ax
// 005b770b  f6c441               test ah, 0x41
// 005b770e  7405                 je 0x5b7715
// 005b7710  b001                 mov al, 1
// 005b7712  c20400               ret 4
// 005b7715  32c0                 xor al, al
// 005b7717  c20400               ret 4
// copied from an identical function in another client (function ?overlapsOrTouches@Extents@@QBE_NABU1@@Z)

// from server: 100% by colin
// roc-cl: 50727
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
struct Extents {
    float lowX;
    float lowY;
    float lowZ;
    float highX;
    float highY;
    float highZ;
    bool overlapsOrTouches(const Extents& other) const;
};

bool Extents::overlapsOrTouches(const Extents& other) const {
    if (!(lowX > other.highX) && !(lowY > other.highY) && !(lowZ > other.highZ) &&
        !(highY < other.lowY) && !(highX < other.lowX) && !(highZ < other.lowZ)) {
        return true;
    }
    return false;
}