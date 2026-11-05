// from server: 100% by colin
struct RBXName;

struct Creator {
    void* m_vtbl;
};

struct CreatorList {
    Creator** m_data;
    int m_size;
};

struct FactoryProduct {
    void* m_vtbl;
    void* m_base;
    char m_pad[0x50];
    CreatorList m_creators;

    void removeCreator(Creator* c);
    void processCreators();
};

extern RBXName* __fastcall getClassName(Creator* c);
extern bool __fastcall isConstructed(RBXName* n);

void FactoryProduct::processCreators()
{
    CreatorList* list = (CreatorList*)((char*)this->m_vtbl + 0x58);
    int i = 0;
    while (i < list->m_size)
    {
        Creator* c = list->m_data[i];
        RBXName* n = getClassName(c);
        if (isConstructed(n))
        {
            removeCreator(c);
        }
        i++;
    }
}
