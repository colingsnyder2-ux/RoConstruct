// from server: 100% by tester
typedef unsigned int size_t;
extern "C" __declspec(dllimport) void qsort(void* base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));

struct CPropertyGridItemBrickColor {
    char pad[0x24];
    void* member_24;
    void* member_28;

    void func_00699020();
};

extern "C" int compar_function(const void* a, const void* b);

void CPropertyGridItemBrickColor::func_00699020() {
    qsort(member_24, (size_t)member_28, 4, compar_function);
}
