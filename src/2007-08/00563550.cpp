// from server: 54% by colin
struct Property {
    char pad[0x104];
    int* begin;
    int* end;
};

struct PropertyContainer {
    char pad[0x14];
    Property* getProperty(int);
};

struct BoolPropertyVerb {
    char pad[0x14];
    PropertyContainer container;
    char pad2[0x0c];
    int flag;
    bool isChecked() const;
};

extern "C" void __stdcall _invalid_parameter_noinfo();

bool BoolPropertyVerb::isChecked() const
{
    PropertyContainer* pc = (PropertyContainer*)(void*)&container;

    Property* p1 = pc->getProperty(1);
    int* e1 = p1->end;
    int* b1 = p1->begin;
    if (b1 > e1)
        _invalid_parameter_noinfo();

    int saved = *(int*)((char*)this + 0x24);

    Property* p2 = pc->getProperty(1);
    int* e2 = p2->end;
    int* b2 = p2->begin;
    if (b2 > e2)
        _invalid_parameter_noinfo();

    Property* p3 = pc->getProperty(1);
    int* b3 = p3->begin;
    int* e3 = p3->end;
    if (b3 > e3)
        _invalid_parameter_noinfo();

    int result = ((int (__stdcall*)(int, int, int, int, int))0x560430)(0x5606f0, saved, (int)b3, (int)e3, (int)e2);

    if (p3 != 0 && p3 != p1)
        _invalid_parameter_noinfo();

    return result != (int)p1;
}
