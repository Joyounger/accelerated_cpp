CPPFLAGS = /c /GX /nologo /I. /I..\chapter04

all:		split_main.exe main3.exe analysis.exe


Student_info.obj: ..\chapter04\Student_info.cpp ..\chapter04\Student_info.h
	$(CPP) $(CPPFLAGS) /c ..\chapter04\Student_info.cpp

split_main.obj:	split_main.cpp ..\chapter05\split.h

split_main.exe:	split_main.obj

analysis.obj:	..\chapter06\analysis.cpp ..\chapter06\analysis.h
	$(CPP) $(CPPFLAGS) -c ..\chapter06\analysis.cpp

grade.obj:	..\chapter06\grade.cpp ..\chapter06\grade.h
	$(CPP) $(CPPFLAGS) -c ..\chapter06\grade.cpp

main3.obj:	..\chapter04\main3.cpp ..\chapter06\grade.h
	$(CPP) $(CPPFLAGS) -c ..\chapter04\main3.cpp

main3.exe:	main3.obj grade.obj analysis.obj Student_info.obj

analysis.exe:	analysis.obj grade.obj Student_info.obj \
		grade_analysis.obj grade_check.obj

grade_analysis.obj: ..\chapter06\grade_analysis.cpp ..\chapter06\analysis.h
	$(CPP) $(CPPFLAGS) -c ..\chapter06\grade_analysis.cpp

grade_check.obj: ..\chapter06\grade_check.cpp
	$(CPP) $(CPPFLAGS) -c ..\chapter06\grade_check.cpp

test:		all
	split_main.exe <split_main.cpp
	main3.exe < ..\data\single_grade
	main3.exe < ..\data\grades
	analysis.exe < ..\data\grades




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
	cl /nologo /I. /I..\chapter04 /GX /c $<

# To convert a collection of .obj files to a .exe file,
# run the linker (same command as the compiler) with these options:
#	/nologo	Don't print a copyright message when starting
.obj.exe:
	cl /nologo $**
