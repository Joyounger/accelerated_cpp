CPPFLAGS = /c /GX /nologo /I..\chapter05

all:		wc.exe xref.exe grammar.exe

wc.obj:		wc.cpp

wc.exe:		wc.obj

xref.obj:	xref.cpp ..\chapter05\split.h

xref.exe:	xref.obj split.obj

grammar.obj:	grammar.cpp ..\chapter05\split.h

grammar.exe:	grammar.obj split.obj

split.obj:	..\chapter06\split.cpp ..\chapter05\split.h
	$(CPP) $(CPPFLAGS) ..\chapter06\split.cpp

test:		all
	wc.exe < wc.cpp
	xref.exe < wc.cpp
	grammar.exe <..\data\grammar_input



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
	cl /nologo /I..\chapter05 /GX /c $<

# To convert a collection of .obj files to a .exe file,
# run the linker (same command as the compiler) with these options:
#	/nologo	Don't print a copyright message when starting
.obj.exe:
	cl /nologo $**
