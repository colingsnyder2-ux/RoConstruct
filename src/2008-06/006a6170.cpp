// from server: 100% by atomic.potato
struct CmdMap {
    int Find(void* cmd, int* index);
};

struct MyXTPCommandBars {
    char pad[0x74];
    void* field_74;
    int FindCommand(void* cmd);
};

int MyXTPCommandBars::FindCommand(void* cmd)
{
    int index;
    int result = ((CmdMap*)((char*)field_74 + 0x8c))->Find(cmd, &index);
    if (result == 0)
        return 0;
    result = ((CmdMap*)((char*)field_74 + 0xa8))->Find(cmd, &index);
    return (result == 0) ? 1 : 0;
}
