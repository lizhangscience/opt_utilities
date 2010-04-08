find_path(LTDL_INCLUDE_DIRS ltdl.h)

message(${LTDL_INCLUDE_DIRS})
SET(LTDL_NAMES ${LTDL_NAMES} ltdl)
MESSAGE(${LTDL_NAMES})
FIND_LIBRARY(LTDL_LIBRARIES ${LTDL_NAMES} )
INCLUDE(FindPackageHandleStandardArgs)

FIND_PACKAGE_HANDLE_STANDARD_ARGS(LTDL DEFAULT_MSG LTDL_LIBRARIES LTDL_INCLUDE_DIRS)

MARK_AS_ADVANCED(LTDL_INCLUDE_DIRS LTDL_LIBRARIES)

