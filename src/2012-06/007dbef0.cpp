// from server: 46% by atomic.potato
struct EventDesc {
    char pad[0x2c];
    int field_2c;
    int invoke(int a, int b);
};

int EventDesc::invoke(int a, int b)
{
    int result = 0;
    if (a != 0) {
        result = this->field_2c + (a - 0x1c);
        ((EventDesc*)(a - 0x1c))->invoke(result, b);
        return result;
    }
    *(int*)b = 0;
    return result;
}
