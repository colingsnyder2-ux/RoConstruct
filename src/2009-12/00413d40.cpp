// from server: 92% by atomic.potato
extern "C" void __cdecl _invalid_parameter_noinfo();

struct CopyVerb
{
    unsigned char padding[0x98];
    struct Vector
    {
        int* begin;
        int* unused;
        unsigned int capacity;
        unsigned int size;
    };
    Vector* vector;
    int* copy(int* result);
};

int* CopyVerb::copy(int* result)
{
    Vector* v = vector;
    unsigned int count = v->capacity;
    result[0] = 0;
    if (v->size > count)
        _invalid_parameter_noinfo();
    result[0] = (int)v->begin;
    result[1] = count;
    return result;
}
