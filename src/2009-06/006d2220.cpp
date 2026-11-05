// from server: 100% by why2
struct Humanoid
{
    char pad[0x18];
    void* field_18;
};

bool func_006d2220(Humanoid* obj)
{
    if (obj != 0 && obj->field_18 != 0)
        return true;
    return false;
}
