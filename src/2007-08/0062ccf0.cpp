// from server: 39% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct V3 {
    float x, y, z;
};

struct RefCounted {
    void* vptr;
    volatile long refCount;
    volatile long weakCount;
};

struct GroupDragTool {
    char pad0[0x14];
    void* field14;
    char pad1[0x0c];
    void* field24;
    int field28;
    float f2c;
    float f30;
    float f34;
    char pad2[0x1c];
    void* field54;
    char pad3[0x08];
    void* field60;
    void* field64;
    void method_62c670();
    void method_62ccf0();
};

extern void func_530100(void*);
extern void func_5095d0(void*, void*);
extern void func_509750(void*, void*, void*);
extern void func_5099a0(void*, void*, void*);
extern void func_51d890(void*, void*, void*, void*, void*);
extern void func_51d9d0(void*, void*, void*);
extern void func_5ab440(void*, void*, void*);
extern void* func_5ab6b0(void*, void*);
extern void func_5ac1f0(void*);
extern void func_5ac3d0(void*, void*, void*);
extern void func_5bd0f0(void*, void*);
extern void func_5e2010(void*, void*);
extern void* func_5fc7f0(void*);
extern void func_577de0(void*, void*);
extern void func_4a04a0(void*, void*);

extern float g_78fef0;
extern float g_797e9c;

void GroupDragTool::method_62ccf0()
{
    void* p24 = this->field24;
    void* edi = *(void**)((char*)p24 + 0x64);
    func_530100(edi);

    int ecx = this->field28;
    int eax = ecx / 3;
    int rem = ecx - eax * 3;
    int edx = 1 - eax * 2;

    float* ebx = (float*)((char*)edi + 0x84);
    float f0 = ebx[rem];
    float f1 = ebx[rem + 3];
    float f2 = ebx[rem + 6];

    float fd = (float)edx;
    float a = f0 * fd;
    float b = f1 * fd;
    float c = f2 * fd;

    void* p14 = this->field14;
    void* edi2 = *(void**)((char*)p14 + 0x64);
    func_530100(edi2);

    char buf1[0x100];
    func_5095d0(buf1, (char*)edi2 + 0x84);

    char buf2[0x100];
    func_5ab440(buf2, buf1, ebx);

    char buf3[0x100];
    func_5099a0(buf3, buf2, (char*)this + 0x160);
    func_509750(buf3, buf3, (char*)this + 0x13c);

    char buf4[0x100];
    func_5099a0(buf4, (char*)this + 0x13c, (char*)this + 0x11c);
    func_509750(buf4, buf4, ebx);

    func_5ac1f0((char*)this + 0x84);

    func_530100(edi2);
    func_5095d0((char*)this + 0x20, (char*)this + 0x84);

    V3 v;
    v.x = *(float*)((char*)edi2 + 0xa8);
    v.y = *(float*)((char*)edi2 + 0xac);
    v.z = *(float*)((char*)edi2 + 0xb0);

    func_5e2010(edi2, &v);

    V3 neg;
    neg.x = -a;
    neg.y = -b;
    neg.z = -c;

    void* r = func_5ab6b0((char*)this + 0x84, &neg);
    this->field60 = r;

    float fx = v.x * this->f2c + v.y * this->f30 + v.z * this->f34 + *(float*)((char*)this + 0x54);
    float fy = v.x * this->f2c + v.y * this->f30 + v.z * this->f34 + *(float*)((char*)this + 0x58);
    float fz = v.x * this->f2c + v.y * this->f30 + v.z * this->f34 + *(float*)((char*)this + 0x5c);

    func_51d890((char*)this + 0x54, &v, &fx, &fy, &fz);

    char buf5[0x100];
    func_51d9d0((char*)this + 0xfc, (char*)this + 0xe4, &v);

    void* p14b = this->field14;
    void* p60 = *(void**)((char*)p14b + 0x60);
    float s = g_797e9c;
    float sx = *(float*)((char*)p60 + 4) * s;
    float sy = *(float*)((char*)p60 + 8) * s;
    float sz = *(float*)((char*)p60 + 12) * s;

    float nx = -sx;
    float ny = -sy;
    float nz = -sz;

    func_5bd0f0(this->field60, &nx);

    char buf6[0x100];
    func_5ac3d0((char*)this + 0x64, (char*)this + 0xac, &nx);

    float t = g_78fef0;
    float tx = nx * t;
    float ty = ny * t;
    float tz = nz * t;

    func_4a04a0((char*)this + 0x64, &tx);

    float ax = tx * *(float*)((char*)this + 0x1c) + ty * *(float*)((char*)this + 0x20) + tz * *(float*)((char*)this + 0x18) + *(float*)((char*)this + 0x40);
    float ay = tx * *(float*)((char*)this + 0x1c) + ty * *(float*)((char*)this + 0x20) + tz * *(float*)((char*)this + 0x18) + *(float*)((char*)this + 0x44);
    float az = tx * *(float*)((char*)this + 0x1c) + ty * *(float*)((char*)this + 0x20) + tz * *(float*)((char*)this + 0x18) + *(float*)((char*)this + 0x48);

    void* r2 = func_5fc7f0(this);
    void* r3 = *(void**)r2;
    func_577de0(r3, &ax);

    RefCounted* rc = (RefCounted*)this->field64;
    if (rc) {
        if (_InterlockedExchangeAdd(&rc->refCount, -1) == 1) {
            void** vt = *(void***)rc;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(rc);
            if (_InterlockedExchangeAdd(&rc->weakCount, -1) == 1) {
                void** vt2 = *(void***)rc;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(rc);
            }
        }
    }

    this->method_62c670();
}
