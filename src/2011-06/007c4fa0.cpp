// from server: 81% by atomic.potato
extern "C" void G1_func_007599c0(void *, void *);

struct BallPolyContact
{
    int value;
    int padding[50];
    int field_cc;
};

BallPolyContact * __stdcall func_007c4fa0(BallPolyContact *obj, void *arg)
{
    G1_func_007599c0(obj, arg);
    obj->value = 0xabd4d8;
    obj->field_cc = 0;
    return obj;
}
