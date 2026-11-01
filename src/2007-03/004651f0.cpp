// from server: 100% by tester
struct DxUserInput {
    float x;
    float y;
};

void DxUserInput_Add(DxUserInput* a, DxUserInput* b)
{
    b->x = b->x + a->x;
    b->y = b->y + a->y;
}
