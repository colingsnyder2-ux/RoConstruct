// from server: 69% by atomic.potato
struct VideoControl {
    struct Video {
        virtual bool ready();
        virtual void play(void*, void*);
    };

    Video* m_video;
    void* m_arg;
    void* m_context;

    void f(void*);
};

void VideoControl::f(void* arg)
{
    if (m_video->ready())
        m_video->play(arg, m_context);
}
