// from server: 62% by atomic.potato
typedef unsigned int size_t;

struct BasicString
{
    void* a;
    void* b;
    void* c;
};

extern "C" void construct_string(BasicString*, const char*);
extern "C" void call_006f7810(void*, BasicString*);

struct TrackCameraCommand
{
    virtual ~TrackCameraCommand();
    TrackCameraCommand(const char*);
};

TrackCameraCommand::TrackCameraCommand(const char* value)
{
    BasicString s;
    construct_string(&s, value);
    call_006f7810(this, &s);
    *(void**)this = (void*)0x00b9c824;
}
