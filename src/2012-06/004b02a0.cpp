// from server: 71% by atomic.potato
struct VideoControlVTable
{
    void (__thiscall *Check)(void *);
    void (__thiscall *Unused1)(void *);
    void (__thiscall *Unused2)(void *);
    int (__thiscall *IsReady)(void *);
    void (__thiscall *Unused4)(void *);
    void (__thiscall *Unused5)(void *);
    void (__thiscall *Unused6)(void *);
    void (__thiscall *Run)(void *);
};

struct VideoControl
{
    void *vptr;
    char padding[0x108];
    void *control;
    void Update();
};

void VideoControl::Update()
{
    VideoControlVTable *vtable;
    vtable = *(VideoControlVTable **)control;
    if (vtable->IsReady(control))
        vtable->Run(control);
}
