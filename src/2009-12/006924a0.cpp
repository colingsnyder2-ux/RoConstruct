// from server: 66% by atomic.potato
struct Vector3
{
    float x;
    float y;
    float z;
};

extern "C" void __stdcall GetVector3(void*, Vector3*, unsigned int);

struct Tool
{
    Vector3 f(unsigned int);
};

Vector3 Tool::f(unsigned int index)
{
    Vector3 result;
    GetVector3((char*)this + 0x13c, &result, index);
    return result;
}
