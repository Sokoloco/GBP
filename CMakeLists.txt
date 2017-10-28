cmake_minimum_required(VERSION 3.8)
project(GPB)

FIND_PACKAGE( OpenCV REQUIRED )


set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp GUI/Map.cpp GUI/Map.h Pathfinding/PathFinding.cpp Pathfinding/PathFinding.h Structures/LinkedList.cpp Structures/LinkedList.h Structures/Node.cpp Structures/Node.h Tests/Tests.h GUI/Map2.cpp GUI/Map2.h)
add_executable(GBP ${SOURCE_FILES})

INCLUDE_DIRECTORIES(  /usr/local/Cellar/allegro/5.2.1.1_1/include )
LINK_DIRECTORIES(  /usr/local/Cellar/allegro/5.2.1.1_1/lib )

file(GLOB LIBRARIES "/usr/local/Cellar/allegro/5.2.1.1_1/lib/*.dylib")
message("LIBRARIES = ${LIBRARIES}")


TARGET_LINK_LIBRARIES(GBP  ${LIBRARIES})
TARGET_LINK_LIBRARIES(GBP  ${OpenCV_LIBS})

TARGET_LINK_LIBRARIES(GBP  allegro_acodec
        allegro_audio
        allegro_color
        allegro_dialog
        allegro_image
        allegro_main
        allegro_memfile
        allegro_physfs
        allegro_primitives
        allegro_ttf
        allegro_font
        allegro)