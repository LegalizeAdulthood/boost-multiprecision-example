find_package(boost_multiprecision REQUIRED CONFIG)

add_library(deep-zoom
    include/deep-zoom/args.h
    include/deep-zoom/deep-zoom.h
    args.cpp
    deep-zoom.cpp
)
target_include_directories(deep-zoom PUBLIC include)
target_link_libraries(deep-zoom PUBLIC Boost::multiprecision)
target_folder(deep-zoom "Libraries")
