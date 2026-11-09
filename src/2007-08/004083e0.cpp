// from server: 100% by colin
struct Creator {
    void* field0;
    void* field4;
    void* field8;
    int fieldC;
    void destroy();
};

extern "C" void __stdcall sub_62FF38(void*, void*);

void Creator::destroy()
{
    if (field4) {
        *(void**)((char*)field4 + 4) = field0;
    }
    if (fieldC) {
        sub_62FF38(0, field8);
    }
}
