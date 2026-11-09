// from server: 80% by atomic.potato
typedef unsigned char Byte;

extern "C" void* __cdecl Function5dc670(Byte*);
extern "C" void __cdecl Function62bea0(Byte*);

int Function62c780(Byte* p)
{
    Byte buffer[136];
    void* value = Function5dc670(buffer);
    int result = *(int*)((Byte*)value + 4);
    Function62bea0(buffer);
    return result;
}
