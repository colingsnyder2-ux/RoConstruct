// from server: 43% by atomic.potato
extern "C" int __cdecl sprintf(char*, const char*, ...);

struct MVCXTPPropertyGridItemXItem
{
    void Format(double value);
};

extern "C" void* __stdcall sub_B247C8(void*, const char*);
extern "C" void __stdcall sub_B22A40(char*, const char*, double);
extern "C" void __cdecl sub_454790(char*);

extern const char str_b460cc[];
extern const char str_b53b20[];
extern const char str_b53b18[];
extern const char str_b53b10[];
extern const char str_b53b00[];
extern const char str_b53af8[];
extern const char str_b53ae8[];
extern const char str_b53ad4[];
extern const char str_b53acc[];

extern const double dbl_b53b28;
extern const double dbl_b4fd68;
extern const double dbl_b53b08;
extern const double dbl_b507e0;
extern const double dbl_b53af0;
extern const double dbl_b53ae0;

void MVCXTPPropertyGridItemXItem::Format(double value)
{
    char buf[40];

    if (value == 0.0)
    {
        sub_B247C8(this, str_b460cc);
        return;
    }

    double a = value < 0.0 ? -value : value;

    if (a >= dbl_b53b28)
    {
        sprintf(buf, str_b53b20, value);
    }
    else if (a >= dbl_b4fd68)
    {
        sub_B22A40(buf, str_b53b18, value);
        sub_454790(buf);
    }
    else if (a >= 1.0)
    {
        sprintf(buf, str_b53b10, value);
    }
    else if (a >= dbl_b53b08)
    {
        sub_B22A40(buf, str_b53b00, value);
        sub_454790(buf);
    }
    else if (a >= dbl_b507e0)
    {
        sub_B22A40(buf, str_b53af8, value);
        sub_454790(buf);
    }
    else if (a >= dbl_b53af0)
    {
        sub_B22A40(buf, str_b53ae8, value);
        sub_454790(buf);
    }
    else if (a >= dbl_b53ae0)
    {
        sub_B22A40(buf, str_b53ad4, value);
    }
    else
    {
        sub_B22A40(buf, str_b53acc, value);
    }

    sub_B247C8(this, buf);
}
