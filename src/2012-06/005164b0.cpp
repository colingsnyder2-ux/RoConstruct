// from server: 35% by atomic.potato
struct S_func_004cc450 {
    char pad0[2120];
    int m_x;
    int f();
};
int S_func_004cc450::f() {
    return m_x;
}

extern "C" int __stdcall _004cc450(S_func_004cc450* a) {
    return a->f();
}

extern "C" int __stdcall _005cd650(int a) {
    return a;
}

struct RBX_RbxParticleEmitter {
    int field_4;
    int field_1c;
    int field_ac;

    int some_function();
};

int RBX_RbxParticleEmitter::some_function() {
    if (field_4 != 0) {
        if (field_1c != 0) {
            int eax = field_ac;
            int edx = *(int*)(eax + 0x4720);
            int temp = -(&this->field_ac)[0x1c4];
            int eax2 = temp;
            if (temp < 0) {
                eax2 = -1;
            }
            int eax3 = eax2 & reinterpret_cast<int>(this);
            int ecx = edx;
            int tmp = _004cc450(reinterpret_cast<S_func_004cc450*>(eax3));
            int ecx2 = tmp;
            int tmp2 = _005cd650(ecx2);
            return tmp2;
        }
    }
    return 0;
}
