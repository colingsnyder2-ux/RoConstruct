// from server: 100% by king_originala
extern "C" const char* __cdecl getText(void*, int, unsigned int*);
extern "C" void* __cdecl getObject(void*, int, const char*);
extern "C" void __cdecl invoke(void*, const char*, void*);

extern const char* objectType;

int __cdecl function_005a89d0(void* state)
{
    const char* text = getText(state, 2, 0);
    void* object = getObject(state, 1, objectType);
    invoke(object, text, state);
    return 0;
}
