// from server: 100% by Yeetserama
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O1 /Ob2 /Oy /GF /GS- /EHsc /MD

struct Child {
    virtual int f0();
    virtual int f1();
};

struct CXTIconHandle {
    int m_pad;
    Child* m_child;
    int method();
};

int CXTIconHandle::method()
{
    return m_child->f1();
}
