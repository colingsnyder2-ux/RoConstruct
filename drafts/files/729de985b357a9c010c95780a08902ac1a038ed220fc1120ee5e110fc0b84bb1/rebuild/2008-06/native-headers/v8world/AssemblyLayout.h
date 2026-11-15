#pragma once
// 2008-06 native Assembly / Clump (inactive). Two parts:
//   1. RBX::AssemblyLayout (always): a field-offset VIEW for units that also reach the donor v8world/Assembly.h /
//      Clump.h (through the donor or part-embedded v8world/Primitive.h, e.g. Seat.cpp), whose classes put the fields
//      elsewhere (donor Assembly::rootClump +0x8, donor Clump::assembly +0x20). It never collides with RBX::Assembly /
//      RBX::Clump. Padding members are INFERRED: only the named offsets are read from the binary.
//   2. The native 2008 RBX::Clump declaration (only when the unit defines NATIVE_CLUMP_DECL before including this
//      header, and so must not reach the donor v8world/Clump.h / Assembly.h). It needs a 2008 IPipelined: it includes
//      native-headers/v8kernel/IPipelined2008.h, so a unit that also reaches the donor v8world/IPipelined.h (through the
//      donor v8world/Edge.h) defines NATIVE_IPIPELINED2008_DONOR too (same layout, see IPipelined2008.h).
// Evidence (2008-06 binary):
//   RTTI     ??_7Clump 0083f7ac, COL 008ad504: Clump -> IPipelined (mdisp 0), boost::noncopyable (mdisp 8). Three
//            slots: 0 scalar deleting dtor 005e7280 (dtor body 005e70a0), 1 putInKernel 00646970 (`jmp 00645830`,
//            IPipelined::putInKernel), 2 removeFromKernel 005e60d0 (`jmp 00645860`, IPipelined::removeFromKernel).
//            The binary has NO RTTI type descriptor for an RBX::Assembly (only Clump and IPipelined among these; the
//            other IPipelined classes are Primitive and the Edge family), so in 2008 the pipelined "assembly" object
//            is a Clump: Clump(Primitive*) 005e6cf0 stores `this` at +0x24 (a root clump is its own assembly), and
//            SleepStage 0064ae90 hands the same object to SimJobStage 0064d200 / 0064d2a0, which call its slots 1 / 2,
//            IPipelined::putInStage / removeFromStage (00645830 / 00645840) and the Clump-unit members 005e6160 /
//            005e6110 on it.
//   size     0x78 (00668d06: `push 0x78; call new` then Clump(Primitive*) 005e6cf0).
//   Clump    +0x1c root primitive: ctor 005e6cf0 (the argument), Seat::seatCharacter 0063c9f1 and
//            Primitive::setCoordinateFrame 005e826b compare [[assembly+0x24]+0x1c] with the primitive.
//            +0x20 parent clump (ctor zero; dtor 005e70a0 removes this from [+0x20]+0x28 through fastRemoveShort
//            005e5200 and walks [+0x20]).
//            +0x24 assembly: ctor 005e6cf0 (`mov [esi+0x24], esi`); Primitive::getAssembly 005e7570 (`clump =
//            [prim+0x5c]; clump ? [clump+0x24] : 0`), 005e7560 (`[[prim+0x5c]+0x24]`).
//            +0x40 SimJob back-link: ctor zero; SimJobStage insert 0064d0f0 (`[job->slot2()+0x40] = job`), erase
//            0064d180 (`[job->slot2()+0x40] = 0`), getter 005e6110 (`mov eax, [ecx+0x40]`, folded with
//            World::getContactManager) called on the assembly by 0064d2a0 before the erase 0064d180.
//   members  005e6160 (`[[ecx+0x1c]+0xa0]`: the root primitive's body), 005e6170 (notifyMoved: primitive iterator
//            from [ecx+0x1c], myOwner +0xa4 IMoving::notifyMoved 00614be0 per primitive, ++ 00647640), 005e6120
//            (all primitives' +0xac flag, the ctor's computed-property callback at +0x70).

namespace RBX
{
	class Assembly;
	class Primitive;
	class SimJob;

	namespace AssemblyLayout
	{
		struct ClumpFields
		{
			char unknown0[0x1c];          // INFERRED: vptr (??_7Clump 0083f7ac) and fields the views never read
			Primitive* rootPrimitive;      // +0x1c (0063c9f1, 005e826b)
			char unknown20[0x4];           // INFERRED: unread here
			Assembly* assembly;            // +0x24 (005e7570, 005e7560)
		};

		// The 2008 SleepInfo (SleepStage's per-assembly record): only its first field, the Sim::AssemblyState, is
		// read through this view (PartInstance::render3dAdorn 0059e5b2 / 0059e664 `mov eax, [eax]`).
		struct SleepInfoFields
		{
			int state;                     // +0x0 (Sim::AssemblyState: 0 ANCHORED .. 5 SLEEPING_DEEPLY)
		};

		struct AssemblyFields
		{
			char unknown0[0x18];          // INFERRED: fields the views never read
			SleepInfoFields* sleepInfo;    // +0x18 (the 2008 Clump sleepInfo: ctor zero, setter 005e5fe0, SleepStage
			                               // 0064c49b reads [[clump+0x18]]; render3dAdorn 0059e5a7 / 0059e659)
			Primitive* primitive;          // +0x1c (005e6160, 005e6170)
			char unknown20[0x4];           // INFERRED: unread here
			ClumpFields* rootClump;        // +0x24 (0063c9ee, 005e8268)
			char unknown28[0x18];          // INFERRED: unread here
			SimJob* simJob;                // +0x40 (0064d0f0, 0064d180, 005e6110)
		};

		inline AssemblyFields* fields(Assembly* assembly)
		{
			return reinterpret_cast<AssemblyFields*>(assembly);
		}

		// The 2008 sleep status of an assembly (openrbx Assembly::getSleepStatus without the parent walk): the state of
		// its SleepInfo, ANCHORED (0) when it has none. PartInstance::render3dAdorn 0059e5a7..0059e5b6 / 0059e659..
		// 0059e668: load +0x18, test, load [0], test against 0 (ANCHORED). Returned as int so that units which do
		// not reach the Sim::AssemblyState definition can include this view; callers cast to Sim::AssemblyState.
		inline int getSleepStatus(Assembly* assembly)
		{
			SleepInfoFields* sleepInfo = fields(assembly)->sleepInfo;
			return sleepInfo ? sleepInfo->state : 0;
		}

		// assembly->getRootClump()->getRootPrimitive() with the 2008 offsets (+0x24, then +0x1c).
		inline Primitive* getRootPrimitive(Assembly* assembly)
		{
			return fields(assembly)->rootClump->rootPrimitive;
		}
	}
}

#ifdef NATIVE_CLUMP_DECL
#include <vector>
#include <boost/noncopyable.hpp>
#include <G3D/Array.h>
#include "util/ComputeProp.h"
#include "v8kernel/IPipelined2008.h"

namespace RBX
{
	class Body;
	class Edge;
	class Joint;
	class Kernel;
	class MotorJoint;
	class SleepInfo;

	// Declared as native-world/App/include/v8world/Clump.h declares it (that header also declares the WEBSERVICE
	// Clump / Assembly, so it cannot be included next to the 2008 Clump below). 2008 evidence: the Clump-unit loops
	// 005e6120 / 005e6170 build {root primitive, 1 (IN_ASSEMBLY)} on the stack (`mov [esp], eax; mov [esp+4], 1`),
	// call ++ 00647640 (??EPrimIterator@RBX@@QAEAAV01@XZ) and stop when the primitive is NULL; ++ 00647640 calls
	// findFirstChild 00647540 / findParent 006474e0 / findNextRelative 00647600 with (primitive, searchType).
	class PrimIterator
	{
		friend class Clump; // INFERRED: Clump::removePrimitiveImp 005e5ff0 calls the private static findFirstChild 00647540
		                    // (registry ?findFirstChild@PrimIterator@RBX@@CA..., CA = private static) directly

	public:
		enum SearchType
		{
			IN_CLUMP = 0,
			IN_ASSEMBLY = 1,
		};

	private:
		Primitive* primitive;  // 0x00
		SearchType searchType; // 0x04

		static bool isParent(Primitive* parentCandidate, Primitive* child, Joint* joint, SearchType searchType);
		static Primitive* findFirstChild(Primitive* primitive, SearchType searchType);
		static Primitive* findNextSibling(Primitive* parent, Primitive* child, SearchType searchType);
		static Primitive* findNextRelative(Primitive* parent, Primitive* child, SearchType searchType);

		PrimIterator(Primitive* primitive, SearchType searchType) : primitive(primitive), searchType(searchType) {}

	public:
		static PrimIterator begin(Primitive* primitive, SearchType searchType)
		{
			return PrimIterator(primitive, searchType);
		}
		static PrimIterator end(SearchType searchType) { return PrimIterator(NULL, searchType); }

		Primitive* operator*() const { return primitive; }

		bool operator==(const PrimIterator& other) const { return primitive == other.primitive; }
		bool operator!=(const PrimIterator& other) const { return primitive != other.primitive; }

		PrimIterator& operator++();                      // 00647640

		static Primitive* findParent(Primitive* primitive, SearchType searchType);
	};

	// Declared as native-world/App/include/v8world/Clump.h declares it (SIZE 0x08). 2008 evidence: Clump 005e6ba0 calls
	// begin 00647730 (?begin@EdgeIterator@RBX@@SA?AV12@PAVPrimitive@2@@Z, hidden return slot) and ++ 00647700
	// (??EEdgeIterator@RBX@@QAEAAV01@XZ), compares {primitive +0x0, edge +0x4} against the function-local static of the
	// inline end() (guard 0097abb4, value 0097abac / 0097abb0 zeroed on first use) and appends edge +0x4.
	class EdgeIterator
	{
	public:
		static EdgeIterator begin(Primitive* primitive); // 00647730

		EdgeIterator() : primitive(NULL), edge(NULL) {}

		EdgeIterator(Primitive* primitive, Edge* edge) : primitive(primitive), edge(edge) {}

		static EdgeIterator& end();

		EdgeIterator& operator++();                      // 00647700

		Edge* operator*() const { return edge; }

		bool operator==(const EdgeIterator& other) const { return edge == other.edge && primitive == other.primitive; }

		bool operator!=(const EdgeIterator& other) const { return !(*this == other); }

	private:
		static Edge* getNextExternalUtil(Primitive* primitive, Edge* edge);

		void findEdgeOnNextPrimitive();

		Primitive* primitive; // 0x00
		Edge* edge;           // 0x04
	};

	inline EdgeIterator& EdgeIterator::end()
	{
		static EdgeIterator temp;
		return temp;
	}

	class Clump : public IPipelined, public boost::noncopyable
	{
		friend class Assembly; // INFERRED: Assembly::getMotor 005e6400 (registry) calls the private getMotorImp 005e6360

	private:
		G3D::Array<Edge*> externalEdges;                 // +0x08 (analog name; Array<T*>: data +0x8, num +0xc, numAllocated
		                                                 // +0x10; ctor 005e6cf0 zeroes them, dtor 005e70a0 alignedFree
		                                                 // 00507d20 then zeroes; 005e6c70 resize 005e6540 and refills it
		                                                 // through 005e6ba0 from EdgeIterator::begin 00647730 / ++ 00647700)
		bool externalEdgesDirty;                         // +0x14 (analog name; ctor true, 005e62a0 sets it, 005e6c70 tests
		                                                 // and clears it)
		SleepInfo* sleepInfo;                            // +0x18 (ctor zero; setter 005e5fe0; SleepStage 0064c49b reads
		                                                 // [[clump+0x18]] as the SleepInfo state)
		Primitive* rootPrimitive;                        // +0x1c (005e6cf0, 005e6160, 005e6170)
		Clump* parent;                                   // +0x20 (analog name; 005e6cf0, 005e70a0, 005e6fd0, 005e6070)
		Assembly* assembly;                              // +0x24 (005e6cf0 stores this; 005e6240; 005e7570)
		std::vector<Assembly*> children;                 // +0x28 (+0x28 aux proxy, +0x34 / +0x38 / +0x3c; 005e6cf0, 005e70a0;
		                                                 // fastRemoveShort<Assembly*> 005e5200 is the registry name)
		SimJob* simJob;                                  // +0x40 (005e6cf0, 0064d0f0, 0064d180, 005e6110)
		int sleepStepId;                                 // +0x44 (INFERRED name: ctor -1; SleepStage 0064c582 / 0064c759
		                                                 // store the stage step id +0x1d8 here)
		int sleepStepCount;                              // +0x48 (INFERRED name: ctor -1; SleepStage 0064c58b / 0064c760
		                                                 // store a counter / 0 here)
		ComputeProp<float, Clump> maxRadius;             // +0x50 (dirty +0x54, object +0x58, getter 005e6420 at +0x60 and
		                                                 // adjustor 0 at +0x64: the 8-byte member pointer of a class with
		                                                 // two bases, 8-aligned)
		ComputeProp<bool, Clump> canSleep;               // +0x68 (dirty +0x69, object +0x6c, getter 005e6120 at +0x70, 0 at
		                                                 // +0x74; size 0x78)

		float computeMaxRadius() const;                  // 005e6420 (analog name: openrbx Assembly::computeMaxRadius)
		bool computeCanSleep() const;                    // 005e6120 (analog name: openrbx Assembly::computeCanSleep;
		                                                 // the ctor 005e6cf0 stores it at +0x70 with this at +0x6c)
		void onPrimitivesChanged();                      // 005e62a0 (analog name: three dirty flags, then the parent's)
		void setAssembly(Assembly* value);               // 005e6240 (analog name: +0x24 here and in every child)
		void addChild(Assembly* child);                  // 005e6f70 (analog name: push_back 004213a0, then std::sort)
		void removePrimitiveImp(Primitive* p);           // 005e5ff0 (INFERRED name: children first through
		                                                 // PrimIterator::findFirstChild IN_CLUMP, then Body::setParent(NULL)
		                                                 // 006148b0 and Primitive::setClump(NULL) 005e7550)
		static Joint* getJointToParent(Primitive* p);    // 005e6080 (analog name: openrbx Assembly::getJointToParent;
		                                                 // cdecl, callers 005e62d0 / 005e6360)
		const MotorJoint* getMotorImp(unsigned int& motorId) const;   // 005e6360 (analog name; caller getMotor 005e6400)
		void computeExternalEdges(G3D::Array<Edge*>& edges);          // 005e6ba0 (INFERRED name: EdgeIterator from the root
		                                                              // primitive, append; only caller 005e6c70)

	public:
		Clump(Primitive* root);                          // 005e6cf0 (Clump.cpp; calls Primitive::setClump 005e7550)
		virtual ~Clump();                                // slot 0 (??_G 005e7280, body 005e70a0)
		virtual void putInKernel(Kernel* kernel);        // slot 1 (00646970, `jmp 00645830`)
		virtual void removeFromKernel();                 // slot 2 (005e60d0, `jmp 00645860`)

		Primitive* getRootPrimitive() const
		{
			return rootPrimitive;
		}
		Assembly* getAssembly() const
		{
			return assembly;
		}
		void setSimJob(SimJob* job)                      // analog name: inline stores of 0064d0f0 / 0064d180
		{
			simJob = job;
		}
		SimJob* getSimJob();                             // 005e6110 (analog name; folded with World::getContactManager)
		Body* getBody();                                 // 005e6160 (analog name)
		void notifyMoved();                              // 005e6170 (analog name)
		void setSleepInfo(SleepInfo* value);             // 005e5fe0 (analog name: openrbx Assembly::setSleepInfo)
		Assembly* getRootAssembly();                     // 005e6070 (analog name: parent ? parent->getRootAssembly() : this)
		void setParent(Clump* newParent);                // 005e6fd0 (analog name: openrbx Assembly::setParent)
		void removePrimitive(Primitive* p);              // 005e6790 (INFERRED name: 005e5ff0, then onPrimitivesChanged)
		void onPrimitiveCanSleepChanged(Primitive* p);   // 005e6530 (analog name: canSleep.setDirty())
		bool getAnchored() const;                        // 005e60e0 (analog name: the root primitive's +0xa8 / +0xa9 / +0xaa;
		                                                 // callers TreeStage::cleanAssembly 00668f20 / cleanEdge 00668fa0)
		unsigned int numMotors() const;                  // 005e62d0 (analog name: openrbx Assembly::numMotors)
		const G3D::Array<Edge*>& getExternalEdges();     // 005e6c70 (INFERRED name: refills externalEdges +0x8 when
		                                                 // externalEdgesDirty +0x14; callers SleepStage 0064a790 / 0064a950
		                                                 // / 0064c470)
	};

	// INFERRED: the 2008 binary has no RTTI for an RBX::Assembly and the assembly object is its root Clump (Clump()
	// 005e6cf0 stores this at +0x24), while the registry names that carry the type (Primitive::getAssembly 005e7570,
	// AssemblySimJob(Assembly*) 005e51e0) spell RBX::Assembly. Declared as a Clump that adds no members and no
	// virtuals, never constructed (so no vtable or RTTI of its own, as in the binary): every member called on it is a
	// Clump member, as 005e6110 / 005e6160 / 005e6170 are Clump-unit code.
	class Assembly : public Clump
	{
	public:
		Clump* getRootClump() const                      // the +0x24 view of 0063c9ee / 005e8268
		{
			return Clump::getAssembly();
		}
		MotorJoint* getMotor(unsigned int index);        // 005e6400 ?getMotor@Assembly@RBX@@QAEPAVMotorJoint@2@I@Z (registry)
	};

	// 005e5f60 (analog name: openrbx lessAssembly; cdecl, the comparator addChild 005e6f70 passes to std::_Sort 005e6e90).
	bool lessAssembly(const Assembly* a0, const Assembly* a1);
}
#endif
