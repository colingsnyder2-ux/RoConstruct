// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs roc_sleep_contact_kernel_predicates_da9029bdf43a589f.cpp

// Candidate translation unit (score above; library headers required).
#undef _RELEASEASSERT
#include <stddef.h>
#include "util/IndexArray.h"
namespace RBX {
namespace Sim {enum EdgeState {UNDEFINED,STEPPING,SLEEPING,TOUCHING,TOUCHING_SLEEPING};}
class Kernel;class Primitive;class World;class Edge;
class IStage {
public:
 virtual ~IStage();
 IStage* upstream;IStage* downstream;
 virtual int getStageType()=0;
 virtual void stepWorld(int,int,bool);
 virtual Kernel* getKernel();
 IStage* getDownstream(){return downstream;}
};
class IWorldStage:public IStage {
public:
 World* world;
 virtual void onEdgeAdded(Edge*);
 virtual void onEdgeRemoving(Edge*);
 IWorldStage* getDownstreamWS(){return static_cast<IWorldStage*>(getDownstream());}
};
class IPipelined {
public:
 virtual ~IPipelined();
 virtual void putInKernel(Kernel*);virtual void removeFromKernel();
 IStage* currentStage;
};
class Edge:public IPipelined {
public:
 Sim::EdgeState edgeState;Primitive* prim0;Primitive* prim1;Edge* next0;Edge* next1;bool inEdgeList;
 virtual int getEdgeType()const=0;
 virtual void setPrimitive(int,Primitive*);
 Sim::EdgeState getEdgeState()const{return edgeState;}
 void setEdgeState(Sim::EdgeState s){edgeState=s;}
};
class Contact:public Edge {
public:
 int lastUiContactStep;int steppingIndex;
 int& steppingIndexFunc(){return steppingIndex;}
};
class SleepStage:public IWorldStage {
public:
 typedef IndexArray<Contact,&Contact::steppingIndexFunc> ContactList;
 char beforeCount[0xd4-sizeof(IWorldStage)];int numContactsInKernel;
 char beforeLists[0x1a0-0xd8];ContactList steppingContacts;ContactList touchingContacts;
 void touchEvent(Contact*);void wakeEvent(Contact*);
 void changeContactState(Contact*,Sim::EdgeState);
};
typedef char edge_size[sizeof(Edge)==32?1:-1];
typedef char contact_index_offset[offsetof(Contact,steppingIndex)==0x24?1:-1];
typedef char edge_state_offset[offsetof(Edge,edgeState)==8?1:-1];
typedef char downstream_offset[offsetof(IStage,downstream)==8?1:-1];
typedef char list_offset[offsetof(SleepStage,steppingContacts)==0x1a0?1:-1];
typedef char touching_offset[offsetof(SleepStage,touchingContacts)==0x1ac?1:-1];
typedef char list_size[sizeof(SleepStage::ContactList)==12?1:-1];
void SleepStage::changeContactState(Contact* c, Sim::EdgeState newState)
{
	Sim::EdgeState currentState = c->getEdgeState();

	bool wasStepping = currentState == Sim::STEPPING;
	bool wasTouching = currentState == Sim::TOUCHING;
	bool desiredInStepping = newState == Sim::STEPPING;
	bool isTouching = newState == Sim::TOUCHING;

	if (wasStepping != desiredInStepping) {
		if (wasStepping) {
			steppingContacts.fastRemove(c);
		}
	}

	if (wasTouching != isTouching) {
		if (wasTouching) {
			touchingContacts.fastRemove(c);
		}
	}

	if (wasStepping != desiredInStepping) {
		if (desiredInStepping) {
			steppingContacts.fastAppend(c);
		}
	}

	if (wasTouching != isTouching) {
		if (isTouching) {
			touchingContacts.fastAppend(c);
		}
	}

	bool wasInKernel = currentState == Sim::TOUCHING;
	bool desiredInKernel = newState == Sim::TOUCHING;
	if (wasInKernel != desiredInKernel) {
		if (wasInKernel) {
			getDownstreamWS()->onEdgeRemoving(c);
			numContactsInKernel--;
		}
		else {
			getDownstreamWS()->onEdgeAdded(c);
			numContactsInKernel++;
		}
	}

	if (currentState == Sim::STEPPING && newState == Sim::TOUCHING) {
		touchEvent(c);
	}
	else if (currentState == Sim::TOUCHING && newState == Sim::STEPPING) {
		wakeEvent(c);
	}

	c->setEdgeState(newState);
}

}
