// from server: 100% by colin
extern "C" int __cdecl sub_80B2EA(int, int, int, int, int);

struct Team {
    bool askSetParent(const void* parent) const;
};

bool Team::askSetParent(const void* parent) const {
    int result = sub_80B2EA((int)parent, 0, 0x00C071F8, 0x00C3943C, 0);
    return result != 0;
}
