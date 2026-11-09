// from server: 36% by colin
struct CXTPImageEditorPicker {
    int field_0x50;
    int method_0x6f0e00(int* out);
    int method_0x6f0e30(int a, int b);
};

extern "C" int __cdecl func_62ff02(int* p);
extern "C" int __cdecl func_62ff20();
extern "C" int __cdecl func_63044e(int x);
extern "C" void __cdecl func_6f0ef6();

int CXTPImageEditorPicker::method_0x6f0e30(int a, int b) {
    int local_20 = 0;
    int* p = (int*)func_62ff02(&local_20);
    int v = func_63044e(p[0x9c / 4]);
    if (v != 0) {
        return 0;
    }
    int local_28;
    this->method_0x6f0e00(&local_28);
    int fn = this->field_0x50;
    if (fn == 0) {
        func_62ff20();
    }
    int result = ((int (__stdcall*)(int, int))fn)(a, b);
    func_6f0ef6();
    return result;
}
