// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// INFERRED: mangled name puts the class under PlayerNativeMaterial, not RBX::ViewNew; layout follows 004d7460.
// INFERRED: self-contained G3D refcount stand-ins; the header chain needs OgreMaterial.h, which is not on the include path.
extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(volatile long*);

namespace G3D
{
	class ReferenceCountedObject
	{
	public:
		virtual ~ReferenceCountedObject() {}
		volatile long ReferenceCountedObject_refCount;
		// 0045ad90
		void ReferenceCountedObject_zeroWeakPointers();
	};

	template<class T>
	class ReferenceCountedPointer
	{
		T* m_pointer;
	public:
		~ReferenceCountedPointer()
		{
			if (m_pointer != 0)
			{
				if (InterlockedDecrement(&m_pointer->ReferenceCountedObject_refCount) == 0)
				{
					m_pointer->ReferenceCountedObject_zeroWeakPointers();
					delete m_pointer;
				}
				m_pointer = 0;
			}
		}
	};
}

namespace PlayerNativeMaterial
{
	class MaterialFactory
	{
		// INFERRED: pointee type only affects the shared refcount-release code, so one stand-in covers all four.
		G3D::ReferenceCountedPointer<G3D::ReferenceCountedObject> megaTexture;
		G3D::ReferenceCountedPointer<G3D::ReferenceCountedObject> surfacesTexture;
		G3D::ReferenceCountedPointer<G3D::ReferenceCountedObject> fileMeshTexture;
		G3D::ReferenceCountedPointer<G3D::ReferenceCountedObject> fileMeshMaterial;
	public:
		~MaterialFactory();
	};

	MaterialFactory::~MaterialFactory()
	{
	}
}
