set(SOURCES
	MWFFile.cpp
	network.c
	util.c
)

set(HEADERS
	manor.h
	MWFFile.h
	network.h
	typedefs.h
	util.h
)

add_library(
	MWF SHARED
	${SOURCES}
	${HEADERS}
)
