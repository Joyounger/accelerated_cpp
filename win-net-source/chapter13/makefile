CPPFLAGS = /c /GX /nologo /I. /I..\chapter08

all:		main_core.exe main_grad.exe main_orig.exe main_core_ptrs.exe

Core.obj:	Core.cpp Core.h

Grad.obj:	Grad.cpp Core.h

Student_info.obj:	Student_info.cpp ..\chapter08\median.h Student_info.h Core.h

grade.obj:	grade.cpp ..\chapter08\median.h Student_info.h

read_hw.obj:	read_hw.cpp ..\chapter08\median.h Student_info.h

main_core.obj:	main_core.cpp Core.h ..\chapter08\median.h

main_grad.obj:	main_grad.cpp Core.h ..\chapter08\median.h

main_orig.obj:	main_orig.cpp Core.h ..\chapter08\median.h Student_info.h

main_core_ptrs.obj:	main_core_ptrs.cpp Core.h ..\chapter08\median.h

main_orig.exe:	main_orig.obj grade.obj Student_info.obj read_hw.obj Core.obj

main_core.exe:	main_core.obj grade.obj  read_hw.obj Core.obj

main_grad.exe:	main_grad.obj grade.obj  read_hw.obj Core.obj

main_core_ptrs.exe:	main_core_ptrs.obj grade.obj  read_hw.obj Core.obj

test:		all
	main_core.exe <..\data\grades_core
	main_grad.exe <..\data\grades_grad
	main_orig.exe <..\data\mixed_grades
	main_core_ptrs.exe <..\data\mixed_grades


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
