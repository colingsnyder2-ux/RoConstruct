// from server: 48% by Intel
struct std_string {
    char _buf[28];
    std_string();
    ~std_string();
    std_string(const char*);
};

extern "C" void __stdcall sub_746250(std_string*);
extern "C" void __stdcall sub_7463d0(const std_string*, std_string*);
extern "C" int __stdcall sub_B24798();
extern "C" void __stdcall sub_B22648(std_string*, int);
extern "C" void __stdcall sub_B2263c(std_string*);

struct FacesItem {
    bool func_45E770(int);
};

bool FacesItem::func_45E770(int arg) {
    std_string s1;
    sub_746250(&s1);

    int v = sub_B24798();
    sub_B22648(&s1, v);

    std_string s2;
    sub_7463d0(&s1, &s2);

    bool result = false;
    sub_B2263c(&s2);
    return result;
}
