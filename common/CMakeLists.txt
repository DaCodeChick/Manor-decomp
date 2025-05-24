set(SOURCES
	MWFFile.cpp
	network.cpp
	util.cpp
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
