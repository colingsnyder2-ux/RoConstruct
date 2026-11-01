// from server: 100% by king_originala
struct S {
    char padding[32];
    void** value;
};

extern "C" void* __stdcall convert(void*);
extern "C" void __cdecl release(void*);

void __cdecl clear(S* object)
{
    void** value = object->value;
    if (*value) {
        release(convert(*value));
        *value = 0;
    }
}
