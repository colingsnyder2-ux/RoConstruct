// from server: 52% by colin
struct CSelectionTreeCtrl {
    char pad[0xb0];
    int fieldB0;
    char pad2[0x24];
    int fieldD8;

    void sub_421C50(int);
};

extern "C" void __stdcall sub_725750(int);
extern "C" void __stdcall sub_725770(int);
extern "C" void __stdcall sub_4A9660(int, int, int);

void CSelectionTreeCtrl::sub_421C50(int arg) {
    int local0 = 0;
    int local1 = 0;
    int local2 = 0;
    int local3 = 0;
    int local4 = 0;

    sub_725750((int)(this->pad + 0xb0));
    local1 = 1;
    sub_4A9660((int)(this->pad + 0xd8), (int)&local0, (int)&local4);
    local2 = -1;
    sub_725770((int)(this->pad + 0xb0));
}
