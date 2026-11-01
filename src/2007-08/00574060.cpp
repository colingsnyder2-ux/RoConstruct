// from server: 100% by colin
struct PartInstance {
    char pad[0x1d8];
    void* field_1d8;
    bool getSomething() const;
};

bool PartInstance::getSomething() const
{
    char* p = (char*)field_1d8;
    if (p[0x70] == 0 && p[0x72] != 0)
        return true;
    return false;
}
