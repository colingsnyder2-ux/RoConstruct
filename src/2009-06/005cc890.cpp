// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <string>
struct B0 { virtual ~B0(); int pad[4]; };
struct B1 { virtual void f1(); };
struct B2 { virtual void f2(); int x; };
struct B3 { virtual void f3(); int pad[26]; };
struct Base : B0, B1, B2, B3 {
    Base();
    virtual ~Base();
    void setName(const std::string& s);
};
struct TaskScheduler : Base {
    void* p;
    TaskScheduler();
    virtual ~TaskScheduler();
    virtual void f1();
    virtual void f2();
    virtual void f3();
};
TaskScheduler::TaskScheduler() : p(0)
{
    setName("Task Scheduler");
}
