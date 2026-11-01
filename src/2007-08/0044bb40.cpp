// from server: 100% by colin
struct CRobloxControlColorSelector {
    char pad[0x9c];
    int field_9c;
    char pad2[0x158 - 0x9c - 4];
    void* field_158;
    int getValue();
};

extern "C" int __fastcall sub_63A580(void* p);

int CRobloxControlColorSelector::getValue()
{
    int result = field_9c;
    if (result == -1) {
        void* p = field_158;
        if (p != 0) {
            return sub_63A580(p);
        }
    }
    return result;
}
