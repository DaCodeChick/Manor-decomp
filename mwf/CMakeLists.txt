set(SOURCES
	MWF.c
	MWFFile.cpp
	MWFThreadManager.cpp
)

set(HEADERS
	MWF.h
	MWFFile.h
	MWFThreadManager.h
)

add_library(
	MWF SHARED
	${SOURCES}
	${HEADERS}
)
