// from server: 70% by colin
struct ChangePropertyItem {
    void* field0;
    void* field4;
    void* ChangePropertyItem_impl(void*);
};

extern "C" void* __cdecl sub_00630d36(void*, void*, void*, void*, void*);
extern "C" void* __cdecl sub_00630b9e(void*, void*);
extern "C" void* __stdcall sub_0077e710(void*);

void* ChangePropertyItem::ChangePropertyItem_impl(void* arg)
{
    void* result;
    result = sub_00630d36(field0, 0, (void*)0x887174, (void*)0x887da8, 0);
    if (result == 0) {
        void* local;
        sub_0077e710(&local);
        sub_00630b9e((void*)0x841e0c, &local);
        result = 0;
    }
    void* p = *(void**)((char*)result + 0x18);
    void* v = *(void**)((char*)p);
    void* fn = *(void**)((char*)v + 4);
    void* a = field4;
    void* b = arg;
    ((void (__thiscall*)(void*, void*, void*))fn)(p, b, a);
    return b;
}
