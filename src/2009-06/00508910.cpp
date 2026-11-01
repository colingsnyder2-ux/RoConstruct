// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
struct Pad { char pad[0x70]; };
struct Link { Link* next; };
struct Job : Pad, Link { };
void insert(Job* job, Link** list)
{
    Link* l = job;
    l->next = *list;
    *list = l;
}
