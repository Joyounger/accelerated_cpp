all:		concat_files.exe copyfile.exe letter_grade.obj \
		pointer_example.exe write_args.exe

concat_files.exe: concat_files.obj

copyfile.exe:	copyfile.obj

pointer_example.exe: pointer_example.obj

write_args.exe:	write_args.obj

test:		all
	concat_files ..\data\name1 ..\data\name2
	copyfile
	pointer_example
	write_args this is a test




# Say "nmake clobber" to get rid of files created by nmake
clobber:
	del *.obj
	del *.exe
	del out

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
