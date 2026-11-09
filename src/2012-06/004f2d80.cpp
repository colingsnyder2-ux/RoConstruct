// from server: 66% by atomic.potato
extern "C" void __stdcall OgreMeshPtrCopy(void* destination, const void* source);

struct LevelGenFunc
{
    int f(void* value);
};

int LevelGenFunc::f(void* value)
{
    OgreMeshPtrCopy((char*)this + 12, value);
    return (int)value;
}
