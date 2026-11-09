// from server: 45% by atomic.potato
// roc 2012-06 007d35f0  unit: RBX::Teams  size: 448 bytes

extern "C" {
    void* __stdcall sub_983448(void*, void*, void*, void*, void*);
    void __stdcall sub_972290(unsigned char, const char*);
}

struct Vec3 { float x, y, z; };

struct Obj {
    char pad0[0x38];
    Obj* field38;
};

struct Inner {
    char pad0[4];
    void* begin;
    void* end;
};

struct Holder {
    char pad0[0x3c];
    Inner* field3c;
};

struct Elem {
    char pad0[0x1c];
    char pad1c[0x70];
    void* field80;
    char pad84[4];
    char field8c;
};

struct S {
    char pad0[0x38];
    Obj* field38;
    Vec3* getVec(Vec3* out, Obj* arg);
};

extern "C" void* __stdcall sub_4a01e0(void*);
extern "C" void* __stdcall sub_417d10(void*);
extern "C" void* __stdcall sub_52b6c0();
extern "C" char __stdcall sub_6c8100(void*, void*);
extern "C" void* __stdcall sub_5314b0(void*);
extern "C" void* __stdcall sub_62bca0();
extern "C" void __stdcall sub_742fb0(void*, void*);

extern unsigned char byte_e580b3;
extern void* dword_e5809c;

Vec3* S::getVec(Vec3* out, Obj* arg) {
    Obj* obj = 0;
    if (this) {
        Obj* a = this->field38;
        if (a) {
            Obj* c = a->field38;
            if (c) {
                obj = (Obj*)sub_4a01e0(c);
            } else {
                obj = a;
            }
        } else {
            obj = (Obj*)this;
        }
    }
    Holder* h = 0;
    if (obj) {
        void* r = sub_983448(obj, 0, (void*)0xd601e8, (void*)0xd65108, 0);
        if (r) {
            h = (Holder*)sub_417d10(r);
        }
    }
    if (byte_e580b3) {
        if (!h) {
            if (dword_e5809c) {
                char ok = ((char (__stdcall*)(int, const char*, const char*))dword_e5809c)(0xa0, (const char*)0xbc0590, (const char*)0xb72b94);
                if (!ok) {
                    sub_972290(byte_e580b3, (const char*)0xbc0608);
                }
            } else {
                sub_972290(byte_e580b3, (const char*)0xbc0608);
            }
        }
    }
    if (!h) {
        Vec3* v = (Vec3*)sub_62bca0();
        out->x = v->x;
        out->y = v->y;
        out->z = v->z;
        return out;
    }
    int i = 0;
    if (h->field3c) {
        if (byte_e580b3 && !h->field3c) {
            if (dword_e5809c) {
                char ok = ((char (__stdcall*)(int, const char*, const char*))dword_e5809c)(0x3d, (const char*)0xb46e18, (const char*)0xb46e04);
                if (!ok) {
                    sub_972290(byte_e580b3, (const char*)0xb46d90);
                }
            } else {
                sub_972290(byte_e580b3, (const char*)0xb46d90);
            }
        }
        Inner* in = h->field3c;
        int count = (int)(((char*)in->end - (char*)in->begin) >> 3);
        while (i < count) {
            if (byte_e580b3 && !in) {
                if (dword_e5809c) {
                    char ok = ((char (__stdcall*)(int, const char*, const char*))dword_e5809c)(0x37, (const char*)0xb46e18, (const char*)0xb46e04);
                    if (!ok) {
                        sub_972290(byte_e580b3, (const char*)0xb4ead0);
                    }
                } else {
                    sub_972290(byte_e580b3, (const char*)0xb4ead0);
                }
            }
            Elem* e = ((Elem**)in->begin)[i];
            if (e) {
                Elem* base = (Elem*)((char*)e + 0x1c);
                if (base) {
                    void* f = *(void**)((char*)base + 0xc);
                    void* g = sub_52b6c0();
                    if (sub_6c8100(f, g)) {
                        Elem* real = (Elem*)((char*)base - 0x1c);
                        if (real) {
                            if (!real->field8c) {
                                void* p = real->field80;
                                if (p) {
                                    void* r = sub_5314b0(p);
                                    if (r == arg) {
                                        void* val = *(void**)((char*)real + 0x88);
                                        out->x = *(float*)&val;
                                        sub_742fb0(out, out);
                                        return out;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            i++;
        }
    }
    Vec3* v = (Vec3*)sub_62bca0();
    out->x = v->x;
    out->y = v->y;
    out->z = v->z;
    return out;
}
