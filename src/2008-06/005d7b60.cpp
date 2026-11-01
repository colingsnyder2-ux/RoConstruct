// from server: 100% by king_originala
struct Storage
{
    char padding[0x150];
};

struct VirtualBase
{
    int value;
};

struct Object : Storage, virtual VirtualBase
{
};

struct GetSetImpl
{
    char padding[8];
    float* (Object::*get)();

    float* getValue(float* out, void* obj);
};

float* GetSetImpl::getValue(float* out, void* obj)
{
    Object* object = obj ? (Object*)((char*)obj - 0x14) : 0;
    float* result = (object->*get)();
    out[0] = result[0];
    out[1] = result[1];
    out[2] = result[2];
    return out;
}
