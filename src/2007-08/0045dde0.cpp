// from server: 100% by colin
struct CScintillaFindReplaceDlg {
    char pad[0x7c];
    int field_7c;
    unsigned int flags_80;
    char pad2[0x14];
    int field_98;
    void Init(int a, int b, int c, int d, int e);
    void method_630964(int a, int b, int c, int d, int e);
};

extern "C" void* __stdcall sub_62FF02();

void CScintillaFindReplaceDlg::Init(int a, int b, int c, int d, int e) {
    void* p = sub_62FF02();
    int v = *(int*)((char*)p + 0xc);
    this->flags_80 |= 0x200;
    this->field_7c = v;
    this->field_98 = (a == 0) ? 0x66 : 0x65;
    this->method_630964(a, b, c, d, e);
}
