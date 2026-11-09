// from server: 52% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __stdcall sub_6dbf60(void*);
extern "C" void* __stdcall sub_5076f0(void*, void*);
extern "C" void __stdcall sub_4026a0(void*, void*);
extern "C" void* __stdcall sub_888470(void*);
extern "C" void __stdcall sub_b22658(void*, void*);

struct RefCounted {
    void* vptr;
    long refcount;
    long weakref;
};

struct FunctionalTest {
    char pad0[0x80];
    void* field80;
    char pad84[4];
    char field88;
    char pad89[3];
    char field8c[0x1c];
    double fielda8;
    char fieldb0;
    char fieldb1;
    char fieldb2;
    void method(void* arg1, int arg2);
};

void FunctionalTest::method(void* arg1, int arg2)
{
    if (arg1 == 0)
        return;

    void* p = sub_6dbf60(arg1);
    void* tmp;
    sub_5076f0(&tmp, p);
    this->field80 = *(void**)tmp;
    sub_4026a0(&this->field80 + 1, (char*)tmp + 4);

    if (tmp != 0) {
        RefCounted* rc = (RefCounted*)tmp;
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            ((void (__stdcall*)(void*))rc->vptr)(rc);
            if (_InterlockedExchangeAdd(&rc->weakref, -1) == 1) {
                ((void (__stdcall*)(void*))((void**)rc->vptr)[2])(rc);
            }
        }
    }

    if (this->field80 != 0)
        return;

    void* p2 = sub_888470(arg1);
    void* tmp2;
    sub_5076f0(&tmp2, p2);
    this->field80 = *(void**)tmp2;
    sub_4026a0(&this->field80 + 1, (char*)tmp2 + 4);

    if (tmp2 != 0) {
        RefCounted* rc = (RefCounted*)tmp2;
        if (_InterlockedExchangeAdd(&rc->refcount, -1) == 1) {
            ((void (__stdcall*)(void*))rc->vptr)(rc);
            if (_InterlockedExchangeAdd(&rc->weakref, -1) == 1) {
                ((void (__stdcall*)(void*))((void**)rc->vptr)[2])(rc);
            }
        }
    }

    if (this->field88 == 0)
        return;

    sub_b22658((char*)this->field80 + 0xd0, this->field8c);
    *(double*)((char*)this->field80 + 0xf0) = this->fielda8;
    *(char*)((char*)this->field80 + 0xf8) = this->fieldb0;
    *(char*)((char*)this->field80 + 0xf9) = this->fieldb1;
    *(char*)((char*)this->field80 + 0xfa) = this->fieldb2;
    this->field88 = 1;
}
