// from server: 66% by atomic.potato
struct S_00653eb0
{
    unsigned int find(const char* s, unsigned int pos, unsigned int n) const;
};

bool f_00653eb0(const S_00653eb0* self)
{
    return self->find("http://", 0, 7) == 0
        || self->find("https://", 0, 8) == 0
        || self->find("rbxasset://", 0, 11) == 0;
}
