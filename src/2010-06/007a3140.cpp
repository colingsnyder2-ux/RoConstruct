// from server: 41% by atomic.potato
// roc 2010-06 007a3140  unit: W4_D3DFORMAT::?$EnumDesc
// library rbxgs/util\Name.cpp

extern "C" __declspec(dllimport) void __stdcall _wassert(const wchar_t*, const wchar_t*, unsigned int);

struct Sub {
    char pad0[0x14];
    int count18;
    char pad1[0x8];
    int count24;
    char pad2[0x8];
    int count30;
    char pad3[0x8];
    int count3c;
    char pad4[0x14];
    int field50;
};

struct Inner {
    char pad0[0x650];
    int count654;
    char pad1[0x4];
    int field650;
};

struct Elem {
    int a;
    int b;
    int c;
    int d;
};

struct Other {
    char pad0[0x8];
    int f8;
    char pad1[0x4];
    int f10;
    int f14;
    int f18;
    char pad2[0x4];
    int f20;
    int f24;
    char pad3[0x10];
    int f38;
    int f3c;
    int f40;
    int f44;
};

struct S {
    bool f(Other* other, int* flags, Sub* sub);
};

bool S::f(Other* other, int* flags, Sub* sub) {
    if (flags[0] == 1) {
        if (sub->pad0[0] != other->pad0[0]) return false;
    }
    if (flags[1] == 1) {
        if (*(int*)(sub->pad0 + 4) != *(int*)(other->pad0 + 4)) return false;
    }
    if (flags[2] == 1) {
        if (*(int*)(sub->pad0 + 8) != other->f8) return false;
    }
    if (flags[3] == 1) {
        if (*(int*)(sub->pad0 + 0xc) != *(int*)(other->pad0 + 8)) return false;
    }
    if (flags[4] == 1) {
        if ((*(unsigned char*)(other->pad0 + 0xc) & 0x40) != 0) {
            Inner* inner = *(Inner**)(sub->pad0 + 0x54);
            if ((inner->field650 & 0x10000) == 0) return false;
        }
    }
    if (flags[5] == 1) {
        Inner* inner = *(Inner**)(sub->pad0 + 0x50);
        int i = 0;
        while (i < inner->count654) {
            if (i < 0 || i >= inner->count654) {
                _wassert((const wchar_t*)0xa54cd8, (const wchar_t*)0xa54d18, 0x21);
            }
            Elem* e = (Elem*)(inner->field650 + i * 0x10);
            if (e->d == other->f8 && e->a == other->f10 && e->b == other->f14) {
                break;
            }
            i++;
        }
        if (i >= inner->count654) return false;
    }
    if (flags[6] == 1) {
        if (*(int*)(sub->pad0 + 0xc) != other->f18) return false;
    }
    if (flags[8] == 1) {
        int i = 0;
        while (i < sub->count24) {
            if (i < 0 || i >= sub->count24) {
                _wassert((const wchar_t*)0xa54cd8, (const wchar_t*)0xa54d18, 0x21);
            }
            int v = *(int*)(*(int*)(sub->pad0 + 0x20) + i * 4);
            if (i < 0 || i >= sub->count30) {
                _wassert((const wchar_t*)0xa54cd8, (const wchar_t*)0xa54d18, 0x21);
            }
            if (v == other->f20) {
                int v2 = *(int*)(*(int*)(sub->pad0 + 0x2c) + i * 4);
                if (v2 >= (unsigned)other->f24) break;
            }
            i++;
        }
        if (i >= sub->count24) return false;
    }
    if (flags[10] == 1) {
        if (flags[11] == 1) {
            if (other->f38 != 0) {
                if (!((bool (*)(int*))0x7a3110)((int*)(sub->pad0 + 0x14))) return false;
            }
        }
        if (flags[10] == 1) {
            if (other->f38 != 0) {
                int base = ((int (*)(int))0x7a4d30)(other->f38);
                int i = 0;
                bool found = false;
                while (i < sub->count18) {
                    if (i < 0 || i >= sub->count18) {
                        _wassert((const wchar_t*)0xa54cd8, (const wchar_t*)0xa54d18, 0x21);
                    }
                    int v = ((int (*)(int))0x7a4d30)(*(int*)(*(int*)(sub->pad0 + 0x14) + i * 4));
                    if (v - base == 0) found = true;
                    i++;
                }
                if (!found) return false;
            }
        }
    }
    if (flags[11] == 1) {
        if (other->f38 != 0) {
            int base = ((int (*)(int))0x7a4d90)(other->f38);
            int i = 0;
            bool found = false;
            while (i < sub->count18) {
                if (i < 0 || i >= sub->count18) {
                    _wassert((const wchar_t*)0xa54cd8, (const wchar_t*)0xa54d18, 0x21);
                }
                int v = ((int (*)(int))0x7a4d90)(*(int*)(*(int*)(sub->pad0 + 0x14) + i * 4));
                if (v - base == 0) found = true;
                i++;
            }
            if (!found) return false;
        }
    }
    if (flags[13] == 1) {
        Inner* inner = *(Inner**)(sub->pad0 + 0x50);
        int i = 0;
        while (i < inner->count654) {
            if (i < 0 || i >= inner->count654) {
                _wassert((const wchar_t*)0xa54cd8, (const wchar_t*)0xa54d18, 0x21);
            }
            Elem* e = (Elem*)(inner->field650 + i * 0x10);
            if (e->d == other->f8 && e->c == other->f40) {
                break;
            }
            i++;
        }
        if (i >= inner->count654) return false;
    }
    if (flags[14] == 1) {
        int n = sub->count3c;
        if (n > 0) {
            int i = 0;
            while (i < n) {
                if (i < 0 || i > n) {
                    _wassert((const wchar_t*)0xa54d9c, (const wchar_t*)0xa54d18, 0x333);
                    return false;
                }
                if (*(int*)(*(int*)(sub->pad0 + 0x38) + i * 4) == other->f44) {
                    if (i == -1) return false;
                    break;
                }
                i++;
            }
            if (i >= n) return false;
        } else {
            return false;
        }
    }
    return true;
}
