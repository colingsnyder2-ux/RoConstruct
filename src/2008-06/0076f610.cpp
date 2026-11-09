// from server: 100% by tester
struct CXTPImageEditorDlg {
    char pad[0xa54];
    void* field_a4c;
    void SetImage(void* p);
};

void CXTPImageEditorDlg::SetImage(void* p) {
    if (field_a4c) {
        ((CXTPImageEditorDlg*)field_a4c)->SetImage(0);
    }
    if (p) {
        ((CXTPImageEditorDlg*)p)->SetImage((void*)1);
    }
    field_a4c = p;
}
