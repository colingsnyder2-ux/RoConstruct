// from server: 68% by atomic.potato
typedef unsigned int DWORD;

extern "C" int CallProperty(void*, void*, void*);
extern "C" int Function6A38B0(int, int);

struct S
{
    char pad[28];
    void* object;
    int f(void*, void*);
};

int S::f(void* a, void* b)
{
    void* p = *(void**)((char*)object);
    void* fn = *(void**)((char*)p + 12);
    int value = ((int (__thiscall*)(void*, void*, void*))fn)(p, &b, a);
    return Function6A38B0((int)b, value);
}
