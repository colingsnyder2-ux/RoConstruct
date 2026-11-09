// from server: 100% by king_originala
extern "C" void (__cdecl *_invalid_parameter_noinfo)();
extern "C" void __cdecl process_entry(void *, void *);

struct S {
    unsigned int padding[3];
    void **begin;
    void **end;
};

void __cdecl f(S *s, void *argument)
{
    unsigned int i = 0;
    if (i < static_cast<unsigned int>(s->end - s->begin)) {
        void (__cdecl *invalid_parameter)() = _invalid_parameter_noinfo;
        do {
            if (i >= static_cast<unsigned int>(s->end - s->begin))
                invalid_parameter();

            process_entry(s->begin[i], argument);
            ++i;
        } while (i < static_cast<unsigned int>(s->end - s->begin));
    }
}
