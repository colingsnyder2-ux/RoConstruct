// from server: 39% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_4D2DF0(void*, float);
extern "C" void __cdecl sub_475050(void*);
extern "C" void __cdecl sub_4D72D0(void*, void*);
extern "C" void __cdecl sub_4D7380(void*, void*);
extern "C" void __cdecl sub_4D2C30(void*, void*, void*, void*);
extern "C" void __cdecl sub_4AC3D0(void*, void*, void*, void*);
extern "C" void __cdecl sub_42C020(void*, void*, void*, void*);
extern "C" void __cdecl sub_728640(void*, void*);
extern "C" void __cdecl sub_728460(void*);
extern "C" void __cdecl sub_49A230(void*);
extern "C" void __cdecl sub_457DD0(void*);
extern "C" void* __stdcall sub_77D2EC(void*);
extern "C" int __stdcall sub_77D2E8(void*);

struct Texture {
    void construct(void* a, float f, void* b, void* c);
};

void Texture::construct(void* a, float f, void* b, void* c)
{
    char* self = (char*)this;
    sub_4D2DF0(self, f);
    *(void**)self = (void*)0x79F180;
    sub_475050(self + 0x1c);

    *(void**)(self + 0x50) = 0;
    *(void**)(self + 0x54) = 0;
    *(char*)(self + 0x58) = 0;
    *(char*)(self + 0x5c) = 0;
    *(void**)(self + 0x64) = 0;
    *(void**)(self + 0x68) = 0;
    *(char*)(self + 0x6c) = 0;
    *(char*)(self + 0x70) = 0;
    *(void**)(self + 0x78) = 0;
    *(void**)(self + 0x7c) = 0;
    *(char*)(self + 0x80) = 0;
    *(char*)(self + 0x84) = 0;
    *(void**)(self + 0x8c) = 0;
    *(void**)(self + 0x90) = 0;
    *(char*)(self + 0x94) = 0;
    *(char*)(self + 0x98) = 0;
    *(void**)(self + 0xa0) = 0;
    *(void**)(self + 0xa4) = 0;
    *(char*)(self + 0xa8) = 0;
    *(char*)(self + 0xac) = 0;

    *(void**)(self + 0xb0) = *(void**)a;
    void* p = *(void**)((char*)a + 4);
    *(void**)(self + 0xb4) = p;
    if (p != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)p + 4), 1);
    }
    *(void**)(self + 0xb8) = 0;
    *(char*)(self + 0xbc) = 1;
    *(void**)(self + 0xc0) = 0;
    *(void**)(self + 0xc4) = b;
    *(void**)(self + 0xc8) = 0;

    sub_77D2EC(self + 4);

    void* v = *(void**)((char*)c + 0x48);
    void** vt = *(void***)v;
    void (*fn)(void*, void*) = (void (*)(void*, void*))vt[1];
    void* tmp = 0;
    fn(v, &tmp);
    if (tmp != 0) {
        if (sub_77D2E8((char*)tmp + 4) == 0) {
            sub_457DD0(tmp);
            if (tmp != 0) {
                void** vt2 = *(void***)tmp;
                void (*fn2)(void*, int) = (void (*)(void*, int))vt2[0];
                fn2(tmp, 1);
            }
        }
    }

    {
        char local[0x20];
        *(void**)(local + 0) = (void*)0x4D7790;
        *(void**)(local + 4) = self;
        *(void**)(local + 8) = self;
        sub_4D72D0(local + 0x20, local);
    }

    {
        void* p2 = *(void**)a;
        void* p3 = (p2 != 0) ? (char*)p2 + 4 : 0;
        char local2[0x20];
        sub_4AC3D0((void*)0x8C1580, p3, local2 + 0x10, local2 + 0x20);
        sub_728640(self + 0x4c, local2 + 0x10);
        sub_728460(local2 + 0x10);
        sub_49A230(local2 + 0x20);
    }

    {
        char local[0x20];
        *(void**)(local + 0) = (void*)0x4D1C60;
        *(void**)(local + 4) = self;
        *(void**)(local + 8) = self;
        sub_4D72D0(local + 0x20, local);
    }

    {
        void* p2 = *(void**)a;
        void* p3 = (p2 != 0) ? (char*)p2 + 4 : 0;
        char local2[0x20];
        sub_4AC3D0((void*)0x8C13F0, p3, local2 + 0x10, local2 + 0x20);
        sub_728640(self + 0x60, local2 + 0x10);
        sub_728460(local2 + 0x10);
        sub_49A230(local2 + 0x20);
    }

    {
        char local[0x20];
        *(void**)(local + 0) = (void*)0x4D0F40;
        *(void**)(local + 4) = self;
        *(void**)(local + 8) = self;
        sub_4D72D0(local + 0x20, local);
    }

    {
        void* p2 = *(void**)a;
        void* p3 = (p2 != 0) ? (char*)p2 + 4 : 0;
        char local2[0x20];
        sub_4AC3D0((void*)0x8C13CC, p3, local2 + 0x10, local2 + 0x20);
        sub_728640(self + 0x74, local2 + 0x10);
        sub_728460(local2 + 0x10);
        sub_49A230(local2 + 0x20);
    }

    {
        char local[0x20];
        *(void**)(local + 0) = (void*)0x4D0390;
        *(void**)(local + 4) = self;
        *(void**)(local + 8) = self;
        sub_4D7380(local + 0x20, local);
    }

    {
        void* p2 = *(void**)a;
        void* p3 = (p2 != 0) ? (char*)p2 + 4 : 0;
        char local2[0x20];
        sub_42C020((void*)0x8C1608, p3, local2 + 0x10, local2 + 0x20);
        sub_728640(self + 0x88, local2 + 0x10);
        sub_728460(local2 + 0x10);
        sub_49A230(local2 + 0x20);
    }

    {
        void* p2 = *(void**)a;
        void* args[3];
        args[0] = (void*)0x4D7790;
        args[1] = self;
        args[2] = self;
        sub_4D2C30(p2, args, args + 1, args + 2);
    }
}
