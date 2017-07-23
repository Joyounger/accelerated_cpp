CPPFLAGS = /c /GX /nologo

all:		fails_vec1.exe fails_vec2.exe fails_iters.exe fails_list.exe \
		split_main.exe split_main2.exe pics_main.exe

median.obj:	..\chapter04\median.cpp ..\chapter04\median.h
	$(CPP) $(CPPFLAGS) /c ..\chapter04\median.cpp

Student_info.obj: ..\chapter04\Student_info.cpp ..\chapter04\Student_info.h
	$(CPP) $(CPPFLAGS) /c ..\chapter04\Student_info.cpp

grade.obj:	grade.cpp grade.h

ext_main.obj:	ext_main.cpp grade.h ..\chapter04\Student_info.h

list_main.obj:	list_main.cpp grade.h ..\chapter04\Student_info.h

fails_vec1.obj:	fails_vec1.cpp grade.h ..\chapter04\Student_info.h

fails_vec2.obj:	fails_vec2.cpp grade.h ..\chapter04\Student_info.h

fails_iters.obj: fails_iters.cpp grade.h ..\chapter04\Student_info.h

fails_list.obj:	fails_list.cpp grade.h  ..\chapter04\Student_info.h

fails_vec1.exe:	fails_vec1.obj ext_main.obj grade.obj \
		median.obj Student_info.obj

fails_vec2.exe:	fails_vec2.obj ext_main.obj grade.obj \
		median.obj Student_info.obj

fails_iters.exe: fails_iters.obj ext_main.obj grade.obj \
		median.obj Student_info.obj

fails_list.exe:	fails_list.obj list_main.obj grade.obj \
		median.obj Student_info.obj

pics.obj:	pics.cpp pics.h

pics_main.obj:	pics_main.cpp pics.h

pics_main.exe:	pics_main.obj pics.obj

split.obj:	split.cpp split.h

split_main.obj:	split_main.cpp split.h

split_main2.obj: split_main2.cpp split.h

split_main.exe:	split_main.obj split.obj

split_main2.exe: split_main2.obj split.obj

test:		all
	fails_vec1.exe <..\data\grades
	fails_vec2.exe <..\data\grades
	fails_iters.exe <..\data\grades
	fails_list.exe <..\data\grades
	split_main.exe < split_main.cpp
	split_main2.exe < split_main2.cpp
	pics_main.exe



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
	cl /nologo /I..\chapter04 /GX /c $<

# To convert a collection of .obj files to a .exe file,
# run the linker (same command as the compiler) with these options:
#	/nologo	Don't print a copyright message when starting
.obj.exe:
	cl /nologo $**
