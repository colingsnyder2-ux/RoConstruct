// from server: 100% by atomic.potato
typedef unsigned int DWORD;

extern "C" void* __stdcall sub_00480e20(void*);

struct S {
    int f(void*);
};

int S::f(void* value)
{
    void* result = sub_00480e20(value);
    if (result)
        return *(int*)((char*)result + 8);
    return 1;
}
