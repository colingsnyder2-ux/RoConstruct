// from server: 100% by tester
struct seg_00420000 {
    char pad[0x98];
    void init();
};

void seg_00420000::init() {
    *(int*)((char*)this + 0x00) = 0x787df4;
    *(int*)((char*)this + 0x04) = 0x787dec;
    *(int*)((char*)this + 0x0c) = 0x787de4;
    *(int*)((char*)this + 0x18) = 0x787ddc;
    *(int*)((char*)this + 0x1c) = 0x787dcc;
    *(int*)((char*)this + 0x34) = 0x787dbc;
    *(int*)((char*)this + 0x4c) = 0x787dac;
    *(int*)((char*)this + 0x64) = 0x787d9c;
    *(int*)((char*)this + 0x7c) = 0x787d8c;
    *(int*)((char*)this + 0x94) = 0x787d7c;
    extern void __stdcall sub_540e80();
    sub_540e80();
}
