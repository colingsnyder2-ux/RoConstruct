// from server: 100% by Espeon
extern "C" void _ReadWriteBarrier();
#pragma intrinsic(_ReadWriteBarrier)
// from server: 87% by colin
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
extern "C" double __cdecl fabs(double);
#pragma intrinsic(fabs)

extern const float toleranceBase;
extern const float toleranceScale;
extern char descriptor;

struct Target {
    char padding[0x94];
    float value;
};

struct S {
    char padding[0x150];
    Target* target;

    void notify(const void* descriptor);
    void f(float value);
};

void S::f(float value)
{
    Target* object=target;
    float previous=object->value;
    _ReadWriteBarrier();
    if (value != previous &&
        !(fabs(value - previous) <=
            (fabs(value) + toleranceBase) * toleranceScale)) {
        object->value = value;
        notify(&descriptor);
    }
}
