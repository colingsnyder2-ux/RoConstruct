// from server: 50% by colin
struct CMarshalWindow {
    void destroy();
};

extern "C" void __stdcall LeaveCriticalSection(void*);
extern "C" void __stdcall DestroyWindow(void*);
extern "C" void __cdecl sub_41D870(void*);
extern "C" void __cdecl sub_407220(void*, void*);
extern "C" void __cdecl sub_77D2F8(void*);

void CMarshalWindow::destroy()
{
    char local[8];
    *(void**)local = (void*)0x8bb93c;
    local[4] = 0;
    sub_41D870(local);
    int* p = (int*)((char*)this + 0x24);
    *p = *p - 1;
    if (*p == 0) {
        sub_407220((void*)0x8bb930, (char*)this + 0x28);
        LeaveCriticalSection(*(void**)((char*)this + 4));
    }
    if (local[4]) {
        sub_77D2F8(*(void**)local);
    }
}
