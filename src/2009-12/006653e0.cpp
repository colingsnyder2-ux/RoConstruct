// from server: 90% by atomic.potato
extern "C" float __fastcall sub_00774cb0(void *);
extern "C" float __fastcall sub_00775580(void *);

struct S_func_006653e0 {
    float f();
};

float S_func_006653e0::f()
{
    float x = sub_00774cb0(this);
    x += sub_00775580(this);
    return x;
}
