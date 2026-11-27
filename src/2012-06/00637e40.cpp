// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
class TokenException
{
public:
    TokenException(const TokenException&);
    virtual ~TokenException();
    char pad[0x74];
};
class WrongTokenType : public TokenException
{
public:
    int expected;
    int actual;
    WrongTokenType(const WrongTokenType& o);
    virtual ~WrongTokenType();
};
WrongTokenType::WrongTokenType(const WrongTokenType& o)
    : TokenException(o), expected(o.expected), actual(o.actual)
{
}
