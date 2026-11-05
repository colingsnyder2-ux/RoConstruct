// from server: 100% by colin
// roc 2007-08 006a36c0  unit: seg_006a0000  size: 62 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a36c0

extern "C" __declspec(dllimport) long __stdcall GetWindowLongA(void*, int);
extern "C" __declspec(dllimport) long __stdcall SetWindowLongA(void*, int, long);

extern "C" long __stdcall sub_6a3320(void*, int, long);

struct CXTPHookManager_CHookSink {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    void sub_6a2e20();
    CXTPHookManager_CHookSink* construct(void* hwnd);
};

CXTPHookManager_CHookSink* CXTPHookManager_CHookSink::construct(void* hwnd) {
    sub_6a2e20();
    field0 = 0x7d3538;
    field1C = 0;
    field18 = (int)hwnd;
    field14 = GetWindowLongA(hwnd, -4);
    SetWindowLongA(hwnd, -4, (long)&sub_6a3320);
    return this;
}
