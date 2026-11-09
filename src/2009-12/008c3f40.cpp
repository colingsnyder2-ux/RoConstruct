// roc 2009-12 008c3f40  unit: CXTPImageEditorPicture  size: 55 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c3f40
//
// 008c3f40  56                   push esi
// 008c3f41  8bf1                 mov esi, ecx
// 008c3f43  83be8c00000000       cmp dword ptr [esi + 0x8c], 0
// 008c3f4a  7429                 je 0x8c3f75
// 008c3f4c  57                   push edi
// 008c3f4d  8d8e80000000         lea ecx, [esi + 0x80]
// 008c3f53  e8f843feff           call 0x8a8350
// 008c3f58  8bf8                 mov edi, eax
// 008c3f5a  8b467c               mov eax, dword ptr [esi + 0x7c]
// 008c3f5d  50                   push eax
// 008c3f5e  8d8e9c000000         lea ecx, [esi + 0x9c]
// 008c3f64  e817fcffff           call 0x8c3b80
// 008c3f69  897e7c               mov dword ptr [esi + 0x7c], edi
// 008c3f6c  5f                   pop edi
// 008c3f6d  8bce                 mov ecx, esi
// 008c3f6f  5e                   pop esi
// 008c3f70  e9dbedffff           jmp 0x8c2d50
// 008c3f75  5e                   pop esi
// 008c3f76  c3                   ret 
// copied from an identical function in another client (function ?sub_6F3A50@CXTPImageEditorPicture@ns_ROCX000045@@QAEXXZ)

namespace ns_ROCX000045 {
struct CXTPImageEditorPicture {
    void sub_6F3A50();
    int sub_6E4440();
    int sub_6E4770(int);
    void sub_6F2890();
    char pad[0x7c];
    int field_7c;
    char pad2[0x0c];
    int field_8c;
};

void CXTPImageEditorPicture::sub_6F3A50() {
    if (field_8c != 0) {
        int saved = ((CXTPImageEditorPicture*)((char*)this + 0x80))->sub_6E4440();
        ((CXTPImageEditorPicture*)((char*)this + 0x9c))->sub_6E4770(field_7c);
        field_7c = saved;
        sub_6F2890();
    }
}
}
