// from server: 100% by colin
// roc 2007-08 006a3510  unit: unknown  size: 29 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a3510

struct CHookSink;

struct CXTPHookManager {
    static CHookSink* __stdcall FindHookSink(int);
};

struct CHookSink {
    void __thiscall Install(int);
};

void __stdcall func_006a3510(int a, int b) {
    CHookSink* p = CXTPHookManager::FindHookSink(a);
    if (p != 0) {
        p->Install(b);
    }
}
