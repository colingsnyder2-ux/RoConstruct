// from server: 100% by tester
struct PartChunk
{
    int field_0;
    int field_4;
    int field_8;
    int field_c;
};

bool __stdcall compareChunks(PartChunk* a, PartChunk* b)
{
    if (a->field_c < b->field_c)
        return true;
    if (a->field_c > b->field_c)
        return false;
    return a < b ? true : false;
}
