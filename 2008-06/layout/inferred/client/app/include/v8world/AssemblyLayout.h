#pragma once
//      RBX::Clump. Padding members are INFERRED: only the named offsets are read from the binary.

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

		struct SleepInfoFields
		{
			int state;                     // +0x0 (Sim::AssemblyState: 0 ANCHORED .. 5 SLEEPING_DEEPLY)
		};

		struct AssemblyFields
		{
			char unknown0[0x18];          // INFERRED: fields the views never read
			SleepInfoFields* sleepInfo;    // +0x18 (the 2008 Clump sleepInfo: ctor zero, setter 005e5fe0, SleepStage
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
		bool externalEdgesDirty;                         // +0x14 (analog name; ctor true, 005e62a0 sets it, 005e6c70 tests
		                                                 // and clears it)
		SleepInfo* sleepInfo;                            // +0x18 (ctor zero; setter 005e5fe0; SleepStage 0064c49b reads
		                                                 // [[clump+0x18]] as the SleepInfo state)
		Primitive* rootPrimitive;                        // +0x1c (005e6cf0, 005e6160, 005e6170)
		Clump* parent;                                   // +0x20 (analog name; 005e6cf0, 005e70a0, 005e6fd0, 005e6070)
		Assembly* assembly;                              // +0x24 (005e6cf0 stores this; 005e6240; 005e7570)
		std::vector<Assembly*> children;                 // +0x28 (+0x28 aux proxy, +0x34 / +0x38 / +0x3c; 005e6cf0, 005e70a0;
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
		void onPrimitivesChanged();                      // 005e62a0 (analog name: three dirty flags, then the parent's)
		void setAssembly(Assembly* value);               // 005e6240 (analog name: +0x24 here and in every child)
		void addChild(Assembly* child);                  // 005e6f70 (analog name: push_back 004213a0, then std::sort)
		void removePrimitiveImp(Primitive* p);           // 005e5ff0 (INFERRED name: children first through
		static Joint* getJointToParent(Primitive* p);    // 005e6080 (analog name: openrbx Assembly::getJointToParent;
		const MotorJoint* getMotorImp(unsigned int& motorId) const;   // 005e6360 (analog name; caller getMotor 005e6400)
		void computeExternalEdges(G3D::Array<Edge*>& edges);          // 005e6ba0 (INFERRED name: EdgeIterator from the root

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
		SleepInfo* getSleepInfo() const                  // inline (donor Assembly::getSleepInfo): SleepStage 0064ae90 reads
		{                                                // [clump+0x18] directly
			return sleepInfo;
		}
		Assembly* getRootAssembly();                     // 005e6070 (analog name: parent ? parent->getRootAssembly() : this)
		void setParent(Clump* newParent);                // 005e6fd0 (analog name: openrbx Assembly::setParent)
		void removePrimitive(Primitive* p);              // 005e6790 (INFERRED name: 005e5ff0, then onPrimitivesChanged)
		// INFERRED names: cdecl (parent, joint, child) Clump-unit helpers called by TreeStage::processEdge 00669560.
		static void updateRigidChild(Primitive* parent, Joint* j, Primitive* child);         // INFERRED: 005e6040 (child body setMeInParent only)
		static void addRigidChild(Primitive* parent, Joint* j, Primitive* child);      // INFERRED: 005e67c0 (setClump, Body::setParent, onPrimitivesChanged, setMeInParent)
		void onPrimitiveCanSleepChanged(Primitive* p);   // 005e6530 (analog name: canSleep.setDirty())
		bool getAnchored() const;                        // 005e60e0 (analog name: the root primitive's +0xa8 / +0xa9 / +0xaa;
		unsigned int numMotors() const;                  // 005e62d0 (analog name: openrbx Assembly::numMotors)
		const G3D::Array<Edge*>& getExternalEdges();     // 005e6c70 (INFERRED name: refills externalEdges +0x8 when
	public:
		void sub_005e6ba0(G3D::Array<const void*>& edges);   // INFERRED: 005e6ba0, placeholder name (identity tier), body byte-proved (Inferred_005e6ba0.cpp)
	public:
		void sub_005e6240(Assembly* value);   // INFERRED: 005e6240, placeholder name (identity tier), body byte-proved (Inferred_005e6240.cpp)
	};

	// INFERRED: the 2008 binary has no RTTI for an RBX::Assembly and the assembly object is its root Clump (Clump()
	class Assembly : public Clump
	{
	public:
		Clump* getRootClump() const                      // the +0x24 view of 0063c9ee / 005e8268
		{
			return Clump::getAssembly();
		}
		static void addMotorChild(Primitive* parent, MotorJoint* motor, Primitive* child);   // 005e7050 ?addMotorChild@Assembly@RBX@@SAXPAVPrimitive@2@PAVMotorJoint@2@0@Z (registry; caller TreeStage::processEdge 00669560)
		MotorJoint* getMotor(unsigned int index);        // 005e6400 ?getMotor@Assembly@RBX@@QAEPAVMotorJoint@2@I@Z (registry)
		public:
		RBX::PrimIterator assemblyPrimEnd(void)const;   // INFERRED: ?assemblyPrimEnd@Assembly@RBX@@QBE?AVPrimIterator@2@XZ (header gap, header_gap_fill.py)
};

	bool lessAssembly(const Assembly* a0, const Assembly* a1);
}
#endif
