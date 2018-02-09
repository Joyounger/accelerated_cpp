all:		urls_main.exe analysis.exe main2.exe main3.exe

Student_info.obj: Student_info.cpp Vec.h Student_info.h

grade.obj:	grade.cpp Vec.h Student_info.h median.h

urls_main.obj:	urls_main.cpp urls.h Vec.h

urls.obj:	urls.cpp urls.h Vec.h

urls_main.exe:	urls_main.obj urls.obj

analysis.exe:	analysis.obj grade.obj Student_info.obj grade_analysis.obj grade_check.obj

analysis.obj:	analysis.cpp Vec.h Student_info.h median.h

grade_analysis.obj: grade_analysis.cpp analysis.h

grade_check.obj: grade_check.cpp

main2.obj: 	main2.cpp

main3.obj: 	main3.cpp grade.h median.h Student_info.h

main2.exe:   	main2.obj

main3.exe:   	main3.obj grade.obj Student_info.obj

test:		all
	urls_main.exe < ..\data\urls.htm
	analysis.exe < ..\data\grades
	main2.exe < ..\data\single_grade
	main2.exe < ..\data\grades
	main3.exe < ..\data\grades




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
