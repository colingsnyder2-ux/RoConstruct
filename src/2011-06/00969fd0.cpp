// from server: 52% by atomic.potato
typedef unsigned int DWORD;

extern "C" void* __stdcall imported_remove_child(void* node, const char* name);

struct S
{
    void* f(const char* name);
    void* function_00969f20(void* child);
};

void* S::f(const char* name)
{
    void* child = imported_remove_child(this, name);
    function_00969f20(child);
    return child;
}

void* S::function_00969f20(void* child)
{
    return 0;
}
