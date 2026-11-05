// from server: 61% by Intel


extern "C" bool __cdecl func_00880f30();

struct S {
    char pad[8];
    void f(int a1, int a2);
};

void S::f(int a1, int a2) {
    int v1;
    int v2;

    v1 = a1;
    v2 = a2;
    if (!func_00880f30()) {
        int* p = reinterpret_cast<int*>(this + 8);
        if (p) {
            *p = v1;
            *(p + 1) = v2;
        }
        *reinterpret_cast<int*>(this) = 0xD6E8A4;
    } else {
        *reinterpret_cast<int*>(this) = 0;
    }
}
