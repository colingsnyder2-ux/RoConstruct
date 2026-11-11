#pragma once
// >>> native-status (generated) -- do not edit >>>
// MarshaledListener | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src be70aacb | roc native-status --write
#include "util/Events.h"
#include "util/MarshalWindow.h"
#include "util/EventDataBase.h"
#include "util/Object.h"

namespace RBX {
CMarshalWindow* __cdecl acquireMarshalWindow();
void __cdecl releaseMarshalWindow(CMarshalWindow*);

// Inactive recovery. Original RTTI proves four template parameters and the
// Listener base; selected Selection dispatch/filter bodies match. Global lifetime
// and game integration remain open.
template<class Source, class Event, class Target = Source, class TargetEvent = Event>
class MarshaledListener : public Listener<Source, Event> {
public:
    class EventData : public EventDataBase {
    public:
        boost::shared_ptr<const Source> source;
        MarshaledListener* listener;
        Event event;
        EventData(MarshaledListener* owner, const Source* from, Event value)
            : listener(owner), event(value)
        {
            setSource(from);
        }
        void setSource(const Source* from) { source = shared_from(from); }
        virtual ~EventData()
        {
            if (listener) listener->remove(this);
        }
        virtual void execute()
        {
            if (listener) {
                try {
                    listener->remove(this);
                    listener->onMarshaledEvent(static_cast<const Target*>(source.get()), event);
                } catch (...) {
                }
                listener = NULL;
            }
        }
    };
    std::vector<EventData*> pending;
    DWORD threadId;
    CMarshalWindow* window;

    MarshaledListener() : threadId(GetCurrentThreadId()), window(acquireMarshalWindow()) {}
    virtual ~MarshaledListener() { detach(); releaseMarshalWindow(window); }
    virtual void onEvent(const Source* source, Event event) throw()
    {
        ATL::CCriticalSection& criticalSection = window->criticalSection;
        criticalSection.Enter();
        marshal(source, event);
        criticalSection.Leave();
    }
    virtual void onMarshaledEvent(const Target*, TargetEvent) = 0;
    virtual void marshal(const Source* source, Event event) throw()
    {
        EventData* data = new EventData(this, source, event);
        pending.push_back(data);
        window->post(data);
    }
    void remove(EventData* data)
    {
        ATL::CCritSecLock lock(window->criticalSection);
        for (std::vector<EventData*>::iterator it = pending.begin(); it != pending.end(); ++it) {
            if (*it == data) {
                pending.erase(it);
                break;
            }
        }
    }
    void detach()
    {
        ATL::CCritSecLock lock(window->criticalSection);
        for (std::vector<EventData*>::iterator it = pending.begin(); it != pending.end(); ++it)
            (*it)->listener = NULL;
        pending.erase(pending.begin(), pending.end());
    }
};

template<class Source, class Event, class Target = Source, class TargetEvent = Event>
class FilteredListener : public MarshaledListener<Source, Event, Target, TargetEvent> {
public:
    virtual void marshal(const Source* source, Event event) throw()
    {
        for (std::vector<EventData*>::iterator it = pending.begin(); it != pending.end(); ++it) {
            if (filter(source, event, (*it)->source.get(), (*it)->event)) {
                if ((*it)->source.get() != source) (*it)->setSource(NULL);
                return;
            }
        }
        MarshaledListener<Source, Event, Target, TargetEvent>::marshal(source, event);
    }
    virtual bool filter(const Source*, const Event&, const Source*, const Event&) = 0;
};
}
