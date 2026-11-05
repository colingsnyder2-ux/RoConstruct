// from server: 52% by atomic.potato
extern "C" void Update(void*);
extern "C" int __stdcall Continue(void*);

struct InsertModelFromRobloxVerb {
    char pad0[0x10];
    void* value;
    double time;
    bool ShouldShow();
};

double g_value;

bool InsertModelFromRobloxVerb::ShouldShow()
{
    Update(this);
    if (this->time > this->time + g_value)
        return false;
    return Continue(this->value) != 0;
}
