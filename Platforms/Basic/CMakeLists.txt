cmake_minimum_required (VERSION 3.6)

project(Diligent-BasicPlatform CXX)

set(SOURCE 
    src/BasicFileSystem.cpp
    src/BasicPlatformDebug.cpp
)

set(INTERFACE 
    interface/BasicAtomics.hpp
    interface/BasicFileSystem.hpp
    interface/BasicPlatformDebug.hpp
    interface/BasicPlatformMisc.hpp
    interface/DebugUtilities.hpp
)

if(PLATFORM_LINUX OR PLATFORM_WIN32 OR PLATFORM_MACOS OR PLATFORM_IOS)
    list(APPEND SOURCE src/StandardFile.cpp)
    list(APPEND INTERFACE interface/StandardFile.hpp)
endif()

add_library(Diligent-BasicPlatform STATIC ${SOURCE} ${INTERFACE})
set_common_target_properties(Diligent-BasicPlatform)

get_target_relative_dir(Diligent-BasicPlatform BASIC_PLATFORM_DIR)

target_include_directories(Diligent-BasicPlatform 
PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/interface>
    $<INSTALL_INTERFACE:include/${BASIC_PLATFORM_DIR}/interface>
)

target_link_libraries(Diligent-BasicPlatform 
PRIVATE
    Diligent-BuildSettings 
PUBLIC
    Diligent-PrimitivesInterface
)

source_group("src" FILES ${SOURCE})
source_group("interface" FILES ${INTERFACE})

set_target_properties(Diligent-BasicPlatform PROPERTIES
    FOLDER DiligentCore/Platforms
)


if(DILIGENT_INSTALL_CORE)
    if(NOT ${DILIGENT_USE_VCPKG})
        install_core_lib(Diligent-BasicPlatform)
    else()
        install_core_lib_and_export(Diligent-BasicPlatform)
    endif()
    install(DIRECTORY    "../interface"
            DESTINATION  "${CMAKE_INSTALL_INCLUDEDIR}/${BASIC_PLATFORM_DIR}/../"
    )
endif()