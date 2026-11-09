// from server: 47% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct SoundService {
    char pad0[0x10c];
    void* field_10c;
    void* field_110;

    void func(void* a, void* b);
};

extern "C" void* __cdecl sub_450D00(void*);
extern "C" void __cdecl sub_432530(void*, void*);
extern "C" void __cdecl sub_541630(void*, int);
extern "C" void __cdecl sub_57AA50(void*, void*, void*);
extern "C" void* __cdecl sub_4554B0(void*);
extern "C" void __cdecl sub_58C4C0(void*, void*, void*);
extern "C" void __cdecl sub_402A60(void*, void*);
extern "C" void __cdecl sub_423240(void*, void*);
extern "C" void __cdecl sub_58CB30(void*);

void SoundService::func(void* a, void* b)
{
    void* edi;
    if (this != 0)
        edi = (char*)this + 0xe8;
    else
        edi = 0;

    if (a != 0) {
        void* eax = sub_450D00(a);
        if (eax != 0) {
            sub_432530((char*)eax + 0xe8, edi);
        }
    }

    if (this->field_10c != 0) {
        sub_541630(this->field_10c, 0);
        this->field_10c = 0;
        void* p = this->field_110;
        this->field_110 = 0;
        if (p != 0) {
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
                void** vt = *(void***)p;
                ((void (__thiscall*)(void*))vt[1])(p);
            }
            if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
                void** vt = *(void***)p;
                ((void (__thiscall*)(void*))vt[2])(p);
            }
        }
    }

    sub_57AA50(this, a, b);

    if (b != 0) {
        void* ebp = sub_4554B0(b);
        if (ebp != 0) {
            void* tmp;
            sub_58C4C0(&tmp, this, b);
            this->field_10c = *(void**)tmp;
            tmp = (char*)tmp + 4;
            sub_402A60((char*)this + 0x110, &tmp);
            void* ebx = tmp;
            if (ebx != 0) {
                if (_InterlockedExchangeAdd((volatile long*)((char*)ebx + 4), -1) == 1) {
                    void** vt = *(void***)ebx;
                    ((void (__thiscall*)(void*))vt[1])(ebx);
                }
                if (_InterlockedExchangeAdd((volatile long*)((char*)ebx + 8), -1) == 1) {
                    void** vt = *(void***)ebx;
                    ((void (__thiscall*)(void*))vt[2])(ebx);
                }
            }
            sub_541630(this->field_10c, (int)ebp);
        }
    }

    if (b != 0) {
        void* eax = sub_450D00(b);
        if (eax != 0) {
            sub_423240((char*)eax + 0xe8, (char*)this + 0xe8);
        }
        sub_58CB30(this);
    }
}
