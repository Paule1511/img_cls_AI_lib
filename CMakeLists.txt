cmake_minimum_required(VERSION 3.10)

project(image_ai)

find_package(OpenCV REQUIRED)

include_directories(${OpenCV_INCLUDE_DIRS})

set_property(GLOBAL PROPERTY CXX_STANDARD 17)

add_compile_options("/std:c++17")

set_property(GLOBAL PROPERTY CXX_STANDARD_REQUIRED ON)

add_executable(image_ai "main.cpp" 
	"Model/Model.h" "Model/Model.cpp" 
	"Model/Layer.h" "Model/Layer.cpp" 
	"Utils/Debug.h" "Utils/Debug.cpp"  
	"Model/Image.h" "Model/Image.cpp"
)


target_link_libraries(image_ai PUBLIC ${OpenCV_LIBS})

add_custom_command(
    TARGET image_ai POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
        "$<TARGET_PROPERTY:image_ai,SOURCE_DIR>/images"
        "$<TARGET_PROPERTY:image_ai,BINARY_DIR>/images"
)

add_custom_command(
    TARGET image_ai POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy -t
        $<TARGET_FILE_DIR:image_ai>
        $<TARGET_RUNTIME_DLLS:image_ai>
	COMMAND_EXPAND_LISTS
)