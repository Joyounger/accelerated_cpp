CPPFLAGS = /c /GX /nologo /I. /I..\chapter08

all: std_main1.exe std_main2.exe std_main3.exe urls_main.exe

std_main1.exe:	std_main1.obj Student_info.obj Core.obj grade.obj read_hw.obj

std_main1.obj:	std_main1.cpp Student_info.h Handle.h

std_main2.exe:	std_main2.obj Student_info.obj Core.obj grade.obj read_hw.obj

std_main2.obj:	std_main2.cpp Student_info.h Ref_handle.h

std_main3.exe:	std_main3.obj Student_info.obj Core.obj grade.obj read_hw.obj

std_main3.obj:	std_main3.cpp Student_info.h Ptr.h

Core.obj:	Core.cpp Core.h

Student_info.obj:	Student_info.cpp Core.h Student_info.h

grade.obj:	grade.cpp Student_info.h

read_hw.obj:	read_hw.cpp

urls_main.exe:	urls_main.obj urls.obj Vec_clone.obj Str.obj

urls_main.obj:	urls_main.cpp urls.h Vec.h Str.h

urls.obj:	urls.cpp urls.h Vec.h Str.h

Vec_clone.obj:	Vec_clone.cpp Vec.h

Str.obj:  Str.cpp Str.h

test:	all
	std_main1.exe <..\data\mixed_grades
	std_main2.exe <..\data\mixed_grades
	std_main3.exe <..\data\mixed_grades
	urls_main.exe <..\data\urls.htm


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
	cl /nologo /I. /I..\chapter08 /GX /c $<

# To convert a collection of .obj files to a .exe file,
# run the linker (same command as the compiler) with these options:
#	/nologo	Don't print a copyright message when starting
.obj.exe:
	cl /nologo $**
