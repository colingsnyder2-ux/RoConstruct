// from server: 100% by colin
struct ICameraSubject {
    char pad[0xbc];
    void* field_bc;
    ICameraSubject* find();
};

extern "C" void* __cdecl func_00630d36(void*, void*, void*, void*, void*);

ICameraSubject* ICameraSubject::find()
{
    ICameraSubject* result = this;
    void* v = func_00630d36(field_bc, 0, (void*)0x881f4c, (void*)0x898fc0, 0);
    if (v != 0) {
        do {
            result = (ICameraSubject*)v;
            v = func_00630d36(*(void**)((char*)v + 0xbc), 0, (void*)0x881f4c, (void*)0x898fc0, 0);
        } while (v != 0);
    }
    return result;
}
