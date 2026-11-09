// from server: 92% by atomic.potato
extern "C" int __stdcall GetMatrixElement(char*, int);

struct RotatePJoint
{
    int GetValue();
};

int RotatePJoint::GetValue()
{
    char* value = *(char**)((char*)this + 0xb4);
    return GetMatrixElement(value + 0xd0, 1);
}
