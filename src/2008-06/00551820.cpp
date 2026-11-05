// from server: 100% by EspClaude
// roc 2008-06 00551820  unit: seg_00550000  size: 242 bytes
// roc-flags: /Od /GS /EHsc /MD
#include <exception>

extern int factoryType;

struct Factory {
    virtual ~Factory();
};
struct First : Factory {
    char data[0x58c];
    First();
};
struct Second : Factory {
    char data[0x4fc];
    Second();
};

Factory* createFactory()
{
    if (factoryType == 0)
        return new First;
    else if (factoryType == 1)
        return new Second;
    else
        throw std::exception("Invalid factory type");
}
