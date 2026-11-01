// from server: 100% by Yeetserama
// from server: 100% by colin
struct S;

extern S &(__cdecl *G_append)(S &, const char *);
extern const char *(__thiscall *G_text)(S *);
extern void __cdecl G_func_00427c20(int, const char *);

struct S
{
    unsigned int storage;
    __declspec(dllimport) S();
    __declspec(dllimport) ~S() throw();
};

struct Crash
{
    int value;
    int source;
};

void func_004282a0()
{
    S message;
    G_append(message, "Pure Call Error");
    G_func_00427c20(1, G_text(&message));
    Crash *p = 0;
    p->value = p->source;
}
