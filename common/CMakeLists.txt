set(SOURCES
	maccompat.c
	MWF.c
	MWFFile.cpp
	network.c
	secure.c
	util.c
)

set(HEADERS
	maccompat.h
	manor.h
	MWF.h
	MWFFile.h
	network.h
	secure.h
	typedefs.h
	util.h
)

add_library(
	MWF SHARED
	${SOURCES}
	${HEADERS}
)
