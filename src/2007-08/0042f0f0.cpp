// from server: 100% by colin
struct CMainFrame {
    char pad[0xe0];
    unsigned char field_0xe0;
    void method(int*);
};

void CMainFrame::method(int* p) {
    unsigned char v = field_0xe0;
    void (__thiscall *fn)(int*, unsigned char) = *(void (__thiscall **)(int*, unsigned char))(*(int*)p + 4);
    fn(p, v);
}
