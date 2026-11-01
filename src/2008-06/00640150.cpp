// from server: 100% by king_originala
struct Object {
    char padding[0x1f0];
    unsigned char flag;
    bool isRestricted();
};

struct Tool {
    bool accepts(void* value);
    int check(Object* object, void* value);
};

int Tool::check(Object* object, void* value)
{
    if (!object->flag && !object->isRestricted() && accepts(value))
        return 1;
    return 0;
}
