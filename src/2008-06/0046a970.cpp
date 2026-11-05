// from server: 100% by atomic.potato
struct CWebToolbox
{
    char padding[0x24];
    void* field24;
    int GetValue();
};

int CWebToolbox::GetValue()
{
    if (field24)
        return *(int*)((char*)field24 + 0x204);
    return 0;
}
