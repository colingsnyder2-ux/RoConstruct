// from server: 100% by king_originala
extern int typeTag;
extern "C" unsigned int* __cdecl getValue(void*, int, int);
extern "C" void __cdecl pushBoolean(void*, int);

int __cdecl compareValues(void* state)
{
    unsigned int* first = getValue(state, 1, typeTag);
    unsigned int* second = getValue(state, 2, typeTag);
    pushBoolean(state, *first == *second);
    return 1;
}
