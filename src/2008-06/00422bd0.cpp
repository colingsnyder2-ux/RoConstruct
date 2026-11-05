// from server: 100% by king_originala
struct Object
{
    virtual void slot0() = 0;
    virtual void action(int) = 0;
};

struct Notification
{
    char padding[0x34];
    Object* object;
};

struct RestoreFlag
{
    unsigned char* flag;
    unsigned char previous;

    RestoreFlag(unsigned char*);
    ~RestoreFlag();
};

inline RestoreFlag::RestoreFlag(unsigned char* p)
    : flag(p), previous(*p)
{
    *p = 1;
}

inline RestoreFlag::~RestoreFlag()
{
    *flag = previous;
}

struct CRobloxTreeCtrl
{
    char padding[0xb8];
    unsigned char flag;

    void func_00422bd0(Notification*, long*);
};

void CRobloxTreeCtrl::func_00422bd0(Notification* notification, long* result)
{
    RestoreFlag restore(&flag);
    Object* object = notification->object;
    if (object)
        object->action(1);
    *result = 0;
}
