// from server: 53% by atomic.potato
struct CMap
{
    char pad0[0x1c0];
    void* head;
    void* tail;

    void* FindOrInsert(void* key);
};

struct Node
{
    char pad0[0x10];
    void* value;
};

extern "C" void* __stdcall sub_00b22640(void*);
extern "C" void* __stdcall sub_009e1720(void*, void*);
extern "C" void* __stdcall sub_009f1270(void*, void*, void*);
extern "C" void* __stdcall sub_009f1d30(void*);
extern "C" void* __stdcall sub_00466420(void*, void*, void*);
extern "C" void* __stdcall sub_00457100(void*, void*);

void* CMap::FindOrInsert(void* key)
{
    void* result;
    void* node;
    void* str;
    void* tmp;

    void* localKey = key;
    void* localNode = 0;

    result = sub_00466420(&head, &localNode, &localKey);
    node = *(void**)result;
    if (node != tail)
    {
        return *(void**)((char*)node + 0x10);
    }

    str = sub_00b22640((char*)key + 4);
    tmp = sub_009e1720(this, str);
    tmp = sub_009f1270(tmp, 0, str);
    str = sub_009f1d30(tmp);

    localKey = key;
    result = sub_00457100(&head, &localKey);
    *(void**)result = str;
    return str;
}
