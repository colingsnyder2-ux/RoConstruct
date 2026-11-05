// from server: 100% by atomic.potato
struct DxUserInput
{
    float x;
    float y;
};

void Add(DxUserInput* self, DxUserInput* other)
{
    other->x += self->x;
    other->y += self->y;
}
