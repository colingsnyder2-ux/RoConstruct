// from server: 76% by atomic.potato
struct S {
};

void __cdecl f(void* value, void** result)
{
    if (value != 0) {
        *(void**)((char*)value + 0x70) = *result;
        *result = (void*)((char*)value + 0x70);
    } else {
        *result = 0;
    }
}
