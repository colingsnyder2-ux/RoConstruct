// from server: 66% by atomic.potato
struct UploadVideoVerb
{
    char padding[12];
    void* field_0c;
    int GetValue();
};

int UploadVideoVerb::GetValue()
{
    return *((int*)((char*)field_0c + 0xa0));
}
