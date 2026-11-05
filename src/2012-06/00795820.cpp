// from server: 35% by colin
struct PartInstance;

struct StateBase {
    void construct(PartInstance* p);
};

struct HumanoidState {
    PartInstance* floorPart;
    StateBase state;
    void init(PartInstance* p, int a);
};

void __stdcall sub_75A4E0(void*, void*, void*);

void HumanoidState::init(PartInstance* p, int a)
{
    floorPart = p;
    state.construct(p);
    PartInstance* q = 0;
    if (p != 0)
        q = (PartInstance*)((char*)p + 0x20);
    sub_75A4E0(&state, q, p);
}
