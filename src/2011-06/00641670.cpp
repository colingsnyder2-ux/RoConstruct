// from server: 59% by atomic.potato
extern "C" void* __cdecl sub_640a80(void*);

struct RefPropDescriptor
{
    void* field44;
    void* f();
};

void* RefPropDescriptor::f()
{
    void* value = sub_640a80(this);
    void* current = field44;
    while (current != value)
        current = *(void**)((char*)current + 68);
    return current == value ? this : current;
}
