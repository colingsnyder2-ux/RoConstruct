// from server: 20% by atomic.potato
struct Mesh;

struct Inner {
    char pad0[8];
    int f8;
    int fc;
};

struct Outer {
    char pad0[0x18];
    int f18;
};

extern "C" void __stdcall _invalid_parameter_noinfo();

extern "C" int __fastcall sub_4e77c0(Mesh* self, int a);
extern "C" void __fastcall sub_4e7830(Inner* out, Mesh* self, int a);
extern "C" int __fastcall sub_4e6170(Mesh* self, int a, int b, int c, int d);
extern "C" int __fastcall sub_9201e0(Inner* p);

struct Mesh {
    int f0;
    char pad4[0x14];
    int f18;
    int get(int a);
};

int Mesh::get(int a) {
    int v38;
    Inner v8;
    int v3c;
    int v10;
    int vc;
    int v40;
    int v1c;
    int v24;
    int v20;
    int v18;
    int v14;
    int v2c;

    v38 = sub_4e77c0(this, a);
    sub_4e7830(&v8, this, v38);

    v3c = this->f18;
    v10 = 0;
    vc = v3c;

    if (this == 0) {
        _invalid_parameter_noinfo();
    }

    v10 = this->f0;

    if (v8.f8 != 0) {
        if (v8.f8 == v10) {
            goto ok1;
        }
    }
    _invalid_parameter_noinfo();
ok1:

    if (v8.fc == vc) {
        goto do_work;
    }

    v40 = v8.fc;
    if (a == 0) {
        goto do_work;
    }
    if (*(int*)a < *(int*)(v40 + 0xc)) {
        goto do_work;
    }
    goto done;

do_work:
    v1c = 0;
    v24 = v8.f8;
    v20 = v8.fc;
    v18 = *(int*)a;
    v14 = v1c;
    sub_4e6170(this, v24, v20, (int)&v18, (int)&v2c);
    v8.f8 = v2c;
    v8.fc = *(int*)((char*)&v2c + 4);

done:
    return sub_9201e0(&v8) + 4;
}
