// from server: 51% by atomic.potato
struct S {
    int f(int, int);
};

extern "C" int __stdcall call_6bde50(int, int);

int S::f(int a1, int a2) {
    int v1 = a1;
    if (!v1) {
        goto loc_6bf9dd;
    }
    int v2 = a2;
    int v3 = *(int*)(v1 + 36);
    v1 -= 28;
    int v4 = v2;
    int v5 = v3 + v1;
    call_6bde50(v5, v4);
    return 8;
loc_6bf9dd:
    int v6 = a2;
    int v7 = *(int*)(v1 + 36);
    v1 = 0;
    int v8 = v6;
    int v9 = v7 + v1;
    call_6bde50(v9, v8);
    return 8;
}
