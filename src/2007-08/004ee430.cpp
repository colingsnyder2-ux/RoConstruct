// from server: 26% by colin
// roc 2007-08 004ee430  unit: HeadBuilder  size: 484 bytes

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);

extern "C" void* __cdecl sub_62FEF6(unsigned int);
extern "C" void __cdecl sub_4F6180();
extern "C" void __cdecl sub_4DD250();
extern "C" void __cdecl sub_474F70();
extern "C" void __cdecl sub_4EB510();
extern "C" void __cdecl sub_5BA1C0();
extern "C" void __cdecl sub_50B010();
extern "C" void __cdecl sub_4EEC20();
extern "C" void __cdecl sub_457DD0();

struct HeadBuilder {
    void ctor(float* a, float* b, int c);
};

void HeadBuilder::ctor(float* a, float* b, int c)
{
    float f1, f2, f3;
    float* p;
    void* obj;
    void* obj2;
    float v1, v2, v3;
    float d1, d2;
    unsigned char flag;

    sub_4F6180();
    *(void**)this = (void*)0x79F4AC;

    f1 = a[2];
    f2 = a[0];
    if (!(f1 > f2)) {
        p = a;
    } else {
        p = a + 2;
    }

    f3 = p[0] * *(double*)0x79F348;
    v1 = f3;

    obj = sub_62FEF6(0x1C);
    if (obj != 0) {
        *(void**)obj = (void*)0x797984;
        *(void**)((char*)obj + 4) = 0;
        *(void**)((char*)obj + 8) = 0;
        *(void**)obj = (void*)0x79F304;
        *(void**)((char*)obj + 0x10) = 0;
        *(void**)((char*)obj + 0x14) = 0;
        *(void**)((char*)obj + 0xC) = 0;
        *(int*)((char*)obj + 0x18) = 5;
        obj2 = obj;
    } else {
        obj2 = 0;
    }

    if (obj2 != 0) {
        InterlockedIncrement((long*)((char*)obj2 + 4));
    }

    sub_4DD250();

    if (obj2 != 0) {
        if (InterlockedDecrement((long*)((char*)obj2 + 4)) == 0) {
            sub_457DD0();
            (*(void(__thiscall**)(void*, int))*(void**)obj2)(obj2, 1);
        }
    }

    v2 = a[0];
    v3 = a[1];
    d1 = a[2];

    sub_474F70();

    sub_4EB510();

    sub_5BA1C0();

    sub_50B010();

    d2 = *(float*)0x795C08;

    v1 = v1 * d2;
    v2 = v2 * d2;

    v1 = v1 / *(float*)0x795C08;
    v2 = v2 / *(float*)0x795C08;

    sub_4EEC20();

    if (obj2 != 0) {
        if (InterlockedDecrement((long*)((char*)obj2 + 4)) == 0) {
            sub_457DD0();
            if (obj2 != 0) {
                (*(void(__thiscall**)(void*, int))*(void**)obj2)(obj2, 1);
            }
        }
    }
}
