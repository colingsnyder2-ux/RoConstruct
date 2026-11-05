// from server: 58% by atomic.potato
extern "C" void __cdecl construct_string(void*, const char*);
extern "C" void __stdcall call_006f7810(void*);

struct TrackCameraCommand {
    int value;
    TrackCameraCommand* f(int);
};

TrackCameraCommand* TrackCameraCommand::f(int arg) {
    char buffer[28];
    construct_string(buffer, "SelectionDown");
    call_006f7810(this);
    value = 0xB9C844;
    return this;
}
