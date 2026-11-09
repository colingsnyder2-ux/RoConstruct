// from server: 37% by atomic.potato
typedef unsigned int DWORD;

struct VBrickColor
{
    char pad[0x12c];
    void* field_12c;
    void* f(void* out);
};

void* VBrickColor::f(void* out)
{
    void* value = 0;
    if (out != 0)
        value = (char*)out + 0x1c;
    else
        value = 0;
    field_12c = value;
    return out;
}
