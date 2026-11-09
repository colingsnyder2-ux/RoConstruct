// from server: 42% by colin
struct RBX_VelocityMotor__FactoryProduct {
    void* vtable;
    char pad[0xb8];
    int field_bc;
    char pad2[0x38];
    int field_f8;
    int field_fc;
    int field_100;
    int field_104;
    void* createInstance(void*);
};

extern "C" {
    int __cdecl sub_630D36(int, int, int, int, int);
    void __cdecl sub_475050(void*);
    void __cdecl sub_5B9C40(void*, void*, void*);
    void __cdecl sub_5AB780(void*, void*, void*);
    void __cdecl sub_5B9B20(void*, void*, void*);
    void __cdecl sub_5BCA60(void*, void*, void*);
    void __cdecl sub_5B9940(int);
    void __cdecl sub_5B9FF0(int);
    void __cdecl sub_5095D0(void*, void*);
}

extern float g_797E9C;
extern float g_79646C;

void* RBX_VelocityMotor__FactoryProduct::createInstance(void* arg) {
    void* result = (void*)sub_630D36(this->field_bc, 0, 0x881f4c, 0x884a28, 0);
    if (result == 0) {
        sub_475050(arg);
        return arg;
    }
    int* p = (int*)((char*)result + 0x1d8);
    int* q = (int*)((char*)*p + 0x60);
    float* f = (float*)((char*)*q + 4);
    float a = f[0];
    float b = f[1];
    float c = f[2];
    float scale = g_797E9C;
    a *= scale;
    b *= scale;
    c *= scale;
    float na = -a;
    float nb = -b;
    float nc = -c;
    float m[9];
    m[0] = na; m[1] = nb; m[2] = nc;
    m[3] = a; m[4] = b; m[5] = c;
    m[6] = a; m[7] = b; m[8] = c;
    float v1[3];
    float v2[3];
    float v3[3];
    sub_5B9C40(v1, v2, v3);
    sub_5AB780(v1, v2, v3);
    float zero = 0.0f;
    int mode = this->field_100;
    float angle = zero;
    if (mode == 0) {
        angle = -angle;
    } else if (mode == 1) {
        angle = zero;
    }
    int mode2 = this->field_fc;
    float angle2 = 0.0f;
    if (mode2 == 1) {
        angle2 = angle;
    } else if (mode2 == 2) {
        angle2 = -angle2;
    }
    int mode3 = this->field_104;
    float angle3 = 0.0f;
    if (mode3 == 1) {
        float t = angle2;
        angle2 = angle3;
        angle3 = t;
    } else if (mode3 == 2) {
        float absv = angle2 < 0 ? -angle2 : angle2;
        float one_minus = 1.0f - absv;
        float t1 = one_minus;
        float t2 = angle2;
        if (t1 > t2) {
            angle3 = t1;
        } else if (t2 > t1) {
            angle3 = t2;
        } else {
            angle3 = t1;
        }
        float absv2 = angle2 < 0 ? -angle2 : angle2;
        float t3 = absv2;
        float t4 = angle2;
        if (t3 > t4) {
            angle3 = t3;
        } else if (t4 > t3) {
            angle3 = t4;
        } else {
            angle3 = t3;
        }
    }
    float out[3];
    sub_5B9B20(out, &angle2, &this->field_f8);
    float out2[3];
    sub_5BCA60(out2, &angle3, &this->field_f8);
    float fx = out2[0] + out[0];
    float fy = out2[1] + out[1];
    float fz = out2[2] + out[2];
    void* vt = this->vtable;
    int (*fn)(void*) = *(int (**)(void*))((char*)vt + 0x44);
    int r = fn(this);
    int val = this->field_f8;
    if (r != 1) {
        val = (val + 3) % 6;
        sub_5B9940(val);
    }
    sub_5B9FF0(val);
    sub_5095D0(arg, (void*)val);
    *(float*)((char*)arg + 0x24) = fx;
    *(float*)((char*)arg + 0x28) = fy;
    *(float*)((char*)arg + 0x2c) = fz;
    return arg;
}
