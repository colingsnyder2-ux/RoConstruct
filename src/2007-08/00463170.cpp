// from server: 30% by colin
struct CSettingsDialog {
    char pad[0x74];
    void* field74;
    char pad2[0x18c - 0x78];
    void* field18c;
    void* field190;
    bool method();
};

extern "C" int __stdcall sub_63041E(void*);
extern "C" void __stdcall sub_40F060();
extern "C" void __stdcall sub_409920();
extern "C" void* __stdcall sub_630652(void*, int, int);
extern "C" void __stdcall sub_54A950(void*);
extern "C" void __stdcall sub_41E8E0(void*, void*);
extern "C" void __stdcall sub_492360(void*);
extern "C" void* __stdcall sub_6305B0(void*, int, int, int);
extern "C" void* __stdcall sub_410D40(void*);
extern "C" void __stdcall sub_441FF0(void*, void*);
extern "C" void* __stdcall sub_63096A(void*, int);
extern "C" void __stdcall sub_6309F4(void*, void*);
extern "C" void __stdcall sub_630034(void*, int, int, int, int, int);
extern "C" void __stdcall GetWindowRect(void*, void*);

bool CSettingsDialog::method() {
    if (sub_63041E(this) == 0)
        return false;
    sub_40F060();
    sub_409920();
    void* v = this->field74;
    int (__stdcall *fn1)(void*, int, int, int, int, int) = *(int (__stdcall**)(void*, int, int, int, int, int))((char*)v + 0x140);
    if (fn1(&this->field74, 1, 2, 0x50000000, 0xe900, 0) == 0)
        return false;
    int (__stdcall *fn2)(void*, int, int, int, int, int) = *(int (__stdcall**)(void*, int, int, int, int, int))((char*)this->field74 + 0x144);
    if (fn2(&this->field74, 0, 0, 0x795554, 0xc8, 0xc8) == 0)
        return false;
    void* r = sub_630652(&this->field74, 0, 0);
    this->field18c = r;
    void* tmp;
    sub_54A950(&tmp);
    sub_41E8E0(this->field18c, *(void**)tmp);
    sub_492360(&tmp);
    void* edx_val = this->field190;
    void* eax_val = sub_6305B0(&this->field74, 0, 1, 0);
    int (__stdcall *fn3)(void*, void*, void*, void*) = *(int (__stdcall**)(void*, void*, void*, void*))((char*)edx_val + 0x13c);
    fn3(&this->field190, &tmp, &this->field74, eax_val);
    sub_54A950(&tmp);
    void* p = *(void**)tmp;
    void* result = 0;
    if (p != 0)
        result = sub_410D40(p);
    sub_492360(&tmp);
    sub_441FF0(&this->field190, result);
    void* w = sub_63096A(this, 0x3e9);
    void* hwnd = *(void**)((char*)w + 0x20);
    struct { int left, top, right, bottom; } rect;
    GetWindowRect(hwnd, &rect);
    sub_6309F4(this, &rect);
    sub_630034(&this->field74, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, 1);
    return true;
}
