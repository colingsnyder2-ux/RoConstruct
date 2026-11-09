// from server: 73% by atomic.potato
struct BoundPropGetSet
{
    void get(float* out, float* value);
    char* data;
};

void __thiscall BoundPropGetSet::get(float* out, float* value)
{
    char* p = value ? (char*)value - 0x1c : 0;
    p = data + ((char*)p - data);
    out[0] = *(float*)p;
    out[1] = *(float*)(p + 4);
    out[2] = *(float*)(p + 8);
}
