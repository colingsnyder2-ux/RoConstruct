// from server: 56% by atomic.potato
struct RBX_AdvRotateTool
{
    char pad[0x14];
    int* begin;
    int* end;
    int* find(int id);
};

int* RBX_AdvRotateTool::find(int id)
{
    unsigned int count = (unsigned int)(end - begin);
    unsigned int i = 0;
    if (count > 0)
    {
        int* p = begin;
        do
        {
            int* obj = (int*)*p;
            if (obj[1] == id || obj[2] == id)
                return obj;
            ++i;
            ++p;
        } while (i < count);
    }
    return 0;
}
