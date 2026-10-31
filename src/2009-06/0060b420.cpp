// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Result {
    char pad[0x13c];
    int mode;
};
struct Sub {
    virtual void v0();
    virtual Result* get();
};
struct Inner {
    char pad[0x118];
    Sub sub;
};
struct FollowCameraCommand {
    char pad[0xc];
    Inner* field_c;
    bool run();
};
bool FollowCameraCommand::run() {
    return field_c->sub.get()->mode == 4;
}
