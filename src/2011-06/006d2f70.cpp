// from server: 56% by atomic.potato
typedef int Value;

struct RotatePJoint
{
    Value *field;
    Value f();
};

extern "C" Value Ball(Value *, int);

Value RotatePJoint::f()
{
    return Ball(field + 0x33, 2);
}
