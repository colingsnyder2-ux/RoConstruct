/**
 @file GModule.cpp

 @maintainer Morgan McGuire, morgan3d@users.sourceforge.net

 @created 2006-04-22
 @edited  2006-04-22
*/

#include "GLG3D/GModule.h"
#include "GLG3D/RenderDevice.h"

namespace G3D {


GModuleManagerRef GModuleManager::create() {
    return new GModuleManager();
}


GModuleManager::GModuleManager() : m_locked(false), m_size(0), m_removeAll(false) {
}


int GModuleManager::size() const {
    return m_size;
}


const GModuleRef& GModuleManager::operator[](int i) const {
    debugAssert(i >= 0 && i < m_size);
    for (int p = NUM_PRIORITY - 1; p >= 0; --p) {
        if (i < m_moduleArray[p].size()) {
            return m_moduleArray[p][i];
        } else {
            // Look in the next array.  We are guaranteed
            // not to underflow by the assertion above.
            i -= m_moduleArray[p].size();
        }
    }

    static GModuleRef tmp;
    return tmp;
}


void GModuleManager::beginLock() {
    debugAssert(! m_locked);
    m_locked = true;
}


void GModuleManager::endLock() {
    debugAssert(m_locked);
    m_locked = false;

    // Process add list
    for (int i = 0; i < m_addList.size(); ++i) {
        add(m_addList[i].module, m_addList[i].priority);
    }
    m_addList.clear();

    // Process remove list
    for (int i = 0; i < m_removeList.size(); ++i) {
        remove(m_removeList[i]);
    }
    m_removeList.clear();

    if (m_removeAll) {
        clear();
        m_removeAll = false;
    }
}


void GModuleManager::remove(const GModuleRef& m) {
    if (m_locked) {
        m_removeList.append(m);
    } else {
        for (int p = 0; p < NUM_PRIORITY; ++p) {
            int j = m_moduleArray[p].findIndex(m);
            if (j != -1) {
                m_moduleArray[p].fastRemove(j);
                --m_size;
                return;
            }
        }
        debugAssertM(false, "Removed a GModule that was not in the manager.");
    }
}


void GModuleManager::add(const GModuleRef& m, EventPriority p) {
    debugAssert(p >= LOW_PRIORITY && p <= HIGH_PRIORITY);
    if (m_locked) {
        m_addList.append(Add(m, p));
    } else {
        ++m_size;
        m_moduleArray[p].append(m);
    }
}


void GModuleManager::clear() {
    if (m_locked) {
        m_removeAll = true;
    } else {
        for (int p = 0; p < NUM_PRIORITY; ++p) {
            m_moduleArray[p].clear();
        }
    }
}

// Iterate through all modules in priority order.
// This same iteration code is used to implement
// all GModule methods concisely.
#define ITERATOR(body)\
    beginLock();\
    for (int p = NUM_PRIORITY - 1; p >= 0; --p) {\
        Array<GModuleRef>& array = m_moduleArray[p];\
        for (int i = array.size() - 1; i >= 0; --i) {\
            body;\
        }\
    }\
    endLock();

void GModuleManager::getPosedModel(
    Array<PosedModelRef>& posedArray, 
    Array<PosedModel2DRef>& posed2DArray) {

    ITERATOR(array[i]->getPosedModel(posedArray, posed2DArray));
}


void GModuleManager::onSimulation(RealTime rdt, SimTime sdt, SimTime idt) {
    ITERATOR(array[i]->onSimulation(rdt, sdt, idt));
}

bool GModuleManager::onEvent(const GEvent& event) {
    // if the event is ever consumed, abort iteration
    ITERATOR(if (array[i]->onEvent(event)) { endLock(); return true; });
    return false;
}

void GModuleManager::onUserInput(UserInput* ui) {
    ITERATOR(array[i]->onUserInput(ui));
}

void GModuleManager::onNetwork() {
    ITERATOR(array[i]->onNetwork());
}

void GModuleManager::onLogic() {
    ITERATOR(array[i]->onLogic());
}

#undef ITERATOR


bool GModuleManager::onEvent(const GEvent& event, GModuleManagerRef& a, GModuleManagerRef& b) {
    a->beginLock();
    b->beginLock();

    for (int p = NUM_PRIORITY - 1; p >= 0; --p) {

        // Process each, interlaced
        for (int k = 0; k < 2; ++k) {
            Array<GModuleRef>& array = 
                (k == 0) ?
                    a->m_moduleArray[p] :
                    b->m_moduleArray[p];
                
            for (int i = array.size() - 1; i >= 0; --i) {
                if (array[i]->onEvent(event)) {
                    b->endLock();
                    a->endLock();
                    return true;
                }
            }
        }

    }
    
    b->endLock();
    a->endLock();

    return false;
}


} // G3D
