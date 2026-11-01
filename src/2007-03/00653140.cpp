// from server: 100% by tester
struct CRobloxTreeCtrl {
    int GetItemState(int item) const;
};

extern "C" int __stdcall sub_665F90(int item, int mask);

int CRobloxTreeCtrl::GetItemState(int item) const {
    return sub_665F90(item, 0x10) & 0x10;
}
