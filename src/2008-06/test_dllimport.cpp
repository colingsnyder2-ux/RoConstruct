// test dllimport
extern "C" __declspec(dllimport) void bar();

void foo() {
    bar();
}