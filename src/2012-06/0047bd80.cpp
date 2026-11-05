// from server: 40% by atomic.potato
struct UploadVideoVerb
{
    int Check();
};

struct UploadVideoResult
{
    int value;
};

int UploadVideoVerb::Check()
{
    UploadVideoResult* result = *(UploadVideoResult**)((char*)this + 0x80);
    int value = 0;

    if (result != 0)
    {
        int (**table)(UploadVideoResult*) = *(int (***)(UploadVideoResult*))result;
        if (table[1](result))
            value = 1;
    }

    return value;
}
