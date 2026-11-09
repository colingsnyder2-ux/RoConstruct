// from server: 49% by colin
struct ChatEnter {
    void* field0;
    ChatEnter(int arg, int arg2);
};

extern "C" void* __cdecl sub_62FEF6(unsigned int size);

ChatEnter::ChatEnter(int arg, int arg2)
{
    field0 = 0;
    void* p = sub_62FEF6(0x14);
    if (p != 0) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(void**)p = (void*)0x7864F8;
        *(int*)((char*)p + 0xC) = arg;
    } else {
        p = 0;
    }
    field0 = p;
}
