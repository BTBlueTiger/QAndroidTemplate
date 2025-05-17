cmake_minimum_required(VERSION 3.16)
project(QAndroidTemplate LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

find_package(Qt6 REQUIRED COMPONENTS
    Quick
    Core
    Gui
)

# Rename the executable to avoid conflict with the directory
qt_add_executable(QAndroidTemplate
    main.cpp
)

qt_add_qml_module(QAndroidTemplate
    URI QAndroidTemplate
    RESOURCES ressource.qrc
)

set_target_properties(CANCarApp PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

if (ANDROID)
    include(FetchContent)
    FetchContent_Declare(
        android_openssl
        DOWNLOAD_EXTRACT_TIMESTAMP true
        URL https://github.com/KDAB/android_openssl/archive/refs/heads/master.zip
    )
    FetchContent_MakeAvailable(android_openssl)
    include(${android_openssl_SOURCE_DIR}/android_openssl.cmake)
endif()

target_link_libraries(QAndroidTemplate PRIVATE
    Qt6::Quick
    Qt6::Core
    Qt6::Gui
)

install(TARGETS QAndroidTemplate
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

# Uncomment and configure translations if needed
# qt_add_translations(CANCarApp TS_FILES
#     Postler_Mobile_de_DE.ts
#     Postler_Mobile_en_EN.ts
#     SOURCES ${QML_SOURCES2} ${CPP_SOURCES} ${HPP_SOURCES}
#     RESOURCE_PREFIX "/translations"
# )
