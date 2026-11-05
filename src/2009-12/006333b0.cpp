// from server: 18% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl _invalid_parameter_noinfo();

struct VBase {
    void* vfptr;
    void* field4;
};

struct SharedPtr {
    void* px;
    void* pi;
};

struct Obj {
    void* vfptr;
    char pad[0x48];
    void* field4c;
};

struct Container {
    char pad[0x50];
    SharedPtr sp;
};

extern "C" void __stdcall sub_4ffeb0(SharedPtr* dst, SharedPtr* src);
extern "C" char __stdcall sub_5122b0(Obj* self, void* arg);

void __cdecl sub_6333b0(Obj* self, Obj* other, Obj* arg3, Obj* arg4)
{
    Obj* esi = self;
    Obj* edi = other;
    if (esi != 0 && esi != arg3) {
        Obj* eax = arg3;
        while (1) {
            if (eax != 0) {
                void* p = *(void**)((char*)eax + 0x4c);
                if (p == esi) break;
                if (sub_5122b0(esi, p)) break;
            }
            void** vt = *(void***)esi;
            void (*fn)(Obj*, Obj*) = (void (*)(Obj*, Obj*))vt[0x2c/4];
            fn(esi, edi);
            esi = *(Obj**)((char*)esi + 0x4c);
            if (esi == 0) break;
            eax = arg3;
        }
    }

    Container* c = (Container*)edi;
    SharedPtr local;
    sub_4ffeb0(&local, &c->sp);

    void* ebp = local.px;
    if (ebp != 0) {
        char* edi2 = *(char**)((char*)ebp + 0xc);
        char* ebx = *(char**)((char*)ebp + 0x10);
        void* esi2 = *(void**)ebp;
        if (edi2 != ebx) {
            while (1) {
                sub_6333b0((Obj*)edi2, arg3, arg4, 0);
                edi2 += 8;
                if (edi2 == ebx) break;
            }
        }
    }

    if (local.pi != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)local.pi + 4), -1) == 1) {
            void** vt = *(void***)local.pi;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(local.pi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)local.pi + 8), -1) == 1) {
                void** vt2 = *(void***)local.pi;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(local.pi);
            }
        }
    }
}
