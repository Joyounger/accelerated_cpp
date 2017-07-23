all:		main1.exe main2.exe main3.exe

Student_info.obj: Student_info.cpp Student_info.h

grade.obj:	grade.cpp grade.h median.h Student_info.h

main3.obj:	main3.cpp grade.h median.h Student_info.h

median.obj:	median.cpp median.h

main1.exe:	main1.obj

main2.exe:	main2.obj

main3.exe:	main3.obj grade.obj median.obj Student_info.obj

test:		all
	main1.exe <..\data\single_grade
	main2.exe <..\data\single_grade
	main2.exe <..\data\grades
	main3.exe <..\data\grades




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
