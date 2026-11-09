// from server: 56% by atomic.potato
extern "C" void construct_string(void*, const char*);
extern "C" void initialize_model(void*);

struct FilteredSelection
{
    int f(const char*);
};

int FilteredSelection::f(const char* value)
{
    char buffer[28];
    construct_string(buffer, "d$XP");
    initialize_model(this);
    *(void**)this = (void*)0x00a2e4f8;
    return (int)this;
}
