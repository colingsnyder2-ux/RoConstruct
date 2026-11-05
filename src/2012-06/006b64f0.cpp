// from server: 12% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_5c9fe8(int, const char*, int);
extern "C" void __stdcall sub_6a9510();
extern "C" void __stdcall sub_6a5a00();
extern "C" void __stdcall sub_6b4490();
extern "C" void __stdcall sub_574350();
extern "C" void* __stdcall sub_975520(void*);
extern "C" void __stdcall sub_852bb0(double, double, int, void*);
extern "C" void __stdcall sub_568d20();

extern unsigned char byte_E31AC5;

struct Outer {
    char pad0[0xd8];
    void* ptr_d8;
    void* ptr_e0;
    char pad2[0x100 - 0xe4];
    int count_100;
    char pad3[0x1f8 - 0x104];
    char field_1f8[0x40];
    char field_238[0x40];
};

void __stdcall helper_6b64f0(Outer* self, double a, int b);

void __stdcall helper_6b64f0(Outer* self, double a, int b)
{
    char flag = 0;
    int local34 = 0;
    int local38 = 0;
    int local3c = 0;
    int local7c = 0;

    if (byte_E31AC5 != 0) {
        sub_5c9fe8((int)byte_E31AC5, (const char*)0xb95a58, 0);
    }

    int i = self->count_100;
    local7c = 0;
    if (i > 0) {
        while (1) {
            i--;
            if (!((char (__thiscall*)(void*, void*))sub_6a9510)(&self->pad2[0], &local34))
                break;
            {
                int v38 = local38;
                int v3c = local3c;
                if (v3c != 0) {
                    _InterlockedExchangeAdd((volatile long*)(v3c + 4), 1);
                }
                if (v38 != 0) {
                    _InterlockedExchangeAdd((volatile long*)(v38 + 4), 1);
                }
            }
            ((void (__thiscall*)(Outer*))sub_6b4490)(self);
            ((void (__thiscall*)(void*))sub_574350)(&self->field_1f8[0]);
            {
                double* d = (double*)sub_975520(&local34);
                double dv = *d;
                if (a > dv) {
                    flag = 1;
                } else {
                    if (i > 0) continue;
                    break;
                }
            }
            break;
        }
    }

    local7c = -1;
    ((void (__thiscall*)(void*))sub_6a5a00)(&local34);

    if (self->ptr_e0 != 0) {
        double dv = *(double*)((char*)self->ptr_d8 + 0xb0);
        sub_852bb0(a, dv, b, &flag);
    }

    {
        int fi = (int)flag;
        double fd = (double)fi;
        ((void (__thiscall*)(void*, double))sub_568d20)(&self->field_238[0], fd);
    }

    if (byte_E31AC5 != 0) {
        sub_5c9fe8((int)byte_E31AC5, (const char*)0xb95a2c, 0);
    }
}
