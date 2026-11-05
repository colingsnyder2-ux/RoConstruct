// from server: 63% by atomic.potato
extern "C" void construct_string(void*, const char*);
extern "C" void initialize_command(void*);

struct TrackCameraCommand
{
    int value;
    TrackCameraCommand* f(const char*);
};

TrackCameraCommand* TrackCameraCommand::f(const char*)
{
    construct_string(this, "FollowCamera");
    initialize_command(this);
    value = 0xB9C804;
    return this;
}
