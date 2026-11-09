// from server: 45% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RBXName {
    void* dummy;
};

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakCount;
};

struct Instance {
    void* vptr;
    char pad[0x12c];
    void* field130;
    RefCounted* field134;

    void method_582200();
};

struct Vector3 {
    float x, y, z;
};

struct CFrame {
    float data[12];
};

extern "C" {
    void* __cdecl sub_6FFA50(void*);
    void* __cdecl sub_630D36(void*, void*, void*, void*, void*);
    void __cdecl sub_541630(void*, int);
    void* __cdecl sub_5A56B0(void*);
    void __cdecl sub_509640(void*, void*, int);
    void* __cdecl sub_5D1AE0(void);
    void __cdecl sub_5BAE60(void*, float, float, float);
    void __cdecl sub_578000(void*, float*);
    void __cdecl sub_581FD0(void*);
}

extern float g_79f2fc;
extern float g_7a32e8;
extern float g_7a34b8;
extern char g_881f4c[];
extern char g_88c6b8[];

void Instance::method_582200()
{
    void* local_28;
    Vector3 v1;
    Vector3 v2;
    float f1, f2, f3;
    void* result;
    RefCounted* rc;
    void* obj;
    void* p;

    if (this->field130) {
        p = sub_6FFA50(this->field130);
        if (p) {
            void* q = *(void**)((char*)p + 0xbc);
            result = sub_630D36(q, 0, g_881f4c, g_88c6b8, 0);
        } else {
            result = 0;
        }
        sub_541630(this->field130, 0);
        this->field130 = 0;
        rc = this->field134;
        this->field134 = 0;
        if (rc) {
            if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
                void** vt = (void**)rc->vptr;
                void (*fn)(void*) = (void (*)(void*))vt[1];
                fn(rc);
                if (_InterlockedExchangeAdd(&rc->weakCount, -1) == 1) {
                    void** vt2 = (void**)rc->vptr;
                    void (*fn2)(void*) = (void (*)(void*))vt2[2];
                    fn2(rc);
                }
            }
        }
    } else {
        result = 0;
    }

    obj = sub_5A56B0(result);
    if (obj) {
        void* a = *(void**)((char*)obj + 0xec);
        void* b = *(void**)((char*)a + 8);
        void* c = *(void**)((char*)b + (int)obj + 0xec);
        void* d = *(void**)c;
        void* e = (void*)((char*)b + (int)obj + 0xec);
        void (*fn)(void*, void*) = (void (*)(void*, void*))d;
        fn(e, &local_28);

        f1 = *(float*)((char*)&local_28 + 0x24);
        f2 = *(float*)((char*)&local_28 + 0x30);
        f3 = *(float*)((char*)&local_28 + 0x30) + g_79f2fc;

        Vector3 vv;
        vv.x = f1;
        vv.y = f2;
        vv.z = f3;

        float w = g_7a32e8;

        sub_509640(&vv, &vv, 2);

        float m = g_7a34b8;
        v1.x = vv.x * m;
        v1.y = vv.y * m;
        v1.z = vv.z * m;

        v2.x = v1.x + f1;
        v2.y = v1.y + f2;
        v2.z = v1.z + f3;

        void* inst = sub_5D1AE0();
        if (inst) {
            sub_5BAE60(inst, v2.x, v2.y, v2.z);
            float one = 1.0f;
            float arr[3];
            arr[0] = one;
            arr[1] = one;
            arr[2] = one;
            sub_578000(inst, arr);
        }
    }

    sub_581FD0(this);
}
