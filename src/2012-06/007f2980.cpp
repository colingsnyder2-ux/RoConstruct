// from server: 42% by atomic.potato
struct VGuiObject {
    void* construct(void* other);
    void assign(void* obj);
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl operator_delete(void* p);

void* VGuiObject::construct(void* other)
{
    void* mem = operator_new(0x38);
    void* obj = mem;
    if (obj != 0) {
        *(void**)((char*)obj + 0) = (void*)0x00bc2e8c;
        *(void**)((char*)obj + 8) = (void*)0x00bc2e84;
    } else {
        obj = 0;
    }
    assign(obj);
    if (obj != 0) {
        operator_delete((char*)obj + 5);
    }
    return obj;
}
