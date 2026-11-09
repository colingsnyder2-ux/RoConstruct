/** @page guidemeshes Working with Meshes
\htmlonly
<TABLE BORDER=0 WIDTH=80%><TR>
    <TD>
        <FONT FACE="Arial"><I><A HREF="guidevar.html">
            <IMG SRC="backarrow.gif" BORDER=0 ALIGN=MIDDLE>
            Vertex Arrays
        </A></I></FONT>
    </TD>
    <TD ALIGN=RIGHT>
        <FONT FACE="Arial"><I><A HREF="guideui.html">
            User Input 
            <IMG SRC="forwardarrow.gif" BORDER=0 ALIGN=MIDDLE>
        </A></I></FONT>
    </TD>
    </TR></TABLE>
\endhtmlonly


<P> A mesh is a collection of faces, edges and vertices that can be 
used to render 3D objects.  Since there are many different varieties 
of mesh implementations, %G3D provides the basic building blocks for 
implementating a mesh class as well as a few specific mesh classes 
such as MD2Model and IFSModel.  The following tutorial will review 
the mesh resources that %G3D provides and give an overview of how to 
use each.

@section mesh_define Important Definitions

<P> There are a few essential definitions required to explain the %G3D
approach to meshes.
<P>An <B>Indexed Face Set (IFS)</B> is a set of faces defined by 
indices into a vertex list.  Simply put, this would be a vertex list 
and an array of indices that defined the face set from the vertex list.  
<P>An <B>entity</B> is an instance (such as a player) that has only a 
reference frame.
<P> A <B>model</B> is a class of shape.  It defines a three dimensional 
object in a specific reference frame.  It has no implementation in %G3D, 
but it would be natural to implement model as a child class of entity.
<P> A <B>posed-model</B> is a model frozen in time.  A posed-model's 
implementation should contain all information necessary to render the 
object.  All model types may have different implementations, but each 
should implement a child class of G3D::PosedModel from which the model 
should be rendered.
<P> <B>***NOTE***</B>  %G3D does not implement entity and model classes 
because they are implementation specific.

@section meshalg G3D::MeshAlg
    
<P> The G3D::MeshAlg class provides the common functionality necessary 
to implement a PosedModel class.  These calculations include the 
ability to compute common vertex attributes such as normals, binormals 
and tangents for tangent space calculations -- as well as mesh 
boundaries and backfaces.  This class also provides basic functions for 
analyzing the face areas and edge lengths of a mesh.  These functions
include the ability to find min, mean, median and max length or area. 
<P> The basic function set in G3D::MeshAlg accepts an array of vertices 
and an array of integers that corresponds to a triangle based indexed 
face set.  If it is necessary to convert from another type of mesh to a 
triangle mesh, then the class function G3D::MeshAlg::toIndexedTriList 
can be used for the conversion.  It will accept an array of vertices in 
any %G3D defined Primitive and convert them to an indexed list of 
triangles.
<P> Another set of useful class features are the functions computeWeld 
and WeldAdjacency, which will collapse vertices that are within a 
defined radius of each other.  This can be used to downsample a model or 
find unique vertices.
  
@section meshbuilder G3D::MeshBuilder
    
<P> G3D::MeshBuilder is a class built to optimize the creation of 
water-tight meshes from a set of polygons.  It allows polygons to be 
added in the form of triangles and quads.  After the models have been 
written, the commit function can be used to create an array of vertices 
and a corresponding index array to be used with G3D::MeshAlg.
<P> See the IFSBuilder contrib program for an example of how to use this 
class.

@section models G3D::IFSModel, G3D::MD2Model and G3D::PosedModel

<P> While %G3D only strives for basic mesh support, it does provide two
model types in the library for application prototyping.  These two types
are the IFSModel and the MD2Model.
<P> G3D::IFSModel allows simple access to loading and saving IFS models.  
The IFSModel can be used in conjunction with MeshBuilder to save a set of 
points to a file.  The class documentation provides further explanation 
of its functionality.  
<P> G3D::MD2Model is the second %G3D model class.  This class provides
advanced functionality for manipulating Quake II's MD2 model.  This 
functionality includes loading, animating and drawing.
<P> G3D::PosedModel is essentially a snapshot of a specific model 
geometry.  It is meant to serve as a base class for user-defined 
PosedModel objects.  A PosedModel child should provide all the 
functionality and data necessary to render a mesh snapshot. 
G3D::MD2Model is an excellent demonstration of a mesh class that
animates a mesh and then uses PosedModel to derive a renderable object.

@section examples Contrib Examples

<A HREF="../contrib/IFSBuilder">contrib/IFSBuilder</A> parses 3DS, SM, PLY, and OBJ files.

<IMG SRC="curveeditor.jpg" WIDTH = 200>
<A HREF="../contrib/CurveEditor">contrib/CurveEditor</A> demonstrates using G3D::MeshBuilder,
 G3D::IFSModel::save and G3D::cyclicCatmullRomSpline to create meshes in a primitive
 interactive editor.

  */