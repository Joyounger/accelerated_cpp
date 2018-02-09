CPPFLAGS = /c /GX /nologo /I..\chapter04 /I..\chapter05

all:		split_main.exe palin.exe urls_main.exe grade_analysis.exe \
		ext_fails1.exe ext_fails2.exe


median.obj:	..\chapter04\median.cpp ..\chapter04\median.h
	$(CPP) $(CPPFLAGS) /c ..\chapter04\median.cpp

Student_info.obj:	..\chapter04\Student_info.cpp ..\chapter04\Student_info.h
	$(CPP) $(CPPFLAGS) /c ..\chapter04\Student_info.cpp

split.obj:	split.cpp ..\chapter05\split.h

split_main.obj:	..\chapter05\split_main.cpp ..\chapter05\split.h
	$(CPP) $(CPPFLAGS) -c ..\chapter05\split_main.cpp

split_main.exe:	split_main.obj split.obj

palin.obj:	palin.cpp

urls.obj:	urls.cpp urls.h

urls_main.obj:	urls_main.cpp urls.h

urls_main.exe:	urls_main.obj urls.obj

grade.obj:	grade.cpp grade.h

grade_check.obj: grade_check.cpp

analysis.obj:	analysis.cpp analysis.h

grade_analysis.obj: grade_analysis.cpp analysis.h

grade_analysis.exe: grade_analysis.obj analysis.obj grade_check.obj \
		 grade.obj median.obj Student_info.obj

ext_main.obj:	..\chapter05\ext_main.cpp grade.h \
		..\chapter04\Student_info.h ..\chapter04\median.h
	$(CPP) $(CPPFLAGS) -c ..\chapter05\ext_main.cpp

ext_fails1.obj:	ext_fails1.cpp grade.h \
		..\chapter04\Student_info.h ..\chapter04\median.h

ext_fails2.obj:	ext_fails2.cpp grade.h \
		..\chapter04\Student_info.h ..\chapter04\median.h

ext_fails1.exe:	ext_fails1.obj ext_main.obj grade.obj \
		median.obj Student_info.obj

ext_fails2.exe: ext_fails2.obj ext_main.obj grade.obj \
		median.obj Student_info.obj

test:		all
	split_main <split.cpp
	palin <..\data\palins_input
	urls_main <..\data\urls.htm
	grade_analysis <..\data\grades
	ext_fails1 <..\data\grades
	ext_fails2 <..\data\grades



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
	cl /nologo /I..\chapter04 /I../chapter05 /GX /c $<

# To convert a collection of .obj files to a .exe file,
# run the linker (same command as the compiler) with these options:
#	/nologo	Don't print a copyright message when starting
.obj.exe:
	cl /nologo $**
