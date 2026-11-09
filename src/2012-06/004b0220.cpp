// from server: 46% by atomic.potato
struct VideoControl {
    char pad_0000[268];
    void* m_control;
    char pad_0110[12];
    void* m_video;
    void f();
};

void VideoControl::f()
{
    struct VTable {
        char pad_0000[12];
        int (*is_ready)(void*);
        char pad_0010[8];
        int (*play)(void*, void*);
    };

    void* control = m_control;
    VTable* table = *(VTable**)control;
    if ((*table->is_ready)(control))
        (*table->play)(control, m_video);
}
