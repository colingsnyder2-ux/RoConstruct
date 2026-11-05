// from server: 69% by atomic.potato
struct CopyTarget
{
    float pad0[9];
};

struct Backpack
{
    char pad0[204];
    CopyTarget value;
    void f(CopyTarget *target);
};

void __fastcall CopyTarget_copy(CopyTarget *destination, CopyTarget *source);

void Backpack::f(CopyTarget *target)
{
    CopyTarget_copy(target, &value);
    target->pad0[9] = value.pad0[9];
    target->pad0[10] = value.pad0[10];
    target->pad0[11] = value.pad0[11];
}
