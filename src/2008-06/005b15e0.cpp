// from server: 100% by king_originala
struct S {
    S* next();
    void attach(S*);
};

extern S* __cdecl lookup(S*);

void __cdecl func_005b15e0(S* source, S* excluded)
{
    S* parent = lookup(source);
    if (parent) {
        S* item = source->next();
        if (item) {
            do {
                if (item != excluded)
                    item->attach(parent);
                item = source->next();
            } while (item);
        }
    }
}
