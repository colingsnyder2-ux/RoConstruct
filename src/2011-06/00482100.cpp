// from server: 66% by atomic.potato
struct InsertModelFromRobloxVerb
{
    char pad0[0x10];
    void* value;
    double number;
    bool ShouldShow();
};

extern "C" void __cdecl Function_0053F700();
extern "C" bool __cdecl Function_005E7940(void*);

double Global_00A690F0;

bool InsertModelFromRobloxVerb::ShouldShow()
{
    Function_0053F700();
    if (this->number + Global_00A690F0 <= 0.0)
        return false;
    return Function_005E7940(this->value);
}
