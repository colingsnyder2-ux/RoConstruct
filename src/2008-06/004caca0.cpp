// from server: 100% by colin
extern "C" void __cdecl mfcFree(void*);
struct BufferCleanupView {
    char opaque[8];
    int flag;
    void* data;
    void release();
};
void BufferCleanupView::release() { if (flag) mfcFree(data); }
