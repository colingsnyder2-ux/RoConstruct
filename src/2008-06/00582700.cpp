// from server: 100% by king_originala
struct State {
    char padding[0x1B4];
    int value;
};

struct Handle {
    State* get(int);
};

extern "C" bool __cdecl check(void*, int);

struct RunCommand {
    char padding[0x0C];
    void* object;
    Handle handle;

    int enabled();
};

int RunCommand::enabled()
{
    int value = handle.get(1)->value;
    if (check(object, 1) || value == 1)
        return 0;
    return 1;
}
