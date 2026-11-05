// from server: 69% by atomic.potato
extern "C" void* __stdcall SendMessageA(void*, unsigned int, unsigned int, unsigned int);

struct CEnabledCmdUI {
    char pad[0x20];
    void* field20;
    void method(int, int*);
};

void CEnabledCmdUI::method(int, int* out)
{
    void* r = SendMessageA(field20, 0x110f, 0, 0);
    void* h = *(void**)((char*)r + 0x20);
    SendMessageA(h, 0xc5, 0x20, 0);
    *out = 0;
}
