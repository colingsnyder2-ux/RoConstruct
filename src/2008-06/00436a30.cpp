// from server: 100% by king_originala
struct VCSecureHtmlView {
    char pad[0xf0];
    char field_f4;

    VCSecureHtmlView();
    virtual ~VCSecureHtmlView();
};

struct COutputView : VCSecureHtmlView {
    struct Data {
        void** proxy;
        char pad[12];
        unsigned long field_10;
        unsigned long field_14;
        unsigned long field_18;
        unsigned long field_1c;

        Data();
    };

    Data data;
    unsigned long field_118;
    unsigned long field_11c;

    COutputView();
    virtual ~COutputView();
};

inline COutputView::Data::Data()
    : proxy(new void*(this)),
      field_10(0),
      field_14(0),
      field_18(0),
      field_1c(0)
{
}

COutputView::COutputView()
    : field_118(0), field_11c(0)
{
}
