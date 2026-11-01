// from server: 68% by colin
struct RunCommand {
    char pad[0xc];
    int field_c;
    char pad2[0x4];
    int field_10;
    bool isEnabled() const;
    void doIt(int);
};

struct DataState {
    char pad[0x1ac];
    bool flag_1ac;
};

extern "C" int __stdcall sub_55e290();
extern "C" DataState* __stdcall sub_562240(int*, int);
extern "C" void __stdcall sub_52d780(DataState*);

bool RunCommand::isEnabled() const {
    int* p = (int*)&field_10;
    DataState* ds = sub_562240(p, 1);
    if (ds->flag_1ac) {
        return true;
    }
    return false;
}

void RunCommand::doIt(int) {
    sub_55e290();
    if (!isEnabled()) {
        sub_52d780((DataState*)0);
    }
}
