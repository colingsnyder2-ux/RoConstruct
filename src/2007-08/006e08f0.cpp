// from server: 100% by colin
struct CXTPDockingPaneTabbedContainer {
    char pad[0xf0];
    int field_f0;
    int GetSomething();
};

int __fastcall sub_6E0540(CXTPDockingPaneTabbedContainer* p);
int __fastcall sub_66F6C0(int v);

int CXTPDockingPaneTabbedContainer::GetSomething()
{
    if (field_f0 == 0)
    {
        CXTPDockingPaneTabbedContainer* p = (CXTPDockingPaneTabbedContainer*)((char*)this - 0x54);
        return sub_66F6C0(sub_6E0540(p));
    }
}
