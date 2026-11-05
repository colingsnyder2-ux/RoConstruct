// from server: 45% by atomic.potato
struct Inner {
    char pad0[0x10];
    int count;
};

struct Outer {
    char pad0[0x10];
    int cap;
    int idx;
    int size;
    char flag;
};

struct Vec3 {
    int x, y, z;
};

extern "C" int __cdecl sub_424D70(void*);
extern "C" void* __cdecl sub_9756F0(void*);
extern "C" Vec3* __cdecl sub_578440();

struct VServerReplicator {
    char pad0[0x10];
    int cap;
    int idx;
    int size;
    char flag;
    Vec3 method(int, double, Vec3*);
};

Vec3 VServerReplicator::method(int a, double d, Vec3* out) {
    char* self = (char*)this;
    char* pflag = self + 0x20;
    int b = sub_424D70(pflag);
    if (*(int*)(self + 0x1c) == 0) {
        if (pflag) *pflag = (char)b;
        return *out;
    }
    Outer* o = (Outer*)self;
    int edx = o->size;
    Inner* eax = *(Inner**)self;
    if (eax) {
        if (eax->count <= edx) {
            edx -= eax->count;
            eax = *(Inner**)eax;
        }
    }
    int* arr = (int*)((char*)eax + 0x10);
    int* ecx = (int*)((char*)arr + edx * 4);
    double v = *(double*)((char*)ecx + 0x10);
    v += d;
    double tmp = v;
    void* r = sub_9756F0(&tmp);
    double rv = *(double*)r;
    if (rv > tmp) {
        if (pflag) *pflag = (char)b;
        return *out;
    }
    Vec3* res = sub_578440();
    out->x = res->x;
    out->y = res->y;
    out->z = res->z;
    int cnt = *(int*)(self + 0x1c);
    if (cnt) {
        (*(int*)(self + 0x18))++;
        int i = *(int*)(self + 0x18);
        if (*(int*)(self + 0x14) <= i) {
            *(int*)(self + 0x18) = 0;
        }
        cnt--;
        *(int*)(self + 0x1c) = cnt;
        if (cnt == 0) {
            *(int*)(self + 0x18) = 0;
        }
    }
    if (pflag) *pflag = (char)b;
    return *out;
}
