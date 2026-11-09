// from server: 16% by Intel
struct std_string {
    char _buf[28];
    std_string() {}
    ~std_string() {}
    std_string& operator=(const std_string&) { return *this; }
};

extern "C" bool __cdecl operator!=(const std_string&, const std_string&);
extern "C" void __stdcall std_string_ctor_ptr(std_string*);
extern "C" void __stdcall std_string_dtor(std_string*);
extern "C" void __stdcall std_string_assign(std_string*, const std_string&);

struct DialogChoice {
    char pad[156];
    std_string field_9C;
    void func();
};

void __stdcall sub_414DA0(DialogChoice*, int);

void DialogChoice::func() {
    std_string local_str;
    std_string_ctor_ptr(&local_str);
    bool result = operator!=(local_str, field_9C);
    if (result) {
        std_string_assign(&field_9C, local_str);
        sub_414DA0(this, 0xE53B14);
    }
    std_string_dtor(&local_str);
}
