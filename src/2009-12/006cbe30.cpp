// from server: 100% by atomic.potato
struct PartInstance
{
    char padding[0x168];
    int *field_168;
    float get_006cbe30();
};

float PartInstance::get_006cbe30()
{
    return *(float *)((char *)field_168 + 0x104);
}
