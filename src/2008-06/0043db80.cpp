// from server: 100% by king_originala
extern const unsigned int primaryTable[];
extern const unsigned int secondaryTable[];
extern const unsigned int tertiaryTable[];

struct CXTPPropertyGridItem {
    const unsigned int* primary;
    char reserved04[0x1C];
    const unsigned int* secondary;
    char reserved24[0xE8];
    const unsigned int* tertiary;
    char reserved110[0x20];

    CXTPPropertyGridItem(void* value, int argument);
    ~CXTPPropertyGridItem();
    void OnValueChanged(int value);
};

struct Vector3Item : CXTPPropertyGridItem {
    void* value;

    Vector3Item(void* value, int argument);
};

Vector3Item::Vector3Item(void* initialValue, int argument)
    : CXTPPropertyGridItem(initialValue, argument)
{
    primary = primaryTable;
    secondary = secondaryTable;
    tertiary = tertiaryTable;
    value = initialValue;
    OnValueChanged(1);
}
