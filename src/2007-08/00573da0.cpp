// from server: 100% by colin
struct VPartInstance_FactoryProduct {
    bool m();
};

struct Sub {
    int getType();
};

struct Container {
    Sub* at(int index);
};

bool VPartInstance_FactoryProduct::m()
{
    int i = 0;
    Container* c = (Container*)((char*)this + 0x1a4);
    while (i < 6) {
        Sub* s = c->at(i);
        if (s->getType() == 6 || s->getType() == 8 || s->getType() == 7)
            return true;
        ++i;
    }
    return false;
}
