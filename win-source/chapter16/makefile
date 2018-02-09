all:	histo.exe

histo.exe:	histo.obj Pic.obj Core.obj Student_info.obj read_hw.obj grade.obj

histo.obj:	histo.cpp Pic.h Core.h median.h

Pic.obj:	Pic.cpp Pic.h

Core.obj:	Core.cpp Core.h

Grad.obj:	Grad.cpp Core.h

Student_info.obj: Student_info.cpp median.h Student_info.h Core.h

grade.obj:        grade.cpp median.h Student_info.h

read_hw.obj:      read_hw.cpp median.h Student_info.h

test:		all
	histo.exe <..\data\kids_grades



# Say "nmake clobber" to get rid of files created by nmake
clobber:
	del *.obj
	del *.exe

# To convert a .cpp file to a .obj file, run the compiler with these options:
#	/nologo	Don't print a copyright message when starting
#	/GX	Enable exception handling
#	/c	Compile only; don't link
#	$<	Built-in macro that expands to the file being compiled
.cpp.obj:
	cl /nologo /GX /c $<

# To convert a collection of .obj files to a .exe file,
# run the linker (same command as the compiler) with these options:
#	/nologo	Don't print a copyright message when starting
.obj.exe:
	cl /nologo $**
