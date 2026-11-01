// from server: 100% by king_originala
struct State {
    char pad[0x1b4];
    int value;
};

struct Helper {
    State* get(int);
};

void* func(void*);

struct ResetCommand {
    char pad[0x0c];
    void* object;
    Helper helper;

    int enabled();
};

int ResetCommand::enabled()
{
    int value = helper.get(1)->value;
    if (value == 1 || value == 2) {
        if (!func(object))
            return 1;
    }
    return 0;
}
