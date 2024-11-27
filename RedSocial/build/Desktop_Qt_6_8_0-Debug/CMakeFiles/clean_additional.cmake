# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/RedSocial_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/RedSocial_autogen.dir/ParseCache.txt"
  "RedSocial_autogen"
  )
endif()
