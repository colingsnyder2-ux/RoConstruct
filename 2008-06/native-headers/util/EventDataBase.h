#pragma once
#include <boost/weak_ptr.hpp>

namespace RBX {
// Original RTTI and EventData construction prove two virtual slots and weak
// storage at +4/+8. Original weak pointee identity remains unverified.
class EventDataBase {
public:
    virtual void execute() = 0;
    virtual ~EventDataBase();
    boost::weak_ptr<void> source;
};
}
