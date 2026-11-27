// from server: 100% by Xemicl
// roc-cl: 30729
// roc-flags: /O2 /GS- /EHsc /MD

struct Slot { virtual void call(float, float); int a; };
struct Obj { char pad[8]; Slot slot; int connected; };
void fire(Obj* obj, float a, float b)
{
    if (obj->connected != 0)
        obj->slot.call(a, b);
}
