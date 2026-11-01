// from server: 100% by colin
struct CopyVerb {
    char pad[0x104];
    void* field104;
    int getCount() const;
};

int CopyVerb::getCount() const
{
    void* p = field104;
    int* begin = *(int**)((char*)p + 4);
    if (begin == 0)
        return 0;
    int* end = *(int**)((char*)p + 8);
    return (int)(((char*)end - (char*)begin) >> 3);
}
