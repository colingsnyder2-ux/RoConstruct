// from server: 34% by Intel
struct S_func_009f9be0 {
    char pad0[36];
    int m_x;
    int f();
};

int S_func_009f9be0::f() {
    return m_x;
}

struct Geometry {
    unsigned char getFlag() const;
};

unsigned char Geometry::getFlag() const {
    const void* ptr = *reinterpret_cast<const void* const*>(reinterpret_cast<const char*>(this) + 0x108);
    return *reinterpret_cast<const unsigned char*>(reinterpret_cast<const char*>(ptr) + 0x40);
}

struct Assembly {
    int func(int* arg);
};

int Assembly::func(int* arg) {
    int* v1 = arg + 3;
    int v2 = v1[1];
    S_func_009f9be0* v3 = reinterpret_cast<S_func_009f9be0*>(v2 + 8);
    int v4 = v3->f();
    int v5 = 0;
    int v6 = 0;
    if (v4) {
        S_func_009f9be0* v7 = reinterpret_cast<S_func_009f9be0*>(v4);
        int v8 = v7->f();
        if (v8) {
            v5 = v8 - 8;
        }
    }
    int v9 = v1[2];
    S_func_009f9be0* v10 = reinterpret_cast<S_func_009f9be0*>(v9 + 8);
    int v11 = v10->f();
    if (v11) {
        S_func_009f9be0* v12 = reinterpret_cast<S_func_009f9be0*>(v11);
        int v13 = v12->f();
        if (v13) {
            v6 = v13 - 8;
        }
    }
    int v14 = v5;
    int v15 = reinterpret_cast<int (__thiscall*)(int)>(0x7e3de0)(v14);
    int v16 = reinterpret_cast<int (__thiscall*)(int)>(0x7b95b0)(v15);
    if (v16) {
        int v17 = v6;
        int v18 = reinterpret_cast<int (__thiscall*)(int)>(0x7e3de0)(v17);
        int v19 = reinterpret_cast<int (__thiscall*)(int)>(0x7b95b0)(v18);
        if (v19) {
            return 1;
        }
    }
    return 0;
}
