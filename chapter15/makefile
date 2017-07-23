CPPFLAGS = /c /GX /nologo /I. /I..\chapter14

all:		main1.exe main2.exe

Pic.obj:	Pic.cpp Pic.h

main2.obj:	main2.cpp Pic.h

main2.exe:	main2.obj Pic.obj

main1.obj:	main1.cpp Pic.h

main1.exe:	main1.obj Pic.obj


test:		all
	main1.exe
	main2.exe



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
	cl /nologo /I. /I..\chapter14 /GX /c $<

# To convert a collection of .obj files to a .exe file,
# run the linker (same command as the compiler) with these options:
#	/nologo	Don't print a copyright message when starting
.obj.exe:
	cl /nologo $**
