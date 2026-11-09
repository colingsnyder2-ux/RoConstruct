// from server: 44% by atomic.potato
struct GuiTextButton {
    void construct(char *a, char *b, char *c, char *d, char *e, char *f, char *g);
};

extern "C" void *__stdcall sub_758ae0(void *out, char *a, char *b, char *c, char *d, char *e);
extern "C" void *__stdcall sub_651bb0(char *a, char *b);
extern "C" void __stdcall sub_7f385a(void *p);
extern "C" void __fastcall sub_6cc9c0(void *self, void *unused, void *p);

void GuiTextButton::construct(char *a, char *b, char *c, char *d, char *e, char *f, char *g)
{
    void *tmp;
    void *v;
    sub_758ae0(&tmp, a, b, c, d, e);
    v = tmp;
    tmp = 0;
    void *local = v;
    void *p = sub_651bb0(f, g);
    sub_6cc9c0(this, 0, p);
    sub_7f385a(local);
    *(void **)this = (void *)0x9e5b7c;
}
