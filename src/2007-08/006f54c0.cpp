// from server: 100% by colin
extern "C" int (__stdcall *EnableWindow)(void* hWnd, int bEnable);

struct CXTPControlCustom {
    char pad[0x9c];
    int field_9c;
    char pad2[0x170 - 0x9c - 4];
    void* field_170;
    void method_63a690(int);
    void setEnabled(int);
};

void CXTPControlCustom::setEnabled(int value) {
    if (value != this->field_9c) {
        void* h = this->field_170;
        this->field_9c = value;
        if (h != 0) {
            EnableWindow(h, value);
        }
        this->method_63a690(1);
    }
}
