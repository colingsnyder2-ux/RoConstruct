// from server: 91% by atomic.potato
extern "C" void* __cdecl RBX_4729B0();
extern "C" void __stdcall EnterCriticalSection(void*);
extern "C" void __stdcall LeaveCriticalSection(void*);

struct MultiJoint
{
    char padding[24];
    int value;
};

void __cdecl f(int* result)
{
    MultiJoint* object = (MultiJoint*)RBX_4729B0();
    EnterCriticalSection(object);
    *result = object->value;
    object->value = (int)result;
    LeaveCriticalSection(object);
}
