// from server: 24% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct ModelInstance {
    char pad0[0x38];
    void* field_38;
    void* field_3c;
    char pad2[0xcc - 0x40];
    void* field_cc;

    void func_67fc30();
};

struct Helper {
    void* f0;
    void* f4;
    void* f8;
};

extern "C" void* __fastcall sub_6a2ce0(void* self, void*, void* out);
extern "C" void __fastcall sub_41d110(void* self, void*, void* arg);
extern "C" void __fastcall sub_754980(void* self, void*);
extern "C" void __fastcall sub_67f390(void* self, void*, void* a, void* b, void* c);

extern float g_9ab804;

void ModelInstance::func_67fc30()
{
    void* local14 = 0;
    void* local18 = 0;
    void* local1c = 0;
    void* local20 = 0;
    void* local28 = 0;
    void* local30 = 0;

    void* ebx;
    void* ebp;

    sub_6a2ce0(&this->field_3c, 0, &local14);
    ebx = *(void**)&local14;

    if (local18) {
        ebp = local18;
        if (_InterlockedExchangeAdd((volatile long*)((char*)ebp + 4), -1) == 1) {
            void** vt = *(void***)ebp;
            ((void(__fastcall*)(void*, void*))vt[1])(ebp, 0);
            if (_InterlockedExchangeAdd((volatile long*)((char*)ebp + 8), -1) == 1) {
                void** vt2 = *(void***)ebp;
                ((void(__fastcall*)(void*, void*))vt2[2])(ebp, 0);
            }
        }
    }

    if (ebx) {
        sub_6a2ce0(&this->field_3c, 0, &local14);
        void* ecx = *(void**)&local14;
        ecx = *(void**)((char*)ecx + 0x4c);
        void* eax = (char*)this - 0x94;
        local30 = 0;
        char al;
        if (eax == ecx) {
            al = 1;
        } else if (ecx) {
            sub_41d110(ecx, 0, eax);
            al = 1;
        } else {
            al = 0;
        }
        ebp = local18;
        char bl = (al == 0);
        local30 = (void*)-1;
        if (ebp) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)ebp + 4), -1) == 1) {
                void** vt = *(void***)ebp;
                ((void(__fastcall*)(void*, void*))vt[1])(ebp, 0);
                if (_InterlockedExchangeAdd((volatile long*)((char*)ebp + 8), -1) == 1) {
                    void** vt2 = *(void***)ebp;
                    ((void(__fastcall*)(void*, void*))vt2[2])(ebp, 0);
                }
            }
        }
        if (bl) {
            sub_754980(&this->field_3c, 0);
        }
    }

    sub_6a2ce0(&this->field_3c, 0, &local14);
    ebp = local18;
    ebx = *(void**)&local14;
    if (ebp) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)ebp + 4), -1) == 1) {
            void** vt = *(void***)ebp;
            ((void(__fastcall*)(void*, void*))vt[1])(ebp, 0);
            if (_InterlockedExchangeAdd((volatile long*)((char*)ebp + 8), -1) == 1) {
                void** vt2 = *(void***)ebp;
                ((void(__fastcall*)(void*, void*))vt2[2])(ebp, 0);
            }
        }
    }

    if (ebx) {
        this->field_38 = 0;
        sub_6a2ce0(&this->field_3c, 0, &local14);
        void* edi = *(void**)&local14;
        void* esi = local18;
        if (esi) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 4), -1) == 1) {
                void** vt = *(void***)esi;
                ((void(__fastcall*)(void*, void*))vt[1])(esi, 0);
                if (_InterlockedExchangeAdd((volatile long*)((char*)esi + 8), -1) == 1) {
                    void** vt2 = *(void***)esi;
                    ((void(__fastcall*)(void*, void*))vt2[2])(esi, 0);
                }
            }
        }
        return;
    }

    if (this->field_38 == 0) {
        float f = g_9ab804;
        void* ecx = (char*)this - 0x94;
        void* eax = (char*)ecx + 0xcc;
        *(void**)eax = 0;
        local20 = eax;
        local1c = 0;
        local14 = 0;
        local28 = (void*)0x67e2d0;
        *(float*)&local14 = f;
        sub_67f390(ecx, 0, &local1c, &local14, &local20);
    }
}
