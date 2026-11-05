// from server: 100% by king_originala
struct Entry {
    int data[2];
};

struct EntryList {
    char padding[0x0C];
    Entry* begin;
    Entry* end;
};

struct SourceResult {
    char padding[0x154];
    EntryList* entries;
};

struct Source {
    char padding[0x0C];
    SourceResult* get(int);
};

struct CameraResult {
    char padding[0x148];
    int** begin;
    int** end;
};

struct Provider {
    CameraResult* get();
};

struct FollowCameraCommand {
    char padding[0x14];
    Source source;
    Provider* provider;
    unsigned char isChecked();
};

unsigned char FollowCameraCommand::isChecked() {
    EntryList* entries = source.get(1)->entries;
    if ((unsigned)(entries->end - entries->begin) <= 0)
        return 0;

    CameraResult* result = provider ? provider->get() : 0;
    return (unsigned)(result->end - result->begin) == 1;
}
