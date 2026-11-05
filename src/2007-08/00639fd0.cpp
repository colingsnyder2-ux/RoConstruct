// from server: 100% by atomic.potato
struct CNested;
struct Controls;
struct COther;

struct COther {
    void* method_a();
};

struct CNested {
    void* method_b();
};

struct Controls {
    char pad[0x20];
    CNested* GetCommandBars();
};

void* DefaultFunc();

struct CRobloxControlColorSelector {
    char pad[0xf4];
    Controls* m_controls;
    char pad_f8[4];
    COther* m_other;
    void* method();
};

void* CRobloxControlColorSelector::method() {
    if (m_other) {
        return m_other->method_a();
    }
    if (m_controls) {
        CNested* n = m_controls->GetCommandBars();
        if (n) {
            return n->method_b();
        }
    }
    return DefaultFunc();
}
