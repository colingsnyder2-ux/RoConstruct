// from server: 96% by colin
extern "C" void __cdecl sub_62AB40(void*);

struct NodeVisiter {
    void* field0;
    void* field4;
    void* field8;
    void* fieldC;
    void* field10;
    void* field14;
    bool method();
};

bool NodeVisiter::method() {
    void* eax = field4;
    void* ecx = field8;
    if (eax == 0) {
        return false;
    }
    void* esi;
    void* edi;
    do {
        esi = *(void**)((char*)eax + (int)ecx - 8);
        edi = *(void**)((char*)eax + (int)ecx - 4);
        sub_62AB40(eax);
        eax = esi;
        ecx = edi;
    } while (esi != 0);
    void* tmp = field14;
    field4 = esi;
    field0 = esi;
    field10 = tmp;
    return true;
}
