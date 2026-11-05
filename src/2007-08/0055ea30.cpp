// from server: 51% by colin
struct DataModel;

struct StatsCommand {
    char pad[0xc];
    DataModel* dataModel;
    bool isChecked() const;
};

struct Instance {
    char pad[0x1a0];
    void* field_1a0;
};

struct DataModel {
    char pad[0x1a0];
    void* field_1a0;
};

struct String {
    char buf[0x1c];
    String(const char*);
    ~String();
};

extern "C" void* __stdcall sub_53e7a0(void*, const char*, const char*, int, void*);
extern "C" int __stdcall sub_630d36(void*);

bool StatsCommand::isChecked() const {
    void* p = dataModel->field_1a0;
    String s("StatsHud1");
    void* r = sub_53e7a0(p, "StatsHud1", "StatsHud1", 0, &s);
    int result = sub_630d36(r);
    s.~String();
    return result != 0;
}
