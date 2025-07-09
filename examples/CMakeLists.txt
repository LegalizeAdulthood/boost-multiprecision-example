find_package(Boost CONFIG REQUIRED COMPONENTS multiprecision)

function(add_example name)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name} PRIVATE Boost::multiprecision)
    target_folder(${name} "Examples")
endfunction()

foreach(name "int" "bin_float" "dec_float" "rational" "complex")
    add_example(cpp_${name}_example)
endforeach()
