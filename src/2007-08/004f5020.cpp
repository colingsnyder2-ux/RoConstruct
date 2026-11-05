// from server: 32% by colin
// roc 2007-08 004f5020  unit: boost::bad_lexical_cast  size: 824 bytes

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) void __cdecl _invalid_parameter_noinfo();

struct Vec3 {
    float x, y, z;
};

struct Mat3 {
    float m[9];
};

struct Obj {
    void* vt;
    int refcount;
};

struct Node {
    Node* next;
    Obj* obj;
};

struct List {
    Node* head;
    Node* tail;
};

struct Cnt {
    int* begin;
    int* end;
    int* cap;
};

struct Holder {
    void* vt;
    int refcount;
    Cnt* data;
};

struct Big {
    float f0;
    float f4;
    float f8;
    float fc;
    float f10;
    float f14;
    float f18;
    float f1c;
    float f20;
    float f24;
    float f28;
    float f2c;
};

struct Tmp {
    void* vt;
    int refcount;
    Cnt* data;
};

extern "C" void* __cdecl sub_4f3fe0();
extern "C" void __cdecl sub_4f4810(void* out, void* in, float f);
extern "C" void __cdecl sub_62fc62(void* p);

extern float g_8bfb20[];

void __stdcall target_4f5020(void* a1, void* a2, void* a3, void* a4)
{
    float* p1 = (float*)sub_4f3fe0();
    float* out1 = (float*)a2;
    out1[0] = p1[0];
    out1[1] = p1[1];
    out1[2] = p1[2];

    float* p2 = (float*)sub_4f3fe0();
    float* out2 = (float*)a3;
    out2[0] = -p2[0];
    out2[1] = -p2[1];
    out2[2] = -p2[2];

    List* list = (List*)a1;
    Node* cur = list->head;
    Node* end = list->tail;

    while (cur != end) {
        Obj* obj = cur->obj;
        void** vt = *(void***)obj;
        void (*fn1)(void*, void*) = (void (*)(void*, void*))vt[6];
        void* tmp = 0;
        fn1(obj, &tmp);
        if (tmp == 0) {
            cur = cur->next;
            continue;
        }

        void** vt2 = *(void***)obj;
        Big* (*fn2)(void*) = (Big* (*)(void*))vt2[7];
        Big* big = fn2(obj);

        Tmp* t = 0;
        sub_4f4810(&t, &tmp, 0.0f);

        Cnt* cnt = t->data;
        int n = cnt->end - cnt->begin;
        for (int i = 0; i < n; i++) {
            int idx = cnt->begin[i];
            float* m = &g_8bfb20[idx * 3];
            float vx = m[0] * big->f0 + m[1] * big->f4 + m[2] * big->f8 + big->f24;
            float vy = m[0] * big->fc + m[1] * big->f10 + m[2] * big->f14 + big->f28;
            float vz = m[0] * big->f18 + m[1] * big->f1c + m[2] * big->f20 + big->f2c;

            float* o2 = (float*)a3;
            float* o1 = (float*)a2;

            float t1 = (vz < o2[2]) ? o2[2] : vz;
            float t2 = (vy < o2[1]) ? o2[1] : vy;
            float t3 = (vx < o2[0]) ? o2[0] : vx;
            o2[0] = t3;
            o2[1] = t2;
            o2[2] = t1;

            float u1 = (vz > o1[2]) ? o1[2] : vz;
            float u2 = (vy > o1[1]) ? o1[1] : vy;
            float u3 = (vx > o1[0]) ? o1[0] : vx;
            o1[0] = u3;
            o1[1] = u2;
            o1[2] = u1;
        }

        if (t) {
            if (InterlockedDecrement((long*)&t->refcount) == 0) {
                Node* n2 = (Node*)t->data;
                while (n2) {
                    void** v = *(void***)n2->obj;
                    void (*d)(void*) = (void (*)(void*))v[1];
                    d(n2->obj);
                    Node* nx = n2->next;
                    sub_62fc62(n2);
                    n2 = nx;
                }
                void** v2 = *(void***)t;
                void (*d2)(void*, int) = (void (*)(void*, int))v2[0];
                d2(t, 1);
            }
        }

        if (tmp) {
            if (InterlockedDecrement((long*)((char*)tmp + 4)) == 0) {
                Node* n3 = (Node*)((char*)tmp + 8);
                while (n3) {
                    void** v = *(void***)n3->obj;
                    void (*d)(void*) = (void (*)(void*))v[1];
                    d(n3->obj);
                    Node* nx = n3->next;
                    sub_62fc62(n3);
                    n3 = nx;
                }
                void** v2 = *(void***)tmp;
                void (*d2)(void*, int) = (void (*)(void*, int))v2[0];
                d2(tmp, 1);
            }
        }

        cur = cur->next;
    }
}
