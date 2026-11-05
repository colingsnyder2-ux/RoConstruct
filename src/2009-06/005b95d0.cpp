// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /Od /GS- /MT
struct Mesh;
struct Ctx;
struct TagA {};
struct TagB {};
void stepA(Mesh* m, Ctx* c, TagA t);
void stepB(Mesh* m, Ctx* c, TagB t);
void process(Mesh* m, Ctx* c)
{
    TagA a;
    stepA(m, c, a);
    stepB(m, c, TagB());
}
