// from server: 100% by atomic.potato
struct FilePacketLogger {
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void v08();
    virtual void v09();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    int m_x;
    void setX(int a1);
    void func(int a1);
};

void FilePacketLogger::func(int a1)
{
    setX(a1);
    v13();
}
