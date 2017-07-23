all:		grading_prog.exe

Student_info.obj: Student_info.cpp Student_info.h

grade.obj:	grade.cpp ..\chapter08\median.h Student_info.h

grading_prog.obj: grading_prog.cpp ..\chapter04\grade.h \
		..\chapter08\median.h Student_info.h

grading_prog.exe: grading_prog.obj grade.obj Student_info.obj

test:		all
	grading_prog.exe <..\data\grades



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
