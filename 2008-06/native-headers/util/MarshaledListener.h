#pragma once
#include "util/Events.h"
#include "util/MarshalWindow.h"
#include "util/EventDataBase.h"

namespace RBX {
CMarshalWindow* __cdecl acquireMarshalWindow();
void __cdecl releaseMarshalWindow(CMarshalWindow*);

// Inactive recovery. Original RTTI proves four template parameters and the
// Listener base; event dispatch/filter behavior still needs separate recovery.
template<class Source, class Event, class Target = Source, class TargetEvent = Event>
class MarshaledListener : public Listener<Source, Event> {
public:
    std::vector<EventDataBase*> pending;
    DWORD threadId;
    CMarshalWindow* window;

    MarshaledListener() : threadId(GetCurrentThreadId()), window(acquireMarshalWindow()) {}
    virtual ~MarshaledListener() { detach(); releaseMarshalWindow(window); }
    virtual void onEvent(const Source*, Event);
    virtual void onMarshaledEvent(const Target*, TargetEvent) = 0;
    virtual void marshal(const Source*, Event);
    void detach();
};

template<class Source, class Event, class Target = Source, class TargetEvent = Event>
class FilteredListener : public MarshaledListener<Source, Event, Target, TargetEvent> {
public:
    virtual void marshal(const Source*, Event);
    virtual bool filter(const Source*, const Event&, const Source*, const Event&) = 0;
};
}
