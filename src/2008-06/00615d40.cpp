// from server: 100% by colin
extern "C" void __cdecl sub_615c30(void*, void*, void*);

struct S
{
    char padding[0x18];
    char* object;
    void* f(void* result, void* input);
};

void* S::f(void* result, void* input)
{
    char* p = object;
    volatile int state = 0;
    void* adjusted = p ? p + 0x288 : 0;
    sub_615c30(result, input, adjusted);
    return result;
}
