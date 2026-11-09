// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

struct S {
    unsigned int field0;
    unsigned int field4;
    unsigned int field8;
    unsigned int fieldC;
    unsigned int field10;
    double* first;
    double* last;
    void method(double value, bool flag);
};

void S::method(double value, bool flag) {
    unsigned int size = last - first;
    unsigned int index = field4;
    if (index >= size) {
        _invalid_parameter_noinfo();
    }
    first[index] = value;
    if (flag) {
        field4 = (field4 + 1) % field0;
    }
}
