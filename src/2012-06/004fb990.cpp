// roc 2012-06 004fb990  unit: Ogre::UTVertexBasic::?$SpecializedMeshGen  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004fb990
//
// 004fb990  8bc1                 mov eax, ecx
// 004fb992  8b4c2404             mov ecx, dword ptr [esp + 4]
// 004fb996  8b11                 mov edx, dword ptr [ecx]
// 004fb998  8910                 mov dword ptr [eax], edx
// 004fb99a  8b5104               mov edx, dword ptr [ecx + 4]
// 004fb99d  895004               mov dword ptr [eax + 4], edx
// 004fb9a0  8b5108               mov edx, dword ptr [ecx + 8]
// 004fb9a3  895008               mov dword ptr [eax + 8], edx
// 004fb9a6  8b510c               mov edx, dword ptr [ecx + 0xc]
// 004fb9a9  89500c               mov dword ptr [eax + 0xc], edx
// 004fb9ac  8b5110               mov edx, dword ptr [ecx + 0x10]
// 004fb9af  895010               mov dword ptr [eax + 0x10], edx
// 004fb9b2  8b5114               mov edx, dword ptr [ecx + 0x14]
// 004fb9b5  895014               mov dword ptr [eax + 0x14], edx
// 004fb9b8  d94118               fld dword ptr [ecx + 0x18]
// 004fb9bb  d95818               fstp dword ptr [eax + 0x18]
// 004fb9be  d9411c               fld dword ptr [ecx + 0x1c]
// 004fb9c1  d9581c               fstp dword ptr [eax + 0x1c]
// 004fb9c4  c20400               ret 4
// copied from an identical function in another client (function ?copy@S@@QAEPAU1@PBU1@@Z)

// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
struct S {
    int a, b, c, d, e, f;
    float g, h;
    S* copy(const S* other);
};

S* S::copy(const S* other) {
    S* result = this;
    result->a = other->a;
    result->b = other->b;
    result->c = other->c;
    result->d = other->d;
    result->e = other->e;
    result->f = other->f;
    result->g = other->g;
    result->h = other->h;
    return result;
}