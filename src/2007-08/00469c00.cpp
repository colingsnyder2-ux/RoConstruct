// from server: 13% by colin
struct LDraw2RobloxColorMap {
    void destructor();
};

extern "C" void __stdcall sub_77E6D8();
extern "C" void __stdcall sub_77E6AC(void*);
extern "C" void __cdecl sub_62FC62(void*);
extern "C" void __cdecl sub_438EB0(void*);
extern "C" void __cdecl sub_5D9F20(void*);
extern "C" void __cdecl sub_4673A0(void*, void*, void*, void*, void*);
extern "C" void __cdecl sub_44EFC0(void*, void*, void*, void*, void*);

void LDraw2RobloxColorMap::destructor()
{
    char* self = (char*)this;
    *(void**)self = (void*)0x7960AC;

    char* list1 = self + 0x3c;
    char* node1 = *(char**)(self + 0x40);
    char* end1 = *(char**)(list1 + 4);

    while (node1 != end1) {
        if (node1 != 0 && node1 != list1) {
            sub_77E6D8();
        }
        if (node1 != 0 && node1 != list1) {
            sub_77E6D8();
        }
        void* p = *(void**)(node1 + 0x10);
        if (p != 0) {
            void** vt = *(void***)p;
            void (*fn)(void*, int) = (void (*)(void*, int))vt[0];
            fn(p, 1);
        }
        sub_438EB0(node1);
        node1 = *(char**)(list1 + 0);
    }

    char* list2 = self + 0x48;
    char* node2 = *(char**)(self + 0x4c);
    char* end2 = *(char**)(list2 + 4);

    while (node2 != end2) {
        if (node2 != 0 && node2 != list2) {
            sub_77E6D8();
        }
        if (node2 != 0 && node2 != list2) {
            sub_77E6D8();
        }
        void* p = *(void**)(node2 + 0x28);
        if (p != 0) {
            void** vt = *(void***)p;
            void (*fn)(void*, int) = (void (*)(void*, int))vt[0];
            fn(p, 1);
        }
        sub_5D9F20(node2);
        node2 = *(char**)(list2 + 0);
    }

    void* tmp;
    sub_4673A0(list2, *(void**)(list2 + 4), *(void**)(*(void**)(list2 + 4)), list2, &tmp);
    sub_62FC62(*(void**)(list2 + 4));
    *(void**)(list2 + 4) = 0;
    *(void**)(list2 + 8) = 0;

    sub_44EFC0(list1, *(void**)(list1 + 4), *(void**)(*(void**)(list1 + 4)), list1, &tmp);
    sub_62FC62(*(void**)(list1 + 4));
    *(void**)(list1 + 4) = 0;
    *(void**)(list1 + 8) = 0;

    sub_77E6AC(self + 0x20);
    sub_77E6AC(self + 4);
}
