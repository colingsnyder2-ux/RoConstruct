// from server: 100% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
extern "C" long __cdecl _InterlockedIncrement(volatile long*);
#pragma intrinsic(_InterlockedExchangeAdd)
#pragma intrinsic(_InterlockedIncrement)

struct Sub_007fe830 {
    char  pad0[0x38];
    int   field_38;
    char* field_3c;
    int   field_40;
    char* field_44;
    void  assign_007fc780(const Sub_007fe830* other);
};

struct Big_007fe830 {
    int           field_00;
    int           pad_04;
    Sub_007fe830  sub_08;
    Big_007fe830* fn_007fe830(int a, const Sub_007fe830* src);
};

Big_007fe830* Big_007fe830::fn_007fe830(int a, const Sub_007fe830* src)
{
    Sub_007fe830* sub = &sub_08;
    field_00 = a;
    sub->assign_007fc780(src);
    sub->field_38 = src->field_38;
    sub->field_3c = src->field_3c;
    if (sub->field_3c)
        _InterlockedIncrement((volatile long*)(sub->field_3c + 8));
    sub->field_40 = src->field_40;
    sub->field_44 = src->field_44;
    if (sub->field_44)
        _InterlockedIncrement((volatile long*)(sub->field_44 + 4));
    return this;
}
