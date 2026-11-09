// from server: 100% by king_originala
struct S {
    unsigned int allocator;
    union {
        char buffer[16];
        char* pointer;
    } storage;
    unsigned int length;
    unsigned int capacity;
};

extern S* __cdecl func_00568460(S*);
extern int (__stdcall *DeleteFileA)(const char*);
extern void (__thiscall *destroy_string)(S*);

void func_005684d0()
{
    S temporary;
    S* result = func_00568460(&temporary);
    DeleteFileA(result->capacity >= 16
        ? result->storage.pointer
        : result->storage.buffer);
    destroy_string(&temporary);
}
