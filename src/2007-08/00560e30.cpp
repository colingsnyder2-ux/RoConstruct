// from server: 26% by colin
struct FilteredSelection {
    char pad[0x130];
    void* begin;
    void* end;
    void* cap;
    void* method();
};

extern "C" void __stdcall sub_725520(void*, void*);
extern "C" void __cdecl sub_55e7c0();
extern "C" void __cdecl sub_40e470();
extern "C" void __cdecl sub_444e70();
extern "C" void __cdecl sub_52cb30();
extern "C" void __cdecl sub_554de0();
extern "C" void __cdecl sub_492360();
extern "C" void __cdecl sub_402a60();
extern "C" void __cdecl sub_77e6d8();

void* FilteredSelection::method()
{
    void* result;
    void* local;
    int idx;
    int count;
    void* elem;
    void* tmp;

    sub_725520((void*)0x8c2328, (void*)0x55ed70);
    sub_55e7c0();
    idx = (int)result;

    if (this->end != 0) {
        count = ((char*)this->cap - (char*)this->end) >> 3;
    } else {
        count = 0;
    }

    if (idx + 1 > count) {
        local = 0;
        tmp = 0;
        sub_40e470();
    } else {
        if (this->end != 0 || idx >= ((char*)this->cap - (char*)this->end) >> 3) {
            sub_77e6d8();
        }
        elem = (void*)((char*)this->end + idx * 8);
        if (elem != 0) {
            return elem;
        }
    }

    if ((*(unsigned char*)0x8c2334 & 1) == 0) {
        *(unsigned int*)0x8c2334 |= 1;
        sub_725520((void*)0x8bbae0, (void*)0x444fb0);
        sub_444e70();
        sub_52cb30();
        *(unsigned char*)0x8c2330 = (result == local) ? 1 : 0;
    }

    if (*(unsigned char*)0x8c2330 == 0) {
        sub_725520((void*)0x8bbae0, (void*)0x444fb0);
        sub_444e70();
        sub_554de0();
        if (local != 0) {
            if (this->end == 0 || idx >= ((char*)this->cap - (char*)this->end) >> 3) {
                sub_77e6d8();
            }
            elem = (void*)((char*)this->end + idx * 8);
            *(void**)elem = local;
            sub_402a60();
            sub_492360();
            return (void*)idx;
        }
        sub_492360();
    }

    return 0;
}
