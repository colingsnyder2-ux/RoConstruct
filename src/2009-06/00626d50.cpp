// from server: 100% by tester
struct Tool {
    char pad[0x178];
    int field_1f4;
    char pad2[0x180 - 0x178 - 4];
    int field_208;
    void func();
};

extern "C" void __fastcall sub_728350(int*);

void Tool::func()
{
    sub_728350(&field_1f4);
    sub_728350(&field_208);
}
