// from server: 50% by colin
struct S_func_00464220 {
    char pad[0x180];
    int field_180;
    float getCursorPos(float* out);
};

extern "C" {
    int __stdcall GetCursorPos(void* lpPoint);
    int __stdcall ScreenToClient(int hWnd, void* lpPoint);
    void __stdcall LeaveCriticalSection(void* lpCriticalSection);
    void __stdcall func_0041d870();
}

float S_func_00464220::getCursorPos(float* out)
{
    char local[16];
    *(void**)(local + 0) = (void*)((char*)this + 0x34);
    local[4] = 0;
    func_0041d870();
    GetCursorPos(local + 8);
    int hwnd = *(int*)(*(int*)((char*)this + 0x180) + 0x20);
    ScreenToClient(hwnd, local + 8);
    out[0] = (float)*(int*)(local + 8);
    out[1] = (float)*(int*)(local + 12);
    if (local[4] != 0) {
        LeaveCriticalSection(*(void**)(local + 0));
    }
    return out[0];
}
