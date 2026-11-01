// from server: 100% by colin
struct CXTPImageEditorPicture {
    void sub_6F3A90();
    int sub_6E4440();
    int sub_6E4770(int);
    void sub_6F2890();
    char pad[0x7c];
    int field_7c;
    char pad2[0x28];
    int field_a8;
};

void CXTPImageEditorPicture::sub_6F3A90() {
    if (field_a8 != 0) {
        int saved = ((CXTPImageEditorPicture*)((char*)this + 0x9c))->sub_6E4440();
        ((CXTPImageEditorPicture*)((char*)this + 0x80))->sub_6E4770(field_7c);
        field_7c = saved;
        sub_6F2890();
    }
}
