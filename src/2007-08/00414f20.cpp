// from server: 45% by colin
struct DHTMLWindow
{
    char pad[0xe8];
    int field_e8;
    int field_ec;
    int field_f0;
    void method_414f20(int, int, int, int, int, int, int);
};

extern "C" void __stdcall sub_00725750(int);
extern "C" void __stdcall sub_00725770(int);
extern "C" void __stdcall sub_0062FF56(int, const char*);
extern "C" void* __stdcall sub_0077E6A8(int, int, int, int, int);
extern "C" void __stdcall sub_0077E6AC(int);

void DHTMLWindow::method_414f20(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    sub_00725750((int)(this->pad + 0xe8));
    if (this->field_f0 != 0)
    {
        void* p = sub_0077E6A8(0, 0, 0, 0, 0);
        sub_0062FF56(this->field_f0, (const char*)p);
    }
    sub_00725770((int)(this->pad + 0xe8));
    sub_0077E6AC((int)(this->pad + 0x24));
}
