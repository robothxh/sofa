cmake_minimum_required(VERSION 2.8)
project(SofaExporter)

set(HEADER_FILES

    initExporter.h
    WriteState.h
    WriteState.inl
    WriteTopology.h
    WriteTopology.inl
    VTKExporter.h
    OBJExporter.h
    STLExporter.h
    MeshExporter.h

    )

set(SOURCE_FILES

    initExporter.cpp
    WriteState.cpp
    WriteTopology.cpp
    VTKExporter.cpp
    OBJExporter.cpp
    STLExporter.cpp
    MeshExporter.cpp

    )

set(GROUP_BASE_DIR "..")

add_library(${PROJECT_NAME} SHARED ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries( ${PROJECT_NAME} SofaSimulationTree)
target_include_directories(${PROJECT_NAME} PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../>")

# ZLIB dependancy through SofaHelper (?)

set( SOFAEXPORTER_COMPILER_FLAGS "-DSOFA_BUILD_EXPORTER")

set_target_properties( ${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX "_d" )
set_target_properties( ${PROJECT_NAME} PROPERTIES VERSION ${SOFAGENERAL_VERSION} )
set_target_properties( ${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${SOFAEXPORTER_COMPILER_FLAGS}"  )
set_target_properties( ${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${HEADER_FILES}" )

install(TARGETS ${PROJECT_NAME}
        COMPONENT SofaExporter_libraries
        EXPORT    SofaGeneralTargets
        RUNTIME DESTINATION "${SOFAGENERAL_INSTALL_BIN_DIR}"
        LIBRARY DESTINATION "${SOFAGENERAL_INSTALL_LIB_DIR}"
        ARCHIVE DESTINATION "${SOFAGENERAL_INSTALL_LIB_DIR}"
        PUBLIC_HEADER DESTINATION "${SOFAGENERAL_INSTALL_INCLUDE_DIR}/${PROJECT_NAME}"
)


