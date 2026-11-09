// from server: 80% by atomic.potato
extern "C" void* __cdecl Function5DC670(void*);
extern "C" void* __cdecl Function62BEA0(void*);

int Function62BF40(void* value)
{
    char buffer[136];
    int result = *(int*)((char*)Function5DC670(buffer) + 12);
    Function62BEA0(buffer);
    return result;
}
