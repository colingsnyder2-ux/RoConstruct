// from server: 33% by atomic.potato
struct Vec2 { float x; float y; };

struct Sub1 {
    char pad[0x1c];
    int field1c;
};

struct Sub2 {
    char pad[0x100];
    int field100;
};

struct Sub3 {
    char pad[0x104];
    Sub1* get(int* p);
};

extern "C" void __cdecl fn_600de0(Vec2* out);
extern "C" float __cdecl fn_600d50();
extern "C" void __cdecl fn_7ca920(int a, int b, Vec2 v);
extern "C" Sub1* __cdecl fn_7ce640(Sub3* self, int* p);

extern float g_a64df0;

struct S {
    char pad0[0xe4];
    int field_e4;
    char pad_e8[0x100 - 0xe8];
    int field_100;
    Sub3 sub3;
    void method(Vec2 v, char flag);
};

void S::method(Vec2 v, char flag) {
    Vec2 tmp;
    fn_600de0(&tmp);
    v.x = tmp.x;
    v.y = tmp.y;
    if (flag == 0) {
        int n = this->field_100;
        int m = n * 12;
        float f;
        if (m < 0) {
            f = (float)m + g_a64df0;
        } else {
            f = (float)m;
        }
        v.y = tmp.y - f;
        int r = (int)fn_600d50();
        fn_7ca920(r, (int)&this->field_e4, v);
    } else {
        int key = 0;
        Sub1* s = fn_7ce640(&this->sub3, &key);
        int n = s->field1c;
        int m = n * 12;
        float f;
        if (m < 0) {
            f = (float)m + g_a64df0;
        } else {
            f = (float)m;
        }
        v.y = tmp.y - f;
        key = 0;
        int r = (int)fn_600d50();
        Sub1* s2 = fn_7ce640(&this->sub3, &key);
        fn_7ca920(r, (int)s2, v);
    }
}
