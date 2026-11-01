// from server: 69% by atomic.potato
struct CXTTreeCtrl {
    char pad[0x38];
    void* field_38;
    char pad2[0xa0 - 0x3c];
    void* field_a0;
    int sub_42A640();
};

extern "C" CXTTreeCtrl* __stdcall sub_983448(void*, void*, void*, void*, void*);

int CXTTreeCtrl::sub_42A640()
{
    if (field_a0 == 0) {
        CXTTreeCtrl* r = sub_983448(field_38, 0, (void*)0xd601e8, (void*)0xd630e8, 0);
        if (r != 0) {
            CXTTreeCtrl* r2 = sub_983448(field_38, 0, (void*)0xd601e8, (void*)0xd630e8, 0);
            if (r2->sub_42A640() != 0) {
                return 1;
            }
        }
        return 0;
    }
    return 0;
}
