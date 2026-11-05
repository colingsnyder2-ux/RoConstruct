// from server: 49% by colin
struct ChatEnter {
    void* field0;
    ChatEnter(int, int);
};

extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

ChatEnter::ChatEnter(int a, int b)
{
    field0 = 0;
    void* p = operator_new(0x14);
    if (p) {
        *(int*)((char*)p + 4) = 1;
        *(int*)((char*)p + 8) = 1;
        *(int*)((char*)p + 0) = 0x786520;
        *(int*)((char*)p + 0xc) = a;
    } else {
        p = 0;
    }
    field0 = p;
}
