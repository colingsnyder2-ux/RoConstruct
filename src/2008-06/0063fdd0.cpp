// from server: 100% by colin
extern "C" void* memset(void*, int, unsigned);
struct B0 { virtual void a(); };
struct B1 { virtual void b(); };
struct Mid : B0, B1 {
    char pad[0x14];
    Mid(int);
};
struct CloneTool : Mid {
    int p; int q;
    CloneTool(int a1);
    virtual void a();
    virtual void b();
};
 CloneTool::CloneTool(int a1) : Mid(a1) { memset(&p, 0, 8); }

