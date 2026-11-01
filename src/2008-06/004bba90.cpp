// from server: 100% by tester
struct RakPeer {
    virtual bool vfunc0();
    virtual bool vfunc1();
    virtual bool vfunc2();
    virtual bool vfunc3();
    virtual bool vfunc4();
    virtual bool vfunc5();
    virtual bool vfunc6();
    virtual bool vfunc7();
    virtual bool vfunc8();
    virtual bool vfunc9();
    virtual bool vfunc10();
    virtual bool vfunc11();
    char pad[0x704];
    int field_708;
    bool setLimit(int limit);
};

bool RakPeer::setLimit(int limit)
{
    if (vfunc11()) {
        return false;
    }
    if (limit < 0x200) {
        limit = 0x200;
    } else if (limit > 0x5d4) {
        limit = 0x5d4;
    }
    field_708 = limit;
    return true;
}
