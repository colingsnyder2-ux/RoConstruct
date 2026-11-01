// from server: 100% by colin
struct SubInfo {
    char pad[0x198];
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
