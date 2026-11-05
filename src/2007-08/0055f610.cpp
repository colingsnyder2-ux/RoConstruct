// from server: 48% by atomic.potato
extern "C" void __stdcall _invalid_parameter_noinfo();

typedef bool (__cdecl *Pred)(int);
int* find_if(int* first, int* last, Pred pred);

struct ClearBackpack {
    char pad[0xf4];
    int f4;
    int f8;
    int fc;
    int method(int);
};

int ClearBackpack::method(int arg) {
    int* p = &f4;
    int ebx = fc;
    if (f8 > ebx) {
        _invalid_parameter_noinfo();
    }
    int edi = p[1];
    if (edi > p[2]) {
        _invalid_parameter_noinfo();
    }
    int result = (int)find_if((int*)arg, (int*)ebx, (Pred)edi);
    int edi2 = p[2];
    if (p[1] > edi2) {
        _invalid_parameter_noinfo();
    }
    if (p != 0) {
        if (p != p) {
            _invalid_parameter_noinfo();
        }
    } else {
        _invalid_parameter_noinfo();
    }
    if (result == edi2) {
        return 0;
    }
    if (p == 0) {
        _invalid_parameter_noinfo();
    }
    if (result >= p[2]) {
        _invalid_parameter_noinfo();
    }
    return *(int*)result;
}
