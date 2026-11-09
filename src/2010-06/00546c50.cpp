// from server: 70% by atomic.potato
extern "C" void __cdecl sub_7A89B2(const char **, const char *);

void f() {
    const char *message = "shouldn't be here";
    sub_7A89B2(&message, (const char *)0x00A1F310);
}
