/**
 @page guidebrown Brown-Specific Instructions

 This document describes Brown University-specific installation instructions. They probably don't belong in the main distribution.

@section introcourses G3D in Courses at Brown

If you're doing this tutorial as the first assignment in a class, you can bet that 
future assignments will assume that you are familiar with the G3D library
and can create 3D scenes, detect collisions, and handle user input. With a solid 
grasp of G3d, you won't have to learn new support code for each project and 
will have a powerful, reliable base of code on which to build.

@section linuxbrown Linux Setup at Brown
Copy the icompile script from
<tt>/course/cs224/bin/icompile</tt> or whereever you downloaded it 
to your new project directory. You will use this script instead of a Makefile (though you
may write your own Makefile if you prefer). iCompile automatically compiles 
and links every C++ file in the directory it's run from, so you won't need 
to edit it to refer to each source file (as you would with a Makefile). 
It needs the following environment variables, which you can set in your 
<tt>.cshrc</tt> file using setenv:

<tt>
<pre>
INCLUDE /course/cs224/libraries/g3d-6_03/include:/usr/include/SDL
LIBRARY /course/cs224/libraries/g3d-6_03/linux-lib
LD_LIBRARY_PATH $LIBRARY
CC gcc-3.2
CXX g++-3.2
</pre>
</tt>

@section windowsbrown Windows Setup at Brown

While there are advantages to developing on Windows. the TA staff will not give you any help
with Windows problems, and you must leave yourself time to make sure your
final code compiles and runs under Linux before you handin. If you exclusively
use %G3D, your assignment should be source-compatible between Linux and Windows,
but it is your responsibility to test your code under Linux before handing
it in.

The first time you use %G3D, mount the G: drive by 
selecting the "Map Network Drive" item under the
"Tools" menu, which appears in any Windows Explorer window. Map the G:
drive to //maytag/gfx0/common/games and check the "Reconnect at logon"
option, then press "Ok". G: is now your G3D_ROOT.





 */