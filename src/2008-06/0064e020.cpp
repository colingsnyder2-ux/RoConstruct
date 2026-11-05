// from server: 100% by king_originala
extern char globalData;

struct Helper {
    int invoke(void *, int, void *);
};

struct ToolMouseCommand {
    char padding[0x130];
    char storage[0x34];
    Helper *helper;

    void update();
    int execute();
};

int ToolMouseCommand::execute()
{
    update();
    if (helper)
        return helper->invoke(storage, 0, &globalData);
    return 0;
}
