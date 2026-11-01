// from server: 100% by Yeetserama
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

extern "C" char s_785954[];

struct CNullDoc {
    char pad[0x2b8];
    int field_2b8;
    void sub_40B010();
    void sub_62FF56(int r);
};

struct Inner {
    int __declspec(dllimport) method1(const char*);
    int __declspec(dllimport) method2(int, int, int, int, int);
};

void CNullDoc::sub_40B010() {
    Inner* p = (Inner*)&field_2b8;
    if (p->method1((const char*)(int)s_785954)) {
        int r = p->method2(0, 0, 0, 0, 0);
        this->sub_62FF56(r);
    }
}
