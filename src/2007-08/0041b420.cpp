// from server: 100% by EspClaude
// from server: 49% by colin
// roc 2007-08 0041b420  unit: VDHTMLWindowService::?$FactoryProduct::Creator  size: 90 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0041b420
// 0041b420  51                   push ecx
// 0041b421  53                   push ebx
// 0041b422  55                   push ebp
// 0041b423  56                   push esi
// 0041b424  57                   push edi
// 0041b425  83ec0c               sub esp, 0xc
// 0041b428  8964241c             mov dword ptr [esp + 0x1c], esp
// 0041b42c  8bdc                 mov ebx, esp
// 0041b42e  33ff                 xor edi, edi
// 0041b430  57                   push edi
// 0041b431  83ec18               sub esp, 0x18
// 0041b434  89642438             mov dword ptr [esp + 0x38], esp
// 0041b438  8bec                 mov ebp, esp
// 0041b43a  6890bf4200           push 0x42bf90
// 0041b43f  83ec08               sub esp, 8
// 0041b442  8bc4                 mov eax, esp
// 0041b444  89642444             mov dword ptr [esp + 0x44], esp
// 0041b448  51                   push ecx
// 0041b449  50                   push eax
// 0041b44a  be904a4100           mov esi, 0x414a90
// 0041b44f  e81c220800           call 0x49d670
// 0041b454  83c408               add esp, 8
// 0041b457  57                   push edi
// 0041b458  56                   push esi
// 0041b459  55                   push ebp
// 0041b45a  e881a3ffff           call 0x4157e0
// 0041b45f  83c418               add esp, 0x18
// 0041b462  8bcb                 mov ecx, ebx
// 0041b464  e837feffff           call 0x41b2a0
// 0041b469  8b0dccaf8b00         mov ecx, dword ptr [0x8bafcc]
// 0041b46f  e8dcc2ffff           call 0x417750
// 0041b474  5f                   pop edi
// 0041b475  5e                   pop esi
// 0041b476  5d                   pop ebp
// 0041b477  5b                   pop ebx
// 0041b478  59                   pop ecx
// 0041b479  c3                   ret 

struct sp_counted_base;

template<class T>
struct shared_ptr {
    T* px;
    sp_counted_base* pn;
    shared_ptr(const shared_ptr& r);
    ~shared_ptr();
};

struct Base1 { virtual void a(); };
struct Base2 { virtual void b(); };
struct Item;
typedef void (*CallbackFn)(Item*);

struct Owner : Base1, Base2 {
    void onEvent(CallbackFn cb, Item* item);
    void connect();
};

template<class T> shared_ptr<T> shared_from(T* p);

struct empty_arg {};

struct Functor {
    void (Owner::*f)(CallbackFn, Item*);
    shared_ptr<Owner> sp;
    CallbackFn cb;
    empty_arg a;
    Functor(const Functor&);
    ~Functor();
};

Functor bind(void (Owner::*f)(CallbackFn, Item*), shared_ptr<Owner> sp, CallbackFn cb);

struct function1 {
    void* manager;
    void* functor;
    void* invoker;
    function1(Functor f, int = 0);
    function1(const function1&);
    ~function1();
};

struct Signal {
    void connect(function1 f);
};

extern Signal* g_signal;

void callbackFn(Item*);

void Owner::connect()
{
    g_signal->connect(bind(&Owner::onEvent, shared_from(this), &callbackFn));
}
