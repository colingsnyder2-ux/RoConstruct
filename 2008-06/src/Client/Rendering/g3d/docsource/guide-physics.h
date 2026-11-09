/** 
  @page guidephysics Physics and Ray Tracing
  \htmlonly
<TABLE BORDER=0 WIDTH=80%><TR><TD><I><FONT FACE="Arial">
<A HREF="guidefiles.html"><IMG SRC="backarrow.gif" BORDER=0 ALIGN=MIDDLE>
Files</A></I></FONT></TD><TD ALIGN=RIGHT><FONT FACE="Arial"><I>
<A HREF="guidecollision.html">
Collision Detection<IMG SRC="forwardarrow.gif" BORDER=0 ALIGN=MIDDLE></A></I></FONT></TD></TR></TABLE>
\endhtmlonly

  Physics and Ray Tracing have a lot in common.  This is because detecting the collision
  between a small projectile and the scene is mathematically identical to detecting 
  the intersection of a light ray and the scene.  G3D provides several routines for 
  assisting in these intersection calculations and making them fast. The next section, 
  \link guidecollision Collision Detection \endlink has more information. 

  This section has not complete.  Follow the links for more information.
  
  @section physics Physics
  <TABLE BORDER=0>
  <TR><TD><IMG SRC="explode.jpg" WIDTH=300>
  </TD></TR>
  <TR><TD><I>Blast Wave Simulation by Gabe Taubman and Edwin Chang</I></TD></TR>
  </TABLE>

  G3D::CoordinateFrame
  G3D::Quat
  G3D::PhysicsFrame
  lerp methods

  G3D::CollisionDetection

  @section raytracing Ray Tracing
  <TABLE ALIGN=RIGHT BORDER=0>
  <TR><TD><IMG SRC="photonmap.jpg" WIDTH=300>
  </TD></TR>
  <TR><TD><I>Photon Mapping by Morgan McGuire and Peter Hopkins</I></TD></TR>
  </TABLE>

  G3D::Ray class

  G3D::Vector::reflectionDirection
  G3D::Vector::refractionDirection
  G3D::Vector::hemiRandom
  G3D::Vector3:random
  G3D::Vector3::cosRandom
  G3D::Vector3::hemiRandom

  G3D::GCamera::worldRay returns the ray that passes through a pixel
  from the center of projection.

  @section bounding Bounding Volumes
  G3D::AABox, G3D::getBounds,
    G3D::Box, G3D::Sphere, G3D::Capsule, 

  G3D::PosedModel has methods for obtaining the bounding box and sphere.

  @section bsptree BSP Tree
  G3D::AABSPTree 

  */