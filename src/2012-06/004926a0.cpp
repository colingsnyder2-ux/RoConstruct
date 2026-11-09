// from server: 100% by tester
struct SubInfo {
    char pad[0x1e0];
    int value;
};

struct InsertModelFromRobloxVerb {
    char pad[0xc];
    SubInfo* info;
    bool ShouldShow();
};

bool InsertModelFromRobloxVerb::ShouldShow()
{
    return this->info->value != 0;
}