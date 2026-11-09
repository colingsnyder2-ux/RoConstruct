// from server: 60% by atomic.potato
extern "C" void sub_006b12d0(void *);
extern "C" void std_string_copy(void *, const void *);

struct DropperTool
{
    void *field;
    void *method();
};

void *DropperTool::method()
{
    void *value = 0;
    sub_006b12d0(&value);
    std_string_copy(field, value);
    return field;
}
