// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs roc_unit_6630ef960eaea8fd.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/Vector2.h>
extern "C" double __cdecl clockSeconds();

struct Event {
    int type;
    int data1;
    int data2;
    int data3;
    short x;
    short y;
};

struct Context {
    int value;
};

struct Input {
    Event event;
    Context* context;
};

struct Handler;

struct Result {
    int handled;
    Handler* next;
};

struct Handler {
    virtual Result* process(Result* result, const Input* input);
};

struct Service {
    char padding[0x130];
    Handler handler;
};

struct FinalService {
    char padding[0x2e8];
    Handler handler;
};

struct Statistics {
    char padding[0x1e0];
    double elapsed;
};

struct S {
    char padding0[0x1f0];
    Context context;
    char padding1[8];
    Service* service1;
    int padding2;
    FinalService* finalService;
    int padding3;
    Statistics* statistics;
    char padding4[12];
    Service* service2;
    int padding5;
    Service* service3;
    int padding6;
    Handler* current;
    bool captured;

    Result* processLocal(Result* result, const Input* input);
    void processEvent(const Event* event);
};

extern G3D::Vector2 canvasSize;
extern "C" void __cdecl notifyInput(S* object);

void S::processEvent(const Event* event)
{
    double started = clockSeconds();

    if (event->type >= 1 && event->type <= 7) {
        canvasSize = G3D::Vector2(event->x,event->y);
    }

    Context* source = this ? &context : 0;
    Input input;
    input.event = *event;
    input.context = source;

    Result temporary;
    Result* initial;
    if (current) {
        initial = current->process(&temporary, &input);
    } else {
        temporary.handled = 0;
        temporary.next = 0;
        initial = &temporary;
    }

    Result result = *initial;

    if (!result.handled) {
        result = *service3->handler.process(&temporary, &input);
        if (!result.handled) {
            result = *service2->handler.process(&temporary, &input);
            if (!result.handled) {
                result = *service1->handler.process(&temporary, &input);
                if (!result.handled)
                    result = *processLocal(&temporary, &input);
            }
        }
    }

    captured = result.handled &&
        current != (finalService ? &finalService->handler : 0);

    if (!result.handled)
        result = *finalService->handler.process(&temporary, &input);

    if ((event->type >= 1 && event->type <= 7) || event->type == 10)
        notifyInput(this);

    current = result.next;

    Statistics* stats = statistics;
    stats->elapsed += clockSeconds() - started;
}
