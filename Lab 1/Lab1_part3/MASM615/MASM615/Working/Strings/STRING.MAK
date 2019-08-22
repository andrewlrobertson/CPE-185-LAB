ORIGIN = PWB
ORIGIN_VER = 2.1.49
PROJ = string
PROJFILE = string.mak
DEBUG = 1

BRFLAGS  =  /o $(PROJ).bsc
BSCMAKE  = bscmake
SBRPACK  = sbrpack
NMAKEBSC1  = set
NMAKEBSC2  = nmake
BROWSE  = 1
CVFLAGS  = /50 /S
ASM  = ml
H2INC  = h2inc
AFLAGS_G  = /W2 /WX /AT
AFLAGS_D  = /Zi /Fl
AFLAGS_R  = /Fl /nologo
MAPFILE_D  = NUL
MAPFILE_R  = NUL
LFLAGS_G  = /NOI /TINY /NOE /BATCH /ONERROR:NOEXE
LFLAGS_D  = /CO /FAR
LFLAGS_R  = /FAR
LINKER  = link
ILINK  = ilink
LRF  = echo > NUL
ILFLAGS  = /a /e

FILES  = STRING~1.ASM
OBJS  = STRING~1.obj
SBRS  = STRING~1.sbr

all: $(PROJ).com

.SUFFIXES:
.SUFFIXES:
.SUFFIXES: .sbr .obj .asm

STRING~1.obj : STRING~1.ASM
!IF $(DEBUG)
        $(ASM) /c $(AFLAGS_G) $(AFLAGS_D) /FoSTRING~1.obj STRING~1.ASM
!ELSE
        $(ASM) /c $(AFLAGS_G) $(AFLAGS_R) /FoSTRING~1.obj STRING~1.ASM
!ENDIF

STRING~1.sbr : STRING~1.ASM
!IF $(DEBUG)
        $(ASM) /Zs $(AFLAGS_G) $(AFLAGS_D) /FRSTRING~1.sbr STRING~1.ASM
!ELSE
        $(ASM) /Zs $(AFLAGS_G) $(AFLAGS_R) /FRSTRING~1.sbr STRING~1.ASM
!ENDIF


$(PROJ).bsc : $(SBRS)
        $(BSCMAKE) @<<
$(BRFLAGS) $(SBRS)
<<

$(PROJ).com : $(OBJS)
        -$(NMAKEBSC1) MAKEFLAGS=
        -$(NMAKEBSC2) $(NMFLAGS) -f $(PROJFILE) $(PROJ).bsc
!IF $(DEBUG)
        $(LRF) @<<$(PROJ).lrf
$(RT_OBJS: = +^
) $(OBJS: = +^
)
$@
$(MAPFILE_D)
$(LIBS: = +^
) +
$(LLIBS_G: = +^
) +
$(LLIBS_D: = +^
)
$(DEF_FILE) $(LFLAGS_G) $(LFLAGS_D);
<<
!ELSE
        $(LRF) @<<$(PROJ).lrf
$(RT_OBJS: = +^
) $(OBJS: = +^
)
$@
$(MAPFILE_R)
$(LIBS: = +^
) +
$(LLIBS_G: = +^
) +
$(LLIBS_R: = +^
)
$(DEF_FILE) $(LFLAGS_G) $(LFLAGS_R);
<<
!ENDIF
        $(LINKER) @$(PROJ).lrf


.asm.sbr :
!IF $(DEBUG)
        $(ASM) /Zs $(AFLAGS_G) $(AFLAGS_D) /FR$@ $<
!ELSE
        $(ASM) /Zs $(AFLAGS_G) $(AFLAGS_R) /FR$@ $<
!ENDIF

.asm.obj :
!IF $(DEBUG)
        $(ASM) /c $(AFLAGS_G) $(AFLAGS_D) /Fo$@ $<
!ELSE
        $(ASM) /c $(AFLAGS_G) $(AFLAGS_R) /Fo$@ $<
!ENDIF


run: $(PROJ).com
        $(PROJ).com $(RUNFLAGS)

debug: $(PROJ).com
        CV $(CVFLAGS) $(PROJ).com $(RUNFLAGS)
