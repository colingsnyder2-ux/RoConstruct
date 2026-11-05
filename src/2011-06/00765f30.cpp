// from server: 43% by atomic.potato
extern "C" void* __stdcall sub_004f1200(void*, void*, void*);

struct LuaArguments
{
    void* value;
    void* getValue(int);
};

void* LuaArguments::getValue(int index)
{
    void* result;
    sub_004f1200((char*)value + 0x2c, &result, (void*)index);
    return result;
}
