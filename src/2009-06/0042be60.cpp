// from server: 100% by EspClaude
// from server: 100% by king_originala
// roc 2008-06 00431ce0  unit: CDataModelPropGrid  size: 20 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 00431ce0
//
// 00431ce0  80b9f800000000       cmp byte ptr [ecx + 0xf8], 0
// 00431ce7  0f94c0               sete al
// 00431cea  0fb6d0               movzx edx, al
// 00431ced  52                   push edx
// 00431cee  e84dfeffff           call 0x431b40
// 00431cf3  c3                   ret 

struct CDataModelPropGrid {
    void f(bool);
    void Update();
    char padding[0xfc];
    unsigned char field_0xf8;
};

void CDataModelPropGrid::Update() {
    f(field_0xf8 == 0);
}
