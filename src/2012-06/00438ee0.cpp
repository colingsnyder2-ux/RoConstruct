// from server: 69% by Intel
struct IUnknown_00438ee0 {
    virtual void Method1() = 0;
    virtual void Release(int) = 0;
    virtual void Method3() = 0;
    virtual void Method4() = 0;
    virtual void Method5() = 0;
    virtual void Method6() = 0;
    virtual void Method7() = 0;
    virtual void Method8() = 0;
    virtual void Method9() = 0;
    virtual void Method10() = 0;
    virtual void Method11() = 0;
    virtual void Method12() = 0;
    virtual void Method13() = 0;
    virtual void Method14() = 0;
    virtual void Method15() = 0;
    virtual void Method16() = 0;
    virtual void Method17() = 0;
    virtual void Method18() = 0;
    virtual void Method19() = 0;
    virtual void Method20() = 0;
    virtual void Method21() = 0;
    virtual void Method22() = 0;
    virtual void Method23() = 0;
    virtual void Method24() = 0;
    virtual void Method25() = 0;
    virtual void Method26() = 0;
};

struct CMainFrame_00438ee0 {
    char pad[0x464];
    IUnknown_00438ee0* member_464;
    IUnknown_00438ee0* member_468;
    IUnknown_00438ee0* member_46c;
    void CleanupMembers();
};

void CMainFrame_00438ee0::CleanupMembers()
{
    IUnknown_00438ee0* p = member_464;
    if (p) {
        if (*(int*)((char*)p + 0x20)) {
            p->Method26();
        }
        member_464 = 0;
        if (p) {
            p->Release(1);
        }
    }

    p = member_468;
    if (p) {
        if (*(int*)((char*)p + 0x20)) {
            p->Method26();
        }
        member_468 = 0;
        if (p) {
            p->Release(1);
        }
    }

    p = member_46c;
    if (p) {
        if (*(int*)((char*)p + 0x20)) {
            p->Method26();
        }
        member_46c = 0;
        if (p) {
            p->Release(1);
        }
    }
}
